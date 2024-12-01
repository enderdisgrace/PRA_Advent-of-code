#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> //Para sort
#include <cmath> // Para absolute value
#include <stdexcept>

using namespace std;

void readListsFromFile(const string &filename, vector<int> &list1, vector<int> &list2) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Error: No se pudo abrir el archivo '" + filename + "'.");
    }
    int num1, num2;
    while (file >> num1 >> num2) {
        list1.push_back(num1);
        list2.push_back(num2);
    }
    file.close();
}

int calculateAbsoluteDifferences(const vector<int> &list1, const vector<int> &list2) {
    int sumDifferences = 0;
    for (size_t i = 0; i < list1.size(); ++i) {
        sumDifferences += abs(list1[i] - list2[i]);
    }
    return sumDifferences;
}

int main() {
    vector<int> list1, list2;
    try {
        readListsFromFile("input.txt", list1, list2);
        if (list1.size() != list2.size()) {
            throw runtime_error("Error: Las listas tienen tamaños diferentes.");
        }
        sort(list1.begin(), list1.end()); //Libreía del algorythm
        sort(list2.begin(), list2.end());

        cout << "Lista 1 ordenada: ";
        for (int num : list1) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Lista 2 ordenada: ";
        for (int num : list2) {
            cout << num << " ";
        }
        cout << endl;

        int totalDifference = calculateAbsoluteDifferences(list1, list2);
        cout << "Suma total de las diferencias absolutas: " << totalDifference << endl;

    } catch (const exception &e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
