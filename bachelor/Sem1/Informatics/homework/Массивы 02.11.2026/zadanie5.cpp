#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    int a[7] = {11, -20, 35, 43, 50, -16, 39};
    cout << "Исходный массив: ";
    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i=1; i < 7; i++) // i=1 т.к. 1 элемент - отсортирован
    {
        int s = a[i];
        int j = i - 1;
        bool f = false;
        while (a[j]> s)
        {
            a[j+1] = a[j];
            j--;
            f=true;
        }
        a[j+1] = s;   
    }   
    cout << "Отсортированный массив: ";
    for (int i=0;i < 7; i++)
        cout << a[i]<< " ";
    return 0;
}