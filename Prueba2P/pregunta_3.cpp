#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int valor;
    std::cout << "Ingrese un valor entre 1 y 20: ";
    std::cin >> valor;
    std::string categoria = 
        (valor >= 1 && valor <= 5)   ? "Deficiente" :
        (valor >= 6 && valor <= 10)  ? "Regular" :
        (valor >= 11 && valor <= 15) ? "Bueno" :
        (valor >= 16 && valor <= 18) ? "Muy Bueno" :
        (valor > 18 && valor <= 20)  ? "Excelente" :
       "Valor fuera de rango";

    std::cout << "El numero pertenece a la categoria: " << categoria << std::endl;


}
