#include <iostream>
#include <cstdlib>
#include <ctime>

char *generuj_haslo() {
    // spółgłoski bez 'y'
    const char wielkie_spolgloski[] = "BCDFGHJKLMNPQRSTVWXZ"; 
    const char male_spolgloski[]   = "bcdfghjklmnpqrstvwxz"; 
    const char samogloski[]        = "aeiouy";               
    const char cyfry[]             = "0123456789";

    char *haslo = new char[11]; // 10 znaków + '\0'

    haslo[0] = wielkie_spolgloski[rand() % 20]; // B
    haslo[1] = male_spolgloski[rand() % 20];    // b
    haslo[2] = samogloski[rand() % 6];          // a
    haslo[3] = wielkie_spolgloski[rand() % 20]; // B
    haslo[4] = male_spolgloski[rand() % 20];    // b
    haslo[5] = samogloski[rand() % 6];          // a
    haslo[6] = wielkie_spolgloski[rand() % 20]; // B
    haslo[7] = male_spolgloski[rand() % 20];    // b
    haslo[8] = cyfry[rand() % 10];              // 0
    haslo[9] = cyfry[rand() % 10];              // 0
    haslo[10] = '\0';                           // zakończenie stringa

    return haslo;
}

int main() {
    srand(time(0)); // inicjalizacja generatora

    char *h1 = generuj_haslo();
    char *h2 = generuj_haslo();

    std::cout << h1 << std::endl;
    std::cout << h2 << std::endl;

    delete[] h1;
    delete[] h2;

    return 0;
}
