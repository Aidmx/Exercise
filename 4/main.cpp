
//add by allen
//3.6 answer

#include <iostream>
#include <ctime>
#include "4_18.h"
#include "BinarySearchTree.h"

using namespace std;

int main(int arg, char* argv[])
{
	//const int m = 50000000;
	//const int n = 10000;
	//Questions_3_6 test;
	//clock_t start, end;

	//start = clock();
	//test.Answer(m, n);
	//end = clock();
	//std::cout << "lei time used:" << ((double)(end - start) / CLOCKS_PER_SEC) << std::endl;

	//start = clock();
	//test.AnswerBook(m, n);
	//end = clock();
	//std::cout << "Correct time used:" << ((double)(end - start) / CLOCKS_PER_SEC) << std::endl;

	//3.22 后缀表达式
	//string expression = "6.1 1.2 + /1 =";
	//PostfixExpression test; 
	//test.DoCalculate(expression);
	//std::cout << expression << " ;result is = " << test.mResult << std::endl;
	//4.2 4.6 4.10 4.14 4.18 4.22 4.26 4.30 4.34,4.38 4.42 4.46 4.50
	cout<<Fib1(15)<<endl;
	cout<<Fib2(15)<<endl;
	
	return 0;
}
