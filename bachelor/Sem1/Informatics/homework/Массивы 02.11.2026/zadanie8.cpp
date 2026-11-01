#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    int a[4][5] = 
    {
        { 11, -20,  35,  43,  50},
        {-16,  39,   7,  60,  -8},
        { 12,  50, -33,   4,   9},
        {  1,   2,   3,   4,   5}
    };
    for (int i = 0; i < 4; ++i) 
    {
        int sum = 0;  //сумма текущей строки
        for (int j = 0; j < 5; ++j) 
        {
            sum += a[i][j];
            cout.width(4); 
            cout << a[i][j];
        }
        cout << "  |  Сумма: ";
        cout.width(2);
        cout << sum << "\n";
    }
    return 0;
}
