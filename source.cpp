//Marcin Sztukowski

#include <iostream>
#include <string>

using namespace std;


// KLASY OGOLNE


//class ARENA_CLASS;
//class BERSERKER_CLASS;
//class BEAST_CLASS;
//class CAESAR_CLASS;
//class HUMAN_CLASS;
//class SQUAD_CLASS;
//class PLAYER_CLASS;



class PLAYER_CLASS{

protected:
    unsigned int health_max;
    unsigned int health_curr;
    unsigned int agility;
    unsigned int strenght;

    PLAYER_CLASS* prev;
    PLAYER_CLASS* next;

    virtual void die ()
    {
        health_curr = 0;
    }


public:

    friend class CAESAR_CLASS;
    friend class SQUAD_CLASS;



    virtual string get_id()
    {
        return "";
    }
    virtual void printParams ()
    {
        return ;
    }

    virtual unsigned int get_max_health()
    {
        return health_max;
    }

    virtual unsigned int get_curr_health(){
        return health_curr;
    };

    virtual unsigned int getRemainingHealth () //
    {
        if ( health_curr == 0  )
        {
            return 0 ;
        } else
        {
            return (health_curr*100/health_max)  ;
        }

    }
    virtual unsigned int getDamage ()
    {
        return strenght;
    }
    virtual unsigned int getAgility ()
    {
        return agility;
    }
    virtual void takeDamage ( unsigned int dmg_taken)
    {
        if ( dmg_taken >= health_curr )
        {
            this->die();
        } else
        {
            health_curr -= dmg_taken ;
        }
    }
    virtual void applyWinnerReward () // ?
    {
        strenght += 2;
        agility += 2;
    }
    virtual void cure ()
    {
        health_curr = health_max;
    }



};



class CAESAR_CLASS
{
protected:
    unsigned int ilosc_osodow;
    unsigned int ilosc_atakow;

public:

    friend class ARENA_CLASS;

    void judgeDeathOrLife ( PLAYER_CLASS* ptr_player)
    {

        if ( ptr_player->getRemainingHealth() == 0 )
        {
            ptr_player->die();
        } else
        {
            ilosc_osodow++;
            if ( ((ilosc_atakow/2)*2) == ilosc_atakow )
            {
                //ilosc_osodow++;
                if ( ((ilosc_osodow/3)*3) == ilosc_osodow )
                {
                    ptr_player->die();
                    //cout << "umar " << ptr_player->get_id()<<"    ile uderzen  " <<ilosc_atakow <<"    ile osadow"<< ilosc_osodow << endl;
                }
            }

        }

    }


};




class ARENA_CLASS
{

private:
    CAESAR_CLASS cezar;

public:

    ARENA_CLASS( CAESAR_CLASS* ptr_cezar )
    {

        cezar = CAESAR_CLASS() ;
        cezar.ilosc_osodow= ptr_cezar->ilosc_osodow;
        //cezar.ilosc_osodow = 0 ;
        cezar.ilosc_atakow= 0 ;
    }

    void fight ( PLAYER_CLASS* ptr_player_1, PLAYER_CLASS* ptr_player_2 )
    {

        PLAYER_CLASS* p1;
        PLAYER_CLASS* p2;


        if ( ptr_player_1->getAgility() >= ptr_player_2->getAgility() )
        {
            p1 = ptr_player_1;
            p2 = ptr_player_2;
        } else if ( ptr_player_1->getAgility() < ptr_player_2->getAgility() )
        {
            p1 = ptr_player_2;
            p2 = ptr_player_1;
        }

        unsigned int temp_rem_helth_p1 = 0;
        unsigned int temp_rem_helth_p2 = 0;

        temp_rem_helth_p1 = ptr_player_1->getRemainingHealth() ;
        temp_rem_helth_p2 = ptr_player_2->getRemainingHealth() ;


        if ( ( temp_rem_helth_p1 != 0 ) && ( temp_rem_helth_p2 != 0 ) )
        {
            p1->printParams();
            p2->printParams();

            int czy_koniec =  0;
            int czy_zyje_p1 = 1;
            int czy_zyje_p2 = 1;

            cezar.ilosc_atakow = 0 ;

            while  (czy_koniec == 0)
            {

                p2->takeDamage( p1->getDamage() );
                p2->printParams();
                cezar.ilosc_atakow++;

                temp_rem_helth_p2 = p2->getRemainingHealth();

                if ( ( temp_rem_helth_p2 < 10) || (cezar.ilosc_atakow == 40)  )
                {
                    czy_koniec = 1 ;
                    if ( temp_rem_helth_p2 == 0 )
                    {
                        czy_zyje_p2 = 0;
                        cezar.judgeDeathOrLife( p2 );
                    }
                } else
                {
                    p1->takeDamage( p2->getDamage() );
                    p1->printParams();
                    cezar.ilosc_atakow++;
                    temp_rem_helth_p1 = p1->getRemainingHealth();

                    if ( (temp_rem_helth_p1 < 10) || (cezar.ilosc_atakow == 40)  )
                    {
                        czy_koniec = 1 ;
                        if ( temp_rem_helth_p1 == 0 )
                        {
                            czy_zyje_p1 = 0;
                            cezar.judgeDeathOrLife( p1 );
                        }
                    }
                }

            }

            if ( czy_zyje_p1==1 )
            {
                cezar.judgeDeathOrLife( p1 ) ;
                p1->printParams();
                if ( p1->getRemainingHealth() == 0 )
                {
                    czy_zyje_p1 = 0;
                } else
                {
                    p1->applyWinnerReward();
                    p1->cure();

                }
            }

            if ( czy_zyje_p2 == 1 )
            {
                cezar.judgeDeathOrLife( p2 );
                p2->printParams();
                if ( p2->getRemainingHealth() == 0 )
                {
                    czy_zyje_p2 = 0;
                } else
                {
                    p2->applyWinnerReward();
                    p2->cure();

                }
            }

            p1->printParams(); // mozliwe ze zla kolejnosc wyswetlania najpuierw judgdzea potem printparams moze
            p2->printParams();


            cezar.ilosc_atakow=0;
        }

    }

};



// KLASY WALCZACE


class HUMAN_CLASS : public virtual PLAYER_CLASS
{

protected:

    string id_human;
    unsigned int defense;
    void die ()
    {
        health_curr = 0;
    }



public:
    friend class SQUAD_CLASS;


    string get_id() {
        return id_human;
    }

    HUMAN_CLASS( string id_human_in )
    {
        id_human = id_human_in;
        health_max = 200;
        health_curr = health_max;
        strenght = 30;
        agility=10;
        defense=10;

        prev=NULL;
        next=NULL;

    }



    void printParams ()
    {
        unsigned int remaining_hp = this->getRemainingHealth();
//        const unsigned int id_len = id_human.length();
//        char id_char[id_len] ;
//        for ( int i = 0 ; i < id_len ; i++ )
//        {
//            id_char[i] = id_human[i];
//        }


        if ( remaining_hp == 0 )
        {
            //std::printf("%s:R.I.P.\n",id_human.c_str());
            cout << id_human << ":R.I.P." << endl ;
        } else
        {
            cout << id_human << ":" << health_max << ":" << health_curr << ":" << remaining_hp << "%:" << strenght << ":" << agility << ":" << defense << endl;

            //std::printf( "%s:%u:%u:%u%%:%u:%u:%u\n",id_human.c_str(),health_max,health_curr,remaining_hp,strenght,agility,defense );
        }

    }


    void takeDamage ( unsigned int dmg_taken)
    {
        unsigned int actual_dmg = dmg_taken;
        if ( defense >= actual_dmg )
        {
            actual_dmg=0;
        } else
        {
            actual_dmg -= defense;
            if ( agility >= actual_dmg )
            {
                actual_dmg=0;
            } else
            {
                actual_dmg -= agility;
            }
        }

        if ( actual_dmg >= health_curr )
        {
            this->die();
        } else
        {
            health_curr -= actual_dmg ;
            if ( this->getRemainingHealth() == 0 )
            {
                this->die();
            }
        }
    }


};



class BEAST_CLASS : public virtual PLAYER_CLASS
{

protected:

    string id_beast;
    void die ()
    {
        health_curr = 0;
    }



public:


    string get_id() {
        return id_beast;
    }



    friend class SQUAD_CLASS;

    BEAST_CLASS( string id_beast_in )
    {
        id_beast = id_beast_in;
        health_max = 150;
        health_curr = health_max;
        strenght = 40;
        agility=20;

        prev=NULL;
        next=NULL;

    }

    void printParams ()
    {
        unsigned int remaining_hp = this->getRemainingHealth();
        if ( remaining_hp == 0 )
        {
            //std::printf("%s:R.I.P.\n",id_beast.c_str());
            cout << id_beast << ":R.I.P." << endl;
        } else{
            if ( remaining_hp < 25 )
            {
                cout << id_beast << ":" << health_max << ":" << health_curr << ":" << remaining_hp << "%:" << (strenght*2) << ":" << agility  << endl;

                //std::printf( "%s:%u:%u:%u%%:%u:%u\n",id_beast.c_str(),health_max,health_curr,remaining_hp,strenght*2,agility );

            } else
            {
                cout << id_beast << ":" << health_max << ":" << health_curr << ":" << remaining_hp << "%:" << strenght << ":" << agility  << endl;

                //std::printf( "%s:%u:%u:%u%%:%u:%u\n",id_beast.c_str(),health_max,health_curr,remaining_hp,strenght,agility );

            }

        }

    }

    unsigned int getDamage ()
    {

        if (this->getRemainingHealth() < 25 )
        {
            return 2*strenght;
        } else
        {
            return strenght;
        }

    }

    void takeDamage ( unsigned int dmg_taken)
    {
        unsigned int actual_dmg = dmg_taken;

        if ( agility/2 >= actual_dmg )
        {
            actual_dmg=0;
        } else
        {
            actual_dmg -= ( agility / 2 ) ;
        }

        if ( actual_dmg >= health_curr )
        {
            this->die();
        } else
        {
            health_curr -= actual_dmg ;
            if ( this->getRemainingHealth() == 0 )
            {
                this->die();
            }
        }

    }


};






class BERSERKER_CLASS : public HUMAN_CLASS , public BEAST_CLASS
{

protected:


    void die ()
    {
        health_curr = 0;
    }


public:
    friend class SQUAD_CLASS;

    string get_id() {

        unsigned int remaining_hp = this->getRemainingHealth();
        string wynik = "";
        if ( remaining_hp  == 0  )
        {
            wynik = id_human;
        } else if ( (remaining_hp > 0) && ( remaining_hp < 25 ) )
        {
            wynik = id_beast;
        } else
        {
            wynik = id_human;
        }
        return wynik;

    }


    BERSERKER_CLASS( string id_berserker_human_in , string id_berserker_beast_in  ) : HUMAN_CLASS(id_berserker_human_in) ,
                                                                                      BEAST_CLASS(id_berserker_beast_in)
    {

//        HUMAN_CLASS::id_human = id_berserker_human_in;
//        BEAST_CLASS::id_beast = id_berserker_beast_in;

        health_max = 200;
        health_curr = health_max;
        strenght = 35;
        agility=5;
        defense=15;

        prev=NULL;
        next=NULL;
    }


    void printParams ()
    {
        unsigned int remaining_hp = this->getRemainingHealth();

        if ( remaining_hp  == 0  )
        {
            HUMAN_CLASS::printParams() ;
        } else if ( (remaining_hp > 0) && ( remaining_hp < 25 ) )
        {
            BEAST_CLASS::printParams();
        } else
        {
            HUMAN_CLASS::printParams();
        }

    }

    void takeDamage ( unsigned int dmg_taken)
    {
        unsigned int remaining_hp = this->getRemainingHealth();

        if ( (remaining_hp > 0) && ( remaining_hp < 25 ) )
        {
            BEAST_CLASS::takeDamage(dmg_taken) ;
        } else
        {
            HUMAN_CLASS::takeDamage(dmg_taken);
        }
    }

    unsigned int getDamage()
    {
        unsigned int wynik = 0;
        unsigned int remaining_hp = this->getRemainingHealth();

        if ( (remaining_hp > 0) && ( remaining_hp < 25 ) )
        {
            wynik = BEAST_CLASS::getDamage() ;
        } else
        {
            wynik = HUMAN_CLASS::getDamage() ;
        }
        return wynik;
    }

};









class SQUAD_CLASS : public virtual PLAYER_CLASS
{
protected:

    void die ()
    {
        strenght = 0 ;
        health_curr = 0 ;
        health_max = 0 ;
        agility = 0 ;

        first = NULL;
        last=NULL;
        n_zespolu = 0 ;

    }

    //unsigned int health_all;
    string id_squad;
    PLAYER_CLASS* first;
    PLAYER_CLASS* last;
    unsigned int n_zespolu;


public:

    SQUAD_CLASS(string id_squad_in)
    {
        id_squad=id_squad_in;
        n_zespolu=0;
        first=NULL;
        last=NULL;

        agility=0;
        health_max=0;
        health_curr=0;
        strenght=0;
    }


    string get_id() {
        return id_squad;
    }

    void addPlayer( PLAYER_CLASS* player_added  )
    {

        if ( player_added->getRemainingHealth() > 0  )
        {
            if ( first == NULL )
            {
                first=player_added;
                last=player_added;

                player_added->prev=NULL;
                player_added->next=NULL;

                health_curr=player_added->health_curr;
                health_max=player_added->health_max;

                agility= player_added->agility; // najmniejsze agility
                strenght = player_added->strenght;

                n_zespolu = 1 ;
            } else
            {
                int czy_znaleziono_kopie = 0 ;
                PLAYER_CLASS* temp = first;

                for ( int i = 0 ;  ( temp != NULL ) && (i < n_zespolu) ; i++ )
                {
                    if ( temp == player_added )
                    {
                        czy_znaleziono_kopie = 1;
                        temp = NULL;
                    } else
                    {
                        temp = temp->next;
                    }
                }


                if ( czy_znaleziono_kopie == 0 )
                {

                    last->next=player_added;
                    player_added->prev=last;
                    player_added->next=NULL;
                    last=player_added;

                    health_curr+=player_added->health_curr;
                    health_max+=player_added->health_max;

                    if ( player_added->agility < this->agility )
                    {
                        this->agility = player_added->agility;
                        this->strenght += player_added->strenght;
                    }

                    n_zespolu += 1 ;
                }

            }

        }


    }


    unsigned int getRemainingHealth ()
    {

        if (  ( first == NULL ) || ( n_zespolu==0 ) )
        {
            return 0 ;
        } else
        {
            unsigned int wynik = 0;
            PLAYER_CLASS* temp_playa = first;
            wynik = temp_playa->getRemainingHealth();
            temp_playa = temp_playa->next;
            if ( temp_playa != NULL )
            {
                for ( int i = 1 ; i < n_zespolu ; i++ )
                {
                    if ( temp_playa->getRemainingHealth() > wynik )
                    {
                        wynik = temp_playa->getRemainingHealth();
                    }

                    temp_playa = temp_playa->next;
                }

            }


            return wynik;
        }

    }
    unsigned int getDamage ()
    {
        unsigned int wynik = 0 ;
        PLAYER_CLASS* temp_playa = first;
        for ( int i = 0 ; i < n_zespolu ; i++ )
        {
            wynik += temp_playa->getDamage() ;
            temp_playa = temp_playa->next;
        }

        return wynik;

    }
    unsigned int getAgility ()
    {

        unsigned int wynik = 0 ;
        PLAYER_CLASS* temp_playa = first;
        if ( temp_playa != NULL )
        {
            wynik = temp_playa->agility;
            temp_playa = temp_playa->next;
        }

        for (int i = 1 ; i < n_zespolu ; i++ )
        {
            if ( temp_playa->agility < wynik )
            {
                wynik = temp_playa->agility ;
            }
            temp_playa = temp_playa->next;
        }

        return wynik;
    }


    void usun_typa(PLAYER_CLASS* player_usuwany)
    {
        if ( player_usuwany== first && player_usuwany == last)
        {
            first = NULL;
            last = NULL;
        } else
        {
            if ( player_usuwany == first )
            {
                first = first->next ;
                first->prev = NULL;
            } else if ( player_usuwany == last )
            {
                last = last->prev;
                last->next = NULL;
            } else
            {
                player_usuwany->prev->next = player_usuwany->next;
                player_usuwany->next->prev = player_usuwany->prev;
            }
        }
    }

    void takeDamage ( unsigned int dmg_taken) {
        unsigned int actual_dmg = dmg_taken / n_zespolu;
        if (actual_dmg > 0) {
            const unsigned int n_zespolu_const = n_zespolu;
            unsigned int ile_usunietych = 0 ;
            PLAYER_CLASS *temp_czlonek = first;
            for (int i = 0; i < n_zespolu_const; i++) {
                temp_czlonek->takeDamage(actual_dmg);
                if (temp_czlonek->getRemainingHealth() == 0) {
                    ile_usunietych++;
                    temp_czlonek->die();
                    usun_typa( temp_czlonek );
                }

                temp_czlonek = temp_czlonek->next;
            }
            n_zespolu -= ile_usunietych;
        }

    }


    void swapp( PLAYER_CLASS* player_1 , PLAYER_CLASS* player_2 )
    {
        if ( first == player_1 )
        {
            first = player_2;
        }

        if ( last == player_2 )
        {
            last = player_1;
        }

        player_1->next = player_2->next;
        player_2->prev = player_1->prev;

        player_1->prev = player_2;
        player_2->next = player_1;

        if ( player_2->prev != NULL )
        {
            player_2->prev->next = player_2;
        }

        if ( player_1->next != NULL )
        {
            player_1->next->prev = player_1;
        }


    }

    void sortuj( )
    {
        PLAYER_CLASS* temp_czlonek = first;

        unsigned int czy_swap_rob = 0 ;
        unsigned int czy_koniec = 0 ;
        unsigned int ile_swapow = 0 ;
        for ( int i = 0 ; (i < n_zespolu ) && ( czy_koniec == 0 ) ; ++i)
        {
            ile_swapow = 0 ;
            temp_czlonek = first;
            for ( int j = 0 ; j < n_zespolu - 1 - i ; ++j )
            {
                //cout <<  "  j : " << j  <<  "    j : " << temp_czlonek->get_id() << "   j + 1 :  " << temp_czlonek->next->get_id()  << "       j  > j +1 : ? "<< (temp_czlonek->get_id() < temp_czlonek->next->get_id() ) <<  endl;
                czy_swap_rob = 0 ;
                if ( temp_czlonek->get_id() > temp_czlonek->next->get_id() )
                {
                    czy_swap_rob = 1 ;
                } else if ( temp_czlonek->get_id() == temp_czlonek->next->get_id() )
                {
                    if ( temp_czlonek->get_max_health() > temp_czlonek->next->get_max_health() )
                    {
                        czy_swap_rob = 1 ;
                    } else if ( temp_czlonek->get_max_health() == temp_czlonek->next->get_max_health() )
                    {
                        if ( temp_czlonek->get_curr_health() > temp_czlonek->next->get_curr_health() )
                        {
                            czy_swap_rob = 1 ;
                        } else if ( temp_czlonek->get_curr_health() == temp_czlonek->next->get_curr_health() )
                        {
                            if ( temp_czlonek->getRemainingHealth() > temp_czlonek->next->getRemainingHealth() )
                            {
                                czy_swap_rob=1;
                            } else if ( temp_czlonek->getRemainingHealth() == temp_czlonek->next->getRemainingHealth() )
                            {
                                if ( temp_czlonek->getDamage() > temp_czlonek->next->getDamage() )
                                {
                                    czy_swap_rob = 1;
                                } else if ( temp_czlonek->getDamage() == temp_czlonek->next->getDamage() )
                                {
                                    if ( temp_czlonek->getAgility() > temp_czlonek->next->getAgility() )
                                    {
                                        czy_swap_rob = 1 ;
                                    } else
                                    {
                                        czy_swap_rob = 0;
                                    }
                                }
                            }
                        }
                    }
                }

                if ( czy_swap_rob == 1 )
                {
                    swapp( temp_czlonek, temp_czlonek->next );
                    ile_swapow++;
                } else
                {
                    temp_czlonek = temp_czlonek->next ;
                }


            }

//            if ( ile_swapow == 0 )
//            {
//                czy_koniec = 1 ;
//            }

        }

    }

    void printParams() // przy wyswietlaniu usuwasz martwych typow
    {


        if ( n_zespolu == 0  )
        {
            //std::printf("%s:nemo\n",id_squad.c_str()) ;
            cout << id_squad << ":nemo" <<  endl;
        } else if ( n_zespolu > 0  )
        {
            this->sortuj();

            unsigned int agility_p = this->getAgility();
            unsigned int strength_p = this->getDamage();
            unsigned int rem_hp_p = this->getRemainingHealth();

            //std::printf("%s:%u:%u:%u:%u\n",id_squad.c_str(),n_zespolu,rem_hp_p,strength_p,agility_p);
            cout << id_squad << ":" << n_zespolu << ":" << rem_hp_p << "%:" << strength_p << ":" << agility_p << endl;

            PLAYER_CLASS* temp_playa = first;
            for ( int i = 0 ; i < n_zespolu ; i++ )
            {
                temp_playa->printParams();
                temp_playa = temp_playa->next;
            }
        }



    }


    void applyWinnerReward ()
    {
        PLAYER_CLASS* temp_playa = first;
        for ( int i = 0 ; i < n_zespolu ; i++ )
        {
            temp_playa->applyWinnerReward();
            temp_playa = temp_playa->next;
        }

    }
    void cure ()
    {
        PLAYER_CLASS* temp_playa = first;
        for ( int i = 0 ; i < n_zespolu ; i++ )
        {
            temp_playa->cure();
            temp_playa = temp_playa->next;
        }
    }


};



// metody




