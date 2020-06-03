#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    BST<int>* bst = new BST<int>();

    bst->insertar(1);
    bst->insertar(12);
    bst->insertar(34);
    bst->insertar(61);
    bst->insertar(85);
    bst->insertar(52);
    bst->insertar(92);
    bst->insertar(2);
    bst->insertar(6);
    bst->insertar(10);
    bst->insertar(45);
    bst->insertar(78);
    bst->insertar(96);
    bst->insertar(33);
    bst->insertar(10);
    bst->insertar(71);
    bst->insertar(8);
    bst->insertar(13);

    cout << bst->size() << endl;
    auto print = [](int x) { cout << x << " "; };
    bst->preorder(print); cout << endl;
    bst->postorder(print); cout << endl;
    bst->inorder(print); cout << endl;   

    cout << (bst->buscar(52) ? "YES" : "NO") << endl;
    cout << (bst->buscar(100) ? "YES" : "NO") << endl;
    
    delete bst;
    return 0;
}
