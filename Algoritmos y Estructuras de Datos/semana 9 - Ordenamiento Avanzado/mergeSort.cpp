#include <iostream>
#include <ctime>
#include "ShuffleYates.h"
#include "mergeSort.h"
using namespace std;

void printArreglo(int arr[], int n)
{
    for ( int i = 0; i < n; ++i )
    {
        cout << arr[i] << ' ';
    }
}

int main()
{
    //plantamos la semilla para los numeros aleatorios.
    srand(time(nullptr));
    int n;
    cout << "Ingrese el length del arreglo: "; cin >> n;
    int arr[n];

    //Lo inicializamos con numeros crecientes.
    for ( int i = 0; i < n; ++i )
    {
        arr[i] = i + 1;
    }

    cout << "Lo desordenamos el arreglo con SuffleYates\n";
    shuffleYates(arr, n);

    printArreglo(arr, n);

    cout << "\nLo ordenamos con Merge Sort\n";
    mergeSort(arr, 0, n-1);

    printArreglo(arr, n);

    return 0;
}