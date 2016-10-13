#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>

class AVL_Tree
{
    private:
        
        struct TreeNode
        {
            TreeNode(const int& data) : data(data) {};
            int data;
            TreeNode* leftChild;
            TreeNode* rightChild;
            void printTree(bool isRight, std::string indent);
            void printTree();
            void printNodeValue();
        };
        TreeNode* root;
        int size;
        TreeNode* findSuccessor(TreeNode* current);
        TreeNode* remove(TreeNode* current, const int& dataToRemove);
    public:

        void deleteNode(const int& data);
        AVL_Tree();
        void add(const int& data);
        TreeNode* insert(TreeNode* current, TreeNode* newNode);
        void print();
        void inOrder(TreeNode* current);
};

#endif
