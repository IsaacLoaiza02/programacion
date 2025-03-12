#include <iostream>
#include <string.h>
using namespace std;
int compararCadenas(char cad1[], char cad2[])
{
    return strcmp(cad1, cad2);
}   

void copiarCadena(char cad1[], char cad2[])
{
    strcpy(cad1, cad2);
}

void añadeCadena(char cad1[], char cad2[])
{
    strcat(cad1, cad2);
}

bool alfabeticoNumerico(char cad1[])
{
    bool alfaNumerico = true;
    for (int i = 0; i < strlen(cad1); i++)
    {
        if (!isalnum(cad1[i]))
        {
            return false;
        }
    }
    return true;
}

bool alfabetico(char cad1[])
{
    bool alfa = true;
    for (int i = 0; i < strlen(cad1); i++)
    {
        if (!isalpha(cad1[i])==false)
        {
            alfa=false;
            break;
        }
    }
    return alfa;
}   

bool numerico(char cad1[])
{
    bool numerico = true;
    for (int i = 0; i < strlen(cad1); i++)
    {
        if (!isdigit(cad1[i])==false)
        {
            numerico=false;
            break;
        }
    }
    return numerico;
}

bool espacios(char cad1[])
{
    bool espacios = true;
    for (int i = 0; i < strlen(cad1); i++)
    {
        if (!isspace(cad1[i])==false)
        {
            espacios=false;
            break;
        }
    }
    return espacios;
}

main ()
{
    char cad1[50],cad2[50],cad3[50];
    int comparacion;
    cout<<"Ingrese la primera cadena: ";
    cin.getline(cad1, 50);
    cout<<"Ingrese la segunda cadena: ";    
    cin.getline(cad2, 50);
    comparacion	= compararCadenas(cad1, cad2);
    cout<<"comparacion: "<<comparacion<<endl;   
    (comparacion == 0) ? cout<<"Las cadenas son iguales" : cout<<"Las cadenas son diferentes";
    //copiarCadena(cad1, cad2);
    //cout<<"\nCadena copiada: c1= "<<cad1;
    // añadeCadena(cad1, cad2);
    //cout<<"\nCadena añadida: c1= "<<cad1;
    (alfabeticoNumerico(cad1)) ? cout<<"\nLa cadena"<<cad1<<" es alfanumerica" : cout<<"\nLa cadena"<<cad1<<" no es alfanumerica";
    (alfabetico(cad1)) ? cout<<"\nLa cadena"<<cad1<<" es alfabetica" : cout<<"\nLa cadena"<<cad1<<" no es alfabetica";  
    (numerico(cad1)) ? cout<<"\nLa cadena"<<cad1<<" es numerica" : cout<<"\nLa cadena"<<cad1<<" no es numerica";
    (espacios(cad1)) ? cout<<"\nLa cadena"<<cad1<<" tiene espacios" : cout<<"\nLa cadena"<<cad1<<" no tiene espacios";
}