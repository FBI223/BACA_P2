//Marcin Sztukowski
#pragma once



template <typename KEY_TYPE , typename DATA_TYPE >
class NODE{
public:
    NODE* gora;
    NODE* prawa;
    NODE* lewa;

    KEY_TYPE klucz;
    DATA_TYPE wartosc;

    NODE(KEY_TYPE key, DATA_TYPE data) {
        this->klucz = key;
        this->wartosc = data;

        gora = NULL;
        prawa = NULL;
        lewa = NULL;
    }

    NODE() {


        gora = NULL;
        prawa = NULL;
        lewa = NULL;
    }


    ~NODE() {


        gora = NULL;
        prawa = NULL;
        lewa = NULL;
    }




};


template <typename KEY_TYPE , typename DATA_TYPE >
class QueueNode {
public:
    NODE<KEY_TYPE, DATA_TYPE>* wsk_node ;
    QueueNode<KEY_TYPE, DATA_TYPE>* next;

    QueueNode(NODE<KEY_TYPE, DATA_TYPE>* wsk )
    {
        this->wsk_node = wsk ;
        next = NULL;
    }

    ~QueueNode( )
    {
        this->wsk_node = NULL ;
        next = NULL;
    }

};

template <typename KEY_TYPE , typename DATA_TYPE >
class Queue {
public:

    QueueNode<KEY_TYPE, DATA_TYPE>* front ;
    QueueNode<KEY_TYPE, DATA_TYPE>* rear;

    Queue()
    {
        front=NULL ;
        rear=NULL ;
    }


    ~Queue()
    {
        if ( front != NULL )
        {
            QueueNode<KEY_TYPE, DATA_TYPE>* temp_wsk = this->front;
            while ( temp_wsk != NULL )
            {
                QueueNode<KEY_TYPE, DATA_TYPE>* usuwany = temp_wsk ;
                temp_wsk = temp_wsk->next ;
                delete usuwany ;

            }
        }
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(NODE<KEY_TYPE, DATA_TYPE>* data) {
        QueueNode<KEY_TYPE, DATA_TYPE>* newNode = new QueueNode<KEY_TYPE, DATA_TYPE>(data);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    NODE<KEY_TYPE, DATA_TYPE>* dequeue() {
        if (front == NULL)
            return NULL;

        QueueNode<KEY_TYPE, DATA_TYPE>* temp = front;
        NODE<KEY_TYPE, DATA_TYPE>* wsk_node_return = temp->wsk_node ;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;


        return wsk_node_return ;
    }

    NODE<KEY_TYPE, DATA_TYPE>* getFront() {
        if (front == NULL)
            return NULL;

        return front->data;
    }
};




template <typename KEY_TYPE , typename DATA_TYPE >
class BST{

public :

    NODE<KEY_TYPE , DATA_TYPE>* korzen;

    BST() {

        this->korzen = NULL;
    }


    void usuwanie_drzewa( NODE<KEY_TYPE,DATA_TYPE>* temp_wsk  )
    {
        if ( temp_wsk != NULL )
        {
            usuwanie_drzewa( temp_wsk->lewa ) ;
            usuwanie_drzewa( temp_wsk->prawa ) ;
            delete temp_wsk;
        }
    }

    ~BST()
    {
        if (this->korzen != NULL  )
        {
            usuwanie_drzewa(this->korzen );
            this->korzen = NULL;
        }
    }



    DATA_TYPE* Search(KEY_TYPE klucz_in )
    {
        DATA_TYPE* wynik_wsk = NULL;

        if (this->korzen != NULL )
        {
            NODE<KEY_TYPE,DATA_TYPE>* temp_wsk = this->korzen ;

            bool czy_znaleziono = false;
            bool czy_koniec = false ;
            while ( czy_koniec == false && temp_wsk != NULL )
            {

                if (  !(temp_wsk->klucz < klucz_in ) && !( klucz_in < temp_wsk->klucz  )  )
                {
                    wynik_wsk = &temp_wsk->wartosc;
                    czy_koniec = true ;
                } else
                {

                    if ( klucz_in < temp_wsk->klucz )
                    {
                        temp_wsk = temp_wsk->lewa;
                    } else
                    {
                        temp_wsk = temp_wsk->prawa ;
                    }
                }
            }

        }


        return wynik_wsk;
    }


    bool Insert(KEY_TYPE klucz_in, DATA_TYPE wartosc_in )
    {
        bool czy_wstawiono = false;
        bool czy_istnieje_juz = false;
        bool czy_mozna_wstawic = false;


        if (this->korzen != NULL  )
        {

            NODE<KEY_TYPE,DATA_TYPE>* wynik_wyszukiwania = Search_node( klucz_in ) ;
            NODE<KEY_TYPE,DATA_TYPE>* temp_wsk = this->korzen ;

            if ( wynik_wyszukiwania == NULL )
            {

                while ( czy_wstawiono == false && czy_istnieje_juz == false && temp_wsk != NULL )
                {

                    if (  !(temp_wsk->klucz<klucz_in) && !(klucz_in<temp_wsk->klucz)  )
                    {
                        czy_istnieje_juz = true;
                        czy_wstawiono=false;

                    } else
                    {

                        if ( klucz_in < temp_wsk->klucz )
                        {
                            if ( temp_wsk->lewa == NULL )
                            {
                                temp_wsk->lewa = new NODE<KEY_TYPE,DATA_TYPE>(klucz_in , wartosc_in) ;
                                temp_wsk->lewa->gora = temp_wsk;
                                czy_mozna_wstawic = true ;

                            }
                            temp_wsk = temp_wsk->lewa ;
                        } else
                        {
                            if ( temp_wsk->prawa == NULL )
                            {
                                temp_wsk->prawa = new NODE<KEY_TYPE,DATA_TYPE>(klucz_in , wartosc_in) ;
                                temp_wsk->prawa->gora = temp_wsk;
                                czy_mozna_wstawic = true ;


                            }
                            temp_wsk = temp_wsk->prawa;
                        }
                    }
                }

                if ( czy_mozna_wstawic  )
                {
                    czy_wstawiono = true ;
                    czy_istnieje_juz= false;
                }
            }

        } else
        {
            this->korzen = new NODE<KEY_TYPE,DATA_TYPE>(klucz_in , wartosc_in) ;
            czy_wstawiono = true ;
        }

        return czy_wstawiono;
    }


    NODE<KEY_TYPE,DATA_TYPE>* Search_node(KEY_TYPE klucz_in )
    {
        NODE<KEY_TYPE,DATA_TYPE>* wynik_wsk = NULL;
        if (this->korzen != NULL )
        {
            NODE<KEY_TYPE,DATA_TYPE>* temp_wsk = this->korzen ;

            bool czy_znaleziono = false;
            bool czy_koniec = false ;
            while ( czy_koniec == false && temp_wsk != NULL )
            {

                if (  !(temp_wsk->klucz < klucz_in) && !( klucz_in < temp_wsk->klucz)  )
                {
                    wynik_wsk = temp_wsk;
                    czy_koniec = true ;
                } else
                {

                    if ( klucz_in < temp_wsk->klucz )
                    {
                        temp_wsk = temp_wsk->lewa;
                    } else
                    {
                        temp_wsk = temp_wsk->prawa ;
                    }
                }
            }
        }

        return wynik_wsk;
    }


    NODE<KEY_TYPE,DATA_TYPE>* wyszukaj_min_node( NODE<KEY_TYPE,DATA_TYPE>* wskazany_node )
    {
        NODE<KEY_TYPE,DATA_TYPE>* wynik_wsk = NULL;

        if ( wskazany_node != NULL )
        {
            while (  wskazany_node->lewa != NULL  )
            {
                wskazany_node = wskazany_node->lewa ;
            }
            wynik_wsk = wskazany_node ;
        }
        return wynik_wsk;

    }

    NODE<KEY_TYPE,DATA_TYPE>* wyszukaj_nastepnik( NODE<KEY_TYPE,DATA_TYPE>* wskazany_node )
    {
        NODE<KEY_TYPE,DATA_TYPE>* wynik_wsk = NULL;

        if ( wskazany_node != NULL )
        {
            if ( wskazany_node->prawa != NULL )
            {
                wynik_wsk = wyszukaj_min_node( wskazany_node->prawa ) ;
            } else
            {
                NODE<KEY_TYPE,DATA_TYPE>* rodzic_wsk = wskazany_node->gora ;
                while ( ( rodzic_wsk != NULL  ) && ( wskazany_node == rodzic_wsk->prawa ) )
                {
                    wskazany_node = rodzic_wsk;
                    rodzic_wsk = rodzic_wsk->gora ;
                }
                wynik_wsk = rodzic_wsk ;
            }
        }
        return wynik_wsk;
    }



    bool Delete(KEY_TYPE klucz_in)
    {
        bool czy_usunieto = false;
        NODE<KEY_TYPE,DATA_TYPE>* usuwany_wsk = Search_node(klucz_in) ;

        if ( usuwany_wsk != NULL )
        {
            czy_usunieto = true ;
            NODE<KEY_TYPE,DATA_TYPE>* usuwany_wsk_rodzic = usuwany_wsk->gora ;

            if ( usuwany_wsk->lewa == NULL && usuwany_wsk->prawa == NULL )
            {
                if ( usuwany_wsk_rodzic == NULL ) // jedyny wezel w drzewie
                {
                    delete usuwany_wsk;
                    this->korzen = NULL;

                } else
                {
                    if ( usuwany_wsk_rodzic->lewa == usuwany_wsk )
                    {
                        usuwany_wsk_rodzic->lewa = NULL;
                    } else if ( usuwany_wsk_rodzic->prawa == usuwany_wsk )
                    {
                        usuwany_wsk_rodzic->prawa = NULL;
                    }

                    usuwany_wsk->gora = NULL;
                    delete usuwany_wsk;
                }
            } else if ( usuwany_wsk->lewa != NULL && usuwany_wsk->prawa == NULL )
            {
                if ( usuwany_wsk_rodzic != NULL )
                {
                    if ( usuwany_wsk_rodzic->lewa == usuwany_wsk )
                    {
                        usuwany_wsk_rodzic->lewa = usuwany_wsk->lewa;

                    } else if ( usuwany_wsk_rodzic->prawa == usuwany_wsk )
                    {
                        usuwany_wsk_rodzic->prawa = usuwany_wsk->lewa;
                    }
                    usuwany_wsk->lewa->gora = usuwany_wsk_rodzic ;
                } else
                {
                    this->korzen = usuwany_wsk->lewa ;
                    usuwany_wsk->lewa->gora = NULL;
                }
                delete usuwany_wsk;

            } else if (  usuwany_wsk->lewa == NULL && usuwany_wsk->prawa != NULL )
            {
                if ( usuwany_wsk_rodzic != NULL )
                {
                    if ( usuwany_wsk_rodzic->lewa == usuwany_wsk )
                    {
                        usuwany_wsk_rodzic->lewa = usuwany_wsk->prawa;
                    } else if ( usuwany_wsk_rodzic->prawa == usuwany_wsk )
                    {
                        usuwany_wsk_rodzic->prawa = usuwany_wsk->prawa;
                    }
                    usuwany_wsk->prawa->gora = usuwany_wsk_rodzic ;
                } else
                {
                    this->korzen = usuwany_wsk->prawa ;
                    usuwany_wsk->prawa->gora = NULL;
                }
                delete usuwany_wsk;

            } else
            {
                NODE<KEY_TYPE,DATA_TYPE>* nastepnik_usuwanego = wyszukaj_nastepnik(usuwany_wsk) ;
                if ( nastepnik_usuwanego != NULL )
                {
                    usuwany_wsk->klucz = nastepnik_usuwanego->klucz;
                    usuwany_wsk->wartosc = nastepnik_usuwanego->wartosc;

                    if ( nastepnik_usuwanego->prawa != NULL )
                    {
                        if ( nastepnik_usuwanego->gora->lewa == nastepnik_usuwanego )
                        {
                            nastepnik_usuwanego->gora->lewa = nastepnik_usuwanego->prawa ;
                            nastepnik_usuwanego->prawa->gora = nastepnik_usuwanego->gora ;
                        } else if ( nastepnik_usuwanego->gora->prawa == nastepnik_usuwanego )
                        {
                            nastepnik_usuwanego->gora->prawa = nastepnik_usuwanego->prawa ;
                            nastepnik_usuwanego->prawa->gora = nastepnik_usuwanego->gora; // to mzoe byc zle
                        }
                    } else
                    {
                        if ( nastepnik_usuwanego->gora->lewa == nastepnik_usuwanego )
                        {
                            nastepnik_usuwanego->gora->lewa = NULL ;
                        } else if ( nastepnik_usuwanego->gora->prawa == nastepnik_usuwanego )
                        {
                            nastepnik_usuwanego->gora->prawa = NULL ;
                        }
                    }
                    delete nastepnik_usuwanego ;
                }
            }

        }

        return czy_usunieto ;
    }


    void PreOrder_help( NODE<KEY_TYPE,DATA_TYPE>* node_wsk )
    {
        if ( node_wsk == NULL )
        {
            return;
        }
        cout << node_wsk->klucz ;
        cout << node_wsk->wartosc ;

        PreOrder_help(node_wsk->lewa) ;
        PreOrder_help(node_wsk->prawa) ;
    }

    void PreOrder(  )
    {
        PreOrder_help(this->korzen) ;
    }

    void InOrder_help( NODE<KEY_TYPE,DATA_TYPE>* node_wsk )
    {
        if ( node_wsk == NULL )
        {
            return;
        }

        InOrder_help(node_wsk->lewa) ;

        cout << node_wsk->klucz ;
        cout << node_wsk->wartosc ;

        InOrder_help(node_wsk->prawa) ;
    }

    void InOrder(  )
    {
        InOrder_help(this->korzen) ;
    }


    void PostOrder_help( NODE<KEY_TYPE,DATA_TYPE>* node_wsk )
    {
        if ( node_wsk == NULL )
        {
            return;
        }

        PostOrder_help(node_wsk->lewa) ;
        PostOrder_help(node_wsk->prawa) ;

        cout << node_wsk->klucz ;
        cout << node_wsk->wartosc ;

    }

    void PostOrder(  )
    {
        PostOrder_help(this->korzen) ;
    }

    void LevelOrder( )
    {

        if (this->korzen != NULL )
        {
            Queue<KEY_TYPE,DATA_TYPE> kolejka = Queue<KEY_TYPE,DATA_TYPE>() ;
            kolejka.enqueue(this->korzen) ;

            while ( kolejka.isEmpty() == false )
            {
                NODE<KEY_TYPE,DATA_TYPE>* curr_node =  kolejka.dequeue();
                cout << curr_node->klucz ;
                cout << curr_node->wartosc ;


                if ( curr_node->lewa != NULL )
                {
                    kolejka.enqueue(curr_node->lewa) ;
                }

                if ( curr_node->prawa != NULL )
                {
                    kolejka.enqueue(curr_node->prawa) ;
                }

            }

        }


    }



    int height(NODE<KEY_TYPE,DATA_TYPE>* node) {
        if (node == NULL) {
            return -1;
        } else {
            int leftHeight = height(node->lewa);
            int rightHeight = height(node->prawa);

            if ( rightHeight < leftHeight )
            {
                return (leftHeight+1) ;
            } else
            {
                return (rightHeight+1) ;
            }

        }
    }

    int Height()
    {
        int wys_wynik = height(this->korzen ) ;
        return wys_wynik ;
    }


};


