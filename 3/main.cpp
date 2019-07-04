
//add by allen
//3.6 answer

#include <iostream>
#include <ctime>

#include "3_2.h"
#include "3_6.h"
#include "3_22.h"


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
	string expression = "6.1 1.2 + /1 =";
	PostfixExpression test; 
	test.DoCalculate(expression);
	std::cout << expression << " ;result is = " << test.mResult << std::endl;

	return 0;
}
