#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    int mxv = 0, mxg = 0;
    int a[4][5] = 
    {
        { 11, -20,  35,  43,  50},
        {-16,  39,   7,  60,  -8},
        { 12,  50, -33,   4,   9},
        {  1,   2,   3,   4,   5}
    };
    int max = a[0][0];
    cout << "Исходный массив: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
            {
            cout.width(5);
            cout << a[i][j];
            }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                mxg=i;
                mxv=j;
            }
        }
    }
    cout << "Максимальный элемент массива: "<< max << endl;
    cout << "Строка: "<< mxg << endl;
    cout << "Столбец: "<< mxv << endl;
    return 0;
}