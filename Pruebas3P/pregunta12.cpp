#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Articulo {
    string producto;
    int cantidad;
    double precio;
    string sucursal;
};

void leerDatos(vector<Articulo>& articulos) {
    articulos = {
        {"Laptop", 5, 1200.00, "Norte"},
        {"Mouse", 15, 25.00, "Centro"},
        {"Teclado", 8, 45.00, "Sur"},
        {"Monitor", 3, 250.00, "Este"},
        {"Laptop", 2, 1200.00, "Centro"},
        {"Impresora", 4, 180.00, "Norte"},
        {"Mouse", 20, 25.00, "Sur"},
        {"Webcam", 6, 60.00, "Este"},
        {"Teclado", 10, 45.00, "Norte"},
        {"Monitor", 7, 250.00, "Centro"},
        {"Laptop", 3, 1200.00, "Sur"},
        {"Impresora", 2, 180.00, "Este"},
        {"Mouse", 12, 25.00, "Norte"},
        {"Webcam", 5, 60.00, "Centro"},
        {"Teclado", 6, 45.00, "Este"},
        {"Monitor", 4, 250.00, "Sur"},
        {"Laptop", 1, 1200.00, "Este"},
        {"Impresora", 3, 180.00, "Centro"},
        {"Mouse", 8, 25.00, "Este"},
        {"Webcam", 7, 60.00, "Sur"}
    };
}

void calcularTotalesPorArticulo(const vector<Articulo>& articulos, vector<int>& totales) {
    for (int i = 0; i < 6; ++i) {
        totales[i] = 0;
    }

    for (const auto& articulo : articulos) {
        if (articulo.producto == "Laptop") totales[0] += articulo.cantidad;
        else if (articulo.producto == "Mouse") totales[1] += articulo.cantidad;
        else if (articulo.producto == "Teclado") totales[2] += articulo.cantidad;
        else if (articulo.producto == "Monitor") totales[3] += articulo.cantidad;
        else if (articulo.producto == "Impresora") totales[4] += articulo.cantidad;
        else if (articulo.producto == "Webcam") totales[5] += articulo.cantidad;
    }
}

void calcularRecaudacionesPorSucursal(const vector<Articulo>& articulos, vector<double>& recaudaciones) {
    for (int i = 0; i < 4; ++i) {
        recaudaciones[i] = 0.0;
    }

    for (const auto& articulo : articulos) {
        double ingreso = articulo.cantidad * articulo.precio;
        if (articulo.sucursal == "Norte") recaudaciones[0] += ingreso;
        else if (articulo.sucursal == "Centro") recaudaciones[1] += ingreso;
        else if (articulo.sucursal == "Sur") recaudaciones[2] += ingreso;
        else if (articulo.sucursal == "Este") recaudaciones[3] += ingreso;
    }
}

int encontrarSucursalMayorRecaudacion(const vector<double>& recaudaciones) {
    int sucursalMax = 0;
    for (int i = 1; i < 4; ++i) {
        if (recaudaciones[i] > recaudaciones[sucursalMax]) {
            sucursalMax = i;
        }
    }
    return sucursalMax;
}

void guardarResultadosEnArchivo(const string& nombreArchivo, 
                                 const vector<int>& totales, 
                                 const vector<int>& sucursalSur, 
                                 const int cantidadTecladoNorte, 
                                 const vector<double>& recaudaciones, 
                                 double recaudacionTotalEmpresa, 
                                 int sucursalMayorRecaudacion) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        archivo << "Totales de cada articulo:\n";
        archivo << "Laptop: " << totales[0] << "\n";
        archivo << "Mouse: " << totales[1] << "\n";
        archivo << "Teclado: " << totales[2] << "\n";
        archivo << "Monitor: " << totales[3] << "\n";
        archivo << "Impresora: " << totales[4] << "\n";
        archivo << "Webcam: " << totales[5] << "\n";

        archivo << "\nCantidad total de articulos en la sucursal Sur:\n";
        archivo << "Laptop: " << sucursalSur[0] << "\n";
        archivo << "Mouse: " << sucursalSur[1] << "\n";
        archivo << "Teclado: " << sucursalSur[2] << "\n";
        archivo << "Monitor: " << sucursalSur[3] << "\n";
        archivo << "Impresora: " << sucursalSur[4] << "\n";
        archivo << "Webcam: " << sucursalSur[5] << "\n";

        archivo << "\nCantidad de articulos 'Teclado' en la sucursal Norte: " << cantidadTecladoNorte << "\n";

        archivo << "\nRecaudacion total de cada sucursal:\n";
        archivo << "Norte: $" << recaudaciones[0] << "\n";
        archivo << "Centro: $" << recaudaciones[1] << "\n";
        archivo << "Sur: $" << recaudaciones[2] << "\n";
        archivo << "Este: $" << recaudaciones[3] << "\n";

        archivo << "\nRecaudacion total de la empresa: $" << recaudacionTotalEmpresa << "\n";
        archivo << "Sucursal de mayor recaudacion: Sucursal " << (sucursalMayorRecaudacion + 1) << "\n";

        archivo.close();
        cout << "Datos guardados en " << nombreArchivo << "\n";
    } else {
        cout << "No se pudo abrir el archivo para escribir.\n";
    }
}

int main() {
    vector<Articulo> articulos;
    vector<int> totales(6);  
    vector<double> recaudaciones(4);  

    
    leerDatos(articulos);


    calcularTotalesPorArticulo(articulos, totales);

    
    calcularRecaudacionesPorSucursal(articulos, recaudaciones);

   
    double recaudacionTotalEmpresa = 0;
    for (double rec : recaudaciones) {
        recaudacionTotalEmpresa += rec;
    }

    
    vector<int> sucursalSur(6);
    for (int i = 0; i < 6; ++i) {
        sucursalSur[i] = 0;
    }

    for (const auto& articulo : articulos) {
        if (articulo.sucursal == "Sur") {
            if (articulo.producto == "Laptop") sucursalSur[0] += articulo.cantidad;
            else if (articulo.producto == "Mouse") sucursalSur[1] += articulo.cantidad;
            else if (articulo.producto == "Teclado") sucursalSur[2] += articulo.cantidad;
            else if (articulo.producto == "Monitor") sucursalSur[3] += articulo.cantidad;
            else if (articulo.producto == "Impresora") sucursalSur[4] += articulo.cantidad;
            else if (articulo.producto == "Webcam") sucursalSur[5] += articulo.cantidad;
        }
    }

    
    int cantidadTecladoNorte = 0;
    for (const auto& articulo : articulos) {
        if (articulo.sucursal == "Norte" && articulo.producto == "Teclado") {
            cantidadTecladoNorte += articulo.cantidad;
        }
    }

    
    int sucursalMayorRecaudacion = encontrarSucursalMayorRecaudacion(recaudaciones);

    guardarResultadosEnArchivo("consolidado.txt", totales, sucursalSur, cantidadTecladoNorte, recaudaciones, recaudacionTotalEmpresa, sucursalMayorRecaudacion);

    return 0;
}
