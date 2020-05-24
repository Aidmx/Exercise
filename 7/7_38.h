#ifndef _7_38_H_
#define _7_38_H_


#include<iostream>
#include<vector>


//a, b 数组个数都为N， 假设 N > 1
int findmid(std::vector<int>& a, std::vector<int>& b)
{
    if ((a.size() < 0) && (b.size() < 0))
    {
        return 0;
    }
    
    
    int midX = 0,midY = 0, midValue;
    
    //判断奇、偶
    if (a.size()%2 <= 0)
    {
        midX = (1+a.size())/2 ;
        midY = (1+a.size())/2 +1 ;
    }
    else
    {
        midX = (1+a.size())/2 ;
        midY = (1+a.size())/2 ;
    }
    
    //
    if ( a[midX] < b[midY])
    { 
    }
    else if ( a[midX] > b[midY])
    { 
    }
    else
    {
        
    }
    
    



}


#endif
