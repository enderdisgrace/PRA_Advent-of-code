#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Regla {
    int x;
    int y;
};

bool cumple_reglas(Regla* reglas, int num_reglas, int* secuencia, int tam_secuencia) {
    for (int i = 0; i < num_reglas; i++) {
        int x = reglas[i].x;
        int y = reglas[i].y;
        int pos_x = -1, pos_y = -1;

        
        for (int j = 0; j < tam_secuencia; j++) {
            if (secuencia[j] == x) pos_x = j;
            if (secuencia[j] == y) pos_y = j;
        }

        
        if (pos_x != -1 && pos_y != -1 && pos_x > pos_y) {
            return false;
        }
    }
    return true;
}

int get_sum(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    int capacidad_reglas = 100;
    Regla* reglas = new Regla[capacidad_reglas]; 
    int num_reglas = 0;
    int* secuencia = new int[100]; 
    int tam_secuencia = 0;
    string line;
    int sum = 0;

    // Leer reglas
    while (getline(file, line) && !line.empty()) {
        size_t pipe_pos = line.find('|'); 
        if (pipe_pos != string::npos) {  
            int x = stoi(line.substr(0, pipe_pos));  
            int y = stoi(line.substr(pipe_pos + 1)); 

            
            if (num_reglas >= capacidad_reglas) {
                capacidad_reglas *= 2; 
                Regla* nuevas_reglas = new Regla[capacidad_reglas];
                for (int i = 0; i < num_reglas; i++) {
                    nuevas_reglas[i] = reglas[i];
                }
                delete[] reglas;
                reglas = nuevas_reglas;
            }

            reglas[num_reglas].x = x;
            reglas[num_reglas].y = y;
            num_reglas++;
        } else {
            cerr << "Formato inválido en la línea de regla: " << line << endl;
        }
    }

    
    while (getline(file, line)) {
        istringstream iss(line);
        tam_secuencia = 0;
        int num;

        
        while (iss >> num) {
            secuencia[tam_secuencia++] = num;
            if (iss.peek() == ',') iss.ignore();
        }

        
        if (cumple_reglas(reglas, num_reglas, secuencia, tam_secuencia)) {
            int medio = secuencia[tam_secuencia / 2];
            sum += medio;
        }
    }

    
    delete[] reglas;
    delete[] secuencia;

    return sum;
}

int main() {
    cout << get_sum("input.txt") << endl;
    return 0;
}
