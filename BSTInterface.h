/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: BSTInterface.h
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This interface defines all virtual methods that will be used by BST Class.
* Last Changed: November 28, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#ifndef BSTINTERFACE_H
#define BSTINTERFACE_H

template <typename ItemType, typename KeyType>
class BSTInterface
{
    public:
    virtual ~BSTInterface(){}
    virtual void add(ItemType entry) = 0; //throws std::runtime_error if duplicate added
    virtual ItemType search(KeyType key) const = 0; //throws std::runtime_error if not in tree
    virtual void clear() = 0; //Empties the tree
    virtual void remove(KeyType key) = 0; //throws std::runtime_error if not in tree

    //For the following methods, each method will take a function as a parameter
    //These function then call the provided function on every entry in the tree in the appropriate order (i.e. pre, in, post)
    //The function you pass in will need to a static method
    virtual void visitPreOrder(void visit(ItemType)) const = 0; //Visits each node in pre order
    virtual void visitInOrder(void visit(ItemType)) const = 0; //Visits each node in in order
    virtual void visitPostOrder(void visit(ItemType)) const = 0; //Visits each node in post order
};
#endif
