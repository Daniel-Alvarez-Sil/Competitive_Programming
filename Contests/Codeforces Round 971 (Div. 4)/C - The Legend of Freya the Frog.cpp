#include <bits/stdc++.h>
using namespace std; 

int resolver(long int x, long int y, long int k){
    long int divx = ceil(((float)x)/k); 
    long int divy = ceil(((float)y)/k); 
    long int diff = abs(divx - divy);
    int aux = divy < divx ? 1 : 0; 
    return divx + divy + diff - aux; 
}

int main(){
    int t = 0; 
    cin >> t; 
    vector<long int> resultados(t); 
    for (int f = 0; f < t; f++){
        long int x = 0, y = 0, k = 0;
        cin >> x >> y >> k;  
        resultados[f] = resolver(x,y,k); 
    }
    for (const auto& r: resultados)
        cout << r << '\n';
    return 0; 
}