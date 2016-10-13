#ifndef AVLTREE_H
#define AVLTREE_H


class AVL_Tree
{
    private:
        
        struct TreeNode
        {
            TreeNode(const int& data) : data(data) {};
            int data;
            TreeNode* leftChild;
            TreeNode* rightChild;
            void print();
        };
        TreeNode* root;
        int size;
        void deleteNode(const int& data);
        TreeNode* findSuccessor(TreeNode* current);
        TreeNode* remove(TreeNode* current, const int& dataToRemove);
    public:

        AVL_Tree();
        void add(const int& data);
        TreeNode* insert(TreeNode* current, TreeNode* newNode);
};

#endif
