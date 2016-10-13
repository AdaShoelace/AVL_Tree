#include "AVL_Tree.h"

int main()
{
    AVL_Tree* at = new AVL_Tree();

    at->add(12);
    at->add(9);
    at->add(45);
    at->add(2);
    at->add(20);
    at->add(19);
    at->add(25);
    at->add(24);
    at->add(17);
    at->add(14);
    at->print();
    at->deleteNode(20);
    at->print();
    delete at;

    return 0;


}
