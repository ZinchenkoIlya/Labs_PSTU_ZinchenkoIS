#include <iostream>
#include <clocale>
using namespace std;

int main(){
    setlocale(LC_ALL,".UTF8");
    int m, n;
    cout << "Введите m: ";
    cin >> m;
    cout << "Введите n: ";
    cin >> n;

    //1. m - ++n
    {
        int m1=m, n1=n; //создал копии переменных, чтобы не менялись первоначальные переменные
        int r=m1 - ++n1;
        cout << "1. m - ++n = " << r << " , m = " << m1 << " , n = " << n1 << endl;
    }
    //2. ++m > --n
    {
        int m2=m, n2=n;
        bool r=++m2 > --n2;            
        cout << "2. ++m > --n = " << boolalpha << r << " , m = " << m2 << " , n = " << n2 << endl; 
    }
    //2. --n < ++m
    {
        int m3=m, n3=n;
        bool r=--n3 < ++m3;
        cout << "3) --n < ++m = " << boolalpha << r << " , m = " << m3 << " , n = " << n3 << endl;
    }
    return 0;
}