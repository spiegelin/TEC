#include "BST.h"
#include <vector>
#include <fstream>

void BST::Insert(int& value, string& log, Node*& current){

    if (current == nullptr){
        current = new Node(value, log);
        return;
    }

    if (value < current->key){
        Insert(value, log, current->left);
    }else if (value > current->key){
        Insert(value, log, current->right);
    }else{
        current->logs.push_back(log);
        current->count++;
    }

}

void BST::DeleteNode(int& value, Node*& current){

    if (current == nullptr){
        cout << "Value not found" << endl;
        return;
    }

    if (value < current->key){
        DeleteNode(value, current->left);
    }else if (value > current->key){
        DeleteNode(value, current->right);
    }else{

        Node* aux = current;

        if (aux->right = nullptr){
            current = aux->left;
        }
        if (aux->left == nullptr){
            current = aux->right;
        }
        if (aux->left != nullptr && aux->right != nullptr){
            SubstituteToMin(current->right, aux);
        }

        delete aux;

    }

}

void BST::SubstituteToMin(Node*& curright, Node*& apAux){

    if (curright->left != nullptr){
        SubstituteToMin(curright->left, apAux);
    }else{
        apAux->key = curright->key;
        apAux = curright;
        curright = curright->right;
    }

}


void BST::DeleteBST(Node *&current){
    if (current == nullptr){
        return;
    }
    DeleteBST(current->left);
    DeleteBST(current->right);
    //cout << "Eliminando: "<< current->key << endl;
    delete current;
}

void BST::InOrder(Node* current){

    if (current == nullptr){
        return;
    }

    InOrder(current->left);
    cout << current->key << " ";
    InOrder(current->right);

}

void BST::PreOrder(Node* current){

    if (current == nullptr){
        return;
    }

    cout << current->key << " ";
    PreOrder(current->left);
    PreOrder(current->right);

}

void BST::PostOrder(Node* current){

    if (current == nullptr){
        return;
    }

    PostOrder(current->left);
    PostOrder(current->right);
    cout << current->key << " ";

}

void BST::BFT(){
    


    if (Root == nullptr){
        cout << "Empty"<<endl;
        return;
    }

    queue<Node*> q;

    q.push(Root);

    Node* aux;
    while (!q.empty()){

        q.push(nullptr);
        aux = q.front();
        while (aux!= nullptr){
            cout << aux->key << " ";
            if (aux->left != nullptr){
                q.push(aux->left);
            }
            if (aux->right != nullptr){
                q.push(aux->right);
            }
            q.pop();
            aux = q.front();
        }

        q.pop();

        cout << endl;

    }
    
}




void BST::FindLargestNodes(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    // Primero, recorremos el subárbol derecho
    FindLargestNodes(node->right);

    if (largestNodes.size() < 5) {
        largestNodes.push_back(*node);
    } else {
        // si se necesita, reeemplazar el nodo más pequeño
        for (int i = 0; i < 5; ++i) {
            if (node->count > largestNodes[i].count) {
                largestNodes[i] = *node;
                break;  
            }
        }
    }

    // recorrer subarbol izquierdo
    FindLargestNodes(node->left);
}

void BST::FindTop5Nodes() {
    largestNodes.clear();  // limpiar el vector
    FindLargestNodes(Root);
}

void BST::printTop5Nodes(ofstream& salida) {
    for (int i = 0; i < largestNodes.size(); ++i) {
        // Imprimir en consola
        cout << "Puerto: " << largestNodes[i].key << ", Cantidad: " << largestNodes[i].count << endl;

        // Guardar en el archivo de salida
        salida << "Puerto: " << largestNodes[i].key << ", Cantidad: " << largestNodes[i].count << endl;

        for (int j = 0; j < largestNodes[i].logs.size(); ++j) {
            // Imprimir en consola
            cout << largestNodes[i].logs[j] << endl;
            
            // Guardar en el archivo de salida
            salida << largestNodes[i].logs[j] << endl;
        }
        // Imprimir en consola
        cout << endl;

        // Guardar en el archivo de salida
        salida << endl;
    }
}