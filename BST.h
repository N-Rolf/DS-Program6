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
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   TreeNode *root;       // Pointer to the root node
   int likeTotal = 0;
   int viewTotal = 0;
   // Private member functions
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(int, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;
   void displayRoot(TreeNode *);
   void displayTotal(TreeNode *);
   
public:
   // Constructor
   BST()
      { root = nullptr; }
      
   // Destructor
   ~BST()
      { destroySubTree(root); }
      
   // Binary tree operations
   void insertNode(SElement, int, int);
   bool searchNode(int);
   void remove(int);
   void displayRoot()
      { displayRoot(root);}

   void displayTotal(int *l, int *v)
      { displayTotal(root);
        *l = likeTotal;
        *v = viewTotal;}

   void displayInOrder() const
      {  displayInOrder(root); }
      
   void displayPreOrder() const
      {  displayPreOrder(root); }
      
   void displayPostOrder() const
      {  displayPostOrder(root); }
};
#endif