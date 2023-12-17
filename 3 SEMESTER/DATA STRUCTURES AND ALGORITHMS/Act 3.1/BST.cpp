#include "BST.hpp"
#include <queue>

// Destructor
BST::~BST() {
    DeleteBST(root);
    std::cout << "\nBST deleted. \n" << std::endl;
}

// Insert
void BST::Insert(int &value, Node *&currentNode) {
    if (currentNode == NULL) {
        currentNode = new Node(value);
    } else {
        if (value < currentNode->data) {
            Insert(value, currentNode->left);
        } else if (value > currentNode->data) {
            Insert(value, currentNode->right);
        } else {
            std::cout << "Repeated element" << std::endl;
        }
    }
}

// Inorder
void BST::Inorder(Node *currentNode) {
    if (currentNode == NULL) {
        return;
    }
    Inorder(currentNode->left);
    std::cout << currentNode->data << " ";
    Inorder(currentNode->right);
}

// Preorder
void BST::Preorder(Node *currentNode) {
    if (currentNode == NULL) {
        return;
    }
    std::cout << currentNode->data << " ";
    Preorder(currentNode->left);
    Preorder(currentNode->right);
}

// Postorder
void BST::Postorder(Node *currentNode) {
    if (currentNode == NULL) {
        return;
    }
    Postorder(currentNode->left);
    Postorder(currentNode->right);
    std::cout << currentNode->data << " ";
}

// BFT
void BST::BFT() {
    if (root == NULL) {
        std::cout << "Empty tree" << std::endl;
        return;
    }

    std::queue<Node*> Q;
    Q.push(root);

    Node *Aux;
    while (!Q.empty()) {
        Q.push(NULL);

        Aux = Q.front();
        while (Aux != NULL) {
            std::cout << Aux -> data << " ";

            if (Aux -> left != NULL) {
                Q.push(Aux -> left);
            }
            if (Aux -> right != NULL) {
                Q.push(Aux -> right);
            }

            Q.pop();
            Aux = Q.front();
        }
        Q.pop();

        std::cout << std::endl;
    }
}

// DeleteNode
void BST::DeleteNode(int &value, Node *&currentNode) {
    if (currentNode == NULL) {
        std::cout << "BST empty" << std::endl;
    } else {
        if (value < currentNode->data) {
            DeleteNode(value, currentNode->left);
        } else if (value > currentNode->data) {
            DeleteNode(value, currentNode->right);
        } else {
            Node *aptAux = currentNode;

            if (aptAux->right == NULL) {
                currentNode = aptAux->left;
            }
            if (aptAux->left == NULL) {
                currentNode = aptAux->right;
            }
            if (aptAux->left != NULL && aptAux->right != NULL) {
                SubstituteToMin(currentNode->right, aptAux);
            }

            std::cout << "\nThe key to delete: " << value << std::endl;
            std::cout << "The element was deleted with the key: " << aptAux->data << std::endl;
            delete aptAux;
        }
    }
}

// SubstituteToMin
void BST::SubstituteToMin(Node *&aptAux, Node *&aptNode) {
    if (aptAux->left != NULL) {
        SubstituteToMin(aptAux->left, aptNode);
    } else {
        aptNode->data = aptAux->data;
        aptNode = aptAux;
        aptAux = aptAux->right;
    }
}

// Delete BST
void BST::DeleteBST(Node *&currentNode) {
    if (!currentNode) {
        return;
    }
    DeleteBST(currentNode->left);
    DeleteBST(currentNode->right);
    delete currentNode;
}

// TAREA
// Visit
void BST::visit(int value) {
    switch (value) {
        case 1:
            std::cout << "\nPreorder: ";
            Preorder();
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "\nInorder: ";
            Inorder();
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "\nPostorder: ";
            Postorder();
            std::cout << std::endl;
            break;
        case 4:
            std::cout << "\nLevel by level: ";
            BFT();
            std::cout << std::endl;
            break;
        default:
            std::cout << "\nInvalid option" << std::endl;
            break;
    }
}

// Height
int BST::height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if (left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

// Ancestors
void BST::ancestors(int value) {
    if (root == NULL) {
        std::cout << "Empty tree" << std::endl;
        return;
    }

    Node* currentNode = root;
    std::cout << "Ancestors of " << value << ": ";

    while (currentNode->data != value) {
        std::cout << currentNode->data << " ";
        
        if (value < currentNode->data) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (currentNode == NULL) {
            std::cout << std::endl << "Value " << value << " not found in the tree." << std::endl;
            return;
        }
    }

    std::cout << std::endl;
}


// What level am I
int BST::whatlevelamI(int value, Node *N, int cont) {
    // Regresará un entero que indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre en el BST
    if (N == NULL) {
        return -1;
    }
    cont++;
    if (value > N->data) {
        return whatlevelamI(value, N->right, cont);
    } else if (value < N->data) {
        return whatlevelamI(value, N->left, cont);
    } else {
        return cont;
    }
}