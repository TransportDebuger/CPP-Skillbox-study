#include <iostream>
#include <cmath>
#include <string>
#include <locale>

struct MathVector {
  double coordinateX;
  double coordinateY;
};

double vectorLength(MathVector mVec) {
  return sqrt(mVec.coordinateX * mVec.coordinateX + mVec.coordinateY * mVec.coordinateY);
}

MathVector vectorNormalize(MathVector mVec) {
  double inv_length = 1/vectorLength(mVec);
  mVec.coordinateX *= inv_length;
  mVec.coordinateY *= inv_length;
  return mVec;
}

MathVector vectorAdd(MathVector mVec1, MathVector mVec2) {
  mVec1.coordinateX += mVec2.coordinateX;
  mVec1.coordinateY += mVec2.coordinateY;
  return mVec1;
}

MathVector vectorScale(MathVector mVec, double multiplier) {
  mVec.coordinateX *= multiplier;
  mVec.coordinateY *= multiplier;
  return mVec;
}

MathVector vectorSubtract(MathVector mVec1, MathVector mVec2) {
  mVec1.coordinateX -= mVec2.coordinateX;
  mVec1.coordinateY -= mVec2.coordinateY;
  return mVec1;
}

int main() {
    std::cout << "Math Vectors!\n";

  std::cout << "This program helps you to do some operations with vectors.\n";
  std::cout << "Choose operations with this keywords:\n  ADD - Sum of two vectors\n  SUBTRACT - Subtraction of two vectors\n  SCALE - Scalar multiplication of vector\n  LENGTH - Get vector length\n  NORMALIZE - Vector normalization\n";
  MathVector firstVector;
  std::cout << "Enter value of X-axis coordinate: ";
  std::cin >> firstVector.coordinateX;
  std::cout << "Enter value of Y-axis coordinate: ";
  std::cin >> firstVector.coordinateY;
  std::cout << "Command> ";
  std::string command;
  std::cin >> command;
  if (command == "LENGTH") {
    std::cout << "Vector length: " << vectorLength(firstVector) << std::endl;
  } else if (command == "NORMALIZE") {
    firstVector = vectorNormalize(firstVector);
    std::cout << "Result vector is (" << firstVector.coordinateX << ", " << firstVector.coordinateY << ")\n";
  } else if (command == "ADD") {
    std::cout << "Enter second vector for operation\n";
    MathVector additionalVector;
    std::cout << "Enter value of X-axis coordinate: ";
    std::cin >> additionalVector.coordinateX;
    std::cout << "Enter value of Y-axis coordinate: ";
    std::cin >> additionalVector.coordinateY;
    firstVector = vectorAdd(firstVector, additionalVector);
    std::cout << "Result vector is (" << firstVector.coordinateX << ", " << firstVector.coordinateY << ")\n";
  } else if (command == "SCALE") {
    double multiplier;
    std::cout << "Enter multiplier value: ";
    std::cin >> multiplier;
    firstVector = vectorScale(firstVector, multiplier);
    std::cout << "Result vector is (" << firstVector.coordinateX << ", " << firstVector.coordinateY << ")\n";
  } else if (command == "SUBTRACT") {
    std::cout << "Enter second vector for operation\n";
    MathVector additionalVector;
    std::cout << "Enter value of X-axis coordinate: ";
    std::cin >> additionalVector.coordinateX;
    std::cout << "Enter value of Y-axis coordinate: ";
    std::cin >> additionalVector.coordinateY;
    firstVector = vectorSubtract(firstVector, additionalVector);
    std::cout << "Result vector is (" << firstVector.coordinateX << ", " << firstVector.coordinateY << ")\n";
  } else {
    std::cout << "Error.Command is not recognized.\n";
  }
}