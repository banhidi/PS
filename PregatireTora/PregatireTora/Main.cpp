#include <stdio.h>
#include "Language.h"
#include "ZSearch.h"

int main() {
	Coord2D a = getZPosition(3, 40);
	printf("%d %d\n", a.x, a.y);
	return 0;
}