#include <iostream>
#include <iomanip>
using namespace std;

#include "BST.h"
int main( int argc, char** argv )
{ 
   unsigned int i; // counter to loop from 1-10
   int item; // variable to hold random values
   BST b;

   
	b.root= NULL;  b.size=0;// tree initially empty
  for ( i = 1; i < argc; ++i ) { 
    insertNode( b, atoi(argv[i]));
  }


  // traverse the tree preOrder
  cout<< "\n\nThe preOrder traversal is:" <<endl ;
  preOrder( b.root );

  // traverse the tree inOrder
  cout<<"\nThe inOrder traversal is:" <<endl;
  inOrder( b.root );

  // traverse the tree postOrder
  cout<< "\nThe postOrder traversal is:" <<endl;
  postOrder( b.root );

  cout<< "\nThe treeOrder traversal is:"<<endl;
  treeOrder(b.root,0);
}

