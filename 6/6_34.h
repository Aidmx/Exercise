// void insert(const Comparable &rhs)
// {
//     //是否扩容
//     currentSize += 1;
//     if (currentSize > capacity())
//     {
//         int oldTrees = theTrees.size();
//         int newTress = std::max(theTrees.size(), 1) + 1;
//         theTrees.resize(newTress);
//         for (int i = oldTrees; i < newTress; i++)
//         {
//             theTrees[i] = nullptr;
//         }
//     }
//     //构建新节点
//     BinomialNode *carry = new BinomialNode(rhs, nullptr, nullptr);
//     int index = 0;
//     while (theTrees[index] != nullptr)
//     {
//         carry = combineTrees(theTrees[index], carry);
//         theTrees[index] = nullptr;
//         index++;
//     }
//     theTrees[index] = carry;
// }
