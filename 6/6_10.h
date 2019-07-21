// //6_10 a
// void preorder(const int &x)
// {
//     time = 0;
//     preorder(x, 1);
// }

// void preorder(const int &x, int hole)
// {
//     if (hole > currentSize)
//     {
//         return;
//     }

//     if (array[hole] < x)
//     {
//         std::cout << array[hole] << " ,time = " << ++time << std::endl;

//         preorder(x, hole * 2);
//         preorder(x, hole * 2 + 1);
//     }
// }
// //6_10 a