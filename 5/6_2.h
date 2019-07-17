/*  a
//            1
//       /         \
//      3            2
//    /   \       /    \
//   6     7      5      4
//  / \    / \    / \    / \
// 15  14  12 9   10 11  13 8 
*/
/*
    b  
        
    void percolateUp(int hole)
    {
        for (; hole  > 1; hole/=2)
        {
            //如果array[hole]比父节点的优先级大，将其上浮
            if (array[hole] > array[hole / 2])
            {
                swap(array[hole] ,std::move(array[hole / 2]));
            }
        } 
    }
 */
