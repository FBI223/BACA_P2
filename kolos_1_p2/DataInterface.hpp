//Marcin Sztukowski


#include <iostream>
#include <stdio.h>
#include <cstdio>
#include "stdlib.h"
#include "string.h"
#include <string>
#include <stdlib.h>
#include "Table.hpp"

#define MAX_LINE_LENGTH 128


#pragma once

using namespace std;


class DataInterface{


public: // nie deklaruj tablicy tutaj


    DataInterface() ;
    ~DataInterface() ;

    void wczytaj( string sciezka , Table* wsk_do_t );
    void printuj_tab(Table* wsk_t) ;
    void zapisz( int ktory_dzien , Table* wsk_do_t ) ;


};




