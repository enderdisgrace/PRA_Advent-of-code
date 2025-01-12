#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
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

        // Si x y y están en la secuencia y x aparece después de y, no cumple las reglas
        if (pos_x != -1 && pos_y != -1 && pos_x > pos_y) {
            return false;
        }
    }
    return true;
}

// Función para aplicar merge sort mientras respetamos las reglas de las dependencias
void merge(vector<int>& arr, int l, int m, int r, unordered_map<int, set<int>>& grafo, unordered_map<int, int>& grado_entrada) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        
        if (grado_entrada[L[i]] <= grado_entrada[R[j]]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función recursiva de merge sort con divide y venceras
void mergeSort(vector<int>& arr, int l, int r, unordered_map<int, set<int>>& grafo, unordered_map<int, int>& grado_entrada) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergeSort(arr, l, m, grafo, grado_entrada);  
        mergeSort(arr, m + 1, r, grafo, grado_entrada); 
        
        merge(arr, l, m, r, grafo, grado_entrada);  
    }
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

    
    unordered_map<int, set<int>> grafo;
    unordered_map<int, int> grado_entrada;

    
    for (int i = 0; i < num_reglas; i++) {
        grafo[reglas[i].x].insert(reglas[i].y);
        grado_entrada[reglas[i].y]++;
        if (grado_entrada.find(reglas[i].x) == grado_entrada.end()) {
            grado_entrada[reglas[i].x] = 0;  
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

        
        if (!cumple_reglas(reglas, num_reglas, secuencia, tam_secuencia)) {
           
            vector<int> secuencia_v(secuencia, secuencia + tam_secuencia);
            mergeSort(secuencia_v, 0, secuencia_v.size() - 1, grafo, grado_entrada);

            
            int medio = secuencia_v[secuencia_v.size() / 2];
            sum += medio;
            printf("Sumo %d\n", medio);
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
