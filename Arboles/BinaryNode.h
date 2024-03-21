#ifndef __BINARYNODE__H__
#define __BINARYNODE__H__
template< class T >
class BinaryNode {
    protected:
        T data;
        BinaryNode <T> *leftChild;
        BinaryNode <T> *rightChild;
    public:
    BinaryNode();
        T& getData();
        void setData(T& val);
        BinaryNode <T>* getLeftChild();
        BinaryNode <T>* getRightChild();
        void setLeftChild(BinaryNode <T> *left);
        void setRightChild(BinaryNode <T> *right);
};

#include "BinaryNode.hxx"
#endif 