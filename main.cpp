#include "AVL_Tree.h"
#include <stdlib.h>
#include <vector>

using std::vector;

int main()
{
    AVL_Tree at;
    vector<int> list;

    for(int i = 0; i < 20; i++)
    {
        int x = rand() % 100;
        list.push_back(x);
        at.add(x);
    }

    at.print();
    at.add(list[0]);
    at.print();
    for(int i = 19; i >= 10; i--)
    {
        at.deleteNode(list[i]);

    }

    at.print();
    return 0;


}
