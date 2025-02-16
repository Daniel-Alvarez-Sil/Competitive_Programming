#include <bits/stdc++.h>
using namespace std; 

long long int resolver(set<pair<long long int,long long int>>& puntos){
    long long int contador = 0; 
    long long int num = -1; 
    long long int contar = 0;
    long long int left = 0;  
    for (pair<long long int,long long int> p : puntos){
        left++; 
        contador += contar; 
        if (num == p.first){
            contar += 1; 
            contador += (left-2);
        }
        num = p.first; 
        if (puntos.count({p.first-1, (long long int)!((bool)p.second)}) && puntos.count({p.first+1, (long long int)!((bool)p.second)}))
            contador++; 
    }
    return contador; 
}

int main(){
    long long int t = 0; 
    cin >> t; 
    vector<long long int> resultados(t); 
    for (long long int f = 0; f < t; f++){
        long long int n = 0; 
        cin >> n; 
        set<pair<long long int,long long int>> puntos; 
        while (n--){
            long long int x = 0, y = 0; 
            cin >> x >> y; 
            puntos.insert({x,y});
        }
        resultados[f] = resolver(puntos);
    }
    for (const auto& r: resultados)
        cout << r << '\n'; 
    return 0; 
}