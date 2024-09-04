#include "includes/RPN.hpp"

RevPolNot::RevPolNot(std::string &input) {
	if (!checkExpression(input)) {
		throw std::invalid_argument("Invalid RPN expression!");
	}
}

int RevPolNot::calculate() {
	std::stack<int> operands;
	std::string token;
	std::stringstream ss(_expression);
	//char *end;
	int result = 0;

	while (std::getline(ss, token, ' ')) {
		if (token.empty()) {
			continue ;
		}
		else if (isValidOperand(token)) {
			operands.push(std::atoi(token.c_str()));
		}
		else if (isValidOperator(token)) {
			if (operands.size() < 2) {
				throw std::runtime_error("Error: Wrong number of operators!");
			}

			int operand2 = operands.top();
			operands.pop();
			int operand1 = operands.top();
			operands.pop();

			char ctok = token.c_str()[0];

			switch (ctok) {
				case '+':
					result = operand1 + operand2; break;
				case '-':
					result = operand1 - operand2; break;
				case '*':
					result = operand1 * operand2; break;
				case '/':
					if (operand2 == 0) {
						throw std::runtime_error("Error: Division by zero!");
					}
					else {
						result = operand1 / operand2; break;
					}
				default:
					throw std::runtime_error("Error: Invalid operator!");
			}

			operands.push(result);
		}
		else {
			throw std::runtime_error("Error: Invalid token!");
		}
	}
	if (operands.size() != 1) {
		throw std::runtime_error("Error: Wrong number of tokens in expression!");
	}

	return (operands.top());
}

RevPolNot::~RevPolNot() {

}

bool RevPolNot::isValidOperator(std::string &token) {
	return (token.length() == 1 && token.find_first_of("+-*/") != std::string::npos);
}

bool RevPolNot::isValidOperand(std::string &token) {
	return (token.length() == 1 && token.find_first_of("0123456789") != std::string::npos);

}

bool RevPolNot::checkExpression(std::string &expression) {
	_expression = expression;
	std::string token;
	std::stringstream ss(expression);

	int operatorsCnt = 0;
	int operandsCnt = 0;

	while (std::getline(ss, token, ' ')) {
		if (token.empty()) {
			continue ;
		}
		else if (isValidOperand(token)) {
			++operandsCnt;
		}
		else if (isValidOperator(token)) {
			++operatorsCnt;
		}
		else {
			std::cerr << BRIGHT_RED "Error: Invalid token: " BRIGHT_MAGENTA "\"" << token << "\"" BRIGHT_RED "!" RESET << std::endl;
			return (false);
		}
	}
	if (operatorsCnt == 0 || operandsCnt == 0 || (operandsCnt - 1 != operatorsCnt)) {
		std::cerr << BRIGHT_RED "Error: Wrong number of operands or operators!" RESET << std::endl;
		return (false);
	}

	return (true);
}
