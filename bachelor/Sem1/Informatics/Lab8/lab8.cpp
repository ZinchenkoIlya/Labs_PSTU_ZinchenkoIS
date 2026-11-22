#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <windows.h>
#include <iomanip>

using namespace std;

const char* FILENAME = "schoolboys.dat";
const char* TEMPFILE = "schoolboys.tmp";

struct Schoolboy
{
    char fio[100];                //фамилия, имя, отчество
    int  klass;                   //класс
    char phone[30];               //номер телефона
    int  marks[4];             //оценки по 4 предметам
};

//функция поиска удаляемой структуры
bool hasBadMark(const Schoolboy& s)
{
    for (int i = 0; i < 4; i++)
    {
        if (s.marks[i] == 2)
        {
            return true;
        }
    }
    return false;
}

//функция печати
void printHeader()
{
    cout << "\n--------------------------------------------------------------------------------------------------\n";
    cout << "ФИО                       | Класс    | Телефон          | Мат  | Физ  | Рус  | Лит\n";
    cout << "--------------------------------------------------------------------------------------------------\n";
}

void printSchoolboy(const Schoolboy& s)
{
    cout << left << setw(25) << s.fio 
         << " | " << setw(8)  << s.klass 
         << " | " << setw(16) << s.phone 
         << " | " << setw(4)  << s.marks[0] 
         << " | " << setw(4)  << s.marks[1] 
         << " | " << setw(4)  << s.marks[2] 
         << " | " << setw(4)  << s.marks[3] << "\n";
}

//ввод одной структуры с клавиатуры
Schoolboy inputSchoolboy()
{
    Schoolboy s;
    cin.ignore();
    cout << "Введите ФИО: ";
    cin.getline(s.fio, sizeof(s.fio));
    cout << "Введите класс: ";
    cin >> s.klass;
    cin.ignore();
    cout << "Введите телефон: ";
    cin.getline(s.phone, sizeof(s.phone));
    cout << "Введите оценки (математика физика русский литература): ";
    for (int i = 0; i < 4; i++)
    {
        cin >> s.marks[i];
    }
    return s;
}

//формирование файла
void createFile()
{
    FILE* f = fopen(FILENAME, "wb");
    if (!f)
    {
        perror("Ошибка открытия файла для записи");
        exit(1);
    }
    int n;
    cout << "Сколько школьников ввести? (не менее 5): ";
    cin >> n;
    if (n < 5)
    {
        n = 5;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Школьник #" << (i + 1) << " ---\n";
        Schoolboy s = inputSchoolboy();

        if (fwrite(&s, sizeof(Schoolboy), 1, f) != 1)
        {
            perror("Ошибка записи в файл");
            fclose(f);
            exit(2);
        }
    }
    fclose(f);
    cout << "\nФайл успешно сформирован (" << n << " записей).\n";
}

//печать файла
void printFile()
{
    FILE* f = fopen(FILENAME, "rb");
    if (!f)
    {
        perror("Ошибка открытия файла для чтения");
        return;
    }

    printHeader();
    Schoolboy s;
    int cnt = 0;
    while (fread(&s, sizeof(Schoolboy), 1, f) == 1)
    {
        printSchoolboy(s);
        cnt++;
    }
    if (ferror(f))
    {
        perror("Ошибка чтения");
    }
    fclose(f);
    cout << "Всего записей: " << cnt << "\n";
}

//Удаление всех элементов с двойкой 
void deleteBadStudents()
{
    FILE* fin  = fopen(FILENAME, "rb");
    FILE* ftmp = fopen(TEMPFILE, "wb");
    if (!fin || !ftmp)
    {
        perror("Ошибка открытия файлов");
        if (fin)
        {
            fclose(fin);
        }
        if (ftmp)
        {
            fclose(ftmp);
        }
        exit(3);
    }

    Schoolboy s;
    int deleted = 0;
    while (fread(&s, sizeof(Schoolboy), 1, fin) == 1)
    {
        if (!hasBadMark(s))
        {
            if (fwrite(&s, sizeof(Schoolboy), 1, ftmp) != 1)
            {
                perror("Ошибка записи во временный файл");
                fclose(fin);
                fclose(ftmp);
                exit(4);
            }
        }
        else
        {
            cout << "Удалён: " << s.fio << "\n";
            deleted++;
        }
    }
    if (ferror(fin))
    {
        perror("Ошибка чтения");
    }
    fclose(fin);
    fclose(ftmp);
    remove(FILENAME);
    if (rename(TEMPFILE, FILENAME) != 0)
    {
        perror("Ошибка переименования файла");
        exit(5);
    }
    cout << "\nУдалено записей: " << deleted << "\n";
}

//Добавление элемента в начало
void addToBegin()
{
    cout << "\n--- Ввод нового школьника ---\n";
    Schoolboy s = inputSchoolboy();
    FILE* fin  = fopen(FILENAME, "rb");
    FILE* ftmp = fopen(TEMPFILE, "wb");
    if (!fin || !ftmp)
    {
        perror("Ошибка открытия файлов");
        if (fin)
        {
            fclose(fin);
        }
        if (ftmp)
        {
            fclose(ftmp);
        }
        exit(6);
    }
    if (fwrite(&s, sizeof(Schoolboy), 1, ftmp) != 1)
    {
        perror("Ошибка записи новой записи");
        fclose(fin);
        fclose(ftmp);
        exit(7);
    }
    Schoolboy tmp;
    while (fread(&tmp, sizeof(Schoolboy), 1, fin) == 1)
    {
        if (fwrite(&tmp, sizeof(Schoolboy), 1, ftmp) != 1)
        {
            perror("Ошибка копирования");
            fclose(fin);
            fclose(ftmp);
            exit(8);
        }
    }
    if (ferror(fin))
    {
        perror("Ошибка чтения старого файла");
    }
    fclose(fin);
    fclose(ftmp);
    remove(FILENAME);
    if (rename(TEMPFILE, FILENAME) != 0)
    {
        perror("Ошибка переименования файла");
        exit(9);
    }
    cout << "Элемент успешно добавлен в начало файла.\n";
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF8");
    cout << "\n---------- ШАГ 1: Формирование файла ----------\n";
    createFile();
    cout << "\n---------- ШАГ 2: Исходное содержимое файла ----------\n";
    printFile();
    cout << "\n---------- ШАГ 3: Удаление школьников с двойками ----------\n";
    deleteBadStudents();
    cout << "\n---------- ШАГ 4: Содержимое после удаления ----------\n";
    printFile();
    cout << "\n---------- ШАГ 5: Добавление школьника в начало ----------\n";
    addToBegin();
    cout << "\n---------- ШАГ 6: Финальное содержимое файла ----------\n";
    printFile();
    cout << "\nПрограмма завершена.\n";
    return 0;
}
