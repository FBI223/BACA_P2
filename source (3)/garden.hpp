//Marcin Sztukowski
#pragma once

using namespace std;

class TREE_CLASS;

struct integer_wlasny;

class GARDEN_CLASS{

private:

    TREE_CLASS* poczatek_arr_tree  ;
    TREE_CLASS* koniec_arr_tree  ;

    unsigned int n_drzew;
    unsigned int n_galezi;
    unsigned int n_owocow;
    unsigned int waga_owocow;



public:

    void plantTree_wstaw_drzewo_juz_zrobione( TREE_CLASS* wstawiaj_to_drzewo );
    void display();

    GARDEN_CLASS();
    ~GARDEN_CLASS();


    TREE_CLASS* get_poczatek_arr_tree();
    TREE_CLASS* get_koniec_arr_tree();
    unsigned int get_n_drzew();
    unsigned int get_n_galezi();
    unsigned int get_n_owocow();
    unsigned int get_waga_owocow();

    void set_poczatek_arr_tree(TREE_CLASS* x);
    void set_koniec_arr_tree(TREE_CLASS* x);
    void set_n_drzew(unsigned int x);
    void set_n_galezi(unsigned int x);
    void set_n_owocow(unsigned int x);
    void set_waga_owocow(unsigned int x);




    // /////////////////// metody do zadania


    unsigned int getTreesTotal();
    unsigned int getBranchesTotal();
    unsigned int getWeightsTotal();
    unsigned int getFruitsTotal();

    void plantTree ( void );
    void extractTree ( unsigned int );


    void growthGarden ( void );
    void fadeGarden ( void );
    void harvestGarden (unsigned int waga_owocu_do_zrywaniaa);
    TREE_CLASS* getTreePointer (unsigned int szukane_drzewo_id );
    void cloneTree (unsigned int klonowane_drzewo_id );









// ///////////////////////// metody do zadania


};

