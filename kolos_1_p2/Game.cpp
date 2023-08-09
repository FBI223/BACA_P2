//Marcin Sztukowski

#include "Game.hpp"
#include "Table.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "DataInterface.hpp"

#define A(ptr,i) *(ptr + i)
#define AA(ptr,i,j) *(*(ptr + i )+j)

Game::Game() {

}

Game::~Game() {


}


/*
zywa komorka, która ma mniej niż dwóch sąsiadów, w kolejnym kroku umiera.
Żywa komórka, która ma więcej niż trzech sąsiadów, umiera.
Żywa komórka, która ma dwóch lub trzech sąsiadów – przeżywa.
Martwa komórka, która ma trzech żywych sąsiadów – ożywa
*/

char Game::jaka_bedzie_komorka_w_next_dniu(Table *wsk_do_t ,int y, int x ) {

    int ile_zyjacych_sasiadow = 0 ;
    int ile_martwych_sasiadow = 0 ;
    int n = wsk_do_t->n;

    char wynikowy_char = '\0' ;


    // 1 sasiad
    if ( y-1 >= 0 && x-1 >= 0  )
    {
        if (AA(wsk_do_t->tab,y-1,x-1) == 'X' )
        {
            ile_zyjacych_sasiadow++;
        } else if ( AA(wsk_do_t->tab,y-1,x-1) == '_' )
        {
            ile_martwych_sasiadow++;
        }
    } else
    {
        ile_martwych_sasiadow++;
    }


    // 2 sasiad
    if (  x-1 >= 0  )
    {
        if (AA(wsk_do_t->tab,y,x-1) == 'X' )
        {
            ile_zyjacych_sasiadow++;
        } else if ( AA(wsk_do_t->tab,y,x-1) == '_' )
        {
            ile_martwych_sasiadow++;
        }
    } else
    {
        ile_martwych_sasiadow++;
    }


    // 3 sasiad
    if ( y+1 < n && x-1 >= 0  )
    {
        if (AA(wsk_do_t->tab,y+1,x-1) == 'X' )
        {
            ile_zyjacych_sasiadow++;
        } else if ( AA(wsk_do_t->tab,y+1,x-1) == '_' )
        {
            ile_martwych_sasiadow++;
        }
    } else
    {
        ile_martwych_sasiadow++;
    }


    // 4 sasiad
    if ( y+1 < n )
    {
        if (AA(wsk_do_t->tab,y+1,x) == 'X' )
        {
            ile_zyjacych_sasiadow++;
        } else if ( AA(wsk_do_t->tab,y+1,x) == '_' )
        {
            ile_martwych_sasiadow++;
        }
    } else
    {
        ile_martwych_sasiadow++;
    }


    // 5 sasiad
    if ( y+1 < n && x+1 < n  )
    {
        if (AA(wsk_do_t->tab,y+1,x+1) == 'X' )
        {
            ile_zyjacych_sasiadow++;
        } else if ( AA(wsk_do_t->tab,y+1,x+1) == '_' )
        {
            ile_martwych_sasiadow++;
        }
    } else
    {
        ile_martwych_sasiadow++;
    }


    // 6 sasiad
    if ( x + 1 < n  )
    {
        if (AA(wsk_do_t->tab,y,x+1) == 'X' )
        {
            ile_zyjacych_sasiadow++;
        } else if ( AA(wsk_do_t->tab,y,x+1) == '_' )
        {
            ile_martwych_sasiadow++;
        }
    } else
    {
        ile_martwych_sasiadow++;
    }


    // 7 sasiad
    if ( y-1 >= 0 && x+1 < n  )
    {
        if (AA(wsk_do_t->tab,y-1,x+1) == 'X' )
        {
            ile_zyjacych_sasiadow++;
        } else if ( AA(wsk_do_t->tab,y-1,x+1) == '_' )
        {
            ile_martwych_sasiadow++;
        }
    } else
    {
        ile_martwych_sasiadow++;
    }

    // 8 sasiad
    if ( y-1 >= 0  )
    {
        if (AA(wsk_do_t->tab,y-1,x) == 'X' )
        {
            ile_zyjacych_sasiadow++;
        } else if ( AA(wsk_do_t->tab,y-1,x) == '_' )
        {
            ile_martwych_sasiadow++;
        }
    } else
    {
        ile_martwych_sasiadow++;
    }




    /*
zywa komorka, która ma mniej niż dwóch sąsiadów, w kolejnym kroku umiera.
Żywa komórka, która ma więcej niż trzech sąsiadów, umiera.
Żywa komórka, która ma dwóch lub trzech sąsiadów – przeżywa.
Martwa komórka, która ma trzech żywych sąsiadów – ożywa
*/

    // rob kopie tablicy i na niej rob zmiany i potem zastap stara tablice nowa i wykasuj ja

    if ( AA(wsk_do_t->tab , y,  x ) == 'X' )
    {
        wynikowy_char='X';
        //cout << " zywa    " << " ile zywych sasiadow "  << ile_zyjacych_sasiadow << "    ile martych sasaidopw " << ile_martwych_sasiadow  <<endl;
        if ( !(ile_zyjacych_sasiadow == 2 || ile_zyjacych_sasiadow == 3 ) )
        {
            //AA(wsk_do_t->tab , y,  x ) = '_' ;
            wynikowy_char='_';
        }

    } else if ( AA(wsk_do_t->tab , y,  x ) == '_' )
    {
        wynikowy_char = '_';
        //cout << " martwa " << " ile zywych sasiadow "  << ile_zyjacych_sasiadow << "    ile martych sasaidopw " << ile_martwych_sasiadow  <<endl;
        if ( ile_zyjacych_sasiadow == 3 )
        {
            //AA(wsk_do_t->tab , y,  x ) = 'X' ;
            wynikowy_char='X';
        }
    }


    return wynikowy_char;

}

void Game::idz_do_kolejnego_dnia(Table *wsk_do_t) {

    Table kopia_tablicy;
    kopia_tablicy = *wsk_do_t ;
    //Table kopia_tablicy = Table(wsk_do_t);
    Table* kopia_tablicy_wsk = &kopia_tablicy;



    char temp_char = '\0';

    for ( int i = 0 ; i < wsk_do_t->n ; i++ )
    {
        for ( int j = 0 ; j < wsk_do_t->n ; j++ )
        {
            temp_char =  jaka_bedzie_komorka_w_next_dniu( wsk_do_t,i,j ) ;
            kopia_tablicy_wsk->dodaj_char_x_y(temp_char,i,j);
        }
    }



    for ( int i = 0 ; i < wsk_do_t->n ; i++ )
    {
        for ( int j = 0 ; j < wsk_do_t->n ; j++ )
        {
            wsk_do_t->dodaj_char_x_y(AA(kopia_tablicy_wsk->tab,i,j) , i , j );
        }
    }


    //*wsk_do_t = kopia_tablicy_wsk ;

    kopia_tablicy_wsk->kasuj_cala_tablice();


}


void Game::przeprowadz_symulacje_n_krokow(int ile_dni, Table *wsk_do_t) {

    cout << endl;
    DataInterface interfejs = DataInterface();
    if ( wsk_do_t->n <= 0 || ile_dni <=0 )
    {
        cout << " nie mozna przeprowadzic symulacji " << endl;
    } else
    {
        cout << " przeprowadzam symulacje ... " << endl;

        interfejs.zapisz( 0 ,wsk_do_t );

        for ( int k = 0 ; k < ile_dni ; k++)
        {
            idz_do_kolejnego_dnia(wsk_do_t) ;
            cout << "--------------------------------" << endl;
            cout << endl;
            cout << "dzien nr " << (k+1) << endl;
            interfejs.printuj_tab(wsk_do_t);
            cout << "--------------------------------" << endl;

            interfejs.zapisz( (k+1),wsk_do_t );

        }

    }
    cout << endl;

}


