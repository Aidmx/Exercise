#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

class PostfixExpression
{
public:
	double mResult;


public:
	PostfixExpression() :mResult{0}
	{
	}

	void DoCalculate(std::string pExpression)
	{
		std::stack<double> stac;
		double result, a, b;
		std::string num;
		for (int k = 0; k < pExpression.length(); k++)
		{
			switch (pExpression[k])
			{
			case '+':
			{
				a = stac.top();
				stac.pop();
				b = stac.top();
				stac.pop();
				stac.push(a + b);
			}
			break;
			case '-':
			{
				a = stac.top();
				stac.pop();
				b = stac.top();
				stac.pop();
				stac.push(a - b);
			}
			break;
			case '*':
			{
				a = stac.top();
				stac.pop();
				b = stac.top();
				stac.pop();
				stac.push(a * b);
			}
			break;
			case '/':
			{
				a = stac.top();
				stac.pop();
				b = stac.top();
				stac.pop();
				stac.push(a / b);
			}
			break;
			case '=':
			{
				mResult = stac.top();
				return;
			}
			case ' ':
			{
				if (num.length() > 0)
				{
					std::stringstream strm(num);
					strm >> result;
					stac.push(result);
					num = "";
				}
			}
			break;
			default:
				num += pExpression[k];
				break;
			}
		}
	}
};

