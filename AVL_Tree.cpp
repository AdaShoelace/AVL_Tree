#include "AVL_Tree.h"
#include "stddef.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>

AVL_Tree::TreeNode::TreeNode(const int& data) 
    : data(data), height(1), leftChild(NULL), rightChild(NULL){};

void AVL_Tree::TreeNode::printNodeValue()
{
    std::cout << data << "\n";
}

void AVL_Tree::TreeNode::printTree(bool isRight, const std::string& indent)
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

/*
 * Constructor for the AVL_Tree
 */
AVL_Tree::AVL_Tree()
{
    this->root = NULL;
    this->size = 0;   
}

AVL_Tree::~AVL_Tree()
{
    destruct(this->root);
}

void AVL_Tree::destruct(TreeNode* root)
{
    if(root != NULL)
    {
        destruct(root->rightChild);
        destruct(root->leftChild);
        delete root;
        root = NULL;
    }
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

/*
 *Adds new node to the tree by calling insert()
 */
void AVL_Tree::add(const int& data)
{
    try 
    {
        TreeNode* node = new TreeNode(data);
        this->root = insert(this->root, node);
        size++;
    }
    catch(std::string s)
    {
        std::cout << s << std::endl; 
    }
}

void AVL_Tree::print()
{
    root->printTree();
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
        throw std::string("Data already exist in tree");
    }
    return current;
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

/**
 * Returns height of tree
 */
int AVL_Tree::height(TreeNode* current)
{
    if(current == NULL)
    {
        return 0;       
    }
    return current->height;
}

int AVL_Tree::getBalance(TreeNode* current)
{
    if(current == NULL)
    {
        return 0; 
    }
    return height(current->leftChild) - height(current->rightChild);
}

AVL_Tree::TreeNode* AVL_Tree::rotateLeft(TreeNode* current)
{
}

AVL_Tree::TreeNode* AVL_Tree::rotateRight(TreeNode* current)
{
}


AVL_Tree::TreeNode* AVL_Tree::findSuccessor(TreeNode* current)
{
    while(current->leftChild != NULL)
    {
        current = current->leftChild; 
    }
    return current;
}








