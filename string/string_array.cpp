#include <iostream>
using namespace std;

void cambiarString(string nombres)
{
    nombres= "Sin nombre";

}

void cambiarArray(char apellido[])
{
    /*apellido[0]='A';
    apellido[1]='l';
    apellido[2]='v';
    apellido[3]='a';
    apellido[4]='r';
    apellido[5]='e';
    apellido[6]='z';
    apellido[7]='\0';*///caracter nulo para indicar el final de la cadena

    cout<<"Ingrese el nuevo apellido: ";
    cin.getline(apellido,20);
}

main()
{
    string nombres, apodo;
    string curso[5]={"C++","Java","Python","C#","PHP"};
    char apellido[20], APODO1[20];

    cout<<"Ingrese sus nombres: ";
    getline(cin,nombres);
    cout<<"Su nombre es: "<<nombres<<endl;
    cambiarString(nombres);
    cout<<"Su nombre es luego de llamar a la funcion: "<<nombres<<endl;

    cout<<"Ingrese sus apellido: ";
    cin.getline(apellido,20);
    cout<<"Su apellido inicial es: "<<apellido<<endl;
    cambiarArray(apellido);
    cout<<"Su apellido luego de llamar a la funcion es: "<<apellido<<endl;





   /* cout<<"Ingrese sus apellidos: ";
    cin.getline(apellido,20);
    cout<<"Su nombre es: "<<nombres<<endl;
    cout<<"Su apellido es: "<<apellido<<endl;
    cout<<"Su nombre completo es: "<<nombres<<" "<<apellido<<endl;
    cout<<"Ingrese su apodo: ";
    getline(cin,apodo);
    cout<<"Su apodo es: "<<apodo<<endl;
    apodo=nombres;*/
    //apellido=apodo¿; //NO SE PUEDE ASIGNAR UN STRING A UN CHAR \
    
}