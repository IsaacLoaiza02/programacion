//Actividad completar en la foto tomada 10:38 am 17/02/2025
#include <iostream>
#include <string>
using namespace std;

struct RegistroAutomovil {
    string codigoA;
    string marca;
    string modelo;
    int anyo;
    string placa;
};

struct ClienteVideoclub {
    string nombre;
    string direccion;
    string telefono;
    float adeuda;
    string codigoCliente;
};

struct LicenciaManejo {
    string nombres;
    string apellidoPaterno;
    string apellidoMaterno;
    string fechaDesde;
    string fechaVencimiento;
    string nacionalidad;
    string grupoSanguineo;
    string tipoLicencia;
    string restricciones;
    bool donaOrganos;
    string direccion;
    string cedula;
};

struct TarjetaCredito {
    string nombre;
    string fechaVencimiento;
    string numeroTarjeta;
    float saldo;
    float limite;
};

main() {

    RegistroAutomovil auto1 = {"A1234", "Toyota", "Corolla", 2020, "XYZ-987"};
    
    ClienteVideoclub cliente1 = {"Juan Perez", "Calle 123", "097849329", 250.75, "C456"};
    
    LicenciaManejo licencia1 = {
        "Ana luisa", "Gonzalez", "Martinez", "2006-01-06", "2033-01-06",
        "Ecuatoriana", "O+", "Tipo C", "Ninguna", false, "Av. Ruminahui 456", "2549302948"
    };
    
    TarjetaCredito tarjeta1 = {"Luis Alcivar", "2033-01-06", "4567-8912-3456-7890", 15000.50, 20000.00};

    // Imprimir datos de un ejemplo
    cout << "Registro de Automovil: "<< auto1.codigoA << ", " << auto1.marca << " " << auto1.modelo << ", Año " << auto1.anyo << ", Placa: " << auto1.placa << endl;
    cout << "Cliente de Videoclub: " << cliente1.nombre << ", deuda: $" << cliente1.adeuda << endl;
    cout << "Licencia de Manejo: " << licencia1.nombres << " " << licencia1.apellidoPaterno << ", Tipo: " << licencia1.tipoLicencia << endl;
    cout << "Tarjeta de Credito: " << tarjeta1.nombre << ", Saldo: $" << tarjeta1.saldo << ", Limite: $" << tarjeta1.limite << endl;

}
