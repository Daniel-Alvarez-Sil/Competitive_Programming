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

int max(vector<int> numeros){
    int max{}; 
    if(numeros.size() > 0) max = numeros[0]; 
    for(auto numero: numeros){
        if (numero > max) max = numero; 
    }
    return max; 
}

int maxPathSum(Node* root){
    if(!(root)) return -1 * std::numeric_limits<int>::max(); 
    if(!(root->left) && !(root->right)) return root->data; 
    int iLeft = maxPathSum(root->left); 
    int iRight = maxPathSum(root->right);
    return root->data + max({iLeft, iRight});  

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
    Node i(0); 

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
    //           8      0
    // 
    // Respuesta: 0

    // cout << "Prueba de ejecucion " << "\n"; 

    cout << maxPathSum(&a) << "\n"; 


    return 0; 
}