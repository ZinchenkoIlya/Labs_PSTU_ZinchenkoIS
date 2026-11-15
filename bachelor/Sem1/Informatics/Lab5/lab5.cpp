#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10; //ограниче для матрицы

int s(int a[MAX][MAX], int n, int m) //функция s для поиска седловых точек в матрице
{
    int count = 0;
    cout << "\nСедловые точки:\n";
    cout << " \n";
    
    //перебор каждого элемента матрицы
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //выделение минимального и максимального в строке
            int imn = a[i][0];
            int imx = a[i][0];
            for (int k = 0; k < m; k++)
            {
                if (a[i][k] < imn) 
                    imn = a[i][k];
                if (a[i][k] > imx) 
                    imx = a[i][k];
            }
            //выделение минимального и максимального в столбце
            int jmn = a[0][j];
            int jmx = a[0][j];
            for (int l = 0; l < n; l++)
            {
                if (a[l][j] < jmn) 
                    jmn = a[l][j];
                if (a[l][j] > jmx) 
                    jmx = a[l][j];
            }
            
            int val = a[i][j]; //текущее значение
            bool f1 = (val == imn && val == jmx);
            bool f2 = (val == imx && val == jmn);
            if (f1 || f2)
            {
                count++;
                cout << "Точка №" << count << ": a[" << i << "][" << j << "] = " << val;
                if (f1)
                    cout << "  (min в строке, max в столбце)";
                if (f2) 
                    cout << "  (max в строке, min в столбце)";
                cout << "\n";
            }
        }
    }
    if (count == 0)
        cout << "Седловых точек не найдено.\n";
    return count;
}

void matrix(int a[MAX][MAX], int n, int m)// Функция вывода матрицы
{
    cout << "\nМатрица " << n << "x" << m << ":\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(5) << a[i][j];
        cout << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, ".UTF8");
    int n, m;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;

    if (n <= 0 || n > MAX || m <= 0 || m > MAX)
    {
        cout << "Недопустимый размер матрицы!\n";
        return 1;
    }
    int a[MAX][MAX];
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    matrix(a, n, m);
    int count = s(a, n, m);
    cout << "\nВсего седловых точек: " << count << "\n";
    return 0;
}
