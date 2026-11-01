#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    int a[7] = {11, -20, 35, 43, 50, -16, 39};
    int kmx = 1, kmn = 1, max = a[0], min = a[0], imx = 0, imn = 0;
    cout << "Исходный массив: ";
    for (int i=0; i<7; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            imx = i;
            kmx = 1;
        }
        else if (a[i] == max)
            kmx++;
        if (a[i] < min)
        {
            min = a[i];
            imn = i;
            kmn = 1;
        }
        else if (a[i] == min)
            kmn++;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Минимальный элемент массива: " << min << endl;
    cout << "Количество минимальных элементов массива: " << kmn << endl;
    cout << "Индекс первого минимального элемента массива: "<< imn << endl;
    cout << "Максимальный элемент массива: " << max << endl;
    cout << "Количество максимальных элементов массива: " << kmx << endl;
    cout << "Индекс первого максимального элемента массива: "<< imx << endl;
    return 0;
}