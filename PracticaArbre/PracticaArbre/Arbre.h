#ifndef __ARBRE_H__
#define __ARBRE_H__

#include <iostream>

#include "p2List.h"
#include "Stack.h"

// Tree node -------------------------------------------------------
template<class T>
struct TreeNode
{
	T						data;
	TreeNode<T>*			parent;
	p2List<TreeNode<T>*>	childs;

	void PreOrder_Recursive(p2List<TreeNode<T>*>* list)
		 {
			list->Add(this);
		
			p2List_item<TreeNode*>* item = childs.start;
		
			for (; item != NULL; item = item->next)
			 item->data->PreOrder_Recursive(list);
		}

	void PostOrder_Recursive(p2List<TreeNode<T>*>* list)
	{
		p2List_item<TreeNode*>* item = childs.start;

		for (; item != NULL; item = item->next)
			item->data->PostOrder_Recursive(list);

		list->Add(this);
	}

	void InOrder_Recursive(p2List<TreeNode<T>*>* list)
	{
		p2List_item<TreeNode*>* item = childs.start;
		unsigned int mid = childs.count() / 2;

		for (unsigned int i = 0; i < mid; ++i, item = item->next)
			item->data->InOrder_Recursive(list);

		list->Add(this);

		for (; item != NULL; item = item->next)
			item->data->InOrder_Recursive(list);
	}

	TreeNode<T>* CheckParent(const T& node)
	{
		if (node == data)
			return this;

		TreeNode<T>* result = NULL;
		p2List_item<TreeNode*>* item = childs.start;
		for (; item != NULL; item = item->next)
		{
			TreeNode* child = item->data;
			result = child->CheckParent(node);

			if (result != NULL)
				break;
		}

		return result;
	}

};

template<class T>

class Tree
{

public:
	TreeNode<T>*	root_node;

public:

	Tree(const T& r_data)
	{
		root_node = new TreeNode<T>;
		root_node->data = r_data;
		root_node->parent = NULL;

	}

	virtual ~Tree()
	{
		//Clear();
	}

	TreeNode<T>* Add(const T& data)
	{
		TreeNode<T>* node = new TreeNode<T>;
		node->data = data;
		root_node->childs.Add(node);
		return node;
	}

	TreeNode<T>* Add(const T& data, const T& parent)
		{	
				TreeNode<T>* NewNode = new TreeNode<T>;
				TreeNode<T>* Parent = root_node->CheckParent(parent);
				NewNode->data = data;
				Parent->childs.Add(NewNode);
				return NewNode;
		}

	void PreOrder_Recursive(p2List<TreeNode<T>*>* list)
	{
		root_node->PreOrder_Recursive(list);
	}

	void PostOrder_Recursive(p2List<TreeNode<T>*>* list)
	{
		root_node->PostOrder_Recursive(list);
	}

	void InOrder_Recursive(p2List<TreeNode<T>*>* list)
	{
		root_node->InOrder_Recursive(list);
	}
	
	void PreOrder_Iterative(p2List<TreeNode<T>*>* list)
	{
		Stack<TreeNode<T>*> stack;
		TreeNode<T>* NewNode = root_node;

		while (NewNode != NULL || stack.Pop(NewNode)==true)
		{
			list->Add(NewNode);

			p2List_item<TreeNode<T>*>* item_list = NewNode->childs.end;
			for (; item_list != NewNode->childs.start; item_list = item_list->prev)
				stack.PushBack(item_list->data);

			NewNode = (item_list != NULL) ? item_list->data : NULL;
		}
	}

	void PostOrder_Iterative(p2List<TreeNode<T>*>* list)
	{
		Stack<TreeNode<T>*> stack;
		TreeNode<T>* NewNode = root_node;

		while (NewNode != NULL || stack.Pop(NewNode))
		{
			p2List_item<TreeNode<T>*>* item_list = NewNode->childs.end;

			if (item_list != NULL && list->find(item_list->data) == -1)
			{
				stack.PushBack(NewNode);
				for (; item_list != NewNode->childs.start; item_list = item_list->prev)
					stack.PushBack(item_list->data);

				NewNode = item_list->data;

			}
			else
			{
				list->Add(NewNode);
				NewNode = NULL;
			}
		}

		/*

	void InOrder_Iterative(p2List<TreeNode<T>*>* list)
	{
	Stack<TreeNode<T>*> stack;
	TreeNode<T>* NewNode = root_node;

	while (NewNode != NULL || stack.Pop(NewNode))
	{
	list->Add(NewNode);

	p2List_item<TreeNode<T>*>* item = NewNode->childs.end;
	for (; item != NewNode->childs.start; item = item->prev)
	stack.PushBack(item->data);

	NewNode = (item != NULL) ? item->data : NULL;
	}
	}

	void Clear()
	{
	p2List<TreeNode<T>*> nodes_deleted;
	root_node.CollectAll(&nodes_deleted);

	DNode<TreeNode<TreeData>*>* item = nodes_deleted.getFirst();

	for (; item != NULL; item = item->next)
	{
	TreeNode<TreeData>* son = item->data;

	if (son->parent)
	{
	son->parent->RemoveChild(son);
	}
	}
	}

	/*
	void Clear()
	{
	p2List<TreeNode<T>*> results;

	p2List_item<TreeNode<T>*>* item = results.start;
	for (; item != NULL; item = item->next)
	{
	TreeNode<T>* child = item->data;
	if (child->parent)
	child->parent->childs.del();
	}
	}

	/*void Clear(TreeNode<T> d_node)
	{
	if (d_node == NULL)
	{
	root_node.Clear();
	}

	else
	{
	d_node.Clear();
	d_node.parent->childs.del();
	}
	}
	*/
	}
};
#endif //__ARBRE_H__