//
//  avl.h
//  avl-tree
//
//  Created by Владимир Коняхин on 31/05/2019.
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef avl_h
#define avl_h

#include "iterator.h"

template <class T, class Compare = std::less<T>>
class AVL {
private:
    Node<T>* root = nullptr;
    
    Compare comp = Compare();
    
    Node<T>* find(Node<T>* temp, const T &key) {
        if (!temp) return nullptr;
        if (comp(temp->data, key)) return find(temp->right, key);
        if (temp->data != key) return find(temp->left, key);
        
        return temp;
    }
    
    size_t size(Node<T>* temp) const {
        if (temp == nullptr) return 0;
        return 1 + size(temp->left) + size(temp->right);
    }
    
    void makeEmpty(Node<T>* temp) {
        if (temp == nullptr) return;
        makeEmpty(temp->left);
        makeEmpty(temp->right);
        delete temp;
    }
    
    Node<T>* insert(T x, Node<T>* t) {
        if(t == nullptr) {
            t = new Node<T>;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data) {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data) {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }
        
        t->height = std::max(height(t->left), height(t->right))+1;
        return t;
    }
    
    Node<T>* singleRightRotate(Node<T>* &t) {
        Node<T>* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = std::max(height(t->left), height(t->right))+1;
        u->height = std::max(height(u->left), t->height)+1;
        return u;
    }
    
    Node<T>* singleLeftRotate(Node<T>* &t) {
        Node<T>* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = std::max(height(t->left), height(t->right))+1;
        u->height = std::max(height(t->right), t->height)+1 ;
        return u;
    }
    
    Node<T>* doubleLeftRotate(Node<T>* &t) {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }
    
    Node<T>* doubleRightRotate(Node<T>* &t) {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    
    
    
    Node<T>* findMin(Node<T>* t) {
        if(t == nullptr)
            return nullptr;
        else if(t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }
    
    Node<T>* findMax(Node<T>* t) {
        if(t == nullptr)
            return nullptr;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    
    Node<T>* remove(int x, Node<T>* t) {
        Node<T>* temp;
        
        // Element not found
        if(t == nullptr) return NULL;
        
        // Searching for element
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        
        // Element found
        // With 2 children
        else if(t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        // With one or zero child
        else {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if (t == NULL)
            return t;
        
        t->height = std::max(height(t->left), height(t->right))+1;
        
        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == 2) {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2) {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    }
    
    size_t height(Node<T>* temp) {
        return (temp == nullptr ? -1 : temp->height);
    }
    
    size_t getBalance(Node<T>* temp) {
        if(temp == nullptr) return 0;
        else return height(temp->left) - height(temp->right);
    }
    
    void inorder(Node<T>* temp) {
        if (temp == nullptr) return;
        inorder(temp->left);
        std::cout << temp->data << " ";
        inorder(temp->right);
    }
    
    void out(Node<T>* v) {
        if(v == nullptr) return;
        std::cout << "\nparent : " << v->data;
        if(v->left) std::cout << "\nleft : " << v->left->data;
        if(v->right) std::cout << "\nright : " << v->right->data;
        out(v->left);
        out(v->right);
        }
    
public:
    Node<T>* getRoot() {
        return root;
    }
    
    TreeIterator<T> begin() {
        if (!root) return TreeIterator<T>();
        Node<T>* temp = root;
        while(temp->left)
            temp = temp->left;
        
        return TreeIterator<T>(temp);
    }
    
    TreeIterator<T> end() {
        return TreeIterator<T>();
    }
    
    
    AVL() {};
    
    AVL(const AVL &t){}
    
    AVL& operator=(const AVL &);
    
    template<class InputIt>
    void assign(InputIt first, InputIt last);
    
    TreeIterator<T> insert(const T &value) {
        root = insert(value, root);
        return TreeIterator<T>(root);
    }
    
    TreeIterator<T> remove(const T &value) {
        root = remove(value, root);
        return TreeIterator<T>(root);
    }
    
    TreeIterator<T> find(const T &value){
        return TreeIterator<T>(find(root, value));
    }
    
    bool empty() const {
        if (root) return false;
        return true;
    }
    
    size_t size() const {
        return size(root);
    }
    
    void show() {
        out(getRoot());
    }

    friend class TreeIterator<T>;
};

#endif /* avl_h */
