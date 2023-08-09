//
// Created by msztu223 on 16.06.2023.
//




#include "Szybowiec.hpp"

std::ostream& operator<<(std::ostream& os, const Szybowiec& samolot) {
    os << "operator <<\n" ;
    os << "Szybowiec id : " << samolot.id_obiektu << endl;
    os << "Szybowiec wiek : " << samolot.wiek << endl;
    os << endl;
    return os;
}

void Szybowiec::print_wiek() {
    cout << " wiek szybowca to " << this->wiek << endl;
}

Szybowiec::Szybowiec() {

}

Szybowiec::~Szybowiec() {


}

void Szybowiec::print() {
    cout << "id szybowca to : " << this->id_obiektu << endl;
    cout << "wiek szybowca to : " << this->wiek << endl;
}
