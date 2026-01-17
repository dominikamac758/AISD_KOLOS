#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

struct Node{
  int data;
  Node*next=nullptr;
};

Node* head=nullptr;

void dodaj(int liczba){
    Node* nowy = new Node;
    nowy->data = liczba;
    nowy->next = nullptr;

    if(!head){
        head = nowy;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = nowy;
}

void wstaw(int liczba, int pozycja){
    
    Node*nowy=new Node;
    nowy->data=liczba;
    
    if(pozycja<=0 || head==nullptr){
        nowy->next=head;
        head=nowy;
        return;
    }
    Node*current=head;
    int indeks=0;
    while(current->next!=nullptr && indeks<pozycja-1){
        current=current->next;
        indeks++;
    }
    
        nowy->next=current->next;
        current->next=nowy;
}

void usun(int pozycja){
    
    if(head==nullptr || pozycja<0) return;
    
    if(pozycja==0){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    
    Node*current=head;
    int indeks=0;
    while(current->next!=nullptr && indeks<pozycja-1){
        current=current->next;
        indeks++;
    }
    
    if(current->next!=nullptr){
        Node*temp=current->next;
        current->next=temp->next;
        delete temp;
    }
    
}

void wyczysc(){
   
   Node*temp=head;
   while(temp!=nullptr){
       Node* do_usuniecia=temp;
       temp=temp->next;
       delete do_usuniecia;
   }
   head=nullptr;
}

void wypisz(){
    
    cout<<"[";
    Node*temp=head;
    while(temp!=nullptr){
        cout<<setw(3)<<temp->data;
        temp=temp->next;
    }
    cout<<"]"<<endl;
}

void odwrotnie(Node*node){
    if(node==nullptr) return;
    odwrotnie(node->next);
    cout<<setw(3)<<node->data;
}

void wypisz_odwrotnie(){
    cout<<"[";
    odwrotnie(head);
    cout<<"]"<<endl;
}

void zamien(int pozycja1, int pozycja2){
    
    if(pozycja1==pozycja2) return;
    
    Node* node1=head;
    Node* node2=head;
    int indeks1=0, indeks2=0;
    
    while(node1!=nullptr && indeks1<pozycja1){
        node1=node1->next;
        indeks1++;
    }
    while(node2!=nullptr && indeks2<pozycja2){
        node2=node2->next;
        indeks2++;
    }
    
    if(node1!=nullptr && node2!=nullptr){
        
        int temp=node1->data;
        node1->data=node2->data;
        node2->data=temp;
    }
}

int main(int argc, char* argv[]){
    
    if(argc<2){
        cout<<"Podaj nazwę pliku z komendami"<<endl;
        return 1;
    }
    
    ifstream plik(argv[1]);
    
    if(!plik){
        cout<<"Nie udało otworzyć się pliku"<<endl;
        return 1;
    }
    
    string linia;
    
    while(getline(plik, linia)){
      stringstream ss(linia);
      string komenda;
      ss>>komenda;
      
      if(komenda=="dodaj"){
          int liczba;
          ss>>liczba;
          dodaj(liczba);
      }else if(komenda=="wstaw"){
          int pozycja,liczba;
          ss>>liczba>>pozycja;
          wstaw(liczba, pozycja);
      }else if(komenda=="usun"){
          int pozycja;
          ss>>pozycja;
          usun(pozycja);
      }else if(komenda=="wyczysc"){
          wyczysc();
      }else if(komenda=="wypisz"){
          wypisz();
      }else if(komenda=="wypisz_odwrotnie"){
          wypisz_odwrotnie();
      }else if(komenda=="zamien"){
          int pozycja1, pozycja2;
          ss>>pozycja1>>pozycja2;
          zamien(pozycja1, pozycja2);
      }
    }
    
    
    return 0;
}
