//Marcin Sztukowski
#pragma once

using namespace std;

class TREE_CLASS;
class FRUIT_CLASS;

class BRANCH_CLASS{

private:
    TREE_CLASS* wsk_do_drzewa_w_galezi;
    unsigned int wysokosc_na_ktorej_rosnie_galaz;

    BRANCH_CLASS* next_branch;
    BRANCH_CLASS* prev_branch;

    FRUIT_CLASS* poczatek_arr_fruit;
    FRUIT_CLASS* koniec_arr_fruit  ;

    unsigned int n_owocow_akt;
    unsigned int waga_owocow;
    unsigned int dlugosc_galezi;


public:

    void display();


    TREE_CLASS* get_wsk_do_drzewa_w_galezi(void);
    BRANCH_CLASS* get_next_branch(void);
    BRANCH_CLASS* get_prev_branch(void);
    FRUIT_CLASS* get_poczatek_arr_fruit(void);
    FRUIT_CLASS* get_koniec_arr_fruit(void);
    unsigned int get_n_owocow_akt(void);
    unsigned int get_waga_owocow(void);
    unsigned int get_wysokosc_na_ktorej_rosnie_galaz(void);
    unsigned int get_dlugosc_galezi();

    void set_wsk_do_drzewa_w_galezi(TREE_CLASS* x);
    void set_next_branch(BRANCH_CLASS* x);
    void set_prev_branch(BRANCH_CLASS* x);
    void set_poczatek_arr_fruit(FRUIT_CLASS* x);
    void set_koniec_arr_fruit(FRUIT_CLASS* x);
    void set_n_owocow_akt(unsigned int x);
    void set_waga_owocow(unsigned int x);
    void set_wysokosc_na_ktorej_rosnie_galaz(unsigned int x);
    void set_dlugosc_galezi(unsigned int x);


    BRANCH_CLASS();
    ~BRANCH_CLASS();
    BRANCH_CLASS(const BRANCH_CLASS * copy_from_me);
    BRANCH_CLASS(const BRANCH_CLASS & copy_from_me);
    BRANCH_CLASS(TREE_CLASS* wsk_do_drzewa_w_galezi_podpiecie);

    // /////////////////// metody do zadania


    unsigned int getFruitsTotal ( void );
    unsigned int getWeightsTotal ( void );
    unsigned int getHeight ( void );
    unsigned int getLength ( void );
    void growthBranch ( void );
    void fadeBranch ( void );
    void harvestBranch ( unsigned int waga_usuwana);
    void cutBranch ( unsigned int nowa_dlugosc);
    FRUIT_CLASS* getFruitPointer (unsigned int szukany_owoc_dlg_na_galezi );
    TREE_CLASS* getTreePointer ( void );





// ///////////////////////// metody do zadania

};

