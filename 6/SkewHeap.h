

#ifndef _SKEW_HEAP_H_
#define _SKEW_HEAP_H_

#include <iostream>

struct SkewNode
{
    int element;
    SkewNode *left;
    SkewNode *right;

    explicit SkewNode(int pElement = 0)
        : element{pElement}, left{nullptr}, right{nullptr}
    {
    }

    explicit SkewNode(const int &pElement, SkewNode *pLeft, SkewNode *pRight)
        : element{pElement}, left{pLeft}, right{pRight}
    {
    }

    explicit SkewNode(const SkewNode &rhs)
        : element{rhs.element}, left{rhs.left}, right{rhs.right}
    {
    }
};

class SkewHeap
{
private:

    SkewNode *root;

    void makeEmpty(SkewNode*& t)
    {
        if (t == nullptr)
        {
           return;
        }
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }
public:
    SkewHeap( )
    {
        root = nullptr;
    }

    ~SkewHeap()
    {
        makeEmpty();
    }


    void makeEmpty()
    {
        makeEmpty(root);
    }

    SkewNode* merge(SkewNode* t1, SkewNode* t2)
    {
        if (t1 == nullptr)
        {
            return t2;
        }
        
        if (t2 == nullptr)
        {
            return t1;
        }

        // 合并t1和t2时，将t1作为合并后的树的根；
        // 这里的操作是保证: t1 < t2
        if (t1->element > t2->element)
        {
            /* 交换 */
            std::swap(t1, t2);
        }

        // 将x的右孩子和y合并，
        // 合并后直接交换x的左右孩子，而不需要像左倾堆一样考虑它们的npl。
        SkewNode *tmp = merge(t1->right, t2);
        t1->right = t1->left;
        t1->left = tmp;
        return t1;
    }



};
 


#endif

