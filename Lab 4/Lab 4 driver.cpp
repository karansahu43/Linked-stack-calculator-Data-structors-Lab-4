// Author:  Karan Sahu
// Assignment Number: Lab 4
// File Name: KaranSahuLab4.cpp
// Course/Section: data struct
// Due Date:  11/1/18
// Instructor: Bernard Ku


#include <iostream>
#include <string>
#include "LinkedStack.h"
#include <fstream>
using namespace std;

//This function returns an integer value used by the main program to check if its an operator or an operand. It take a char parameter which is a character in the 
//postfix string.
int checkcharacter(char C)
{
	int checker = 0;
	if(C == '0'|| C == '1' || C == '2' || C == '3'|| C == '4' || C == '5'||C == '6'|| C == '7' || C == '8' || C == '9' )
		checker = 1;
	else if(C == '*'|| C == '-'|| C == '+'|| C == '/')
		checker = 2;
		
	return checker;
	
	
}

//This function returns an integer value which is the result of the postfix equation. It takes in 3 paramter: the first is an integer which is the first operand for
//the calculation, the second is an integer which is the second operand for the calculation, the third is a char which is the operator for the calculation.
int calculator(int op1, int op2, char C)
{
	int result;
	if(C == '+')
		result = op1 + op2;
	else if(C == '-')
		result = op2 - op1;
	else if(C == '*')
		result = op1 * op2;
	else if(C == '/')
		result = op2 / op1;
	else
	{
		cout << "\n Somthing went wrong in calculator"<< endl;
		result = 0;
	}
	return result;
}

//This function returns a bool value which is going to be used in the main function to check if there is issues with the postfix string related to invalid characters 
//or operators. This function takes a string parameter which is the postfix string that is being tested for those issues.
bool isStringValid(string S)
{
	for(int i = 0; i < S.size(); i++)
	{
		if(!(S[i] == '0'|| S[i] == '1' || S[i] == '2' || S[i] == '3'|| S[i] == '4' ||
		 S[i] == '5'|| S[i] == '6'|| S[i] == '7' || S[i] == '8' || S[i] == '9'|| S[i] == '*'|| S[i] == '-'|| S[i] == '+'|| S[i] == '/' ))
		{
			if(S[i] != '%')
				cout << "\n" << S << "  Malformed expression - invalid operand character detected " << endl;
			else if(S[i] =='%')
				cout << "\n" << S << "  Malformed expression - invalid operator detected " << endl;
			return false;
		}
	}

	return true;

	
}

//The main function will pull the strings out of the file and use the functions to ultimetly do error checking, printing, and calculations for the postfix expressions
int main () {

	string line[20]; 
	string holder;
	int intHolder;
	bool valid;
	int checker;
	int op1, op2, result;
	
	LinkedStack<int> object1;
	
	ifstream myfile ("postfix.txt");
	if (myfile.is_open())
	{
    	for(int i = 0; i < 12; i++ )
    	{
      		getline (myfile,line[i]);
    	}
	}
	else 
		cout << "Unable to open the file";
	myfile.close();
	

	for(int i = 0; i < 12; i++ )
	{
		if(isStringValid(line[i]))					
		{
			holder = line[i];
			for(int j= 0; j < holder.size(); j++)
			{
				checker = checkcharacter(holder[j]);
				if(checker == 1)
				{
					intHolder = holder[j] - '0';
					object1.push(intHolder);
				}
				else if (checker == 2)
				{
					if(!(object1.isEmpty()))
					{	
						
						op1 = object1.peek();
						object1.pop();
					}
					else
					{
						continue;
					}
					if((!object1.isEmpty()))
					{
						op2 = object1.peek();
						object1.pop();
						valid = true;
					}
					else
					{
						valid = false;
					}
					
					if(valid == true)
					{
						result = calculator(op1, op2, holder[j]);
						object1.push(result);
					}
					else if(valid == false)
						break;
				}
			}
			if(valid == true)
			{
				cout << endl << line[i] << " = " << object1.peek() << endl;
				object1.pop();
			}
			else cout << "\n" << line[i] << "  Malformed expression - invalid postfix " << endl;
		}
		else 
		{
			continue;
		}
		
		
	}



  return 0;
}

// 		Sample output
//
//	345*+67*8+9*+ = 473
//
//	1234*+5/- = -1
//
//	12+43-* = 3
//
//	48+65-*32-22+*/ = 3
//
//	234+* = 14
//
//	72/ = 3
//
//	512+4*+3- = 14
//
//	72%  Malformed expression - invalid operator detected
//
//	7*22+  Malformed expression - invalid postfix
//
//	A2/  Malformed expression - invalid operand character detected
//
//	72//  Malformed expression - invalid postfix
//
//	(23-  Malformed expression - invalid operand character detected


