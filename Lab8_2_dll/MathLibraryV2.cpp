#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "MathLibraryV2.h"
#include <stdexcept>
#include <cmath>
#include <iostream>

double CalcAverageHarmonic(double a, double b, double c)
{
	if (a == 0 || b == 0 || c == 0)
	{
		throw std::invalid_argument("Attempted to divide by zero");
	}
	return 3 / ((1 / a) + (1 / b) + (1 / c));
}

// Factorial calculation
double fact(double n)
{
	double fact = 1;
	for (int i = 1; i <= n; ++i)
	{
		fact *= i;
	}
	return fact;
}

double CalcTaylorRow(double x, int n)
{
	if (std::abs(x) >= 1 || n <= 0)
	{
		throw std::invalid_argument("Doesn`t satisfy |x| < 1 or n > 0");
	}

	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		double numerator = pow(-1, i) * fact(2 * i);
		double denominator
			= static_cast<double>(1 - 2 * i) * pow(fact(i), 2) * pow(4, i);
		sum += numerator / denominator * pow(x, i);
	}
	std::cout << "Taylor row calculated: " << sum << std::endl;
	std::cout << "sqrt(1+x) calculated: " << sqrt(1 + x) << std::endl;

	return sum;
}

// ctg(x) * tg(x) = 1
double ctg(double arg)
{ return 1.0 / tan(arg); }

double CalcPolygonArea(double a, int n)
{
	// https://ua.onlinemschool.com/math/formula/regular_polygon/
	if (a <= 0 || n <= 2)
	{
		throw std::invalid_argument("Doesn`t satisfy a <= 0 or n <= 2");
	}
	const double M_PI = 3.14159265358979323846;
	return (n * pow(a, 2) * ctg(M_PI / n)) / 4;
}