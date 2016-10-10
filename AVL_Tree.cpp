#include "AVL_Tree.h"
#include "stddef.h"

AVL_Tree::AVL_Tree()
{
    this->root = NULL;
    this->size = 0;   
}

void AVL_Tree::add(const int& data)
{
    
}

AVL_Tree::TreeNode& AVL_Tree::insert(TreeNode& current, TreeNode& newNode)
{
   TreeNode* newRoot =&current;

   if(newRoot != NULL)
   {
        if(newNode.data < current.data)  
        {
            if(newRoot->leftChild == NULL) 
            {
                newRoot->leftChild = &newNode;
            } 
            else
            {
                newRoot->leftChild = insert(newRoot->leftChild, newNode)
            }
        }
   }
}
