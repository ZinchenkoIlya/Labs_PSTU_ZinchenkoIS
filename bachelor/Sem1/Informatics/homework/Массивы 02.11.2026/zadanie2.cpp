#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    int a[7] = {11, -20, 35, 43, 50, -16, 39};
    bool f = true;
    int n = a[0];
    cout << "Исходный массив: ";
    for (int i=0; i < 7; i++)
    {
        if (a[i]<n)
            f = false;
        cout << a[i] << " ";
    }
    cout << endl;
    if (f)
        cout << "Массив упорядочен по возрастанию";
    else
        cout << "Массив не упорядочен по возрастанию";
    return 0;
}