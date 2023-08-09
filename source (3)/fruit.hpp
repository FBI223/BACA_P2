//Marcin Sztukowski
#pragma once


using namespace std;

class BRANCH_CLASS;

class FRUIT_CLASS{

private:
    BRANCH_CLASS* wsk_do_galezi_w_owocu;
    unsigned int dlg_na_ktorej_rosnie_owoc;

    FRUIT_CLASS* next_fruit ;
    FRUIT_CLASS* prev_fruit ;

    unsigned int waga_fruit;

public:

    void display();

    FRUIT_CLASS();
    ~FRUIT_CLASS();
    FRUIT_CLASS( const FRUIT_CLASS & copy_from_me);
    FRUIT_CLASS( const FRUIT_CLASS * copy_from_me);
    FRUIT_CLASS(BRANCH_CLASS* wsk_do_galezi_w_owocu_podpiecie);

    BRANCH_CLASS* get_wsk_do_galezi_w_owocu(void);
    FRUIT_CLASS* get_next_fruit(void);
    FRUIT_CLASS* get_prev_fruit(void);
    unsigned int get_waga_fruit(void);
    unsigned int get_dlg_na_ktorej_rosnie_owoc(void);

    void set_wsk_do_galezi_w_owocu(BRANCH_CLASS* x);
    void set_next_fruit(FRUIT_CLASS* x);
    void set_prev_fruit(FRUIT_CLASS* x);
    void set_waga_fruit(unsigned int x);
    void set_dlg_na_ktorej_rosnie_owoc(unsigned int x);

    // /////////////////// metody do zadania


    unsigned int getLength(void);
    unsigned int getWeight(void);
    void growthFruit(void);
    void fadeFruit(void);
    void pluckFruit(void);

    BRANCH_CLASS* getBranchPointer(void);















// ///////////////////////// metody do zadania


};


