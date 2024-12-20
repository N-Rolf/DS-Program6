// Implementation file for the IntBinaryTree class
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
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->title < nodePtr->title)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void BST::insertNode(string t, int l, int v)
{
   TreeNode *newNode = nullptr;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->title = t;
   newNode->likes = l;
   newNode->views = v;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
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
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

// bool BST::searchNode(int num)
// {
//    TreeNode *nodePtr = root;

//    while (nodePtr)
//    {
//       if (nodePtr->likes == num)
//          return true;
//       else if (num < nodePtr->likes)
//          nodePtr = nodePtr->left;
//       else
//          nodePtr = nodePtr->right;
//    }
//    return false;
// }

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

// void BST::remove(int num)
// {
//    deleteNode(num, root);
// }


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

// void BST::deleteNode(int num, TreeNode *&nodePtr)
// {
//    if (num < nodePtr->likes)
//       deleteNode(num, nodePtr->left);
//    else if (num > nodePtr->likes)
//       deleteNode(num, nodePtr->right);
//    else
//       makeDeletion(nodePtr);
// }


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

// void BST::makeDeletion(TreeNode *&nodePtr)
// {
//    // Define a temporary pointer to use in reattaching
//    // the left subtree.
//    TreeNode *tempNodePtr = nullptr;

//    if (nodePtr == nullptr)
//       cout << "Cannot delete empty node.\n";
//    else if (nodePtr->right == nullptr)
//    {
//       tempNodePtr = nodePtr;
//       nodePtr = nodePtr->left;   // Reattach the left child
//       delete tempNodePtr;
//    }
//    else if (nodePtr->left == nullptr)
//    {
//       tempNodePtr = nodePtr;
//       nodePtr = nodePtr->right;  // Reattach the right child
//       delete tempNodePtr;
//    }
//    // If the node has two children.
//    else
//    {
//       // Move one node the right.
//       tempNodePtr = nodePtr->right;
//       // Go to the end left node.
//       while (tempNodePtr->left != nullptr)
//          tempNodePtr = tempNodePtr->left;
//       // Reattach the left subtree.
//       tempNodePtr->left = nodePtr->left;
//       tempNodePtr = nodePtr;
//       // Reattach the right subtree.
//       nodePtr = nodePtr->right;
//       delete tempNodePtr;
//    }
// }

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via in order traversal.  *
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
      cout << root->title << root->likes << root->views << endl;
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

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

// void BST::displayPreOrder(TreeNode *nodePtr) const
// {
//    if (nodePtr)
//    {
//       cout << nodePtr->likes << endl;
//       displayPreOrder(nodePtr->left);     
//       displayPreOrder(nodePtr->right);
//    }
// }

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

// void BST::displayPostOrder(TreeNode *nodePtr) const
// {
//    if (nodePtr)
//    {
//       displayPostOrder(nodePtr->left);    
//       displayPostOrder(nodePtr->right);
//       cout << nodePtr->likes << endl;
//    }
// }