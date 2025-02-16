#include <bits/stdc++.h>

using namespace std;

int resolver(){
    string p;
    cin >> p;
    int a = p[0]-48;
    int b = p[1]-48;
    int resultado = a+b;
    return resultado;
}

int main(){
    int c;
    cin >> c;
    vector<int> danysil{};
    for(int i = 0; i<c;i++) danysil.push_back(resolver());
    for(const auto& x : danysil)
        cout << x << '\n';
    

}

