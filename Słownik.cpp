#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node{
   char litera;
   bool koniec_slowa;
   vector<Node*>dzieci;
};

void dodaj(Node*root, const string& slowo){
    
    Node*current=root;
    
    for(char c : slowo){
        Node*next=nullptr;
        
        for(Node*child : current->dzieci){
            
            if(child->litera==c){
                next=child;
                break;
            }
        }
        
       if(!next){
           Node*nowy=new Node;
           nowy->litera=c;
           nowy->koniec_slowa=false;
           current->dzieci.push_back(nowy);
           next=nowy;
       } 
       
       current=next;
        
    }
    
    
    current->koniec_slowa=true;
    
}


bool sprawdz(Node*root, const string& slowo){
    Node*current=root;
    
    for(char c : slowo){
        Node*next=nullptr;
        
        for(Node*child : current->dzieci){
            if(child->litera==c){
                next=child;
                break;
            }
        }
        
        if(!next) return false;
        
        current=next;
    }
    
    return current->koniec_slowa;
}

void dfs(Node*node, string slowo){
    
    if(node->koniec_slowa)
      cout<<slowo<<endl;
      
    for(Node*child : node->dzieci){
        
        dfs(child, slowo+child->litera);
    }
}

void bfs(Node*root){
    
    queue<pair<Node*,string>>q;
    q.push({root, ""});
    
    
    while(!q.empty()){
        
        Node*node=q.front().first;
        string slowo=q.front().second;
        q.pop();
        
        if(node->koniec_slowa)
           cout<<slowo<<endl;
           
        for(Node*child : node->dzieci){
            q.push({child, slowo+child->litera});
        }
    }
}


int main(int argc, char* argv[]) {
   
    if (argc < 3) {
        return 1;
    }

    ifstream file(argv[1]);
    if (!file) {
        cout << "Nie można otworzyć pliku\n";
        return 1;
    }
     
    Node* root = new Node; 
    root->litera = '\0';
    root->koniec_slowa = false;
    
    string slowo;
    
    while (getline(file, slowo)){
       
        if (!slowo.empty())
            dodaj(root, slowo);
    }

    string komenda = argv[2];

    if (komenda == "sprawdz") {
        if (argc < 4) {
            cout << "Brak slowa do sprawdzenia\n";
            return 1;
        }

        string wyraz = argv[3];
        if (sprawdz(root, wyraz))
            cout << "Słowo \"" << wyraz << "\" występuje w słowniku\n";
        else
            cout << "Brak słowa \"" << wyraz << "\" w słowniku\n";
    }
    else if (komenda == "w_glab") {
        dfs(root, "");
    }
    else if (komenda == "wszerz") {
        bfs(root);
    }
   
    return 0;
}

