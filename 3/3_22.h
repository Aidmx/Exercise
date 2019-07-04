#pragma once

#include<stack>


class PostfixExpression
{
	double Calculate(char* pExpression[], int arg)
	{
		std::stack<double> stac;
		double result, a, b;
		for (int i = 0; i < arg; i++)
		{
			result = atof(pExpression[i]);

			if (result)
			{
				
			}



		}

		return 0.0f;
	}
};

