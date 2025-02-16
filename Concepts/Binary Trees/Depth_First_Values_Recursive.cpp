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

vector<string> depthFirstValues(Node* root){
    if (!(root))
        return {};
    vector<string> izquierda = depthFirstValues(root->left);
    vector<string> derecha = depthFirstValues(root->right);
    vector<string> resultado{}; 
    resultado.push_back(root->data); 
    for (auto valor: izquierda)
        resultado.push_back(valor); 
    for (auto valor: derecha) 
        resultado.push_back(valor);         
    return resultado;
}


int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false); 

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

    for(auto nodo: depthFirstValues(&a)){
        cout << nodo << "\n"; 
    }

    return 0; 
}