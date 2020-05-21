void merge(int arr[], int ini, int fin)
{
    int length = fin - ini + 1;
    int temp[length];

    int m = ( ini + fin ) / 2;
    int j = m + 1, k = ini; 

    for ( int i = 0; i < length; ++i )
    {
        if ( j > fin || ( k <= m && arr[k] < arr[j] ) )
        {
            temp[i] = arr[k++];
        }
        else
        {
            temp[i] = arr[j++];
        }
    }

    for ( int i = 0; i < length; ++i )
    {
        arr[ini+ i] = temp[i];
    }
}

void mergeSort(int arr[], int ini, int fin)
{
    if ( ini < fin )
    {
        int m = ini + ( fin - ini ) / 2;

        mergeSort(arr, ini, m);
        mergeSort(arr, m+1, fin);
        merge(arr, ini, fin);
    }
}