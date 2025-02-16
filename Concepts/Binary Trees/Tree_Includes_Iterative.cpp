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

bool incluyeLetra(Node* root, string buscar){
    queue<Node*> nodos{}; 
    if (root)
        nodos.push(root);
    else    
        return false; 
    while(nodos.size() > 0){
        Node* current = nodos.front(); 
        nodos.pop(); 
        if (current->data == buscar) return true; 
        if (current->left) nodos.push(current->left); 
        if (current->right) nodos.push(current->right);
    }

    return false; 
}

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false); 

    string letra{};

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

    cin >> letra; 

    cout << incluyeLetra(&a, letra) << "\n"; 

    return 0; 
}