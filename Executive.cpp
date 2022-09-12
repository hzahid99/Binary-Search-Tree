/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: Executive.cpp
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This file defines the member methods declared in Executive.h.
* Last Changed: December 04, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "Executive.h"
#include "Pokemon.h"
#include "BST.h"
#include "BSTInterface.h"

Executive::Executive(std::string fileName)
{
  m_fileName = fileName;
  std::ifstream inFile;
  inFile.open(m_fileName);
  if(inFile.is_open())
  {
    std::string tempAmericanName;
    std::string tempJapeneseName;
    int tempID;

    tree = new BST<Pokemon, int>();
    while(inFile >> tempAmericanName >> tempID >> tempJapeneseName)
    {
      Pokemon tempPokemon = Pokemon(tempAmericanName, tempID, tempJapeneseName);
      try
        {
          tree -> add(tempPokemon);
        }
      catch(std::runtime_error& rte)
        {
        std::cout<< rte.what() << "\n";
        }
    }
  }
  else
  {
    std::cout<<"ERROR: File could not be opened. Try again! \n";
    std::exit(-1);
  }
}

void Executive::run()
{
  int choice = 0;
  int totalTrees = 1;
  int choiceOfTree = 0;
  while(choice != 6)
  {
    BST<Pokemon, int>* temp = nullptr;
    temp = tree;

    std::cout<< "1) Add \n" ;
    std::cout<< "2) Search \n" ;
    std::cout<< "3) Print \n";
    std::cout<< "4) Copy the original tree \n";
    std::cout<< "5) Remove \n";
    std::cout<< "6) Exit \n";
    std::cout<<"Enter your choice: ";
    std::cin >> choice;
    std::cout << "\n";

    if (totalTrees == 2)
    {
      while (choiceOfTree != 1 && choiceOfTree != 2 && choice != 4 && choice != 6)
      {
        std::cout << "Which of the following trees would you like to interact with?\n";
        std::cout << "1) Original Tree\n";
        std::cout << "2) Copy Tree\nChoice: ";
        std::cin >> choiceOfTree;
        std::cout << "\n";
        if (choiceOfTree != 1 && choiceOfTree != 2)
        {
          std::cout << "\nInvalid choice made. Try again!\n\n";
        }
      }

      if (choiceOfTree == 1)
      {
        temp = tree;
      }

      else
      {
        temp = copyTree;
      }
      choiceOfTree = 0;
    }

    if(choice == 2)
    {
      int index;
      std::cout << "Enter an index to search: ";
      std::cin >> index;
      std::cout << "\n";
      try
      {
        Pokemon tempPokemon = temp -> search(index);
        std::cout << "--Pokemon Information--\n" << "American Name: " << tempPokemon.getAmericanName() << "\nJapanese Name: " << tempPokemon.getJapaneseName() << "\nPokedex Number: " << tempPokemon.getIndex() << "\n\n\n";
      }
      catch(std::runtime_error& rte)
      {
        std::cout << rte.what() << "\n";
      }
    }

    else if(choice == 1)
    {
      int pokedex;
      std::string name_US;
      std::string name_Japanese;

      std::cout << "Enter the following information of the pokemon you wish to add:\n";
      std::cout<<"American Name: ";
      std::cin >> name_US;
      std::cout<< "Pokedex Number (Index): ";
      std::cin >> pokedex;
      std::cout<< "Japanese Name: ";
      std::cin >> name_Japanese;

      Pokemon tempPokemon = Pokemon(name_US, pokedex, name_Japanese);
      try
      {
        temp -> add(tempPokemon);
        std::cout << "Pokemon added to the tree.\n\n";
      }
      catch(std::runtime_error& rte)
      {
        std::cout<< rte.what() << "\n";
      }
    }

    else if(choice == 3)
    {
      int choice = 0;
      std::cout << "In what order would you like to traverse the tree?\n";
      std::cout << "1) Pre-Order\n";
      std::cout << "2) In-Order\n";
      std::cout << "3) Post-Order\n";
      std::cout << "Choice: ";
      std::cin >> choice;
      std::cout << "\n";

      if(choice == 1)
      {
        temp -> visitPreOrder(Pokemon::print);
      }
      else if (choice == 2)
      {
        temp -> visitInOrder(Pokemon::print);
      }
      else if(choice == 3)
      {
        temp -> visitPostOrder(Pokemon::print);
      }
    }

    else if (choice == 5)
    {
      int index = 0;
      std::cout << "Enter the index/Pokedex number you want to remove: ";
      std::cin >> index;
      std::cout << "\n";
      try
      {
        temp -> remove(index);
        std::cout<< "The pokemon at index/pokedex number "<< index << " has been successfully removed.\n\n";
      }
      catch(std::runtime_error& rte)
      {
        std::cout << rte.what() << "\n";
      }
    }

    else if(choice == 4)
    {
      if (totalTrees == 1)
      {
        copyTree = new BST<Pokemon, int>();
        tree -> copy(*copyTree);
        totalTrees = 2;

        std::cout << "A copy has been made.\n\n";
      }
      else
      {
        std::cout<< "Only one copy of the original tree is allowed.\n\n";
      }
    }
  }
  delete tree;
  if (totalTrees > 1)
  {
    delete copyTree;
  }
}
