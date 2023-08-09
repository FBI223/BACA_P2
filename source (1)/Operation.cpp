//Marcin Sztukowski
#include "string"
#include "cstdarg"


using namespace std;





void konwertuj_chararr_na_stringa3( int* count_arr, string* string_wyjsciowy , char arr_wejsciowa[] )
{

    if ( (*count_arr) != '\0' )
    {
        (*string_wyjsciowy) += *(arr_wejsciowa+(*count_arr)) ;
        *count_arr += 1 ;
        konwertuj_chararr_na_stringa3(count_arr,string_wyjsciowy,arr_wejsciowa) ;
    }



}


void pod_string_stringa3( int* count_petla_poczatek ,int* iteracja , string* string_obcinany , string* wyjsciowy_string )
{
    if ( *iteracja > 0 )
    {
        *wyjsciowy_string += string_obcinany->at(*count_petla_poczatek);
        *count_petla_poczatek += 1 ;
        *iteracja -= 1 ;
        pod_string_stringa3(count_petla_poczatek,iteracja,string_obcinany,wyjsciowy_string) ;
    }
}



void rob_stringa_z_chara3(int* count_arr  , char* poczatek_arr, string* wyjsciowy_string)
{

    if ( *(poczatek_arr+(*count_arr)) != '\0' )
    {
        *wyjsciowy_string += *(poczatek_arr+(*count_arr) ) ;
        *count_arr += 1 ;
        rob_stringa_z_chara3(count_arr,poczatek_arr,wyjsciowy_string) ;
    }

}



void rob_array_z_va_list3(int* gdzie_jestem, int len, ::va_list lista_va , string* arr_docelowe )
{

    if ( *gdzie_jestem < len )
    {

        char* char_arr_temp = va_arg(lista_va,char*);
        string temp_s = "" ;

        int i = 0 ;

        rob_stringa_z_chara3(&i,char_arr_temp,&temp_s) ;
        *( arr_docelowe+ (*gdzie_jestem) ) = temp_s ;




        *gdzie_jestem = *gdzie_jestem + 1 ;

        rob_array_z_va_list3(gdzie_jestem,len,lista_va,arr_docelowe) ;

    }

}



string Operation ( string (*funkcja)( int , const string*  ), int integer, const string* array_konst )
{

    string wynikk = funkcja(integer , array_konst) ;

    return wynikk ;
}
string Operation ( string (*funkcja)( int , const string*  ), int integer, ... )
{


    string wynik = "" ;

    std::va_list ap;
    va_start(ap,integer) ;
    const int konstt_int = integer;
    string array_string_temp[konstt_int] ;
    //const string string_array[konstt_int] ;
    int count_iteracja = 0;


    rob_array_z_va_list3(&count_iteracja,integer,ap,array_string_temp) ;

    wynik = funkcja(integer,array_string_temp) ;

    va_end(ap) ;

    return wynik ;
}
void Operation ( string* wynik, string (*funkcja)( int , const string*  ), int integer, ... )
{




    string wynikkkk = "" ;

    std::va_list ap;
    va_start(ap,integer) ;
    const int konstt_int = integer;
    string array_string_temp[konstt_int] ;
    //const string string_array[konstt_int] ;
    int count_iteracja = 0;


    rob_array_z_va_list3(&count_iteracja,integer,ap,array_string_temp) ;

    wynikkkk = funkcja(integer,array_string_temp) ;

    *wynik = wynikkkk ;

    va_end(ap) ;





}
void Operation ( string* wynik, string (*funkcja)( int , const string*  ), int integer, const string* array_konst )
{


    *wynik = funkcja(integer,array_konst) ;





}
void Operation ( string& wynik, void (*funkcja)( string* b, int , const string*  ), int integer, const string* array_konst )
{

    string wynik_temp = "" ;
    funkcja(&wynik_temp,integer,array_konst);
    wynik = wynik_temp ;




}
void Operation ( string& wynik, void (*funkcja)( string* a, int , const string* ), int integer, ... )
{


    string wynikkkk = "" ;

    std::va_list ap;
    va_start(ap,integer) ;
    const int konstt_int = integer;
    string array_string_temp[konstt_int] ;
    //const string string_array[konstt_int] ;
    int count_iteracja = 0;


    rob_array_z_va_list3(&count_iteracja,integer,ap,array_string_temp) ;

    funkcja(&wynikkkk,integer,array_string_temp) ;

    wynik = wynikkkk ;

    va_end(ap) ;



}
