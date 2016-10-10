#ifndef AVLTREE_H
#define AVLTREE_H


class AVL_Tree
{
    
    private:
        
        struct TreeNode
        {
            int data;
            TreeNode* leftChild;
            TreeNode* rightChild;
        };

        TreeNode* root;
        int size;
        TreeNode remove(TreeNode current, const int& dataToRemove);
        TreeNode findSuccessor(TreeNode current);       
    
    public:

        AVL_Tree();
        
        void add(const int& data);
        
        TreeNode& insert(TreeNode& current, TreeNode& newNode);
       
        void deleteNode(const int& data);
        
        TreeNode find(TreeNode current, const int& dataToFind);

        void inOrder(TreeNode current);

        

};

#endif
