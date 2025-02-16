#include<bits/stdc++.h>
using namespace std; 

long long int resolver(long long int n, long long int k){
    long long int lo = 1; 
    long long int hi = n; 
    long long int curr = 1; 
    while(lo <= hi){
        long long int mid = lo + (hi - lo)/2; 
        long long int prefix = (k + k + mid - 1) * (mid/(long double)2); 
        long long int suffix = (k + k + n - 1) * (n/(long double)2) - prefix;
        // cout << mid << ": " << prefix << " - " << suffix << '\n'; 
        if (prefix < suffix)
        {
            curr = mid; 
            lo = mid + 1; 
        }
        else if (prefix > suffix){
            hi = mid - 1; 
        }
        else return 0; 
    }
    long long int prefix1 = (k + k + curr - 1) * (curr/(long double)2); 
    long long int suffix1 = (k + k + n - 1) * (n/(long double)2) - prefix1;
    long long int prefix2 = (k + k + (curr + 1) - 1) * ((curr + 1)/(long double)2); 
    long long int suffix2 = (k + k + n - 1) * (n/(long double)2) - prefix2;
    return min((suffix1-prefix1), (prefix2-suffix2)); 
}

int main(){
    int t = 0; 
    cin >> t; 
    vector<long long int> resultados(t); 
    for (int f = 0; f < t; f++)
    {
        long long int n = 0, k = 0;
        cin >> n >> k; 
        resultados[f] = resolver(n,k);
    }
    for (const auto &r: resultados)
        cout << r << '\n'; 
    return 0; 
}