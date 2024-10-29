//Marcin Sztukowski

#include "Lotnia.hpp"
#include "Motolotnia.hpp"
#include "Samolot.hpp"
#include "StatekPowietrzny.hpp"
#include "Szybowiec.hpp"
#include "Lotnisko.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main() {



    Samolot s1("Airbus A320");
    Samolot s3("Boeing 737");
    cout << s1; //Samolot Airbus A320
    cout << s3; //Samolot Airbus A320
    Lotnisko< Samolot> balice(4);
    balice[1] = &s1;
    balice[3] = &s3;




    //balice[0];
    balice[1]->print() ;
    //balice[2];
     cout << *balice[3];
    //balice[4];
    //balice[1]->print();

    cout << endl << endl;
    cout << balice; // Airbus A320 / Pusty hangar / Boeing 737 / Pusty hangar

    try {
        balice[5] = &s1; //Rzuca wyjątek „Nieprawidłowy numer hangaru”
    }
    catch (const std::exception& e) {
        // Kod do obsługi wyjątku
        std::cout << "Wystąpił wyjątek: " << e.what() << std::endl;
    }


    cout << balice ;


    Lotnia a2("Czerwona");
    Lotnisko <Lotnia> aeroklub(3);
    aeroklub[2] = &a2;
    cout << aeroklub;



    Motolotnia m( "Niebieska" );
    cout << m ;
    m.print_wiek();



    StatekPowietrzny* ptr = &m;
    ptr->dodaj_rok() ;
    ptr->print_wiek(); //Motolotnia Niebieska 80KM ma 1 lat



    cout << "Hello, World!" <<endl;
    return 0;
}
