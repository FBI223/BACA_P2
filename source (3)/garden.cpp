// Marcin Sztukowski

#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"

#include <iostream>

using namespace std;






GARDEN_CLASS::GARDEN_CLASS() {
    poczatek_arr_tree=NULL;
    koniec_arr_tree=NULL;

    n_drzew=0;
    n_galezi=0;
    n_owocow=0;
    waga_owocow=0;
}




GARDEN_CLASS::~GARDEN_CLASS() {

        TREE_CLASS* temp_wsk_drzewa = poczatek_arr_tree;
        TREE_CLASS* temp_usun=temp_wsk_drzewa;

            for (int i = 0 ; i < n_drzew  ; i++) {
                temp_usun = temp_wsk_drzewa;
                temp_wsk_drzewa = temp_wsk_drzewa->get_next_tree();
                delete temp_usun;
            }
}

TREE_CLASS* GARDEN_CLASS::get_poczatek_arr_tree()
{
    return poczatek_arr_tree;
}
TREE_CLASS* GARDEN_CLASS::get_koniec_arr_tree()
{
    return koniec_arr_tree;
}
unsigned int GARDEN_CLASS::get_n_drzew()
{
    return n_drzew;
}
unsigned int GARDEN_CLASS::get_n_galezi()
{
    return n_galezi;
}
unsigned int GARDEN_CLASS::get_n_owocow()
{
    return n_owocow;
}
unsigned int GARDEN_CLASS::get_waga_owocow()
{
    return waga_owocow;
}


void GARDEN_CLASS::set_poczatek_arr_tree(TREE_CLASS* x)
{
    poczatek_arr_tree=x;
}
void GARDEN_CLASS::set_koniec_arr_tree(TREE_CLASS* x)
{
    koniec_arr_tree=x;
}
void GARDEN_CLASS::set_n_drzew(unsigned int x)
{
    n_drzew=x;
}
void GARDEN_CLASS::set_n_galezi(unsigned int x)
{
    n_galezi=x;
}
void GARDEN_CLASS::set_n_owocow(unsigned int x)
{
    n_owocow=x;
}
void GARDEN_CLASS::set_waga_owocow(unsigned int x)
{
    waga_owocow=x;
}




// /////////////////////////////////////////////////////////////////////////


unsigned int GARDEN_CLASS::getTreesTotal() {
    unsigned int wynik = n_drzew;
    return wynik;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {
    unsigned int wynik = n_galezi;
    return wynik;
}
unsigned int GARDEN_CLASS::getWeightsTotal() {
    unsigned int wynik = waga_owocow;
    return wynik;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {
    return n_owocow;
}



void GARDEN_CLASS::plantTree() {


    TREE_CLASS* nowe_drzewo = new TREE_CLASS(this);

    if ( n_drzew > 0 )
    {


        if ( poczatek_arr_tree->get_id_drzewa() != 0 )
        {
          nowe_drzewo->set_id_drzewa(0);
          nowe_drzewo->set_next_tree(poczatek_arr_tree) ;
          poczatek_arr_tree->set_prev_tree(nowe_drzewo) ;
          poczatek_arr_tree=nowe_drzewo;

        } else if ( poczatek_arr_tree->get_id_drzewa() + ( n_drzew - 1  ) == koniec_arr_tree->get_id_drzewa() ) {


                unsigned int temp_id = -1;
                temp_id = koniec_arr_tree->get_id_drzewa() + 1;
                nowe_drzewo->set_prev_tree(koniec_arr_tree);
                koniec_arr_tree->set_next_tree(nowe_drzewo);
                koniec_arr_tree = nowe_drzewo;
                koniec_arr_tree->set_id_drzewa(temp_id);


        } else
        {

            int i = 0 ;
            int czy_koniec = 0;
            unsigned long long int temp_id = -1 ;
            TREE_CLASS* temp_wsk_drzewo= poczatek_arr_tree  ;




                while ( (i < n_drzew-1) && ( czy_koniec == 0 ) )
                {
                    if ( temp_wsk_drzewo->get_next_tree()->get_id_drzewa() - temp_wsk_drzewo->get_id_drzewa() > 1 )
                    {
                        temp_id = temp_wsk_drzewo->get_id_drzewa() + 1 ;
                        czy_koniec = 1 ;
                        nowe_drzewo->set_id_drzewa(temp_id) ;

                        TREE_CLASS* temp_wsk_drzewo_next = temp_wsk_drzewo->get_next_tree();
                        nowe_drzewo->set_prev_tree(temp_wsk_drzewo);
                        nowe_drzewo->set_next_tree(temp_wsk_drzewo_next);
                        temp_wsk_drzewo->set_next_tree(nowe_drzewo);
                        temp_wsk_drzewo_next->set_prev_tree(nowe_drzewo);

                    } else
                    {
                        temp_wsk_drzewo = temp_wsk_drzewo->get_next_tree();
                    }

                    i++;
                }



        }

    } else
    {

        poczatek_arr_tree=nowe_drzewo;
        koniec_arr_tree=nowe_drzewo;
        nowe_drzewo->set_id_drzewa(0);
    }

    n_drzew += 1;

}




void GARDEN_CLASS::plantTree_wstaw_drzewo_juz_zrobione(TREE_CLASS* nowe_drzewo  ) {


    if ( n_drzew > 0 )
    {


        if ( poczatek_arr_tree->get_id_drzewa() != 0 )
        {
            nowe_drzewo->set_id_drzewa(0);
            nowe_drzewo->set_next_tree(poczatek_arr_tree) ;
            poczatek_arr_tree->set_prev_tree(nowe_drzewo) ;
            poczatek_arr_tree=nowe_drzewo;

        } else if ( poczatek_arr_tree->get_id_drzewa() + ( n_drzew - 1  ) == koniec_arr_tree->get_id_drzewa() ) {


            unsigned int temp_id = 0;
            temp_id = koniec_arr_tree->get_id_drzewa() + 1;
            nowe_drzewo->set_prev_tree(koniec_arr_tree);
            koniec_arr_tree->set_next_tree(nowe_drzewo);
            koniec_arr_tree = nowe_drzewo;
            koniec_arr_tree->set_id_drzewa(temp_id);


        } else
        {

            int i = 0 ;
            int czy_koniec = 0;
            unsigned long long int temp_id = 0 ;
            TREE_CLASS* temp_wsk_drzewo= poczatek_arr_tree  ;




            while ( (i < n_drzew-1) && ( czy_koniec == 0 ) )
            {
                if ( temp_wsk_drzewo->get_next_tree()->get_id_drzewa() - temp_wsk_drzewo->get_id_drzewa() > 1 )
                {
                    temp_id = temp_wsk_drzewo->get_id_drzewa() + 1 ;
                    czy_koniec = 1 ;
                    nowe_drzewo->set_id_drzewa(temp_id) ;

                    TREE_CLASS* temp_wsk_drzewo_next = temp_wsk_drzewo->get_next_tree();
                    nowe_drzewo->set_prev_tree(temp_wsk_drzewo);
                    nowe_drzewo->set_next_tree(temp_wsk_drzewo_next);
                    temp_wsk_drzewo->set_next_tree(nowe_drzewo);
                    temp_wsk_drzewo_next->set_prev_tree(nowe_drzewo);

                } else
                {
                    temp_wsk_drzewo = temp_wsk_drzewo->get_next_tree();
                }

                i++;
            }



        }

    }

    n_drzew += 1;

}




void GARDEN_CLASS::extractTree(unsigned int id_usuwane) {


    if ( n_drzew > 0 )
    {
        TREE_CLASS* usuwany_tree=NULL;
        unsigned int czy_znaleziono_usuwany = 0;

      if ( n_drzew == 1 )
      {
          if ( poczatek_arr_tree->get_id_drzewa() == id_usuwane )
          {
              czy_znaleziono_usuwany=1;
              usuwany_tree=poczatek_arr_tree;

              poczatek_arr_tree=NULL;
              koniec_arr_tree=NULL;

              n_owocow-= usuwany_tree->get_n_owocow_drzewa();
              n_galezi-= usuwany_tree->get_n_galezi_drzewa();
              //waga_owocow -= usuwany_tree->get_waga_owocow_drzewa();

              delete usuwany_tree;
              n_drzew-=1;

          }

      } else
      {
          if ( poczatek_arr_tree->get_id_drzewa() == id_usuwane )
          {
              usuwany_tree=poczatek_arr_tree;
              czy_znaleziono_usuwany = 1 ;

              n_owocow-= usuwany_tree->get_n_owocow_drzewa();
              n_galezi-= usuwany_tree->get_n_galezi_drzewa();
              //waga_owocow -= usuwany_tree->get_waga_owocow_drzewa();

              poczatek_arr_tree = poczatek_arr_tree->get_next_tree();
              poczatek_arr_tree->set_prev_tree(NULL);


              delete usuwany_tree;
              n_drzew-=1;

          } else if ( koniec_arr_tree->get_id_drzewa() == id_usuwane )
          {
              usuwany_tree=koniec_arr_tree;
              czy_znaleziono_usuwany = 1 ;

              n_owocow-= usuwany_tree->get_n_owocow_drzewa();
              n_galezi-= usuwany_tree->get_n_galezi_drzewa();
              waga_owocow -= usuwany_tree->get_waga_owocow_drzewa();

              koniec_arr_tree = koniec_arr_tree->get_prev_tree();
              koniec_arr_tree->set_next_tree(NULL);

              delete usuwany_tree;
              n_drzew-=1;

          } else if ( id_usuwane < koniec_arr_tree->get_id_drzewa() )
          {
              unsigned int czy_koniec = 0;
              czy_znaleziono_usuwany=0;
              usuwany_tree=NULL;

              usuwany_tree = poczatek_arr_tree;
              while ( (czy_koniec==0) && ( usuwany_tree != koniec_arr_tree ) )
              {
                  if ( usuwany_tree->get_id_drzewa() == id_usuwane )
                  {
                      czy_znaleziono_usuwany = 1 ;
                      czy_koniec=1;
                  } else
                  {
                      if ( ( usuwany_tree->get_id_drzewa() < id_usuwane ) && ( id_usuwane < usuwany_tree->get_next_tree()->get_id_drzewa()   ) )
                      {
                          czy_koniec = 1;
                          czy_znaleziono_usuwany = 0;
                      } else
                      {
                          usuwany_tree = usuwany_tree->get_next_tree();
                      }
                  }
              }

              if ( czy_znaleziono_usuwany == 1  )
              {

                  usuwany_tree->get_prev_tree()->set_next_tree( usuwany_tree->get_next_tree() );
                  usuwany_tree->get_next_tree()->set_prev_tree( usuwany_tree->get_prev_tree() );

                  n_owocow-= usuwany_tree->get_n_owocow_drzewa();
                  n_galezi-= usuwany_tree->get_n_galezi_drzewa();
                  //waga_owocow -= usuwany_tree->get_waga_owocow_drzewa();

                  delete usuwany_tree;
                  n_drzew-=1;

              }


          }




      }


    }

}




void GARDEN_CLASS::growthGarden() {

    if ( n_drzew > 0 )
    {
        TREE_CLASS* temp_wsk_drzewo = poczatek_arr_tree;
        for (int i = 0 ; i < n_drzew ; i++)
        {
            temp_wsk_drzewo->growthTree();
            temp_wsk_drzewo = temp_wsk_drzewo->get_next_tree();
        }
    }

}


void GARDEN_CLASS::fadeGarden() {
    if ( n_drzew > 0 )
    {
        TREE_CLASS* temp_wsk_drzewo = poczatek_arr_tree;
        for (int i = 0 ; i < n_drzew ; i++)
        {
            temp_wsk_drzewo->fadeTree();
            temp_wsk_drzewo = temp_wsk_drzewo->get_next_tree();
        }
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int waga_owocu_do_zrywaniaa) {

        TREE_CLASS* temp_wsk_drzewo = poczatek_arr_tree;
        for (int i = 0 ; i < n_drzew ; i++)
        {
            temp_wsk_drzewo->harvestTree(waga_owocu_do_zrywaniaa);
            temp_wsk_drzewo = temp_wsk_drzewo->get_next_tree();
        }
    }




 // niedokonczone
TREE_CLASS *GARDEN_CLASS::getTreePointer(unsigned int szukane_drzewo_id) {

    TREE_CLASS* wsk_do_drzewa_wynik = NULL;

    if ( n_drzew > 0 )
    {

        if ( poczatek_arr_tree->get_id_drzewa() == szukane_drzewo_id )
        {
            wsk_do_drzewa_wynik = poczatek_arr_tree;
        } else if ( koniec_arr_tree->get_id_drzewa() == szukane_drzewo_id )
        {
            wsk_do_drzewa_wynik = koniec_arr_tree;
        } else
        {
            unsigned int czy_znaleziono = 0 ;
            unsigned int czy_koniec = 0 ;

            if ( szukane_drzewo_id < koniec_arr_tree->get_id_drzewa() )
            {
                TREE_CLASS* wsk_temp_drzewo = poczatek_arr_tree;
                if ( szukane_drzewo_id <= ( koniec_arr_tree->get_id_drzewa() / 2 )  )
                {
                    while ( (czy_koniec == 0 ) && (wsk_temp_drzewo != koniec_arr_tree ) )
                    {
                        if ( wsk_temp_drzewo->get_id_drzewa() == szukane_drzewo_id )
                        {
                            czy_koniec =1 ;
                            czy_znaleziono =1;
                            wsk_do_drzewa_wynik = wsk_temp_drzewo;
                        } else
                        {
                            if ( ( wsk_temp_drzewo->get_id_drzewa() < szukane_drzewo_id ) && ( szukane_drzewo_id < wsk_temp_drzewo->get_next_tree()->get_id_drzewa()  ) )
                            {
                                czy_koniec = 1;
                                czy_znaleziono = 0;
                                wsk_do_drzewa_wynik = NULL;
                            } else
                            {
                                wsk_temp_drzewo = wsk_temp_drzewo->get_next_tree();
                            }

                        }
                    }

                } else
                {
                    wsk_temp_drzewo = koniec_arr_tree;
                    while ( (czy_koniec == 0 ) && (wsk_temp_drzewo != poczatek_arr_tree ) )
                    {
                        if ( wsk_temp_drzewo->get_id_drzewa() == szukane_drzewo_id )
                        {
                            czy_koniec =1 ;
                            czy_znaleziono =1;
                            wsk_do_drzewa_wynik = wsk_temp_drzewo;
                        } else
                        {
                            if ( ( wsk_temp_drzewo->get_prev_tree()->get_id_drzewa() < szukane_drzewo_id ) && ( szukane_drzewo_id < wsk_temp_drzewo->get_id_drzewa() )  )
                            {
                                czy_koniec = 1;
                                czy_znaleziono=0;
                                wsk_do_drzewa_wynik = NULL;
                            } else
                            {
                                wsk_temp_drzewo = wsk_temp_drzewo->get_prev_tree();
                            }

                        }
                    }

                }

            } else
            {
                czy_koniec = 1 ;
            }

        }
    }

    return wsk_do_drzewa_wynik;

}






void GARDEN_CLASS::cloneTree(unsigned int klonowane_drzewo_id) {


    TREE_CLASS* wsk_do_szukanego_drzewa = getTreePointer(klonowane_drzewo_id);


        //wsk_do_szukanego_drzewa = getTreePointer(klonowane_drzewo_id);
        if ( wsk_do_szukanego_drzewa != NULL )
        {

            TREE_CLASS* temp_nowy = new TREE_CLASS(*wsk_do_szukanego_drzewa);
            temp_nowy->set_wsk_do_ogrodu_w_drzewie(this);



            n_galezi += wsk_do_szukanego_drzewa->get_n_galezi_drzewa() ;
            n_owocow += wsk_do_szukanego_drzewa->get_n_owocow_drzewa() ;
            waga_owocow += wsk_do_szukanego_drzewa->get_waga_owocow_drzewa() ;

            this->plantTree_wstaw_drzewo_juz_zrobione(temp_nowy);
            //temp_nowy->set_id_drzewa( wsk_do_szukanego_drzewa->get_id_drzewa() );


        } else
        {
            return;
        }



}


// ///////////////////////////////////////////////////////////////


