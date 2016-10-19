#include "AVL_Tree.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    AVL_Tree at;
    vector<int> list;

    for (int i = 0; i < 20; i++) {
       // int x = rand() % 100;
        list.push_back(i);
        at.add(i);
    }

    at.print();
    cout << endl;
    at.add(list[0]);
    cout << endl;
    at.print();
    for (int i = 19; i >= 15; i--) {
        at.deleteNode(list[i]);

    }
    cout << endl; 
    at.print();

    /*
    at.add(23);
    at.add(50);
    at.add(15);
    at.add(35);
    at.add(73);
    at.add(25);
    at.add(78);
    at.add(39);

    at.print();
	std::cout << std::endl;
	std::cout << "Deleting 23" << std::endl;
    at.deleteNode(23);

    at.print();
    return 0;
    */


}
