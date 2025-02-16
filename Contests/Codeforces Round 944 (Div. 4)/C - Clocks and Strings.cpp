#include<bits/stdc++.h>

using namespace std; 

string resolver(){
    int a = 0, b = 0, c = 0, d = 0; 
    cin >> a >> b >> c >> d;
    int min1 = min(a,b); 
    int max1 = max(a,b);  
    int contador = 0; 
    for (int f = min1; f < max1; f++){
        if (f == c || f == d) 
            contador++; 
    }
    if (contador == 1)
        return "YES"; 
    return "NO"; 
}

int main(){

    int t; 
    cin >> t; 
    vector<string> resultados(t);
    for (int f = 0; f < t; f++){
        resultados[f] = resolver();
    }
    for (const auto &x: resultados){
        cout << x << '\n'; 
    }
    return 0; 
}