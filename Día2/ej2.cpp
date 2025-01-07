#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> //Para sort
#include <cmath> // Para absolute value
#include <stdexcept>
#include <sstream> //Para coger líneas

using namespace std;


int safes_check(string filename){
    ifstream file(filename);
    int anterior,temp,num,safes,ascend,i;
    string line;
    
    while (getline(file, line)) {
        istringstream snum(line);//diseccionar
        ascend=0;
        i=0;
        anterior=0;
        while(snum>>num){
            if(anterior==0){anterior=num;continue;} //Para el primero
            i++;
            temp=abs(anterior-num);
            if(temp>3 || temp<1){break;}
            if(num<anterior){ascend--;}
            if(num>anterior){ascend++;}
            anterior=num;
        }
        if(ascend==i||ascend==-i){safes++;}//Si todos eran ascend o descend
    
    }
        return safes;
}




int main(){


cout<<safes_check("input2.txt")<<endl;


    return 0;
}
