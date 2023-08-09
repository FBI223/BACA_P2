//Marcin Sztukowski
#define A(ptr,i) *(ptr + i)
#define AA(ptr,i,j) *(*(ptr + i )+j)

#include <iostream>
#include <stdio.h>

#pragma once


class Table{

public:
    unsigned int n;
    char** tab;

    Table& operator=(const Table& inny);

    char zwroc_char_y_x( int y , int x);


    void kasuj_cala_tablice();

    Table();

    Table( const Table& other  );
    Table( const Table* other  );

    ~Table(   );

    Table(int n_in);

    void dodaj_char_x_y( char x_in ,  int y,  int x);


    void tworz_cala_tablice( int wymiar );


};

