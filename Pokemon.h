/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: Pokemon.h
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This header file is used to declare the member variable, methods, etc. defined in Pokemon.cpp.
* Last Changed: November 28, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <iostream>

class Pokemon
{
  private:
    std::string m_americanName;
    std::string m_japaneseName;
    int m_index;

  public:
    /**
    @param: None
    @pre: The pokemon exists
    @post: get the index of Pokemon object
    */
    int getIndex() const;

    /**
    @param: None
    @pre: The pokemon exists
    @post: get the American name of the Pokemon
    */
    std::string getAmericanName() const;

    /**
    @param: None
    @pre: The pokemon exists
    @post: get the Japanese name of the Pokemon
    */
    std::string getJapaneseName()const;

    /**
    @param: None
    @pre: None
    @post: creates a Pokemon instance
    */
    Pokemon();

    /**
    @param: The names and pokedex number of the pokemon
    @pre: the input file is open
    @post: set all the pokemon's variables to values in the input file
    */
    Pokemon (std::string AmericanName, int pokedex, std::string JapaneseName);

    /**
    @post: true if this pokemon's index is equal to other pokemon's index
    */
    bool operator==(const Pokemon& rhs)const;

    /**
    @post: true if this pokemon's index is smaller than other pokemon's index
    */
    bool operator<(const Pokemon& rhs)const;

    /**
    @post: true if this pokemon's index is higher than other pokemon's index
    */
    bool operator>(const Pokemon& rhs)const;

    /**
    @post: true if this pokemon's index is equal to an index key
    */
    bool operator==(int index)const;

    /**
    @post: true if this pokemon's index is lower than index key
    */
    bool operator<(int index)const;

    /**
    @post: true if this pokemon's index is higher than index key
    */
    bool operator>(int index)const;

    /**
    @Param: Pokemon object
    @post: prints the pokemon information
    */
    static void print(Pokemon poke);
};
#endif
