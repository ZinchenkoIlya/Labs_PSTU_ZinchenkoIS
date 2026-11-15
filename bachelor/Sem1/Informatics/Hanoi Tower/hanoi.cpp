#include <iostream>
#include <clocale>
using namespace std;

//n-количество дисков
//s-начальный стержень
//p-конечный стержень
//t-временный стержень
void han(int n, int s, int p, int t, int &step)
{
    setlocale(LC_ALL,".UTF8");
    if (n == 0)
        return;
    han(n - 1, s, t, p, step);            //n-1 дисков с начального на временный
    cout << ++step << ". " << n << "-й диск: " << s << " -> " << p << "\n";
    han(n - 1, t, p, s, step);            //n-1 дисков с временного на конечный
}

int main()
{
    int step = 0;
    han(5, 1, 3, 2, step);     //5 колец c первого стержня перенести на третий стержень
    cout << "\nВсего ходов: " << step << "\n";
    return 0;
}
