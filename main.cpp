#include <iostream>
#include <string>
using namespace std;

void input(double& a, double& b, double& c, double& d, char& ch, char& oper);
string Adding_two_fractions(int a, int b, int c, int d);
double Decimal_fraction(double a, double b);
double adding_fractions(double a, double b);
int nod(int a, int b);

//int gcd(int a, int b) {
//	if (b == 0)
//		return a;
//	else
//		return gcd(b, a % b);
//}

int main()
{
	double a;
	double b;
	double c;
	double d;
	char ch = ' ';
	char oper = ' ';

	input(a, b, c, d, ch, oper);

	double math1 = Decimal_fraction(a, b);
	double math2 = Decimal_fraction(c, d);

	cout << "Result with adding fractions: " 
	<< Adding_two_fractions(a,b,c,d);

	cout << endl;

	cout << "Result as a decimal fraction: "
		 << adding_fractions(math1,math2);

	return 0;
}

void input(double& a, double& b, double& c, double& d, char& ch, char& oper)
{
	cout << "Input:";
	//while (ch != '/' && oper != '+')
	//{
		cin >> a >> ch >> b >> oper >> c >> ch >> d;
	//}
}

int nod(int a, int b)
{
	// НОД [Метод последовательных разностей]
	// [Method of successive differences] - MSD
	// FIX WITH A MINUS SIGN [-]
	
	while (a != b)
	{
		cout << "Hello" << endl;
		// Примечание: Проблема со вторым числителем (c)
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	return a;
}

// UPGRADE VERSION OPERATION WITH 2 FRACTIONS
string Adding_two_fractions(int a, int b, int c, int d)
{
	int numerators; 
	int denominators;
	string s_numerators;
	string s_denominators;
	string s_result;

	if (b == 0 || d == 0)
	{
		cout << "It is forbidden to divide by zero! ";
		s_result = "Underfined";
		return s_result;

	}

	if (a == 0)
	{
		numerators = c;
		denominators = d;

		s_numerators = to_string(numerators);
		s_denominators = to_string(denominators);
		s_result = s_numerators + "/" + s_denominators;

		return s_result;
	}
	else if (c == 0)
	{
		numerators = a;
		denominators = b;

		s_numerators = to_string(numerators);
		s_denominators = to_string(denominators);
		s_result = s_numerators + "/" + s_denominators;

		return s_result;
	}

	if (b == d)
	{
		int adding_two_numerators = a + c;

		numerators = adding_two_numerators;
		denominators = b;
	}
	else if (b != d)
	{
		// ... Не вычисляется здесь НОК/НОД [1/6+2/9 показывает не точный тест]
		

		// Приводим дроби к общему знаменателю
		int Common_denominator1 = a * d;
		int Common_denominator2 = c * b;

		// Складываем числители
		numerators = Common_denominator1 + Common_denominator2;
		denominators = b * d; // Общий знаменатель


	}

	// Reduce fractions using NOD
	int commonDivisor = nod(numerators, denominators);

	if (commonDivisor > 1)
	{
		numerators = numerators / commonDivisor;
		denominators = denominators / commonDivisor;
	}


	// Форматируем результат в виде строки
	s_numerators = to_string(numerators);
	s_denominators = to_string(denominators);
	s_result = s_numerators + "/" + s_denominators;

	return s_result;
}


double Decimal_fraction(double a, double b)
{
	double d_decimal = a / b;
	return d_decimal;
}

double adding_fractions(double a, double b)
{
	double math_res = a + b;

	return math_res;
}
