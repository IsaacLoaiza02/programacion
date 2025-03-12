#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>
using namespace std;

struct estudiante {
    string nombres;
    int id;
    float nota[3];
    float e_Estandarizar;  
    string categoria;  
};

void ingreso(estudiante student[], int n) {
    for (int i = 0; i < n; i++) {
        bool id_valido;
        do {
            cout << "Ingrese el id del estudiante : ";
            cin >> student[i].id;
            id_valido = true;

            for (int j = 0; j < i; j++) {
                if (student[j].id == student[i].id) {
                    cout << "El ID ya esta registrado, por favor ingrese otro.\n";
                    id_valido = false;
                    break;
                }
            }
        } while (!id_valido);

        cin.ignore(); 
        cout << "Ingrese el nombre y apellido del estudiante, por favor: ";
        getline(cin, student[i].nombres);

        for (int j = 0; j < 3; j++) {
            do {
                cout << "Ingrese la nota " << j + 1 << " : ";
                cin >> student[i].nota[j];
                if (student[i].nota[j] < 0 || student[i].nota[j] > 20) {
                    cout << "Nota inválida. Debe estar entre 0 y 20.\n";
                }
            } while (student[i].nota[j] < 0 || student[i].nota[j] > 20);
        }
    }
}

void mostrarregistro(estudiante student[], int n) {
    cout << left << setw(5) << "ID" 
         << setw(25) << " NOMBRES " 
         << setw(10) << " NOTAS " 
         << setw(10) << "PROMEDIO " 
         << setw(15) << "CATEGORIA" 
         << setw(10) << "Z" << endl;  
    cout << string(80, '-') << endl;  

    for (int i = 0; i < n; i++) {
        float promedio = (student[i].nota[0] + student[i].nota[1] + student[i].nota[2]) / 3.0;
        cout << left << setw(5) << student[i].id
             << setw(20) << student[i].nombres
             << setw(10) << student[i].nota[0] << " "  
             << setw(10) << student[i].nota[1] << " "
             << setw(10) << student[i].nota[2] 
             << fixed << setprecision(2) << setw(10) << promedio
             << setw(15) << student[i].categoria   
             << setw(10) << fixed << setprecision(2) << student[i].e_Estandarizar << endl; 
    }
}

estudiante& BuscarestudianteID(estudiante student[], int n, int a) {
    for (int i = 0; i < n; i++) {
        if (student[i].id == a) {
            return student[i];
        }
    }
    static estudiante vacio;
    vacio.id = -1;  
    return vacio;  
}

void modificacion(estudiante student[], int n) {
    int id, op, notas;
    cout << "Ingrese el id del estudiante del registro que quiere modificar: ";
    cin >> id;
    estudiante& encontrado = BuscarestudianteID(student, n, id);

    if (encontrado.id == -1) {
        cout << "Estudiante no encontrado.\n";
        return;
    }

    cout << "Estudiante encontrado, elija que desea modificar: ";
    cout << "\n 1. Nombre";
    cout << "\n 2. Nota\n";
    cin >> op;

    switch (op) {
        case 1:
            cin.ignore();  
            cout << "Ingrese el nuevo nombre: ";
            getline(cin, encontrado.nombres);
            break;
        case 2:
            cout << "Ingrese que nota desea modificar (1, 2 o 3): ";
            cin >> notas;
            if (notas >= 1 && notas <= 3) {
                cout << "Ingrese la nueva nota " << notas << ": ";
                cin >> encontrado.nota[notas - 1];
            } else {
                cout << "Opcion invalida.\n";
            }
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
    }
}

float calcularMedia(estudiante students[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += (students[i].nota[0] + students[i].nota[1] + students[i].nota[2]) / 3.0;
    }
    return suma / n;
}

float CalcularDesviacionEstandar(estudiante students[], float media, int n) {
    float sumaDesviacion = 0;
    for (int i = 0; i < n; i++) {
        float promedio = (students[i].nota[0] + students[i].nota[1] + students[i].nota[2]) / 3.0;
        sumaDesviacion += (promedio - media) * (promedio - media);
    }
    return sqrt(sumaDesviacion / n); 
}

void condicion(estudiante students[], int n){
    if (n == 0) { 
        return;
    }

    float media = calcularMedia(students, n);
    float desviacion = CalcularDesviacionEstandar(students, media, n);

    for (int i = 0; i < n; i++) {  
        float promedio = (students[i].nota[0] + students[i].nota[1] + students[i].nota[2]) / 3.0;
        students[i].e_Estandarizar = (desviacion == 0.0) ? 0.0 : (promedio - media) / desviacion;

        if (students[i].e_Estandarizar >= 1.0) {
            students[i].categoria = "A";
        } else if (students[i].e_Estandarizar >= 0.0) {
            students[i].categoria = "B";
        } else if (students[i].e_Estandarizar>= -1.0) {
            students[i].categoria = "C";
        } else {
            students[i].categoria = "D";
        }
    }
}

void eliminarEstudiante(estudiante students[], int &n) {
    if (n == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    int id;
    cout << "\nIngrese el ID del estudiante a eliminar: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Estudiante no encontrado.\n";
        return;
    }
    for (int i = index; i < n - 1; i++) {
        students[i] = students[i + 1];
    }

    n--; 
    cout << "Estudiante eliminado correctamente.\n";
}


void menu(estudiante students[], int &n) {
    int opcion;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "Ingrese la opcion que desee: \n";
        cout << "1. Ingresar estudiantes\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Modificar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Salir\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el numero de estudiantes a registrar: ";
                cin >> n;
                ingreso(students, n);
                condicion(students, n);  
                break;
            case 2:
                mostrarregistro(students, n);
                break;
            case 3:
                modificacion(students, n);
                break;
            case 4:
                eliminarEstudiante(students, n);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);  
}

int main() {
    int n = 0;
    estudiante estudiantes[100];
    menu(estudiantes, n);
    return 0;

}