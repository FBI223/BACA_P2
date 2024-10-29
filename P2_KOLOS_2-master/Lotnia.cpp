//
// Created by msztu223 on 16.06.2023.
//

#include "Lotnia.hpp"

std::ostream& operator<<(std::ostream& os, const Lotnia& samolot) {
    os << "operator <<\n" ;
    os << "Lotnia id : " << samolot.id_obiektu << endl;
    os << "Lotnia wiek : " << samolot.wiek << endl;
    os << endl;
    return os;
}

void Lotnia::print_wiek() {
    cout << "wiek lotni to : " << this->wiek << endl;
}

Lotnia::Lotnia(std::string idd)
{
    this->wiek=0;
    this->id_obiektu = idd;
}

void Lotnia::print() {
    cout << "Lotnia id : " << this->id_obiektu << endl;
    cout << "Lotnia wiek : " << this->wiek << endl;
    cout << endl;
}

Lotnia::~Lotnia() {

}

Lotnia::Lotnia() {

}