#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    int a[7] = {11, -20, 35, 43, 50, -16, 39};
    cout << "Исходный массив: ";
    for (int i = 0; i < 7; i++) 
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < 6; i++) 
    {
        int imn = i;   
        for (int j = i + 1; j < 7; j++) 
            if (a[j] < a[imn]) 
                imn = j;
        if (imn != i) 
        {
            int s = a[i];
            a[i] = a[imn];
            a[imn] = s;
        }
    }
    cout << "Отсортированный массив: ";
    for (int i = 0; i < 7; i++) 
        cout << a[i] << " ";
    return 0;
}