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
    vector<string> resultado; 
    vector<Node*> stack;
    if (root)
        stack.push_back(root); 
    while(stack.size() > 0){
        Node* current = stack[stack.size() - 1];
        stack.pop_back(); 
        resultado.push_back(current->data);
        if(current->right)
            stack.push_back(current->right);
        if(current->left)
            stack.push_back(current->left);

    }
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

    //                 af
    //                / \
    //               b   c
    //              / \   \
    //             d   e   f 

    for(auto nodo: depthFirstValues(&a)){
        cout << nodo << "\n"; 
    }

    return 0; 
}