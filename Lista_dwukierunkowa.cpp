#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

struct Node{
  int data;
  Node*next=nullptr;
  Node*prev=nullptr;
};

Node* head=nullptr;
Node* tail=nullptr;

void dodaj(int liczba){
    Node* nowy = new Node;
    nowy->data = liczba;

    if(!head){
        head = tail = nowy;
        return;
    }

    tail->next=nowy;
    nowy->prev=tail;
    tail=nowy;
    
}

void wstaw(int liczba, int pozycja){
    
    Node*nowy=new Node;
    nowy->data=liczba;
    
    if(pozycja<=0 || head==nullptr){
        nowy->next=head;
        if(head) head->prev = nowy;
        head=nowy;
        if(!tail) tail=nowy;
        return;
    }
    Node*current=head;
    int indeks=0;
    while(current->next!=nullptr && indeks<pozycja-1){
        current=current->next;
        indeks++;
    }
    
        nowy->next=current->next;
        nowy->prev=current;
        
    if(current->next){
        current->next->prev=nowy;
    }
    else
    tail=nowy;
    
    current->next=nowy;
}

void usun(int pozycja){
    if(!head || pozycja < 0) return;

    Node* current = head;
    int indeks = 0;

    while(current && indeks < pozycja){
        current = current->next;
        indeks++;
    }

    if(!current) return;

    if(current->prev)
        current->prev->next = current->next;
    else
        head = current->next;

    if(current->next)
        current->next->prev = current->prev;
    else
        tail = current->prev;

    delete current;
}

void wyczysc(){
   
   Node*temp=head;
   while(temp!=nullptr){
       Node* do_usuniecia=temp;
       temp=temp->next;
       delete do_usuniecia;
   }
   head=tail=nullptr;
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

void wypisz_odwrotnie(){
    cout<<"[";
    Node*temp=tail;
    while(temp!=nullptr){
        cout<<setw(3)<<temp->data;
        temp=temp->prev;
    }
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
