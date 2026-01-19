#include <iostream>
#include <queue>
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
    if (!root) return createNode(value);

    if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);

    return root;
}

// BFS iteracyjnie – znajdowanie najgłębszego liścia
Node* findDeepestLeafBFS(Node* root) {
    if (!root) return nullptr;

    queue<Node*> q;
    q.push(root);
    Node* last = nullptr;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        last = current; // ostatni przetworzony węzeł = najgłębszy

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }

    return last;
}

int main() {
    Node* root = nullptr;
    int values[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int v : values) root = insert(root, v);

    Node* deepest = findDeepestLeafBFS(root);

    if (deepest)
        cout << "Najglebszy lisć: " << deepest->value << endl;

    return 0;
}


#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

// Tworzenie węzła
Node* createNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Wstawianie do BST
Node* insert(Node* root, int value) {
    if (!root) return createNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);

    return root;
}

// DFS rekurencyjnie – znajdowanie najgłębszego liścia
void findDeepestLeafDFS(Node* root, int depth, int &maxDepth, Node* &deepestLeaf) {
    if (!root) return;

    // jeśli liść
    if (!root->left && !root->right) {
        if (depth >= maxDepth) { // >= zamiast >, żeby wziąć najprawy liść w tej samej głębokości
            maxDepth = depth;
            deepestLeaf = root;
        }
    }

    findDeepestLeafDFS(root->left, depth + 1, maxDepth, deepestLeaf);
    findDeepestLeafDFS(root->right, depth + 1, maxDepth, deepestLeaf);
}

int main() {
    Node* root = nullptr;

    int values[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int v : values) root = insert(root, v);

    int maxDepth = -1;
    Node* deepestLeaf = nullptr;

    findDeepestLeafDFS(root, 0, maxDepth, deepestLeaf);

    if (deepestLeaf)
        cout << "Najglebszy lisć: " << deepestLeaf->value 
             << " na głębokości " << maxDepth << endl;

    return 0;
}
