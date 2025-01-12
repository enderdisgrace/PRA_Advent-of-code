#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

#define MAX_SIZE 130  // Tamaño máximo para el mapa


struct punto {
    int x, y;
};

// Función para imprimir el mapa
void imprime(char** mapa, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}


int simular_guardia(char** mapa, bool** visitado, int filas, int columnas, punto* guardia) {
    
    int direccion = 0;  // Inicialmente mirando hacia arriba
    int visitadas = 0;

    
    int movimientos[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    while (true) {
        // Marca la posición actual como visitada
        if (!visitado[guardia->x][guardia->y]) {
            visitado[guardia->x][guardia->y] = true;
            mapa[guardia->x][guardia->y] = 'X';
            visitadas++;
        }

        // Verifica si el guardia está fuera de los límites del mapa
        if (guardia->x < 0 || guardia->x >= filas || guardia->y < 0 || guardia->y >= columnas) {
            return visitadas;
        }

        
        int nx = guardia->x + movimientos[direccion][0];
        int ny = guardia->y + movimientos[direccion][1];

        if (nx >= 0 && nx < filas && ny >= 0 && ny < columnas && mapa[nx][ny] != '#') {
            
            guardia->x = nx;
            guardia->y = ny;
        } else {
            
            direccion = (direccion + 1) % 4;
        }
    }

    return -1;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return 1;
    }

    
    string linea;
    int filas = 0;
    int columnas = 0;

    
    while (getline(file, linea)) {
        columnas = max(columnas, (int)linea.length());
        filas++;
    }

    file.clear();
    file.seekg(0, ios::beg);

    
    char** mapa = new char*[filas];
    bool** visitado = new bool*[filas];
    for (int i = 0; i < filas; i++) {
        mapa[i] = new char[columnas]();
        visitado[i] = new bool[columnas]();
    }

    
    int fila = 0;
    while (getline(file, linea)) {
        for (int i = 0; i < linea.length(); i++) {
            mapa[fila][i] = linea[i];
        }
        fila++;
    }

    
    punto guardia;
    bool encontrado = false;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (mapa[i][j] == '^') {
                guardia.x = i;
                guardia.y = j;
                mapa[i][j] = '.';  // Reemplazamos '^' por '.' para no interferir en la simulación
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontró la guardia en el mapa.\n";
        return 1;
    }

 
    int visitadas = simular_guardia(mapa, visitado, filas, columnas, &guardia);

 
    cout << "La guardia visitó " << visitadas << " posiciones distintas.\n";
    imprime(mapa, filas, columnas);

    // Libera la memoria dinámica
    for (int i = 0; i < filas; i++) {
        delete[] mapa[i];
        delete[] visitado[i];
    }
    delete[] mapa;
    delete[] visitado;

    file.close();
    return 0;
}
