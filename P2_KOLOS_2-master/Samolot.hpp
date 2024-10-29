//
// Created by msztu223 on 16.06.2023.
//

#include "StatekPowietrzny.hpp"

#ifndef KOLOS_2_SAMOLOT_HPP
#define KOLOS_2_SAMOLOT_HPP

using namespace std;

class Samolot : public virtual StatekPowietrzny
{
protected:

public:

    void print_wiek()
    {
        cout << " wiek samolotu to " << this->wiek << endl;
    }

    Samolot();

    Samolot(string idd);


    ~Samolot();


    void print();


    friend ostream& operator << (ostream &os, const Samolot& c);


};





#endif //KOLOS_2_SAMOLOT_HPP
