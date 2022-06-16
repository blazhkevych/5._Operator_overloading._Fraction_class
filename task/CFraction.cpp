#include "CFraction.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Действия с дробями.
// http://spacemath.xyz/deistviya_s_drobyami/

// Функция вычисляет наибольший общий делитель целых чисел (сокращенно НОД).
int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

// Функция вычисляет наименьшее общее кратное (сокращенно НОК).
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

// Функция сокращения дробей.
CFraction FractReduction(CFraction fraction)
{
	CFraction result{};

	int nod = GCD(fraction.getNumerator(), fraction.getDenominator());
	if (nod == 1)
		return fraction;
	else
	{
		result.setWhole(fraction.getWhole()); // 0
		result.setNumerator(fraction.getNumerator() / nod); // 1
		result.setDenominator(fraction.getDenominator() / nod); // 1

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
CFraction ConvIncorFractToMixNum(CFraction fraction)
{
	CFraction result{};

	result.setWhole(int(fraction.getNumerator() / fraction.getDenominator()));
	result.setNumerator(fraction.getNumerator() - (result.getWhole() * fraction.getDenominator()));
	result.setDenominator(fraction.getDenominator());

	return result;
}

// Функция превращения смешанного числа в неправильную дробь.
CFraction ConvMixedNumToIncorrFract(CFraction fraction)
{
	if (fraction.getWhole() == 0)
		return fraction;
	else
	{
		CFraction result{};
		result.setNumerator(fraction.getWhole() * fraction.getDenominator() + fraction.getNumerator());
		result.setDenominator(fraction.getDenominator());

		return result;
	}
}

// Функция реализующая операцию сложения.
CFraction AdditionOfFractions(CFraction fraction1, CFraction fraction2)
{
	CFraction f1Copy = fraction1;
	CFraction f2Copy = fraction2;
	if (f1Copy.getWhole() > 0)
		f1Copy = ConvMixedNumToIncorrFract(f1Copy);
	if (f2Copy.getWhole() > 0)
		f2Copy = ConvMixedNumToIncorrFract(f2Copy);

	CFraction result{};

	// Сложение дробей с одинаковыми знаменателями.
	if (f1Copy.getDenominator() == f2Copy.getDenominator())
	{
		result.setWhole(f1Copy.getWhole() + f2Copy.getWhole());
		result.setNumerator(f1Copy.getNumerator() + f2Copy.getNumerator());
		result.setDenominator(f1Copy.getDenominator());
	}

	// Сложение дробей с разными знаменателями.
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

// Функция для ввода дроби.
void Input(CFraction& fraction)
{
	cout << "whole: ";
	int w;
	cin >> w;
	fraction.setWhole(w);
	cout << "numerator: ";
	int n;
	cin >> n;
	fraction.setNumerator(n);
	cout << "denominator: ";
	int d;
	cin >> d;
	fraction.setDenominator(d);
}

// Функция для вывода дроби.
void Print(CFraction fraction)
{
	cout << "\nResult:\n";
	if (fraction.getWhole())
		cout << fraction.getWhole() << ' ';
	if (fraction.getNumerator() && fraction.getDenominator())
		cout << fraction.getNumerator() << '/' << fraction.getDenominator() << endl;
}

// Функция выполняет вычитание дробей.
CFraction FractionSubtraction(CFraction fraction1, CFraction fraction2)
{
	CFraction f1Copy = fraction1;
	CFraction f2Copy = fraction2;
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

	// Вычитание обычных дробей.
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

// Функция реализующая операцию умножения.
CFraction Multiplication(CFraction fraction1, CFraction fraction2)
{
	CFraction f1Copy = fraction1;
	CFraction f2Copy = fraction2;
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

// Функция реализующая операцию деления.
CFraction Division(CFraction fraction1, CFraction fraction2)
{
	CFraction f1Copy = fraction1;
	CFraction f2Copy = fraction2;
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

// Перегрузка арифметических операторов с помощью методов класса:
// Перегрузка оператора "+" для "object + object".
CFraction CFraction::operator+(const CFraction& fraction) const
{
	/*CFraction fraction1(m_whole, m_numerator, m_denominator);
	return AdditionOfFractions(fraction1, fraction);*/
	//CFraction fraction1(m_whole, m_numerator, m_denominator);
	return AdditionOfFractions(*this, fraction); // проверить работает ли корректно подобный подход
}

// Перегрузка оператора "-" для "object - object".
CFraction CFraction::operator-(const CFraction& fraction) const
{
	/*CFraction fraction1(m_whole, m_numerator, m_denominator);
	return FractionSubtraction(fraction1, fraction);*/
	return FractionSubtraction(*this, fraction);
}

// Перегрузка оператора "*" для "object * object".
CFraction CFraction::operator*(const CFraction& fraction) const
{
	/*CFraction fraction1(m_whole, m_numerator, m_denominator);
	return Multiplication(fraction1, fraction);*/
	return Multiplication(*this, fraction);
}

// Перегрузка оператора "/" для "object / object".
CFraction CFraction::operator/(const CFraction& fraction) const
{
	/*CFraction fraction1(m_whole, m_numerator, m_denominator);
	return Division(fraction1, fraction);*/
	return Division(*this, fraction);
}

// Перегрузка операторов отношения с помощью методов класса:
// Перегрузка оператора "==" для "object == object".
bool CFraction::operator==(const CFraction& fraction) const
{
	CFraction fraction1Copy(m_whole, m_numerator, m_denominator);
	CFraction fraction2Copy = fraction;
	if (fraction1Copy.m_whole > 0)
		fraction1Copy = ConvMixedNumToIncorrFract(fraction1Copy);
	if (fraction2Copy.m_whole > 0)
		fraction2Copy = ConvMixedNumToIncorrFract(fraction2Copy);

	if (fraction1Copy.m_numerator == fraction2Copy.m_numerator &&
		fraction1Copy.m_denominator == fraction2Copy.m_denominator)
		return true;
	else
		return false;
}

// Перегрузка оператора "!=" для "object != object".
bool CFraction::operator!=(const CFraction& fraction) const
{
	return !(this->operator==(fraction));
}

// Перегрузка оператора ">" для "object > object".
bool CFraction::operator>(const CFraction& fraction) const
{
	CFraction fraction1Copy(m_whole, m_numerator, m_denominator);
	CFraction fraction2Copy = fraction;
	if (fraction1Copy.m_whole > 0)
		fraction1Copy = ConvMixedNumToIncorrFract(fraction1Copy);
	if (fraction2Copy.m_whole > 0)
		fraction2Copy = ConvMixedNumToIncorrFract(fraction2Copy);

	// Сравнение дробей с одинаковыми знаменателями.
	if (fraction1Copy.m_denominator == fraction2Copy.m_denominator)
	{
		if (fraction1Copy.m_numerator > fraction2Copy.m_numerator)
			return true;
		else
			return false;
	}
	// Сравнение дробей с одинаковыми числителями.
	else if (fraction1Copy.m_numerator == fraction2Copy.m_numerator)
	{
		if (fraction1Copy.m_denominator < fraction2Copy.m_denominator)
			return true;
		else
			return false;
	}
	// Сравнение дробей с разными числителями и разными знаменателями.
	else if (fraction1Copy.m_numerator != fraction2Copy.m_numerator &&
		fraction1Copy.m_denominator != fraction2Copy.m_denominator)
	{
		// Приведение дроби к одинаковому (общему) знаменателю.
		int nok = LCM(fraction1Copy.m_denominator, fraction2Copy.m_denominator); // НОК.
		int additionalMultiplierFraction1 = (nok / fraction1Copy.m_denominator); // Дополнительный множитель.
		int additionalMultiplierFraction2 = (nok / fraction2Copy.m_denominator); // Дополнительный множитель.
		fraction1Copy.m_numerator = fraction1Copy.m_numerator * additionalMultiplierFraction1;
		fraction1Copy.m_denominator = fraction1Copy.m_denominator * additionalMultiplierFraction1;
		fraction2Copy.m_numerator = fraction2Copy.m_numerator * additionalMultiplierFraction2;
		fraction2Copy.m_denominator = fraction2Copy.m_denominator * additionalMultiplierFraction2;

		// Сравнение дробей с одинаковыми знаменателями.
		if (fraction1Copy.m_numerator > fraction2Copy.m_numerator)
			return true;
		else
			return false;
	}
}

// Перегрузка оператора ">=" для "object >= object".
bool CFraction::operator>=(const CFraction& fraction) const
{
	return !(this->operator<(fraction));
}

// Перегрузка оператора "<" для "object < object".
bool CFraction::operator<(const CFraction& fraction) const
{
	return !(this->operator>(fraction));
}

// Перегрузка оператора "<=" для "object <= object".
bool CFraction::operator<=(const CFraction& fraction) const
{
	return !(this->operator>(fraction));
}