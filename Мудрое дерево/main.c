#include "tree.h"



int main() {
	node maintree = init();
	addel(&maintree, 6);
	addel(&maintree, 2);
	addel(&maintree, 7);
	addel(&maintree, 3);
	addel(&maintree, 4);
	addel(&maintree, 5);
	printf("%d", findel(&maintree, 10));
	return 0;
}


