#include <bits/stdc++.h>
using namespace std; 

class Node{
    public: 
        string data; 
        Node* left; 
        Node* right; 
        Node(string paramData){
            data = paramData; 
            left = nullptr;
            right = nullptr;
        }
}; 

void preorderTraversal(Node* root){
    if (!root) return; 
    cout << root->data /*<< "\n"*/; 
    preorderTraversal(root->left);
    preorderTraversal(root->right); 
}

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false); 

    Node a("A"); 
    Node b("B"); 
    Node c("C");
    Node d("D"); 
    Node e("E"); 
    Node f("F"); 

    a.left = &b; 
    a.right = &c; 
    b.left = &d; 
    b.right = &e; 
    e.left = &f; 

    //                 a
    //                / \
    //               b   c
    //              / \   
    //             d   e 
    //                /   
    //               f

    preorderTraversal(&a);

    return 0; 
}