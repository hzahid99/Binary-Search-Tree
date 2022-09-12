/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: Executive.h
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This header file declares the member methods defined in Executive.cpp.
* Last Changed: November 28, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "BST.h"
#include "Pokemon.h"
#include <string>
#include <iostream>
#include <stdexcept>

class Executive
{
  private:
    std::string m_fileName;
    BST<Pokemon, int>* tree;
    BST<Pokemon, int>* copyTree;

  public:
  /**
  @param: file name that was passed as command-line argument
  @pre: the file exists
  @post: Creates a BST and fills it in by opening the input file and reading in all the data from it
  */
    Executive(std::string fileName);

  /**
  @param: None
  @pre: a binary search tree exists
  @post: Prints the entry at user-input index
  */
    void run();
};
#endif
