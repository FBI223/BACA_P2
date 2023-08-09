// Marcin Sztukowski


#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>

#include "Table.hpp"
#include "DataInterface.hpp"



class Game{

public:

    /*
    zywa komorka, która ma mniej niż dwóch sąsiadów, w kolejnym kroku umiera.
    Żywa komórka, która ma więcej niż trzech sąsiadów, umiera.
    Żywa komórka, która ma dwóch lub trzech sąsiadów – przeżywa.
    Martwa komórka, która ma trzech żywych sąsiadów – ożywa
    */

    Game();
    ~Game();

    void przeprowadz_symulacje_n_krokow( int ile_dni , Table* wsk_do_t ) ;
    void idz_do_kolejnego_dnia( Table* wsk_do_t );
    char jaka_bedzie_komorka_w_next_dniu( Table* wsk_do_t , int y , int x  ) ;


};

