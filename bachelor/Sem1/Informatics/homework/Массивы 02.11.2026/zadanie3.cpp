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
    for (int i = 0; i < 7/2; i++)
    {
        int n = a[i];
        a[i] = a[7 - 1 - i];
        a[7 - 1 - i] = n;
    }
    cout << "Перевернутый массив: ";
    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    return 0;
}