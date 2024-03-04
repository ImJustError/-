#include "tree.h"


node init() {
	node parentnode = { 0 };
	return parentnode;
}

void* memalloc(int size) {
	void* mem = malloc(size);
	if (!mem) {
		printf("error mem alloc");
		return 0;
	}
	return mem;
}


/*
оба поддерева Ч левое и правое Ч €вл€ютс€ двоичными деревь€ми поиска;
у всех узлов левого поддерева произвольного узла X значени€ ключей данных меньше либо равны, нежели значение ключа данных самого узла X;
у всех узлов правого поддерева произвольного узла X значени€ ключей данных больше, нежели значение ключа данных самого узла X.
*/



int addel(node* parentnode, int data) {
	if (!parentnode->data) {
		parentnode->data = memalloc(sizeof(int));
		if (!parentnode->data)return 0;
		*(parentnode->data) = data;
		return 1;
	}
	else if (*parentnode->data >= data) {
		if (!parentnode->left) {
			parentnode->left = memalloc(sizeof(node));
			if (!parentnode->left)return 0;
			*parentnode->left = init();
		}
		return addel(parentnode->left, data);
	}
	else if (*parentnode->data < data) {
		if (!parentnode->right) {
			parentnode->right = memalloc(sizeof(node));
			if (!parentnode->right)return 0;
			*parentnode->right = init();
		}
		return addel(parentnode->right, data);
	}
	else return 0;
}


int findel(node* parentnode, int data) {
	if (*parentnode->data == data) {
		return 1;
	}
	else if (*parentnode->data >= data) {
		if (!parentnode->left)return 0;
		return findel(parentnode->left, data);
	}
	else if (*parentnode->data < data) {
		if (!parentnode->right)return 0;
		return findel(parentnode->right, data);
	}
	else return 0;
}



