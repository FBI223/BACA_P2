//
// Created by msztu223 on 16.06.2023.
//


#include "Lotnia.hpp"
#include "Motolotnia.hpp"
#include "Samolot.hpp"
#include "Szybowiec.hpp"

#include <vector>
#include <iostream>

#ifndef KOLOS_2_LOTNISKO_HPP
#define KOLOS_2_LOTNISKO_HPP

using namespace std;


template <class CLASS_TYPE >
class Lotnisko{

public:
    vector<CLASS_TYPE*> vector_obiektow;


    Lotnisko(int dlg_vec) : vector_obiektow(dlg_vec, nullptr) {
        cout << "stworzylem lotnisko z " << dlg_vec << " hangarami ! " << endl;
    }


    void add(const CLASS_TYPE* element) {
        vector_obiektow.push_back(element);
    }


    void removeLast() {
        if (!vector_obiektow.empty()) {
            vector_obiektow.pop_back();
        } else {
            throw std::out_of_range("Vector is empty\n");
        }
    }


    CLASS_TYPE*& operator [] (int index) {
        if (index >= 0 && index < vector_obiektow.size()) {
            return vector_obiektow[index];
        } else {
            cout << "zly index , nic tu nie ma !!!! " << endl;
            throw std::out_of_range("zly index, nie ma nic pod nim\n");
        }
    }


};


template <class CLASS_TYPE >
std::ostream& operator<<(std::ostream& os, const Lotnisko<CLASS_TYPE>& lotniskoo) {

    cout << endl;
    cout << "Zaczynamy iteracje po lotnisku !!! " << endl;
    for ( int i = 0 ; i < lotniskoo.vector_obiektow.size() ; i++   )
    {

        if ( lotniskoo.vector_obiektow[i] == nullptr )
        {
            cout << endl;
            cout << "Pod indeksem i : " << i << " stoi pusty hangar " << endl;
        } else
        {
            cout << endl;
            cout << "Pod indeksem i : " << i << " stoi pelny hangar z obiektem w srodku " << endl;
            cout << *lotniskoo.vector_obiektow[i];
        }


    }
    cout << "Konczymy wycieczke po lotnisku !!! " << endl;
    cout << endl;

    return os;
}



#endif //KOLOS_2_LOTNISKO_HPP
