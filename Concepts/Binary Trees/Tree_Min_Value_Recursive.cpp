// Depth First Values Recursive Approach

#include <bits/stdc++.h>
#include <limits>
using namespace std; 

class Node{
    public: 
        int data; 
        Node* left; 
        Node* right; 
        Node(int paramData){
            data = paramData; 
            left = nullptr; 
            right = nullptr; 
        }
}; 

int min(vector<int> numeros){
    int min = 0; 
    if (numeros.size() > 0) min = numeros[0]; 
    for (auto num: numeros){
        if (num < min) min = num; 
    }
    return min; 
}

int treeMinValue(Node* root){
    if(!(root)) return std::numeric_limits<int>::max(); 
    int iLeft = treeMinValue(root->left); 
    int iRight = treeMinValue(root->right); 
    return min({root->data, iLeft, iRight}); 

}

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false); 

    Node a(1); 
    Node b(2); 
    Node c(3); 
    Node d(4); 
    Node e(5); 
    Node f(6); 
    Node g(7); 
    Node h(8); 
    Node i(-10); 

    a.left = &b;
    a.right = &c;
    b.left = &d; 
    b.right = &e; 
    d.left = &h; 
    c.left = &f; 
    c.right = &g; 
    f.left = &i;  


    //                 1
    //               /   \
    //              2     3
    //             / \   / \ 
    //            4  5   6  7
    //           /      /  
    //           8     -10
    // 
    // Respuesta: -10

    cout << treeMinValue(&a) << "\n"; 

    return 0; 
}
