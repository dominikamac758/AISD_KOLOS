#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum class TypLeku {
    Syrop, Tabletki, Czopki
};

struct Lek {
    string nazwa;
    TypLeku typ;
    int pojemnosc; // odpowiednio sztuki lub mililitry
    int stan;
};

Lek* recepta(int n) {
    // Tablice nazw leków
    string syropy[55] = {
        "Pelavo Kaszel suchy i mokry", "Bronchostop Duo na kaszel", "Sirupus Thymi compositum",
        "Pelafen Kid MD Przeziębienie", "GrinTuss Adult - kaszel suchy i mokry",
        "Solvetusan 60 mg/ 10 ml", "Tretussin Med", "Muconatural Complete", "Bronchipret TE",
        "Maxipulmon 3 mg/ml", "Sirupus Thymi compositum", "Supremin Max 1,5 mg/ ml",
        "PlantagoPharm 506 mg/ 5 ml", "Pelavo Oskrzela", "Herbion na kaszel 30 mg/ 5 ml",
        "Bronchosol", "Levopront 60 mg/ 10 ml", "Flegamina Classic o smaku malinowym",
        "Flegamina Classic o smaku miętowym bez cukru", "Mucosolvan 30 mg/ 5 ml",
        "Ambrosol 30 mg/ 5 ml", "Syrop prawoślazowy 35,9 g/ 100 g",
        "Syrop prawoślazowy z malinami i cynkiem", "Deflegmin 30 mg/ 5 ml", "Hederasal 26,6 mg/ 5 ml",
        "Sirupus Plantaginis Plus", "Flavamed 15 mg/ 5 ml", "Boiron Stodal", "Pyrosal 1 g/ 10 g",
        "Guajazyl 125 mg/ 5 ml", "Apipulmol", "Herbapect", "Sinecod 1,5 mg/ml",
        "Mucosolvan 30 mg/ 5 ml", "Sirupus Plantaginis", "Supremin", "Amatussin", "Levosol 6mg/ml",
        "Honikan Kaszel", "Contril 60 mg/10 ml", "Boiron Drosetux", "LevoDril",
        "Bronchostop Duo na kaszel", "Flegatussin", "Syrop islandzki na kaszel", "Herbapect",
        "Gardlox", "Amara Sir. Altaeae", "Gardlox", "Envil kaszel 30 mg/ 5 ml", "Drosetux",
        "Prospan 35 mg/ 5 ml", "Islaherb", "GrinTuss Adult, kaszel suchy i mokry",
        "Flegamina Classic o smaku malinowym"
    };

    string tabletki[31] = {
        "Solvetusan 60 mg", "Strepsils na kaszel 375 mg", "Respero Myrtol 300 mg",
        "Mucopect Control 375 mg", "Soledum forte 200 mg", "Prospan 26 mg",
        "Pelafen Med 20 mg", "Detusan", "Natur-sept Kaszel", "Flavamed 30 mg",
        "Flegamina Classic 8 mg", "Sal Ems factitium 450 mg", "Tussal Expectorans 30 mg",
        "Deflegmin 30 mg", "Flavamed 60 mg", "ACC 200 mg", "Deflegmin 75 mg",
        "ACC Optima 600 mg", "Heel Engystol", "Fluimucil Forte 600 mg", "Mucosolvan 30 mg",
        "Flegamina Fast 8 mg", "Bronchosol Maxipuren", "Protego Acetylocysteina",
        "Bronchosol Solid 37,5 mg + 75 mg", "Mucoatac 600 mg", "Fervex Phyto gardło i kaszel",
        "Mucofortin 600 mg", "Gardlox bez cukru", "Levosol 60 mg", "Acetylocysteina"
    };

    string czopki[24] = {
        "Paracetamol Hasco 80 mg", "Paracetamol Hasco 500mg", "Scopolan 10 mg", "Anusir",
        "Criorectum Protect", "Hemkortin-HC 10 mg + 10 mg", "Hemocal", "Hemorol",
        "Posterisan 387,1 mg", "Procto-Glyvenol 400 mg + 40 mg", "Procto-Hemolan Protect",
        "Proctomina (200 mg + 100 mg + 150 mg)", "Procto-Zac Relief", "Proktis-M", "Proktosedon",
        "UniGel Procto", "Avena Glyceroli Suppositoria 2 g", "Farmina Glyceroli Suppositoria 2 g",
        "Laxol 100 mg", "Boiron, Avenoc", "Farmina Glyceroli Suppositoria 1 g",
        "Avena Glyceroli Suppositoria 1 g", "Dulcobis 10 mg", "Apirectal"
    };

    // inicjalizacja generatora
    srand(time(0));

    Lek* tab = new Lek[n];

    for (int i = 0; i < n; i++) {
        int r = rand() % 100 + 1; // losowanie 1-100 dla typu leku

        if (r <= 60) { // Syrop
            tab[i].typ = TypLeku::Syrop;
            tab[i].nazwa = syropy[rand() % 55];
            tab[i].pojemnosc = rand() % (250 - 60 + 1) + 60; // 60-250
        } else if (r <= 90) { // Tabletki
            tab[i].typ = TypLeku::Tabletki;
            tab[i].nazwa = tabletki[rand() % 31];
            tab[i].pojemnosc = rand() % (50 - 20 + 1) + 20; // 20-50
        } else { // Czopki
            tab[i].typ = TypLeku::Czopki;
            tab[i].nazwa = czopki[rand() % 24];
            tab[i].pojemnosc = rand() % (20 - 5 + 1) + 5; // 5-20
        }

        tab[i].stan = rand() % 21; // 0-20
    }

    return tab;
}
