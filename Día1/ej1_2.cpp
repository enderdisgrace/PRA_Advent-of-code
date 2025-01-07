#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map> //Hash table para sacar frecuencia de aparición (similarities)
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

int calculateSimilarityScore(const vector<int> &list1, const vector<int> &list2) {
    unordered_map<int, int> frequencyMap;
    for (int num : list2) {
        frequencyMap[num]++;
    }
    int similarityScore = 0;
    for (int num : list1) {
        similarityScore += num * frequencyMap[num];
    }
    return similarityScore;
}

int main() {
    vector<int> list1, list2;
    try {
        readListsFromFile("input.txt", list1, list2);
        int similarityScore = calculateSimilarityScore(list1, list2);
        cout << "Puntaje de similitud: " << similarityScore << endl;
    } catch (const exception &e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
