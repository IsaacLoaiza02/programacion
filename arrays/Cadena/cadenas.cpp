#include <iostream>
using namespace std;
void llenarCadena(char cad[], int n=50)
{
    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cad, n);
    cin.clear();
} 

int longitudCadena(char cad[])
{
    int contador=0;
    for (int i=0; cad[i]!='\0'; i++)
        contador++;
    return contador;
}
//CORREGIR EL CODIGO PARA QUE CUENTE LA CANTIDAD DE PALABRAS EN UNA CADENA
int contarPalabras(const char cad[])
{
    int palabras = 0;
    int longitudPalabra = 0; 
    bool enPalabra = false;

    for (int i = 0; cad[i] != '\0'; i++)
    {
        if (cad[i] != ' ')  
        {
            if (!enPalabra)  
            {
                enPalabra = true;
                longitudPalabra = 1; 
            }
            else
            {
                longitudPalabra++; 
            }
        }
        else  
        {
            if (enPalabra && longitudPalabra > 1) 
            {
                palabras++;
            }
            enPalabra = false;
        }
    }

    if (enPalabra && longitudPalabra > 1)
    {
        palabras++;
    }

    return palabras;
}



main ()
{  
    char palabras[50];
    llenarCadena(palabras);
    cout << "La cadena ingresada es: " << palabras << endl;
    cout << "La longitud de la cadena es: " << longitudCadena(palabras) << endl;
    cout << "La cantidad de palabras en la cadena es: " << contarPalabras(palabras) << endl;

}