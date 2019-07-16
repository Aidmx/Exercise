
#ifndef _4_22_H_
#define _4_22_H_
    // //4_22
    // int PostorderCheckHeight(AvlNode *pNode) const
    // {
    //     if (pNode == nullptr)
    //     {
    //         return height(pNode);
    //     }
    //     if ((pNode->left == nullptr) && (pNode->right == nullptr))
    //     {
    //         if (pNode->height != 0)
    //         {
    //             /* 叶子节点高度不是0 就是error*/
    //             std::cout<<"should be height = 0; error height:"<<pNode->height<<std::endl;
    //         }
    //         return height(pNode);
    //     }
    //     //检查高度是否正确， 以及是否平衡
    //     int hleft =  PostorderCheckHeight(pNode->left);
    //     int hright =  PostorderCheckHeight(pNode->right);
    //     int node_height = (std::max(hleft, hright) + 1);
    //     if (pNode->height != node_height)
    //     {
    //         /* error */
    //         std::cout<<"should be height = "<<node_height<<"; error height:"<<pNode->height<<std::endl;
    //         return node_height;
    //     }
    //     if (((hleft - hright) > ALLOW_IMBALANCE) ||(hright - hleft) > ALLOW_IMBALANCE)
    //     {
    //         /* error */
    //         std::cout<<"error:not be balance." <<std::endl;
    //     }
    //     return pNode->height;
    // }
    

//4_22
#endif
