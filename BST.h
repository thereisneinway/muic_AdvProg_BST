// An integer binary search tree

struct TreeNode {                                           
   TreeNode *leftPtr; // pointer to left subtree 
   int data; // node value                               
   TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes
void insertNode( BST &, int );

void insertNode( BST &b, int value ){
	TreeNodePtr t =b.root,new_node;
	int inserted=0;
	new_node =new TreeNode;
	if(new_node){
	  new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		//Case inserting as first node
		if(!b.root)	b.root=new_node;
    //Case inserting as child node
		else {
      while(!inserted){
        if(t->data >=value){//Case inserting to the left (<=)
          if(t->leftPtr == NULL){
            t->leftPtr=new_node;
            inserted++;
          }else{//If assign node is impossible
            t = t->leftPtr;
          }
        }else{//Case inserting to the right (>)
  	      if(t->rightPtr == NULL){
            t->rightPtr=new_node;
            inserted++;
          }else{//If assign node is impossible
            t = t->rightPtr;
          }
	      }
      }	
    }
  b.size++;
  }
  
}


void inOrder( TreeNodePtr treePtr ){ 
   // if tree is not empty, then traverse
  if ( treePtr != NULL ) {        
    inOrder( treePtr->leftPtr ); //Recursion to the left
    printf( "%3d", treePtr->data );  //print the value 
    inOrder( treePtr->rightPtr ); //Recursion to the right
  }
} 

void preOrder( TreeNodePtr treePtr ){
  if( treePtr != NULL ){
    cout<<setw(3)<<treePtr->data;
    preOrder( treePtr->leftPtr);
    preOrder( treePtr->rightPtr);
  }
}

void postOrder( TreeNodePtr treePtr ){
  if( treePtr != NULL ){
    postOrder( treePtr->leftPtr);
    postOrder( treePtr->rightPtr);
    cout<<setw(3)<<treePtr->data;
  }
}

void treeOrder(TreeNodePtr treePtr,int j){
  if( treePtr != NULL ){
    treeOrder( treePtr->rightPtr ,j+1);
    cout<<endl<<setw(j*2)<<treePtr->data;
    treeOrder( treePtr->leftPtr ,j+1);
  }
}

