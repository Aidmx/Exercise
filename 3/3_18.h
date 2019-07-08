#pragma once
#include <list>

//template<class _Value_type,
//	class _Voidptr>
//	struct _list_node
//{	// list node
//_Node 中添加一个 bool 标记这个 节点是否 失效(被erase)
// erase 并不是真的删除 node，而是 node.bool = false;
// 调用之前 先判断 node.bool == true;
// 
/*
 * 
template<class _Value_type,
	class _Voidptr>
	struct _List_node
		{	// list node
		using _Nodeptr = _Rebind_pointer_t<_Voidptr, _List_node>;
		_Nodeptr _Next;	// successor node, or first element if head
		_Nodeptr _Prev;	// predecessor node, or last element if head
		_Value_type _Myval;	// the stored value, unused if head

		_List_node& operator=(const _List_node&) = delete;

		template<class _Alloc>
			static void _Freenode0(_Alloc& _Al, _Nodeptr _Ptr) noexcept
			{
			using _Alnode = _Rebind_alloc_t<_Alloc, _List_node>;
			using _Alnode_traits = allocator_traits<_Alnode>;
			_Alnode _Node_alloc(_Al);
			_Alnode_traits::destroy(_Node_alloc, _STD addressof(_Ptr->_Next));
			_Alnode_traits::destroy(_Node_alloc, _STD addressof(_Ptr->_Prev));
			_Alnode_traits::deallocate(_Node_alloc, _Ptr, 1);
			}
		};

 */



typedef struct Node
{
	bool mStale;
	struct Node* mNext;
} Node;


class CustomList
{
public:
	CustomList()
	{ 
	}

	Node* erase(Node* pNode)
	{
		if (pNode != nullptr)
		{
			if (pNode->mStale != false)
			{
				pNode->mStale = false;
				return pNode->mNext;
			}
		}
		return nullptr;
	}

	std::list<int> mList;
};

