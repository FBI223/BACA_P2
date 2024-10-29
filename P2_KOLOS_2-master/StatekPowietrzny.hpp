//
// Created by msztu223 on 16.06.2023.
//

/*
#include "Lotnia.hpp"
#include "Motolotnia.hpp"
#include "Samolot.hpp"
#include "Szybowiec.hpp"
#include "Lotnisko.hpp"
*/
#include <vector>
#include <iostream>


using namespace std;

#ifndef KOLOS_2_STATEKPOWIETRZNY_HPP
#define KOLOS_2_STATEKPOWIETRZNY_HPP



class StatekPowietrzny{

protected:
    int wiek;
    std::string id_obiektu;

public:

    virtual void dodaj_rok()
    {
        this->wiek = this->wiek + 1 ;
    }

    StatekPowietrzny()
    {
        wiek=0;
        id_obiektu="";
    }

    StatekPowietrzny( string iddd)
    {
        id_obiektu = iddd;
        wiek = 0 ;
    }

    virtual void print()
    {
        std::cout << wiek << std::endl;
        std::cout << id_obiektu << std::endl;
    }

    friend ostream& operator << (ostream &os, const StatekPowietrzny& c);

    virtual void print_wiek()=0;


};



#endif //KOLOS_2_STATEKPOWIETRZNY_HPP
