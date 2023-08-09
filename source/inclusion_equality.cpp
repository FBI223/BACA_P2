//Marcin Sztukowski


bool Inclusion(int integer_1 , int integer_2)
{
    if ( (integer_1 | integer_2) == integer_2 )
    {
        return true;
    } else
    {
        return false;
    }


}


bool Equality(int integer_1 , int integer_2)
{

    if ( integer_1 == integer_2 )
    {
        return true ;
    } else
    {
        return false;
    }

}
