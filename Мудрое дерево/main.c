#include "tree.h"



int main() {
	node maintree = init(NULL);
	addel(&maintree, 8);
	addel(&maintree, 3);
	addel(&maintree, 10);
	addel(&maintree, 1);
	addel(&maintree, 6);
	addel(&maintree, 4);
	addel(&maintree, 7);
	addel(&maintree, 13);
	printDerevo(&maintree);
	deleteFunc(&maintree, 10);
	printf("\n");
	printDerevo(&maintree);

	
	return 0;
}


