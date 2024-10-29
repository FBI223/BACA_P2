//
// Created by msztu223 on 16.06.2023.
//


#include "StatekPowietrzny.hpp"

/*
#include "Lotnia.hpp"
#include "Motolotnia.hpp"
#include "Samolot.hpp"
#include "Samolot.hpp"
*/




#include <vector>
#include <iostream>


#ifndef KOLOS_2_SZYBOWIEC_HPP
#define KOLOS_2_SZYBOWIEC_HPP

using namespace std;

class Szybowiec : public virtual StatekPowietrzny
        {
protected:


public:


    void print_wiek() ;

    Szybowiec() ;

    ~Szybowiec();


    void print() ;

    friend ostream& operator << (ostream &os, const Szybowiec& c);


};


#endif //KOLOS_2_SZYBOWIEC_HPP
