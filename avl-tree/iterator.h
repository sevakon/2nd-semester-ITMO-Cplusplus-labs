//
//  iterator.h
//  avl-tree
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef iterator_h
#define iterator_h

#include "avl.h"

template <class T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    size_t height;
    Node* parent;
};

template <class T>
class TreeIterator {
private:
    Node<T> *node = nullptr;
    
public:
    //constructors
    TreeIterator(){}
    TreeIterator(Node<T> *x) : node(x) {}
    TreeIterator(const TreeIterator& other) : node(other.node) {}
    
    //tree traversals
    TreeIterator& operator++() {
        Node<T> *temp = node->right;
        if (temp) {
            while(temp->left) temp = temp->left;
        } else {
            Node<T>* prev = node;
            temp = node->parent;
            while(temp) {
                if (temp->left == prev)
                    break;
                prev = temp;
                temp = temp->parent;
            }
        }
        node = temp;
        return *this;
    }
    
    
    //overloading comparison operators
    bool operator==(const TreeIterator& other) const {return node == other.node;}
    bool operator!=(const TreeIterator& other) const {return node != other.node;}
    
    //get node's value
    T& operator*() {return node->data;}
};



#endif /* iterator_h */
