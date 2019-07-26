

#include<iostream>
#include<vector>

void findK(int k, std::vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == (k - a[i]))
            {
                std::cout<<a[i] <<" +" <<a[j]<<"="<<k<<std::endl;
            }
            
        } 
    }
    
}
