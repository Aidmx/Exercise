
#ifndef _4_26_H_
#define _4_26_H_

// 4_26
    // AvlNode *doubleLeftRotate(AvlNode *k3)
    // {
    //     AvlNode *k1 = k3->left;
    //     AvlNode *k2 = k1->right;
    //     k1->right = k2->left;
    //     k3->left = k2->right;
    //     k2->left = k1;
    //     k2->right = k3;
    //     k1->height =  std::max(height(k1->left), height(k1->right)) + 1;
    //     k3->height =  std::max(height(k3->left), height(k3->right)) + 1;
    //     k2->height =  std::max(height(k2->left), height(k2->right)) + 1;
    //     return k2;
    // }

    // AvlNode *doubleRightRotate(AvlNode *k1)
    // {
    //     AvlNode *k3 = k1->right;
    //     AvlNode *k2 = k3->left;
    //     k1->right = k2->left;
    //     k3->left = k2->right;
    //     k2->left = k1;
    //     k2->right = k3;
    //     k1->height = std::max(height(k1->left), height(k1->right)) + 1;
    //     k3->height = std::max(height(k3->left), height(k3->right)) + 1;
    //     k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    //     return k2;
    // } 
// 4_26
#endif