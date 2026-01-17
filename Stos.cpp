#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* head = nullptr;


void odloz(string data) {
    Node* nowy = new Node;
    nowy->data = data;
    nowy->next = head;
    head = nowy;
}


void zdejmij() {
    if (!head) {
        cout << "Stos jest pusty, nie można zdjąć elementu." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void podejrzyj() {
    if (!head) {
        cout << "Stos jest pusty." << endl;
    } else {
        cout << "Na wierzchu stosu: " << head->data << endl;
    }
}

void rozmiar() {
    int licznik = 0;
    Node* temp = head;

    while (temp != nullptr) {
        licznik++;
        temp = temp->next;
    }

    cout << "Rozmiar stosu: " << licznik << endl;
}

void czy_pusty() {
    if (!head)
        cout << "Stos jest pusty." << endl;
    else
        cout << "Stos nie jest pusty." << endl;
}

void wypisz() {
    if (!head) {
        cout << "Stos jest pusty." << endl;
        return;
    }

    cout << "Stos:" << endl;
    Node* temp = head;
    int index = 1;

    while (temp != nullptr) {
        cout << "[  " << index << "] " << temp->data << endl;
        temp = temp->next;
        index++;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Brak pliku z komendami" << endl;
        return 1;
    }

    ifstream plik(argv[1]);
    if (!plik) {
        cout << "Nie można otworzyć pliku" << endl;
        return 1;
    }

    string linia;
     while (getline(plik, linia)) {

        string komenda;
        string tekst;

        stringstream ss(linia);
        ss >> komenda;   
        if (komenda == "odloz") {

            ss >> ws;        
            getline(ss, tekst); 
            odloz(tekst);

        } else if (komenda == "zdejmij") {
            zdejmij();

        } else if (komenda == "podejrzyj") {
            podejrzyj();

        } else if (komenda == "rozmiar") {
            rozmiar();

        } else if (komenda == "czy_pusty") {
            czy_pusty();

        } else if (komenda == "wypisz") {
            wypisz();
        }
    }
    plik.close();
    return 0;
}
