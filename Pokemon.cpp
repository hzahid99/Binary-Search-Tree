/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: Pokemon.cpp
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This file includes the definitions of the member methods, constructor, etc. declared in Pokemon.h.
* Last Changed: November 28, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon()
{
  m_americanName = " ";
  m_index = 0;
  m_japaneseName = " ";
}

Pokemon::Pokemon(std::string AmericanName, int pokedex, std::string JapaneseName)
{
  m_americanName = AmericanName;
  m_index = pokedex;
  m_japaneseName = JapaneseName;
}

int Pokemon:: getIndex()const
{
  return m_index;
}

std::string Pokemon::getAmericanName()const
{
  return m_americanName;
}

std::string Pokemon::getJapaneseName()const
{
  return m_japaneseName;
}

bool Pokemon::operator==(const Pokemon& rhs)const
{
  return(m_index == rhs.getIndex());
}

bool Pokemon::operator<(const Pokemon& rhs)const
{
  return(m_index < rhs.getIndex());
}

bool Pokemon::operator>(const Pokemon& rhs)const
{
  return(m_index > rhs.getIndex());
}

bool Pokemon::operator==(int index)const
{
  return(m_index == index);
}

bool Pokemon::operator<(int index)const
{
  return(m_index < index);
}

bool Pokemon::operator>(int index)const
{
  return(m_index > index);
}

void Pokemon::print(Pokemon poke)
{
  std::cout << "--Pokemon Information--\n" << "American Name: " << poke.getAmericanName() << "\nJapanese Name: " << poke.getJapaneseName() << "\nPokedex Number: " << poke.getIndex() << "\n\n\n";
}
