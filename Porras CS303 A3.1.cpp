/*Objectives:
	1. Read an infix expression from the user
	2. Perform Balanced Parenthesis Check on read expression
	3. {},(),[] are the only symbols considered for check. All other characters can be ignored.
	4. If expression fails Balanced Parentheses Check, report a message to user that expression is invalid.
	5. If expression passes Balanced Parenthesis Check, convert from infix to postfix expression and display to user.
	6. Operators to be considered are =,-,*,/,%
------------------------------------------
Current Bug: 
	Program passes Balanced Expression, but includes parenthesis in output.

	Example in use: "w - ( 5.1 / sum ) * 2" == "w 5.1 sum / 2 * -"
	Results in: "w 5.1 sum ) / 2 * ( -"; Issue is NO PARENTHESIS should be shown!
----------------------------------------
*/
#include <stack>
#include <string>
#include <iostream>
#include "Infix_To_Postfix.h"
using namespace std;

// The set of opening parentheses.
const string OPEN = "([{";
// The corresponding set of closing parentheses.
const string CLOSE = ")]}";

/*	Function to determine whether a character is one of the opening
	parenheses (defined in constant OPEN).
	@param ch		Character to be tested
	@return true	If the character is an opening parenthesis
*/
bool is_open(char ch) {
	return OPEN.find(ch) != string::npos;
}

/*	Function to determine whether a character is one of the closing
	parentheses (defined in constant CLOSE).
	@param ch		Character to be tested
	@return	true	If the character is a closing parenthesis
*/
bool is_close(char ch) {
	return CLOSE.find(ch) != string::npos;
}

/*	Test the input string to see that it contains balanced parentheses. This function tests an input string to see
	that each typoe of parenthesis is balanced. '(' is matched with ')', '[' is matched with ']', and '{' is matched with '}'.
	@param expression	A string containing the expression to be examined
	@return true		If all parenthesis match
*/
bool is_balanced(const string& expression) {
	//A stack for the opening parentheses that haven't been matched
	stack<char> s;
	bool balanced = true;
	string::const_iterator iter = expression.begin();
	while (balanced && (iter != expression.end())) {
		char next_ch = *iter;
		if (is_open(next_ch)) {
			s.push(next_ch);
		} else if (is_close(next_ch)) {
			if (s.empty()) {
				balanced = false;
			} else {
				char top_ch = s.top();
				s.pop();
				balanced = OPEN.find(top_ch) == CLOSE.find(next_ch);
			}
		}
		++iter;
	}
	return balanced && s.empty();
}

int main() {
	Infix_To_Postfix infix_to_postfix;
	cout << "Enter an expression to be converted, or press Return when done\n";
	string expression;
	while (getline(cin, expression) && (expression != "")) {
		cout << expression;
		if (is_balanced(expression)) {
			cout << " is balanced\n";
				try {	//Double Checker in case Balanced Parenthesis Check fails to catch missing parenthesis, and to verify correct output
					string result = infix_to_postfix.convert(expression);
					cout << "== " << result << endl;
				}
				catch (Syntax_Error& ex) {
					cout << "Syntax Error: " << ex.what() << endl;
				}
		} else {
			cout << " is not balanced/n";
		}
		cout << "Enter another expression: ";
	}
	return 0;
}