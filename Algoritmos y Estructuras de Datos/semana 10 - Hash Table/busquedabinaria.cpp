#include <iostream>

using namespace std;
int binsearch(int* numeros, int elem)
{
    int l = 0, r = 9;
    while( r - l >= 0 )
    {
        int m = ( l + r ) / 2;

        if ( numeros[m] == elem ) 
        {
            return m;
        }

        if ( numeros[m] < elem ) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main()
{
    int numeros[10] = { 6, 12, 19, 25, 31, 35, 42, 51, 53, 62 };
    int quiero;
    cin >> quiero;

    cout << binsearch(numeros, quiero);

    return 0;
}