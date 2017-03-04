#include "ZSearch.h"
#include <math.h>

Coord2D getZPosition(int n, int m) {
	int dim = pow(2, n);
	Coord2D first, last;
	int firstValue = 1, lastValue = dim * dim;

	first.x = first.y = 1;
	last.x = last.y = dim;

	while(first.x != last.x || first.y != last.y) {
		int aux = (lastValue - firstValue + 1) / 4;
		int xMid = (first.x + last.x) / 2;
		int yMid = (first.y + last.y) / 2;
		if (m < firstValue + aux) {
			lastValue = firstValue + aux - 1;
			last.x = xMid;
			last.y = yMid;
		} else if (m >= firstValue + aux && m < firstValue + 2 * aux) {
			lastValue = firstValue + 2 * aux - 1;
			firstValue = firstValue + aux;
			first.y = yMid + 1;
			last.x = xMid;
		} else if (m >= firstValue + 2 * aux && m < firstValue + 3 * aux) {
			lastValue = firstValue + 3 * aux - 1;
			firstValue = firstValue + 2 * aux;
			first.x = xMid + 1;
			last.y = yMid;
		} else {
			firstValue = firstValue + 3 * aux;
			first.x = xMid + 1;
			first.y = yMid + 1;
		}
	}
	
	return first;
}
