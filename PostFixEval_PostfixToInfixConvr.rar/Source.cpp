#include <iostream>
#include <string>
#include <cstring>
#include "Stack_.h"

using namespace std;

//simple macro to detect operator
#define isOperator(op) (op=='+'||op=='*'||op=='/'||op=='-')
int applyOperator(int o1, int o2, char oprt)
{
	switch (oprt) {
	case '+': return o1 + o2;
	case '-': return o1 - o2;
	case '*': return o1 * o2;
	case '/': return o1 / o2;
	}
}
int evalPostFix(char *postFixExpr)
{
	Stack_<int> s;
	while (*postFixExpr != '\0')
	{
		char symb = *postFixExpr;
		//int val='5'-'0';
		//c/c++ interprets above expression as val=57-52    ;//57 is the ascii value of '5'
		if (isalnum(symb)) { //one of '0' ...'9' alpha numeric char is encountered
			int val = symb - '0';//conversion of single digit char to int val
			s.push(val);
		}
		else if (isOperator(symb))
		{
			int op2, op1;
			if (s.isEmpty()) {
				cout << "Stack Underflow: (there are more operands than operators)";
				exit(0);
			}
			op2 = s.pop();
			if (s.isEmpty()) {
				cout << "Stack Underflow: (there are more operands than operators)";
				exit(0);
			}
			op1 = s.pop();
			int partialExp = applyOperator(op1, op2, symb);
			s.push(partialExp);
		}
		else
			;//just consume whatever the value in symb 
		postFixExpr++;
	}
	
	if (s.isEmpty())
	{
		cout << "Stack Underflow";
		exit(0);
	}
	int finalResul(s.pop());
	if (!s.isEmpty())
	{
		cout << "Stack Underflow: (there are more operands than operators)";
		exit(0);
	}
	return finalResul;
	
}

string convertPosfixToInfix(char *postFix)
{
Stack_<string> s;
while (*postFix != '\0')
{
	char symb = *postFix;
	//int val='5'-'0';
	//c/c++ interprets above expression as val=57-52    ;//57 is the ascii value of '5'
	
	if (isOperator(symb))
	{
		string op2, op1;
		if (s.isEmpty()) {
			cout << "Stack Underflow: (there are more operands than operators)";
			exit(0);
		}
		op2 = s.pop();
		if (s.isEmpty()) {
			cout << "Stack Underflow: (there are more operands than operators)";
			exit(0);
		}
		op1 = s.pop();
		string partialExp = "(" + op1 + symb + op2 + ")";
		s.push(partialExp);
	}
	else if (iswspace(symb))
	{
		;//just consume whatever the value in symb 
	}
	else {
		string oprand(1,symb);
		s.push(oprand);
	}
	
	postFix++;
}

if (s.isEmpty())
{
	cout << "Stack Underflow";
	exit(0);
}
string finalResul(s.pop());
if (!s.isEmpty())
{
	cout << "Stack Underflow: (there are more operands than operators)";
	exit(0);
}
return finalResul;

}
int main(int argc,char *argv[]) 
{
	char commandLinePostFix[256];
	char *postFix = "6 5 2 3 + 8 * + 3 + * ";
	/*char postFix[] = "6 5 2 3 + 8 * + 3 *";
	string postFix = "6 5 2 3 + 8 * + 3 *";*/
	int res;
	string infix;
	cout << "Argc:" << argc << endl;
	
	if (argc > 1) {
		cout << argv[1] << endl;
		strcpy(commandLinePostFix, argv[1]);
		res = evalPostFix(commandLinePostFix);
		cout << commandLinePostFix << " expression evaluates to :" << res << endl;
		infix = convertPosfixToInfix(commandLinePostFix);
		cout << commandLinePostFix << " equivalent infix expr: " << infix << endl;
	}
	else {
		res = evalPostFix(postFix);
		cout << postFix << " expression evaluates to :" << res << endl;
		infix = convertPosfixToInfix(postFix);
		cout << postFix << " equivalent infix expr: " << infix << endl;
	}
	

	

	return 0;
}