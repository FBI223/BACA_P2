// Marcin Sztukowski

#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"

#include <iostream>


using namespace std;





FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS &copy_from_me) {

    FRUIT_CLASS const* const copy_from_me_wsk = &copy_from_me;

    wsk_do_galezi_w_owocu=copy_from_me_wsk->wsk_do_galezi_w_owocu;
    dlg_na_ktorej_rosnie_owoc=copy_from_me_wsk->dlg_na_ktorej_rosnie_owoc;

    next_fruit=NULL;
    prev_fruit=NULL;

    waga_fruit=copy_from_me_wsk->waga_fruit;


}

//
//FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS *copy_from_me) {
//    wsk_do_galezi_w_owocu=copy_from_me->wsk_do_galezi_w_owocu;
//    dlg_na_ktorej_rosnie_owoc=copy_from_me->dlg_na_ktorej_rosnie_owoc;
//
//    next_fruit=NULL;
//    prev_fruit=NULL;
//
//    waga_fruit=copy_from_me->waga_fruit;
//
//}


FRUIT_CLASS::~FRUIT_CLASS() {

    next_fruit = NULL;
    prev_fruit = NULL;


    if ( waga_fruit > 0 )
    {
        if ( wsk_do_galezi_w_owocu != NULL )
        {
            wsk_do_galezi_w_owocu->set_waga_owocow( wsk_do_galezi_w_owocu->get_waga_owocow() - waga_fruit );
            if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi() != NULL )
            {
                wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->set_waga_owocow_drzewa( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_waga_owocow_drzewa() - waga_fruit ) ;
                if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie() != NULL )
                {
                    wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie()->set_waga_owocow(  wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie()->get_waga_owocow() - waga_fruit ) ;
                }
            }
        }
    }

}

FRUIT_CLASS::FRUIT_CLASS() {
    wsk_do_galezi_w_owocu=NULL;
    dlg_na_ktorej_rosnie_owoc=0;

    next_fruit=NULL;
    prev_fruit=NULL;

    waga_fruit=0;
}

FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS *wsk_do_galezi_w_owocu_podpiecie) {
    wsk_do_galezi_w_owocu = wsk_do_galezi_w_owocu_podpiecie;
    dlg_na_ktorej_rosnie_owoc=0;

    next_fruit=NULL;
    prev_fruit=NULL;

    waga_fruit=0;
}



BRANCH_CLASS *FRUIT_CLASS::get_wsk_do_galezi_w_owocu() {
    return wsk_do_galezi_w_owocu;
}

FRUIT_CLASS* FRUIT_CLASS::get_next_fruit()
{
    return next_fruit;
}
FRUIT_CLASS* FRUIT_CLASS::get_prev_fruit()
{
    return prev_fruit;
}
unsigned int FRUIT_CLASS::get_waga_fruit()
{
    return waga_fruit;
}

unsigned int FRUIT_CLASS::get_dlg_na_ktorej_rosnie_owoc() {
    return dlg_na_ktorej_rosnie_owoc;
}


void FRUIT_CLASS::set_wsk_do_galezi_w_owocu(BRANCH_CLASS *x) {
    wsk_do_galezi_w_owocu=x;
}

void FRUIT_CLASS::set_next_fruit(FRUIT_CLASS* x)
{
    next_fruit=x;
}
void FRUIT_CLASS::set_prev_fruit(FRUIT_CLASS* x)
{
    prev_fruit=x;
}
void FRUIT_CLASS::set_waga_fruit(unsigned int x)
{
    waga_fruit=x;
}

void FRUIT_CLASS::set_dlg_na_ktorej_rosnie_owoc(unsigned int x) {
    dlg_na_ktorej_rosnie_owoc=x;
}

// /////////////////// metody do zadania


BRANCH_CLASS *FRUIT_CLASS::getBranchPointer() {
    return wsk_do_galezi_w_owocu;
}


unsigned int FRUIT_CLASS::getLength() {
    return dlg_na_ktorej_rosnie_owoc;
}

unsigned int FRUIT_CLASS::getWeight() {
    return waga_fruit;
}


void FRUIT_CLASS::growthFruit() {

    if ( wsk_do_galezi_w_owocu != NULL )
    {
        wsk_do_galezi_w_owocu->set_waga_owocow( wsk_do_galezi_w_owocu->get_waga_owocow() + 1 );
        if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi() != NULL )
        {
            wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->set_waga_owocow_drzewa( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_waga_owocow_drzewa() + 1 ) ;
            if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie() != NULL )
            {
                wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie()->set_waga_owocow(  wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie()->get_waga_owocow() + 1 ) ;
            }
        }
    }

    waga_fruit+=1;

}


void FRUIT_CLASS::fadeFruit() {

    if ( waga_fruit > 0 )
    {


        if ( wsk_do_galezi_w_owocu != NULL )
        {

            if ( wsk_do_galezi_w_owocu->get_waga_owocow() > 0 )
            {
                wsk_do_galezi_w_owocu->set_waga_owocow( wsk_do_galezi_w_owocu->get_waga_owocow() - 1 );
            }

            if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi() != NULL )
            {


                if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_waga_owocow_drzewa()  > 0  > 0 )
                {
                    wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->set_waga_owocow_drzewa( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_waga_owocow_drzewa() - 1 ) ;
                }


                if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie() != NULL )
                {
                    if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie()->get_waga_owocow()  > 0 )
                    {
                        wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie()->set_waga_owocow(  wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie()->get_waga_owocow() - 1 ) ;
                        ;
                    }
                }
            }
        }

        waga_fruit-=1;
    }
}



void FRUIT_CLASS::pluckFruit() {

    if ( waga_fruit > 0 )
    {

        if ( wsk_do_galezi_w_owocu != NULL )
        {
            wsk_do_galezi_w_owocu->set_waga_owocow( wsk_do_galezi_w_owocu->get_waga_owocow() - waga_fruit );
            if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi() != NULL )
            {
                wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->set_waga_owocow_drzewa( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_waga_owocow_drzewa() - waga_fruit ) ;
                if ( wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie() != NULL )
                {
                    wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie()->set_waga_owocow(  wsk_do_galezi_w_owocu->get_wsk_do_drzewa_w_galezi()->get_wsk_do_ogrodu_w_drzewie()->get_waga_owocow() - waga_fruit ) ;
                }
            }
        }

        waga_fruit = 0;
    }


}


// /////////////////// metody do zadania



