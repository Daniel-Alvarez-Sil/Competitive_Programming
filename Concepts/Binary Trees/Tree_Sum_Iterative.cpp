// Breadth First Values Approach

#include <bits/stdc++.h>
#include <queue>
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
    if(!(root))
        return 0; 
    int suma = 0; 
    queue<Node*> nodos{}; 
    nodos.push(root);
    while(nodos.size() > 0){
        Node* current = nodos.front(); 
        nodos.pop(); 
        suma += current->data; 
        if (current->left) nodos.push(current->left);
        if (current->right) nodos.push(current->right);

    }
    return suma; 
}


int main(){
    return 0; 
}