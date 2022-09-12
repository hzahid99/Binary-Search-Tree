/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: BNode.h
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This header file is used to declare the member variable, pointer, methods, etc. defined in BNode.cpp.
* Last Changed: November 28, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#ifndef BNODE_H
#define BNODE_H

template <typename ItemType>

class BNode
{

  private:
    ItemType m_entry;
    BNode<ItemType>* m_left;
    BNode<ItemType>* m_right;

  public:

    /*
    @param: node's entry
    @pre: entry is initialized
    @post: entry is stored in the binary node
    */
    BNode(ItemType entry);

    /*
    @param: None
    @pre: non-empty binary node
    @post: return the value/info at that node
    */
    ItemType getEntry();

    /*
    @param: None
    @pre: None (Since even if the left subtree is empty, it exists in a binary search tree but just points to null)
    @post: return the left pointer of a node
    */
    BNode<ItemType>* getLeft();

    /*
    @param: None
    @pre: None
    @post return the right pointer of a node
    */
    BNode<ItemType>* getRight();

    /*
    @param: entry
    @pre: entry is initialized
    @post: set value to m_entry
    */
    void setEntry(ItemType entry);

    /*
    @param: a Binary node
    @pre: the type of entry has been initialized
    @post: set the left pointer to a node
    */
    void setLeft(BNode<ItemType>* left);

    /*
    @param: a Binary node
    @pre: the type of entry has been initialized
    @post: set the Right pointer to a node
    */
    void setRight(BNode<ItemType>*right);

};
#include "BNode.cpp"
#endif
