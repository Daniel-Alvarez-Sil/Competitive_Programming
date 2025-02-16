#include <bits/stdc++.h>
using namespace std; 

// Length of the longest palindromic subsequence
int lps(const string& s, int lo, int hi){
    // Base Case 1: If there is only 1 character
    if (lo == hi)
        return 1; 
    // Base Case 2: If there are only 2 characters and they are the same
    if (s[lo] == s[hi] && lo + 1 == hi)
        return 2; 
    // Base Case 3: If the first and last characters match
    if (s[lo] == s[hi]){
        return lps(s, lo + 1, hi - 1) + 2; 
    }
    // Base Case 4: If the first and last characters do not match
    return max(lps(s, lo, hi - 1), lps(s, lo + 1, hi));
    
}

int main() {
    string s = "SABCDEFS"; 
    int n = s.size(); 
    cout << "The length of the LPS is: " << lps(s, 0, n - 1); 
    return 0; 
}