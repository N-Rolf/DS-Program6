/********************************************************************
***  NAME       :Neil Rolf                                        ***
***  CLASS      :CSc 300                                          ***
***  ASSIGNMENT :Program 2                                        ***
***  DUE DATE   :02/04/2022                                       ***
***  INSTRUCTOR :Kurtenbach                                       ***
*********************************************************************
***  DESCRIPTION :Stack ADT implemented with linked list giving   ***
***               user access to grocery item purchase history.   ***
********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "BST.h"
using namespace std;

enum Menu {PRINT_ROOT_TITLE=1, PRINT_ALL, PRINT_TOTAL, EXIT};

struct Node
    {
        string title;
        int likes;
        int views;
    };

int ingestData();
BST tree;

int main()
{
   int catchLikes = 0, catchViews = 0;
   int *likePtr = &catchLikes;
   int *viewPtr = &catchViews;
//initial data ingest and user file name prompt
   int itemCount = ingestData();
   tree.displayTotal(likePtr, viewPtr);
   cout << catchLikes << " " << catchViews << endl;
   
   //USER MENU
   //  int selection = 0;
   //  do{
   //      cout << "\nChoose an Option...\n";
   //      cout << "1: Print previous items.\n";
   //      cout << "2: Display total purchases value. \n";
   //      cout << "3: Exit. \n";
   //      cin.clear();
   //      cin >> selection;
   //      switch(selection){
   //          case PRINT_ROOT_TITLE:{
   //             //tree.displayRoot();
   //              break;
   //              }
   //          case PRINT_ALL:{
   //             //tree.displayTotal();
   //              break;
   //              }
   //          case PRINT_TOTAL:{
   //             //print total number of likes and views
   //             break;
   //          }
   //          case EXIT:{
   //              cout << "\nExiting...\n";
   //              break;
   //              }
   //      }
   //  }while(selection != 4);
   
   return 0;
}

/********************************************************************
*** FUNCTION ingestData                                           ***
*********************************************************************
*** DESCRIPTION : displays all nodes in the stack                 ***
*** INPUT ARGS : none                                             ***
*** OUTPUT ARGS : none                                            ***
*** RETURN : number of items pushed to stack                      ***
********************************************************************/
int ingestData()
{
   string userFile = "videos.txt";

    //check for file
    ifstream infile;
    infile.open(userFile);
        if(!infile)
        {
            cout << "Error opening file." << endl;
            exit(102);
        }
    
    //read from file to temporary node, push from temp to stack
    Node tempNode;
    int count = 0;

    while(infile)
    {
      infile >> tempNode.likes;
      infile >> tempNode.views;
      getline(infile, tempNode.title);

      //cout << "inserting: " << tempNode.title << ", " << tempNode.likes << ", " << tempNode.views << endl;
      tree.insertNode(tempNode.title, tempNode.likes, tempNode.views);     
      count ++;
      if(infile.eof())  //checks eof flag before entering final while loop (prevents inserting last item x2)
         break;
    }
   cout << count << " items inserted." << endl;
   infile.close();
   return count;
}