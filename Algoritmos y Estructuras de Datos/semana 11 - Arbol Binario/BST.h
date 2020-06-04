#ifndef simpleBST_H
#define simpleBST_H
#include <functional>

template<typename T>
class BST
{
    struct Nodo
    {
        T elem;
        Nodo* left;
        Nodo* right;
        Nodo(T el) : elem(el), left(nullptr), right(nullptr) {} 
    };
    Nodo* root;
    int length;
public:
    BST() : root(nullptr), length(0) {}

    ~BST()
    {
        clear(root);
    }

    int size()
    {
        return this->length;
    }

    bool insertar(T elem)
    {
        if ( !add(this->root, elem) ) return false;
        this->length++;
        return true;

    }

    bool buscar(T elem)
    {
        return find(root, elem);
    }

    void preorder( std::function<void(T)> proc )
    {
        preorder(this->root, proc);
    }

    void postorder( std::function<void(T)> proc )
    {
        postorder(this->root, proc);
    }

    void inorder( std::function<void(T)> proc )
    {
        inorder(this->root, proc);
    }

    T mayorArbol()
    {
        return getMayor(this->root);
    }

    void eliminarNodo(T elem)
    {
        Nodo* eliminar = root;
        Nodo* auxPadre = nullptr;
        bool leftchild;
        //buscamos el nodo
        while( eliminar != nullptr )
        {
            if ( elem == eliminar->elem ) break;
            else if ( elem < eliminar->elem )
            {
                auxPadre = eliminar;
                leftchild = true;
                eliminar = eliminar->left;
            }
            else
            {
                auxPadre = eliminar;
                leftchild = false;
                eliminar = eliminar->right;
            }
        }

        if ( eliminar == nullptr ) return;

        //si no tiene hijo izquierdo, solo eliminamos y subimso el derecho
        if ( eliminar->left == nullptr )
        {
            if ( auxPadre == nullptr )
            {
                this->root = eliminar->right;
            }
            else if ( leftchild )
            {
                auxPadre->left = eliminar->right;
            }
            else auxPadre->right = eliminar->right;

            delete eliminar;
            return;
        }

        //Si existe hijo izquierdo buscamos el mayor de ese subarbol izquierdo
        Nodo* aux2 = eliminar->left;
        Nodo* aux2Padre = eliminar;
        leftchild = true;
        while( aux2->right != nullptr )
        {
            aux2Padre = aux2;
            leftchild = false;
            aux2 = aux2->right;
        }

        eliminar->elem = aux2->elem;
        if ( leftchild ) aux2Padre->left = aux2->left;
        else aux2Padre->right = aux2->left;

        delete aux2;
    }
private:
    void clear(Nodo* node)
    {
        if ( node != nullptr )
        {
            this->clear(node->left);
            this->clear(node->right);
            delete node;
        }
    }

    bool add(Nodo* &node, T elem)
    {
        if ( node == nullptr ) 
        {
            node = new Nodo(elem);
            return true;
        }
        else
        {
            if ( elem == node->elem ) return false;
            else if ( elem < node->elem )
            {
                return add(node->left, elem);
            }
            else return add(node->right, elem);
        }   
    }

    bool find(Nodo* node, T elem)
    {
        if (node == nullptr) return false;
        else if (elem == node->elem) return true;
        else if ( elem < node->elem ) return find(node->left, elem);
        else return find(node->right, elem);
    }

    void preorder( Nodo* node, std::function<void(T)> proc )
    {
        if ( node != nullptr )
        {
            proc(node->elem);
            preorder(node->left, proc);
            preorder(node->right, proc);
        }
    }

    void postorder( Nodo* node, std::function<void(T)> proc )
    {
        if ( node != nullptr )
        {
            postorder(node->left, proc);
            postorder(node->right, proc);
            proc(node->elem);
        }
    }

    void inorder( Nodo* node, std::function<void(T)> proc )
    {
        if ( node != nullptr )
        {
            inorder(node->left, proc);
            proc(node->elem);
            inorder(node->right, proc);
        }
    }
    
    T getMayor(Nodo* node)
    {
        if ( node->right == nullptr ) return node->elem;
        getMayor(node->right);
    }
};

#endif