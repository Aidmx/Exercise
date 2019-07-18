


/*   */
#ifndef _LEFTIST_HEAP_H_
#define _LEFTIST_HEAP_H_

#include <vector>

template<typename Comparable>
class LeftistHeap
{
    LeftistHeap();
    explicit LeftistHeap(const LeftistHeap& rhs);
    explicit LeftistHeap(LeftistHeap&& rhs);
    
    ~LeftistHeap();

    LeftistHeap &operator=(const LeftistHeap &rhs);
    LeftistHeap &operator=(LeftistHeap &&rhs);
    bool isEmpty() const;
    const Comparable &findMin() const;
    void deleteMin( Comparable & minltem );
    void makeEmpty();
    void merge( LeftistHeap & rhs )
    {
        if (this == &rhs)
        {
            return;
        }
        
        root = merge(root, rhs.root);
        rhs.root = nullptr;
    }

private:
    struct LeftistNode
    {
        Comparable element;
        LeftistNode *left;
        LeftistNode *right;
        int npl;

        LeftistNode(const Comparable &theElement, LeftistNode *lt = NULL,
                    LeftistNode *rt = NULL, int np = 0)
            : element(theElement), left(lt), right(rt), npl(np)
        {
        }
    };

    LeftistNode *root;
    LeftistNode *merge(LeftistNode *h1, LeftistNode *h2)
    {
            if (h1 == nullptr)
            {
                return h2;
            }
            if (h2 == nullptr)
            {
                return h1;
            }

            if (h1->element > h2->element)
            {
                 return merge1(h1, h2);
            }else
            {
                 return merge1(h2, h1);
            }
    }

    LeftistNode *merge1(LeftistNode *h1, LeftistNode *h2)
    {
        if ( h1 == nullptr)
        {
            h1->left = h2;
        }else
        {
            h1->right = nerge(h1->right, h2);
            if (h1->left->npl < h1->right->npl)
            {
               swapChildren(h1);
            }
            h1->npl = h1->right->npl + 1;
        }
        return h1;
    }

    void swapChildren(LeftistNode *t);
    void reclaimMemory(LeftistNode *t);
    LeftistNode *clone(LeftistNode *t) const;
};


#endif