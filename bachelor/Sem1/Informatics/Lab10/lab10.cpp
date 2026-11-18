#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,".UTF8");
    int n, m, k;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;
    //формирование двумерного ДМ с рандомными числами
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 100;
    }
    cout << "\nИсходный массив:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "Введите номер строки для удаления (от 1 до " << n << "): \n";
    cin >> k;                      //k - номер строки для удаления
    //удаление строки с заданным номером
    if (k < 1 || k > n)
    {
        cout << "Неверный номер строки!" << endl;
        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
        return 0;
    }
    int idx = k - 1;        //из номера в индекс
    //создаём новый массив без удаляемой строки
    int** res = new int*[n - 1];
    int r = 0;
    for (int i = 0; i < n; i++) 
    {
        if (i == idx) 
            continue;
        res[r] = new int[m];
        for (int j = 0; j < m; j++)
            res[r][j] = a[i][j];
        r++;
    }

    cout << "\nМассив после удаления строки " << k << ":" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    for (int i = 0; i < n - 1; i++)
        delete[] res[i];
    delete[] res;
    return 0;
}
