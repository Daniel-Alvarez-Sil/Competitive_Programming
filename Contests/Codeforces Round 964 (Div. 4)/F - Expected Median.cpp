#include <bits/stdc++.h>

using namespace std; 

int resolver(){
    vector<int> a(2);
    vector<int> b(2);
    int respuesta = 0; 
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    for (int f = 0; f < 2; f++){
        for (int j = 0; j < 2; j++){
            int f2 = f == 0 ? 1 : 0; 
            int j2 = j == 0 ? 1 : 0; 
            if (a[f2] > b[j2] && a[f] > b[j]
                || (a[f2] >= b[j2] && a[f] > b[j])
                || (a[f2] > b[j2] && a[f] >= b[j])) respuesta++;
        }
    } 
    return respuesta; 
}

int main(){
    int t = 0; 
    cin >> t; 
    vector<int> respuestas(t);
    for (int f = 0; f < t; f++)
        respuestas[f] = resolver();
    for (const auto& x: respuestas)
        cout << x << '\n'; 
    return 0; 
}