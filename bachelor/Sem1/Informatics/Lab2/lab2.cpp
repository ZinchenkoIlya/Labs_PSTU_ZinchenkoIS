#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    double t = 0.0001; //заданная точность
    double sum = 0; //накопление суммы ряда
    int n = 1; //номер члена ряда (начинаем с 1 номера)
    
    //начальные значения для n = 1
    double x = 1.0 / 2.0;
    double y = 1.0 / 3.0;
    double a = x + y; //первый член ряда

    while (a >= t)
    {
        sum += a;
        //вычисление следующего члена ряда по рекуррентной формуле
        x /= 2.0;
        y /= 3.0;
        a = x + y;
        n++; //двигаемся дальше по ряду
    }
    cout << "Сумма членов ряда с заданной точностью : "<< sum << endl;
    return 0;
}

