#include <iostream>
#include <clocale>
using namespace std;

int main(){
    setlocale(LC_ALL,".UTF8");
    const int a=1000;
    const float fb=0.0001;
    const double db=0.0001;

    //float
    float fl_a3=a*a*a;     //это a^3
    float fl_b2=fb*fb;     //это b^2
    float fl_a2=a*a;       //это a^2
    float fl_b3=fb*fb*fb;  //это b^3
    float fchisl=(a-fb)*(a-fb)*(a-fb)-(fl_a3-3*a*fl_b2); //числитель дроби
    float fznam=fl_b3-3*fl_a2*fb;                        //знаменатель дроби
    float fl_result=fchisl/fznam;                         //искомое значение

    //double
    double dl_a3=a*a*a;     //это a^3
    double dl_b2=db*db;     //это b^2
    double dl_a2=a*a;       //это a^2
    double dl_b3=db*db*db;  //это b^3
    double dchisl=(a-db)*(a-db)*(a-db)-(dl_a3-3*a*dl_b2); //числитель дроби
    double dznam=dl_b3-3*dl_a2*db;                        //знаменатель дроби
    double dl_result=dchisl/dznam;                         //искомое значение
    cout << "Значение выражения для данных типа float: " << fl_result << endl;
    cout << "Значение выражения для данных типа double: " << dl_result << endl;
}