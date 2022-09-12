/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: BNode.cpp
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This file includes the definitions of the member methods, constructor, etc. declared in BNode.h.
* Last Changed: November 28, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
template <typename ItemType>
BNode<ItemType>:: BNode(const ItemType entry)
{
  m_entry = entry;
  m_left = nullptr;
  m_right = nullptr;
}

template <typename ItemType>
ItemType BNode<ItemType>:: getEntry()
{
  return m_entry;
}

template <typename ItemType>
BNode<ItemType>* BNode<ItemType>:: getLeft()
{
  return m_left;
}

template <typename ItemType>
BNode<ItemType>* BNode<ItemType>:: getRight()
{
  return m_right;
}

template <typename ItemType>
void BNode<ItemType>:: setEntry(const ItemType entry)
{
  m_entry = entry;
}

template <typename ItemType>
void BNode<ItemType>:: setLeft(BNode<ItemType>* left)
{
  m_left = left;
}

template <typename ItemType>
void BNode<ItemType>:: setRight(BNode<ItemType>* right)
{
  m_right = right;
}
