#include <bits/stdc++.h> // Importar librería 
using namespace std; // Comando para no tener que incluir el prefijo "std::"

// Funcion que recibe un palabra como parametro 
int resolver(string &palabra){
    // Cantidad de caractertes
    int n = palabra.size(); 
    // Inicializamos arreglo
    int dp[n][n];
    
    // Inicializamos subsecuencias de longitud 1 
    for (int f = 0; f < n; f++)
        dp[f][f] = 1; 

    // Resolución de Problema 
    for (int f = n - 2; f >= 0; f--){
        for (int j = f + 1; j < n; j++){
            if (palabra[f] == palabra[j]){
                dp[f][j] = (j-f == 1) ? 2 : dp[f+1][j-1] + 2;  
            } else{
                dp[f][j] = max(dp[f+1][j], dp[f][j-1]);
            }
        }
    } 
    // Obtención de Respuesta
    return dp[0][n-1]; 
}

int main(){
    string prueba = "awsaawa";
    cout << "Longest Palindromic Subsequence: " << resolver(prueba);
    return 0; 
}