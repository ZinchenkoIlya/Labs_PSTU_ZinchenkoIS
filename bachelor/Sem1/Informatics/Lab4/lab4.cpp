#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    srand(time(NULL));
    cout<<"Одномерный массив: ";
    int a[100];
    int n = 100; //длина массива
    for (int i = 0; i < 100; i++)
    {
        a[i] = rand() % 100 - 50;
        cout << a[i] <<" ";
    }
    cout << endl << endl;
    int k;
    cout <<"Введите номер элемента, который хотите удалить (от 1 до " << n << "): ";
    cin >> k;
    if (k < 1 || k > n)
        cout << "Элемента с таким номером не существует!"<<endl;
    else
        {
            k--;  //перевод номера в индекс
            for (int i = k; i < n - 1; i++)
                a[i] = a[i + 1]; //сдвиг всех элементов влево
            n--; //уменьшение длины массива
        }
    int ch = -1; //т.к индекса -1 нет
    for (int i = 0; i < n; i++) 
        if (a[i] % 2 == 0 && ch == -1) 
            ch = i;  // запоминаем индекс
    if (ch == -1)
        cout << "В массиве нет четных элементов." << endl;
    else if (ch == 0)  
        cout << "\nПервый четный элемент стоит на первом месте — " << "M[i-1] не существует." << endl;
    else 
    {
        int nv = a[ch - 1] + 2; //значение элемента, который нужно вставить после четного
        for (int i = n; i > ch + 1; i--)
            a[i] = a[i - 1];  
        a[ch + 1] = nv;  
        n++;
        cout << "\nПервый четный элемент: a[" << ch << "] = " << a[ch] << endl;
        cout << "После него добавлен элемент со значением: " << nv << endl<<endl;
        cout << "Итоговый массив: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}

