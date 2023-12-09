#include "RPN.hpp"

const std::string RPN::ACCEPTED_NUMERIC_OPERATIONS = "+-*/";

double RPN::plus( double rvalue, double lvalue ) { return (lvalue + rvalue); }
double RPN::minus( double rvalue, double lvalue ) { return (lvalue - rvalue); }
double RPN::divide( double rvalue, double lvalue ) { if (rvalue == 0) throw std::runtime_error(ERR_ZERO_EXC); return (lvalue / rvalue); }
double RPN::multiply( double rvalue, double lvalue ) { return (lvalue * rvalue); }

RPN::RPN( void ) {}
RPN::RPN( const RPN & ) {}
RPN::~RPN() {}
void RPN::operator=( const RPN & ) {}

void RPN::executeExpression( char * expression ) {
	if (!expression)
		throw std::runtime_error(ERR_WRONG_ARG_LIST);

	const std::string expr(expression);
	const std::string *exprList;
	size_t expressionListSize = 0;

	exprList = RPN::split(expr, ' ', expressionListSize);

	try {
		if (!expressionListSize)
			throw std::runtime_error("");
		for (size_t i = 0; i < expressionListSize; i++) {
			if (!isValidExpressionItem(exprList[i]))
				throw std::runtime_error("");
		}
	} catch (...) {
		delete[] exprList;
		throw std::runtime_error(ERR_WRONG_EXPR);
	}

	std::stack<double> expressionStack;
	double rvalue, lvalue;
	ExecuteOperation operations[4] = { &RPN::plus, &RPN::minus, &RPN::multiply, &RPN::divide };

	try {
		for (size_t i = 0; i < expressionListSize; i++) {
			char expressionItem = exprList[i][0];
			size_t operationIndex = RPN::ACCEPTED_NUMERIC_OPERATIONS.find(expressionItem);

			if (operationIndex == std::string::npos) {
				expressionStack.push(std::strtod(exprList[i].c_str(), NULL));
			} else {
				if (expressionStack.size() < 2)
					throw std::runtime_error(ERR_WRONG_EXPR);

				rvalue = expressionStack.top();
				expressionStack.pop();
				lvalue = expressionStack.top();
				expressionStack.pop();

				expressionStack.push(operations[operationIndex](rvalue, lvalue));
			}
		}

		double result = expressionStack.top();
		expressionStack.pop();

		if (expressionStack.size())
			throw std::runtime_error(ERR_WRONG_EXPR);

		std::cout << "Result: " << result << std::endl;
	} catch(const std::exception* exc) {
		throw std::runtime_error(exc->what());
	}

	delete[] exprList;
}

bool RPN::isValidExpressionItem( const std::string & exprItem ) {
	if (!exprItem.length() || exprItem.length() > 1)
		return (false);

	if (!::isdigit(exprItem[0]) && ACCEPTED_NUMERIC_OPERATIONS.find(exprItem[0]) == std::string::npos)
		return (false);

	return (true);
}

std::string* RPN::split(const std::string& str, char delimiter, size_t& size) {
	size = 0;

	std::string token;
	std::stringstream ss(str);

	while (std::getline(ss, token, delimiter)) {
		// Davs brats vonc paymanavorvel enq
		if(!token.empty())
			size++;
	}

	std::string *dividedList = new std::string[size];
	size_t fillSize = 0;

	ss.clear();
	ss.seekg(0);

	while (std::getline(ss, token, delimiter)) {
		if(!token.empty()) {
			dividedList[fillSize] = token;
			fillSize++;
		}
	}

	return (dividedList);
}