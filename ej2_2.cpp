#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>  
#include <sstream> 
#include <string>

using namespace std;

bool is_safe(const vector<int>& report) {
    int n = report.size();
    if (n < 2) return false;

    int ascend = 0;
    for (int i = 1; i < n; i++) {
        int diff = abs(report[i] - report[i - 1]);
        if (diff < 1 || diff > 3) {
            return false;  
        }
        if (report[i] > report[i - 1]) ascend++;
        if (report[i] < report[i - 1]) ascend--;
    }
    return (ascend == n - 1 || ascend == -(n - 1));
}

//Bruteforce, pruebo a quitar cada nivel y si vale retorno true
bool is_safe_with_one_removal(const vector<int>& report) {
    int n = report.size();

    for (int i = 0; i < n; i++) {//Contador de qué nivel quitamos
        vector<int> mod_report;
        for (int j = 0; j < n; j++) {//Construyo el nuevo vector
            if (j != i) {
                mod_report.push_back(report[j]);
            }
        }
        if (is_safe(mod_report)) {
            return true; 
        }
    }
    return false;
}


int safes_check(string filename) {
    ifstream file(filename);
    int safes = 0;
    string line;

    while (getline(file, line)) {//Lo almacenamos primero en vector
        istringstream snum(line);
        vector<int> report;
        int num;

        while (snum >> num) {
            report.push_back(num); 
        }

        if (is_safe(report) || is_safe_with_one_removal(report)) {
            safes++;
        }
    }

    return safes;
}

int main() {
    cout << safes_check("input2.txt") << endl; 
    return 0;
}
