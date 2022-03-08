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
      int value;         
      int views;
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   TreeNode *root;       // Pointer to the root node
   
   // Private member functions
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(int, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;
   
public:
   // Constructor
   IntBinaryTree()
      { root = nullptr; }
      
   // Destructor
   ~IntBinaryTree()
      { destroySubTree(root); }
      
   // Binary tree operations
   void insertNode(int);
   bool searchNode(int);
   void remove(int);
   
   void displayInOrder() const
      {  displayInOrder(root); }
      
   void displayPreOrder() const
      {  displayPreOrder(root); }
      
   void displayPostOrder() const
      {  displayPostOrder(root); }
};
#endif