#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>

using namespace std;

struct Osoba{
  string imie;
  string nazwisko;
  int wiek;
  double waga;
};

struct Node{
  Osoba osoba;
  Node*next;
};

Node*front=nullptr;
Node*back=nullptr;

void zakolejkuj(string imie, string nazwisko, int wiek, double waga){
   Node*nowy=new Node;
   nowy->osoba.imie=imie;
   nowy->osoba.nazwisko=nazwisko;
   nowy->osoba.wiek=wiek;
   nowy->osoba.waga=waga;
   nowy->next=nullptr;
   
   if(!front){
       front=back=nowy;
   }
   else{
       back->next=nowy;
       back=nowy;
   }
}

void pobierz(){
    if(!front){
        cout<<"Kolejka jest pusta, nie można pobrać elementu"<<endl;
        return;
    }
    
    Node*temp=front;
    front=front->next;
    delete temp;
    
    if(!front){
        back=nullptr;
    }
}

void rozmiar(){
    
    int licznik=0;
    Node*temp=front;
    
    while(temp){
        temp=temp->next;
        licznik++;
    }
    
    cout<<"Rozmiar kolejki: "<<licznik<<endl;
}

void wypisz() {
    if (!front) {
        cout << "Kolejka jest pusta." << endl;
        return;
    }

    cout << "Kolejka:" << endl;
    cout << setw(3) << "NR" << " | "
         << setw(25) << "IMIE" << " | "
         << setw(25) << "NAZWISKO" << " | "
         << setw(4) << "WIEK" << " | "
         << setw(5) << "WAGA " << endl;

    Node* temp = front;
    int nr = 1;

    while (temp) {
        cout << setw(3) << nr << " | "
             << setw(25) << temp->osoba.imie << " | "
             << setw(25) << temp->osoba.nazwisko << " | "
             << setw(4) << temp->osoba.wiek << " | ";

        cout << setw(5);
        if (temp->osoba.waga == (int)temp->osoba.waga)
            cout << (int)temp->osoba.waga;
        else
            cout << fixed << setprecision(1) << temp->osoba.waga;

        cout << endl;

        temp = temp->next;
        nr++;
    }
}


int main(int argc, char*argv[]){
    
    if(argc!=2){
        cout<<"Brak pliku z komendami";
    } 
    
    ifstream plik(argv[1]);
    if(!plik){
        cout<<"Nie można otworzyć pliku"<<endl;
        return 1;
    }
    
    string linia;
    
    while(getline(plik, linia)){
        
        stringstream ss(linia);
        string komenda;
        ss>>komenda;
        if(komenda=="zakolejkuj"){
            string imie, nazwisko;
            int wiek;
            double waga;
            
            ss>>imie>>nazwisko>>wiek>>waga;
            zakolejkuj(imie, nazwisko, wiek, waga);
            
        }else if(komenda=="pobierz"){
            pobierz();
        }else if(komenda=="rozmiar"){
            rozmiar();
        }else if(komenda=="wypisz"){
            wypisz();
        }else
        cout<<"Nieprawidłowa komenda"<<endl;
    }
    plik.close();
    return 0;
}
