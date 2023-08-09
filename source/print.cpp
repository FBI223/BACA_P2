//Marcin Sztukowski


void Print(int integer , char* wejscie )
{

    int wsk_char = 0;
    int temp_int = 1;

    temp_int = temp_int << 31 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }

    temp_int = 1;
    temp_int = temp_int << 30 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }

    temp_int = 1;
    temp_int = temp_int << 29 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 28 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 27 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 26 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 25 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 24 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 23 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 22 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 21 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 20 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 19 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 18 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 17 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 16 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '1' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 15 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 14 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 13 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 12 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 11 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 10 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }

    temp_int = 1;
    temp_int = temp_int << 9 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 8 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '1' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 7 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 6 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 5 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 4 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '1' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 3 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    temp_int = temp_int << 2 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '1' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }

    temp_int = 1;
    temp_int = temp_int << 1 ;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '1' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }
    temp_int = 1;
    if ( (integer | temp_int) == integer )
    {
        *(wejscie+wsk_char+0) = '0' ;
        *(wejscie+wsk_char+1) = '0' ;
        *(wejscie+wsk_char+2) = '0' ;
        *(wejscie+wsk_char+3) = '0' ;
        *(wejscie+wsk_char+4) = '0' ;
        *(wejscie+wsk_char+5) = ' ' ;
        wsk_char = wsk_char+6;

    }

    if ( wsk_char != 0 )
    {
        wsk_char = wsk_char-1;
        *(wejscie+wsk_char) = '\0' ;
    } else if ( wsk_char == 0 )
    {
        *(wejscie+wsk_char+0) = 'e' ;
        *(wejscie+wsk_char+1) = 'm' ;
        *(wejscie+wsk_char+2) = 'p' ;
        *(wejscie+wsk_char+3) = 't' ;
        *(wejscie+wsk_char+4) = 'y' ;
        *(wejscie+wsk_char+5) = '\0' ;
    }

}