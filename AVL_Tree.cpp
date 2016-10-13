#include "AVL_Tree.h"
#include "stddef.h"
#include <stdexcept>

/*
 * Constructor for the AVL_Tree
 */
AVL_Tree::AVL_Tree()
{
    this->root = NULL;
    this->size = 0;   
}

void AVL_Tree::TreeNode::print()
{

}

/*
 *Adds new node to the tree by calling insert()
 */
void AVL_Tree::add(const int& data)
{
    TreeNode* node = new TreeNode(data);
    this->root = insert(this->root, node);
    size++;
}

/*
 *Recursively traverse the tree to find the correct place for the new node and then
 *returns the tree.
 */
AVL_Tree::TreeNode* AVL_Tree::insert(TreeNode* current, TreeNode* newNode)
{
    TreeNode* retNode = current;

    if(retNode->data != newNode->data)
    {
        if(retNode == NULL) 
        {
            retNode = newNode; 
        }
        else if(newNode->data < retNode->data)
        {
            if(retNode->leftChild == NULL) 
            {
                retNode->leftChild = newNode; 
            }
            else
            {
                retNode->leftChild = insert(retNode->leftChild, newNode);
            }
        }
        else if(newNode->data > retNode->data) 
        {
            if(retNode->rightChild == NULL) 
            {
                retNode->rightChild = newNode; 
            }
            else
            {
                retNode->rightChild = insert(retNode->rightChild, newNode);
            }
        }
        else
        {
            throw "Data already exixts in tree!";
        }
    }

    return retNode;
}

void AVL_Tree::deleteNode(const int& data)
{

}

AVL_Tree::TreeNode* AVL_Tree::remove(TreeNode* current, const int& dataToRemove)
{
    if(current == NULL) return current;
    else if(dataToRemove < current->data) 
    {
        current->leftChild = remove(current->leftChild, dataToRemove);
    }
    else if(dataToRemove > current->data)
    {
        current->rightChild = remove(current->rightChild, dataToRemove);
    }
    else
    {
        if(current->leftChild == NULL && current->rightChild == NULL) 
        {
            delete current;
            current = NULL;
        }
        else if(current->leftChild == NULL)
        {
            TreeNode* temp = current;
            current = current->rightChild;
            delete temp;
        }
        else if(current->rightChild == NULL)
        {
            TreeNode* temp = current;
            current = current->leftChild;
            delete temp;
        }
        else
        {
            TreeNode* temp = findSuccessor(current);
            current->data = temp->data;
            remove(current->rightChild, temp->data);
        }
    }
    return current;
}

AVL_Tree::TreeNode* AVL_Tree::findSuccessor(TreeNode* current)
{
    if(current->rightChild != NULL)
    {
        current = current->rightChild; 
        
        while(current->leftChild != NULL)
        {
            current = current->leftChild;
        }
    }
    else if(current->leftChild != NULL)
    {
        current = current->leftChild; 
    }
    else
    {
        current = NULL; 
    }
    return current;
}









