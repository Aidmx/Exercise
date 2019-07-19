
//add by allen
//3.6 answer

#include <iostream>
#include "BinaryHeap.h"
#include "LeftistHeap.h"
#include "BinomialQueue.h"
#include "SkewHeap.h"

using namespace std;
#define random(x) (rand() % x)

int main(int arg, char *argv[])
{
	// BinaryHeap  bh;
	// bh.insert1(10);
	// bh.insert1(12);
	// bh.insert1(1);
	// bh.insert1(14);
	// bh.insert1(6);
	// bh.insert1(5);
	// bh.insert1(8);
	// bh.insert1(15);
	// bh.insert1(3);
	// bh.insert1(9);
	// bh.insert1(7);
	// bh.insert1(4);
	// bh.insert1(11);
	// bh.insert1(13);
	// bh.insert1(2);
	// bh.preorder(2);

	LeftistHeap<int> lh;
	lh.insert(3);
	lh.insert(8);
	lh.insert(10);
	lh.insert(21);
	lh.insert(14);
	lh.insert(23);
	lh.insert(17);
	lh.insert(26);

	return 0;
}
