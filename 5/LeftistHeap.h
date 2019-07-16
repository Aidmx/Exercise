


/*   */
#ifndef _LEFTIST_HEAP_H_
#define _LEFTIST_HEAP_H_

#include <vector>

template<typename Comparable>
class LeftistHeap
{
    LeftistHeap();
    LeftistHeap(const LeftistHeap& rhs);
    LeftistHeap(LeftistHeap&& rhs);
    
    ~LeftistHeap();

    LeftistHeap &operator=(const LeftistHeap &rhs);
    LeftistHeap &operator=(LeftistHeap &&rhs);
    bool isEmpty() const { return currentSize <= 0; }
    const Comparable &findMin() const;
    void deleteMin( Comparable & minltem );
    void makeEmpty();
    void merge( LeftistHeap & rhs );

private:
    struct LeftistNode
    {
        Comparable element;
        LeftistNode *left;
        LeftistNode *right;
        int npl;

        LeftistNode(const Comparable &theElement, LeftistNode *lt = NULL,
                    LeftistNode *rt = NULL, int np = 0)
            : element(theElement), left(It), right(rt), npl(np)
        {
        }
    };

    LeftistNode *root;
    LeftistNode *merge(LeftistNode *hl, LeftistNode *h2);
    LeftistNode *merge(LeftistNode *hl, LeftistNode *h2);
    void swapchildren(LeftistNode *t);
    void reclaimMemory(LeftistNode *t);
    LeftistNode *clone(LeftistNode *t) const;
};

#endif