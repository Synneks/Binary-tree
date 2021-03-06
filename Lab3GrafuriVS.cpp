#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "Tree.h"
#include <cassert>

using namespace std;

void testing();

int main()
{
	int choice, num, numarnoduri = 0;
	int vect[100], i, j;
	Tree Tree;

	testing();	//apel functie testing

	while (1)
	{
		cout << "-----------------" << endl;
		cout << "1.Insert Element " << endl;
		cout << "2.Delete Element " << endl;
		cout << "3.Inorder" << endl;
		cout << "4.Preorder" << endl;
		cout << "5.Postorder" << endl;
		cout << "6.Display" << endl;
		cout << "7.Count Nodes" << endl;
		cout << "8.Count Edges" << endl;
		cout << "9.Height" << endl;
		cout << "10.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the number to be inserted: ";
			cin >> num;
			Tree.insert(Tree.getr(), num, numarnoduri);
			break;

		case 2:
			if (Tree.getr() == NULL)
			{	
				cout << "Tree is empty, nothing to delete" << endl;
				continue;
			}
			cout << "Enter the number to be deleted: ";
			cin >> num;
			Tree.del(num, numarnoduri);
			break;

		case 3:
			cout << "Inorder:" << endl;
			Tree.inorder(Tree.getr());
			cout << endl;
			break;

		case 4:
			cout << "Preorder:" << endl;
			Tree.preorder(Tree.getr());
			cout << endl;
			break;

		case 5:
			cout << "Postorder:" << endl;
			Tree.postorder(Tree.getr());
			cout << endl;
			break;

		case 6:
			cout << "Display:" << endl;
			Tree.display(Tree.getr(), 1);
			cout << endl;
			break;

		case 7:
			cout << "Count Node: " << numarnoduri << endl;
			break;

		case 8:
			cout << "Count Edges: " << numarnoduri - 1 << endl;
			break;

		case 9:
			cout << "Height: " << Tree.height(Tree.getr()) - 1 << endl;
			break;

		case 10:
			exit(1);

		default:
			cout << "Wrong choice" << endl;
		}
	}
}

void testing()
{
	int numarnoduri = 0;
	Tree Tree;
	Node *root = Tree.getr();
	Tree.insert(Tree.getr(), 5, numarnoduri);
	Tree.insert(Tree.getr(), 6, numarnoduri);
	Tree.insert(Tree.getr(), 3, numarnoduri);
	assert(numarnoduri == 3);
	assert(Tree.height(Tree.getr()) - 1 == 1);
}