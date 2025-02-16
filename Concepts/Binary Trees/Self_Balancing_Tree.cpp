// Altura de cada nodo
int height(node *N){
    if (!N)
        return -1; 
    return N->ht; 
}

// Crear un nodo 
node* newNode(int val){
    node *n = new node(); 
    n->val = val; 
    n->left = nullptr; 
    n->right = nullptr; 
    n->ht = 0; 
    return n; 
}

// Rotar hacia la derecha 
node* rightRotate(node *padre){
    node *hijo = padre->left; 
    node *tree2 = hijo->right; 
    
    // Realizamos rotacion
    hijo->right = padre; 
    padre->left = tree2; 
    
    // Actualizamos las alturas
    padre->ht = max(height(padre->left), height(padre->right)) + 1;
    hijo->ht = max(height(hijo->left), height(hijo->right)) + 1; 
    
    return hijo;     
}

// Rotar hacia la izquierda
node* leftRotate(node *padre){
    node *hijo = padre->right; 
    node *tree2 = hijo->left; 
    
    // Ejecutamos la rotacion
    hijo->left = padre; 
    padre->right = tree2; // No pasa nada si el segund arbol es nulo
    
    // Actualizamos las alturas
    padre->ht = max(height(padre->left), height(padre->right)) + 1;
    hijo->ht = max(height(hijo->left), height(hijo->right)) + 1;
    
    return hijo; 
}

int getBalance(node *n){
    if (!n) return 0; 
    return height(n->left) - height(n->right);
} 



node * insert(node * root,int val)
{
    if (!root) return newNode(val);
    
    if (root->val > val)
        root->left = insert(root->left, val); 
    else 
        root->right = insert(root->right, val); 
    
    root->ht = max(height(root->left), height(root->right)) + 1;
    
    int balance = getBalance(root); 
    
    // Left Left Case
    if (balance > 1 && val < root->left->val)
        return rightRotate(root);
    
    // Right Right Case
    if (balance < -1 && val > root->right->val)
        return leftRotate(root);
    
    // Left Right Case
    if (balance > 1 && val > root->left->val){
        root->left = leftRotate(root->left); 
        return rightRotate(root);
    }
    
    // Right Left Case
    if (balance < -1 && val < root->right->val){
        root->right = rightRotate(root->right);
        return leftRotate(root); 
    }
    
    return root; 
  
}


// // Node is defined as :

// typedef struct node
// {
//     int val;
//     struct node* left;
//     struct node* right;
//     int ht;
// } node;

// node* rotar(node* root, int val){
//     node* abuelo = new node(); 
//     node* padre = new node();
//     node* hijo = new node();
//     node* ingreso = new node();
//     node* current = root; 
//     ingreso->val = val; 
//     if (root) hijo = root; 
//     while(current){
//         abuelo = padre; 
//         padre = hijo;
//         hijo = current; 
//         node* derecha = padre->right; 
//         node* izquierda = padre->left;
//         int iderecha = 0, iizquierda = 0; 
//         if (derecha) iderecha += derecha->ht;
//         else iderecha -= 1; 
//         if (izquierda) iizquierda += izquierda->ht; 
//         else iizquierda -= 1; 
//         if (current->val < val) {
//             current = derecha; 
//             iderecha++; 
//         }
//         else{
//             current = izquierda; 
//             iizquierda++; 
//         } 
//     }
    
//     cout << "Padre: " << padre->val << "\n"; 
//     cout << "Hijo: " << hijo->val << "\n"; 
    
//     ingreso->ht = hijo->ht + 1; 
    
//     if (hijo->val > val) hijo->left = ingreso; 
//     else hijo->right = ingreso; 
    
//     if ((padre != hijo) && !(padre->left && padre->right)){
//         cout << "Entramos a la primera condicion. \n";
//         int ipadre = padre->val, ihijo = hijo->val, iingreso = val;
//         if (ipadre > ihijo && ihijo < iingreso){
//             cout << "Entramos a la segunda condicion. \n";
//             hijo->val = iingreso; 
//             ingreso->val = ihijo; 
//             hijo->left = ingreso; 
//             hijo->right = nullptr;
//         }
//         else if (ipadre < ihijo && ihijo > iingreso){
//             cout << "Entramos a la segunda condicion. \n";
//             // padre->right = ingreso; 
//             // ingreso->right = hijo; 
//             hijo->val = iingreso; 
//             ingreso->val = ihijo; 
//             hijo->right = ingreso; 
//             hijo->left = nullptr; 
            
//         }
//         // hijo->right = nullptr; 
//         // hijo->left = nullptr; 
//         ipadre = padre->val, ihijo = hijo->val, iingreso = ingreso->val;
//         if (ihijo > ipadre){
//             hijo->left = padre;
//             padre->right = nullptr; 
//             // ingreso->right = hijo; 
//             // ingreso->left = padre; 
//             // padre->right = nullptr; 
//             // padre->left = nullptr; 
//             // padre = ingreso; 
//         }
//         else {
//             hijo->right = padre; 
//             padre->left = nullptr; 
//             // ingreso->right = padre; 
//             // ingreso->left = hijo; 
//             // padre->right = nullptr; 
//             // padre->left = nullptr; 
//             // padre = ingreso; 
//         }
//         if (hijo->val < abuelo->val) abuelo->left = hijo; 
//         else abuelo->right = hijo; 
//     }
    
    
//     return root; 
// }

// void depthPrint(node* root){
//     vector<node*> stack; 
//     if (root) stack.push_back(root); 
//     while(stack.size() > 0){
//         node* current = stack[stack.size() - 1]; 
//         stack.pop_back(); 
//         cout << "Valor: " << current->val << " - Altura: " << current->ht << "\n"; 
//         if (current->right) stack.push_back(current->right); 
//         if (current->left) stack.push_back(current->left); 
//     }
// }


// node *insertar(node * root, int val, int height){
//     if (!root) {
//         node* current = new node();
//         current->val = val; 
//         current->ht = height; 
//         return current; 
//     }
    
//     if (root->val > val){
//         root->left = insertar(root->left, val, root->ht + 1);
//     }
//     else {
//         root->right = insertar(root->right, val, root->ht + 1); 
//     }
    
//     return root; 
// }

// node * insert(node * root,int val)
// {
//     // root = insertar(root, val, 0); 
//     depthPrint(root); 
//     cout << "\n\n"; 
//     root = rotar(root, val); 
//     depthPrint(root); 
//     return root; 
  
// }