#include <bits/stdc++.h>
#include <queue>
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


vector<string> breadthFirstValues(Node* root){
    // cout << "Prueba" << "\n";
    vector<string> valores{}; 
    queue<Node*> nodos {}; 
    if (root)
        nodos.push(root); 
    while (nodos.size() > 0){
        Node* current = nodos.front(); 
        nodos.pop(); 
        valores.push_back(current->data); 
        if (current->left)
            nodos.push(current->left); 
        if (current->right)
            nodos.push(current->right); 
    }
    return valores; 
}

int main(){
    // cout << "Prueba" << "\n";

    std::cin.tie(nullptr); 
    std::ios_base::sync_with_stdio(false);

    // cout << "Prueba" << "\n";

    Node a("a");
    Node b("b"); 
    Node c("c");
    Node d("d"); 
    Node e("e");
    Node f("f"); 

    a.left = &b; 
    a.right = &c; 
    b.left = &d; 
    b.right = &e; 
    c.right = &f; 

    //                 a
    //                / \
    //               b   c
    //              / \   \
    //             d   e   f 

    for(auto nodo: breadthFirstValues(&a)){
        cout << nodo << "\n";
    }

    return 0; 
}