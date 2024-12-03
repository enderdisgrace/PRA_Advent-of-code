#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    int sum = 0;
    int a = 0;
    int b = 0;
    bool enabled = true;
    ifstream inputFile("input.txt");
    string content;
    if(inputFile.is_open()){
        string line;
        while(getline(inputFile,line)){
            content += line;
        }
        inputFile.close();
    } else{
        cout << "No se pudo abrir el archivo input.txt" << endl;
        return -1;
    }

    for(int i = 0; i + 7 < content.size(); i++){
        if(content[i] == 'd' && content[i+1] == 'o' && content[i+2] == '(' && content[i+3] == ')'){
            enabled = true;
            i+=3;
        }

        if(content[i] == 'd' && content[i+1] == 'o' && content[i+2] == 'n' && content[i+3] == '\'' && content[i+4] == 't' && content[i+5] == '(' && content[i+6] == ')'){
            enabled = false;
            i+=6;
        }

        a  = 0;
        b = 0;
        if(content[i] == 'm' && content[i+1] == 'u' && content[i+2] == 'l' && content[i+3] == '(' && isdigit(content[i+4]) && enabled){
            i+=4;
            while(isdigit(content[i]) && i < content.size()){
                a = a*10+((content[i] - '0'));
                i++;
            }
        }
        if(content[i] == ',' && isdigit(content[i+1]) && enabled){
            i+=1;
            while(isdigit(content[i]) && i < content.size()){
                b = b*10+((content[i] - '0'));
                i++;
            }
            if(content[i] == ')'&& enabled){
                sum += (a*b);
            }
        }
    }
    cout << sum << endl;
    return 0;
}