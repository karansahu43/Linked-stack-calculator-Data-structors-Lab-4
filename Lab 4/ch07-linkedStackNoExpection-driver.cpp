//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "LinkedStack.h"

void copyConstructorTester()
{
	LinkedStack<std::string> stack;
   std::string items[] = {"zero", "one", "two", "three", "four", "five"};
	for (int i = 0; i < 6; i++)
   {
		std::cout << "Pushing " << items[i] << std::endl;
      bool success = stack.push(items[i]);
      if (!success)
         std::cout << "Failed to push " << items[i] << " onto the stack." << std::endl;
	}
   std::cout << "Stack contains, from top to bottom, five four three two one zero." << std::endl;

   LinkedStack<std::string> copyOfStack(stack);
   std::cout << "Copy of stack contains, from top to bottom, ";
	for (int i = 0; i < 6; i++)
   {
      std::cout << " " << copyOfStack.peek();
      copyOfStack.pop();
   }
   std::cout << "." << std::endl;
   
   std::cout << "Original stack contains, from top to bottom,";
	for (int i = 0; i < 6; i++)
   {
      std::cout << " " << stack.peek();
      stack.pop();
   }
   std::cout << "." << std::endl;
}  // end copyConstructorTester

void stackTester()
{
	StackInterface<std::string>* stackPtr = new LinkedStack<std::string>();
	std::cout << "\nTesting the Link-Based Stack:" <<std::endl;
   
	std::string items[] = {"zero", "one", "two", "three", "four", "five"};
	std::cout << "Empty: " << stackPtr->isEmpty() << std::endl;
	for (int i = 0; i < 6; i++)
   {
		std::cout<<"Pushing " << items[i] << std::endl;
      bool success = stackPtr->push(items[i]);
      if (!success)
         std::cout << "Failed to push " << items[i] << " onto the stack." << std::endl;
	}
   
	std::cout << "Empty?: " << stackPtr->isEmpty() << std::endl;
	
	for (int i = 0; i < 5; i++)  // NEEDS TO BE 5 TO AVOID ASSERT ERROR
   {
		std::cout << "Loop " << i << std::endl;
      std::cout << "peek1: " << stackPtr->peek() << std::endl;
		std::cout << "pop: " << stackPtr->pop() << std::endl;
		std::cout << "Empty: " << stackPtr->isEmpty() << std::endl;
	}
	std::cout << "Empty: " << stackPtr->isEmpty() << std::endl;
   
   std::cout << "pop an empty stack: " << std::endl;
	std::cout << "pop: " << stackPtr->pop() << std::endl; // nothing to pop!
   
   std::cout << "peek into an empty stack: " << std::endl;
	std::cout << "peek: " << stackPtr->peek() << std::endl; // nothing to peek!
}  // end stackTester

int main()
{
   copyConstructorTester();
   stackTester();
   return 0;
}  // end main

/*
 Pushing zero
 Pushing one
 Pushing two
 Pushing three
 Pushing four
 Pushing five
 Stack contains, from top to bottom, five four three two one zero.
 Copy of stack contains, from top to bottom,  five four three two one zero.
 Original stack contains, from top to bottom, five four three two one zero.
 
 Testing the Link-Based Stack:
 Empty: 1
 Pushing zero
 Pushing one
 Pushing two
 Pushing three
 Pushing four
 Pushing five
 Empty?: 0
 Loop 0
 peek1: five
 pop: 1
 Empty: 0
 Loop 1
 peek1: four
 pop: 1
 Empty: 0
 Loop 2
 peek1: three
 pop: 1
 Empty: 0
 Loop 3
 peek1: two
 pop: 1
 Empty: 0
 Loop 4
 peek1: one
 pop: 1
 Empty: 0
 Empty: 0
 pop an empty stack:
 pop: 1
 peek into an empty stack:
 Assertion failed: (!isEmpty()), function peek, file /Users/Frank/Desktop/Test/Tester/Tester/LinkedStack.cpp, line 106.
 peek: 
*/
