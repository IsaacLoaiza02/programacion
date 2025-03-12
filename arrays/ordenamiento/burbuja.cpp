//https://github.com/IsaacLoaiza02/programacion.git
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std; 
void llenarVector(int v[],int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        //v[i]=rand()%20+1;
       cin>>v[i];
    }
}
int ordenarBurbujav1(int v[], int n){
    int aux, contador=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            contador++;
                if(v[j]<v[j+1]){
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux;
                }
        }
    }
        return contador;
}
int ordenarBurbujav2(int v[], int n){
    int mejora=1;
    int aux, contador=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-mejora;j++){
            contador++;
                if(v[j]<v[j+1]){
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux;
                }
        }
          mejora++;
    }
        return contador;
}
void verDatos(int v[], int ne){
    cout<<"Los elemenetos del vector son: "<<endl;
    for(int i=0;i<ne;i++){
        cout<<v[i]<<" "<<endl;
    }
}
int ordenarBurbujav3(int v[], int n){
    int mejora=1;
    bool cambio=true;
    int aux, contador=0;
    for(int i=0;i<n && cambio;i++){
        cambio =false;
        for(int j=0;j<n-mejora;j++){
            contador++;
                if(v[j]<v[j+1]){
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux;
                    cambio=true;
                }
        }
          mejora++;
    }
        return contador;
}
main(){
    int ne;
    cout<<"Numero de elementos: ";
    cin>>ne;
int vec[ne];
llenarVector(vec,ne);
cout<<"Vector original: "<<endl;
verDatos(vec,ne);
ordenarBurbujav1(vec,ne);
cout<<"El nro de comparacionde elementos v1 :"<<ordenarBurbujav1(vec,ne)<<endl;
cout<<"El nro de comparacionde elementos v2 :"<<ordenarBurbujav2(vec,ne)<<endl;
cout<<"El nro de comparacionde elementos v3 :"<<ordenarBurbujav3(vec,ne)<<endl;
cout<<"Vector ordenado: "<<endl;
verDatos(vec,ne);
}


