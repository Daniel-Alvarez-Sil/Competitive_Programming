// Depth First Values Recursive Approach

#include <bits/stdc++.h>
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

int sumaDeNodos(Node* root){
    if (!(root)) return 0; 
    return root->data + sumaDeNodos(root->left) + sumaDeNodos(root->right); 
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
    Node i(9); 

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
    //           8      9
    // 
    // Respuesta: 45

    cout << sumaDeNodos(&a) << "\n"; 

    return 0; 
}