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
            void printTree(bool isRight, const std::string& indent);
            void printTree();
            void printNodeValue();
        };
        
        int size;
        TreeNode* root;
        TreeNode* findSuccessor(TreeNode* current);
        TreeNode* remove(TreeNode* current, const int& dataToRemove);
        TreeNode* insert(TreeNode* current, TreeNode* newNode);
    public:

        AVL_Tree();
        void deleteNode(const int& data);
        void add(const int& data);
        void print();
        void inOrder(TreeNode* current);
};

#endif
