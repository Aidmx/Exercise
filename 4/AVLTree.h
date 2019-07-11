#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include<iostream>

template <typename Comparable>
class AvlTree
{
public:
    AvlTree() : root{nullptr}
    {
    }

    AvlTree(const AvlTree &rhs) :root{nullptr}
    {
        root = clone(rhs.root);
    }

    AvlTree(AvlTree &&rhs) :root{nullptr}
    {
        root = clone(rhs.root);
    }
    ~AvlTree()
    {
        makeEmpty(root);
    }

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    bool contains(const Comparable &x) const
    {
        return contains(x, root);
    }

    bool isEmpty() const;

    void insert(const Comparable &x)
    {
        insert(x, root);
    }
    void insert(Comparable &&x)
    {
        insert(x, root);
    }
    void remove(const Comparable &x)
    {
        remove(x, root);
    }

    AvlTree &operator=(const AvlTree &rhs);
    AvlTree &operator=(AvlTree &&rhs);

public:
    static const int ALLOW_IMBALANCE = 1;
    typedef struct AvlNode
    {
        Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const Comparable &theElement, AvlNode *pleft, AvlNode *pRight, int pHeight = 0)
            : element{theElement}, left{pleft}, right{pRight}, height(pHeight)
        {
        }

        AvlNode(Comparable &&theElement, AvlNode *pleft, AvlNode *pRight, int pHeight = 0)
            : element{std::move(theElement)}, left{pleft}, right{pRight}, height(pHeight)
        {
        }

    } AvlNode;
 
    AvlNode *root;
    
    void printNode(AvlNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return;
        }
        std::cout << pNode->element << std::endl;
    }

    //先序
    void Preorder(AvlNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return;
        }
        
        printNode(pNode);
        Preorder(pNode->left);
        Preorder(pNode->right);
    }
    //后序
    void Postorder(AvlNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return;
        }
        
        Postorder(pNode->left);
        Postorder(pNode->right);
        printNode(pNode);
    }
    //中序
    void Inorder(AvlNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return;
        }
        
        Inorder(pNode->left);
        printNode(pNode);
        Inorder(pNode->right);
    }

private:
    void insert(const Comparable &x, AvlNode *&t)
    {
        if (t == nullptr)
        {
            t = new AvlNode{x, nullptr, nullptr};
        }else if(x < t->element)
        {
            insert(x, t->left);
        }else if(x > t->element)
        {
            insert(x, t->right);
        }

        balance(t); 
    }
    void insert(Comparable &&x, AvlNode *&t)
    {
        if (t == nullptr)
        {
            t = new AvlNode{x, nullptr, nullptr};
        }
        else if (x < t->element)
        {
            insert(std::move(x), t->left);
        }
        else if (x > t->element)
        {
            insert(std::move(x), t->right);
        }
        
        balance(t);
    }

    void remove(const Comparable &x, AvlNode *&t)
    {
        if (t == nullptr)
        {
            return;
        }
        else if (x < t->element)
        {
            remove(x, t->left);
        }
        else if (x > t->element)
        {
            remove(x, t->right);
        }
        else if ((t->left != nullptr) && (t->right != nullptr))
        {
            AvlNode *min = findMin(t->right);
            if (min != nullptr)
            {
                t->element = min->element;
                remove(t->element, t->right);
            }
        }
        else
        {
            AvlNode *old = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete old;
        }

        balance(t);
    }

    AvlNode *findMin(AvlNode *t) const
    {
        if (t != nullptr)
        {
          while (t->left != nullptr)
          {
              t = t->left;
          }
        }
        return t;

        //递归
        // if (t == nullptr)
        // {
        //     return nullptr;
        // }
        // else if (t->left == nullptr)
        // {
        //     return t;
        // }else
        // {
        //     return findMin(t->left);
        // } 
    }
    AvlNode *findMax(AvlNode *t) const
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        while (t->right != nullptr)
        {
             t=t->right;
        }
        return t;
    }

    bool contains(const Comparable &x, AvlNode *&t)
    {
        if (t==nullptr)
        {
            return false;
        }
        else if (t->element < x)
        {
          return contains(t->right);
        }
        else if (t->element > x)
        {
          return contains(t->left);
        }
        else
        {
            return true;
        }
    }

    AvlNode *clone(AvlNode *t) const
    {
        if (t != nullptr)
        {
            return new AvlNode(t->element, clone(t->left), clone(t->right));
        }
        else
        {
            return nullptr;
        }
    }

    void makeEmpty(AvlNode* t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = nullptr;
        }
    }

    int height(AvlNode* t) const
    {
          return (t == nullptr ) ? -1 : t->height;
    }

    void rotateWithRightChild(AvlNode*& k2)
    {
        AvlNode* k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height =  std::max(height(k2->left), height(k2->right)) +1;
        k1->height =  std::max(height(k1->right), k2->height) +1;
        k2 = k1;
    }

    void rotateWithLeftChild(AvlNode*& k2)
    {
        AvlNode* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height =  std::max(height(k2->left), height(k2->right)) +1;
        k1->height =  std::max(height(k1->left), k2->height) +1;
        k2 = k1;
    }
    void doubleWithLeftChild(AvlNode *&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(AvlNode *&k3)
    {
        rotateWithLeftChild(k3->left);
        rotateWithRightChild(k3);
    }
// 4_26
    AvlNode *doubleLeftRotate(AvlNode *k3)
    {
        AvlNode *k1 = k3->left;
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k3->left = k2->right;
        k2->left = k1;
        k2->right = k3;
        k1->height =  std::max(height(k1->left), height(k1->right)) + 1;
        k3->height =  std::max(height(k3->left), height(k3->right)) + 1;
        k2->height =  std::max(height(k2->left), height(k2->right)) + 1;
        return k2;
    }

    AvlNode *doubleRightRotate(AvlNode *k1)
    {
        AvlNode *k3 = k1->right;
        AvlNode *k2 = k3->left;
        k1->right = k2->left;
        k3->left = k2->right;
        k2->left = k1;
        k2->right = k3;
        k1->height = std::max(height(k1->left), height(k1->right)) + 1;
        k3->height = std::max(height(k3->left), height(k3->right)) + 1;
        k2->height = std::max(height(k2->left), height(k2->right)) + 1;
        return k2;
    } 
// 4_26

    void balance(AvlNode*& t)
    {
        if (t == nullptr)
        {
            return;
        }

        if ((height(t->left)-height(t->right)) > ALLOW_IMBALANCE)
        {
            if (height(t->left->left) >= height(t->left->right))
            {
                rotateWithLeftChild(t);
            }
            else
            {
                doubleLeftRotate(t);
                // doubleWithLeftChild(t);
            }
        }
        else if ((height(t->right)-height(t->left)) > ALLOW_IMBALANCE)
        {
            if (height(t->right->right) >= height(t->right->left))
            {
                rotateWithRightChild(t);
            }else
            { 
                doubleRightRotate(t);
                // doubleWithRightChild(t);
            }
        }
        t->height =  std::max(height(t->left), height(t->right)) + 1;
    }

public:
    //4_22
    int PostorderCheckHeight(AvlNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return height(pNode);
        }
        if ((pNode->left == nullptr) && (pNode->right == nullptr))
        {
            if (pNode->height != 0)
            {
                /* 叶子节点高度不是0 就是error*/
                std::cout<<"should be height = 0; error height:"<<pNode->height<<std::endl;
            }
            return height(pNode);
        }
        //检查高度是否正确， 以及是否平衡
        int hleft =  PostorderCheckHeight(pNode->left);
        int hright =  PostorderCheckHeight(pNode->right);
        int node_height = (std::max(hleft, hright) + 1);
        if (pNode->height != node_height)
        {
            /* error */
            std::cout<<"should be height = "<<node_height<<std::endl<<"; error height:"<<pNode->height<<std::endl;
        }
        if (((hleft - hright) > ALLOW_IMBALANCE) ||(hright - hleft) > ALLOW_IMBALANCE)
        {
            /* error */
            std::cout<<"error:not be balance." <<std::endl;
        }
        return pNode->height;
    }
    
    //4_22
};

#endif