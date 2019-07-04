#pragma once

//3.14 针对链表写一个  operator+ 返回一个对应当前位置前k个位置的迭代器
//
//
//
//const_iterator & operator+ (int k)
//{
//	const_iterator advanced = *this;
//	for (int i = 0; i < k; i++)
//		advanced.current = advanced.current->next;
//	return advanced;
//}