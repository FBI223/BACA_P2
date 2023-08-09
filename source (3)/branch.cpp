// Marcin Sztukowski

#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"

#include <iostream>

using namespace std;




BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS &copy_from_me) {

    BRANCH_CLASS const* const copy_from_me_wsk = &copy_from_me;

    wsk_do_drzewa_w_galezi=copy_from_me_wsk->wsk_do_drzewa_w_galezi;
    wysokosc_na_ktorej_rosnie_galaz=copy_from_me_wsk->wysokosc_na_ktorej_rosnie_galaz;

    n_owocow_akt=copy_from_me_wsk->n_owocow_akt;
    waga_owocow = copy_from_me_wsk->waga_owocow;
    dlugosc_galezi = copy_from_me_wsk->dlugosc_galezi;

    next_branch=NULL;
    prev_branch=NULL;

    if ( copy_from_me_wsk->n_owocow_akt > 0 )
    {
        FRUIT_CLASS* temp_owoc = copy_from_me_wsk->poczatek_arr_fruit;
        //FRUIT_CLASS temp_nowy_copy_constr = FRUIT_CLASS( *temp_owoc );
        //FRUIT_CLASS* temp_nowy = & temp_nowy_copy_constr;
        FRUIT_CLASS* temp_nowy = new FRUIT_CLASS(*temp_owoc);
        FRUIT_CLASS* temp_last = temp_nowy;

        poczatek_arr_fruit=temp_nowy;
        koniec_arr_fruit=temp_nowy;
        temp_nowy->set_wsk_do_galezi_w_owocu(this);

        for (  int i = 1 ; i < copy_from_me_wsk->n_owocow_akt ; i++)
        {

            temp_owoc = temp_owoc->get_next_fruit();
            //temp_nowy_copy_constr = FRUIT_CLASS( *temp_owoc );
            //temp_nowy = &temp_nowy_copy_constr;
            temp_nowy = new FRUIT_CLASS(*temp_owoc);
            temp_nowy->set_wsk_do_galezi_w_owocu(this);
            temp_nowy->set_prev_fruit(temp_last);
            temp_last->set_next_fruit(temp_nowy);
            temp_last=temp_nowy;
            koniec_arr_fruit=temp_nowy;
        }
    } else
    {
        poczatek_arr_fruit=NULL;
        koniec_arr_fruit=NULL;
    }


}
//
//
//BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS* copy_from_me) {
//    wsk_do_drzewa_w_galezi=copy_from_me->wsk_do_drzewa_w_galezi;
//    wysokosc_na_ktorej_rosnie_galaz=copy_from_me->wysokosc_na_ktorej_rosnie_galaz;
//
//    n_owocow_akt=copy_from_me->n_owocow_akt;
//    waga_owocow = copy_from_me->waga_owocow;
//    dlugosc_galezi = copy_from_me->dlugosc_galezi;
//
//    next_branch=NULL;
//    prev_branch=NULL;
//
//    if ( copy_from_me->n_owocow_akt > 0 )
//    {
//        FRUIT_CLASS* temp_owoc = copy_from_me->poczatek_arr_fruit;
//        FRUIT_CLASS* temp_nowy = new FRUIT_CLASS(temp_owoc);
//        FRUIT_CLASS* temp_last = temp_nowy;
//
//        poczatek_arr_fruit=temp_nowy;
//        koniec_arr_fruit=temp_nowy;
//        temp_nowy->set_wsk_do_galezi_w_owocu(this);
//
//        for (  int i = 1 ; i < copy_from_me->n_owocow_akt ; i++)
//        {
//
//            temp_owoc = temp_owoc->get_next_fruit();
//            temp_nowy = new FRUIT_CLASS(temp_owoc);
//            temp_nowy->set_wsk_do_galezi_w_owocu(this);
//            temp_nowy->set_prev_fruit(temp_last);
//            temp_last->set_next_fruit(temp_nowy);
//            temp_last=temp_nowy;
//            koniec_arr_fruit=temp_nowy;
//        }
//    } else
//    {
//        poczatek_arr_fruit=NULL;
//        koniec_arr_fruit=NULL;
//    }
//
//
//
//}


BRANCH_CLASS::BRANCH_CLASS() {
    wsk_do_drzewa_w_galezi=NULL;

    wysokosc_na_ktorej_rosnie_galaz=0;

    next_branch=NULL;
    prev_branch=NULL;

    poczatek_arr_fruit= NULL;
    koniec_arr_fruit=NULL;

    n_owocow_akt=0;
    waga_owocow=0;
    dlugosc_galezi=0;
}

BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS *wsk_do_drzewa_w_galezi_podpiecie) {
    wsk_do_drzewa_w_galezi = wsk_do_drzewa_w_galezi_podpiecie;

    wysokosc_na_ktorej_rosnie_galaz=0;

    next_branch=NULL;
    prev_branch=NULL;

    poczatek_arr_fruit= NULL;
    koniec_arr_fruit=NULL;

    n_owocow_akt=0;
    waga_owocow=0;
    dlugosc_galezi=0;
}



BRANCH_CLASS::~BRANCH_CLASS() { // galezi moga miec puste miejsce na owoce2

    FRUIT_CLASS* usuwany_fruit = poczatek_arr_fruit;
    FRUIT_CLASS* temp_fruit = poczatek_arr_fruit;

    next_branch=NULL;
    prev_branch = NULL;

    for ( int i = 0 ; i < n_owocow_akt ; i++)
    {
        usuwany_fruit = temp_fruit;
        temp_fruit = temp_fruit->get_next_fruit();
        delete usuwany_fruit;
    }

}



TREE_CLASS *BRANCH_CLASS::get_wsk_do_drzewa_w_galezi() {
    return wsk_do_drzewa_w_galezi;
}

BRANCH_CLASS* BRANCH_CLASS::get_next_branch()
{
    return next_branch;
}
BRANCH_CLASS* BRANCH_CLASS::get_prev_branch()
{
    return prev_branch;
}
FRUIT_CLASS* BRANCH_CLASS::get_poczatek_arr_fruit()
{
    return poczatek_arr_fruit;
}
FRUIT_CLASS* BRANCH_CLASS::get_koniec_arr_fruit()
{
    return koniec_arr_fruit;
}
unsigned int BRANCH_CLASS::get_n_owocow_akt()
{
    return n_owocow_akt;
}
unsigned int BRANCH_CLASS::get_waga_owocow()
{
    return waga_owocow;
}

unsigned int BRANCH_CLASS::get_wysokosc_na_ktorej_rosnie_galaz() {
    return wysokosc_na_ktorej_rosnie_galaz;
}

unsigned int BRANCH_CLASS::get_dlugosc_galezi() {
    return dlugosc_galezi;
}




void BRANCH_CLASS::set_wsk_do_drzewa_w_galezi(TREE_CLASS *x) {
    wsk_do_drzewa_w_galezi=x;
}

void BRANCH_CLASS::set_next_branch(BRANCH_CLASS* x)
{
    next_branch=x;
}
void BRANCH_CLASS::set_prev_branch(BRANCH_CLASS* x)
{
    prev_branch=x;
}
void BRANCH_CLASS::set_poczatek_arr_fruit(FRUIT_CLASS* x)
{
    poczatek_arr_fruit=x;
}
void BRANCH_CLASS::set_koniec_arr_fruit(FRUIT_CLASS* x)
{
    koniec_arr_fruit=x;
}
void BRANCH_CLASS::set_n_owocow_akt(unsigned int x)
{
    n_owocow_akt=x;
}
void BRANCH_CLASS::set_waga_owocow(unsigned int x)
{
    waga_owocow=x;
}

void BRANCH_CLASS::set_wysokosc_na_ktorej_rosnie_galaz(unsigned int x) {
    wysokosc_na_ktorej_rosnie_galaz=x;
}

void BRANCH_CLASS::set_dlugosc_galezi(unsigned int x) {
    dlugosc_galezi=x;
}


// /////////////////// metody do zadania


unsigned int BRANCH_CLASS::getFruitsTotal() {
    return n_owocow_akt;
}

unsigned int BRANCH_CLASS::getWeightsTotal() {
    return waga_owocow;
}

unsigned int BRANCH_CLASS::getHeight() {
    return wysokosc_na_ktorej_rosnie_galaz;
}

unsigned int BRANCH_CLASS::getLength() {

    return dlugosc_galezi;
}

TREE_CLASS *BRANCH_CLASS::getTreePointer() {
    return wsk_do_drzewa_w_galezi;
}


void BRANCH_CLASS::growthBranch() {

    dlugosc_galezi += 1;
    if ( n_owocow_akt > 0  )
    {
        FRUIT_CLASS* temp_owoc = poczatek_arr_fruit;
        for (int i = 0 ; i < n_owocow_akt ; i++)
        {
            temp_owoc->growthFruit();
            temp_owoc = temp_owoc->get_next_fruit();
        }
    }

    if ( ((dlugosc_galezi/2)*2) == dlugosc_galezi ) {
        FRUIT_CLASS* temp_nowy_fruit = new FRUIT_CLASS(this);
        temp_nowy_fruit->set_dlg_na_ktorej_rosnie_owoc( dlugosc_galezi);

        if ( n_owocow_akt == 0 )
        {
            poczatek_arr_fruit = temp_nowy_fruit;
            koniec_arr_fruit = temp_nowy_fruit;

        } else if ( n_owocow_akt > 0 )
        {

            koniec_arr_fruit->set_next_fruit( temp_nowy_fruit );
            temp_nowy_fruit->set_prev_fruit( koniec_arr_fruit );
            koniec_arr_fruit = temp_nowy_fruit;

        }

        n_owocow_akt += 1 ;
        if ( wsk_do_drzewa_w_galezi != NULL )
        {
            wsk_do_drzewa_w_galezi->set_n_owocow_drzewa( wsk_do_drzewa_w_galezi->get_n_owocow_drzewa() + 1 );
            if ( wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie() != NULL )
            {
                wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie()->set_n_owocow( wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie()->get_n_owocow() + 1 );

            }
        }

    }

}





void BRANCH_CLASS::fadeBranch() {


    if ( dlugosc_galezi > 1  )
    {
        dlugosc_galezi -= 1 ;

        if ( (((dlugosc_galezi+1)/2)*2) == (dlugosc_galezi+1) ) {

            FRUIT_CLASS* usuwany_fruit = koniec_arr_fruit;

            if ( n_owocow_akt == 1  )
            {
                poczatek_arr_fruit = NULL;
                koniec_arr_fruit = NULL;

            } else if ( n_owocow_akt > 1  )
            {
                koniec_arr_fruit = koniec_arr_fruit->get_prev_fruit();
                koniec_arr_fruit->set_next_fruit(NULL);

            }


            n_owocow_akt -= 1 ;
            if ( wsk_do_drzewa_w_galezi != NULL )
            {
                wsk_do_drzewa_w_galezi->set_n_owocow_drzewa( wsk_do_drzewa_w_galezi->get_n_owocow_drzewa() - 1 );
                if ( wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie() != NULL )
                {
                    wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie()->set_n_owocow( wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie()->get_n_owocow() - 1 );

                }
            }

            delete usuwany_fruit;
        }


    } else if ( dlugosc_galezi == 1  )
    {
        dlugosc_galezi -= 1 ;

    }

    if ( n_owocow_akt > 0  )
    {

        FRUIT_CLASS* temp_fruit = poczatek_arr_fruit;
        for (int i = 0 ; i < n_owocow_akt ; i++)
        {
            temp_fruit->fadeFruit();
            temp_fruit = temp_fruit->get_next_fruit();
        }


    }


}



void BRANCH_CLASS::harvestBranch(unsigned int waga_usuwana ) {


        FRUIT_CLASS* temp_wsk_owoc = poczatek_arr_fruit;
        for (int i = 0 ; i < n_owocow_akt ; i++ )
        {
            if ( temp_wsk_owoc->get_waga_fruit() >= waga_usuwana )
            {
                temp_wsk_owoc->pluckFruit();

            }
            temp_wsk_owoc = temp_wsk_owoc->get_next_fruit();
        }

}


void BRANCH_CLASS::cutBranch(unsigned int nowa_dlugosc ) {
    if ( nowa_dlugosc < dlugosc_galezi )
    {
        if ( dlugosc_galezi != 1 )
        {
            FRUIT_CLASS* temp_owoc = koniec_arr_fruit;
            FRUIT_CLASS* temp_usuwany_owoc = koniec_arr_fruit;
            FRUIT_CLASS* temp_last_owoc_w_arr = koniec_arr_fruit;

            while ( ( temp_owoc->get_prev_fruit() != NULL ) && ( nowa_dlugosc < temp_owoc->get_dlg_na_ktorej_rosnie_owoc()  )  )
            {
                temp_usuwany_owoc=temp_owoc;
                temp_owoc = temp_owoc->get_prev_fruit();
                delete temp_usuwany_owoc;

                n_owocow_akt-=1;
                if ( wsk_do_drzewa_w_galezi != NULL )
                {
                    wsk_do_drzewa_w_galezi->set_n_owocow_drzewa( wsk_do_drzewa_w_galezi->get_n_owocow_drzewa() - 1 );
                    if ( wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie() != NULL )
                    {
                        wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie()->set_n_owocow(wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie()->get_n_owocow() - 1  );
                    }
                }
            }

            if ( nowa_dlugosc < temp_owoc->get_dlg_na_ktorej_rosnie_owoc()  )
            {
                delete temp_owoc;
                n_owocow_akt-=1;

                if ( wsk_do_drzewa_w_galezi != NULL )
                {
                    wsk_do_drzewa_w_galezi->set_n_owocow_drzewa( wsk_do_drzewa_w_galezi->get_n_owocow_drzewa() - 1 );
                    if ( wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie() != NULL )
                    {
                        wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie()->set_n_owocow(wsk_do_drzewa_w_galezi->get_wsk_do_ogrodu_w_drzewie()->get_n_owocow() - 1  );
                    }
                }
            }

            if ( n_owocow_akt == 0 )
            {
                poczatek_arr_fruit = NULL;
                koniec_arr_fruit = NULL;
            } else if ( n_owocow_akt >= 1  )
            {
                koniec_arr_fruit = temp_owoc;
                temp_owoc->set_next_fruit(NULL);
            }


            dlugosc_galezi = nowa_dlugosc;

        } else
        {
            dlugosc_galezi = nowa_dlugosc;
        }
        dlugosc_galezi  = nowa_dlugosc;

    }

}


 // NEISKONCZONE
FRUIT_CLASS *BRANCH_CLASS::getFruitPointer(unsigned int szukany_owoc_na_dlg ) {

    FRUIT_CLASS* wsk_do_owocu_na_danej_dlg = NULL;
    if (  !( (szukany_owoc_na_dlg == 0 ) || ( szukany_owoc_na_dlg == 1  ) || ( ((szukany_owoc_na_dlg/2)*2) != szukany_owoc_na_dlg ) || ( szukany_owoc_na_dlg > dlugosc_galezi ) )   )
    {

        if  ( szukany_owoc_na_dlg == 2 )
        {
            wsk_do_owocu_na_danej_dlg = poczatek_arr_fruit;
        } else if ( szukany_owoc_na_dlg == koniec_arr_fruit->get_dlg_na_ktorej_rosnie_owoc() )
        {
            wsk_do_owocu_na_danej_dlg = koniec_arr_fruit;
        } else
        {
            unsigned int czy_znaleziono = 0;
            if ( szukany_owoc_na_dlg <= (dlugosc_galezi/2) )
            {
                wsk_do_owocu_na_danej_dlg=poczatek_arr_fruit;
                while ( ( wsk_do_owocu_na_danej_dlg != NULL ) && (czy_znaleziono==0)   )
                {
                    if ( wsk_do_owocu_na_danej_dlg->get_dlg_na_ktorej_rosnie_owoc() == szukany_owoc_na_dlg )
                    {
                        czy_znaleziono = 1 ;
                    } else
                    {
                        wsk_do_owocu_na_danej_dlg = wsk_do_owocu_na_danej_dlg->get_next_fruit();
                    }
                }

                if ( czy_znaleziono == 0 )
                {
                    wsk_do_owocu_na_danej_dlg = NULL;
                }

            } else
            {
                wsk_do_owocu_na_danej_dlg = koniec_arr_fruit;
                while ( ( wsk_do_owocu_na_danej_dlg != NULL )  &&  (czy_znaleziono==0) )
                {
                    if ( wsk_do_owocu_na_danej_dlg->get_dlg_na_ktorej_rosnie_owoc() == szukany_owoc_na_dlg )
                    {
                        czy_znaleziono = 1 ;
                    } else
                    {
                        wsk_do_owocu_na_danej_dlg = wsk_do_owocu_na_danej_dlg->get_prev_fruit();
                    }
                }

                if ( czy_znaleziono == 0 )
                {
                    wsk_do_owocu_na_danej_dlg = NULL;
                }
            }


        }

    }

    return wsk_do_owocu_na_danej_dlg;

}



