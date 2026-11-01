#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    int a[7] = {11, -20, 35, 43, 50, -16, 39};
    setlocale(LC_ALL,".UTF8");
    cout << "Исходный массив: ";
    for (int i = 0; i < 7; i++) 
        cout << a[i] << " ";
    for (int i = 0; i < 6; i++) 
        for (int j = 0; j < 6 - i; j++) 
            if (a[j] > a[j + 1]) 
            {
                int s = a[j];
                a[j] = a[j + 1];
                a[j + 1] = s;
            }
    cout << endl << "Отсортированный массив: ";
    for (int i = 0; i < 7; i++) 
        cout << a[i] << " ";
    return 0;
}