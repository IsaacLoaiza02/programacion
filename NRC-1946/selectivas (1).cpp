#include <iostream>
using namespace std;

main()
{
    int num, r, num2;
    cout<< "ingrese primer numero";
    cin >> num;
    cout << "ingresar siguiente numero";
    cin >> num2;
    r = num % num2;
    if(r==0)
    {
        cout<< "el numero" << num << "es divisible para"<< num2 << endl;
    }
    else
    {
        cout << num << "no es divisible para" << num2 << endl;
    }
    num=06
}