#include <iostream>
#include <iomanip>
using namespace std;

struct estudiante{
    string nombre;
    int id;

    float notap;
};

main(){
    int ne;
    bool ordena=true;
    float suma=0,promedio=0;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>ne;
    estudiante estudiantes[ne],aux;
    for (int i = 0; i < ne; i++){
        cout<<"Ingrese el nombre del estudiante "<<i+1<<": ";
        cin.ignore();
        getline(cin,estudiantes[i].nombre);
        cin>>estudiantes[i].nombre;
        cout<<"Ingrese el id del estudiante "<<i+1<<": ";
        cin>>estudiantes[i].id;
        cout<<"Ingrese la nota del estudiante "<<i+1<<": ";
        cin>>estudiantes[i].notap;
    }
    cout<<" Los datos ingresados son: "<<endl;
    cout<<setw(5)<<"Nombre"<<setw(5)<<"Id"<<setw(5)<<"Nota"<<endl;
    for (int i = 0; i < ne; i++){
        cout<<setw(5);
        cout<<estudiantes[i].id<<setw(10);
        cout<<estudiantes[i].nombre<<setw(10);
        cout<<estudiantes[i].notap<<endl;
        suma+=estudiantes[i].notap;
    }
        cout<<"Promedio de notas= "<<(float)suma/ne<<endl;
        cout<<" Listado de estudiantes de mayor a menor nota"<<endl;
        for(int i=0;i<ne+1&&ordena;i++){
            ordena=false;
            for(int j=i+1;j<ne;j++){
                if(estudiantes[i].notap<estudiantes[j+1].notap){
                    estudiante aux=estudiantes[j+1];
                    estudiantes[j+1]=estudiantes[j];
                    estudiantes[j]=aux;
                    ordena=true;
                }
            }
        }
        for (int i = 0; i < ne; i++){
            cout<<setw(5);
            cout<<estudiantes[i].id<<setw(10);
            cout<<estudiantes[i].nombre<<setw(10);
            cout<<estudiantes[i].notap<<endl;
            suma+=estudiantes[i].notap;
        }
}