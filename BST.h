/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: BST.h
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This header file is used to declare the member variable, methods, etc. defined in BST.cpp.
* Last Changed: December 04, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#ifndef BST_H
#define BST_H

#include "BSTInterface.h"
#include "BNode.h"
#include <stdexcept>
#include <iostream>

template<typename ItemType, typename KeyType>
class BST : public BSTInterface<ItemType, KeyType>
{

  public:
    /**
      @param: None
      @pre: None
      @post: Construct a new BST object
    */
    BST();

    /**
      @param: None
      @pre: a BST exists
      @post: clear all the nodes of the tree
    */
    ~BST();

    /**
    @param: entry
    @pre: the entry is initialized
    @post: calls the private addHelper method
    @throw: gives an error if a pokemon already exists on that index
    */
    void add(ItemType entry);

    /**
    @param: key
    @pre: key is initialized
    @post: returns the pokemon information at the given index by calling the searchHelper method
    @throw: error if the entry does not exist
    */
    ItemType search(KeyType key) const;

    /**
    @param: None
    @pre: a BST existed
    @post: clear all the nodes of the BST
    */
    void clear();

    /**
    @param: visit function
    @pre: BST is not empty
    @post: calls the PostOrderHelper function
    */

    void visitPreOrder(void visit(ItemType)) const;

    /**
    @param: visit function
    @pre: BST is not empty
    @post: call the InOrderHelper function
    */
    void visitInOrder(void visit(ItemType)) const;

    /**
    @param: visit function
    @pre: BST is not e to an empty treempty
    @post: call the PostOrderHelper function
    */

    void visitPostOrder(void visit(ItemType)) const;
    /**
    @param: None
    @pre: BST is made and filled so that the root exists
    @post: return the root pointer of the tree
    */
    BNode<ItemType>* getRoot();

    /**
    @param: index of the node to be removed
    @pre: BST is not empty
    @post: removes that node from the tree while maintaing its structure
    */
    void remove(KeyType key);

    /**
    @param: BST by reference
    @pre: The BST to be copied exists
    @post: Creates a deep copy of the original tree
    */
    void copy(BST<ItemType, KeyType>& copyTree);

  private:

    BNode<ItemType>* m_root;
    /**
    @param: subtree pointer and key
    @pre: None
    @post: return node's entry
    @throw: error if entry does not exist
    */
    BNode<ItemType>* searchHelper(BNode<ItemType>* subtree, KeyType key) const;

    /**
    @param: entry and the subtree pointer
    @post: add a new Node to the tree
    @throw: error if entry at that index already exists
    */
    BNode<ItemType>* addHelper(ItemType entry, BNode<ItemType>* root);

    /**
    @param: subtree
    @post: delete all the nodes of the tree
    */
    void clearHelper(BNode<ItemType>* subtree);

    /**
    @param: a subtree pointer
    @post: returns the node with the smallest value
    */
    BNode<ItemType>* minValueNode(BNode<ItemType>* subtree);

    /**
    @param: a subtree pointer and visit function
    @post: Order -> print, traverse left, traverse right
    */
    void PreOrderHelper (BNode<ItemType>* subtree, void visit(ItemType)) const;

    /*
    @param: a subtree pointer, a void fuction that prints
    @post: Order -> traverse left, print, traverse right
    */
    void InOrderHelper (BNode<ItemType>* subtree, void visit(ItemType)) const;

    /*
    @param: a subtree pointer, a void function that prints
    @post: Order -> traverse Left, traverse Right, print
    */
    void PostOrderHelper (BNode<ItemType>* subtree, void visit(ItemType)) const;

    /**
    @param: a subtree pointer and a key to find the node
    @pre: The index exists on the tree
    @post: Removes the node from the tree
    */
    BNode<ItemType>* removeHelper(BNode<ItemType>* subtree, ItemType key);

    /**
    @param: pointer to the original tree and copy tree by reference
    @pre: The original tree to be copied exists
    @post: creates a deep copy of the original tree
    */
    void copyHelper(BNode<ItemType>* originalTree, BST<ItemType, KeyType>& copyTree);
};
#include "BST.cpp"
#endif
