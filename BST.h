/********************************************************************
***  NAME       :Neil Rolf                                        ***
***  CLASS      :CSc 300                                          ***
***  ASSIGNMENT :Program 6                                        ***
***  DUE DATE   :03/11/2022                                       ***
***  INSTRUCTOR :Kurtenbach                                       ***
*********************************************************************
***  DESCRIPTION :Binary Search Tree for handling video data      ***
********************************************************************/
#ifndef BST_H
#define BST_H
#include <string>
typedef std::string SElement;

class BST
{
private:
   struct TreeNode
   {
      SElement title;
      int likes;         
      int views;
      TreeNode *left;    
      TreeNode *right;   
   };

   TreeNode *root;       
   int likeTotal = 0;
   int viewTotal = 0;

   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void displayInOrder(TreeNode *) const;
   void displayRoot(TreeNode *);
   void displayTotal(TreeNode *);
   
public:
   BST()
      { root = nullptr; }
   ~BST()
      { destroySubTree(root); }
      

   void insertNode(SElement, int, int);

   void displayRoot()
      { displayRoot(root);}

   void displayTotal(int *l, int *v)
      { displayTotal(root);
        *l = likeTotal;
        *v = viewTotal;}

   void displayInOrder() const
      {  displayInOrder(root); }

};
#endif