#include <bits/stdc++.h>
using namespace std;

int resolver(string &palabra){
    int n = palabra.size(); 
    int dp[n][n];
    
    for (int f = 0; f < n; f++)
        dp[f][f] = 1; 

    for (int f = n - 2; f >= 0; f--){
        for (int j = f + 1; j < n; j++){
            if (palabra[f] == palabra[j]){
                dp[f][j] = (j-f == 1) ? 2 : dp[f+1][j-1] + 2;  
            } else{
                dp[f][j] = max(dp[f+1][j], dp[f][j-1]);
            }
        }
    } 
    return dp[0][n-1]; 
}

int main(){
    string prueba = "awsaawa";
    cout << "Longest Palindromic Subsequence: " << resolver(prueba);
    return 0; 
}