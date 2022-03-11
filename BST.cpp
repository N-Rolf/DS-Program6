/********************************************************************
***  NAME       :Neil Rolf                                        ***
***  CLASS      :CSc 300                                          ***
***  ASSIGNMENT :Program 6                                        ***
***  DUE DATE   :03/11/2022                                       ***
***  INSTRUCTOR :Kurtenbach                                       ***
*********************************************************************
***  DESCRIPTION :Binary Search Tree for handling video data      ***
********************************************************************/
#include <iostream>
#include <iomanip>
#include "BST.h"
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void BST::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                  
   else if (newNode->title < nodePtr->title)
      insert(nodePtr->left, newNode);     
   else 
      insert(nodePtr->right, newNode);    
}

//**********************************************************
// insertNode creates a new node to hold video data,       *
// and passes it to the insert function.                   *
//**********************************************************

void BST::insertNode(string t, int l, int v)
{
   TreeNode *newNode = nullptr;

   newNode = new TreeNode;
   newNode->title = t;
   newNode->likes = l;
   newNode->views = v;
   newNode->left = newNode->right = nullptr;

   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void BST::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via in order traversal. *
//****************************************************************

void BST::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << setw(45) << std::left << nodePtr->title;
      cout << setw(12) << std::left << nodePtr->likes;
      cout << setw(12) << std::left << nodePtr->views << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayRoot member function displays the values           *
// in the root node                                              *
//****************************************************************

void BST::displayRoot(TreeNode *root)
{
   if(root)
   {
      cout << "\nTitle in root node: " << "\"" << root->title << "\"" << endl;
   }
}

//****************************************************************
// The displayTotal member function displays the summed values   *
// of likes and views data                                       *
//****************************************************************

void BST::displayTotal(TreeNode *nodePtr)
{
   if(nodePtr)
   {
      displayTotal(nodePtr->left);
      likeTotal += nodePtr->likes;
      viewTotal += nodePtr->views;
      displayTotal(nodePtr->right);
   }
}