#include "CFraction. Global functions.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// �������� � �������.
// http://spacemath.xyz/deistviya_s_drobyami/

// ������� ��������� ���������� ����� �������� ����� ����� (���������� ���).
int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

// ������� ��������� ���������� ����� ������� (���������� ���).
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

// ������� ���������� ������.
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

// ������� ����������� ������������ ����� � ��������� �����.
CFraction ConvIncorFractToMixNum(CFraction fraction)
{
	CFraction result{};

	result.setWhole(int(fraction.getNumerator() / fraction.getDenominator()));
	result.setNumerator(fraction.getNumerator() - (result.getWhole() * fraction.getDenominator()));
	result.setDenominator(fraction.getDenominator());

	return result;
}

// ������� ����������� ���������� ����� � ������������ �����.
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

// ������� ����������� �������� ��������.
CFraction AdditionOfFractions(CFraction fraction1, CFraction fraction2)
{
	CFraction f1Copy = fraction1;
	CFraction f2Copy = fraction2;
	if (f1Copy.getWhole() > 0)
		f1Copy = ConvMixedNumToIncorrFract(f1Copy);
	if (f2Copy.getWhole() > 0)
		f2Copy = ConvMixedNumToIncorrFract(f2Copy);

	CFraction result{};

	// �������� ������ � ����������� �������������.
	if (f1Copy.getDenominator() == f2Copy.getDenominator())
	{
		result.setWhole(f1Copy.getWhole() + f2Copy.getWhole());
		result.setNumerator(f1Copy.getNumerator() + f2Copy.getNumerator());
		result.setDenominator(f1Copy.getDenominator());
	}

	// �������� ������ � ������� �������������.
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

// ������� ��� ����� �����.
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

// ������� ��� ������ �����.
void Print(CFraction fraction)
{
	//cout << "\nResult:\n";
	if (fraction.getWhole())
		cout << fraction.getWhole() << ' ';
	if (fraction.getNumerator() && fraction.getDenominator())
		cout << fraction.getNumerator() << '/' << fraction.getDenominator() << endl;
}

// ������� ��������� ��������� ������.
CFraction FractionSubtraction(CFraction fraction1, CFraction fraction2)
{
	CFraction f1Copy = fraction1;
	CFraction f2Copy = fraction2;
	if (f1Copy.getWhole() > 0)
		f1Copy = ConvMixedNumToIncorrFract(f1Copy);
	if (f2Copy.getWhole() > 0)
		f2Copy = ConvMixedNumToIncorrFract(f2Copy);

	CFraction result{};

	// ��������� ������ � ����������� �������������.
	if (f1Copy.getDenominator() == f2Copy.getDenominator() && f1Copy.getWhole() == 0 && f2Copy.getWhole() == 0)
	{
		result.setNumerator(f1Copy.getNumerator() - f2Copy.getNumerator());
		result.setDenominator(f1Copy.getDenominator());
	}

	// ��������� ������� ������.
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

// ������� ����������� �������� ���������.
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

// ������� ����������� �������� �������.
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

// ���������� �������������� ���������� � ������� ���������� �������:
// ���������� ��������� "+" ��� "object + object".
CFraction operator + (const CFraction& fraction1, const CFraction& fraction2)
{

}

// ���������� ��������� "-" ��� "object - object".
CFraction operator - (const CFraction& fraction1, const CFraction& fraction2)
{

}

// ���������� ��������� "*" ��� "object * object".
CFraction operator * (const CFraction& fraction1, const CFraction& fraction2)
{

}

// ���������� ��������� "/" ��� "object / object".
CFraction operator / (const CFraction& fraction1, const CFraction& fraction2)
{

}

// ���������� ���������� ��������� � ������� ���������� �������:
// ���������� ��������� "==" ��� "object == object".
bool operator == (const CFraction& fraction1, const CFraction& fraction2)
{

}

// ���������� ��������� "!=" ��� "object != object".
bool operator != (const CFraction& fraction1, const CFraction& fraction2)
{

}

// ���������� ��������� ">" ��� "object > object".
bool operator > (const CFraction& fraction1, const CFraction& fraction2)
{

}

// ���������� ��������� ">=" ��� "object >= object".
bool operator >= (const CFraction& fraction1, const CFraction& fraction2)
{

}

// ���������� ��������� "<" ��� "object < object".
bool operator < (const CFraction& fraction1, const CFraction& fraction2)
{

}

// ���������� ��������� "<=" ��� "object <= object".
bool operator <= (const CFraction& fraction1, const CFraction& fraction2)
{

}