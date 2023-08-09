#include <iostream>

using namespace std;


#include "Table.hpp"
#include "Game.hpp"
#include "DataInterface.hpp"


int main() {


    Game gra = Game();
    Table tabelka_testowa = Table();
    DataInterface interfejs = DataInterface( );
    interfejs.wczytaj("C:\\Users\\msztu\\CLionProjects\\P2\\KOLOS_1_P2_POPRAWIONE\\temp.txt" , &tabelka_testowa );
    interfejs.zapisz(0,&tabelka_testowa) ;

    gra.przeprowadz_symulacje_n_krokow( 5 , &tabelka_testowa) ;


    tabelka_testowa.kasuj_cala_tablice();


    cout << "Hello, World!" << endl;
    return 0;
}
