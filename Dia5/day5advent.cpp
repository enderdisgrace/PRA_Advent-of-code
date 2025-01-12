#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool cumple_reglas(vector<pair<int, int>> reglas, vector<int> secuencia) {
    for (int i = 0; i < reglas.size(); i++) {
        int x = reglas[i].first;
        int y = reglas[i].second;
        auto pos_x = find(secuencia.begin(), secuencia.end(), x);
        auto pos_y = find(secuencia.begin(), secuencia.end(), y);

        if (pos_x != secuencia.end() && pos_y != secuencia.end()) {
            if (pos_x > pos_y) {
                return false; 
            }
        }
    }
    return true;
}

int get_sum(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1; 
    }
    vector<pair<int, int>> reglas;
    vector<int> secuencia;
    string line;
    int sum = 0;

    
    while (getline(file, line) && !line.empty()) {
        istringstream iss(line);
        int x, y;
        char sep;
        iss >> x >> sep >> y;
        reglas.push_back(make_pair(x, y));
    }

    
    while (getline(file, line)) {
        istringstream iss(line);
        int num;
        secuencia.clear();

        
        while (iss >> num) {
            secuencia.push_back(num);
            if (iss.peek() == ',') iss.ignore();
        }

        
        if (cumple_reglas(reglas, secuencia)) {
            int medio = secuencia[secuencia.size() / 2];
            sum += medio;
        }
    }

    return sum;
}

int main() {
    cout << get_sum("input.txt") << endl;
    return 0;
}
