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
��� ��������� � ����� � ������ � �������� ��������� ��������� ������;
� ���� ����� ������ ��������� ������������� ���� X �������� ������ ������ ������ ���� �����, ������ �������� ����� ������ ������ ���� X;
� ���� ����� ������� ��������� ������������� ���� X �������� ������ ������ ������, ������ �������� ����� ������ ������ ���� X.
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



