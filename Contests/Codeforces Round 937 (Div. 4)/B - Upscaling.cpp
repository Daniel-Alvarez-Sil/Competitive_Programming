#include <bits/stdc++.h>

using namespace std; 

void printhash(){
    cout << "##"; 
}

void printdot(){
    cout << ".."; 
}

void printspace(){
    cout << '\n'; 
}

void resolver(int n){
    if (n == 1){
        printhash(); 
        printspace(); 
        printhash(); 
        printspace(); 
        return; 
    }
    int iswitch = 1; 
    int isconst = 1; 
    for (int f = 0; f < n; f++){
        if (f % 2) isconst = 0; 
        else isconst = 1; 
        for (int j = 0; j < 2; j++){
            iswitch = isconst; 
            for (int k = 0; k < n; k++){
                if (iswitch){
                    iswitch = 0; 
                    printhash(); 
                }
                else{
                    printdot(); 
                    iswitch = 1; 
                }
            }
            printspace(); 
        }
    }
}

int main(){
    int t = 0; 
    cin >> t; 
    vector<int> tests(t); 
    for (int f = 0; f < t; f++)
        cin >> tests[f]; 
    for (int f = 0; f < t; f++) 
        resolver(tests[f]); 
    return 0; 
}