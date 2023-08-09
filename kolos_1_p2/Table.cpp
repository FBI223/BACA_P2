//Marcin Sztukowski
#include "Table.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iostream>

#include "DataInterface.hpp"

using namespace std;

void Table::dodaj_char_x_y(char x_in,  int y,  int x) {

    if (  !( (x_in == '_') || (x_in == 'X' )  ) )
    {
        x_in = '_';
    }
    int czy_dodac = 1 ;
    if ( x >= n )
    {
        czy_dodac = 0 ;
    } else if ( y >= n )
    {
        czy_dodac = 0;
    } else if ( n <= 0  )
    {
        czy_dodac = 0;
    } else if ( x < 0 )
    {
        czy_dodac = 0 ;
    } else if ( y < 0  )
    {
        czy_dodac=0;
    }

    if (   czy_dodac == 1  )
    {
        AA(tab,y,x) = x_in;
    } else
    {

    }
}

Table::Table() {
    n=0;
    tab= nullptr;
}

Table::Table(int n_in) {
    if ( n_in > 0  )
    {
        n = n_in;
        tab = (char**) malloc(n* sizeof(char*));
        for ( int i = 0 ; i < n_in ; i++ )
        {
            A(tab,i) = (char*) malloc(n* sizeof(char ));
        }

    } else {
        n = 0 ;
        tab = NULL;
    }


}

Table::Table(const Table &other) {
    n = other.n;
    tab = (char**) malloc(n* sizeof(char*));
    for ( int i = 0 ; i < n ; i++)
    {
        A(tab,i) = (char*) malloc(n* sizeof(char ));
        for ( int j = 0 ; j < n ; j++ )
        {
            AA(tab,i,j) = AA(other.tab,i,j);
        }
    }
}

Table::Table(const Table *other) {

    if ( other->n > 0  )
    {
        n = other->n;
        tab = (char**) malloc(n* sizeof(char*));
        for ( int i = 0 ; i < n ; i++)
        {
            A(tab,i) = (char*) malloc(n* sizeof(char ));
            for ( int j = 0 ; j < n ; j++ )
            {
                AA(tab,i,j) = AA(other->tab,i,j);
            }
        }
    }


}


Table::~Table() {

    if ( n > 0  )
    {
        for ( int i = 0 ; i < n ; i++)
        {
            free(A( tab , i ) );
        }
        free(tab);
    }


}



Table& Table::operator=(const Table& inny) {
    if (this != &inny) {

        cout << " siema \n";

        // 1. Usuń starą pamięć
        for (unsigned int i = 0; i < n; i++)
            std::free(tab[i]);
        std::free(tab);

        // 2. Skopiuj wartości z obiektu 'inny'
        n = inny.n;

        if ( inny.n > 0  )
        {
            n = inny.n;
            tab = (char**) malloc(n* sizeof(char*));
            for ( int i = 0 ; i < n ; i++)
            {
                A(tab,i) = (char*) malloc(n* sizeof(char ));
                for ( int j = 0 ; j < n ; j++ )
                {
                    AA(tab,i,j) = AA(inny.tab,i,j);
                }
            }
        }



//        tab = (char**)std::malloc(n * sizeof(char*));
//        for (unsigned int i = 0; i < n; i++) {
//            tab[i] = (char*)std::malloc((strlen(inny.tab[i])+1)*(sizeof(char))); // alokujemy pamięć dla każdego ciągu znaków
//            strcpy(tab[i], inny.tab[i]); // kopiujemy ciąg znaków
//        }

    }
    return *this;
}




void Table::kasuj_cala_tablice() {
    if ( n > 0  )
    {
        for ( int i = 0 ; i < n ; i++)
        {
            free(A( tab , i ) );
        }
        free(tab);
        n=0;
        tab = nullptr;
    }
}


char Table::zwroc_char_y_x(int y, int x) {

    return AA(this->tab,y,x);
}


void Table::tworz_cala_tablice( int wymiar )
{
    if ( n > 0  )
    {
        this->kasuj_cala_tablice();
    }

    if ( wymiar > 0  )
    {
        n = wymiar;
        tab = (char**) malloc(n* sizeof(char*));
        for ( int i = 0 ; i < wymiar ; i++ )
        {
            A(tab,i) = (char*) malloc(n* sizeof(char ));
        }

    }


}

