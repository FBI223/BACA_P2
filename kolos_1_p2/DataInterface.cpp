//Marcin Sztukowski

#include "DataInterface.hpp"
#include <iostream>


DataInterface::DataInterface() {

}

DataInterface::~DataInterface() {

}


void DataInterface::wczytaj(std::string sciezka, Table *wsk_do_t) {


    std::printf(" \n -------------------------------------------------- \n") ;

    int n_data = 0 ;
    FILE* file_in = fopen(sciezka.c_str(), "r");
    if (file_in == NULL) {
        printf("Error opening file!\n");
        return ;
    } else {
        cout << "file oppened: " << sciezka << endl;
    }

    char line[MAX_LINE_LENGTH];
    unsigned int index = 0 ;

    fgets(line, MAX_LINE_LENGTH, file_in);
    while ( (line[index] != '\n' && line[index] != '\0' ) ) {
        index++;
    }

    if ( wsk_do_t->n == 0 )
    {
        wsk_do_t->kasuj_cala_tablice();
    }

    n_data = index;
    wsk_do_t->tworz_cala_tablice( index ) ;
    std::fclose(file_in);
    file_in = fopen(sciezka.c_str(), "r");
    int wiersz = -1 ;
    int kolumna = 0 ;
    int czy_blad = 0;

    while (fgets(line, MAX_LINE_LENGTH, file_in) != NULL) {
        wiersz++;
        index = 0 ;
        kolumna = -1;
        while ( (line[index] != '\n' && line[index] != '\0' ) ) {
            kolumna++ ;
            if ( index >= n_data )
            {
                czy_blad = 1 ;
                break;
            }
            if ( !((line[index] == '_') || ( line[index] == 'X' )) ) {
                line[index] = '_';
            }
            wsk_do_t->dodaj_char_x_y( line[index],wiersz,kolumna ) ;
            index++;
        }

        if ( index < n_data )
        {
            czy_blad = 1 ;
            break;
        }

    }


    if ( czy_blad == 1  )
    {
        std::printf("\n nastapil blad wczytania, kasuje cala dotychczasowa tablice\n") ;

        wsk_do_t->kasuj_cala_tablice();
    } else
    {
        std::printf("wczytywanie powiodlo sie, wyswietlam wczytane dane :\n");
        printuj_tab(wsk_do_t) ;
    }

    std::fclose(file_in);


    std::printf(" \n -------------------------------------------------- \n\n") ;


}

void DataInterface::printuj_tab(Table *wsk_t) {

    std::printf("\n") ;
    if ( wsk_t->n > 0  )
    {

        for ( int i = 0 ; i < wsk_t->n ; i++ )
        {
            for ( int j = 0 ; j < wsk_t->n ; j++)
            {
                std::printf("%c", AA(wsk_t->tab,i,j));
            }
            printf("\n");
        }

    } else
    {
        std::printf("nie ma nic do printowania, tabelka nie istnieje\n") ;
    }
    std::printf("\n") ;

}


void DataInterface::zapisz(int ktory_dzien, Table *wsk_do_t) {

    cout << endl;
    cout << " -------------------------------------------------- " << endl;
    if ( wsk_do_t->n > 0  )
    {

        char ktory_dzien_str[32]; // Ensure this is large enough for any integer + null terminator
        sprintf(ktory_dzien_str, "%d", ktory_dzien);
        int i = 0 ;
        while ( ktory_dzien_str[i] != '\0' )
        {
            i++;
        }
        ktory_dzien_str[i] = '.';
        ktory_dzien_str[i+1] = 't';
        ktory_dzien_str[i+2] = 'x';
        ktory_dzien_str[i+3] = 't';
        ktory_dzien_str[i+4] = '\0';

        FILE* file_out = fopen( ktory_dzien_str , "w");
        if (file_out == NULL) {
            printf("Error opening file!\n");
            return ;
        } else {
            cout << "file openned correctly " << endl;
        }

        cout << "saving data to " << ktory_dzien_str << " ..." << endl;

        int wiersz = 0 ;
        for ( int i = 0 ; i < wsk_do_t->n - 1  ; i++ )
        {

            for ( int j = 0 ; j < wsk_do_t->n ; j++ )
            {
                char char_out = AA(wsk_do_t->tab,i,j);
                std::fputc( char_out , file_out );
            }
            char char_out = '\n' ;
            std::fputc( char_out , file_out );

            wiersz++;
        }

        for ( int j = 0 ; j < wsk_do_t->n ; j++ )
        {
            char char_out = AA(wsk_do_t->tab,wiersz,j);
            std::fputc( char_out , file_out );
        }


        cout << "data saved "  << endl;
    } else
    {
        cout << "could not save data "  << endl;
    }
    cout << " -------------------------------------------------- " << endl;
    cout << endl;


}


