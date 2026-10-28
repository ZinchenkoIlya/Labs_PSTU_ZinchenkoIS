#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() 
{
    double a = 0.1, b = 1.0, t = 0.0001;
    int k = 10, n = 25;
    double h = (b - a) / k;
    double pi = acos(-1.0);

    cout << fixed << setprecision(6);

    for (int i = 0; i <= k; i++) //Диапазон x
    {
        double x = a + i * h;

        // а) Сумма для заданного n
        double SN = 1.0, c = 1.0;
        for (int j = 1; j <= n; j++) 
        {
            c *= x / j;
            SN += c * cos(j * pi / 4.0);
        }

        // б) Сумма для заданной точности
        double SE = 1.0;
        c = x;
        int j = 1;
        double ts = c * cos(j * pi / 4.0);
        while (fabs(ts) > t || j <= n) 
        {
            SE += ts;
            j++;
            c *= x / j;
            ts = c * cos(j * pi / 4.0);
        }

        double Y = exp(x*cos(pi / 4.0)) * cos(x * sin(pi / 4.0)); //Точное значение функции
        cout << "X=" << x << "  SN=" << SN << "  SE=" << SE << "  Y=" << Y << "\n";
    }

    return 0;
}

