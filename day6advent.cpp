#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

#define MAX_SIZE 130  // Tamaño máximo para el mapa

// Estructura para almacenar la posición de la guardia
struct punto {
    int x, y;
};

// Función para imprimir el mapa
void imprime(char mapa[][MAX_SIZE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

// Función para simular el movimiento de la guardia
int simular_guardia(char mapa[][MAX_SIZE], int filas, int columnas, punto* guardia) {
    // Direcciones: 0 = arriba, 1 = derecha, 2 = abajo, 3 = izquierda
    int direccion = 0;  // Inicialmente mirando hacia arriba
    int visitadas = 0;
    int dentro = 0;
    // Array de movimientos según las direcciones
    int movimientos[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while(dentro==0){
    // Set para rastrear posiciones visitadas
    if(direccion==0){
        if(mapa[(guardia->x)-1][(guardia->y)]=='#'){
            direccion++;
        }
        else{
        mapa[guardia->x][guardia->y]='X';
        guardia->x--;
        }
    }
    if(direccion==1){
        if(mapa[guardia->x][(guardia->y)+1]=='#'){
            direccion++;
        }
        else{
        mapa[guardia->x][guardia->y]='X';
        guardia->y++;
        }
    }
    if(direccion==2){
        if(mapa[(guardia->x)+1][(guardia->y)]=='#'){
            direccion++;
        }
        else{
        mapa[guardia->x][guardia->y]='X';
        guardia->x++;
        }
    }
    if(direccion==3){
        if(mapa[(guardia->x)][(guardia->y)-1]=='#'){
            direccion=0;
        }
        else{
        mapa[guardia->x][guardia->y]='X';
        guardia->y--;
        }
    }
    if((guardia->x) >= 130 || (guardia->y)>= 130 ||(guardia->x) < 0||(guardia->y)< 0){
        for (int i = 0; i < 130; i++) {
        for (int j = 0; j < 130; j++) {
            if (mapa[i][j] == 'X') {
                visitadas++;
                
            }
        }
    }
    return visitadas;
    }
    imprime(mapa, MAX_SIZE, MAX_SIZE);
    printf("\n %d,%d \n", guardia->x, guardia->y);
    }
    return -1;
}

int main() {
    ifstream file("input2.txt");
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return 1;
    }

    // Variables para almacenar el mapa y sus dimensiones
    
    string linea;
    int filas = 0;
    int columnas = 0;


    char mapa[MAX_SIZE][MAX_SIZE];
    while (getline(file, linea)) {
        for (int i = 0; i < linea.length() && i < MAX_SIZE; i++) {
            mapa[filas][i] = linea[i];
        }
        filas++;
    }
    imprime(mapa, MAX_SIZE, MAX_SIZE);
    // Buscamos la posición inicial de la guardia
    punto guardia;
    bool encontrado = false;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
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

    // Simulamos el movimiento de la guardia
    int visitadas = simular_guardia(mapa, filas, columnas, &guardia);

    // Imprimimos el resultado final
    cout << "La guardia visitó " << visitadas << " posiciones distintas.\n";
    imprime(mapa, filas, columnas);
    file.close();
    return 0;
}
