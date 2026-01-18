#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* left = nullptr;
    Node* right = nullptr;
};

void usun_z_wyrazenia_spacje_i_przecinki(string& wyrazenie) {
    string new_wyrazenie = "";

    for (int i=0; i<wyrazenie.length(); i++)
        if (wyrazenie[i] != ' ' && wyrazenie[i] != ',')
            new_wyrazenie += wyrazenie[i];

    wyrazenie = new_wyrazenie;
}

Node* buildTree(string& wyrazenie, int& index) {
    if (wyrazenie[index] == '(')
        index++;

    Node* node = new Node;
    node->value = wyrazenie[index++]; // różnica między i++ i ++i

    if (wyrazenie[index] == '(')
        node->left = buildTree(wyrazenie, index);
    else {
        Node* n = new Node;
        n->value = wyrazenie[index++];
        node->left = n;
    }

    if (wyrazenie[index] == '(')
        node->right = buildTree(wyrazenie, index);
    else {
        Node* n = new Node;
        n->value = wyrazenie[index++];
        node->right = n;
    }

    if (wyrazenie[index] == ')') {
        index++;
        return node;
    }

    return node;
}

void wypisz_preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->value << " ";
    wypisz_preorder(root->left);
    wypisz_preorder(root->right);
}

void wypisz_inorder(Node* root) {
    if (root == nullptr)
        return;

    if (root->left != nullptr && root->right != nullptr)
        cout << "( ";

    wypisz_inorder(root->left);
    cout << root->value <<" ";
    wypisz_inorder(root->right);

    if (root->left != nullptr && root->right != nullptr)
        cout << ") ";
}

void wypisz_postorder(Node* root) {
    if (root == nullptr)
        return;

    wypisz_postorder(root->left);
    wypisz_postorder(root->right);
    cout << root->value << " ";
}

int main(int argc, char* argv[]) {
    string wyrazenie = "(+, (*, 1, (-, 2, 3)), (+, 4, 5))";

    cout << "Wyrażenie " << wyrazenie << endl;

    usun_z_wyrazenia_spacje_i_przecinki(wyrazenie);

    int index = 0;
    Node* root = buildTree(wyrazenie, index);
    
    cout<<"In-order - notacja wzrostkowa"<<endl;
    wypisz_inorder(root);
    cout << endl;
    cout<<"Pre-order - notacja polska"<<endl;
    wypisz_preorder(root);
    cout << endl;
    cout<<"Post-order - odwrotna notacja polska"<<endl;
    wypisz_postorder(root);
    cout << endl;

    return 0;
}
