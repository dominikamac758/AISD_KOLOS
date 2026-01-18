#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct Osoba{
    string data;
    string name;
    string pesel;
};

struct Node{
    Osoba* osoba;
    Node* next_alfa = nullptr;
    Node* next_wiek = nullptr;
    Node* next_data = nullptr;
};

Node* head_alfa = nullptr;
Node* head_data = nullptr;
Node* head_wiek = nullptr;


bool czy_poprawny_pesel(const string& pesel)
{
    if (pesel.length() != 11) return false;

    int wagi[10] = {1,3,7,9,1,3,7,9,1,3};
    int suma = 0;

    for (int i = 0; i < 10; i++) {
        if (pesel[i] < '0' || pesel[i] > '9') return false;
        suma += (pesel[i] - '0') * wagi[i];
    }

    int kontrolna = (10 - (suma % 10)) % 10;
    return kontrolna == (pesel[10] - '0');
}

bool czy_wizyta_zajeta(string data)
{
    Node* temp = head_data;

    while(temp!=nullptr)
    {
        if(temp->osoba->data==data) return true;
        temp=temp->next_data;
    }
    return false;
}

string wiek(const string& pesel) {

    int rok = (pesel[0]-'0')*10 + (pesel[1]-'0');
    int mies = (pesel[2]-'0')*10 + (pesel[3]-'0');

    string dzien;
    dzien += pesel[4];
    dzien += pesel[5];

    if(mies > 20){
        mies -= 20;
        rok += 2000;
    } else {
        rok += 1900;
    }

    string m;
    if(mies < 10) m += '0';
    m += char('0' + (mies / 10));
    m += char('0' + (mies % 10));

    string wynik = to_string(rok) + m + dzien;
    return wynik;
}

void dodaj(string data, string czas, string pesel, string nazwisko, string imie)
{
    string termin= data + " " + czas;

    if(czy_wizyta_zajeta(termin)){
        cout<<"Termin zajęty: "<<termin<<endl;
        return;
    }

    if(!czy_poprawny_pesel(pesel)){
        cout<<"Nieprawidłowy PESEL: "<<pesel<<endl;
        return;
    }

   
    Osoba* nowa = new Osoba;
    nowa->data = termin;
    nowa->pesel = pesel;
    nowa->name = imie + " " + nazwisko;

    Node* new_node = new Node;
    new_node->osoba = nowa;

    // Dodawanie alfabetycznie:
    if(head_alfa==nullptr)
    {
        head_alfa = new_node;

    } else if(head_alfa->osoba->name > nowa->name)
    {
        new_node->next_alfa = head_alfa;
        head_alfa = new_node;

    } else{
        Node* temp = head_alfa;

        while(temp->next_alfa!=nullptr && temp->next_alfa->osoba->name < nowa->name)
            temp = temp->next_alfa;

        new_node->next_alfa = temp->next_alfa;
        temp->next_alfa = new_node;
    }

    // Dodawanie według daty wizyty:
    if(head_data==nullptr)
    {
        head_data = new_node;

    } else if(head_data->osoba->data > nowa->data)
    {
        new_node->next_data = head_data;
        head_data = new_node;

    } else
    {
        Node* temp = head_data;
        while(temp->next_data!=nullptr && temp->next_data->osoba->data < nowa->data)
            temp = temp->next_data;

        new_node->next_data = temp->next_data;
        temp->next_data = new_node;
    }

    // Dodawanie według wieku 
    string data_nowa = wiek(nowa->pesel);

    if(head_wiek==nullptr)
    {
        head_wiek = new_node;

    } else if(wiek(head_wiek->osoba->pesel) > data_nowa)
    {
        new_node->next_wiek = head_wiek;
        head_wiek = new_node;

    } else
    {
        Node* temp = head_wiek;

        while(temp->next_wiek!=nullptr && wiek(temp->next_wiek->osoba->pesel) < data_nowa)
            temp = temp->next_wiek;

        new_node->next_wiek = temp->next_wiek;
        temp->next_wiek = new_node;
    }
}

void wypisz_alfa(){
    Node* temp = head_alfa;
    int index = 1;
    while(temp!=nullptr){
        cout<<setw(4)<<index<<" | "<<temp->osoba->data<<" | "<<temp->osoba->pesel<<" | "<<temp->osoba->name<<endl;
        temp = temp->next_alfa;
        index++;
    }
}

void wypisz_wiek(){
    Node* temp = head_wiek;
    int index = 1;
    while(temp!=nullptr){
        cout<<setw(4)<<index<<" | "<<temp->osoba->data<<" | "<<temp->osoba->pesel<<" | "<<temp->osoba->name<<endl;
        temp = temp->next_wiek;
        index++;
    }
}

void wypisz_data(){
    Node* temp = head_data;
    int index = 1;
    while(temp!=nullptr){
        cout<<setw(4)<<index<<" | "<<temp->osoba->data<<" | "<<temp->osoba->pesel<<" | "<<temp->osoba->name<<endl;
        temp = temp->next_data;
        index++;
    }
}

void usun(string wizyta){
    Node* temp=head_data;
    while(temp!=nullptr && temp->osoba->data!=wizyta)
        temp=temp->next_data;

    if(!temp){
        cout<<"Wizyta nie znaleziona: "<<wizyta<<endl;
        return;
    }

    //alfabetycznie
    if(head_alfa==temp) head_alfa = head_alfa->next_alfa;
    else {
        Node* current = head_alfa;
        while(current->next_alfa && current->next_alfa!=temp) current=current->next_alfa;
        if(current->next_alfa) current->next_alfa = temp->next_alfa;
    }

    //wiekiem
    if(head_wiek==temp) head_wiek = head_wiek->next_wiek;
    else {
        Node* current = head_wiek;
        while(current->next_wiek && current->next_wiek!=temp) current=current->next_wiek;
        if(current->next_wiek) current->next_wiek = temp->next_wiek;
    }

    //wizyta
    if(head_data==temp) head_data = head_data->next_data;
    else {
        Node* current = head_data;
        while(current->next_data && current->next_data!=temp) current=current->next_data;
        if(current->next_data) current->next_data = temp->next_data;
    }

    delete temp->osoba;
    delete temp;
}

int main(int argc, char*argv[]){

     if (argc < 2) return 0;

     ifstream plik(argv[1]);

    string linia;
    while(getline(plik, linia))
    {
        stringstream ss(linia);
        string komenda;
        ss>>komenda;

        if(komenda=="dodaj"){
            string data, czas, pesel, imie, nazwisko;
            ss>>data>>czas>>pesel>>imie>>nazwisko;
            dodaj(data, czas, pesel, nazwisko, imie);
        } else if(komenda=="wypisz"){
            string jak;
            ss>>jak;
            if(jak=="alfabetycznie"){
                cout<<"Lista alfabetycznie:"<<endl;
                wypisz_alfa();
            } else if(jak=="wiekiem"){
                cout<<"Lista wiekiem:"<<endl;
                wypisz_wiek();
            } else if(jak=="wizytami"){
                cout<<"Lista wizytami:"<<endl;
                wypisz_data();
            }
        } else if(komenda=="usun"){
            string data, czas;
            ss>>data>>czas;
            usun(data+" "+czas);
        }
    }

    return 0;
}

