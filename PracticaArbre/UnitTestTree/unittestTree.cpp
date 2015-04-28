#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "../PracticaArbre/Arbre.h"
#include "../PracticaArbre/p2List.h"
#include "../PracticaArbre/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTree
{		
	TEST_CLASS(TestTree)
	{
	public:
		
		TEST_METHOD(Add)
		{
			Tree<int> tree(0);

			tree.Add(300);
			tree.Add(400);
			tree.Add(500);

			Assert::AreEqual(tree.root_node->childs.start->data->data, 300);
			Assert::AreEqual(tree.root_node->childs.end->data->data, 500);
		}
		
		TEST_METHOD(Add2)
		{
			Tree<int> tree(0);
			unsigned int check1 = 2;

			tree.Add( 5, 0);
			tree.Add( 3, 0);
			tree.Add( 2, 5);
			tree.Add( 4, 5);

			
			Assert::AreEqual(tree.root_node->childs.start->data->data, 5);
			Assert::AreEqual(tree.root_node->childs.count(), check1);
			Assert::AreEqual(tree.root_node->CheckParent(5)->childs.count(), check1);
		}
	
		TEST_METHOD(PreOrder_Recursive)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.PreOrder_Recursive(&list);

			Assert::IsTrue(list.count() == 9);

			Assert::IsTrue((char)list[0]->data == 'F');
			Assert::IsTrue((char)list[1]->data == 'B');
			Assert::IsTrue((char)list[2]->data == 'A');
			Assert::IsTrue((char)list[3]->data == 'D');
			Assert::IsTrue((char)list[4]->data == 'C');
			Assert::IsTrue((char)list[5]->data == 'E');
			Assert::IsTrue((char)list[6]->data == 'G');
			Assert::IsTrue((char)list[7]->data == 'I');
			Assert::IsTrue((char)list[8]->data == 'H');
		}
		
		TEST_METHOD(PostOrder_Recursive)
		{
			Tree<char> tree('F');
			
			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');
			
			p2List<TreeNode<char>*> list;
			tree.PostOrder_Recursive(&list);
			
			Assert::AreEqual((int)list.count(), 9);
			
			Assert::IsTrue((char)list[0]->data == 'A');
			Assert::IsTrue((char)list[1]->data == 'C');
			Assert::IsTrue((char)list[2]->data == 'E');
			Assert::IsTrue((char)list[3]->data == 'D');
			Assert::IsTrue((char)list[4]->data == 'B');
			Assert::IsTrue((char)list[5]->data == 'H');
			Assert::IsTrue((char)list[6]->data == 'I');
			Assert::IsTrue((char)list[7]->data == 'G');
			Assert::IsTrue((char)list[8]->data == 'F');
		}

		TEST_METHOD(InOrder_Recursive)
		{
			Tree<char> tree('F');
			
			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');
			
			p2List<TreeNode<char>*> list;
			tree.InOrder_Recursive(&list);
			
			Assert::IsTrue((int)list.count() == 9);
			
			Assert::IsTrue((char)list[0]->data == 'A');
			Assert::IsTrue((char)list[1]->data == 'B');
			Assert::IsTrue((char)list[2]->data == 'C');
			Assert::IsTrue((char)list[3]->data == 'D');
			Assert::IsTrue((char)list[4]->data == 'E');
			Assert::IsTrue((char)list[5]->data == 'F');
			Assert::IsTrue((char)list[6]->data == 'G');
			Assert::IsTrue((char)list[7]->data == 'I');
			Assert::IsTrue((char)list[8]->data == 'H');
		}
		
		TEST_METHOD(PreOrder_Iterative)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.InOrder_Recursive(&list);

			Assert::IsTrue((int)list.count() == 9);

			Assert::IsTrue((char)list[0]->data == 'A');
			Assert::IsTrue((char)list[1]->data == 'B');
			Assert::IsTrue((char)list[2]->data == 'C');
			Assert::IsTrue((char)list[3]->data == 'D');
			Assert::IsTrue((char)list[4]->data == 'E');
			Assert::IsTrue((char)list[5]->data == 'F');
			Assert::IsTrue((char)list[6]->data == 'G');
			Assert::IsTrue((char)list[7]->data == 'I');
			Assert::IsTrue((char)list[8]->data == 'H');
		}
		
		TEST_METHOD(PostOrder_Iterative)
		{
			Tree<char> tree('F');
			
			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');
			
				p2List<TreeNode<char>*> list;
			tree.PostOrder_Iterative(&list);
			
			Assert::IsTrue((int)list.count() == 9);
			
			Assert::IsTrue ((char)list[0]->data == 'A');
			Assert::IsTrue ((char)list[1]->data == 'C');
			Assert::IsTrue ((char)list[2]->data == 'E');
			Assert::IsTrue ((char)list[3]->data == 'D');
			Assert::IsTrue ((char)list[4]->data == 'B');
			Assert::IsTrue ((char)list[5]->data == 'H');
			Assert::IsTrue ((char)list[6]->data == 'I');
			Assert::IsTrue ((char)list[7]->data == 'G');
			Assert::IsTrue ((char)list[8]->data == 'F');
		}

	};
}
