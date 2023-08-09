//Marcin Sztukowski
#pragma once


using namespace std;


class BRANCH_CLASS;

class GARDEN_CLASS;



class TREE_CLASS{

private:
    GARDEN_CLASS* wsk_do_ogrodu_w_drzewie;

    TREE_CLASS* next_tree;
    TREE_CLASS* prev_tree;

    BRANCH_CLASS* poczatek_arr_branch  ;
    BRANCH_CLASS* koniec_arr_branch  ;

    unsigned int id_drzewa;
    unsigned int wysokosc_drzewa;
    unsigned int n_galezi_aktualnie;
    unsigned int n_owocow_lacznie;
    unsigned int waga_owocow_lacznie;



public:

    void display();



    TREE_CLASS();
    ~TREE_CLASS();
    TREE_CLASS(const TREE_CLASS * copy_from_me);
    TREE_CLASS(const TREE_CLASS & copy_from_me);
    TREE_CLASS(GARDEN_CLASS* wsk_do_ogrodu_w_drzewie_podpiecie);

    unsigned int get_id_drzewa();
    unsigned int get_wys_drzewa();
    unsigned int get_n_galezi_drzewa();
    unsigned int get_n_owocow_drzewa();
    unsigned int get_waga_owocow_drzewa();
    GARDEN_CLASS* get_wsk_do_ogrodu_w_drzewie();
    TREE_CLASS* get_prev_tree();
    TREE_CLASS* get_next_tree();
    BRANCH_CLASS* get_koniec_arr_branch();
    BRANCH_CLASS* get_poczatek_arr_branch();


    void set_id_drzewa(unsigned int x);
    void set_wys_drzewa(unsigned int x);
    void set_n_galezi_drzewa(unsigned int x);
    void set_n_owocow_drzewa(unsigned int x);
    void set_waga_owocow_drzewa(unsigned int x);
    void set_prev_tree(TREE_CLASS* x);
    void set_next_tree(TREE_CLASS* x);
    void set_koniec_arr_branch(BRANCH_CLASS* x);
    void set_poczatek_arr_branch(BRANCH_CLASS* x);
    void set_wsk_do_ogrodu_w_drzewie(GARDEN_CLASS* x);

    void delete_last_galaz( ) ;
    void add_last_galaz() ;


    // /////////////////// metody do zadania


    unsigned int getBranchesTotal ( void );
    unsigned int getFruitsTotal ( void );
    unsigned int getWeightsTotal ( void ) ;
    unsigned int getNumber ( void );
    unsigned int getHeight ( void );
    void growthTree ( void );
    void fadeTree ( void );
    void harvestTree (unsigned int waga_owocu_do_zrywania );
    void cutTree (unsigned int nowa_wysokosc );
    void cloneBranch ( BRANCH_CLASS* kopiowany_branch );
    GARDEN_CLASS* getGardenPointer ( void );
    BRANCH_CLASS* getBranchPointer( unsigned int szukany_branch_na_wys );






// ///////////////////////// metody do zadania

};


