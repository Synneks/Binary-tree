#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/*
* Constructor
*/

Tree::Tree()
{
	//root = NULL;
}

/*
* Destructor
*/

Tree::~Tree()
{
}

/*
* Caut element in tree
*/

Node * Tree::getr()
{
	return this->root;
}

void Tree::find(int item, Node **par, Node **loc)
{
	Node *ptr, *ptrsave;
	if (root == NULL)
	{
		*loc = NULL;
		*par = NULL;
		return;
	}

	if (item == root->info)
	{
		*loc = root;
		*par = NULL;
		return;
	}

	if (item < root->info)
		ptr = root->left;
	else
		ptr = root->right;

	ptrsave = root;
	while (ptr != NULL)
	{
		if (item == ptr->info)
		{
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if (item < ptr->info)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*loc = NULL;
	*par = ptrsave;
}

/*
* Insert
*/

void Tree::insert(Node *Tree, int newNode, int &numarnoduri)
{
	if (root == NULL)	//verific daca am sau nu o root
	{
		root = new Node(newNode);	//in cazul in care nu exista una, o creez
		root->left = NULL;
		root->right = NULL;
		cout << "root added" << endl;
		numarnoduri++;
		return;
	}

	if (Tree->info == newNode)	//verific daca nodul pe care ma aflu e egal cu cel pe care trebuie sa il inserez
	{									//ca sa nu am dubluri
		cout << "Element already in Tree" << endl;
		return;
	}

	if (Tree->info > newNode)	//verific daca trebuie sa o iau la stanga nodului curent sau la dreapta
	{
		if (Tree->left != NULL)	//daca la stanga mai ma un nod reapelez functia
		{
			insert(Tree->left, newNode, numarnoduri);
		}
		else //daca la stanga nu e nimic creez un nod
		{
			Tree->left = new Node(newNode);
			(Tree->left)->left = NULL;
			(Tree->left)->right = NULL;
			cout << "Node Added To Left" << endl;
			numarnoduri++;
			return;
		}
	}
	else    //cazul in care o iau la dreapta este identic cu cel in care merg spre stanga
	{
		if (Tree->right != NULL)
		{
			insert(Tree->right, newNode, numarnoduri);
		}
		else
		{
			Tree->right = new Node(newNode);
			(Tree->right)->left = NULL;
			(Tree->right)->right = NULL;
			cout << "Node Added To Right" << endl;
			numarnoduri++;
			return;
		}
	}

}

/*
* Delete
*/

void Tree::del(int item, int &numarnoduri)
{
	Node *parent, *location;
	if (root == NULL)	//verific daca am root, daca nu am inseamna ca nu am arbore
	{
		cout << "Tree empty" << endl;
		return;
	}

	find(item, &parent, &location);	//apelez functia de cautare a elementului item, pe care vreau sa il sterg

	if (location == NULL)	//verific daca nodul exista in arbore
	{
		cout << "Item not present in Tree" << endl;
		return;
	}

	//exista trei cazuri de stergere.
	if (location->left == NULL && location->right == NULL)
		case_a(parent, location);	//cazul a in care nodul este chiar frunza

	if ((location->left != NULL && location->right == NULL) || (location->left == NULL && location->right != NULL))
		case_b(parent, location);	//cazul in care nodul mai are o legatura spre dreapta sau spre stanga

									/*if (location->left == NULL && location->right != NULL)
									case_b(parent, location);*/

	if (location->left != NULL && location->right != NULL)
		case_c(parent, location);	//cazul in care are in ambele directii cate o legatura
	numarnoduri--;
	free(location);
}


/*
* Case A
*/

void Tree::case_a(Node *par, Node *loc)
{
	if (par == NULL)	//daca nu exista parent inseamna ca vreau sa sterg root.
	{
		root = NULL;
	}
	else
	{
		if (loc == par->left)	//daca e o frunza atunci golesc si partea stanga sau dreapta a nodului anterior
			par->left = NULL;
		else
			par->right = NULL;
	}
}

/*
* Case B
*/

void Tree::case_b(Node *par, Node *loc)
{
	Node *child;
	if (loc->left != NULL)	//verific in ce parte am urmas
		child = loc->left;
	else
		child = loc->right;

	if (par == NULL)	//daca nu exista parent inseamna ca vreau sa sterg root
	{
		root = child;	//noua root va fi acum urmasul fostei radacini
	}
	else
	{
		if (loc == par->left)	//daca exista un nod anterior, atunci ii atribui acestuia urmasii nodului sters
			par->left = child;
		else
			par->right = child;
	}
}


/*
*Case C
*/

void Tree::case_c(Node *par, Node *loc)
{
	Node *ptr, *ptrsave, *suc, *parsuc;
	ptrsave = loc;	//salvez locatia actuala
	ptr = loc->right;	//salvez urmasul dreapta
	while (ptr->left != NULL)	//mut partea stanga a urmasului dreapta cu un nivel mai sus
	{
		ptrsave = ptr;
		ptr = ptr->left;
	}
	suc = ptr;
	parsuc = ptrsave;

	if (suc->left == NULL && suc->right == NULL)
		case_a(parsuc, suc);
	else
		case_b(parsuc, suc);
	if (par == NULL)
	{
		root = suc;
	}

	else
	{
		if (loc == par->left)
			par->left = suc;
		else
			par->right = suc;
	}
	suc->left = loc->left;
	suc->right = loc->right;
}

/*
* Preorder
*/

void Tree::preorder(Node *ptr)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		cout << ptr->info << "  ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

/*
* Inorder
*/

void Tree::inorder(Node *ptr)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		inorder(ptr->left);
		cout << ptr->info << " ";
		inorder(ptr->right);
	}
}


/*
* Postorder
*/

void Tree::postorder(Node *ptr)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->info << "  ";
	}
}

/*
* Display
*/

void Tree::display(Node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "root->:  ";
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->info;
		display(ptr->left, level + 1);
	}
}

int Tree::height(Node *ptr)
{
	if (ptr == NULL)	//verific prima data daca am radacina
	{
		return 0;
	}

	int left = height(ptr->left);	//verific recursiv partea stanga a nodului curent
	int right = height(ptr->right);	//verific recursiv partea dreapta a nodului curent

	if (left > right)	//la final verific care parte e mai mare si o returnez
		return left + 1;
	else
		return right + 1;
}