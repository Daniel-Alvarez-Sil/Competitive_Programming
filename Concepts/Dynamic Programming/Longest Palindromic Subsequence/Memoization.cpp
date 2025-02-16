#include <bits/stdc++.h>
using namespace std; 

int lpsrec(const string& s, int lo, int hi, vector<vector<int>>& memo){
    // Base Case 1: If there is only one number
    if (lo == hi) return 1; 
    // Base Case 2: If there are only two numbers and they are the same
    if (lo + 1 == hi && s[lo] == s[hi]) return 2; 
    // Fetching the value of the memo, if it exists
    if (memo[lo][hi] != -1)
        return memo[lo][hi]; 
    // Case 3: If there is more than 2 numbers and the ends match
    if (s[lo] == s[hi])
        return memo[lo][hi] = lpsrec(s, lo + 1, hi - 1, memo) + 2;
    // Case 4: If there is more than 2 numbers and the ends dont match
    return memo[lo][hi] = max(lpsrec(s, lo + 1, hi, memo), lpsrec(s, lo, hi - 1, memo)); 
    
}

int lps(const string& s){
    int n = s.size(); 
    vector<vector<int>> memo(n, vector<int>(n, -1)); 
    return lpsrec(s, 0, n - 1, memo);  
}

int main(){
    string s = "SAWAS";
    cout << "The longest subsequence existing in the string is of size: " << lps(s); 
    return 0;  
}