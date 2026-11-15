#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    char s[256], l[256], d[256], o[256];
    int nl = 0, nd = 0, no = 0; //счетчики для буферов l, d и o соответственно

    cout << "Введите строку: \n";
    cin.getline(s,sizeof(s));                       
    //цикл для распределения символов по буферам
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)s[i]))       //проверка на букву
            l[nl++] = s[i];
        else if (isdigit((unsigned char)s[i]))  //проверка на цифру
            d[nd++] = s[i];
        else                                    //специальные символы
            o[no++] = s[i];
    }

    l[nl] = '\0';
    d[nd] = '\0';
    o[no] = '\0';

    //собираем в строку по условию
    strcpy(s, l);
    strcat(s, d);

    cout << "\nРезультат: " << s;
    return 0;
}
