#include <iostream>
#define MAX 50
using namespace std;
void llenaTabla(int tabla[][MAX], int f, int c)
{
    for (int i=0; i<f; i++)
    {
        for (int j=0; j<c; j++)
        {
            cout<<"Introduce el valor de la posicion ["<<i<<"]["<<j<<"]: " ;
            cin>>tabla[i][j];
        }
    }
}
void ImprimeTabla(int tabla[][MAX],int f, int c)
{
    for (int i=0; i<f; i++)
    {
        for (int j=0; j<c; j++)
        {
            cout<<tabla [i][j]<<"\t";
        }
        cout<<endl;
    }
}
main()
{
    int tabla[MAX][MAX], filas,columnas;
    cout<<"Introduzca numero de filas: ";
    cin>> filas;
    cout<<"Introduzca numero de columnas: ";
    cin>>columnas;
    llenaTabla(tabla,filas,columnas);
    ImprimeTabla(tabla,filas,columnas);
}