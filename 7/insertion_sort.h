#ifndef _INSERTIOM_SORT_H_
#define _INSERTIOM_SORT_H_

#include<iostream>
#include<vector>

template<typename Comparable>
void insertionSort(std::vector<Comparable> a)
{
    for (int p = 0; p < a.size(); p++)
    {
        Comparable tmp = std::move(a[p]);
        int j = p;
        for (; j > 0 && tmp< a[j - 1]; --j)
        {
            a[j] = std::move(a[j -1]);
        }
        a[j] = std::move(tmp);
    }
    
}


template<typename Iterator, typename Comparator>
void insertionSort(const Iterator& begin, const Iterator& end, Comparator lessThan)
{
    if (begin == end)
    {
        return;
    }
    Iterator j;
    for (Iterator p = begin +1; p != end; p++)
    {
        auto tmp = std::move(*p);
        for (j = p; j!=begin &&lessThan(tmp, *(j -1)); --j)
        {
            *j = std::move(*(j -1));
        }
        *j = std::move(tmp);
    }
}

template<typename Iterator>
void insertionSort(const Iterator& begin, const Iterator& end)
{
    insertionSort(begin, end, less<decltype(*begin)>{});
}


#endif
