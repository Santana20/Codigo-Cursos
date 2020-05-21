#include <cstdlib>

void shuffleYates(int arr[], int n)
{
    //OJO, el i no puede ser 0, ya que, si fuera 0, j no tomaria ningun valor y el programa se cae(debido al funcionamiento de rand()).
    // un numero entre 0 y 0 no existe, por eso j no toma valor.
    for ( int i = n - 1; i > 0; --i )
    {
        int j = rand() % i;
        if ( i != j )
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } 
    }
    
}