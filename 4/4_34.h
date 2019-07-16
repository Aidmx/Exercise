 
    // BinaryNode* makeRandomTree(Comparable lower, Comparable upper)
    // {
    //     BinaryNode* pNode = nullptr;
    //     if (lower <= upper)
    //     {
    //         Comparable randomValue = randInt(lower, upper);
    //         pNode = new BinaryNode(randomValue,
    //                                makeRandomTree(lower, randomValue - 1),
    //                                makeRandomTree(randomValue + 1, upper));
    //     }
    //     return pNode;
    // }
     
    // void makeRandomBSTree(Comparable lower, Comparable upper)
    // {
    //     if (upper <= lower)
    //     {
    //         return;
    //     }
        
    //     root=makeRandomTree( lower, upper); 
    // }