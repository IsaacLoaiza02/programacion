#include <iostream>
using namespace std;
struct persona
{
    string nombre="Sin nombre";
    int edad=0;
    float estatura=0.0;
};

struct 
{
    string nombre;
    float nota;
}e1, e2;

void registro()
{
    persona p5,p6;
}

main()
{
    //typedef persona personas;
    //typedef int entero;

    persona persona3, persona4;
    persona3.nombre="Carlos Ortiz";
    persona3.edad=28;
    persona3.estatura=1.90;
    cout<<"nombre="<<persona3.nombre<<endl;
    cout<<"edad="<<persona3.edad<<endl;
    cout<<"estatura="<<persona3.estatura<<endl;
    cout<<"datos personales2: "<<endl;
    cout<<"Nombre: ";
    getline(cin,persona4.nombre);
    cout<<"Edad: ";
    cin>>persona4.edad;
    cout<<"Estatura: ";
    cin>>persona4.estatura;
    cout<<"datos ingresados: "<<endl;
    cout<<"nombre="<<persona3.nombre<<"\t";
    cout<<"edad="<<persona3.edad<<"\t";
    cout<<"estatura="<<persona3.estatura<<"\n"; 
    cout<<"nombre="<<persona4.nombre<<"\t";
    cout<<"edad="<<persona4.edad<<"\t";
    cout<<"estatura="<<persona4.estatura<<endl;
    cout <<"Datos del estudiante No. 1: "<<endl;
    cout<<"Nombre: ";
    cin.ignore();
    getline(cin,e1.nombre); 
    cout<<"Nota: ";
    cin>>e1.nota;
}