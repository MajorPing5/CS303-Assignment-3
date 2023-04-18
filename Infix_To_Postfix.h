#ifndef INFIX_TO_POSTFIX_H_
#define INFIX_TO_POSTFIX_H_

#include "Syntax_Error.h"
#include <string>
#include <stack>

/* Class to convert infix expressions to postfix expressions. */
class Infix_To_Postfix {
	public:
		/*Extracts and processes each token in infix and returns the equivalent postfix string.
		  @param expression The infix expression
		  @returns The equivalent postfix expression
		  @throws Syntax_Error
		*/
		std::string convert(const std::string& expression);

	private:
		/* Function to process operators.
		   @param op The operator
		   @throws Syntax_error
		*/
		void process_operator(char op);

		/* Determines whether a character is an operator.
		   @param ch The character to be tested
		   @return true if the character is an operator
		*/
		bool is_operator(char ch) const {
			return OPERATORS.find(ch) != std::string::npos;
		}

		/* Determines the precedence of an operator.
		   @param op The operator
		   @return The precedence
		*/
		int precedence(char op) const {
			return PRECEDENCE[OPERATORS.find(op)];
		}

		// Data fields
		static const std::string OPERATORS;
		static const int PRECEDENCE[];
		std::stack<char> operator_stack;
		std::string postfix;
};

#endif