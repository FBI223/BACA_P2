//Marcin Sztukowski
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define A(ptr,i) *(ptr + i)
#define AA(ptr,i,j) *(*(ptr + i )+j)



int little_endian_na_big_endian_int(int x )
{
    int wyjscie = 0;

    int cz1 = x << 24 ;

    int cz2 = x << 16 ;
    cz2 = cz2 >> 24;
    cz2 = cz2 << 16 ;

    int cz3 = x << 8 ;
    cz3 = cz3 >> 24 ;
    cz3 = cz3 << 8;

    int cz4 = x >> 24 ;

    wyjscie = cz1 | cz2 | cz3 | cz4 ;

    return wyjscie ;
}



unsigned short little_endian_na_big_endian_unsigned_short(unsigned short x )
{
    unsigned short wyjscie = 0;

    unsigned short cz1 = x << 8 ;
    unsigned short cz2 = x >> 8 ;

    wyjscie = cz1 | cz2 ;

    return wyjscie ;
}


void PRT( int*** wsk_do_arr,int** array ,unsigned short** wsk_do_dlg_kolumn,unsigned short* kolumny_dlugosci, unsigned short* row )
{
    if ( *row != 0 )
    {
        printf("%d\n",*row);
        int i;
        for (i = 0 ; i < *row ; i++)
        {
            if (A(kolumny_dlugosci,i) == 0 )
            {
                printf("0\n") ;
            } else
            {
                printf("%d ", A(kolumny_dlugosci,i)) ;
                int j;
                for (j = 0 ; j <A(kolumny_dlugosci,i) ; j++ )
                {
                    if ( j != A(kolumny_dlugosci,i) - 1  )
                    {
                        printf("%d ", AA(array,i,j));
                    } else
                    {
                        printf("%d\n",AA(array,i,j)) ;
                    }
                }
            }


        }
    } else
    {
        printf("0\n") ;
    }
}


void pokaz_2d_array(int*** wsk_do_arr,int** array ,unsigned short** wsk_do_dlg_kolumn,unsigned short* kolumny_dlugosci, unsigned short* row)
{

    if ( *row != 0 )
    {
        printf("---------------------------\n") ;
        int i ;
        for ( i = 0 ; i < *row ; i++)
        {
            printf("i:%d   dlg wiersz n  a: %d        ",i, A(kolumny_dlugosci,i)) ;
            int j;
            for( j = 0 ; j < A(kolumny_dlugosci,i) ; j++)
            {
                printf("%d ", AA(array,i,j));
            }
            printf("\n") ;
        }

        printf("---------------------------\n") ;
    } else
    {
        printf("---------------------------\n") ;
        printf("-----------Pusto-------------\n") ;
        printf("---------------------------\n") ;
    }

    printf("czesc to koniec \n") ;



}


void AFR(int*** wsk_do_arr,int** array, unsigned short** wsk_do_dlgugosci_kolumn,unsigned short*kolumny_dlugosci,unsigned short* row )
{


    int w;
    scanf("%d",&w);
    *row += 1 ;

    int temp_int = 0;


    if ( *row == 1 )
    {
        array = (int**) malloc(sizeof(int*));
        kolumny_dlugosci = (unsigned short*) malloc(sizeof(unsigned short));
        A(kolumny_dlugosci,0) = w;

    } else
    {

        array = (int**)realloc(array,(*row)*(sizeof(int*)));
        //temp_wsk = A(array,*row - 1) ;
        int i ;
        for ( i = 0 ; i < *row-1 ; i++)
        {
            A(array,(*row)-1-i) = A(array,(*row)-2-i) ;
        }
        //A(array,0) = temp_wsk ;

        kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,(*row)*sizeof(unsigned short));


        for (  i = 0 ; i < *row-1 ; i++)
        {
            A(kolumny_dlugosci,(*row)-1-i) = A(kolumny_dlugosci,(*row)-2-i) ;
        }
        A(kolumny_dlugosci,0) = w;

    }


    A(array,0) = (int*) malloc(w* sizeof(int)) ;

    int i ;
    for (  i = 0 ; i < w ; i++)
    {
        scanf("%d",&temp_int) ;
        AA(array,0,i) = temp_int ;

    }

    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;



}

void AFR_oryginal(int** array, unsigned short* row ,unsigned short*kolumny_dlugosci )
{


    int* temp_wsk = NULL ;

    int w;
    scanf("%d",&w);
    *row += 1 ;

    int temp_int = 0;


    if ( *row == 1 )
    {
        array = (int**) malloc(sizeof(int*));
        kolumny_dlugosci = (unsigned short*) malloc(sizeof(unsigned short));
        A(kolumny_dlugosci,0) = w;

    } else
    {

        array = (int**)realloc(array,(*row)*(sizeof(int*)));
        //temp_wsk = A(array,*row - 1) ;
        int i ;
        for (  i = 0 ; i < *row-1 ; i++)
        {
            A(array,(*row)-1-i) = A(array,(*row)-2-i) ;
        }
        //A(array,0) = temp_wsk ;

        kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,(*row)*sizeof(unsigned short));

        for (  i = 0 ; i < *row-1 ; i++)
        {
            A(kolumny_dlugosci,(*row)-1-i) = A(kolumny_dlugosci,(*row)-2-i) ;
        }
        A(kolumny_dlugosci,0) = w;

    }

    A(array,0) = (int*) malloc(w* sizeof(int)) ;

    int i ;
    for (  i = 0 ; i < w ; i++)
    {
        scanf("%d",&temp_int) ;
        AA(array,0,i) = temp_int ;

    }




}

void ALR(int*** wsk_do_arr,int** array, unsigned short** wsk_do_dlgugosci_kolumn,unsigned short* kolumny_dlugosci,unsigned short* row)
{

    int w;
    scanf("%d",&w);
    *row += 1 ;

    int temp_int = 0;

    int* temp_wsk = NULL ;

    if ( *row == 1 )
    {
        array = (int**) malloc(sizeof(int*));
        kolumny_dlugosci = (unsigned short*) malloc(sizeof(unsigned short));
        A(kolumny_dlugosci,0) = w;

    } else
    {

        array = (int**)realloc(array,(*row)*(sizeof(int*)));
        temp_wsk = A(array,*row - 1) ;
        kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,(*row)*sizeof(unsigned short));
        A(kolumny_dlugosci,*row -1) = w;

    }

    A(array,*row - 1) = (int*) malloc(w* sizeof(int)) ;


    int i ;
    for (  i = 0 ; i < w ; i++)
    {
        scanf("%d",&temp_int) ;
        AA(array,*row - 1,i) = temp_int ;

    }


    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

}



void AFC(int*** wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    int temp_int = 0;
    int h;
    scanf("%d",&h);
    int ile_juz_wstawiles = 0 ;

    int* temp_wsk = NULL ;


    if ( h > 0 )
    {
        if ( *row < h )
        {
            int i ;
            for ( i = 0 ; i < *row ; i++ )
            {

                A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + 1 ;
                A(array,i) = (int*) realloc(A(array,i), A(kolumny_dlugosci,i)*(sizeof(int)) ) ;

                int j ;
                for ( j  = 0  ; j < A(kolumny_dlugosci,i) - 1;j++)
                {
                    AA(array,i, A(kolumny_dlugosci,i)-1-j) = AA(array,i, A(kolumny_dlugosci,i)-2-j) ;
                }

                scanf("%d",&temp_int);
                AA(array,i,0) = temp_int;

                ile_juz_wstawiles += 1;
            }


            if ( *row != 0 )
            {
                array = (int**) realloc(array,h* sizeof(int*));
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,h* sizeof(unsigned short)) ;
            } else
            {
                array = (int**) malloc(h* sizeof(int*)) ;
                kolumny_dlugosci = (unsigned short*) malloc(h* sizeof(unsigned short)) ;
            }



            for ( i = ile_juz_wstawiles ; i < h ;i++)
            {
                A(array,i) = (int*) malloc(1* sizeof(int)) ;
                scanf("%d",&temp_int);
                AA(array,i,0) = temp_int ;
                A(kolumny_dlugosci,i) = 1;
                *row += 1 ;

            }


        } else
        {

            int i ;
            for ( i = 0 ; i < h ; i++)
            {
                A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + 1 ;
                A(array,i) = (int* ) realloc(A(array,i),A(kolumny_dlugosci,i)*(sizeof(int ))) ;
                int j ;
                for ( j = 0 ; j < A(kolumny_dlugosci,i) - 1 ; j++ )
                {
                    AA(array,i,A(kolumny_dlugosci,i)-j-1) = AA(array,i,A(kolumny_dlugosci,i)-j-2) ;
                }

                scanf("%d",&temp_int);
                AA(array,i,0) = temp_int;

                ile_juz_wstawiles += 1;

            }

        }
    }




    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


}


void ALC(int*** wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    int temp_int = 0;
    int h;
    scanf("%d",&h);
    int ile_juz_wstawiles = 0 ;

    int* temp_wsk = NULL ;


    if ( h > 0  )
    {
        if ( *row < h )
        {
            int i ;
            for ( i = 0 ; i < *row ; i++ )
            {

                A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + 1 ;
                A(array,i) = (int*) realloc(A(array,i), A(kolumny_dlugosci,i)*(sizeof(int)) ) ;

                scanf("%d",&temp_int);
                AA(array,i,A(kolumny_dlugosci,i)-1) = temp_int;

                ile_juz_wstawiles += 1;
            }


            if ( *row != 0  )
            {
                array = (int**) realloc(array,h* sizeof(int*));
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,h* sizeof(unsigned short)) ;
            } else
            {
                array = (int**) malloc(h* sizeof(int*)) ;
                kolumny_dlugosci = (unsigned short*) malloc(h* sizeof(unsigned short)) ;
            }



            for ( i = ile_juz_wstawiles ; i < h ;i++)
            {
                A(array,i) = (int*) malloc(1* sizeof(int)) ;
                scanf("%d",&temp_int);
                AA(array,i,0) = temp_int ;
                A(kolumny_dlugosci,i) = 1;
                *row += 1 ;
            }


        } else
        {

            int i ;
            for ( i = 0 ; i < h ; i++)
            {
                A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + 1 ;
                A(array,i) = (int* ) realloc(A(array,i),A(kolumny_dlugosci,i)*(sizeof(int ))) ;

                scanf("%d",&temp_int);
                AA(array,i,A(kolumny_dlugosci,i)-1) = temp_int;

                ile_juz_wstawiles += 1;

            }

        }


        *wsk_do_arr = array ;
        *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

    }



}



void IBR(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{

    int temp_int = 0;
    int r;
    int w;
    scanf("%d",&r);
    scanf("%d",&w);

    int* temp_wsk = NULL ;

    int index_p = 0;
    int index_k = *row - 1;
    if ( index_k == -1 )
    {
        index_p = -1 ;
    }

    if ( (r >=index_p ) && ( r<= index_k ) && ( *row != 0) && (array != NULL) )
    {

        *row += 1;
        array = (int**) realloc(array,(*row)*(sizeof(int*))) ;
        kolumny_dlugosci = (unsigned short* ) realloc(kolumny_dlugosci,(*row)* sizeof(unsigned short)) ;
        int pozycja_nowego_wiersza = r ;

        int i ;
        for ( i = 0 ; i < (*row - r-1)  ; i++)
        {
            A(array,*row-1-i ) = A(array,*row-2-i )  ;
            A(kolumny_dlugosci,*row-1-i) = A(kolumny_dlugosci,*row-2-i) ;
        }

        A(array,r) = (int*) malloc(w* sizeof(int));
        A(kolumny_dlugosci,r) = w;

        for ( i = 0 ; i < w ; i++)
        {
            scanf("%d",&temp_int);
            AA(array,r,i) = temp_int ;
        }


    }


    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


}



void IAR(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{

    int temp_int = 0;
    int r;
    int w;
    scanf("%d",&r);
    scanf("%d",&w);

    int* temp_wsk = NULL ;

    int index_p = 0;
    int index_k = *row - 1;
    if ( index_k == -1 )
    {
        index_p = -1 ;
    }

    if ( (r >=index_p ) && ( r<= index_k ) && (*row != 0) && (array != NULL) )
    {

        *row += 1;
        array = (int**) realloc(array,(*row)*(sizeof(int*))) ;
        kolumny_dlugosci = (unsigned short* ) realloc(kolumny_dlugosci,(*row)* sizeof(unsigned short)) ;
        int pozycja_nowego_wiersza = r ;

        int i ;
        for ( i = 0 ; i < (*row - r -2 )  ; i++)
        {
            A(array,*row-1-i ) = A(array,*row-2-i )  ;
            A(kolumny_dlugosci,*row-1-i) = A(kolumny_dlugosci,*row-2-i) ;
        }

        A(array,r+1) = (int*) malloc(w* sizeof(int));
        A(kolumny_dlugosci,r+1) = w;


        for ( i = 0 ; i < w ; i++)
        {
            scanf("%d",&temp_int);
            AA(array,r+1,i) = temp_int ;
        }


    }


    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


}


// Jeżeli wiersz liczy mniej elementów niż numer
//wstawianej kolumny, elementy dodawane są na
//koniec wiersza. len(wiersz) = 8 oraz c = 8??

void IBC( int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row )
{

    int temp_int = 0;
    int c;
    int h;
    scanf("%d",&c);
    scanf("%d",&h);

    int* temp_wsk = NULL ;



    if ( h > 0 )
    {

        if (*row == 0)
        {
            array =(int**) malloc(h*sizeof(int*)) ;
            kolumny_dlugosci = (unsigned short*) malloc(h* sizeof(unsigned short)) ;

            int i ;
            for (  i = 0 ; i < h ; i++)
            {
                A(array,i) = (int*) malloc(1* sizeof(int)) ;
                A(kolumny_dlugosci,i) = 1 ;

                scanf("%d",&temp_int) ;
                AA(array,i,0) = temp_int ;
                //printf("   AA(array,i,0) : %d       temp_int : %d      dlg kolumn : %d \n ",AA(array,i,0) , temp_int , A(kolumny_dlugosci,i)  ) ;
            }

            *row = h ;

        } else
        {

            if ( h > *row )
            {
                array = (int**) realloc(array,h* sizeof(int*)) ;
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,h* sizeof(unsigned short)) ;


                int i ;
                for (  i = 0 ; i < *row ; i++ )
                {

                    A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + 1  ;
                    A(array,i) = (int*) realloc(A(array,i) , A(kolumny_dlugosci,i)*sizeof(int)) ;

                    if ( c < A(kolumny_dlugosci,i) - 1 )
                    {
                        int j ;
                        for ( j = 0 ; j < ( A(kolumny_dlugosci,i) - c -1   ) ; j++ )
                        {
                            AA(array,i,A(kolumny_dlugosci,i) - 1- i ) = AA(array,i,A(kolumny_dlugosci,i) - 2- i ) ;
                        }
                        scanf("%d",&temp_int) ;
                        AA(array,i,c) = temp_int ;
                    } else
                    {
                        scanf("%d",&temp_int) ;
                        AA(array,i, A(kolumny_dlugosci,i)-1) = temp_int ;
                    }

                }


                for (  i = *row ; i < h ; i++)
                {
                    A(array,i) = (int*) malloc(1* sizeof(int)) ;
                    A(kolumny_dlugosci,i) = 1 ;

                    scanf("%d",&temp_int) ;
                    AA(array,i,0) = temp_int ;
                }

                *row = h ;


            } else
            {


                int i ;
                for (  i = 0 ; i < h ; i++ )
                {

                    A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + 1  ;
                    A(array,i) = (int*) realloc(A(array,i) , A(kolumny_dlugosci,i)*sizeof(int)) ;



                    if ( c < A(kolumny_dlugosci,i) - 1 )
                    {

                        int j ;
                        for ( j = 0 ; j < ( A(kolumny_dlugosci,i) - c - 1  ) ; j++ )
                        {
                            AA(array,i,A(kolumny_dlugosci,i) - 1- j ) = AA(array,i,A(kolumny_dlugosci,i) - 2- j ) ;
                        }
                        scanf("%d",&temp_int) ;
                        AA(array,i,c) = temp_int ;
                    } else
                    {
                        scanf("%d",&temp_int) ;
                        AA(array,i, A(kolumny_dlugosci,i)-1) = temp_int ;
                    }

                }


            }

        }

    }





    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


}


void IAC( int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row )
{



    int temp_int = 0;
    int c;
    int h;
    scanf("%d",&c);
    scanf("%d",&h);

    int* temp_wsk = NULL ;



    if ( h > 0  )
    {


        if (*row == 0)
        {
            array =(int**) malloc(h*sizeof(int*)) ;
            kolumny_dlugosci = (unsigned short*) malloc(h* sizeof(unsigned short)) ;

            int i ;
            for (  i = 0 ; i < h ; i++)
            {
                A(array,i) = (int*) malloc(1* sizeof(int)) ;
                A(kolumny_dlugosci,i) = 1 ;

                scanf("%d",&temp_int) ;
                AA(array,i,0) = temp_int ;
            }

            *row = h ;


        } else
        {

            if ( h > *row )
            {
                array = (int**) realloc(array,h* sizeof(int*)) ;
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,h* sizeof(unsigned short)) ;


                int i ;
                for (  i = 0 ; i < *row ; i++ )
                {

                    A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + 1  ;
                    A(array,i) = (int*) realloc(A(array,i) , A(kolumny_dlugosci,i)*sizeof(int)) ;

                    if ( c < A(kolumny_dlugosci,i) - 1 )
                    {
                        int j ;
                        for ( j = 0 ; j < ( A(kolumny_dlugosci,i) - c - 2 ) ; j++ )
                        {

                            AA(array,i,A(kolumny_dlugosci,i) - 1- j ) = AA(array,i,A(kolumny_dlugosci,i) - 2- j ) ;
                        }
                        scanf("%d",&temp_int) ;
                        AA(array,i,c+1) = temp_int ;
                    } else
                    {
                        scanf("%d",&temp_int) ;
                        AA(array,i, A(kolumny_dlugosci,i)-1) = temp_int ;
                    }

                }

                for (  i = *row ; i < h ; i++)
                {
                    A(array,i) = (int*) malloc(1* sizeof(int)) ;
                    A(kolumny_dlugosci,i) = 1 ;

                    scanf("%d",&temp_int) ;
                    AA(array,i,0) = temp_int ;
                }

                *row = h ;


            } else
            {


                int i ;
                for (  i = 0 ; i < h ; i++ )
                {

                    A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + 1  ;
                    A(array,i) = (int*) realloc(A(array,i) , A(kolumny_dlugosci,i)*sizeof(int)) ;

                    if ( c < A(kolumny_dlugosci,i) - 1 )
                    {
                        int j ;
                        for ( j = 0 ; j < ( A(kolumny_dlugosci,i) - c - 2  ) ; j++ )
                        {

                            AA(array,i,A(kolumny_dlugosci,i) - 1- j ) = AA(array,i,A(kolumny_dlugosci,i) - 2- j ) ;
                        }
                        scanf("%d",&temp_int) ;
                        AA(array,i,c+1) = temp_int ;
                    } else
                    {
                        scanf("%d",&temp_int) ;
                        AA(array,i, A(kolumny_dlugosci,i)-1) = temp_int ;
                    }

                }


            }

        }


    }



    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;



}


void SWR(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{

    int temp_int = 0;
    int r;
    int s;
    scanf("%d",&r);
    scanf("%d",&s);


    if ( (r >= *row) || ( s >= *row ) || ( r < 0 ) || ( s < 0 ) )
    {

        r =  -1;
        s = -1;
    }

    if ( (r != -1) && ( s != -1 ) )
    {


        int* temp_wsk_do_arr = NULL;
        int temp_kolumny_dlg = 0;

        temp_wsk_do_arr = A(array,r) ;
        A(array,r) = A(array,s) ;
        A(array,s) = temp_wsk_do_arr ;

        temp_kolumny_dlg = A(kolumny_dlugosci,r) ;
        A(kolumny_dlugosci,r) = A(kolumny_dlugosci,s) ;
        A(kolumny_dlugosci,s) = temp_kolumny_dlg ;



    }


    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;





}


void SWC(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    if ( *row > 0  )
    {


        int temp_int = 0;
        int c;
        int d;
        scanf("%d",&c);
        scanf("%d",&d);

        int czy_wykonywac_zamiane = 1 ;


        int i ;

        if ( *row  > 0  )
        {

            for (  i = 0 ; i < *row ; i++)
            {
                if ( ( c >= A(kolumny_dlugosci,i) ) || ( d >= A(kolumny_dlugosci,i) ) || ( c < 0  ) || ( d < 0 )  || ( c == d ) )
                {
                    czy_wykonywac_zamiane = 0;

                } else
                {
                    czy_wykonywac_zamiane = 1;
                }

                if ( czy_wykonywac_zamiane == 1 )
                {

                    temp_int = AA(array,i,c) ;
                    AA(array,i,c) = AA(array,i,d) ;
                    AA(array,i,d) = temp_int ;

                }

            }

        }


    }


    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


}


void DFR(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    if ( *row > 1 )
    {
        free(A(array,0));
        A(kolumny_dlugosci,0) = 0;

        int i ;
        for ( i  = 0 ; i < *row - 1 ; i++ )
        {
            A(array,i) = A(array,i+1);
            A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i+1) ;
        }
        *row -= 1 ;
        array = (int**) realloc(array,(*row)*(sizeof(int*)) ) ;
        kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,(*row)*(sizeof(unsigned short)) ) ;

    } else if ( *row == 1  )
    {
        free(A(array,0));
        A(kolumny_dlugosci,0) = 0;
        free(kolumny_dlugosci) ;
        free(array) ;
        *row = 0 ;
    }


    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


}

void DLR(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    if ( *row > 1 )
    {
        free(A(array, *row - 1 ));
        A(kolumny_dlugosci, *row - 1 ) = 0;

        *row -= 1 ;
        array = (int**) realloc(array,(*row)*(sizeof(int*)) ) ;
        kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,(*row)*(sizeof(unsigned short)) ) ;

    } else if ( *row == 1  )
    {
        free(A(array,0));
        A(kolumny_dlugosci,0) = 0;
        free(kolumny_dlugosci) ;
        free(array) ;
        *row = 0 ;
    }


    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


}


void DFC(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    int temp_int = 0;
    int ile_wierszy = *row ;

    if ( *row > 0  )
    {
        int** temp_arr_wsk = NULL;

        int i ;
        for ( i = 0 ; i < ile_wierszy ; i++ )
        {
            if (A(kolumny_dlugosci,i) == 1 )
            {
                free(A(array,i)) ;
                A(kolumny_dlugosci,i) = 0;
                ile_wierszy -= 1;

                int k ;
                for ( k = i ; k < ile_wierszy ; k++ )
                {
                    A(array,k) = A(array,k+1) ;
                    A(kolumny_dlugosci,k) = A(kolumny_dlugosci,k+1) ;
                }
                i-=1 ;

            } else
            {

                int j ;
                for (  j = 0 ; j < A(kolumny_dlugosci,i)-1 ; j++ )
                {
                    AA(array,i,j) =  AA(array,i,j+1) ;
                }

                A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) - 1 ;
                A(array,i) = (int*) realloc(A(array,i) ,A(kolumny_dlugosci,i)*(sizeof(int)) ) ;

            }


        }


        if ( *row != ile_wierszy )
        {
            if( ile_wierszy == 0 )
            {
                free(array) ;
                free(kolumny_dlugosci) ;
            } else
            {
                array = (int**) realloc(array,ile_wierszy*(sizeof(int*))) ;
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,ile_wierszy* sizeof(unsigned short));

            }

            *row = ile_wierszy ;

        }

    }else if ( *row == 1  )
    {

        if( ile_wierszy == 0 )
        {
            free(array) ;
            free(kolumny_dlugosci) ;

            *row = ile_wierszy ;
        }

    }



    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


}

void DLC(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    int temp_int = 0;
    int* temp_int_wsk = NULL;
    int ile_wierszy = *row ;

    if ( *row > 0  )
    {

        int i ;
        for ( i = 0 ; i < ile_wierszy ; i++ )
        {
            if (A(kolumny_dlugosci,i) == 1 )
            {
                free(A(array,i)) ;
                A(kolumny_dlugosci,i) = 0;
                ile_wierszy -= 1;

                int k ;
                for ( k = i ; k < ile_wierszy ; k++ )
                {
                    A(array,k) = A(array,k+1) ;
                    A(kolumny_dlugosci,k) = A(kolumny_dlugosci,k+1) ;
                }
                i -= 1 ;

            } else
            {

                A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) - 1 ;
                A(array,i) = (int*) realloc(A(array,i) ,A(kolumny_dlugosci,i)*(sizeof(int)) ) ;

            }


        }


        if ( *row != ile_wierszy )
        {
            if( ile_wierszy == 0 )
            {
                free(array) ;
                free(kolumny_dlugosci) ;
            } else
            {
                array = (int**) realloc(array,ile_wierszy*(sizeof(int*))) ;
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,ile_wierszy* sizeof(unsigned short));

            }

            *row = ile_wierszy ;

        }

    }else if ( *row == 1  )
    {

        if( ile_wierszy == 0 )
        {
            free(array) ;
            free(kolumny_dlugosci) ;

            *row = ile_wierszy ;
        }

    }



    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


}

void RMR(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{

    int r;
    scanf("%d",&r);

    if ( (r>=*row) || ( r < 0 ) )
    {
        r = -1;
    }


    if ( r != -1 )
    {

        free(A(array,r))  ;
        A(kolumny_dlugosci,r) = 0;

        int i ;
        for ( i = 0 ; i < *row - r - 1 ; i++ )
        {
            A(array,r+i) = A(array,r+i+1) ;
            A(kolumny_dlugosci,r+i) = A(kolumny_dlugosci,r+i+1 ) ;
        }
        *row -= 1 ;

        if ( *row == 0 )
        {
            free(array) ;
            free( kolumny_dlugosci ) ;
        } else
        {

            array = (int**) realloc(array, (*row)*sizeof(int*)) ;
            kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci, (*row)* sizeof(unsigned short) ) ;
        }


    }


    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

}

void RMC(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    int c;
    scanf("%d",&c) ;

    int temp_int = 0;
    int ile_wierszy = *row ;

    if ( *row > 0  )
    {
        int** temp_arr_wsk = NULL;

        int i ;
        for ( i = 0 ; i < ile_wierszy ; i++ )
        {
            if (A(kolumny_dlugosci,i) == 1 )
            {

                if ( c == 0 )
                {
                    free(A(array,i)) ;
                    A(kolumny_dlugosci,i) = 0;
                    ile_wierszy -= 1;

                    int k ;
                    for ( k = i ; k < ile_wierszy ; k++ )
                    {
                        A(array,k) = A(array,k+1) ;
                        A(kolumny_dlugosci,k) = A(kolumny_dlugosci,k+1) ;
                    }
                    i-=1 ;
                }


            } else
            {



                if ( c < A(kolumny_dlugosci,i) )
                {


                    int j ;
                    for (  j = c ; j < A(kolumny_dlugosci,i) -1 ; j++ )
                    {

                        AA(array,i,j) =  AA(array,i,j+1) ;
                    }

                    A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) - 1 ;
                    A(array,i) = (int*) realloc(A(array,i) ,A(kolumny_dlugosci,i)*(sizeof(int)) ) ;


                }


            }


        }


        if ( *row != ile_wierszy )
        {
            if( ile_wierszy == 0 )
            {
                free(array) ;
                free(kolumny_dlugosci) ;
            } else
            {
                array = (int**) realloc(array,ile_wierszy*(sizeof(int*))) ;
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,ile_wierszy* sizeof(unsigned short));

            }

            *row = ile_wierszy ;

        }

    }



    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

}




void RMB_2( int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row )
{


    int r;
    int h;
    int c;
    int w;

    scanf("%d",&r) ;
    scanf("%d",&h) ;
    scanf("%d",&c) ;
    scanf("%d",&w) ;


    int temp_poczatek_kolumn = c ;
    int temp_dlg_kolumn_usuwanych = w ;
    int ile_wierszy = *row ;



    if ( (h != 0) && (w != 0) )
    {

        if ( (r >= *row) || (r < 0 ) )
        {
            r = -1 ;
        }

        if ( r != -1 )
        {

            if ( r+h > *row )
            {
                h = *row - r;
            }

            temp_poczatek_kolumn = c ;
            temp_dlg_kolumn_usuwanych = w ;


            int i ;
            for (  i = r ; i < r + h ; i++ )
            {

                temp_poczatek_kolumn = c ;
                w = temp_dlg_kolumn_usuwanych;

                if ( ( temp_poczatek_kolumn < 0   ) || (temp_poczatek_kolumn >= A(kolumny_dlugosci,i) ) )
                {
                    temp_poczatek_kolumn = -1;
                }

                if ( temp_poczatek_kolumn != -1 )
                {

                    if ( temp_poczatek_kolumn + w > A(kolumny_dlugosci,i) )
                    {
                        w = A(kolumny_dlugosci,i) - temp_poczatek_kolumn ;
                    }


                    if (  w == A(kolumny_dlugosci,i) )
                    {

                        A(kolumny_dlugosci,i) = 0;
                        free(A(array,i)) ;


                        int k ;
                        for (  k = i ; k < ile_wierszy - 1 ; k++ )
                        {
                            A(array,k) = A(array,k+1) ;
                            A(kolumny_dlugosci,k) = A(kolumny_dlugosci,k+1) ;
                        }
                        ile_wierszy -= 1;
                        i-=1;
                        h-=1;


                    } else
                    {

                        int j ;
                        for ( j = 0 ; j < A(kolumny_dlugosci,i) - ( c+w ) ; j++ )
                        {

                            AA(array,i,c+j) = AA(array,i,c+j+w) ;


//                            if ( j+w <  A(kolumny_dlugosci,i) )
//                            {
//                                printf("j+w : %d     w: %d       j: %d       temp poczatek kolummt : %d     AA(array,i,j) : %d       AA(array,i,j+w) : %d  \n",j+w,w,j  , temp_poczatek_kolumn , AA(array,i,j) ,AA(array,i,j+w) ) ;
//                                AA(array,i,j) = AA(array,i,j+w) ;
//                            } else
//                            {
//                                j = temp_poczatek_kolumn + w ;
//                            }

                        }

                        A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) - w ;
                        A(array,i) = (int*) realloc(A(array,i), A(kolumny_dlugosci,i) * (sizeof(int)) ) ;

                    }



                }

            }




            if ( *row != ile_wierszy )
            {

                if ( ile_wierszy == 0 )
                {
                    free(kolumny_dlugosci) ;
                    free(array) ;
                    *row = ile_wierszy ;
                } else
                {
                    array = (int**) realloc(array,ile_wierszy* sizeof(int*) ) ;
                    kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,ile_wierszy* sizeof(unsigned short*)) ;
                    *row = ile_wierszy ;

                }

            }



        }

    }




    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;




}


void RMB( int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row )
{


    int r;
    int h;
    int c;
    int w;

    scanf("%d",&r) ;
    scanf("%d",&h) ;
    scanf("%d",&c) ;
    scanf("%d",&w) ;


    int temp_poczatek_kolumn = c ;
    int temp_dlg_kolumn_usuwanych = w ;
    int ile_wierszy = *row ;



    if ( (h != 0) && (w != 0) )
    {

        if ( (r >= *row) || (r < 0 ) )
        {
            r = -1 ;
        }

        if ( r != -1 )
        {

            if ( r+h > *row )
            {
                h = *row - r;
            }

            temp_poczatek_kolumn = c ;
            temp_dlg_kolumn_usuwanych = w ;


            int i ;
            for (  i = r ; i < r + h ; i++ )
            {

                temp_poczatek_kolumn = c ;
                w = temp_dlg_kolumn_usuwanych;

                if ( ( temp_poczatek_kolumn < 0   ) || (temp_poczatek_kolumn >= A(kolumny_dlugosci,i) ) )
                {
                    temp_poczatek_kolumn = -1;
                }

                if ( temp_poczatek_kolumn != -1 )
                {

                    if ( temp_poczatek_kolumn + w > A(kolumny_dlugosci,i) )
                    {
                        w = A(kolumny_dlugosci,i) - temp_poczatek_kolumn ;
                    }


                    if (  w == A(kolumny_dlugosci,i) )
                    {

                        A(kolumny_dlugosci,i) = 0;
                        free(A(array,i)) ;


                        int k ;
                        for (  k = i ; k < ile_wierszy - 1 ; k++ )
                        {
                            A(array,k) = A(array,k+1) ;
                            A(kolumny_dlugosci,k) = A(kolumny_dlugosci,k+1) ;
                        }
                        ile_wierszy -= 1;
                        i-=1;
                        h-=1;


                    } else
                    {


                        int j ;
                        for ( j = temp_poczatek_kolumn ; j < temp_poczatek_kolumn + w ; j++ )
                        {

                            if ( j+w <  A(kolumny_dlugosci,i) )
                            {
                                //printf("j+w : %d     w: %d       j: %d       temp poczatek kolummt : %d     AA(array,i,j) : %d       AA(array,i,j+w) : %d  \n",j+w,w,j  , temp_poczatek_kolumn , AA(array,i,j) ,AA(array,i,j+w) ) ;
                                AA(array,i,j) = AA(array,i,j+w) ;
                            } else
                            {
                                j = temp_poczatek_kolumn + w ;
                            }

                        }

                        A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) - w ;
                        A(array,i) = (int*) realloc(A(array,i), A(kolumny_dlugosci,i) * (sizeof(int)) ) ;

                    }



                }

            }




            if ( *row != ile_wierszy )
            {

                if ( ile_wierszy == 0 )
                {
                    free(kolumny_dlugosci) ;
                    free(array) ;
                    *row = ile_wierszy ;
                } else
                {
                    array = (int**) realloc(array,ile_wierszy* sizeof(int*) ) ;
                    kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci,ile_wierszy* sizeof(unsigned short*)) ;
                    *row = ile_wierszy ;

                }

            }



        }

    }




    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

}

void ISB(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    int r;
    int h;
    int c;
    int w;

    int x = 1 ;


    scanf("%d",&r) ;
    scanf("%d",&c) ;
    scanf("%d",&h) ;
    scanf("%d",&w) ;

    int temp_poczatek_kolumn = c ;
    int temp_dlg_kolumn_usuwanych = w ;
    int ile_wierszy = *row ;
    int temp_int = 0;
    int ile_wierszy_wstawiles = 0;


    if ( (h != 0 ) && ( w != 0 ) )
    {

        if ( *row == 0 )
        {
            array = (int** ) malloc( h* sizeof(int*) );
            kolumny_dlugosci = (unsigned short*) malloc(h* sizeof(unsigned short));
            *row = h ;


            int i ;
            for ( i = 0 ; i < h ; i++ )
            {
                A(array,i) = (int*) malloc(w* sizeof(int)) ;
                A(kolumny_dlugosci,i) = w;

                int j ;
                for ( j = 0 ; j < w ; j++)
                {
                    scanf("%d",&temp_int) ;
                    AA(array,i,j) = temp_int ;
                }



            }


        } else
        {

            int i ;
            for ( i = r ; (i < r+h) && ( i < *row ) ; i++ )
            {
                A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + w ;
                A(array,i) = (int*) realloc(A(array,i) , A(kolumny_dlugosci,i)*(sizeof(int)) ) ;

                int k = 0 ;

                int j ;
                for ( j = c ; j < A(kolumny_dlugosci,i) - w ; j++ )
                {
                    AA(array,i, A(kolumny_dlugosci,i) - 1 - k ) =  AA(array,i, A(kolumny_dlugosci,i) - 1 - k - w ) ;
                    k++ ;
                }


                int temp_poczatek_wstawiania_kolumn = c;
                if ( temp_poczatek_wstawiania_kolumn > A(kolumny_dlugosci,i) -w )
                {
                    temp_poczatek_wstawiania_kolumn = A(kolumny_dlugosci,i) - w ;
                }


                for (  j = 0 ; j < w ; j++ )
                {

                    scanf("%d",&temp_int) ;
                    AA(array,i,temp_poczatek_wstawiania_kolumn+j) = temp_int ;
                }

                ile_wierszy_wstawiles += 1;

            }


            *wsk_do_arr = array ;
            *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

            if ( ile_wierszy_wstawiles < h )
            {

                int ile_wierszy_zostalo_do_wstawienia = h - ile_wierszy_wstawiles ;

                *row += ile_wierszy_zostalo_do_wstawienia ;


                array = (int**) realloc(array,(*row)*sizeof(int*)) ;
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci, (*row)*sizeof(unsigned short)) ;

                int j ;
                for ( j = *row - ile_wierszy_zostalo_do_wstawienia  ; j < *row ; j++ )
                {
                    A(array,j) = (int*) malloc( w* sizeof(int)) ;
                    A(kolumny_dlugosci,j) = w ;

                    int k ;
                    for ( k = 0 ; k < w; k++ )
                    {
                        scanf("%d",&temp_int) ;
                        AA(array,j,k) = temp_int ;
                    }
                }


            }


        }

    }





    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

}




void ISB_do_IBC(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    int r;
    int h;
    int c;
    int w;

    int x = 1 ;

    r = 0;
    w = 1 ;

    scanf("%d",&c) ;
    scanf("%d",&h) ;

    int temp_poczatek_kolumn = c ;
    int temp_dlg_kolumn_usuwanych = w ;
    int ile_wierszy = *row ;
    int temp_int = 0;
    int ile_wierszy_wstawiles = 0;


    if ( (h != 0 ) && ( w != 0 ) )
    {

        if ( *row == 0 )
        {
            array = (int** ) malloc( h* sizeof(int*) );
            kolumny_dlugosci = (unsigned short*) malloc(h* sizeof(unsigned short));
            *row = h ;


            int i ;
            for ( i = 0 ; i < h ; i++ )
            {
                A(array,i) = (int*) malloc(w* sizeof(int)) ;
                A(kolumny_dlugosci,i) = w;

                int j ;
                for ( j = 0 ; j < w ; j++)
                {
                    scanf("%d",&temp_int) ;
                    AA(array,i,j) = temp_int ;
                }



            }


        } else
        {

            int i ;
            for ( i = r ; (i < r+h) && ( i < *row ) ; i++ )
            {
                A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + w ;
                A(array,i) = (int*) realloc(A(array,i) , A(kolumny_dlugosci,i)*(sizeof(int)) ) ;

                int k = 0 ;

                int j ;
                for ( j = c ; j < A(kolumny_dlugosci,i) - w ; j++ )
                {
                    AA(array,i, A(kolumny_dlugosci,i) - 1 - k ) =  AA(array,i, A(kolumny_dlugosci,i) - 1 - k - w ) ;
                    k++ ;
                }


                int temp_poczatek_wstawiania_kolumn = c;
                if ( temp_poczatek_wstawiania_kolumn > A(kolumny_dlugosci,i) -w )
                {
                    temp_poczatek_wstawiania_kolumn = A(kolumny_dlugosci,i) - w ;
                }


                for (  j = 0 ; j < w ; j++ )
                {

                    scanf("%d",&temp_int) ;
                    AA(array,i,temp_poczatek_wstawiania_kolumn+j) = temp_int ;
                }

                ile_wierszy_wstawiles += 1;

            }


            *wsk_do_arr = array ;
            *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

            if ( ile_wierszy_wstawiles < h )
            {

                int ile_wierszy_zostalo_do_wstawienia = h - ile_wierszy_wstawiles ;

                *row += ile_wierszy_zostalo_do_wstawienia ;


                array = (int**) realloc(array,(*row)*sizeof(int*)) ;
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci, (*row)*sizeof(unsigned short)) ;

                int j ;
                for ( j = *row - ile_wierszy_zostalo_do_wstawienia  ; j < *row ; j++ )
                {
                    A(array,j) = (int*) malloc( w* sizeof(int)) ;
                    A(kolumny_dlugosci,j) = w ;

                    int k ;
                    for ( k = 0 ; k < w; k++ )
                    {
                        scanf("%d",&temp_int) ;
                        AA(array,j,k) = temp_int ;
                    }
                }


            }


        }

    }





    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

}



void ISB_do_IAC(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    int r;
    int h;
    int c;
    int w;


    r = 0;
    w = 1 ;

    scanf("%d",&c) ;
    scanf("%d",&h) ;
    c += 1 ;

    int temp_poczatek_kolumn = c ;
    int temp_dlg_kolumn_usuwanych = w ;
    int ile_wierszy = *row ;
    int temp_int = 0;
    int ile_wierszy_wstawiles = 0;


    if ( (h != 0 ) && ( w != 0 ) )
    {

        if ( *row == 0 )
        {
            array = (int** ) malloc( h* sizeof(int*) );
            kolumny_dlugosci = (unsigned short*) malloc(h* sizeof(unsigned short));
            *row = h ;


            int i ;
            for ( i = 0 ; i < h ; i++ )
            {
                A(array,i) = (int*) malloc(w* sizeof(int)) ;
                A(kolumny_dlugosci,i) = w;

                int j ;
                for ( j = 0 ; j < w ; j++)
                {
                    scanf("%d",&temp_int) ;
                    AA(array,i,j) = temp_int ;
                }



            }


        } else
        {

            int i ;
            for ( i = r ; (i < r+h) && ( i < *row ) ; i++ )
            {
                A(kolumny_dlugosci,i) = A(kolumny_dlugosci,i) + w ;
                A(array,i) = (int*) realloc(A(array,i) , A(kolumny_dlugosci,i)*(sizeof(int)) ) ;

                int k = 0 ;

                int j ;
                for ( j = c ; j < A(kolumny_dlugosci,i) - w ; j++ )
                {
                    AA(array,i, A(kolumny_dlugosci,i) - 1 - k ) =  AA(array,i, A(kolumny_dlugosci,i) - 1 - k - w ) ;
                    k++ ;
                }


                int temp_poczatek_wstawiania_kolumn = c;
                if ( temp_poczatek_wstawiania_kolumn > A(kolumny_dlugosci,i) -w )
                {
                    temp_poczatek_wstawiania_kolumn = A(kolumny_dlugosci,i) - w ;
                }


                for (  j = 0 ; j < w ; j++ )
                {

                    scanf("%d",&temp_int) ;
                    AA(array,i,temp_poczatek_wstawiania_kolumn+j) = temp_int ;
                }

                ile_wierszy_wstawiles += 1;

            }


            *wsk_do_arr = array ;
            *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

            if ( ile_wierszy_wstawiles < h )
            {

                int ile_wierszy_zostalo_do_wstawienia = h - ile_wierszy_wstawiles ;

                *row += ile_wierszy_zostalo_do_wstawienia ;


                array = (int**) realloc(array,(*row)*sizeof(int*)) ;
                kolumny_dlugosci = (unsigned short*) realloc(kolumny_dlugosci, (*row)*sizeof(unsigned short)) ;

                int j ;
                for ( j = *row - ile_wierszy_zostalo_do_wstawienia  ; j < *row ; j++ )
                {
                    A(array,j) = (int*) malloc( w* sizeof(int)) ;
                    A(kolumny_dlugosci,j) = w ;

                    int k ;
                    for ( k = 0 ; k < w; k++ )
                    {
                        scanf("%d",&temp_int) ;
                        AA(array,j,k) = temp_int ;
                    }
                }


            }


        }

    }





    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

}



void WRF(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{


    char* sciezka_pliku = (char*) malloc(16 * sizeof(char)) ;

    scanf("%s",sciezka_pliku);
    FILE* file = fopen(sciezka_pliku,"wb") ;



    fprintf(file,"%hu\n",*row) ;

    int temp_int = 0;
    unsigned int temp_short = 0;

    int temp_int_endian = 0;
    unsigned short temp_short_endian = 0;

    if ( *row > 0  )
    {
        int i;
        for ( i = 0 ; i < *row ; i++)
        {
            temp_short = A(kolumny_dlugosci,i);
            temp_short_endian = little_endian_na_big_endian_unsigned_short(temp_short) ;
            fwrite(&temp_short_endian, sizeof(unsigned short), 1 , file ) ;


            int j;
            for ( j = 0 ; j < temp_short ; j++)
            {
                temp_int = AA(array,i,j);
                temp_int_endian = little_endian_na_big_endian_int(temp_int) ;
                fwrite(&temp_int_endian, sizeof(int), 1 , file ) ;

            }



        }
    }



    fclose(file) ;
    free(sciezka_pliku) ;

    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

}

void RDF(int***wsk_do_arr ,int** array ,unsigned short** wsk_do_dlgugosci_kolumn  ,unsigned short* kolumny_dlugosci, unsigned short* row)
{



    char* sciezka_pliku = (char*) malloc(16 * sizeof(char)) ;

    scanf("%s",sciezka_pliku);
    FILE* file = fopen(sciezka_pliku,"rb") ;


    if ( *row > 0 )
    {
        free(kolumny_dlugosci) ;
        int i;
        for ( i = 0 ; i < *row ; i++ )
        {
            free(A(array,i)) ;
        }
    }
    free(array) ;

    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;


    char temp_char = '\0' ;
    fscanf(file,"%hu",row) ;
    fread(&temp_char, sizeof(char),1,file) ;


    array =(int**) malloc( (*row)* sizeof(int*) ) ;
    kolumny_dlugosci =(unsigned short*) malloc( (*row)* sizeof(unsigned short) ) ;



    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;

    int temp_int = 0;
    unsigned int temp_short = 0;

    int temp_int_endian = 0;
    unsigned short temp_short_endian = 0;

    //printf("row : %d\n",*row) ;

    if ( *row > 0  )
    {
        int i ;
        for ( i = 0 ; i < *row ; i++)
        {

            //printf("flaga damn 2  \n"   ) ;

            fread(&temp_short , sizeof(unsigned short), 1 , file );
            //printf("flaga damn 3     przed konwersja : %d \n  " , temp_short   ) ;
            temp_short_endian = little_endian_na_big_endian_unsigned_short(temp_short) ;
            //printf("flaga damn 3     po konwersja : %d \n  " , temp_short_endian   ) ;
            A(array,i) = (int*) malloc(temp_short_endian * sizeof(int )) ;
            A(kolumny_dlugosci,i) = temp_short_endian ;

            //printf("   i %d    wartos po konwertowaniu    temp short endian  :%d  \n", i,temp_short_endian ) ;

            int j;
            for ( j = 0 ; j < temp_short_endian ; j++)
            {


                //printf("flaga j : %d            temp short endian : %d  \n ",j , temp_short_endian  ) ;
                fread(&temp_int, sizeof(int) , 1 , file );
                temp_int_endian = little_endian_na_big_endian_int(temp_int) ;
                AA(array,i,j)  = temp_int_endian ;
                //printf("wartos po konwertowaniu    AA(array,i,j) :%d  \n", temp_int_endian ) ;


            }
            //printf("flaga damn \n"   ) ;


        }
    }



    fclose(file) ;
    free(sciezka_pliku) ;

    *wsk_do_arr = array ;
    *wsk_do_dlgugosci_kolumn = kolumny_dlugosci ;
}




int main() {



    char* polecenie =(char*) malloc(4* sizeof(char)) ;
    *(polecenie+0) = '0' ;
    *(polecenie+1) = '0' ;
    *(polecenie+2) = '0' ;
    *(polecenie+3) = '0' ;


    int temp_int = 0;
    unsigned short row = 0;



    int** array =  NULL ;
    unsigned short* kolumny_dlugosci = NULL ;


    int*** wsk_do_arr = &array ;
    unsigned short** wsk_do_dlg_kolumn = &kolumny_dlugosci ;




    while ( (*(polecenie+0) != 'E') && (*(polecenie+1) != 'N') && (*(polecenie+2) != 'D') )
    {


        scanf("%s",polecenie) ;



        if ( (*(polecenie+0) == 'A') && (*(polecenie+1) == 'F') && (*(polecenie+2) == 'R') )
        {


            AFR(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
            //pokaz_2d_array(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;




        } else if ( ( *(polecenie+0) == 'A') && (*(polecenie+1) == 'L') && (*(polecenie+2) == 'R') )
        {
            ALR(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
            //pokaz_2d_array(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'A') && (*(polecenie+1) == 'F') && (*(polecenie+2) == 'C') )
        {

            AFC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
            //pokaz_2d_array(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'A') && (*(polecenie+1) == 'L') && (*(polecenie+2) == 'C') )
        {

            ALC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
            //pokaz_2d_array(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;



        } else if ( (*(polecenie+0) == 'I') && (*(polecenie+1) == 'B') && (*(polecenie+2) == 'R') )
        {

            IBR(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
            //pokaz_2d_array(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'I') && (*(polecenie+1) == 'A') && (*(polecenie+2) == 'R') )
        {

            IAR(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
            //pokaz_2d_array(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'I') && (*(polecenie+1) == 'B') && (*(polecenie+2) == 'C') )
        {


            ISB_do_IBC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
            //IBC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;



        } else if ( (*(polecenie+0) == 'I') && (*(polecenie+1) == 'A') && (*(polecenie+2) == 'C') )
        {

            //IAC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
            ISB_do_IAC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'S') && (*(polecenie+1) == 'W') && (*(polecenie+2) == 'R') )
        {

            SWR(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'S') && (*(polecenie+1) == 'W') && (*(polecenie+2) == 'C') )
        {

            SWC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'D') && (*(polecenie+1) == 'F') && (*(polecenie+2) == 'R') )
        {

            DFR(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'D') && (*(polecenie+1) == 'L') && (*(polecenie+2) == 'R') )
        {

            DLR(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'D') && (*(polecenie+1) == 'F') && (*(polecenie+2) == 'C') )
        {


            DFC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'D') && (*(polecenie+1) == 'L') && (*(polecenie+2) == 'C') )
        {

            DLC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;

        } else if ( (*(polecenie+0) == 'R') && (*(polecenie+1) == 'M') && (*(polecenie+2) == 'R') )
        {

            RMR(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'R') && (*(polecenie+1) == 'M') && (*(polecenie+2) == 'C') )
        {
            RMC(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;

        } else if ( (*(polecenie+0) == 'R') && (*(polecenie+1) == 'M') && (*(polecenie+2) == 'B') )
        {

            RMB_2(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;

        } else if ( (*(polecenie+0) == 'I') && (*(polecenie+1) == 'S') && (*(polecenie+2) == 'B') )
        {

            ISB(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'W') && (*(polecenie+1) == 'R') && (*(polecenie+2) == 'F') )
        {

            WRF(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'R') && (*(polecenie+1) == 'D') && (*(polecenie+2) == 'F') )
        {

            RDF(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        } else if ( (*(polecenie+0) == 'P') && (*(polecenie+1) == 'R') && (*(polecenie+2) == 'T') )
        {

            PRT(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;


        }


        //pokaz_2d_array(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
        //PRT(wsk_do_arr,array,wsk_do_dlg_kolumn,kolumny_dlugosci,&row) ;
        scanf("%c",(polecenie+3)) ;




    }



    int i;
    for ( i = 0 ; i < row ; i++)
    {
        free(A(array,i));
    }
    if ( row != 0 )
    {
        free(array) ;
    }

    if ( row != 0 )
    {
        free(kolumny_dlugosci) ;
    }
    row = 0 ;
    free(polecenie) ;


    return 0;
}
