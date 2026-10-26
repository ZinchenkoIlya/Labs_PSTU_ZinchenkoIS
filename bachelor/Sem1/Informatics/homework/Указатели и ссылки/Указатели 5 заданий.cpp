using namespace std;
#include <iostream>
int main()
{
    //1

    // int a = 10;
    // int b = 20;
    // int& r = a;
    // r = b;
    // r++;
    // std::cout << a << " " << b;

    //2

    // int a = 12;
    // int* ptr = &a;
    // int copy = *ptr;
    // (*ptr)++;
    // std::cout << a << " " << copy;

    //3

    // int a = 4, b = 9;
    // int* p = &a;
    // int* q = p;
    // int& r = *p;
    // p = &b;
    // *q += *p;
    // *p = r - 3;
    // q = p;
    // *q += r;
    // cout << a << " " << b << " " << r;

    //4

    // int a = 5, b = 8;
    // int& r = a;
    // int& s = a;
    // int copy = a;
    // r = b;
    // s += 2;
    // b = copy;
    // cout << a << " " << b << " " << r << " " << s << " " << copy;

    //5

    int a = 2, b = 5, c = 8;
    int* p = &a;
    int& r = a;
    int copy = *p;
    *p = b;
    p = &c;
    r = *p;
    *p = b + copy;
    p = &b;
    *p = r - copy;
    r++;
    cout << a << " " << b << " " << c << " " << copy;


}