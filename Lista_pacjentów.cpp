#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

struct Osoba{
    string data;
    string name;
    string pesel;
};

struct Node{
  Osoba*osoba;
  Node*next=nullptr;
};

Node* head_alfa=nullptr;

void dodaj(string data, string czas, string pesel, string nazwisko, string imie){

  Osoba*nowa=new Osoba;
  nowa->data=data+" "+czas;
  nowa->pesel=pesel;
  nowa->name=imie+" "+nazwisko;
  
  if(head_alfa==nullptr){
      Node*head=new Node;
      head->osoba=nowa;
      head_alfa=head;
  }
  
  Node*temp=head_alfa;
  
  if(temp->osoba->name > nowa->name){
      
    Node*node=new Node;
    node->osoba=nowa;
      
    node->next=temp;
    head_alfa=node;
    return;
  }
  
  while(temp->next!=nullptr ){
      
      if(temp->osoba->name < nowa->name  &&  nowa->name <= temp->next->osoba->name)
      {
        Node*node=new Node;
        node->osoba=nowa;
        
        node->next=temp->next;
        temp->next=node;
        return;
      }else
        temp=temp->next;
  }
  
   Node*node=new Node;
   node->osoba=nowa;
   temp->next=node;
  
}

void wypisz(){
    
    Node*temp=head_alfa;
    
    while(temp!=nullptr){
        cout<<temp->osoba->name<<endl;
        temp=temp->next;
    }
}

int main(){
    
    ifstream plik("pacjenci_10.txt");
    
     
    string linia;
    
    while(getline(plik, linia)){
      stringstream ss(linia);
      string komenda;
      ss>>komenda;
      
      if(komenda=="dodaj"){
          string data,czas,imie, nazwisko, pesel;
          ss>>data>>czas>>pesel>>imie>>nazwisko;
          
          dodaj(data, czas, pesel, nazwisko, imie);
      }else if(komenda=="wypisz"){
          wypisz();
         
      }else if(komenda=="usun"){
         
      }
        
    }
    return 0;
}


