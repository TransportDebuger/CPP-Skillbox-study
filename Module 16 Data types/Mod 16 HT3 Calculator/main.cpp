#include <iostream>
#include <string>
#include <sstream>

double calcExpression(double fNum, double sNum, char Op) {
  if (Op=='+') return fNum+sNum;
  if (Op=='-') return fNum-sNum;
  if (Op=='*') return fNum*sNum;
  if (Op=='/') return fNum/sNum;
  return 0;
}

int main() {
  std::cout << "Calculator!\n";
  std::string expression;
  std::cout << "Enter your expression" << std::endl;
  std::cin >> expression;
  std::stringstream ss;
  ss << expression;

  double firstValue, secondValue, result;
  char operation;
  ss >> firstValue >> operation >> secondValue;
  std::cout << "Result: " << calcExpression(firstValue, secondValue, operation);
  
} 