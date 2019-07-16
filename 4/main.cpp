
//add by allen
//3.6 answer

#include <iostream>
#include <ctime>
#include "4_18.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "4_50.h"
#include "4_30.h"

using namespace std;
#define random(x) (rand()%x)

int main(int arg, char* argv[])
{
	//const int m = 50000000;
	//const int n = 10000;
	//Questions_3_6 test;
	//clock_t start, end;

	//start = clock();
	//test.Answer(m, n);
	//end = clock();
	//std::cout << "lei time used:" << ((double)(end - start) / CLOCKS_PER_SEC) << std::endl;

	//start = clock();
	//test.AnswerBook(m, n);
	//end = clock();
	//std::cout << "Correct time used:" << ((double)(end - start) / CLOCKS_PER_SEC) << std::endl;

	//3.22 后缀表达式
	//string expression = "6.1 1.2 + /1 =";
	//PostfixExpression test; 
	//test.DoCalculate(expression);
	//std::cout << expression << " ;result is = " << test.mResult << std::endl;
	//4.2 4.6 4.10 4.14 4.18 4.22 4.26 4.30 4.34,4.38 4.42 4.46 4.50
	// cout<<Fib1(15)<<endl;
	// cout<<Fib2(15)<<endl;
	// BinarySearchTree<int> tree;
	// for (int i = 0; i < 30; i++)
	// {
	// 	tree.insert( i);
	// }

	// std::cout<<"BST "<<std::endl;
	// std::cout<<"Preorder"<<std::endl;
	// tree.Preorder(tree.root);
	// std::cout<<"Postorder" <<std::endl;
	// tree.Postorder(tree.root);
	// std::cout<<"Inorder"<<std::endl;
	// tree.Inorder(tree.root);

	// AvlTree<int> avl;
	// for (int i = 0; i < 3; i++)
	// {
	// 	avl.insert( i);
	// }

	// avl.root->height = 5;
	// std::cout<<"AVL "<<std::endl;
	// std::cout<<"Preorder"<<std::endl;
	// avl.Preorder(avl.root);
	// std::cout<<"Postorder" <<std::endl;
	// avl.Postorder(avl.root);
	// std::cout<<"Inorder"<<std::endl;
	// avl.Inorder(avl.root);

	// int root_height = avl.PostorderCheckHeight(avl.root);
	// std::cout<<"root height check= "<<root_height<<"  save= "<<avl.root->height<<std::endl;

	// BinarySearchTree<int> tree;
	// tree.makeRandomBSTree(1,30);
	// std::cout<<"level"<<std::endl;
	// tree.LevelOrder(tree.root);

	// int x[] = {15,7,3,5,4,11,9,25,19,20,23,21,24};
	// BinarySearchTree<int> a;
	// BinarySearchTree<int> b;
	// for (int i = 0; i < 13; i++)
	// {
	// 	a.insert(x[i]);
	// 	b.isomorphis_insert(x[i]);
	// }
	// if (BinarySearchTree<int>::isomorphis(a.root, b.root))
	// {
	// 	std::cout << "isomorphis is true" << std::endl;
	// }else
	// {
	// 	std::cout << "isomorphis is false"  << std::endl;
	// }
	// load_cpp_file("D:/Projects/Exercise/4/test_file.cpp");

    SplayTree splayTree;
	BinarySearchTree<int> BSTree;
	AvlTree<int> AvlTree;
	for (int i = 0; i < 30; i++)
	{
		int value =random(100); 
		splayTree.InsertSplayTree(value);
		BSTree.insert(value);
		AvlTree.insert(value);
	}
	
	cout<<"splay tree rotate times =" <<splayTree.SplayTimes()<<endl; 
	cout<<"splay tree rotate times =" <<splayTree.SplayTimes()<<endl; 
	cout<<"splay tree rotate times =" <<splayTree.SplayTimes()<<endl; 

	return 0; 
}
