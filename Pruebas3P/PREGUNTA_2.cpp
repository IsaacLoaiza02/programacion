#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string toLower(const string& s) {
    string res = s;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] >= 'A' && res[i] <= 'Z')
            res[i] = res[i] + ('a' - 'A');
    }
    return res;
}

vector<string> split(const string& s, char delim) {
    vector<string> tokens;
    size_t start = 0, pos;
    while ((pos = s.find(delim, start)) != string::npos) {
        tokens.push_back(s.substr(start, pos - start));
        start = pos + 1;
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

struct ProductoTotal {
    string producto;
    int total;
};

struct SucursalRevenue {
    string sucursal;
    double revenue;
};

void x() {
    ifstream infile("empresa.txt");
    if (!infile.is_open()) {
        cout << "No se pudo abrir empresa.txt" << endl;
        return;
    }

    vector<ProductoTotal> productos;
    vector<SucursalRevenue> sucursales;
    int totalSur = 0;
    int totalTecladoNorte = 0;

    string line;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        vector<string> campos = split(line, '\t');
        if (campos.size() != 5 && campos.size() != 6) continue;

        int cant;
        double precio;
        string producto, sucursal;

        try {
            cant = stoi(campos[campos.size() == 6 ? 3 : 2]);
            precio = stod(campos[campos.size() == 6 ? 4 : 3]);
        } catch (...) {
            continue;
        }

        producto = campos[1];
        sucursal = campos[campos.size() == 6 ? 5 : 4];

        bool encontrado = false;
        for (int i = 0; i < productos.size(); i++) {
            if (productos[i].producto == producto) {
                productos[i].total += cant;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            productos.push_back({producto, cant});
        }

        string sucLower = toLower(sucursal);
        if (sucLower == "sur") totalSur += cant;
        string prodLower = toLower(producto);
        if (prodLower == "teclado" && sucLower == "norte") totalTecladoNorte += cant;

        bool sucEncontrada = false;
        for (int j = 0; j < sucursales.size(); j++) {
            if (sucursales[j].sucursal == sucursal) {
                sucursales[j].revenue += cant * precio;
                sucEncontrada = true;
                break;
            }
        }
        if (!sucEncontrada) {
            sucursales.push_back({sucursal, cant * precio});
        }
    }

    infile.close();

    double totalRevenue = 0.0;
    for (int i = 0; i < sucursales.size(); i++)
        totalRevenue += sucursales[i].revenue;

    string maxSucursal = "";
    double maxRevenue = -1;
    for (int i = 0; i < sucursales.size(); i++) {
        if (sucursales[i].revenue > maxRevenue) {
            maxRevenue = sucursales[i].revenue;
            maxSucursal = sucursales[i].sucursal;
        }
    }

    ofstream outfile("consolidado.txt");
    outfile << "Totales por producto:\n";
    for (int i = 0; i < productos.size(); i++)
        outfile << productos[i].producto << ": " << productos[i].total << "\n";
    outfile << "\nCantidad total de articulos en la sucursal Sur: " << totalSur << "\n";
    outfile << "Cantidad del articulo 'teclado' en la sucursal Norte: " << totalTecladoNorte << "\n\n";
    outfile << "Recaudacion por sucursal:\n";
    for (int i = 0; i < sucursales.size(); i++)
        outfile << sucursales[i].sucursal << ": " << sucursales[i].revenue << "\n";
    outfile << "\nRecaudacion total de la empresa: " << totalRevenue << "\n";
    outfile << "Sucursal con mayor recaudacion: " << maxSucursal << "\n";
    outfile.close();
}

int main() {
    x();
    return 0;
}