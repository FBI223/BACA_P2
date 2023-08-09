//Marcin Sztukowski


int Cardinality_2(int integer)
{
    int wynik = 0;
    int temp_int = 1 ;
    int i = 0;


    if ( ( ( temp_int<<0 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<1 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<2 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<3 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<4 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<5 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<6 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<7 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<8 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<9 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<10 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<11 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<12 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<13 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<14 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<15 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<16 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<17 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<18 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<19 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<20 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<21 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<22 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<23 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<24 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<25 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<26 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<27 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<28 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<29 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<30 ) | integer) == integer )
    {
        wynik += 1 ;
    }
    if ( ( ( temp_int<<31 ) | integer) == integer )
    {
        wynik += 1 ;
    }


    return wynik ;
}



bool LessThen( int integer_1, int integer_2 )
{


    if ( integer_1 == integer_2 )
    {
        return false;
    } else
    {


        int licznosc_zb_1 = Cardinality_2(integer_1 );
        int licznosc_zb_2 = Cardinality_2(integer_2 );

        if ( licznosc_zb_1 < licznosc_zb_2 )
        {
            return true;
        } else if ( licznosc_zb_1 > licznosc_zb_2 )
        {
            return false;
        } else if ( licznosc_zb_1 == licznosc_zb_2 )
        {

            return ( integer_1 < integer_2 ) ;

        }



    }


    return true ;
}

bool LessEqual( int integer_1, int integer_2 )
{



    if ( integer_1 == integer_2 )
    {
        return true;
    } else
    {


        int licznosc_zb_1 = Cardinality_2(integer_1 );
        int licznosc_zb_2 = Cardinality_2(integer_2 );


        if ( licznosc_zb_1 < licznosc_zb_2 )
        {
            return true;
        } else if ( licznosc_zb_1 > licznosc_zb_2 )
        {
            return false;
        } else if ( licznosc_zb_1 == licznosc_zb_2 )
        {

            return ( integer_1 < integer_2 ) ;

        }


    }


}

bool GreatEqual( int integer_1, int integer_2 )
{


    if ( integer_1 == integer_2 )
    {
        return true;
    } else
    {

        int licznosc_zb_1 = Cardinality_2(integer_1 );
        int licznosc_zb_2 = Cardinality_2(integer_2 );


        if ( licznosc_zb_1 > licznosc_zb_2 )
        {
            return true;
        } else if ( licznosc_zb_1 < licznosc_zb_2 )
        {
            return false;
        } else if ( licznosc_zb_1 == licznosc_zb_2 )
        {

            return ( integer_1 > integer_2 ) ;

        }



    }


}

bool GreatThen( int integer_1, int integer_2 )
{


    if ( integer_1 == integer_2 )
    {
        return false;
    } else
    {

        int licznosc_zb_1 = Cardinality_2(integer_1 );
        int licznosc_zb_2 = Cardinality_2(integer_2 );

        if ( licznosc_zb_1 > licznosc_zb_2 )
        {
            return true;
        } else if ( licznosc_zb_1 < licznosc_zb_2 )
        {
            return false;
        } else if ( licznosc_zb_1 == licznosc_zb_2 )
        {

            return ( integer_1 > integer_2 ) ;

        }


    }


    return true ;
}

