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

vector<string> inorderTraversal(Node* root) {
    if (!root)
        return {}; 
    vector<string> resultados{}; 
    for (const auto& x: inorderTraversal(root->left))
        resultados.push_back(x); 
    resultados.push_back(root->data); 
    for (const auto& x: inorderTraversal(root->right))
        resultados.push_back(x); 
    // for (const auto& x: resultados)
    //     cout << x; 
    // cout << "\n"; 
    return resultados; 
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

    vector<string> respuestas{}; 
    respuestas = inorderTraversal(&a);

    for (const auto& x: respuestas)
        cout << x; 

    return 0; 
}