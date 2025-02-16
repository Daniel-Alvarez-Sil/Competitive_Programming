#include <bits/stdc++.h>
using namespace std; 

int lps(const string& s){
    int n = s.size(); 
    vector<vector<int>> dp(n, vector<int>(n));

    // Initialize all single character substrings as palindromes of length 1
    for (int i = 0; i < n; i++){
        dp[i][i] = 1; 
    }
    // The DP table is constructed for substrings of length 2 or more
    for (int i = n - 2; i >= 0; i--){
        for (int j = i + 1; j < n; j++){
            if (s[i]==s[j]){
                dp[i][j] = dp[i + 1][j - 1] + 2;
                cout << "dp[" << i << "][" << j << "] = " << "dp[" << i+1 << "][" << j-1 << "] + 2 = " << dp[i][j] << '\n';

            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                cout << "dp[" << i << "][" << j << "] = " << "max(dp[" << i+1 << "][" << j << "], dp[" << i << "][" << j-1 << "]) =" << dp[i][j] << '\n';
            }
        }
        cout << "\n"; 
    }
    return dp[0][n-1]; 
}

int main(){
    string s = "abcdcaefgj"; 
    cout << "The length of the LPS is: " << lps(s); 
    return 0; 
}