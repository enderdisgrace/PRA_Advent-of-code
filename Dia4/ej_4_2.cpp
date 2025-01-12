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
    for (int y = 1; y < n-1; y++) {
        for (int x = 1; x < content[y].size() -1; x++) {
            if (content[y][x] == 'A') {
                if (content[y - 1][x + 1] == 'M' && content[y - 1][x - 1] == 'M' && content[y + 1][x - 1] == 'S' && content[y + 1][x + 1] == 'S') {
                    count
                    ++;
                }
                if (content[y - 1][x + 1] == 'S' && content[y - 1][x - 1] == 'S' && content[y + 1][x - 1] == 'M' && content[y + 1][x + 1] == 'M') {
                    count++;
                }
                if (content[y - 1][x + 1] == 'M' && content[y - 1][x - 1] == 'S' && content[y + 1][x - 1] == 'S' && content[y + 1][x + 1] == 'M') {
                    count++;
                }
                if (content[y - 1][x + 1] == 'S' && content[y - 1][x - 1] == 'M' && content[y + 1][x - 1] == 'M' && content[y + 1][x + 1] == 'S') {
                    count++;
                }
            }
        }
    }

    // Resultado
    cout << "Total encontrado: " << count << endl;
    return 0;
}
