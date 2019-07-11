    // //4_46
    // static bool isomorphis(BinaryNode* a, BinaryNode* b)
    // {
    //     if ((a==nullptr) && (b==nullptr))
    //     {
    //        return true;
    //     }
    //     if ((a==nullptr) || (b==nullptr))
    //     {
    //         return false;
    //     }
    //     if (a->element != b->element)
    //     {
    //         return false;
    //     }

    //     return (isomorphis(a->left, b->left) && isomorphis(a->right, b->right)) 
    //         || (isomorphis(a->left, b->right) && isomorphis(a->right, b->left));
    // }