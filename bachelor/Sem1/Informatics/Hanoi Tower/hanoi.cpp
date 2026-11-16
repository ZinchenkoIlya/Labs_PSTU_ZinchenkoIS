#include <iostream>
#include <clocale>
using namespace std;


int st[3][5] = {0}; 
void draw() 
{
    for (int level = 4; level >= 0; level--)
    {
        for (int r = 0; r < 3; r++) 
        {
            int disk = st[r][level];
            if (disk == 0) 
                cout << "         ";
            else 
            {
                int left_spaces = (9 - disk) / 2;
                int right_spaces = 9 - disk - left_spaces;
                
                for (int i = 0; i < left_spaces; i++) 
                    cout << " ";
                for (int i = 0; i < disk; i++) 
                    cout << "*";
                for (int i = 0; i < right_spaces; i++) 
                    cout << " ";
            }
            cout << " ";
        }
        cout << "\n";
    }
    cout << "--------- --------- ---------\n";
    cout << "    1         2         3    \n\n";
}
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
    int from = s - 1, to = p - 1;
    int pos = 0;
    while (st[from][pos] != 0) 
        pos++;
    int disk = st[from][pos - 1];
    st[from][pos - 1] = 0;
    pos = 0;
    while (st[to][pos] != 0) 
        pos++;
    st[to][pos] = disk;
    cout << ++step << ". " << n << "-й диск: " << s << " -> " << p << "\n";
    draw();
    han(n - 1, t, p, s, step);            //n-1 дисков с временного на конечный
}
int main()
{
    int step = 0;
    for (int i = 0; i < 5; i++) st[0][i] = 5 - i;
    draw();
    han(5, 1, 3, 2, step);     //5 колец c первого стержня перенести на третий стержень
    cout << "\nВсего ходов: " << step << "\n";
    return 0;
}
