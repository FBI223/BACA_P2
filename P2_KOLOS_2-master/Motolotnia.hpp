//
// Created by msztu223 on 16.06.2023.
//

#include "Samolot.hpp"
#include "Lotnia.hpp"

#include <vector>
#include <iostream>

using namespace std;

#ifndef KOLOS_2_MOTOLOTNIA_HPP
#define KOLOS_2_MOTOLOTNIA_HPP

class Motolotnia : public Samolot, public Lotnia
        {


protected:


public:

            void print_wiek();
    Motolotnia(string iddd);


    Motolotnia();


    ~Motolotnia();

    void print();

    friend ostream& operator << (ostream &os, const Motolotnia& c);


};


#endif //KOLOS_2_MOTOLOTNIA_HPP
