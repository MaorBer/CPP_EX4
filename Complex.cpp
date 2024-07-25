// maorw9@gmail.com
// 212305965

#pragma once
#include <string>

using std::string;

// Define a small epsilon for floating-point precision
#define EPSILON 1e-6

class Complex {
private:
    double realPart;    // Real component of the complex number
    double imaginaryPart; // Imaginary component of the complex number

public:
    // Constructor for initializing a Complex number with real and imaginary parts
    Complex(double real, double imaginary) : realPart(real), imaginaryPart(imaginary) {}

    // Get the real part of the complex number
    double getReal() const {
        return realPart;
    }

    // Get the imaginary part of the complex number
    double getImaginary() const {
        return imaginaryPart;
    }

    // Calculate the squared magnitude (norm) of the complex number
    double getNorm() const {
        return realPart * realPart + imaginaryPart * imaginaryPart;
    }

    // Overload the + operator to add two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    // Overload the - operator to subtract one complex number from another
    Complex operator-(const Complex& other) const {
        return Complex(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    // Overload the * operator to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        double realResult = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
        double imaginaryResult = realPart * other.imaginaryPart + imaginaryPart * other.realPart;
        return Complex(realResult, imaginaryResult);
    }

    // Overload the / operator to divide one complex number by another
    Complex operator/(const Complex& other) const {
        double denominator = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        double realResult = (realPart * other.realPart + imaginaryPart * other.imaginaryPart) / denominator;
        double imaginaryResult = (imaginaryPart * other.realPart - realPart * other.imaginaryPart) / denominator;
        return Complex(realResult, imaginaryResult);
    }

    // Overload the < operator to compare if this complex number is less than another
    bool operator<(const Complex& other) const {
        return getNorm() < other.getNorm();
    }

    // Overload the > operator to compare if this complex number is greater than another
    bool operator>(const Complex& other) const {
        return other < *this;
    }

    // Overload the == operator to check if two complex numbers are equal (within EPSILON tolerance)
    bool operator==(const Complex& other) const {
        return (std::abs(realPart - other.realPart) <= EPSILON) &&
               (std::abs(imaginaryPart - other.imaginaryPart) <= EPSILON);
    }

    // Overload the != operator to check if two complex numbers are not equal
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overload the <= operator to compare if this complex number is less than or equal to another
    bool operator<=(const Complex& other) const {
        return *this == other || *this < other;
    }

    // Overload the >= operator to compare if this complex number is greater than or equal to another
    bool operator>=(const Complex& other) const {
        return *this == other || *this > other;
    }

    // Convert the complex number to a string representation
    string toString() const {
        string result = "(" + formatDouble(getReal());
        result.append(",").append(formatDouble(getImaginary()));
        result.append(")");
        return result;
    }

private:
    // Convert a double value to a string, removing unnecessary trailing zeros
    string formatDouble(double value) const {
        string str = std::to_string(value);
        while (str.back() == '0') {
            str.pop_back();
        }
        if (str.back() == '.') {
            str.pop_back();
        }
        return str;
    }
};
