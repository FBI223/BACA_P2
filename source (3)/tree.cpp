// Marcin Sztukowski

#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"

#include <iostream>

using namespace std;




TREE_CLASS::TREE_CLASS(const TREE_CLASS &copy_from_me) {

    TREE_CLASS const* const  copy_from_me_wsk = &copy_from_me;


    wsk_do_ogrodu_w_drzewie = NULL;

    next_tree=NULL;
    prev_tree=NULL;

    id_drzewa = 0;
    wysokosc_drzewa = copy_from_me_wsk->wysokosc_drzewa;
    n_galezi_aktualnie=copy_from_me_wsk->n_galezi_aktualnie;
    n_owocow_lacznie=copy_from_me_wsk->n_owocow_lacznie;
    waga_owocow_lacznie=copy_from_me_wsk->waga_owocow_lacznie;


    if ( n_galezi_aktualnie > 0 )
    {

        BRANCH_CLASS* temp_branch = copy_from_me_wsk->poczatek_arr_branch;

        BRANCH_CLASS* temp_nowy = new BRANCH_CLASS(*temp_branch);
        BRANCH_CLASS* temp_last = temp_nowy;

        poczatek_arr_branch=temp_nowy;
        koniec_arr_branch=temp_nowy;
        temp_nowy->set_wsk_do_drzewa_w_galezi(this);

        for ( int i = 1 ; i < copy_from_me_wsk->n_galezi_aktualnie ; i++)
        {
            temp_branch = temp_branch->get_next_branch();
            //temp_nowy_copy_constr = BRANCH_CLASS(*temp_branch);
            //temp_nowy = &temp_nowy_copy_constr;
            temp_nowy = new BRANCH_CLASS(*temp_branch);
            temp_nowy->set_wsk_do_drzewa_w_galezi(this);
            temp_nowy->set_prev_branch(temp_last);
            temp_last->set_next_branch(temp_nowy);
            temp_last=temp_nowy;
            koniec_arr_branch=temp_nowy;

        }

    } else
    {
        poczatek_arr_branch=NULL;
        koniec_arr_branch=NULL;

    }

}


//
//TREE_CLASS::TREE_CLASS(const TREE_CLASS* copy_from_me) {
//
//    wsk_do_ogrodu_w_drzewie = copy_from_me->wsk_do_ogrodu_w_drzewie;
//
//    next_tree=NULL;
//    prev_tree=NULL;
//
//    id_drzewa = copy_from_me->id_drzewa;
//    wysokosc_drzewa = copy_from_me->wysokosc_drzewa;
//    n_galezi_aktualnie=copy_from_me->n_galezi_aktualnie;
//    n_owocow_lacznie=copy_from_me->n_owocow_lacznie;
//    waga_owocow_lacznie=copy_from_me->waga_owocow_lacznie;
//
//
//    if ( n_galezi_aktualnie > 0 )
//    {
//
//        BRANCH_CLASS* temp_branch = copy_from_me->poczatek_arr_branch;
//        BRANCH_CLASS* temp_nowy = new BRANCH_CLASS(temp_branch);
//        BRANCH_CLASS* temp_last = temp_nowy;
//
//        poczatek_arr_branch=temp_nowy;
//        koniec_arr_branch=temp_nowy;
//        temp_nowy->set_wsk_do_drzewa_w_galezi(this);
//
//        for ( int i = 1 ; i < copy_from_me->n_galezi_aktualnie ; i++)
//        {
//            temp_branch = temp_branch->get_next_branch();
//            temp_nowy = new BRANCH_CLASS(temp_branch);
//            temp_nowy->set_wsk_do_drzewa_w_galezi(this);
//            temp_nowy->set_prev_branch(temp_last);
//            temp_last->set_next_branch(temp_nowy);
//            temp_last=temp_nowy;
//            koniec_arr_branch=temp_nowy;
//
//        }
//
//    } else
//    {
//        poczatek_arr_branch=NULL;
//        koniec_arr_branch=NULL;
//
//    }
//
//}



TREE_CLASS::TREE_CLASS() {
    wsk_do_ogrodu_w_drzewie=NULL;

    next_tree=NULL;
    prev_tree=NULL;

    poczatek_arr_branch=NULL;
    koniec_arr_branch=NULL;

    id_drzewa=0;
    wysokosc_drzewa=0;
    n_galezi_aktualnie=0;
    n_owocow_lacznie=0;
    waga_owocow_lacznie=0;

}

TREE_CLASS::TREE_CLASS(GARDEN_CLASS *wsk_do_ogrodu_w_drzewie_podpiecie) {
    wsk_do_ogrodu_w_drzewie=wsk_do_ogrodu_w_drzewie_podpiecie;

    next_tree=NULL;
    prev_tree=NULL;

    poczatek_arr_branch=NULL;
    koniec_arr_branch=NULL;

    id_drzewa=0;
    wysokosc_drzewa=0;
    n_galezi_aktualnie=0;
    n_owocow_lacznie=0;
    waga_owocow_lacznie=0;

}



TREE_CLASS::~TREE_CLASS() {
    next_tree = NULL;
    prev_tree = NULL;

    BRANCH_CLASS *usuwany_branch = poczatek_arr_branch;
    BRANCH_CLASS *branch_temp = poczatek_arr_branch;
    for (int i = 0; i < n_galezi_aktualnie; i++) {
        usuwany_branch = branch_temp;
        branch_temp = branch_temp->get_next_branch();
        delete usuwany_branch;

    }

}



GARDEN_CLASS *TREE_CLASS::get_wsk_do_ogrodu_w_drzewie() {
    return wsk_do_ogrodu_w_drzewie;
}


unsigned int TREE_CLASS::get_id_drzewa() {
    return id_drzewa;
}

BRANCH_CLASS *TREE_CLASS::get_koniec_arr_branch() {
    return koniec_arr_branch;
}

unsigned int TREE_CLASS::get_n_galezi_drzewa() {
    return n_galezi_aktualnie;
}

unsigned int TREE_CLASS::get_n_owocow_drzewa() {
    return n_owocow_lacznie;
}

BRANCH_CLASS *TREE_CLASS::get_poczatek_arr_branch() {
    return poczatek_arr_branch;
}

unsigned int TREE_CLASS::get_waga_owocow_drzewa() {
    return waga_owocow_lacznie;
}

unsigned int TREE_CLASS::get_wys_drzewa() {
    return wysokosc_drzewa;

}

TREE_CLASS *TREE_CLASS::get_next_tree() {
    return next_tree;
}

TREE_CLASS *TREE_CLASS::get_prev_tree() {
    return prev_tree;
}



void TREE_CLASS::set_wsk_do_ogrodu_w_drzewie(GARDEN_CLASS *x) {
    wsk_do_ogrodu_w_drzewie = x;
}

void TREE_CLASS::set_id_drzewa(unsigned int x) {
    id_drzewa=x;
}

void TREE_CLASS::set_koniec_arr_branch(BRANCH_CLASS* x) {
    koniec_arr_branch=x;
}

void TREE_CLASS::set_n_galezi_drzewa(unsigned int x) {
    n_galezi_aktualnie=x;
}

void TREE_CLASS::set_n_owocow_drzewa(unsigned int x) {
    n_owocow_lacznie=x;
}

void TREE_CLASS::set_poczatek_arr_branch(BRANCH_CLASS* x) {
    poczatek_arr_branch=x;
}

void TREE_CLASS::set_waga_owocow_drzewa(unsigned int x) {
    waga_owocow_lacznie=x;
}

void TREE_CLASS::set_wys_drzewa(unsigned int x) {
    wysokosc_drzewa=x;
}

void TREE_CLASS::set_prev_tree(TREE_CLASS *x) {
    prev_tree=x;
}

void TREE_CLASS::set_next_tree(TREE_CLASS *x) {
    next_tree=x;
}


// ////////////////////////////////////////////////////////


unsigned int TREE_CLASS::getBranchesTotal() {
    return n_galezi_aktualnie;
}

unsigned int TREE_CLASS::getFruitsTotal() {
    return n_owocow_lacznie;
}

unsigned int TREE_CLASS::getWeightsTotal() {
    return waga_owocow_lacznie;
}

unsigned int TREE_CLASS::getNumber() {
    return id_drzewa;
}

unsigned int TREE_CLASS::getHeight() {
    return wysokosc_drzewa;
}

GARDEN_CLASS *TREE_CLASS::getGardenPointer() {
    return wsk_do_ogrodu_w_drzewie;
}





void TREE_CLASS::growthTree() {


    wysokosc_drzewa += 1 ;
    if ( n_galezi_aktualnie > 0  )
    {
        BRANCH_CLASS* temp_wsk_branch = poczatek_arr_branch;
        for ( int i = 0 ; i < n_galezi_aktualnie ; i++ )
        {
            temp_wsk_branch->growthBranch();
            temp_wsk_branch = temp_wsk_branch->get_next_branch();
        }
    }


    if ( wysokosc_drzewa > 2 )
    {

        if ( ( (wysokosc_drzewa/3)*3) == (wysokosc_drzewa)  )
        {
            BRANCH_CLASS* nowy_branch = new BRANCH_CLASS(this);
            nowy_branch->set_wysokosc_na_ktorej_rosnie_galaz(wysokosc_drzewa);

            if ( wysokosc_drzewa == 3 )
            {
                poczatek_arr_branch = nowy_branch;
                koniec_arr_branch = nowy_branch;

            } else
            {
                nowy_branch->set_prev_branch(koniec_arr_branch);
                koniec_arr_branch->set_next_branch(nowy_branch);
                koniec_arr_branch = nowy_branch;

            }
            n_galezi_aktualnie += 1;
            if ( wsk_do_ogrodu_w_drzewie != NULL )
            {
                wsk_do_ogrodu_w_drzewie->set_n_galezi( wsk_do_ogrodu_w_drzewie->get_n_galezi() + 1 ) ;
            }

        }

    }


}



void TREE_CLASS::fadeTree() {




    if ( wysokosc_drzewa > 0  )
    {

        if ( ((wysokosc_drzewa/3)*3) == wysokosc_drzewa )
        {

            BRANCH_CLASS* temp_usuwany_branch= koniec_arr_branch;

            if ( wysokosc_drzewa == 3 )
            {
                poczatek_arr_branch = NULL;
                koniec_arr_branch = NULL;
            } else
            {
                koniec_arr_branch = koniec_arr_branch->get_prev_branch();
                koniec_arr_branch->set_next_branch(NULL);

            }

            n_owocow_lacznie -=temp_usuwany_branch->getFruitsTotal();
            n_galezi_aktualnie -= 1 ;

            if ( wsk_do_ogrodu_w_drzewie != NULL )
            {
                wsk_do_ogrodu_w_drzewie->set_n_owocow( wsk_do_ogrodu_w_drzewie->get_n_owocow() - temp_usuwany_branch->getFruitsTotal() );
                wsk_do_ogrodu_w_drzewie->set_n_galezi( wsk_do_ogrodu_w_drzewie->get_n_galezi() - 1 );
            }
            wysokosc_drzewa -=1 ;


            delete temp_usuwany_branch;


        } else
        {
            wysokosc_drzewa -=1 ;

        }


    }


    if ( n_galezi_aktualnie > 0 )
    {
        BRANCH_CLASS* temp_branch = poczatek_arr_branch;
        for ( int i = 0 ; i < n_galezi_aktualnie ; i++)
        {
            temp_branch->fadeBranch();
            temp_branch = temp_branch->get_next_branch();
        }

    }




}



void TREE_CLASS::harvestTree(unsigned int waga_owocu_do_zrywania ) {


        BRANCH_CLASS* temp_wsk_branch = poczatek_arr_branch;
        for ( int i = 0 ; i < n_galezi_aktualnie ; i++)
        {
            temp_wsk_branch->harvestBranch(waga_owocu_do_zrywania);
            temp_wsk_branch = temp_wsk_branch->get_next_branch();
        }



}

void TREE_CLASS::cutTree(unsigned int nowa_wysokosc ) {

    if ( nowa_wysokosc < wysokosc_drzewa )
    {

        if ( (wysokosc_drzewa != 1 ) && ( wysokosc_drzewa != 2 ) )
        {
            BRANCH_CLASS* temp_usuwany_branch = koniec_arr_branch;
            BRANCH_CLASS* temp_branch  = koniec_arr_branch;

            while (  ( temp_branch->get_prev_branch() != NULL  ) && ( nowa_wysokosc < temp_branch->get_wysokosc_na_ktorej_rosnie_galaz() ) )
            {

                temp_usuwany_branch = temp_branch ;
                temp_branch = temp_branch->get_prev_branch();

                n_galezi_aktualnie-=1;
                n_owocow_lacznie -= temp_usuwany_branch->get_n_owocow_akt();
                if ( wsk_do_ogrodu_w_drzewie != NULL )
                {
                    wsk_do_ogrodu_w_drzewie->set_n_owocow( wsk_do_ogrodu_w_drzewie->get_n_owocow() - temp_usuwany_branch->get_n_owocow_akt() );
                    wsk_do_ogrodu_w_drzewie->set_n_galezi( wsk_do_ogrodu_w_drzewie->get_n_galezi() - 1 );
                }

                delete temp_usuwany_branch ;
            }

            if ( nowa_wysokosc < temp_branch->get_wysokosc_na_ktorej_rosnie_galaz() )
            {
                n_owocow_lacznie -= temp_branch->get_n_owocow_akt();
                n_galezi_aktualnie-=1;
                if ( wsk_do_ogrodu_w_drzewie != NULL )
                {
                    wsk_do_ogrodu_w_drzewie->set_n_owocow( wsk_do_ogrodu_w_drzewie->get_n_owocow() - temp_branch->get_n_owocow_akt() );
                    wsk_do_ogrodu_w_drzewie->set_n_galezi( wsk_do_ogrodu_w_drzewie->get_n_galezi() - 1 );
                }
                delete temp_branch;
            }


            if ( n_galezi_aktualnie == 0 )
            {
                poczatek_arr_branch = NULL;
                koniec_arr_branch = NULL;
            } else if ( n_galezi_aktualnie >= 1 )
            {

                koniec_arr_branch = temp_branch;
                koniec_arr_branch->set_next_branch(NULL);

            }

            wysokosc_drzewa = nowa_wysokosc;

        } else
        {
            wysokosc_drzewa = nowa_wysokosc ;

        }

        wysokosc_drzewa = nowa_wysokosc;

    }

}


 // niedokonczoczne
BRANCH_CLASS *TREE_CLASS::getBranchPointer(unsigned int szukany_branch_na_wys) {
    BRANCH_CLASS* wsk_do_galezi_na_danej_wysokosci = NULL ;

    if ( !( (szukany_branch_na_wys == 0 ) || ( szukany_branch_na_wys == 1 ) || szukany_branch_na_wys == 2 )  || ( ((szukany_branch_na_wys/3)*3) != szukany_branch_na_wys ) || (szukany_branch_na_wys > wysokosc_drzewa) )
    {

        if ( szukany_branch_na_wys == 3  )
        {
            wsk_do_galezi_na_danej_wysokosci = poczatek_arr_branch;
        } else if ( szukany_branch_na_wys == koniec_arr_branch->get_wysokosc_na_ktorej_rosnie_galaz() )
        {
            wsk_do_galezi_na_danej_wysokosci = koniec_arr_branch;
        } else
        {
            unsigned int czy_znaleziono = 0;
            if ( szukany_branch_na_wys <= (wysokosc_drzewa/2) )
            {

                wsk_do_galezi_na_danej_wysokosci = poczatek_arr_branch;
                while (( wsk_do_galezi_na_danej_wysokosci != NULL ) && (czy_znaleziono == 0)  )
                {
                    if ( wsk_do_galezi_na_danej_wysokosci->get_wysokosc_na_ktorej_rosnie_galaz() == szukany_branch_na_wys )
                    {
                        czy_znaleziono = 1 ;
                    } else
                    {
                        wsk_do_galezi_na_danej_wysokosci = wsk_do_galezi_na_danej_wysokosci->get_next_branch();
                    }
                }

                if ( czy_znaleziono == 0  )
                {
                    wsk_do_galezi_na_danej_wysokosci = NULL;
                }

            } else
            {
                wsk_do_galezi_na_danej_wysokosci = koniec_arr_branch;
                while (  ( wsk_do_galezi_na_danej_wysokosci != NULL ) && (czy_znaleziono == 0)    )
                {
                    if ( wsk_do_galezi_na_danej_wysokosci->get_wysokosc_na_ktorej_rosnie_galaz() == szukany_branch_na_wys )
                    {
                        czy_znaleziono = 1 ;
                    } else
                    {
                        wsk_do_galezi_na_danej_wysokosci = wsk_do_galezi_na_danej_wysokosci->get_prev_branch() ;
                    }
                }

                if ( czy_znaleziono == 0  )
                {
                    wsk_do_galezi_na_danej_wysokosci = NULL;
                }

            }

        }
    }

    return wsk_do_galezi_na_danej_wysokosci;

}



void TREE_CLASS::cloneBranch(BRANCH_CLASS* kopiowany_branch) {




    if ( n_galezi_aktualnie > 0 )
    {

        int czy_znaleziono = 0;
        BRANCH_CLASS* temp_branch = poczatek_arr_branch;
        while (  ( temp_branch != NULL ) &&  ( czy_znaleziono == 0 )  )
        {

            if ( temp_branch->get_dlugosc_galezi() == 0 )
            {
                czy_znaleziono = 1 ;
            } else
            {
                temp_branch = temp_branch->get_next_branch();

            }

        }




        if  ( (czy_znaleziono == 1) && ( kopiowany_branch != NULL ) )
        {


            //BRANCH_CLASS skopiowany_branch_copy_constr = BRANCH_CLASS(*kopiowany_branch);
            //BRANCH_CLASS* skopiowany_branch = &skopiowany_branch_copy_constr;
            BRANCH_CLASS* skopiowany_branch = new BRANCH_CLASS(*kopiowany_branch);
            skopiowany_branch->set_next_branch(NULL);
            skopiowany_branch->set_prev_branch(NULL);

            skopiowany_branch->set_wsk_do_drzewa_w_galezi(this);
            skopiowany_branch->set_wysokosc_na_ktorej_rosnie_galaz( temp_branch->get_wysokosc_na_ktorej_rosnie_galaz() );
            BRANCH_CLASS* temp_usuwany_branch = NULL;


            if ( n_galezi_aktualnie == 1 )
            {
                temp_usuwany_branch = temp_branch;
                poczatek_arr_branch = skopiowany_branch;
                koniec_arr_branch = skopiowany_branch;
            } else if ( temp_branch == poczatek_arr_branch )
            {
                temp_usuwany_branch = poczatek_arr_branch;
                skopiowany_branch->set_next_branch( poczatek_arr_branch->get_next_branch() );
                if ( poczatek_arr_branch->get_next_branch() != NULL )
                {
                    poczatek_arr_branch->get_next_branch()->set_prev_branch( skopiowany_branch );
                }
                //poczatek_arr_branch->get_next_branch()->set_prev_branch( skopiowany_branch );
                poczatek_arr_branch = skopiowany_branch;


            } else if ( temp_branch == koniec_arr_branch )
            {
                temp_usuwany_branch = koniec_arr_branch;
                skopiowany_branch->set_prev_branch( koniec_arr_branch->get_prev_branch()  );
                if ( koniec_arr_branch->get_prev_branch() != NULL )
                {
                    koniec_arr_branch->get_prev_branch()->set_next_branch( skopiowany_branch );
                }
                //koniec_arr_branch->get_prev_branch()->set_next_branch( skopiowany_branch );
                koniec_arr_branch = skopiowany_branch;
            } else
            {

                temp_usuwany_branch = temp_branch;
                skopiowany_branch->set_next_branch( temp_branch->get_next_branch() );
                temp_branch->get_prev_branch()->set_next_branch( skopiowany_branch );
                skopiowany_branch->set_prev_branch(temp_branch->get_prev_branch());
                temp_branch->get_next_branch()->set_prev_branch( skopiowany_branch );
            }


            if ( temp_usuwany_branch != NULL )
            {
                delete temp_usuwany_branch;
            }


            n_owocow_lacznie+= skopiowany_branch->get_n_owocow_akt();
            waga_owocow_lacznie+= skopiowany_branch->get_waga_owocow();
            if ( wsk_do_ogrodu_w_drzewie != NULL )
            {
                wsk_do_ogrodu_w_drzewie->set_n_owocow( wsk_do_ogrodu_w_drzewie->get_n_owocow() + skopiowany_branch->get_n_owocow_akt() );
                wsk_do_ogrodu_w_drzewie->set_waga_owocow( wsk_do_ogrodu_w_drzewie->get_waga_owocow() + skopiowany_branch->get_waga_owocow() );
            }



        }


    }




}


// ////////////////////////////////////////////////////////



