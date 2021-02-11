#include <iostream>
#include <ctime>
#include "BTree.h"
using namespace std;
int main() {
	srand(unsigned(time(0)));
	BTree<int> tree;
	tree.add(10);
	cout << "Empty: " << tree.isEmpty() << endl;
	cout << "Size: " << tree.getSize() << endl;
	size_t amount = 7;
	for (size_t i = 0; i < amount; i++)
	{
		int data = rand() % 100;
		cout << "Add node " << data << endl;
		tree.add(data);
	}
	tree.print();
	cout << "Max: " << tree.max() << endl;
	cout << "New: " << endl;
	BTree<int> tree1;
	tree1.add(325);
	tree1.add(43);
	tree1.add(130);
	tree1.add(43);
	tree1.add(12);
	tree1.add(78);
	cout << boolalpha << tree1.find(200) << endl;
	cout << endl;
	cout << "Print bigger" << endl;
	tree1.printBigger(33);
	return 0;
}