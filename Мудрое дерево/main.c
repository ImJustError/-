#include "tree.h"



int main() {
	node maintree = init(NULL);
	addel(&maintree, 8);
	addel(&maintree, 4);
	addel(&maintree, 1);
	addel(&maintree, 0);
	addel(&maintree, 2);
	printDerevo(&maintree);
	deleteFunc(&maintree, 1);
	printf("\n");
	printDerevo(&maintree);

	
	return 0;
}


