#include <bits/stdc++.h>
using namespace std; 

#define ll long long

void resolver(ll n, ll q, vector<ll>& results, int& iresults){
    vector<ll> a(n+1); 
    vector<ll> sums(2*n + 1, 0);
    
    for (int f = 1; f <= n; f++){
        cin >> a[f]; 
        sums[f] = a[f] + sums[f-1]; 
    }

    for (int f = 1; f <= n; f++)
        sums[f+n] = a[f] + sums[f+n-1]; 

    while (q--){
        ll l = 0, r = 0; 
        cin >> l >> r; 

        l--; r--; 

        ll i = l/n, j = r/n; 
        ll frep = j-i+1; 

        l%=n; 
        r%=n; 

        ll result = sums[n]*frep - (sums[i+l]-sums[i]) - (sums[j+n] - sums[j+r+1]);
        results[iresults++] = result; 
    }
}

int main(){
    int t = 0; 
    cin >> t; 
    int iresults = 0; 
    vector<ll> results(2*1e5 + 1);
    for (int f = 0; f < t; f++){
        ll n = 0, q = 0; 
        cin >> n >> q; 
        resolver(n,q,results,iresults); 
    }
    for (int f = 0; f < iresults; f++)
        cout << results[f] << '\n'; 
    return 0; 
}