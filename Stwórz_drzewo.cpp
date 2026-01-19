#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

int height(Node* root) {
    if (root == nullptr) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return (l > r ? l : r) + 1;
}

void printLevel(Node* root, int level, int space) {
    if (root == nullptr) {
        for (int i = 0; i < space; i++) cout << " ";
        cout << " ";
        return;
    }

    if (level == 1) {
        for (int i = 0; i < space; i++) cout << " ";
        cout << root->value;
    } else {
        printLevel(root->left, level - 1, space);
        printLevel(root->right, level - 1, space);
    }
}

void printTree(Node* root) {
    int h = height(root);
    int space = 32;

    for (int i = 1; i <= h; i++) {
        printLevel(root, i, space);
        cout << endl << endl;
        space /= 2;
    }
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


int main() {
    Node* root = nullptr;

    int numbers[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int i = 0; i < 9; i++) {
        root = insert(root, numbers[i]);
    }

    cout << "Drzewo (inorder): ";
    inorder(root);
    cout << "\n\nWizualizacja drzewa:\n";

    printTree(root);

    deleteTree(root);
    return 0;
}

