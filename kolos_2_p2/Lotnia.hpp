//
// Created by msztu223 on 16.06.2023.
//

#include "StatekPowietrzny.hpp"


#ifndef KOLOS_2_LOTNIA_HPP
#define KOLOS_2_LOTNIA_HPP

using namespace std;


class Lotnia : public virtual StatekPowietrzny
{
protected:

public:

    Lotnia(string idd);
    Lotnia();
    ~Lotnia();

    void print_wiek();
    void print();

    friend ostream& operator << (ostream &os, const Lotnia& c);


};


#endif //KOLOS_2_LOTNIA_HPP
