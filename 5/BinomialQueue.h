
/*   */
#ifndef _BINOMIAL_QUEUE_H_
#define _BINOMIAL_QUEUE_H_

template<typename Comparable>
class BinomialQueue
{
private:
    /* data */
public:
    BinomialQueue();
    explicit BinomialQueue(const Comparable &rhs);
    explicit BinomialQueue(Comparable &&rhs);

    ~BinomialQueue();

    Comparable &operator=(const Comparable &rhs);
    Comparable &operator=(Comparable &&rhs);


    bool isEmpty() const;
    const Comparable &findMin() const;
    void insert(const Comparable &rhs);
    void insert(Comparable&& minltem);
    
    void deleteMin();
    void deleteMin(Comparable & minltem);

    void makeEmpty();
    void merge(BinomialQueue &ths);

private:
    struct BinomialNode
    {
        Comparable element;
        BinomialNode* leftChild;
        BinomialNode* nextSibling;

        BinomialNode(const Comparable& e, BinomialNode* lt, BinomialNode* rt)
        : element{e},leftChild{lt},nextSibling{rt}
        {

        }

        BinomialNode(Comparable&& e, BinomialNode* lt, BinomialNode* rt)
        : element{std::move(e)},leftChild{lt},nextSibling{rt}
        {

        }


        cosnt static int DEFAULT_TREES = 1;
        std::vector<BinomialNode*> theTrees;
        int currentSize;

        int findMinIndex() const;
        int capacity() const;
        BinomialNode* combineTrees(BinomialNode* t1, BinomialNode* t2);
        void makeEmpty(BinomialNode*& t);
        BinomialNode* clone(BinomialNode* t) const;

    };
}; 



#endif