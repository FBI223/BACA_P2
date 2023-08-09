//
// Created by msztu223 on 16.06.2023.
//

#include "Samolot.hpp"

std::ostream& operator<<(std::ostream& os, const Samolot& samolot) {
    os << "operator <<\n" ;
    os << "Samolot id : " << samolot.id_obiektu << endl;
    os << "Samolot wiek : " << samolot.wiek << endl;
    os << endl;
    return os;
}

void Samolot::print() {
    cout << "Samolot id : " << this->id_obiektu << endl;
    cout << "Samolot wiek : " << this->wiek << endl;
    cout << endl;
}


Samolot::Samolot() {

}

Samolot::~Samolot() {


}

Samolot::Samolot(std::string idd) {

    this->id_obiektu = idd;
    wiek = 0;
}

