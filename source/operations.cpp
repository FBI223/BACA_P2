//Marcin Sztukowski


void Union(int integer_1 , int integer_2, int* integer_3)
{
    *integer_3 = integer_1 | integer_2 ;
}

void Intersection(int integer_1 , int integer_2, int* integer_3)
{
    *integer_3 = integer_1 & integer_2 ;
}


void Symmetric(int integer_1 , int integer_2, int* integer_3)
{
    *integer_3 = integer_1 ^ integer_2 ;
}

void Difference(int integer_1 , int integer_2, int* integer_3)
{
    int temp_czesc_wspolna = integer_1 & integer_2 ;
    *integer_3 = integer_1 ^ temp_czesc_wspolna;
}


void Complement(int integer_1 , int* integer_2)
{

    *integer_2 = ~integer_1 ;
}

