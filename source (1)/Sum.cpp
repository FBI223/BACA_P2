//Marcin Sztukowski
#include "string"
#include "cstdarg"


using namespace std;



void konwertuj_chararr_na_stringa( int* count_arr, string* string_wyjsciowy , char arr_wejsciowa[] )
{

    if ( (*count_arr) != '\0' )
    {
        (*string_wyjsciowy) += *(arr_wejsciowa+(*count_arr)) ;
        *count_arr += 1 ;
        konwertuj_chararr_na_stringa(count_arr,string_wyjsciowy,arr_wejsciowa) ;
    }


}


void pod_string_stringa( int* count_petla_poczatek ,int* iteracja ,string* string_obcinany , string* wyjsciowy_string )
{

    if ( (*iteracja > 0) && ( *count_petla_poczatek < string_obcinany->length() ) )
    {

        *wyjsciowy_string += string_obcinany->at(*count_petla_poczatek);
        *count_petla_poczatek += 1 ;
        *iteracja -= 1 ;
        pod_string_stringa(count_petla_poczatek,iteracja,string_obcinany,wyjsciowy_string) ;
    }
}


void rob_stringa_z_chara(int* count_arr  , char* poczatek_arr, string* wyjsciowy_string)
{

    if ( *(poczatek_arr+(*count_arr)) != '\0' )
    {
        *wyjsciowy_string += *(poczatek_arr+(*count_arr) ) ;
        *count_arr += 1 ;
        rob_stringa_z_chara(count_arr,poczatek_arr,wyjsciowy_string) ;
    }

}

void weryfikacja_zer_w_stringu( int* count_str , int len , string* string_weryfikacja )
{

    if ( ((*count_str) < len) && (string_weryfikacja->at(*count_str) == '0')  )
    {

        *count_str += 1 ;
        weryfikacja_zer_w_stringu(count_str,len,string_weryfikacja) ;
    }

}
int czy_poprawiac_string(  string* string_weryfikacja )
{
    int wynik = 0;

    if ( (string_weryfikacja->length() >= 2) && ( string_weryfikacja->at(1) == '0' )  )
    {
        if ( ( string_weryfikacja->at(0) == '0' ) || ( string_weryfikacja->at(0) == '+' ) || ( string_weryfikacja->at(0) == '-' ) )
        {
            wynik = 1 ;
        }


    } else if ( (string_weryfikacja->length() >= 2) && ( string_weryfikacja->at(0) == '0' ) )
    {
        wynik = 1;
    } else if ( (string_weryfikacja->length() >= 2) && ( string_weryfikacja->at(0) == '+') )
    {
        wynik = 1;
    }


    return wynik;

}

void ewentualne_poprawienie_stringa( string* string_weryfikacja )
{

    if (czy_poprawiac_string( string_weryfikacja ) == 1 )
    {
        int count_str = 0 ;
        int len = string_weryfikacja->length() ;


        if ( len == 2  )
        {
            if ( string_weryfikacja->at(1) != '0' )
            {
                *string_weryfikacja = string_weryfikacja->at(1) ;
            } else
            {
                *string_weryfikacja = "0" ;
            }


        } else if ( len > 2  )
        {
            if ( (string_weryfikacja->at(0) == '+') || (string_weryfikacja->at(0) == '-') )
            {
                count_str = 1 ;
            }

            weryfikacja_zer_w_stringu( &count_str , len , string_weryfikacja ) ;

            if ( count_str >= string_weryfikacja->length() )
            {
                *string_weryfikacja = "0" ;

            } else
            {
                string string_znaku = "" ;
                if ( string_weryfikacja->at(0) == '-')
                {
                    string_znaku = "-";
                }


                if ( string_weryfikacja->at(0) != '+' )
                {
                    string obciety = "" ;
                    int ii = count_str;
                    int jj = len-count_str ;
                    pod_string_stringa(&ii,&jj,string_weryfikacja,&obciety) ;
                    *string_weryfikacja = string_znaku + obciety ;
                } else
                {

                    string obciety = "" ;
                    int ii = count_str;
                    int jj = len-count_str ;
                    pod_string_stringa(&ii,&jj,string_weryfikacja,&obciety) ;
                    *string_weryfikacja =  obciety ;
                }


            }


        }


    }


}

int rozpoznaj_char( char x_in )
{
    int wynik = 0;


    if ( x_in == '1' )
    {
        wynik = 1;
    } else if ( x_in == '2' )
    {
        wynik = 2;
    } else if ( x_in == '3' )
    {
        wynik = 3;
    } else if ( x_in == '4' )
    {
        wynik = 4;
    } else if ( x_in == '5' )
    {
        wynik = 5;
    } else if ( x_in == '6' )
    {
        wynik = 6;
    } else if ( x_in == '7' )
    {
        wynik = 7;
    } else if ( x_in == '8' )
    {
        wynik = 8;
    } else if ( x_in == '9' )
    {
        wynik = 9;
    } else if ( x_in == '0' )
    {
        wynik = 0;
    } else if ( x_in == '+' )
    {
        wynik = 0;
    }else if ( x_in == '-' )
    {
        wynik = 0;
    }


    return wynik;

}

int rozpoznaj_string( string x_in )
{
    int wynik_int = 0;


    if ( x_in == "-9")
    {
        wynik_int = -9;
    } else if ( x_in == "-8" )
    {
        wynik_int = -8;
    } else if ( x_in == "-7" )
    {
        wynik_int = -7;
    } else if ( x_in == "-6" )
    {
        wynik_int = -6;
    } else if ( x_in == "-5" )
    {
        wynik_int = -5;
    } else if ( x_in == "-4" )
    {
        wynik_int = -4;
    } else if ( x_in == "-3" )
    {
        wynik_int = -3;
    } else if ( x_in == "-2" )
    {
        wynik_int = -2;
    } else if ( x_in == "-1" )
    {
        wynik_int = -1;
    } else if ( x_in == "0" )
    {
        wynik_int = 0;
    } else if ( x_in == "1" )
    {
        wynik_int = 1;
    }else if ( x_in == "2" )
    {
        wynik_int = 2;
    }else if ( x_in == "3" )
    {
        wynik_int = 3;
    }else if ( x_in == "4" )
    {
        wynik_int = 4;
    }else if ( x_in == "5" )
    {
        wynik_int = 5;
    }else if ( x_in == "6" )
    {
        wynik_int = 6;
    }else if ( x_in == "7" )
    {
        wynik_int = 7;
    }else if ( x_in == "8" )
    {
        wynik_int = 8;
    }else if ( x_in == "9" )
    {
        wynik_int = 9;
    }

    return wynik_int;

}


string dodaj_2_cyfry(string s1 , string s2 )
{

    string wynik_s = "" ;
    int wynik_int = 0;
    int s1_int = rozpoznaj_string(s1) ;
    int s2_int = rozpoznaj_string(s2) ;
    wynik_int = s1_int + s2_int ;




    if ( wynik_int == 0 )
    {
        wynik_s = "0" ;
    } else if ( wynik_int == 1 )
    {
        wynik_s = "1" ;
    } else if ( wynik_int == 2 )
    {
        wynik_s = "2" ;
    } else if ( wynik_int == 3 )
    {
        wynik_s = "3" ;
    } else if ( wynik_int == 4 )
    {
        wynik_s = "4" ;
    } else if ( wynik_int == 5 )
    {
        wynik_s = "5" ;
    } else if ( wynik_int == 6 )
    {
        wynik_s = "6" ;
    } else if ( wynik_int == 7 )
    {
        wynik_s = "7" ;
    } else if ( wynik_int == 8 )
    {
        wynik_s = "8" ;
    } else if ( wynik_int == 9 )
    {
        wynik_s = "9" ;
    } else if ( wynik_int == 10 )
    {
        wynik_s = "10" ;
    } else if ( wynik_int == 11)
    {
        wynik_s = "11" ;
    } else if ( wynik_int == 12 )
    {
        wynik_s = "12" ;
    } else if ( wynik_int == 13 )
    {
        wynik_s = "13" ;
    } else if ( wynik_int == 14 )
    {
        wynik_s = "14" ;
    } else if ( wynik_int == 15 )
    {
        wynik_s = "15" ;
    } else if ( wynik_int == 16 )
    {
        wynik_s = "16" ;
    } else if ( wynik_int == 17 )
    {
        wynik_s = "17" ;
    } else if ( wynik_int == 18 )
    {
        wynik_s = "18" ;
    }  else if ( wynik_int == -1 )
    {
        wynik_s = "-1" ;
    } else if ( wynik_int == -2 )
    {
        wynik_s = "-2" ;
    } else if ( wynik_int == -3 )
    {
        wynik_s = "-3" ;
    } else if ( wynik_int == -4 )
    {
        wynik_s = "-4" ;
    } else if ( wynik_int == -5 )
    {
        wynik_s = "-5" ;
    } else if ( wynik_int == -6 )
    {
        wynik_s = "-6" ;
    } else if ( wynik_int == -7 )
    {
        wynik_s = "-7" ;
    } else if ( wynik_int == -8 )
    {
        wynik_s = "-8" ;
    } else if ( wynik_int == -9 )
    {
        wynik_s = "-9" ;
    } else if ( wynik_int == -10 )
    {
        wynik_s = "-10" ;
    } else if ( wynik_int == -11)
    {
        wynik_s = "-11" ;
    } else if ( wynik_int == -12 )
    {
        wynik_s = "-12" ;
    } else if ( wynik_int == -13 )
    {
        wynik_s = "-13" ;
    } else if ( wynik_int == -14 )
    {
        wynik_s = "-14" ;
    } else if ( wynik_int == -15 )
    {
        wynik_s = "-15" ;
    } else if ( wynik_int == -16 )
    {
        wynik_s = "-16" ;
    } else if ( wynik_int == -17 )
    {
        wynik_s = "-17" ;
    } else if ( wynik_int == -18 )
    {
        wynik_s = "-18" ;
    }

    return wynik_s ;



}


char dodaj_do_sb(char x1 , char x2, char* czy_przenosic_wejcie , char* czy_przenosic_wyjscie )
{

    char wynik_char = '0' ;
    int wynik = 0;
    if ( *czy_przenosic_wejcie == '0' )
    {

        wynik += rozpoznaj_char(x1);
        wynik += rozpoznaj_char(x2);

        if ( wynik >= 10 )
        {
            wynik-= 10;
            *czy_przenosic_wyjscie = '1' ;
        }


    } else if ( *czy_przenosic_wejcie == '1' )
    {
        wynik += 1 ;
        wynik += rozpoznaj_char(x1);
        wynik += rozpoznaj_char(x2);

        if ( wynik >= 10 )
        {
            wynik-= 10;
            *czy_przenosic_wyjscie = '1' ;
        } else
        {
            *czy_przenosic_wyjscie = '0' ;
        }

    }


    if ( wynik == 0 )
    {
        wynik_char = '0' ;
    } else if (wynik == 1)
    {
        wynik_char = '1' ;
    }else if (wynik == 2)
    {
        wynik_char = '2' ;
    }else if (wynik == 3)
    {
        wynik_char = '3' ;
    }else if (wynik == 4)
    {
        wynik_char = '4' ;
    }else if (wynik == 5)
    {
        wynik_char = '5' ;
    }else if (wynik == 6)
    {
        wynik_char = '6' ;
    }else if (wynik == 7)
    {
        wynik_char = '7' ;
    } else if (wynik == 8)
    {
        wynik_char = '8' ;
    }else if (wynik == 9)
    {
        wynik_char = '9' ;
    }



    return wynik_char ;

}




char odejmij_od_sb(char x1 , char x2, char* czy_przenosic_wejcie , char* czy_przenosic_wyjscie )
{

    char wynik_char = '0' ;
    int wynik = 0;
    if ( *czy_przenosic_wejcie == '0' )
    {

        wynik += rozpoznaj_char(x1);
        wynik -= rozpoznaj_char(x2);

        if ( wynik < 0 )
        {
            wynik = wynik + 10 ;
            *czy_przenosic_wyjscie = '1' ;
        }



    } else if ( *czy_przenosic_wejcie == '1' )
    {
        wynik += rozpoznaj_char(x1);

        if ( wynik == 0  )
        {
            *czy_przenosic_wyjscie = '1' ;
            wynik = 9;
            wynik = wynik - rozpoznaj_char(x2) ;
        } else
        {

            wynik -= 1;
            *czy_przenosic_wyjscie = '0' ;
            wynik -= rozpoznaj_char(x2) ;
            if ( wynik < 0 )
            {
                wynik = wynik + 10 ;
                *czy_przenosic_wyjscie = '1' ;
            }


            *czy_przenosic_wejcie == '0' ;

        }


    }


    if ( wynik == 0 )
    {
        wynik_char = '0' ;
    } else if (wynik == 1)
    {
        wynik_char = '1' ;
    }else if (wynik == 1)
    {
        wynik_char = '1' ;
    }else if (wynik == 2)
    {
        wynik_char = '2' ;
    }else if (wynik == 3)
    {
        wynik_char = '3' ;
    }else if (wynik == 4)
    {
        wynik_char = '4' ;
    }else if (wynik == 5)
    {
        wynik_char = '5' ;
    }else if (wynik == 6)
    {
        wynik_char = '6' ;
    }else if (wynik == 7)
    {
        wynik_char = '7' ;
    } else if (wynik == 8)
    {
        wynik_char = '8' ;
    }else if (wynik == 9)
    {
        wynik_char = '9' ;
    }



    return wynik_char ;

}




void pseudo_petla_2( int* poz_s1 , int* poz_s2, int* poz_wynik ,const string* s1 , const string* s2, char wynik[] , char* czy_przenosiny )
{
    if ( (*poz_wynik) >= 0 )
    {

        char temp_char_1 = '0' ;
        char temp_char_2 = '0' ;

        if ( (*poz_s1) < 0 )
        {
            temp_char_1 = '0' ;
        } else
        {
            temp_char_1 = s1->at(*poz_s1) ;
            (*poz_s1) = (*poz_s1) - 1 ;
        }

        if ( (*poz_s2) < 0 )
        {
            temp_char_2 = '0' ;
        } else
        {
            temp_char_2 = s2->at(*poz_s2) ;
            (*poz_s2) = (*poz_s2) - 1 ;
        }


        wynik[*poz_wynik] = odejmij_od_sb(temp_char_1,temp_char_2,czy_przenosiny, czy_przenosiny) ;

        (*poz_wynik ) = (*poz_wynik ) - 1 ;
        pseudo_petla_2( poz_s1 , poz_s2, poz_wynik , s1 , s2  , wynik , czy_przenosiny );
    }
}


void pseudo_petla_1( int* poz_s1 , int* poz_s2, int* poz_wynik ,const string* s1 , const string* s2, char wynik[] , char* czy_przenosiny )
{
    if ( (*poz_wynik) >= 0 )
    {

        char temp_char_1 = '0' ;
        char temp_char_2 = '0' ;

        if ( (*poz_s1) < 0 )
        {
            temp_char_1 = '0' ;
        } else
        {
            temp_char_1 = s1->at(*poz_s1) ;
            (*poz_s1) = (*poz_s1) - 1 ;
        }

        if ( (*poz_s2) < 0 )
        {
            temp_char_2 = '0' ;
        } else
        {
            temp_char_2 = s2->at(*poz_s2) ;
            (*poz_s2) = (*poz_s2) - 1 ;
        }


        wynik[*poz_wynik] = dodaj_do_sb(temp_char_1,temp_char_2,czy_przenosiny, czy_przenosiny) ;


        (*poz_wynik ) = (*poz_wynik ) - 1 ;
        pseudo_petla_1( poz_s1 , poz_s2, poz_wynik , s1 , s2  , wynik , czy_przenosiny );
    }
}


void pseudo_petla_1_bez_const( int* poz_s1 , int* poz_s2, int* poz_wynik , string* s1 ,  string* s2, char wynik[] , char* czy_przenosiny )
{
    if ( (*poz_wynik) >= 0 )
    {

        char temp_char_1 = '0' ;
        char temp_char_2 = '0' ;

        if ( (*poz_s1) < 0 )
        {
            temp_char_1 = '0' ;
        } else
        {
            temp_char_1 = s1->at(*poz_s1) ;
            (*poz_s1) = (*poz_s1) - 1 ;
        }

        if ( (*poz_s2) < 0 )
        {
            temp_char_2 = '0' ;
        } else
        {
            temp_char_2 = s2->at(*poz_s2) ;
            (*poz_s2) = (*poz_s2) - 1 ;
        }


        wynik[*poz_wynik] = dodaj_do_sb(temp_char_1,temp_char_2,czy_przenosiny, czy_przenosiny) ;


        (*poz_wynik ) = (*poz_wynik ) - 1 ;
        pseudo_petla_1( poz_s1 , poz_s2, poz_wynik , s1 , s2  , wynik , czy_przenosiny );
    }
}


void petelka_pomocnicza_str_1( int* poz_char_arr,char tab[])
{
    if ( tab[*poz_char_arr] == '0' )
    {
        *poz_char_arr = *poz_char_arr + 1 ;
        petelka_pomocnicza_str_1(poz_char_arr, tab) ;
    }
}


void petelka_pomocnicza_str_2( int* poz_char_arr,char tab[], string* wyjscie)
{
    if ( tab[*poz_char_arr] != '\0' )
    {
        wyjscie->push_back(tab[*poz_char_arr]) ;
        *poz_char_arr = *poz_char_arr + 1 ;
        petelka_pomocnicza_str_2(poz_char_arr, tab, wyjscie) ;
    }
}


string sumuj_w_liczby_const(const string* s1 , const string* s2 )
{

    string s_wynikowy = "" ;
    int s1_len = s1->length() ;
    int s2_len = s2->length() ;

    int temp_int = 0;

    int aktualna_poz_s1 = s1->length() - 1 ;
    int aktualna_poz_s2 = s2->length() - 1;

    if ( s1->length() >= s2->length() )
    {
        temp_int = s1->length() ;
    } else
    {
        temp_int = s2->length() ;
    }


    const int dlg_wyniku = temp_int  + 3 ;
    char wynik[dlg_wyniku] ;
    wynik[dlg_wyniku-1] = '\0' ;
    int aktualna_pozycja_wynik = dlg_wyniku-2 ;
    char czy_przenosiny = '0' ;


    if ( (s1->at(0) != '-' ) && ( s2->at(0) != '-' ) )
    {

        // void pseudo_petla_1( int* poz_s1 , int* poz_s2, int* poz_wynik ,string* s1 , string* s2, char wynik[] , char* czy_przenosiny )
        pseudo_petla_1( &aktualna_poz_s1 , &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny) ;
    } else if ( (s1->at(0) == '-') && ( s2->at(0) == '-' ) )
    {
        pseudo_petla_1( &aktualna_poz_s1 , &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;
        wynik[0] = '-' ;

    }else if ( (s1->at(0) == '-') && ( s2->at(0) != '-' ) )
    {
        int index_poczatku_s1 = 1;
        int index_poczatku_s2 = 0;
        int len_s1 = s1->length() - 1;
        int len_s2 = s2->length();
        if ( s2->at(0) == '+' )
        {
            len_s2 -= 1 ;
            index_poczatku_s2 += 1;
        }


        if ( (len_s2 > len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) > (int)(s1->at(index_poczatku_s1)) ) ) )
        {
            pseudo_petla_2( &aktualna_poz_s2, &aktualna_poz_s1 , &aktualna_pozycja_wynik , s2, s1 , wynik , &czy_przenosiny ) ;
        } else if ( (len_s2 < len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) < (int)(s1->at(index_poczatku_s1)) ) ) )
        {
            pseudo_petla_2( &aktualna_poz_s1, &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;
            wynik[0] = '-' ;
        } else
        {

            string s2_bez_znaku;

            string obciety = "" ;
            int ii = 1 ;
            int jj = len_s1 ;
            string s1_do_f = *s1 ;
            pod_string_stringa(&ii,&jj,&s1_do_f,&obciety) ;
            string s1_bez_znaku =  obciety ;

            if ( s2->at(0)=='+' )
            {
                string obciety = "" ;
                ii = 1 ;
                jj = len_s2 ;
                string s2_do_f = *s2 ;
                pod_string_stringa(&ii,&jj,&s2_do_f,&obciety) ;
                string s2_bez_znaku =  obciety ;

            } else
            {
                string obciety = "" ;
                ii = 0 ;
                jj = len_s2 ;
                string s2_do_f = *s2 ;
                pod_string_stringa(&ii,&jj,&s2_do_f,&obciety) ;
                string s2_bez_znaku =  obciety ;

            }

            if ( s2_bez_znaku > s1_bez_znaku  )
            {
                pseudo_petla_2( &aktualna_poz_s2, &aktualna_poz_s1 , &aktualna_pozycja_wynik , s2, s1 , wynik , &czy_przenosiny ) ;
            } else if ( s2_bez_znaku <= s1_bez_znaku  )
            {
                pseudo_petla_2( &aktualna_poz_s1, &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;
                wynik[0] = '-' ;

            }



        }


    } else if ( (s1->at(0) != '-') && ( s2->at(0) == '-' ) )
    {

        int index_poczatku_s1 = 0;
        int index_poczatku_s2 = 1;
        int len_s1 = s1->length() ;
        int len_s2 = s2->length()-1;
        if ( s1->at(0) == '+' )
        {
            len_s1 -= 1 ;
            index_poczatku_s1 += 1;
        }

        if ( (len_s2 > len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) > (int)(s1->at(index_poczatku_s1)) ) ) )
        {
            pseudo_petla_2( &aktualna_poz_s2, &aktualna_poz_s1 , &aktualna_pozycja_wynik , s2, s1 , wynik , &czy_przenosiny ) ;
            wynik[0] = '-' ;
        } else if ( (len_s2 < len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) < (int)(s1->at(index_poczatku_s1)) ) ) )
        {
            pseudo_petla_2( &aktualna_poz_s1, &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;

        } else {


            string obciety = "" ;
            int ii = 1 ;
            int jj = len_s2 ;
            string s2_do_f = *s2 ;
            pod_string_stringa(&ii,&jj,&s2_do_f,&obciety) ;
            string s2_bez_znaku =  obciety ;

            string s1_bez_znaku;
            if (s1->at(0) == '+') {

                obciety = "" ;
                ii = 1 ;
                jj = len_s1 ;
                string s1_do_f = *s1 ;
                pod_string_stringa(&ii,&jj,&s1_do_f,&obciety) ;
                string s1_bez_znaku =  obciety ;

            } else {

                obciety = "" ;
                ii = 0 ;
                jj = len_s1 ;
                string s1_do_f = *s1 ;
                pod_string_stringa(&ii,&jj,&s1_do_f,&obciety) ;
                string s1_bez_znaku =  obciety ;


            }

            if (s2_bez_znaku > s1_bez_znaku) {
                pseudo_petla_2(&aktualna_poz_s2, &aktualna_poz_s1, &aktualna_pozycja_wynik, s2, s1, wynik,
                               &czy_przenosiny);
                wynik[0] = '-';
            } else if (s2_bez_znaku <= s1_bez_znaku) {
                pseudo_petla_2(&aktualna_poz_s1, &aktualna_poz_s2, &aktualna_pozycja_wynik, s1, s2, wynik,
                               &czy_przenosiny);

            }

        }


    }


    s_wynikowy = "" ;
    aktualna_pozycja_wynik = 0 ;
    string s_znaku = "";
    if ( wynik[0] == '-' )
    {
        s_znaku = "-" ;
        aktualna_pozycja_wynik += 1 ;
        petelka_pomocnicza_str_1( &aktualna_pozycja_wynik, wynik ) ;
        //string s_wynikowy_temp(wynik) ; // !!!!!!

        string s_wynikowy_temp="";
        int kk = 0;
        rob_stringa_z_chara(&kk,wynik,&s_wynikowy_temp) ;


        string obciety = "" ;
        int ii = aktualna_pozycja_wynik ;
        int jj = dlg_wyniku - aktualna_pozycja_wynik ;
        pod_string_stringa(&ii,&jj,&s_wynikowy_temp,&obciety) ;

        s_wynikowy_temp = obciety ;

        s_wynikowy_temp = s_znaku + s_wynikowy_temp ;
        s_wynikowy = s_wynikowy_temp ;

    } else if ( wynik[0]=='+' )
    {
        aktualna_pozycja_wynik += 1;
        petelka_pomocnicza_str_1( &aktualna_pozycja_wynik, wynik ) ;
        //string s_wynikowy_temp(wynik) ; // !!!!!


        string s_wynikowy_temp="";
        int kk = 0;
        rob_stringa_z_chara(&kk,wynik,&s_wynikowy_temp) ;

        string obciety = "" ;
        int ii = aktualna_pozycja_wynik ;
        int jj = dlg_wyniku-aktualna_pozycja_wynik ;
        pod_string_stringa(&ii,&jj,&s_wynikowy_temp,&obciety) ;

        s_wynikowy_temp = obciety ;

        s_wynikowy = s_wynikowy_temp ;
    } else
    {

        aktualna_pozycja_wynik = 0;
        petelka_pomocnicza_str_1( &aktualna_pozycja_wynik, wynik ) ;
        //string s_wynikowy_temp(wynik) ;

        string s_wynikowy_temp="";
        int kk = 0;
        rob_stringa_z_chara(&kk,wynik,&s_wynikowy_temp) ;


        string obciety = "" ;
        int ii = aktualna_pozycja_wynik ;
        int jj = dlg_wyniku-aktualna_pozycja_wynik ;
        pod_string_stringa(&ii,&jj,&s_wynikowy_temp,&obciety) ;
        s_wynikowy_temp = obciety ;

        s_wynikowy = s_wynikowy_temp ;

    }


    return s_wynikowy ;

}



string sumuj_w_liczby_const_i_zwykle( string* s1 , const string* s2 )
{

    string s_wynikowy = "" ;
    int s1_len = s1->length() ;
    int s2_len = s2->length() ;

    int temp_int = 0;

    int aktualna_poz_s1 = s1->length() - 1 ;
    int aktualna_poz_s2 = s2->length() - 1;

    if ( s1->length() >= s2->length() )
    {
        temp_int = s1->length() ;
    } else
    {
        temp_int = s2->length() ;
    }


    const int dlg_wyniku = temp_int  + 3 ;
    char wynik[dlg_wyniku] ;
    wynik[dlg_wyniku-1] = '\0' ;
    int aktualna_pozycja_wynik = dlg_wyniku-2 ;
    char czy_przenosiny = '0' ;


    if ( (s1->at(0) != '-' ) && ( s2->at(0) != '-' ) )
    {

        // void pseudo_petla_1( int* poz_s1 , int* poz_s2, int* poz_wynik ,string* s1 , string* s2, char wynik[] , char* czy_przenosiny )
        pseudo_petla_1( &aktualna_poz_s1 , &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny) ;
    } else if ( (s1->at(0) == '-') && ( s2->at(0) == '-' ) )
    {
        pseudo_petla_1( &aktualna_poz_s1 , &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;
        wynik[0] = '-' ;

    }else if ( (s1->at(0) == '-') && ( s2->at(0) != '-' ) )
    {
        int index_poczatku_s1 = 1;
        int index_poczatku_s2 = 0;
        int len_s1 = s1->length() - 1;
        int len_s2 = s2->length();
        if ( s2->at(0) == '+' )
        {
            len_s2 -= 1 ;
            index_poczatku_s2 += 1;
        }


        if ( (len_s2 > len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) > (int)(s1->at(index_poczatku_s1)) ) ) )
        {
            pseudo_petla_2( &aktualna_poz_s2, &aktualna_poz_s1 , &aktualna_pozycja_wynik , s2, s1 , wynik , &czy_przenosiny ) ;
        } else if ( (len_s2 < len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) < (int)(s1->at(index_poczatku_s1)) ) ) )
        {
            pseudo_petla_2( &aktualna_poz_s1, &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;
            wynik[0] = '-' ;
        } else
        {


            string s2_bez_znaku;

            string obciety = "" ;
            int ii = 1 ;
            int jj = len_s1 ;
            string s1_do_f = *s1 ;
            pod_string_stringa(&ii,&jj,&s1_do_f,&obciety) ;
            string s1_bez_znaku =  obciety ;


            if ( s2->at(0)=='+' )
            {
                string obciety = "" ;
                ii = 1 ;
                jj = len_s2 ;
                string s2_do_f = *s2 ;
                pod_string_stringa(&ii,&jj,&s2_do_f,&obciety) ;
                string s2_bez_znaku =  obciety ;
            } else
            {
                string obciety = "" ;
                ii = 0 ;
                jj = len_s2 ;
                string s2_do_f = *s2 ;
                pod_string_stringa(&ii,&jj,&s2_do_f,&obciety) ;
                string s2_bez_znaku =  obciety ;
            }

            if ( s2_bez_znaku > s1_bez_znaku  )
            {
                pseudo_petla_2( &aktualna_poz_s2, &aktualna_poz_s1 , &aktualna_pozycja_wynik , s2, s1 , wynik , &czy_przenosiny ) ;
            } else if ( s2_bez_znaku <= s1_bez_znaku  )
            {
                pseudo_petla_2( &aktualna_poz_s1, &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;
                wynik[0] = '-' ;

            }



        }


    } else if ( (s1->at(0) != '-') && ( s2->at(0) == '-' ) )
    {

        int index_poczatku_s1 = 0;
        int index_poczatku_s2 = 1;
        int len_s1 = s1->length() ;
        int len_s2 = s2->length()-1;
        if ( s1->at(0) == '+' )
        {
            len_s1 -= 1 ;
            index_poczatku_s1 += 1;
        }


        if ( (len_s2 > len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) > (int)(s1->at(index_poczatku_s1)) ) ) )
        {
            pseudo_petla_2( &aktualna_poz_s2, &aktualna_poz_s1 , &aktualna_pozycja_wynik , s2, s1 , wynik , &czy_przenosiny ) ;
            wynik[0] = '-' ;
        } else if ( (len_s2 < len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) < (int)(s1->at(index_poczatku_s1)) ) ) )
        {
            pseudo_petla_2( &aktualna_poz_s1, &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;

        } else {

            string obciety = "" ;
            int ii = 1 ;
            int jj = len_s2 ;
            string s2_do_f = *s2 ;
            pod_string_stringa(&ii,&jj,&s2_do_f,&obciety) ;
            string s2_bez_znaku =  obciety ;

            string s1_bez_znaku;


            if (s1->at(0) == '+') {

                obciety = "" ;
                ii = 1 ;
                jj = len_s1 ;
                string s1_do_f = *s1 ;
                pod_string_stringa(&ii,&jj,&s1_do_f,&obciety) ;
                string s1_bez_znaku =  obciety ;

            } else {

                obciety = "" ;
                ii = 0 ;
                jj = len_s1 ;
                string s1_do_f = *s1 ;
                pod_string_stringa(&ii,&jj,&s1_do_f,&obciety) ;
                string s1_bez_znaku =  obciety ;

            }

            if (s2_bez_znaku > s1_bez_znaku) {
                pseudo_petla_2(&aktualna_poz_s2, &aktualna_poz_s1, &aktualna_pozycja_wynik, s2, s1, wynik,
                               &czy_przenosiny);
                wynik[0] = '-';
            } else if (s2_bez_znaku <= s1_bez_znaku) {
                pseudo_petla_2(&aktualna_poz_s1, &aktualna_poz_s2, &aktualna_pozycja_wynik, s1, s2, wynik,
                               &czy_przenosiny);

            }

        }


    }


    s_wynikowy = "" ;
    aktualna_pozycja_wynik = 0 ;
    string s_znaku = "";
    if ( wynik[0] == '-' )
    {
        s_znaku = "-" ;
        aktualna_pozycja_wynik += 1 ;
        petelka_pomocnicza_str_1( &aktualna_pozycja_wynik, wynik ) ;
        //string s_wynikowy_temp(wynik) ;

        string s_wynikowy_temp="";
        int kk = 0;
        rob_stringa_z_chara(&kk,wynik,&s_wynikowy_temp) ;

        string obciety = "" ;
        int ii = aktualna_pozycja_wynik ;
        int jj = dlg_wyniku - aktualna_pozycja_wynik ;
        pod_string_stringa(&ii,&jj,&s_wynikowy_temp,&obciety) ;

        s_wynikowy_temp = obciety ;

        //s_wynikowy_temp = s_wynikowy_temp.substr(aktualna_pozycja_wynik, dlg_wyniku - aktualna_pozycja_wynik ) ;
        s_wynikowy_temp = s_znaku + s_wynikowy_temp ;
        s_wynikowy = s_wynikowy_temp ;

    } else if ( wynik[0]=='+' )
    {
        aktualna_pozycja_wynik += 1;
        petelka_pomocnicza_str_1( &aktualna_pozycja_wynik, wynik ) ;
        //string s_wynikowy_temp(wynik) ;

        string s_wynikowy_temp="";
        int kk = 0;
        rob_stringa_z_chara(&kk,wynik,&s_wynikowy_temp) ;

        string obciety = "" ;
        int ii = aktualna_pozycja_wynik ;
        int jj = dlg_wyniku-aktualna_pozycja_wynik ;
        pod_string_stringa(&ii,&jj,&s_wynikowy_temp,&obciety) ;

        s_wynikowy_temp = obciety ;

        //s_wynikowy_temp = s_wynikowy_temp.substr(aktualna_pozycja_wynik,dlg_wyniku-aktualna_pozycja_wynik) ;
        s_wynikowy = s_wynikowy_temp ;
    } else
    {

        aktualna_pozycja_wynik = 0;
        petelka_pomocnicza_str_1( &aktualna_pozycja_wynik, wynik ) ;
        //string s_wynikowy_temp(wynik) ;

        string s_wynikowy_temp="";
        int kk = 0;
        rob_stringa_z_chara(&kk,wynik,&s_wynikowy_temp) ;


        string obciety = "" ;
        int ii = aktualna_pozycja_wynik ;
        int jj = dlg_wyniku-aktualna_pozycja_wynik ;
        pod_string_stringa(&ii,&jj,&s_wynikowy_temp,&obciety) ;
        s_wynikowy_temp = obciety ;

        //s_wynikowy_temp = s_wynikowy_temp.substr(aktualna_pozycja_wynik,dlg_wyniku-aktualna_pozycja_wynik) ;
        s_wynikowy = s_wynikowy_temp ;

    }


    return s_wynikowy ;

}



string sumuj_w_liczby_zwykle_i_zwykle( string* s1 ,  string* s2 )
{


    ewentualne_poprawienie_stringa(s1) ;
    ewentualne_poprawienie_stringa(s2) ;



    int cz_juz_dobry_wynik = 0 ;


    string s_wynikowy = "" ;
    int s1_len = s1->length() ;
    int s2_len = s2->length() ;

    int temp_int = 0;

    int aktualna_poz_s1 = s1->length() - 1 ;
    int aktualna_poz_s2 = s2->length() - 1;

    if ( s1->length() >= s2->length() )
    {
        temp_int = s1->length() ;
    } else
    {
        temp_int = s2->length() ;
    }


    const int dlg_wyniku = temp_int  + 3 ;
    char wynik[dlg_wyniku] ;
    wynik[dlg_wyniku-1] = '\0' ;
    int aktualna_pozycja_wynik = dlg_wyniku-2 ;
    char czy_przenosiny = '0' ;


    if ( (s1->at(0) != '-' ) && ( s2->at(0) != '-' ) )
    {


        if ( (s1->length() == s2->length()) && (s1->length() == 1 ) )
        {
            s_wynikowy = dodaj_2_cyfry(*s1,*s2) ;
            cz_juz_dobry_wynik = 1;

        } else
        {
            pseudo_petla_1( &aktualna_poz_s1 , &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny) ;
        }

    } else if ( (s1->at(0) == '-') && ( s2->at(0) == '-' ) )
    {

        if ( (s1->length() == 2) & (s2->length() == 2 ) )
        {
            s_wynikowy = dodaj_2_cyfry(*s1,*s2) ;
            cz_juz_dobry_wynik = 1;
        } else
        {
            pseudo_petla_1( &aktualna_poz_s1 , &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;
            wynik[0] = '-' ;

        }


    }else if ( (s1->at(0) == '-') && ( s2->at(0) != '-' ) )
    {


        if ( (s1->length() == 2) & (s2->length() == 1 ) )
        {
            s_wynikowy = dodaj_2_cyfry(*s1,*s2) ;
            cz_juz_dobry_wynik = 1;
        } else
        {



            int index_poczatku_s1 = 1;
            int index_poczatku_s2 = 0;
            int len_s1 = s1->length() - 1;
            int len_s2 = s2->length();
            if ( s2->at(0) == '+' )
            {
                len_s2 -= 1 ;
                index_poczatku_s2 += 1;
            }


            if ( (len_s2 > len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) > (int)(s1->at(index_poczatku_s1)) ) ) )
            {
                pseudo_petla_2( &aktualna_poz_s2, &aktualna_poz_s1 , &aktualna_pozycja_wynik , s2, s1 , wynik , &czy_przenosiny ) ;
            } else if ( (len_s2 < len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) < (int)(s1->at(index_poczatku_s1)) ) ) )
            {
                pseudo_petla_2( &aktualna_poz_s1, &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;
                wynik[0] = '-' ;
            } else
            {


                string s2_bez_znaku;

                string obciety = "" ;
                int ii = 1 ;
                int jj = len_s1 ;
                string s1_do_f = *s1 ;
                pod_string_stringa(&ii,&jj,&s1_do_f,&obciety) ;
                string s1_bez_znaku =  obciety ;


                if ( s2->at(0)=='+' )
                {
                    string obciety = "" ;
                    ii = 1 ;
                    jj = len_s2 ;
                    string s2_do_f = *s2 ;
                    pod_string_stringa(&ii,&jj,&s2_do_f,&obciety) ;
                    string s2_bez_znaku =  obciety ;
                } else
                {
                    string obciety = "" ;
                    ii = 0 ;
                    jj = len_s2 ;
                    string s2_do_f = *s2 ;
                    pod_string_stringa(&ii,&jj,&s2_do_f,&obciety) ;
                    string s2_bez_znaku =  obciety ;
                }

                if ( s2_bez_znaku > s1_bez_znaku  )
                {
                    pseudo_petla_2( &aktualna_poz_s2, &aktualna_poz_s1 , &aktualna_pozycja_wynik , s2, s1 , wynik , &czy_przenosiny ) ;
                } else if ( s2_bez_znaku <= s1_bez_znaku  )
                {
                    pseudo_petla_2( &aktualna_poz_s1, &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;
                    wynik[0] = '-' ;

                }


            }

        }



    } else if ( (s1->at(0) != '-') && ( s2->at(0) == '-' ) )
    {


        if ( (s1->length() == 1) & (s2->length() == 2 ) )
        {
            s_wynikowy = dodaj_2_cyfry(*s1,*s2) ;
            cz_juz_dobry_wynik = 1;
        } else {


            int index_poczatku_s1 = 0;
            int index_poczatku_s2 = 1;
            int len_s1 = s1->length() ;
            int len_s2 = s2->length()-1;
            if ( s1->at(0) == '+' )
            {
                len_s1 -= 1 ;
                index_poczatku_s1 += 1;
            }


            if ( (len_s2 > len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) > (int)(s1->at(index_poczatku_s1)) ) ) )
            {
                pseudo_petla_2( &aktualna_poz_s2, &aktualna_poz_s1 , &aktualna_pozycja_wynik , s2, s1 , wynik , &czy_przenosiny ) ;
                wynik[0] = '-' ;
            } else if ( (len_s2 < len_s1) || ( (len_s1 == len_s2) && ( (int)(s2->at(index_poczatku_s2)) < (int)(s1->at(index_poczatku_s1)) ) ) )
            {
                pseudo_petla_2( &aktualna_poz_s1, &aktualna_poz_s2 , &aktualna_pozycja_wynik , s1, s2 , wynik , &czy_przenosiny ) ;

            } else {

                string obciety = "" ;
                int ii = 1 ;
                int jj = len_s2 ;
                string s2_do_f = *s2 ;
                pod_string_stringa(&ii,&jj,&s2_do_f,&obciety) ;
                string s2_bez_znaku =  obciety ;

                string s1_bez_znaku;

                if (s1->at(0) == '+') {
                    obciety = "" ;
                    ii = 1 ;
                    jj = len_s1 ;
                    string s1_do_f = *s1 ;
                    pod_string_stringa(&ii,&jj,&s1_do_f,&obciety) ;
                    string s1_bez_znaku =  obciety ;
                } else {
                    obciety = "" ;
                    ii = 0 ;
                    jj = len_s1 ;
                    string s1_do_f = *s1 ;
                    pod_string_stringa(&ii,&jj,&s1_do_f,&obciety) ;
                    string s1_bez_znaku =  obciety ;
                }

                if (s2_bez_znaku > s1_bez_znaku) {
                    pseudo_petla_2(&aktualna_poz_s2, &aktualna_poz_s1, &aktualna_pozycja_wynik, s2, s1, wynik,
                                   &czy_przenosiny);
                    wynik[0] = '-';
                } else if (s2_bez_znaku <= s1_bez_znaku) {
                    pseudo_petla_2(&aktualna_poz_s1, &aktualna_poz_s2, &aktualna_pozycja_wynik, s1, s2, wynik,
                                   &czy_przenosiny);

                }

            }



        }


    }



    if ( cz_juz_dobry_wynik != 1 )
    {
        s_wynikowy = "" ;
    }


    aktualna_pozycja_wynik = 0 ;
    string s_znaku = "";



    if ( cz_juz_dobry_wynik != 1  )
    {


        if ( wynik[0] == '-' )
        {
            s_znaku = "-" ;
            aktualna_pozycja_wynik += 1 ;
            petelka_pomocnicza_str_1( &aktualna_pozycja_wynik, wynik ) ;
            //string s_wynikowy_temp(wynik) ;

            string s_wynikowy_temp="";
            int kk = 0;
            rob_stringa_z_chara(&kk,wynik,&s_wynikowy_temp) ;

            string obciety = "" ;
            int ii = aktualna_pozycja_wynik ;
            int jj = dlg_wyniku - aktualna_pozycja_wynik ;
            pod_string_stringa(&ii,&jj,&s_wynikowy_temp,&obciety) ;

            s_wynikowy_temp = obciety ;


            //s_wynikowy_temp = s_wynikowy_temp.substr(aktualna_pozycja_wynik, dlg_wyniku - aktualna_pozycja_wynik ) ;
            s_wynikowy_temp = s_znaku + s_wynikowy_temp ;
            s_wynikowy = s_wynikowy_temp ;

        } else if ( wynik[0]=='+' )
        {
            aktualna_pozycja_wynik += 1;
            petelka_pomocnicza_str_1( &aktualna_pozycja_wynik, wynik ) ;
            //string s_wynikowy_temp(wynik) ;


            string s_wynikowy_temp="";
            int kk = 0;
            rob_stringa_z_chara(&kk,wynik,&s_wynikowy_temp) ;

            string obciety = "" ;
            int ii = aktualna_pozycja_wynik ;
            int jj = dlg_wyniku-aktualna_pozycja_wynik ;
            pod_string_stringa(&ii,&jj,&s_wynikowy_temp,&obciety) ;

            s_wynikowy_temp = obciety ;

            //s_wynikowy_temp = s_wynikowy_temp.substr(aktualna_pozycja_wynik,dlg_wyniku-aktualna_pozycja_wynik) ;
            s_wynikowy = s_wynikowy_temp ;
        } else
        {

            aktualna_pozycja_wynik = 0;
            petelka_pomocnicza_str_1( &aktualna_pozycja_wynik, wynik ) ;
            //string s_wynikowy_temp(wynik) ;

            string s_wynikowy_temp="";
            int kk = 0;
            rob_stringa_z_chara(&kk,wynik,&s_wynikowy_temp) ;


            string obciety = "" ;
            int ii = aktualna_pozycja_wynik ;


            int jj = dlg_wyniku-aktualna_pozycja_wynik ;

            pod_string_stringa(&ii,&jj,&s_wynikowy_temp,&obciety) ;
            s_wynikowy_temp = obciety ;

            //s_wynikowy_temp = s_wynikowy_temp.substr(aktualna_pozycja_wynik,dlg_wyniku-aktualna_pozycja_wynik) ;
            s_wynikowy = s_wynikowy_temp ;


        }



    }


    if ( s_wynikowy.length() == 1 )
    {


        if ( (s_wynikowy.at(0) == '+') || (s_wynikowy.at(0) == '-'))
        {
            s_wynikowy = "0" ;
        }

    } else
    {
        if ( s_wynikowy.length() == 0 )
        {
            s_wynikowy = "0" ;
        }
    }


    return s_wynikowy ;

}

void petelka_po_tab_str(int integer_ile_w_tab , int* tablica_count, string* temp_strr, const string* string_array  )
{
    if ( *tablica_count < integer_ile_w_tab )
    {
        *temp_strr =  sumuj_w_liczby_const_i_zwykle(temp_strr, ( string_array + (*tablica_count))  ) ;
        *tablica_count = *tablica_count + 1 ;
        petelka_po_tab_str(integer_ile_w_tab,tablica_count,temp_strr,string_array) ;
    }
}

void petelka_po_tab_str_tylko_zwykly_string(int integer_ile_w_tab , int* tablica_count, string* temp_strr,  string* string_array  )
{
    if ( *tablica_count < integer_ile_w_tab )
    {


        string obciety = "" ;
        int ii = 0 ;
        int jj = (string_array + (*tablica_count)) ->length() ;
        string s_do_f = *( string_array + (*tablica_count))  ;
        pod_string_stringa(&ii,&jj,&s_do_f,&obciety) ;

        string temp_str_next_element = obciety ;


        //string temp_str_next_element =  ( string_array + (*tablica_count))->substr(0,( string_array + (*tablica_count)) ->length()  ) ;
        *temp_strr =  sumuj_w_liczby_zwykle_i_zwykle(temp_strr, &temp_str_next_element) ;

        *tablica_count = *tablica_count + 1 ;
        petelka_po_tab_str_tylko_zwykly_string(integer_ile_w_tab,tablica_count,temp_strr,string_array) ;
    }
}

void petelka_po_tab_str_tylko_zwykly_string_const(int integer_ile_w_tab , int* tablica_count, string* temp_strr,  const string* string_array  )
{
    if ( *tablica_count < integer_ile_w_tab )
    {




        string obciety = "" ;
        int ii = 0 ;
        int jj = (string_array + (*tablica_count)) ->length() ;
        string s_do_f = *( string_array + (*tablica_count))  ;
        pod_string_stringa(&ii,&jj,&s_do_f,&obciety) ;

        string temp_str_next_element = obciety ;


        //string temp_str_next_element =  ( string_array + (*tablica_count))->substr(0,( string_array + (*tablica_count)) ->length()  ) ;
        *temp_strr =  sumuj_w_liczby_zwykle_i_zwykle(temp_strr, &temp_str_next_element) ;

        *tablica_count = *tablica_count + 1 ;
        petelka_po_tab_str_tylko_zwykly_string_const(integer_ile_w_tab,tablica_count,temp_strr,string_array) ;
    }
}


void petelka_po_tab_str_do_va_list(int integer_ile_w_tab , int* tablica_count, string* temp_strr,  string* string_array  )
{
    if ( *tablica_count < integer_ile_w_tab )
    {



        *temp_strr =  sumuj_w_liczby_zwykle_i_zwykle(temp_strr,  string_array + (*tablica_count))   ;
        *tablica_count = *tablica_count + 1 ;
        petelka_po_tab_str_do_va_list(integer_ile_w_tab,tablica_count,temp_strr,string_array) ;
    }
}


string Sum_pomocniczy(int integer, string* string_arr)
{
    string wyjscie = "" ;
    string temp_string="" ;


    int i = 0 ;
    int tab_count = 0 ;
    temp_string = "0" ;


    //void petelka_po_tab_str(int integer_ile_w_tab , int* tablica_count, string* temp_strr, const string* string arr  )
    petelka_po_tab_str_tylko_zwykly_string( integer , &tab_count, &temp_string , string_arr ) ;


    return temp_string ;
}



string Sum(int integer, const string* string_arr)
{
    string wyjscie = "" ;
    string temp_string="" ;


    int i = 0 ;
    int tab_count = 0 ;
    temp_string = "0" ;



    //void petelka_po_tab_str(int integer_ile_w_tab , int* tablica_count, string* temp_strr, const string* string arr  )
    petelka_po_tab_str_tylko_zwykly_string_const( integer , &tab_count, &temp_string , string_arr ) ;


    return temp_string ;
}

string Suma_pomocnicza_do_va_list(int integer, string* string_arr)
{
    string wyjscie = "" ;
    string temp_string = "";
    string* temp_string_add = &temp_string ;
    const string konst_s("0")  ;

    int i = 0 ;
    int tab_count = 1 ;
    temp_string = *(string_arr+0) ;

    if ( integer == 1 )
    {
        temp_string = sumuj_w_liczby_const_i_zwykle( temp_string_add, &konst_s) ;
    } else
    {
        //void petelka_po_tab_str_do_va_list(int integer_ile_w_tab , int* tablica_count, string* temp_strr, const string** string_array  )
        petelka_po_tab_str_do_va_list( integer , &tab_count, temp_string_add , string_arr ) ;

    }
    return temp_string ;
}


void petelka_po_va_list(int integer_ile_w_tab , int* tablica_count, string* temp_strr,  string* string_array, std::va_list va_lista  )
{
    if ( *tablica_count < integer_ile_w_tab )
    {

        string_array = va_arg(va_lista, string*);

        *temp_strr =  sumuj_w_liczby_const_i_zwykle(temp_strr, string_array  ) ;
        *tablica_count = *tablica_count + 1 ;
        petelka_po_va_list(integer_ile_w_tab,tablica_count,temp_strr,string_array,va_lista) ;

    }
}

void rob_array_z_va_list(int* gdzie_jestem, int len, ::va_list lista_va , string* arr_docelowe )
{

    if ( *gdzie_jestem < len )
    {

        char* char_arr_temp = va_arg(lista_va,char*);
        string temp_s = "" ;

        int i = 0 ;

        rob_stringa_z_chara(&i,char_arr_temp,&temp_s) ;
        *( arr_docelowe+ (*gdzie_jestem) ) = temp_s ;




        *gdzie_jestem = *gdzie_jestem + 1 ;

        rob_array_z_va_list(gdzie_jestem,len,lista_va,arr_docelowe) ;

    }

}

string Sum(int integer, ... )
{


    string wyjscie = "" ;
    string kolejny_str_z_va_list = "" ;


    char* temp_str_char;
    string temp_string = "" ;
    string* wsk_do_temp_arr;
    string temp_string_array;

    const int integer_konst = integer ;

    string tablica_str_va_list[integer_konst] ;
    int i_petla_v1 = 0;
    std::va_list ap ;
    va_start(ap,integer) ;


    rob_array_z_va_list(&i_petla_v1 , integer , ap , tablica_str_va_list) ;


    wyjscie = Sum_pomocniczy(integer,tablica_str_va_list) ;

    //petelka_po_va_list(integer, &count_list , &temp_string ,&temp_string_array, ap ) ;

    va_end(ap) ;


    return wyjscie ;

}


void Sum(string* string_wejscie_1 , int integer_wejscie, const string* string_wejscie_2 ) // to moze byc zle
{

    *string_wejscie_1 = "" ;
    *string_wejscie_1 = Sum(integer_wejscie,string_wejscie_2);
}




void Sum(string* string_wejscie , int integer_wejscie , ...  )
{


    string wyjscie = "" ;
    string kolejny_str_z_va_list = "" ;


    char* temp_str_char;
    string temp_string = "" ;
    string* wsk_do_temp_arr;
    string temp_string_array;


    const int integer_konst = integer_wejscie ;

    string tablica_str_va_list[integer_konst] ;
    int i_petla_v1 = 0;
    std::va_list ap ;
    va_start(ap,integer_wejscie) ;

    rob_array_z_va_list(&i_petla_v1 , integer_wejscie , ap , tablica_str_va_list) ;


    wyjscie = Sum_pomocniczy(integer_wejscie,tablica_str_va_list) ;

    //petelka_po_va_list(integer, &count_list , &temp_string ,&temp_string_array, ap ) ;


    va_end(ap) ;

    *string_wejscie = wyjscie ;


}




void Sum(string& string_wejscie_1 , int integer_wejscie, const string* string_wejscie_2 )
{
    string_wejscie_1 = "" ;
    string_wejscie_1 = Sum(integer_wejscie,string_wejscie_2);


}



void Sum(string& string_wejscie , int integer_wejscie , ... )
{

    string wyjscie = "" ;
    string kolejny_str_z_va_list = "" ;


    char* temp_str_char;
    string temp_string = "" ;
    string* wsk_do_temp_arr;
    string temp_string_array;


    const int integer_konst = integer_wejscie ;

    string tablica_str_va_list[integer_konst] ;
    int i_petla_v1 = 0;
    std::va_list ap ;
    va_start(ap,integer_wejscie) ;

    rob_array_z_va_list(&i_petla_v1 , integer_wejscie , ap , tablica_str_va_list) ;


    wyjscie = Sum_pomocniczy(integer_wejscie,tablica_str_va_list) ;

    //petelka_po_va_list(integer, &count_list , &temp_string ,&temp_string_array, ap ) ;

    va_end(ap) ;

    string_wejscie = wyjscie ;



}
