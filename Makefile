
AVL_Tree: main.o AVL_Tree.o
	g++ main.o AVL_Tree.o -o AVL_Tree

main.o: main.cpp
	g++ -c main.cpp

AVL_Tree.o: AVL_Tree.cpp AVL_Tree.h
	g++ -c AVL_Tree.cpp

clean:
	rm -rf *.o

