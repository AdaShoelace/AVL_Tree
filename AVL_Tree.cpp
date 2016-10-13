#include "AVL_Tree.h"
#include "stddef.h"
#include <stdexcept>
#include <iostream>

/*
 * Constructor for the AVL_Tree
 */
AVL_Tree::AVL_Tree()
{
    this->root = NULL;
    this->size = 0;   
}

void AVL_Tree::print()
{
    root->printTree();
}

void AVL_Tree::TreeNode::printTree()
{
    if(rightChild != NULL)
    {
        rightChild->printTree(true, "");
    }
    printNodeValue();
    if(leftChild != NULL)
    {
        leftChild->printTree(false, "");
    }
}

void AVL_Tree::TreeNode::printTree(bool isRight, std::string indent)
{
    if(rightChild != NULL)
    {
        rightChild->printTree(true, indent + (isRight ? "       " : " |     "));
    }
    std::cout << indent;
    if(isRight)
    {
        std::cout << " /"; 
    }
    else
    {
        std::cout << " \\";
    }
    std::cout << "----- ";
    printNodeValue();
    if(leftChild != NULL)
    {
        leftChild->printTree(false, indent + (isRight ? " |     " : "       "));
    }
}

void AVL_Tree::TreeNode::printNodeValue()
{
    std::cout << data << "\n";
}

void AVL_Tree::inOrder(TreeNode* current)
{
    if(current != NULL)
    {
        inOrder(current->leftChild);
        std::cout << current->data << std::endl;
        inOrder(current->rightChild);
    }
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
    if(current == NULL)
    {
        return newNode;
    }
    if(newNode->data < current->data)
    {
        current->leftChild = insert(current->leftChild, newNode);
    }
    else if(newNode->data > current->data)
    {
        current->rightChild = insert(current->rightChild, newNode);
    }
    else 
    {
        throw "Data already exist in tree";
    }
    return current;
}

void AVL_Tree::deleteNode(const int& data)
{
    TreeNode* temp = remove(this->root, data);
    if(temp != NULL)
    {
        this->root = temp;
        size--;
    }
}

AVL_Tree::TreeNode* AVL_Tree::remove(TreeNode* current, const int& dataToRemove)
{
    if(current == NULL) 
    {
        return current; 
    }
    if(dataToRemove < current->data)
    {
        current->leftChild = remove(current->leftChild, dataToRemove);
    }
    else if(dataToRemove > current->data)
    {
        current->rightChild = remove(current->rightChild, dataToRemove);
    }
    else if(dataToRemove == current->data)
    {
        TreeNode* temp = NULL;
        //No children
        if(current->leftChild == NULL && current->rightChild == NULL)
        {
            delete current;
            current = NULL;
        }
        //One child
        else if(current->leftChild != NULL && current->rightChild == NULL)
        {
            temp = current->leftChild;
            current->data = temp->data;
            current->leftChild = remove(current->leftChild, temp->data);
        }
        else if(current->leftChild == NULL && current->rightChild != NULL)
        {
            temp = current->rightChild;
            current->data = temp->data;
            current->rightChild = remove(current->rightChild, temp->data);
        }
        //Two children
        else if(current->leftChild != NULL && current->rightChild != NULL)
        {
            temp = findSuccessor(current->rightChild);
            current->data = temp->data;
            remove(current->rightChild, temp->data);
        }
    }
    return current;
}
AVL_Tree::TreeNode* AVL_Tree::findSuccessor(TreeNode* current)
{
    while(current->leftChild != NULL)
    {
        current = current->leftChild; 
    }
    return current;
}








