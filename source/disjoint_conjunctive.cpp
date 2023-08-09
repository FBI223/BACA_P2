//Marcin Sztukowski



bool Disjoint ( int integer_1 , int integer_2 )
{

    if ( (integer_1==0) || (integer_2 == 0)  )
    {
        return true;
    } else
    {
        if ( (integer_1 & integer_2) != 0 )
        {
            return false;

        } else
        {
            return true;
        }


    }



}

bool Conjunctive( int integer_1 , int integer_2 )
{

    if ( (integer_1==0) || (integer_2 == 0)  )
    {
        return false;
    } else
    {
        if ( (integer_1 & integer_2) != 0 )
        {
            return true;

        } else
        {
            return false;
        }


    }

}
