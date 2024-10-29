//
// Created by msztu223 on 16.06.2023.
//

#include "Motolotnia.hpp"

std::ostream& operator<<(std::ostream& os, const Motolotnia& samolot) {
    os << "operator <<\n" ;
    os << "Motolotnia id : " << samolot.id_obiektu << endl;
    os << "Motolotnia wiek : " << samolot.wiek << endl;
    os << endl;
    return os;
}


void Motolotnia::print_wiek()  {
    cout << " wiek motolotnii to " << this->wiek << endl;
}

Motolotnia::Motolotnia(std::string iddd)     {
    this->wiek = 0 ;
    this->id_obiektu = iddd;
}

Motolotnia::Motolotnia() {

}

Motolotnia::~Motolotnia() {


}

void Motolotnia::print() {

    cout << "id motolotnii to : " << this->id_obiektu << endl;
    cout << "wiek motolotnii to : " << this->wiek << endl << endl;

}
