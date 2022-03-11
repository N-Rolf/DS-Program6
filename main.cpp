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
   
    //USER MENU
    int selection = 0;
    do{
        cout << "\nChoose an Option...\n";
        cout << "1: Print the Title field of the root node.\n";
        cout << "2: Display the information for all Videos. (alphabetically) \n";
        cout << "3: Display the total number of likes and views. \n";
        cout << "4: Exit. \n";
        cin.clear();
        cin >> selection;
        switch(selection){
            case PRINT_ROOT_TITLE:{
               tree.displayRoot();
                break;
                }
            case PRINT_ALL:{
                cout << setw(46) << std::left << "\nTitle"; 
                cout << setw(12) << std::left << "Likes";
                cout << setw(12) << std::left << "Views" << endl;
                cout << string(69, '-') << endl;
                tree.displayInOrder();
                break;
                }
            case PRINT_TOTAL:{
               tree.displayTotal(likePtr, viewPtr);
               cout << "\nTotal Likes: " << catchLikes << endl; //27349
               cout << "Total Views: " << catchViews << endl; //9773
               break;
            }
            case EXIT:{
                cout << "\nExiting...\n";
                break;
                }
        }
    }while(selection != 4);
   
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

    while(infile >> tempNode.likes)
    {
      //infile >> tempNode.likes;
      infile >> tempNode.views;
      infile.ignore();
      getline(infile, tempNode.title);

      //cout << "inserting: " << tempNode.title << ", " << tempNode.likes << ", " << tempNode.views << endl;
      tree.insertNode(tempNode.title, tempNode.likes, tempNode.views);     
      count ++;
      //cout << "eof status: " << infile.eof() << endl;
    }

   //cout << "\n" << count << "/10 items inserted." << endl;
   infile.close();
   return count;
}