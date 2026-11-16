#include <iostream>
#include <clocale>
using namespace std;

template <typename T>
T mn(T a)
{
    return a;
}

template <typename T, typename... T1>
T mn(T first, T1... rest)
{
    T m = mn(rest...);
    if (first < m)
        return first;
    else
        return m;
}

void vvod(int a[], int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << i + 1 << ": ";
        cin >> a[i];
    }
}

int main()
{
    setlocale(LC_ALL, ".UTF8");
    int a[12];

    cout << "Введите 5 чисел:\n";
    vvod(a, 5);
    cout << "Минимум из 5 чисел = "
         << mn(a[0], a[1], a[2], a[3], a[4]) << "\n\n";

    cout << "Введите 10 чисел:\n";
    vvod(a, 10);
    cout << "Минимум из 10 чисел = "
         << mn(a[0], a[1], a[2], a[3], a[4],
               a[5], a[6], a[7], a[8], a[9]) << "\n\n";

    cout << "Введите 12 чисел:\n";
    vvod(a, 12);
    cout << "Минимум из 12 чисел = "
         << mn(a[0], a[1], a[2], a[3], a[4], a[5],
               a[6], a[7], a[8], a[9], a[10], a[11]) << "\n";

    return 0;
}
