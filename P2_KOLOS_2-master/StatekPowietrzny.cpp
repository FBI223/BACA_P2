//
// Created by msztu223 on 16.06.2023.
//

#include "StatekPowietrzny.hpp"


std::ostream& operator<<(std::ostream& os, const StatekPowietrzny& samolot) {
    os << "StatekPowietrzny id : " << samolot.id_obiektu << endl;
    os << "StatekPowietrzny wiek : " << samolot.wiek << endl;
    os << endl;
    return os;
}






