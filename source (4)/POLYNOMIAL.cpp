//Marcin Sztukowski




class ULAMEK{

public:
    int liczik;
    int mianownik;




    ULAMEK( int integer_wejsciowy)
    {
        liczik = integer_wejsciowy;
        mianownik =1 ;
    }


    ULAMEK( int l , int m )
    {
        liczik=l;
        mianownik=m;
    }

    ULAMEK(  )
    {
        liczik=0;
        mianownik=1;
    }

    ULAMEK( const ULAMEK& other)
    {
        this->liczik = other.liczik;
        this->mianownik = other.mianownik;

    }

    // nwd
    int nwd(int a, int b)
    {
        if ( a==0 )
        {
            return b;
        }
        if ( b==0)
        {
            return a;
        }

        if ( a < 0 )
        {
            a = a * (-1);
        }
        if ( b < 0 )
        {
            b = b * (-1);
        }


        while (b != 0) {
            int reszta = a % b;
            a = b;
            b = reszta;
        }



        return a; // lub b - obie zmienne przechowują wynik NWD(a,b)
    }

    int nww(int a , int b )
    {

        int a_original = a;
        int b_original = b;

        if ( a==0 || b==0)
        {
            return 0;
        }


        if ( a < 0 )
        {
            a = a * (-1);
            a_original *= (-1) ;
        }
        if ( b < 0 )
        {
            b = b * (-1);
            b_original *= (-1) ;
        }
        while (b != 0) {
            int reszta = a % b;
            a = b;
            b = reszta;
        }

        int nwd_temp = a;


        return ( ( a_original*b_original ) / ( nwd_temp ) );

    }

    ULAMEK& operator = (const ULAMEK& other )
    {

        this->liczik = other.liczik;
        this->mianownik = other.mianownik;



        if (this->liczik == 0  )
        {
            this->mianownik = 1;
        } else
        {
            int temp_nwd = nwd(this->liczik , this->mianownik);
            if ( (temp_nwd > 1) && (this->liczik >=  this->mianownik) )
            {
                this->liczik = this->liczik / temp_nwd ;
                this->mianownik = this->mianownik / temp_nwd ;
            }
        }






        return *this;
    }


    void skroc_ulamek()
    {

        if (this->liczik == 0  )
        {
            this->mianownik = 1 ;
        } else
        {
            int temp_nwd = nwd(this->liczik , this->mianownik);
            if ( (temp_nwd > 1) && (this->liczik >=  this->mianownik) )
            {
                this->liczik = this->liczik / temp_nwd ;
                this->mianownik = this->mianownik / temp_nwd ;
            }
        }


    }


    ULAMEK operator + (const ULAMEK& other )
    {

        ULAMEK other_kopia(other);
        ULAMEK ulamek_out(this->liczik , this->mianownik);


        if (this->mianownik == other.mianownik )
        {
            ulamek_out.liczik += other.liczik ;

        } else
        {
            int temp_nww = nww(this->mianownik , other.mianownik ) ;
            int pomnoz_1 = temp_nww / this->mianownik ;
            int pomnoz_2 = temp_nww / other.mianownik ;

            ulamek_out.liczik *= pomnoz_1;
            ulamek_out.mianownik = temp_nww;

            other_kopia.liczik *= pomnoz_2;
            other_kopia.mianownik = temp_nww;

            ulamek_out.liczik += other_kopia.liczik ;

            if ( ulamek_out.liczik == 0 )
            {
                ulamek_out.mianownik = 1;
            }
        }

        return ulamek_out;
    }

    ULAMEK operator - (const ULAMEK& other )
    {
        ULAMEK other_kopia(other);
        ULAMEK ulamek_out(this->liczik , this->mianownik);
        if (this->mianownik == other.mianownik )
        {
            ulamek_out.liczik -= other.liczik ;
        } else
        {
            int temp_nww = nww(this->mianownik , other.mianownik ) ;

            if ( temp_nww != 0 && this->mianownik != 0 && other.mianownik != 0  )
            {
                int pomnoz_1 = temp_nww / this->mianownik ;
                int pomnoz_2 = temp_nww / other.mianownik ;

                ulamek_out.liczik *= pomnoz_1;
                ulamek_out.mianownik = temp_nww;

                other_kopia.liczik *= pomnoz_2;
                other_kopia.mianownik = temp_nww;

                ulamek_out.liczik -= other_kopia.liczik ;

                if ( ulamek_out.liczik == 0 )
                {
                    ulamek_out.mianownik = 1;
                }
            }


        }

        return ulamek_out;
    }

    ULAMEK operator * (const ULAMEK& other )
    {
        ULAMEK ulamek_out(this->liczik * other.liczik , this->mianownik * other.mianownik );
        if ( ulamek_out.liczik == 0  )
        {
            ulamek_out.mianownik = 1 ;
        } else if (ulamek_out.mianownik == 0) {
            ulamek_out.mianownik = -1;
            ulamek_out.liczik = 0;
        }else
        {
            int temp_nwd = nwd( ulamek_out.liczik , ulamek_out.mianownik );
            if ( temp_nwd > 1 )
            {
                ulamek_out.liczik = ulamek_out.liczik / temp_nwd ;
                ulamek_out.mianownik = ulamek_out.mianownik / temp_nwd ;
            }
        }


        return ulamek_out;
    }

    ULAMEK operator / (const ULAMEK& other )
    {
        ULAMEK ulamek_out(this->liczik * other.mianownik  , this->mianownik * other.liczik );
        if ( ulamek_out.liczik < 0 && ulamek_out.mianownik < 0  )
        {
            ulamek_out.liczik *= (-1) ;
            ulamek_out.mianownik *= (-1) ;
        } else if ( ulamek_out.liczik > 0 && ulamek_out.mianownik < 0 )
        {
            ulamek_out.liczik *= (-1) ;
            ulamek_out.mianownik *= (-1) ;
        }

        if ( ulamek_out.mianownik == 0 || ulamek_out.liczik == 0 )
        {
            ulamek_out.liczik =  0 ;
            ulamek_out.mianownik = -1;
        } else
        {
            int temp_nwd = nwd( ulamek_out.liczik , ulamek_out.mianownik );
            if ( temp_nwd > 1  && this->liczik >=  this->mianownik )
            {
                ulamek_out.liczik = ulamek_out.liczik / temp_nwd ;
                ulamek_out.mianownik = ulamek_out.mianownik / temp_nwd ;
            }
        }

        return ulamek_out;

    }



};


class POLYNOMIAL_ULAMKOWY{
public:


    int n_stopien_u;
    ULAMEK* arr_ulamki;



    POLYNOMIAL_ULAMKOWY()
    {
        n_stopien_u = 0 ;
        arr_ulamki = new ULAMEK[1] ;
        arr_ulamki[0].mianownik=1;
        arr_ulamki[0].liczik = 0 ;
    }


    POLYNOMIAL_ULAMKOWY(int n_stopien_in)
    {
        n_stopien_u = n_stopien_in ;
        arr_ulamki = new ULAMEK[ n_stopien_in + 1 ] ;


        for ( int i = 0 ; i < n_stopien_in+1 ; i++ )
        {
            arr_ulamki[i].liczik = 0;
            arr_ulamki[i].mianownik = 1 ;
        }

    }

    POLYNOMIAL_ULAMKOWY(int n_stopien_in, ULAMEK* ulamek_wstaw_na_stopien)
    {
        n_stopien_u = n_stopien_in ;
        arr_ulamki = new ULAMEK[ n_stopien_in + 1 ] ;


        int i = 0 ;
        for ( i = 0 ; i < n_stopien_in ; i++ )
        {
            arr_ulamki[i].liczik = 0;
            arr_ulamki[i].mianownik = 1 ;
        }

        arr_ulamki[i].liczik = ulamek_wstaw_na_stopien->liczik;
        arr_ulamki[i].mianownik = ulamek_wstaw_na_stopien->mianownik;

    }



    POLYNOMIAL_ULAMKOWY(const POLYNOMIAL_ULAMKOWY& other)
    {
        n_stopien_u =  other.n_stopien_u ;
        arr_ulamki = new ULAMEK[ n_stopien_u + 1 ] ;


        for ( int i = 0 ; i < n_stopien_u + 1 ; i++ )
        {
            arr_ulamki[i].liczik = other.arr_ulamki[i].liczik ;
            arr_ulamki[i].mianownik = other.arr_ulamki[i].mianownik ;
        }

    }


    POLYNOMIAL_ULAMKOWY( int n_stopien_in ,int* arr_z_liczbami )
    {
        this->n_stopien_u = n_stopien_in;
        arr_ulamki = new ULAMEK[ n_stopien_in + 1 ] ;

        for ( int i = 0 ; i < n_stopien_in+1 ; i++ )
        {
            arr_ulamki[i].liczik =  *(arr_z_liczbami+i) ;
            arr_ulamki[i].mianownik = 1 ;
        }

    }


    ~POLYNOMIAL_ULAMKOWY()
    {

        n_stopien_u=0;
        delete[] arr_ulamki;

    }

    void usun_zera()
    {
        int len = n_stopien_u +1;
        int j = len-1 ;
        int ile_usuniec = 0;

        while ( (j > 0) && ( arr_ulamki[j].liczik == 0 ) )
        {
            ile_usuniec++;
            j-- ;
        }
        if ( ile_usuniec == 0  )
        {
            return;
        }
        n_stopien_u -= ile_usuniec ;
        if ( n_stopien_u < 0 )
        {
            n_stopien_u=0;
        }

    }

    POLYNOMIAL_ULAMKOWY operator- ()
    {

        POLYNOMIAL_ULAMKOWY p_out(*this);
        for ( int i = 0 ; i < this->n_stopien_u + 1 ; i++  )
        {
            p_out.arr_ulamki[i].liczik *= ( -1 );
        }

        return p_out;

    }

    POLYNOMIAL_ULAMKOWY operator+(const POLYNOMIAL_ULAMKOWY& other)
    {
        if (this->n_stopien_u >= other.n_stopien_u )
        {
            POLYNOMIAL_ULAMKOWY p_out(*this);
            int len = other.n_stopien_u+1 ;
            for ( int i = 0 ; i < len ; i++)
            {
                p_out.arr_ulamki[i] = p_out.arr_ulamki[i] + other.arr_ulamki[i] ;
            }
            p_out.usun_zera();

            return p_out;

        } else
        {
            POLYNOMIAL_ULAMKOWY p_out( other );

            int len = this->n_stopien_u + 1 ;
            for ( int i = 0 ; i < len ; i++)
            {
                p_out.arr_ulamki[i] = p_out.arr_ulamki[i] + other.arr_ulamki[i] ;
            }
            p_out.usun_zera();

            return p_out;

        }

    }

    POLYNOMIAL_ULAMKOWY& operator=(const POLYNOMIAL_ULAMKOWY& other)
    {

        delete[] this->arr_ulamki;
        n_stopien_u = other.n_stopien_u;

        arr_ulamki = new ULAMEK[n_stopien_u+1];
        for ( int i = 0 ; i < n_stopien_u+1 ; i++ )
        {
            arr_ulamki[i].liczik = other.arr_ulamki[i].liczik;
            arr_ulamki[i].mianownik = other.arr_ulamki[i].mianownik;
        }

        return *this;
    }


    POLYNOMIAL_ULAMKOWY operator-(const POLYNOMIAL_ULAMKOWY& other)
    {

        if (this->n_stopien_u >= other.n_stopien_u )
        {
            POLYNOMIAL_ULAMKOWY p_out(*this);
            int len = other.n_stopien_u+1 ;
            for ( int i = 0 ; i < len ; i++)
            {
                p_out.arr_ulamki[i] = p_out.arr_ulamki[i] - other.arr_ulamki[i] ;
            }

            p_out.usun_zera();

            return p_out;

        } else
        {
            POLYNOMIAL_ULAMKOWY p_out( other );
            int len = this->n_stopien_u+1 ;

            for ( int i = 0 ; i < len ; i++)
            {
                p_out.arr_ulamki[i].liczik *= (-1) ;
            }


            for ( int i = 0 ; i < len ; i++)
            {
                p_out.arr_ulamki[i] = p_out.arr_ulamki[i] +  this->arr_ulamki[i] ;
            }

            p_out.usun_zera();
            return p_out;

        }

    }



    POLYNOMIAL_ULAMKOWY operator*(const POLYNOMIAL_ULAMKOWY& other)
    {
        int n_out = this->n_stopien_u + other.n_stopien_u;
        POLYNOMIAL_ULAMKOWY p_out( n_out );

        int len_1 = this->n_stopien_u+1;
        int len_2 = other.n_stopien_u+1;



        for ( int i = 0 ; i < len_1 ; i++  )
        {
            if ( arr_ulamki[i].liczik != 0 )
            {
                ULAMEK mnoznik(arr_ulamki[i].liczik, arr_ulamki[i].mianownik );
                for ( int j = 0 ; j < len_2 ; j++ )
                {
                    if ( other.arr_ulamki[j].liczik != 0 )
                    {
                        int temp_index = j + i  ;
                        ULAMEK temp_wynik_int =  mnoznik * other.arr_ulamki[j] ;
                        p_out.arr_ulamki[ temp_index] = p_out.arr_ulamki[ temp_index]  + temp_wynik_int;



                    }

                }

            }

        }

        p_out.usun_zera();
        return p_out;

    }







    void przeksztalc_arr(int nowe_n)
    {
        delete[] arr_ulamki;
        n_stopien_u = nowe_n;

        arr_ulamki = new ULAMEK[nowe_n+1];

        for ( int i = 0 ; i < nowe_n+1 ; i++ )
        {
            arr_ulamki[i].mianownik=1;
            arr_ulamki[i].liczik = 0;
        }


    }

};



class POLYNOMIAL{
public:
    static int overloaded;

    int n_stopien;
    int* arr_liczby;



    // utilities




    POLYNOMIAL( POLYNOMIAL_ULAMKOWY* wsk_pol_ul )
    {

        if ( wsk_pol_ul->n_stopien_u==0  && wsk_pol_ul->arr_ulamki[0].liczik == 0  )
        {
            arr_liczby = new int [1];
            arr_liczby[0] = 0 ;
            n_stopien = 0 ;
        } else
        {
            int nww_temp = wsk_pol_ul->arr_ulamki[0].mianownik;

            if ( nww_temp == 0  )
            {
                nww_temp = 1 ;
            }

            for ( int i = 1 ; i < wsk_pol_ul->n_stopien_u+1 ; i++ )
            {
                nww_temp = nww( nww_temp , wsk_pol_ul->arr_ulamki[i].mianownik ) ;

            }

            if ( nww_temp == 0  )
            {
                nww_temp = 1 ;
            }
            arr_liczby = new int[wsk_pol_ul->n_stopien_u+1] ;
            this->n_stopien = wsk_pol_ul->n_stopien_u;
            for ( int i = 0 ; i < wsk_pol_ul->n_stopien_u+1 ; i++)
            {
                int mianownik_temp = wsk_pol_ul->arr_ulamki[i].mianownik ;
                if ( mianownik_temp == 0  )
                {
                    mianownik_temp = 1 ;
                }
                arr_liczby[i] = (nww_temp * wsk_pol_ul->arr_ulamki[i].liczik) / ( mianownik_temp ) ;
            }
        }


    }

    void przeksztalc_arr( int n_nowe)
    {
        int len_out = n_nowe + 1 ;
        delete[] arr_liczby;
        n_stopien = n_nowe;
        arr_liczby = new int[len_out];

        for ( int i = 0 ; i < len_out ; i++  )
        {
            arr_liczby[i] = 0 ;
        }

    }





    // nwd
    int nwd(int a, int b)
    {
        if ( a==0 )
        {
            return b;
        }
        if ( b==0)
        {
            return a;
        }

        if ( a < 0 )
        {
            a = a * (-1);
        }
        if ( b < 0 )
        {
            b = b * (-1);
        }


        while (b != 0) {
            int reszta = a % b;
            a = b;
            b = reszta;
        }



        return a; // lub b - obie zmienne przechowują wynik NWD(a,b)
    }


    int nwd_arr_int()
    {

        if ( n_stopien >= 1 )
        {
            int temp_nwd = this->arr_liczby[0] ;
            int len = n_stopien+1;

            int i = 0;

            /*
            while ( (i < len ) && (arr_liczby[i] == 0) )
            {
                i++;
            }
            temp_nwd= arr_liczby[i];
            i++;

            if ( i >= len )
            {
                if ( temp_nwd != 0  )
                {
                    return temp_nwd;
                } else
                {
                    return 1;
                }

            }

            */

            while ( i < len )
            {

                temp_nwd = nwd( temp_nwd , arr_liczby[i]) ;
//                    if ( temp_nwd == 1  )
//                    {
//                        return 1 ;
//                    }
                i++;

            }

            if ( temp_nwd < 0 )
            {
                temp_nwd *= (-1) ;
            }

            return temp_nwd;

        } else
        {



            if ( this->arr_liczby[0] < 0  )
            {
                return ( this->arr_liczby[0] ) ;
            } else if ( this->arr_liczby[0] > 0 )
            {
                return ( this->arr_liczby[0] ) ;
            } else
            {
                return 1;
            }

        }
    }


    int nww(int a , int b )
    {

        int a_original = a;
        int b_original = b;

        if ( a==0 || b==0)
        {
            return 0;
        }


        if ( a < 0 )
        {
            a = a * (-1);
            a_original *= (-1) ;
        }
        if ( b < 0 )
        {
            b = b * (-1);
            b_original *= (-1) ;
        }
        while (b != 0) {
            int reszta = a % b;
            a = b;
            b = reszta;
        }

        int nwd_temp = a;


        return ( ( a_original*b_original ) / ( nwd_temp ) );

    }


    void nwd_arr()
    {

        if ( n_stopien==0 && arr_liczby[0] != 0 )
        {
            if ( this->arr_liczby[0] < 0 )
            {
                this->arr_liczby[0] = -1 ;
            } else
            {
                this->arr_liczby[0] = 1 ;
            }
        } else
        {
            int temp_nwd = this->nwd_arr_int() ;
            int len = n_stopien+1;


            if ( temp_nwd != 0 )
            {
                for ( int i = 0 ; i < len ; i++)
                {
                    arr_liczby[i] = arr_liczby[i] / temp_nwd ;
                }
            }
        }




    }

    int nww_arr()
    {

        if ( this->n_stopien >= 1 ) {
            int temp_nww = 1;
            int len = n_stopien + 1 ;

            int i = 0;
            while ((i < len) && (arr_liczby[i] == 0)) {
                i++;
            }
            temp_nww = arr_liczby[i];
            i++;

            if (i >= len) {
                return 0;
            }
            while (i < len) {
                if (arr_liczby[i] != 0) {
                    temp_nww = nwd(temp_nww, arr_liczby[i]);
                    if (temp_nww == 1) {
                        return 0;
                    }
                }

                i++;

            }
        }


    }


    void usun_zera()
    {
        int len = n_stopien+1;
        int j = len-1 ;
        int ile_usuniec = 0;

        while ( (j > 0) && ( arr_liczby[j] == 0 ) )
        {
            ile_usuniec++;
            j-- ;
        }
        if ( ile_usuniec == 0  )
        {
            return;
        }
        n_stopien -= ile_usuniec ;
        if ( n_stopien < 0 )
        {
            n_stopien=0;
        }

    }

    POLYNOMIAL( int n , ...)
    {
        va_list va_lista;
        int temp_nwd = 1;
        n_stopien = n;

        va_start( va_lista , n );
        const int size_arr = n + 1;
        arr_liczby = new int[size_arr];
        int i = 0;
        for ( i = 0 ; i < size_arr ; i++ )
        {
            int temp_int = va_arg(va_lista,int) ;
            arr_liczby[i] = temp_int;
        }
        va_end(va_lista);

        this->usun_zera();
        this->nwd_arr() ;

    }


    POLYNOMIAL(const POLYNOMIAL& other ){

        n_stopien = other.n_stopien ;
        const int size_arr = n_stopien + 1;
        arr_liczby = new int[size_arr];

        for ( int i = 0 ; i < size_arr ; i++)
        {
            this->arr_liczby[i] = other.arr_liczby[i];
        }
    }


//    POLYNOMIAL(int n_stop , float fl )
//    {
//        n_stopien=n_stop;
//        int len = n_stop+2;
//        arr_liczby = new int[len] ;
//        arr_liczby[0] = n_stop;
//
//        for ( int i = 1 ; i < len ; i++ )
//        {
//            arr_liczby[i] = 0;
//        }
//
//    }


    POLYNOMIAL()
    {
        n_stopien=0;
        arr_liczby = new int[1];
        arr_liczby[0] = 0;
    }

    ~POLYNOMIAL()
    {
        delete[] arr_liczby;
        n_stopien=0;
        arr_liczby= NULL;
    }



    POLYNOMIAL& operator=(const POLYNOMIAL& other)
    {

        if ( this != &other )
        {
            delete[] arr_liczby;
            arr_liczby= NULL;

            n_stopien = other.n_stopien ;
            const int size_arr = n_stopien + 1;
            arr_liczby = new int[size_arr];

            for ( int i = 0 ; i < size_arr ; i++)
            {
                this->arr_liczby[i] = other.arr_liczby[i];
            }


        }

        this->usun_zera();
        this->nwd_arr() ;

        return *this;
    }


    POLYNOMIAL operator+(const POLYNOMIAL& other)
    {

        if (this->n_stopien >= other.n_stopien )
        {
            POLYNOMIAL p_out(*this);
            int len = other.n_stopien+1 ;
            for ( int i = 0 ; i < len ; i++)
            {
                p_out.arr_liczby[i] += other.arr_liczby[i] ;
            }
            p_out.usun_zera();
            p_out.nwd_arr();
            return p_out;

        } else
        {
            POLYNOMIAL p_out( other );

            int len = this->n_stopien+1 ;
            for ( int i = 0 ; i < len ; i++)
            {
                p_out.arr_liczby[i] += this->arr_liczby[i] ;
            }
            p_out.usun_zera();
            p_out.nwd_arr();

            return p_out;

        }

    }


    POLYNOMIAL operator-(){

        int len = n_stopien+1;
        POLYNOMIAL p_out(*this) ;
        for ( int i = 0 ; i < len ; i++  )
        {
            if ( p_out.arr_liczby[i] != 0 )
            {
                p_out.arr_liczby[i] *= (-1);
            }
        }
        return p_out;

    }


    POLYNOMIAL operator-(const POLYNOMIAL& other)
    {
        POLYNOMIAL p1(other);

        if (this->n_stopien >= other.n_stopien )
        {
            POLYNOMIAL p_out(*this);
            int len = other.n_stopien+1 ;
            for ( int i = 0 ; i < len ; i++)
            {
                p_out.arr_liczby[i] -= other.arr_liczby[i] ;
            }


            p_out.usun_zera();
            p_out.nwd_arr();

            return p_out;

        } else
        {
            POLYNOMIAL p_out( other );

            for ( int i = 0 ; i < other.n_stopien+1 ; i++ )
            {
                p_out.arr_liczby[i] *= (-1) ;
            }

            int len = this->n_stopien+1 ;
            for ( int i = 0 ; i < len ; i++)
            {
                p_out.arr_liczby[i] += this->arr_liczby[i] ;
            }

            p_out.usun_zera();
            p_out.nwd_arr();

            return p_out;

        }

    }



    POLYNOMIAL operator * (const POLYNOMIAL& other){

        int n_out = this->n_stopien+other.n_stopien;
        POLYNOMIAL p_out(0,0);
        p_out.przeksztalc_arr(n_out) ;

        int len_1 = this->n_stopien+1;
        int len_2 = other.n_stopien+1;



        for ( int i = 0 ; i < len_1 ; i++  )
        {
            if ( arr_liczby[i] != 0 )
            {
                int mnoznik = arr_liczby[i] ;
                for ( int j = 0 ; j < len_2 ; j++ )
                {
                    if ( other.arr_liczby[j] != 0 )
                    {
                        int temp_index = j + i  ;
                        int temp_wynik_int =  mnoznik * other.arr_liczby[j] ;
                        p_out.arr_liczby[ temp_index] += temp_wynik_int;
                    }

                }

            }

        }


        p_out.usun_zera();
        p_out.nwd_arr();

        return p_out;

    }


    POLYNOMIAL operator / (const POLYNOMIAL& other )
    {

        if ( ( (this->n_stopien == 0 ) && (this->arr_liczby[0] == 0 ) ) ||  ( (other.n_stopien == 0 ) && (other.arr_liczby[0] == 0 ) ) || ( other.n_stopien >
                                                                                                                                            this->n_stopien ) )
        {
            POLYNOMIAL p_out(0,0);
            return p_out;
        }  else
        {
            int stopien_wyniku = this->n_stopien - other.n_stopien ;
            int uu_mnoznik_stopien = this->n_stopien - other.n_stopien;


            POLYNOMIAL_ULAMKOWY operand_1(this->n_stopien, this->arr_liczby);
            POLYNOMIAL_ULAMKOWY operand_2(other.n_stopien, other.arr_liczby);


            ULAMEK u1( this->arr_liczby[operand_1.n_stopien_u] );
            ULAMEK u2(other.arr_liczby[operand_2.n_stopien_u]) ;

            ULAMEK mnoznik_temp = u1 / u2 ;


            int mnoznik_stopien = operand_1.n_stopien_u - operand_2.n_stopien_u ;
            POLYNOMIAL_ULAMKOWY p_wynik(mnoznik_stopien) ;

            p_wynik.arr_ulamki[mnoznik_stopien].liczik = mnoznik_temp.liczik;
            p_wynik.arr_ulamki[mnoznik_stopien].mianownik = mnoznik_temp.mianownik;

            POLYNOMIAL_ULAMKOWY temp_tablica_mnoznik( mnoznik_stopien , &mnoznik_temp );
            POLYNOMIAL_ULAMKOWY temp_wynik_mnozenia = temp_tablica_mnoznik * operand_2 ;
            POLYNOMIAL_ULAMKOWY temp_wynik_odejmowania =  operand_1 - temp_wynik_mnozenia  ;

            if ( uu_mnoznik_stopien == 0  )
            {
                uu_mnoznik_stopien--;
            }


            if ( temp_wynik_odejmowania.n_stopien_u < operand_2.n_stopien_u)
            {
                uu_mnoznik_stopien = -1 ;
            }



            for ( int i = 1 ; (i < stopien_wyniku + 1) && (uu_mnoznik_stopien > -1) && !( temp_wynik_odejmowania.n_stopien_u==0 && temp_wynik_odejmowania.arr_ulamki[0].liczik == 0  ); i++ )
            {


                ULAMEK uu1( temp_wynik_odejmowania.arr_ulamki[ temp_wynik_odejmowania.n_stopien_u ]   ) ;
                ULAMEK uu2( other.arr_liczby[ other.n_stopien ]  ) ;

                uu_mnoznik_stopien = temp_wynik_odejmowania.n_stopien_u - other.n_stopien ;
                ULAMEK uu_mnoznik = uu1 / uu2 ;


                p_wynik.arr_ulamki[uu_mnoznik_stopien].liczik = uu_mnoznik.liczik;
                p_wynik.arr_ulamki[uu_mnoznik_stopien].mianownik = uu_mnoznik.mianownik;


                POLYNOMIAL_ULAMKOWY uu_temp_tablica_mnoznik( uu_mnoznik_stopien , &uu_mnoznik );


                temp_wynik_mnozenia = uu_temp_tablica_mnoznik * operand_2 ;
                temp_wynik_odejmowania =  temp_wynik_odejmowania - temp_wynik_mnozenia ;


                if ( uu_mnoznik_stopien == 0 )
                {
                    uu_mnoznik_stopien--;
                }


                if ( temp_wynik_odejmowania.n_stopien_u < operand_2.n_stopien_u)
                {
                    uu_mnoznik_stopien = -1 ;
                }


            }


            POLYNOMIAL p_out(&p_wynik);


            p_out.nwd_arr();
            p_out.usun_zera();


            return p_out;

        }

    }



    POLYNOMIAL operator % (const POLYNOMIAL& other ){



        if ( ( (this->n_stopien == 0 ) && (this->arr_liczby[0] == 0 ) ) ||  ( (other.n_stopien == 0 ) && (other.arr_liczby[0] == 0 ) )  )
        {
            POLYNOMIAL p_out(0,0);
            return p_out;
        } else if ( ( other.n_stopien >
                      this->n_stopien ) )
        {
            POLYNOMIAL p_out( *this );
            return p_out;
        } else
        {
            int stopien_wyniku = this->n_stopien - other.n_stopien ;
            int uu_mnoznik_stopien = this->n_stopien - other.n_stopien;


            POLYNOMIAL_ULAMKOWY operand_1(this->n_stopien, this->arr_liczby);
            POLYNOMIAL_ULAMKOWY operand_2(other.n_stopien, other.arr_liczby);


            ULAMEK u1( this->arr_liczby[operand_1.n_stopien_u] );
            ULAMEK u2(other.arr_liczby[operand_2.n_stopien_u]) ;
            ULAMEK mnoznik_temp = u1 / u2 ;
            int mnoznik_stopien = operand_1.n_stopien_u - operand_2.n_stopien_u ;
            POLYNOMIAL_ULAMKOWY p_wynik(mnoznik_stopien) ;

            p_wynik.arr_ulamki[mnoznik_stopien].liczik = mnoznik_temp.liczik;
            p_wynik.arr_ulamki[mnoznik_stopien].mianownik = mnoznik_temp.mianownik;

            POLYNOMIAL_ULAMKOWY temp_tablica_mnoznik( mnoznik_stopien , &mnoznik_temp );
            POLYNOMIAL_ULAMKOWY temp_wynik_mnozenia = temp_tablica_mnoznik * operand_2 ;
            POLYNOMIAL_ULAMKOWY temp_wynik_odejmowania =  operand_1 - temp_wynik_mnozenia  ;

            if ( uu_mnoznik_stopien == 0  )
            {
                uu_mnoznik_stopien--;
            }

            if ( temp_wynik_odejmowania.n_stopien_u < operand_2.n_stopien_u)
            {
                uu_mnoznik_stopien = -1 ;
            }

            for ( int i = 1 ; (i < stopien_wyniku + 1) && (uu_mnoznik_stopien > -1) && !( temp_wynik_odejmowania.n_stopien_u==0 && temp_wynik_odejmowania.arr_ulamki[0].liczik == 0  ) ; i++ )
            {


                ULAMEK uu1( temp_wynik_odejmowania.arr_ulamki[ temp_wynik_odejmowania.n_stopien_u ]   ) ;
                ULAMEK uu2( other.arr_liczby[ other.n_stopien ]  ) ;

                uu_mnoznik_stopien = temp_wynik_odejmowania.n_stopien_u - other.n_stopien ;
                ULAMEK uu_mnoznik = uu1 / uu2 ;

                p_wynik.arr_ulamki[uu_mnoznik_stopien].liczik = uu_mnoznik.liczik;
                p_wynik.arr_ulamki[uu_mnoznik_stopien].mianownik = uu_mnoznik.mianownik;


                POLYNOMIAL_ULAMKOWY uu_temp_tablica_mnoznik( uu_mnoznik_stopien , &uu_mnoznik );


                temp_wynik_mnozenia = uu_temp_tablica_mnoznik * operand_2 ;
                temp_wynik_odejmowania =  temp_wynik_odejmowania - temp_wynik_mnozenia ;


                if ( temp_wynik_odejmowania.n_stopien_u < operand_2.n_stopien_u)
                {
                    uu_mnoznik_stopien = -1 ;
                }

                if ( uu_mnoznik_stopien == 0 )
                {
                    uu_mnoznik_stopien--;
                }

            }


            POLYNOMIAL p_out(&temp_wynik_odejmowania);

            p_out.nwd_arr();
            p_out.usun_zera();
            return p_out;

        }

    }





    POLYNOMIAL operator<<(int shift) {

        if ( shift < 0  )
        {
            POLYNOMIAL p_out(0,0) ;
            return p_out;
        } else if ( shift == 0 )
        {
            POLYNOMIAL p_out(*this) ;
            return p_out;
        } else
        {
            POLYNOMIAL p_out(*this) ;
            int len = this->n_stopien + 1;

            while (  shift > 0 && len > 0  )
            {

                for ( int i = 0 ; i < len - 1 ; i++  )
                {
                    p_out.arr_liczby[i] = p_out.arr_liczby[i+1] ;
                }

                p_out.arr_liczby[len-1] = 0;
                len--;


                shift--;
            }

            p_out.usun_zera();
            p_out.nwd_arr() ;


            return p_out;
        }


    }


    POLYNOMIAL operator>>(int shift) {

        if ( shift < 0  )
        {
            POLYNOMIAL p_out(0,0) ;
            return p_out;

        } else if ( shift == 0 )
        {
            POLYNOMIAL p_out(*this) ;
            return p_out;
        } else
        {
            POLYNOMIAL p_out(*this) ;

            if ( !(this->n_stopien == 0 && this->arr_liczby[0] == 0)  )
            {
                p_out.przeksztalc_arr(this->n_stopien + shift ) ;

                int len = this->n_stopien+1 ;
                p_out.arr_liczby[0] = 0;


                for ( int i = len - 1 ; i > -1  ; i--  )
                {
                    p_out.arr_liczby[i+shift] = this->arr_liczby[i] ;
                }

                shift=0;

                p_out.usun_zera();
                p_out.nwd_arr() ;

            }

            return p_out;
        }


    }





    POLYNOMIAL& operator+=( const POLYNOMIAL& wielomian )
    {

        POLYNOMIAL p_out = (*this) + wielomian ;
        delete[] arr_liczby;
        n_stopien = p_out.n_stopien;
        arr_liczby = new int[n_stopien+1] ;

        for ( int i = 0 ; i < n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] = p_out.arr_liczby[i] ;
        }

        return *this ;
    }

    POLYNOMIAL& operator-=( const POLYNOMIAL& wielomian )
    {

        POLYNOMIAL p_out = (*this) - wielomian ;
        delete[] arr_liczby;
        n_stopien = p_out.n_stopien;
        arr_liczby = new int[n_stopien+1] ;

        for ( int i = 0 ; i < n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] = p_out.arr_liczby[i] ;
        }

        return *this ;
    }

    POLYNOMIAL& operator*=( const POLYNOMIAL& wielomian )
    {

        POLYNOMIAL p_out = (*this) * wielomian ;
        delete[] arr_liczby;
        n_stopien = p_out.n_stopien;
        arr_liczby = new int[n_stopien+1] ;

        for ( int i = 0 ; i < n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] = p_out.arr_liczby[i] ;
        }

        return *this ;
    }


    POLYNOMIAL& operator/=( const POLYNOMIAL& wielomian )
    {

        POLYNOMIAL p_out = (*this) / wielomian ;
        delete[] arr_liczby;
        n_stopien = p_out.n_stopien;
        arr_liczby = new int[n_stopien+1] ;

        for ( int i = 0 ; i < n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] = p_out.arr_liczby[i] ;
        }

        return *this ;
    }



    POLYNOMIAL& operator%=( const POLYNOMIAL& wielomian )
    {

        POLYNOMIAL p_out = (*this) % wielomian ;
        delete[] arr_liczby;
        n_stopien = p_out.n_stopien;
        arr_liczby = new int[n_stopien+1] ;

        for ( int i = 0 ; i < n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] = p_out.arr_liczby[i] ;
        }

        return *this ;
    }


    POLYNOMIAL& operator<<=( int shift )
    {

        POLYNOMIAL p_out =( (*this) << shift ) ;
        delete[] arr_liczby;
        n_stopien = p_out.n_stopien;
        arr_liczby = new int[n_stopien+1] ;

        for ( int i = 0 ; i < n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] = p_out.arr_liczby[i] ;
        }

        return *this ;
    }


    POLYNOMIAL& operator>>=( int shift )
    {

        POLYNOMIAL p_out = ( (*this) >> shift );
        delete[] arr_liczby;
        n_stopien = p_out.n_stopien;
        arr_liczby = new int[n_stopien+1] ;

        for ( int i = 0 ; i < n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] = p_out.arr_liczby[i] ;
        }

        return *this ;

    }



    // Preinkrementacja
    POLYNOMIAL& operator++() {

        for ( int i = 0 ; i < this->n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] += 1 ;
        }

        this->usun_zera();
        this->nwd_arr();

        return *this;
    }

    // Postinkrementacja
    POLYNOMIAL operator++(int) {
        POLYNOMIAL temp(*this); // zapisuje aktualny stan


        for ( int i = 0 ; i < this->n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] += 1 ;
        }

        this->usun_zera();
        this->nwd_arr();

        return temp; // zwraca stan PRZED inkrementacją
    }

    // Predekrementacja
    POLYNOMIAL& operator--() {
        // Zabezpieczenie przed dekrementacją stopnia poniżej zera


        for ( int i = 0 ; i < this->n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] -= 1 ;
        }

        this->usun_zera();
        this->nwd_arr();

        return *this;
    }

    // Postdekrementacja
    POLYNOMIAL operator--(int) {
        POLYNOMIAL temp(*this); // zapisuje aktualny stan


        for ( int i = 0 ; i < this->n_stopien + 1 ; i++ )
        {
            this->arr_liczby[i] -= 1 ;
        }

        this->usun_zera();
        this->nwd_arr();


        return temp; // zwraca stan PRZED dekrementacją
    }


    static void* operator new[](size_t size) {
        void* p = ::operator new[](size);

        overloaded++;

        // Dodatkowe operacje inicjalizacyjne, jeśli są wymagane
        return p;
    }

    static void operator delete[](void* p) {

        overloaded--;
        ::operator delete[](p);
        // Dodatkowe operacje przed zwolnieniem pamięci, jeśli są wymagane
    }


    static void* operator new(size_t size) {
        void* p = ::operator new(size);

        overloaded++;

        // Dodatkowe operacje inicjalizacyjne, jeśli są wymagane
        return p;
    }

    static void operator delete(void* p) {

        overloaded--;
        ::operator delete(p);
        // Dodatkowe operacje przed zwolnieniem pamięci, jeśli są wymagane
    }

};


std::ostream &operator << ( std::ostream &os , const POLYNOMIAL& wielomian )
{

    int len = wielomian.n_stopien + 1 ;

    os << "( " ;
    int i = 0;
    for ( i = 0 ; i < len - 1 ; i++ )
    {
        os << wielomian.arr_liczby[i] << ", " ;
    }
    os << wielomian.arr_liczby[i] ;
    os << " )"  ;

    return os;
}

std::istream &operator >> ( std::istream &is , POLYNOMIAL& wielomian )
{

    int stopien = 0;
    is >> stopien ;
    wielomian.n_stopien = stopien ;
    const int len = stopien + 1 ;
    delete[] wielomian.arr_liczby ;
    wielomian.arr_liczby = new int [len] ;

    int temp_int = 0 ;
    for ( int i = 0  ; i < len ; i++  )
    {
        is >> temp_int;
        wielomian.arr_liczby[i] = temp_int;
    }

    wielomian.usun_zera();
    wielomian.nwd_arr();


    return is;

}


bool operator==(const POLYNOMIAL& a, const POLYNOMIAL& b) {

    bool wynik = true;

    if ( a.n_stopien == b.n_stopien )
    {
        for ( int i = 0 ; i < a.n_stopien + 1 ; i++ )
        {
            if ( a.arr_liczby[i] != b.arr_liczby[i] )
            {
                wynik = false;
                break;
            }
        }
    } else
    {
        wynik = false ;
    }

    return wynik;
}

bool operator!=(const POLYNOMIAL& a, const POLYNOMIAL& b) {

    bool wynik = ( a== b );
    wynik = !wynik ;

    return wynik ;
}

bool operator<(const POLYNOMIAL& a, const POLYNOMIAL& b) {

    bool wynik = false ;
    if ( a.n_stopien != b.n_stopien )
    {
        if ( a.n_stopien < b.n_stopien )
        {
            wynik = true ;
        } else
        {
            wynik = false;
        }


    } else
    {
        for ( int i = a.n_stopien ; (i > -1 )  ; i-- )
        {

            if ( a.arr_liczby[i] != b.arr_liczby[i] )
            {
                if ( a.arr_liczby[i] < b.arr_liczby[i] )
                {
                    wynik = true ;
                } else if ( a.arr_liczby[i] > b.arr_liczby[i] )
                {
                    wynik= false;
                }

                break;

            } else
            {
                wynik = false ;
            }

        }
    }

    return wynik;
}

bool operator<=(const POLYNOMIAL& a, const POLYNOMIAL& b) {


    return (a < b) || (a == b);
}

bool operator>(const POLYNOMIAL& a, const POLYNOMIAL& b) {
    return !(a <= b);  // Wykorzystanie już zdefiniowanych operatorów
}

bool operator>=(const POLYNOMIAL& a, const POLYNOMIAL& b) {

    return !(a < b);
}


