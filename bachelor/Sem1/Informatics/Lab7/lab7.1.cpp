#include <iostream>
#include <clocale>
using namespace std;

double resd, resm;

double raz(double a, double b) 
{
    return a - b;
}

void raz(double ad, double am, double bd, double bm)
{
    resd = ad - bd;
    resm = am - bm;
}

int main() 
{
    setlocale(LC_ALL,".UTF8");
    double a, b;
    cout << "Введите два вещественных числа: \n";
    cin >> a >> b;
    cout << "\na) Разность вещественных чисел: " << a << " - " << b << " = " << raz(a, b) << endl << endl;

    double ad, am, bd, bm;
    cout << "Введите действительную и мнимую части первого комплексного числа: \n";
    cin >> ad >> am;
    cout << "Введите действительную и мнимую части второго комплексного числа: \n";
    cin >> bd >> bm;

    raz(ad, am, bd, bm);

    cout << "\nб) Разность комплексных чисел: (" << ad << " + " << am << "i) - (" << bd << " + " << bm << "i) = " << resd << " + " << resm << "i" << endl;
    return 0;
}
