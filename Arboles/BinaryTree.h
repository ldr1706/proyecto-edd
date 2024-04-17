#ifndef __BINARYTREE__H__
#define __BINARYTREE__H__
#include "BinaryNode.h"

template <class T>
class BinaryTree{
    protected:
        NodoBinario<T> *root;
    public:
    BinaryTree();
        bool empty();
        T& getRoot();
        int height();
        int size();
        void insert(T& val);

        bool delete(T& val);
        void search(T& val);
        void preOrder();
        void inOrder();
        void posOrder();
        void levelOrder();
};

#include "BinaryTree.hxx"
#endif 
