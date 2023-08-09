//Marcin Sztukowski

void Erase_pomoc(char* wejscie, int* integer, int* wsk_wejscia )
{

    int temp_piecio_bitowe_slowo = 0;
    int temp_int_lub =  1 ;

    if ( *(wejscie+(*(wsk_wejscia))) != '\0' )
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
                    if ( temp_int_lub == (  (*integer) & temp_int_lub  ) )
                    {
                        *integer = ( (*integer) ^ temp_int_lub ) ;
                    }
                    *wsk_wejscia = *wsk_wejscia + 1 ;
                    Erase_pomoc(wejscie,integer,wsk_wejscia) ;

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
                if ( temp_int_lub == (  (*integer) & temp_int_lub  ) )
                {
                    *integer = ( (*integer) ^ temp_int_lub ) ;
                }
                *wsk_wejscia = *wsk_wejscia + 1 ;
                Erase_pomoc(wejscie,integer,wsk_wejscia) ;

            }

        } else if ( *(wejscie + *wsk_wejscia) == ' ' )
        {
            *wsk_wejscia = *wsk_wejscia + 1 ;
            Erase_pomoc(wejscie,integer,wsk_wejscia) ;
        }




    }

}

void Erase(char* wejscie, int* integer) {


    int wsk_wejscia = 0;
    Erase_pomoc(wejscie,integer, &wsk_wejscia);



}

