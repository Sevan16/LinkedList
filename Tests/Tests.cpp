#include "CppUnitTest.h"
#include "../Solver/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(NodeCtor_IntData_Success)
		{
            // Arrange & Act
            int data = 1;
            Node* newNode = new Node(data);

            //Assert
            Assert::IsTrue(newNode->data == 1);
		}

		TEST_METHOD(LinkedListCtor_IntData_Success)
		{
			// Arrange & Act
			LinkedList list;

			//Assert
			Assert::IsTrue(list.printList() == "");
		}

		TEST_METHOD(LinkedListPushFront_ValidData_Success)
		{
			// Arrange
			LinkedList list;

			// Act
			list.pushFront(12);
			list.pushFront(13);

			//Assert
			Assert::IsTrue(list.printList() == "13 12 ");
		}
		TEST_METHOD(LinkedListPushBack_ValidData_Success)
		{
			// Arrange
			LinkedList list;

			// Act
			list.pushBack(12);
			list.pushBack(13);

			//Assert
			Assert::IsTrue(list.printList() == "12 13 ");
		}

		TEST_METHOD(LinkedListPopFront_InvalidData_Exception)
		{
			//Arrane & Act & Assert
			Assert::ExpectException<std::logic_error>([]() 
				{
					LinkedList list;
					list.popFront();
				});
		}

		TEST_METHOD(LinkedListPopBack_InvalidData_Exception)
		{
			//Arrane & Act & Assert
			Assert::ExpectException<std::logic_error>([]()
				{
					LinkedList list;
					list.popBack();
				});
		}
	};
}
