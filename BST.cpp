//
//  BST.cpp
//  TreeProject
//
//  Created by Toby Dragon on 11/13/14.
//  Copyright (c) 2014 Toby Dragon. All rights reserved.
//

#include <iostream>
#include "BST.h"

//Big O(1)
BST::BST(){
    root = nullptr;
}

//Big O(N)
void deleteSubTree(BTNode* current){
    if (current != nullptr) {
        deleteSubTree(current->getLeft());
        deleteSubTree(current->getRight());
        delete current;
    }
}

// O(n)
BTNode* copy_helper( BTNode* copy_from)
{
    if(copy_from == nullptr){
        return nullptr;
    } else{
        BTNode* copy_to= new BTNode(copy_from->getItem());
        copy_to->setLeft(copy_helper(copy_from->getLeft()));
        copy_to->setRight(copy_helper(copy_from->getRight()));
        return copy_to;

    }
}

BST::BST(const BST& treeToCopy){
    //TODO (consider calling a recursive function that takes a current node,
    //and returns a copy of that node and everything below it)
    root=::copy_helper( treeToCopy.root);



}

BST& BST::operator=(const BST& treeToCopy){
    //TODO (consider calling the same recursive functons used in destructor and copy constructor)
    if(this!=&treeToCopy){
        root=::copy_helper( treeToCopy.root);
    }
    return *this;

}

BST::~BST(){
    deleteSubTree(root);
}

//O (logN)
void add(BTNode* current,  int newValue){
    if (newValue == current->getItem()){
        throw DuplicateValueException();
    }
    else if (newValue < current->getItem()){
        BTNode* child = current->getLeft();
        if (child != nullptr){
            add(child, newValue);
        }
        else {
            current->setLeft(new BTNode(newValue));
        }
    }
    else { //newValue > current->getItem()
        BTNode* child = current->getRight();
        if (child != nullptr){
            add(child, newValue);
        }
        else {
            current->setRight(new BTNode(newValue));
        }
    }
}

void BST::add(int newValue){
    if (root == nullptr){
        root = new BTNode(newValue);
    }
    else {
        ::add(root, newValue);
    }
}


//O(n)
bool find(BTNode *current, int itemToFind) {
    if (current == nullptr){
        return false;
    }
    else {
        if (current->getItem() == itemToFind) {
            return true;
        } else if (current->getItem() > itemToFind) {
            return find(current->getLeft(), itemToFind);
        } else {
            return find(current->getRight(), itemToFind);
        }
    }
}

bool BST::find(int itemToFind) {
    return ::find(root, itemToFind);
}

//O(n)
void printInOrder(BTNode* current){
    if(current != nullptr){
        if(current->getLeft()!= nullptr){
            printInOrder(current->getLeft());

        }
        std::cout<<current->getItem()<<", ";
        if(current->getRight()!= nullptr){
            printInOrder(current->getRight());


        }
    }
    else{
        std::cout<<"The tree is empty\n";
    }

}

void BST::printInOrder(){
    ::printInOrder(root);
    std::cout<<"\n";
}

//O(n)
int itemCount(BTNode* current){
    int count = 1;
    if (current->getLeft() != nullptr) {
        count += itemCount(current->getLeft());
    }
    if (current->getRight() != nullptr) {
        count += itemCount(current->getRight());
    }
    return count;
}

int BST::itemCount(){
    if(root== nullptr){
        return 0;
    }
    else {
        return ::itemCount(root);
    }
}

//O(log N)
int height(BTNode* current){
    if(current== nullptr){
        return 0;
    }
    else {
        int lSide = height(current->getLeft());
        int rSide = height(current->getRight());

        if (rSide > lSide) {
            return rSide + 1;
        } else {
            return lSide + 1;
        }
    }
}

int BST::height(){
    return ::height(root)-1;
}

//O(n)
int max(BTNode* current){


    if(current== nullptr) {
        throw std::out_of_range("pass");
    }
    else if(current->getRight()== nullptr) {
        return current->getItem();
    }
    else {
        return max(current->getRight());
    }

}

int BST::max(){


        return ::max(root);

}







