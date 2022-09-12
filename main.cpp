/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: main.cpp
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This file calls the Executive run() function to implement the pokemon BST.
* Last Changed: November 28, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include "Pokemon.h"
#include "Executive.h"

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters passed!\n";
    return(0);
  }

  else
  {
    std::string fileName = argv[1];
    Executive exec(fileName);
    exec.run();
  }
  return(0);
}
