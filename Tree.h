#pragma once
#include "Node.h"

class Tree
{
public:
	Tree();
	~Tree();
	void find(int, Node **, Node **);
	void insert(Node *, int, int &);
	void del(int, int &);
	void case_a(Node *, Node *);
	void case_b(Node *, Node *);
	void case_c(Node *, Node *);
	void preorder(Node *);
	void inorder(Node *);
	void postorder(Node *);
	void display(Node *, int);
	int height(Node *);
	Node *getr();
private:
	Node * root;
};