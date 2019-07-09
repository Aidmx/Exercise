#ifndef __4_18_H
#define __4_18_H

int Fib1(int pHeight)
{
    if (pHeight == 0)
    {
        return 0;
    }
    else if (pHeight == 1)
    {
        return 2;
    }

    return Fib1(pHeight - 1) + Fib1(pHeight - 2) + 1;
}

int Fib2(int pHeight)
{
    int result1 = 0;
    int result2 = 0;
    int result = 0;
    for (int h = 0; h <= pHeight; h++)
    {
        if (h == 0)
        {
        }
        else if (h == 1)
        {
            result2 = 2;
            result = 2;
        }
        else
        {
            result = result2 + result1 + 1;
            result1 = result2;
            result2 = result;
        }
    }
    return result;
}
#endif