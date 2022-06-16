#include "CFraction.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// http://spacemath.xyz/deistviya_s_drobyami/

// Функция вычисляет наибольший общий делитель целых чисел (сокращенно НОД)
int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

// Функция вычисляет наименьшее общее кратное (сокращенно НОК)
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

// Функция сокращения дробей
CFraction FractReduction(CFraction f)
{
	CFraction result{};

	int nod = GCD(f.getNumerator(), f.getDenominator());
	if (nod == 1)
		return f;
	else
	{
		result.setWhole(f.getWhole()); // 0
		result.setNumerator(f.getNumerator() / nod); // 1
		result.setDenominator(f.getDenominator() / nod); // 1

		if (result.getNumerator() == result.getDenominator())
		{
			result.setWhole(result.getWhole() + (result.getNumerator() / result.getDenominator()));
			result.setNumerator(0);
			result.setDenominator(0);
		}
		return result;
	}
}

// Функция превращения неправильной дроби в смешанное число.
CFraction ConvIncorFractToMixNum(CFraction f)
{
	CFraction result{};

	result.setWhole(int(f.getNumerator() / f.getDenominator()));
	result.setNumerator(f.getNumerator() - (result.getWhole() * f.getDenominator()));
	result.setDenominator(f.getDenominator());

	return result;
}

// Функция превращения смешанного числа в неправильную дробь.
CFraction ConvMixedNumToIncorrFract(CFraction f)
{
	if (f.getWhole() == 0)
		return f;
	else
	{
		CFraction result{};
		result.setNumerator(f.getWhole() * f.getDenominator() + f.getNumerator());
		result.setDenominator(f.getDenominator());

		return result;
	}
}

// Функция реализующая операцию сложения
CFraction AdditionOfFractions(CFraction f1, CFraction f2)
{
	CFraction f1Copy = f1;
	CFraction f2Copy = f2;
	if (f1Copy.getWhole() > 0)
		f1Copy = ConvMixedNumToIncorrFract(f1Copy);
	if (f2Copy.getWhole() > 0)
		f2Copy = ConvMixedNumToIncorrFract(f2Copy);

	CFraction result{};

	// Сложение дробей с одинаковыми знаменателями
	if (f1Copy.getDenominator() == f2Copy.getDenominator())
	{
		result.setWhole(f1Copy.getWhole() + f2Copy.getWhole());
		result.setNumerator(f1Copy.getNumerator() + f2Copy.getNumerator());
		result.setDenominator(f1Copy.getDenominator());
	}

	// Сложение дробей с разными знаменателями
	else if (f1Copy.getDenominator() != f2Copy.getDenominator())
	{
		int nok = LCM(f1Copy.getDenominator(), f2Copy.getDenominator());

		result.setNumerator((nok / f1Copy.getDenominator() * f1Copy.getNumerator()) + (nok / f2Copy.getDenominator() * f2Copy.getNumerator()));
		result.setDenominator(nok);
	}

	if (result.getNumerator() > result.getDenominator())
		result = ConvIncorFractToMixNum(result);

	result = FractReduction(result);
	return result;
}

// Функция для ввода дроби
void Input(CFraction& f)
{
	cout << "whole: ";
	int w;
	cin >> w;
	f.setWhole(w);
	cout << "numerator: ";
	int n;
	cin >> n;
	f.setNumerator(n);
	cout << "denominator: ";
	int d;
	cin >> d;
	f.setDenominator(d);
}

// Функция для вывода дроби
void Print(CFraction f)
{
	cout << "\nResult:\n";
	if (f.getWhole())
		cout << f.getWhole() << ' ';
	if (f.getNumerator() && f.getDenominator())
		cout << f.getNumerator() << '/' << f.getDenominator() << endl;
}

// Функция выполняет вычитание дробей
CFraction FractionSubtraction(CFraction f1, CFraction f2)
{
	CFraction f1Copy = f1;
	CFraction f2Copy = f2;
	if (f1Copy.getWhole() > 0)
		f1Copy = ConvMixedNumToIncorrFract(f1Copy);
	if (f2Copy.getWhole() > 0)
		f2Copy = ConvMixedNumToIncorrFract(f2Copy);

	CFraction result{};

	// Вычитание дробей с одинаковыми знаменателями.
	if (f1Copy.getDenominator() == f2Copy.getDenominator() && f1Copy.getWhole() == 0 && f2Copy.getWhole() == 0)
	{
		result.setNumerator(f1Copy.getNumerator() - f2Copy.getNumerator());
		result.setDenominator(f1Copy.getDenominator());
	}

	// Вычитание обычных дробей
	else if (f1Copy.getDenominator() != f2Copy.getDenominator() && f1Copy.getWhole() == 0 && f2Copy.getWhole() == 0)
	{
		int nok = LCM(f1Copy.getDenominator(), f2Copy.getDenominator());

		result.setNumerator((nok / f1Copy.getDenominator() * f1Copy.getNumerator()) - (nok / f2Copy.getDenominator() * f2Copy.getNumerator()));
		result.setDenominator(nok);
	}

	if (result.getNumerator() > result.getDenominator())
		result = ConvIncorFractToMixNum(result);

	result = FractReduction(result);
	return result;
}

// Функция реализующая операцию умножения
CFraction Multiplication(CFraction f1, CFraction f2)
{
	CFraction f1Copy = f1;
	CFraction f2Copy = f2;
	if (f1Copy.getWhole() > 0)
		f1Copy = ConvMixedNumToIncorrFract(f1Copy);
	if (f2Copy.getWhole() > 0)
		f2Copy = ConvMixedNumToIncorrFract(f2Copy);

	CFraction result{};

	result.setNumerator(f1Copy.getNumerator() * f2Copy.getNumerator());
	result.setDenominator(f1Copy.getDenominator() * f2Copy.getDenominator());

	if (result.getNumerator() > result.getDenominator())
		result = ConvIncorFractToMixNum(result);

	result = FractReduction(result);
	return result;
}

// Функция реализующая операцию деления
CFraction Division(CFraction f1, CFraction f2)
{
	CFraction f1Copy = f1;
	CFraction f2Copy = f2;
	if (f1Copy.getWhole() > 0)
		f1Copy = ConvMixedNumToIncorrFract(f1Copy);
	if (f2Copy.getWhole() > 0)
		f2Copy = ConvMixedNumToIncorrFract(f2Copy);

	int temp = f2Copy.getNumerator();
	f2Copy.setNumerator(f2Copy.getDenominator());
	f2Copy.setDenominator(temp);

	CFraction result{};

	result = Multiplication(f1Copy, f2Copy);

	if (result.getNumerator() > result.getDenominator())
		result = ConvIncorFractToMixNum(result);

	result = FractReduction(result);
	return result;
}