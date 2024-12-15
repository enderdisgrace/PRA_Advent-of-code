#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int count = 0;
    vector<string> content;
    ifstream inputFile("input.txt");

    // Leer archivo
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            content.push_back(line);
        }
        inputFile.close();
    } else {
        cout << "No se pudo abrir el archivo input.txt" << endl;
        return -1;
    }

    int n = content.size();

    // Verificar patrones en todas las direcciones
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < content[y].size(); x++) {
            if (content[y][x] == 'X') {
                // Hacia arriba
                if (y >= 3 && content[y - 1][x] == 'M' && content[y - 2][x] == 'A' && content[y - 3][x] == 'S') {
                    count++;
                }
                // Hacia abajo
                if (y + 3 < n && content[y + 1][x] == 'M' && content[y + 2][x] == 'A' && content[y + 3][x] == 'S') {
                    count++;
                }
                // Hacia la izquierda
                if (x >= 3 && content[y][x - 1] == 'M' && content[y][x - 2] == 'A' && content[y][x - 3] == 'S') {
                    count++;
                }
                // Hacia la derecha
                if (x + 3 < content[y].size() && content[y][x + 1] == 'M' && content[y][x + 2] == 'A' && content[y][x + 3] == 'S') {
                    count++;
                }
                // Diagonal arriba-derecha
                if (y >= 3 && x + 3 < content[y].size() &&
                    content[y - 1][x + 1] == 'M' && content[y - 2][x + 2] == 'A' && content[y - 3][x + 3] == 'S') {
                    count++;
                }
                // Diagonal arriba-izquierda
                if (y >= 3 && x >= 3 &&
                    content[y - 1][x - 1] == 'M' && content[y - 2][x - 2] == 'A' && content[y - 3][x - 3] == 'S') {
                    count++;
                }
                // Diagonal abajo-derecha
                if (y + 3 < n && x + 3 < content[y].size() &&
                    content[y + 1][x + 1] == 'M' && content[y + 2][x + 2] == 'A' && content[y + 3][x + 3] == 'S') {
                    count++;
                }
                // Diagonal abajo-izquierda
                if (y + 3 < n && x >= 3 &&
                    content[y + 1][x - 1] == 'M' && content[y + 2][x - 2] == 'A' && content[y + 3][x - 3] == 'S') {
                    count++;
                }
            }
        }
    }

    // Resultado
    cout << "Total encontrado: " << count << endl;
    return 0;
}
