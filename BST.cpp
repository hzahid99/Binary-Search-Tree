/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
* File name: BST.cpp
* Author: Huzaifa Zahid
* KUID: 3044791
* Email Address: huzaifazahid@ku.edu
* Homework Assignment Number: Lab-10
* Description: This file includes the definitions of the member methods, constructor, etc. declared in BST.h.
* Last Changed: December 03, 2021
-------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#include <iostream>

template<typename ItemType, typename KeyType>
BST<ItemType,KeyType>::~BST()
{
  if(m_root != nullptr)
  {
    clear();
  }
}

template<typename ItemType, typename KeyType>
BST<ItemType, KeyType>:: BST()
{
  m_root = nullptr;
}

template<typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>:: search(KeyType key) const
{
  BNode<ItemType>* result = searchHelper(m_root, key);
  if (result == nullptr)
  {
    throw (std::runtime_error("Pokemon not in the tree.\n"));
  }

  else
  {
    return result -> getEntry();
  }
}

template<typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>:: searchHelper(BNode<ItemType>* root, KeyType key) const
{
  if (root == nullptr || root -> getEntry() == key)
  {
    return root;
  }

  if (root -> getEntry() < key)
  {
    return searchHelper(root -> getRight(), key);
  }

  else
  {
    return searchHelper(root -> getLeft(), key);
  }
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::add(ItemType entry)
{
  m_root  = addHelper (entry, m_root);
}

template<typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType,KeyType>::addHelper(ItemType entry, BNode<ItemType>* root)
{
  if (root == nullptr)
  {
    return new BNode<ItemType>(entry);
  }
  if (entry == root -> getEntry())
  {
    throw(std::runtime_error("Duplicates are not allowed.\n"));
  }
  else if (entry < root -> getEntry())
  {
    root -> setLeft(addHelper(entry, root -> getLeft()));
  }
  else if (entry > root -> getEntry())
  {
    root -> setRight(addHelper(entry, root -> getRight()));
  }
  return root;
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::clear()
{
  clearHelper(m_root);
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>:: clearHelper(BNode<ItemType>* subtree)
{
  if(subtree != nullptr)
  {
    BNode<ItemType>* temp = subtree;
    clearHelper(subtree -> getLeft());
    clearHelper(subtree -> getRight());
    delete temp;
  }
}

template<typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>:: minValueNode(BNode<ItemType>* subtree)
{
  if(subtree -> getLeft() == nullptr)
  {
    return subtree;
  }
  return minValueNode(subtree -> getLeft());
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>:: visitPreOrder(void visit(ItemType)) const
{
  PreOrderHelper(m_root, visit);
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>:: PreOrderHelper(BNode<ItemType>*subtree, void visit(ItemType)) const
{
  if(subtree != nullptr)
  {
    visit(subtree -> getEntry());
    PreOrderHelper(subtree -> getLeft(), visit);
    PreOrderHelper(subtree -> getRight(), visit);
  }
  return;
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>:: visitInOrder(void visit(ItemType)) const
{
  InOrderHelper(m_root, visit);
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>:: InOrderHelper(BNode<ItemType>*subtree, void visit(ItemType)) const
{
  if(subtree != nullptr)
  {
    InOrderHelper(subtree -> getLeft(), visit);
    visit(subtree -> getEntry());
    InOrderHelper(subtree -> getRight(), visit);
  }
  return;
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>:: visitPostOrder(void visit(ItemType)) const
{
  PostOrderHelper(m_root, visit);
}

template<typename ItemType, typename KeyType>

void BST<ItemType, KeyType>:: PostOrderHelper(BNode<ItemType>*subtree, void visit(ItemType)) const
{
  if(subtree != nullptr)
  {
    PostOrderHelper(subtree -> getLeft(), visit);
    PostOrderHelper(subtree -> getRight(), visit);
    visit(subtree -> getEntry());
  }
  return;
}

template<typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>:: getRoot()
{
  return m_root;
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::remove (KeyType key)
{
	ItemType pokemon = search(key);
	removeHelper(m_root, pokemon);
}

template<typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>:: removeHelper(BNode<ItemType>* subtree, ItemType key)
{
	if (subtree == nullptr)
	{
		throw (std::runtime_error("Cannot remove a non-existent entry.\n"));
	}

	else if (subtree -> getEntry() < key)
	{
		subtree -> setRight(removeHelper(subtree-> getRight(), key)); 
	}

	else if (subtree -> getEntry() > key)
	{
		subtree -> setLeft(removeHelper(subtree-> getLeft(), key)); 
	}

	else
	{
		if (subtree -> getLeft() == nullptr && subtree -> getRight() == nullptr)
		{
			BNode<ItemType>* temp = subtree;
			subtree = nullptr;
			delete temp;
		}

		else if (subtree -> getLeft() == nullptr && subtree -> getRight() != nullptr)
		{
			BNode<ItemType>* temp = subtree -> getRight();
			delete subtree;
			return temp;
		}

		else if (subtree -> getLeft() != nullptr && subtree -> getRight() == nullptr)
		{
			BNode<ItemType>* temp = subtree -> getLeft();
			delete subtree;
			return temp;
		}

		else
		{
			BNode<ItemType>* temp = minValueNode(subtree -> getRight());
			subtree -> setEntry(temp -> getEntry());
			subtree -> setRight(removeHelper(subtree->getRight(), temp -> getEntry()));
		}
	}
	return subtree;
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::copy(BST<ItemType, KeyType>& copyTree)
{
  if(copyTree.getRoot() != nullptr)
  {
    copyTree.clear();
  }
  copyHelper(m_root, copyTree);
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::copyHelper(BNode<ItemType>* originalTree, BST<ItemType, KeyType>& copyTree)
{
  if(originalTree == nullptr)
  {
    return;
  }
  else
  {
    copyTree.add(originalTree -> getEntry());
    copyHelper(originalTree -> getLeft(), copyTree);
    copyHelper(originalTree -> getRight(), copyTree);
  }
}
