#include <bits/stdc++.h>
using namespace std; 

void resolver(int n, vector<int>& array, vector<pair<int,int>>& queries){
    int dp[n][n]; 
    for (int f = 0; f < n; f++){
        for (int j = f + 1; j < n; j++){
            dp[f][j] = abs(array[f] - array[j]); 
        }
    }

    for (int f = 2; f < n; f++){
        for (int j = f; j < n; j++){
            int i = j-f; 
            dp[i][j] = min(dp[i][j], min(dp[i][j-1], dp[i+1][j])); 
        }
    }

    for (const auto& x: queries)
        cout << dp[x.first][x.second] << '\n'; 

}


int main(){
   int n = 0; 
   cin >> n; 
   vector<int> array(n);   

   for (auto& x: array){
    cin >> x; 
   }
   
   int q = 0; 
   cin >> q; 
   vector<pair<int,int>> queries(q); 
   
   for (int f = 0; f < q; f++){
    int a = 0, b = 0; 
    cin >> a >> b; 

    queries[f].first = a - 1; 
    queries[f].second = b - 1;     
   }

   resolver(n, array, queries);
   return 0;  
}