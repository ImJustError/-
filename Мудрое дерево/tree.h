#pragma once
#include <stdlib.h>
#include <stdio.h>



typedef struct Nodest {
	int* data;
	struct Nodest* left;
	struct Nodest* right;
}node;

node init();
int addel(node* parentnode, int data);
int findel(node* parentnode, int data);


