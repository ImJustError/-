#include "tree.h"

node* findmin(node* parentnode);

node init(node* parent) {
	node parentnode = { 0 };
	parentnode.parent = parent;
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
			*parentnode->left = init(parentnode);
		}
		return addel(parentnode->left, data);
	}
	else if (*parentnode->data < data) {
		if (!parentnode->right) {
			parentnode->right = memalloc(sizeof(node));
			if (!parentnode->right)return 0;
			*parentnode->right = init(parentnode);
		}
		return addel(parentnode->right, data);
	}
	else return 0;
}


node* findel(node* parentnode, int data) {
	if (*parentnode->data == data) {
		return parentnode;
	}
	else if (*parentnode->data > data) {
		if (!parentnode->left)return 0;
		return findel(parentnode->left, data);
	}
	else if (*parentnode->data < data) {
		if (!parentnode->right)return 0;
		return findel(parentnode->right, data);
	}
	else return 0;
}



int deleteFunc(node* parentnode, int data) {
	
	
	node* MoiNode = findel(parentnode, data);
	if (!MoiNode->left && !MoiNode->right) {
		*MoiNode->parent->data = data;
		free(MoiNode->data);
		if (MoiNode == MoiNode->parent->left)MoiNode->parent->left = 0;
		if (MoiNode == MoiNode->parent->right)MoiNode->parent->right = 0;
		return 1;
	}
	else {
		node* min = findmin(MoiNode->right);
		*MoiNode->data = *min->data;
		return deleteFunc(min, *min->data);
	}


}


node* findmin(node* parentnode) {

	if (!parentnode->left) {
		return parentnode;
	}
	else {
		return findmin(parentnode->left);
	}
}


int printDerevo(node* derevo) {
	if (!derevo) {
		return 0;
	}
	else printf("%d", *derevo->data);
	printDerevo(derevo->left);
	printDerevo(derevo->right);
}

