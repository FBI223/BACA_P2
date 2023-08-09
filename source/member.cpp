//Marcin Sztukowski



void Emplace_pomoc_2(char* wejscie, int* integer, int* wsk_wejscia, int* czy_koniec ) {

    int temp_piecio_bitowe_slowo = 0;
    int temp_int_lub = 0;

    if ( (*(wejscie+(*(wsk_wejscia))) != '\0') && ( *czy_koniec != 1 ) )
    {

        if ( *(wejscie + *wsk_wejscia) != ' ' )
        {

            if ( *wsk_wejscia != 0 )
            {

                if ( *(wejscie + (*wsk_wejscia)-1) == ' ' )
                {

                    temp_piecio_bitowe_slowo = 0;

                    if ( *(wejscie + *wsk_wejscia )  == '1' )
                    {
                        temp_piecio_bitowe_slowo += 16 ;
                    }
                    *wsk_wejscia += 1;
                    if ( *(wejscie + *wsk_wejscia )  == '1' )
                    {
                        temp_piecio_bitowe_slowo += 8 ;
                    }
                    *wsk_wejscia += 1;
                    if ( *(wejscie + *wsk_wejscia )  == '1' )
                    {
                        temp_piecio_bitowe_slowo += 4 ;
                    }
                    *wsk_wejscia += 1;
                    if ( *(wejscie + *wsk_wejscia )  == '1' )
                    {
                        temp_piecio_bitowe_slowo += 2 ;
                    }
                    *wsk_wejscia += 1;
                    if ( *(wejscie + *wsk_wejscia )  == '1' )
                    {
                        temp_piecio_bitowe_slowo += 1 ;
                    }



                    temp_int_lub = 1;
                    temp_int_lub = temp_int_lub << temp_piecio_bitowe_slowo ;
                    *integer = ( (*integer) | temp_int_lub ) ;


                    *wsk_wejscia = *wsk_wejscia + 1 ;
                    Emplace_pomoc_2(wejscie,integer,wsk_wejscia, czy_koniec) ;

                }

            } else if ( *wsk_wejscia == 0  )
            {


                temp_piecio_bitowe_slowo = 0;

                if ( *(wejscie + *wsk_wejscia )  == '1' )
                {
                    temp_piecio_bitowe_slowo += 16 ;
                }
                *wsk_wejscia += 1;
                if ( *(wejscie + *wsk_wejscia )  == '1' )
                {
                    temp_piecio_bitowe_slowo += 8 ;
                }
                *wsk_wejscia += 1;
                if ( *(wejscie + *wsk_wejscia )  == '1' )
                {
                    temp_piecio_bitowe_slowo += 4 ;
                }
                *wsk_wejscia += 1;
                if ( *(wejscie + *wsk_wejscia )  == '1' )
                {
                    temp_piecio_bitowe_slowo += 2 ;
                }
                *wsk_wejscia += 1;
                if ( *(wejscie + *wsk_wejscia )  == '1' )
                {
                    temp_piecio_bitowe_slowo += 1 ;
                }


                temp_int_lub = 1;
                temp_int_lub = temp_int_lub << temp_piecio_bitowe_slowo ;
                *integer = ( (*integer) | temp_int_lub ) ;


                *wsk_wejscia = *wsk_wejscia + 1 ;
                Emplace_pomoc_2(wejscie,integer,wsk_wejscia, czy_koniec) ;
            }

        } else if ( *(wejscie + *wsk_wejscia) == ' ' )
        {
            *wsk_wejscia = *wsk_wejscia + 1 ;
            Emplace_pomoc_2(wejscie,integer,wsk_wejscia,czy_koniec) ;
        }




    }

}

void Emplace_2(char* wejscie, int* integer) {

    int czy_koniec = 0;
    *integer = 0;
    int wsk_wejscia = 0;

    Emplace_pomoc_2(wejscie,integer, &wsk_wejscia,&czy_koniec);



}

bool Member(char* wejscie , int integer )
{

    int int_1 = 0;
    Emplace_2(wejscie,&int_1) ;

    if ( int_1 == integer )
    {
        return true ;
    } else
    {

        if ( (int_1 | integer) == integer )
        {
            return true ;
        } else
        {
            return false;
        }

    }

}
