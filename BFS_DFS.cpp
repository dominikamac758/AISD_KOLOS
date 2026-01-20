DFS- inorder (lewo->korzen->prawo):

void dfs(Node* root) {
    if (root == nullptr) return;

    dfs(root->left);
    cout << root->value << " ";
    dfs(root->right);
}

DFS-preorder (korzen->lewo->prawo):

void dfs_preorder(Node* root) {
  if (root == nullptr) return;

  cout << root->value << " ";
  dfs_preorder(root->left);
  dfs_preorder(root->right);
}

DFS-postorder (lewo->prawo->korzen):

void dfs_postorder(Node* root) {
    if (root == nullptr) return;

    dfs_postorder(root->left);
    dfs_postorder(root->right);
    cout << root->value << " ";
}
BFS:
struct Node
{
    int val;
    vector<Node*> children;
};

void bfs(Node* root)
{
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        cout << current->val << " ";

        for (Node* child : current->children)
        {
            q.push(child);
        }
    }
}
BFS-najprostszy:
int height(Node* root) {
    if (root == nullptr) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return (l > r ? l : r) + 1;
}
void printLevel(Node* root, int level) {
    if (root == nullptr) return;

    if (level == 1) {
        cout << root->value << " ";
    } else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
void bfs(Node* root) {
    int h = height(root);

    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

Wersja Taranka:
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

struct Wezel {
    int liczba;
    vector<Wezel *> dzieci;
};

void wypisz_w_glab(Wezel *w) {
    if (w==nullptr)
        return;
    printf("%d ", w->liczba);

    for (int i=0; i<w->dzieci.size(); i++) {
        wypisz_w_glab(w->dzieci[i]);
    }
}
queue<Wezel*> wezly_do_powrotu;

void wypisz_w_szerz(Wezel *w) {
    if (w==nullptr)
        return;
    //potrzebna jest kolejka

    for (int i=0; i<w->dzieci.size(); i++) {
        printf("%d\n", w->dzieci[i]->liczba);
        wezly_do_powrotu.push(w->dzieci[i]);
    }
    while(!wezly_do_powrotu.empty()) {
        Wezel*temp=wezly_do_powrotu.front();
        wezly_do_powrotu.pop();
        wypisz_w_szerz(temp);
    }
}

void wypisz_w_szerz_iteracujnie(Wezel* w){
    queue<Wezel*> wezly_do_powrotu;
    wezly_do_powrotu.push(w);
    while (!wezly_do_powrotu.empty()) {
        Wezel * temp= wezly_do_powrotu.front();
        wezly_do_powrotu.pop();
        cout<<temp->liczba<<" ";

        for (Wezel*wezel:temp->dzieci) {
            wezly_do_powrotu.push(wezel);
        }
    }

}
// Pomocnicza funkcja do tworzenia nowych wezłów
Wezel* stworz(int wartosc) {
    Wezel* nowy = new Wezel;
    nowy->liczba = wartosc;
    return nowy;
}

int main() {
    // KORZEŃ (Poziom 0)
    Wezel* root = stworz(0);

    // POZIOM 1 (Setki)
    Wezel* s0 = stworz(0);
    Wezel* s100 = stworz(100);
    Wezel* s200 = stworz(200);

    root->dzieci.push_back(s0);
    root->dzieci.push_back(s100);
    root->dzieci.push_back(s200);

    // POZIOM 2 (Dziesiątki)
    // Dzieci s0:
    Wezel* d0 = stworz(0);
    Wezel* d40 = stworz(40);
    s0->dzieci.push_back(d0);
    s0->dzieci.push_back(d40);

    // Dzieci s100:
    Wezel* d120 = stworz(120);
    Wezel* d150 = stworz(150);
    Wezel* d110 = stworz(110);
    Wezel* d180 = stworz(180);
    s100->dzieci.push_back(d120);
    s100->dzieci.push_back(d150);
    s100->dzieci.push_back(d110);
    s100->dzieci.push_back(d180);

    // Dzieci s200:
    Wezel* d200 = stworz(200);
    Wezel* d270 = stworz(270);
    Wezel* d220 = stworz(220);
    s200->dzieci.push_back(d200);
    s200->dzieci.push_back(d270);
    s200->dzieci.push_back(d220);

    // POZIOM 3 (Liście)
    // Liście pod s0 -> d0:
    d0->dzieci.push_back(stworz(2));
    d0->dzieci.push_back(stworz(5));
    // Liście pod s0 -> d40:
    d40->dzieci.push_back(stworz(43));
    d40->dzieci.push_back(stworz(48));
    d40->dzieci.push_back(stworz(40));

    // Liście pod s100:
    d120->dzieci.push_back(stworz(120));
    d150->dzieci.push_back(stworz(151));
    d150->dzieci.push_back(stworz(156));
    d110->dzieci.push_back(stworz(112));
    d180->dzieci.push_back(stworz(189));
    d180->dzieci.push_back(stworz(185));

    // Liście pod s200:
    d200->dzieci.push_back(stworz(204));
    d200->dzieci.push_back(stworz(202));
    d270->dzieci.push_back(stworz(279));
    d220->dzieci.push_back(stworz(229));
    d220->dzieci.push_back(stworz(220));

    // Tutaj możesz teraz wywołać swoją funkcję wypisz_w_glab(root);

    wypisz_w_glab(root);
    wypisz_w_szerz(root);
    wypisz_w_szerz_iteracujnie(root);

    return 0;
}



