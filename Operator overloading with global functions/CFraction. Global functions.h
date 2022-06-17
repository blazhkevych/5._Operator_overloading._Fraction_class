#pragma once
class CFraction
{
private:
	// ������ - �����(����) :
	int m_whole;			// �����.
	int m_numerator;		// ���������.
	int m_denominator;		// �����������.
public:
	// ������-���������:
	// ���������� (��������� �������� �������� �����).
	int getWhole() { return m_whole; }
	int getNumerator() { return m_numerator; }
	int getDenominator() { return m_denominator; }

	// ������������ (��������� ���������� �������� �����).
	void setWhole(int whole) { m_whole = whole; }
	void setNumerator(int numerator) { m_numerator = numerator; }
	void setDenominator(int denominator) { m_denominator = denominator; }

	// ������������:
	// ����������� �� ��������� (������ ��������� ��������).
	CFraction() :CFraction(0, 0, 0) {};

	// ����������� � ����� ���������� ������������ ���� �������� ������������� �������������� �� ����� ���� � ������ ������.
	CFraction(int whole) :CFraction(whole, 0, 0) {};

	// ����������� ��� ����� �����.
	CFraction(int numerator, int denominator) :CFraction(0, numerator, denominator) {};

	// ����������� � ����� ������.
	CFraction(int whole, int numerator, int denominator)
		:m_whole(whole), m_numerator(numerator), m_denominator(denominator) {};	
};

// ������� ��������� ���������� ����� �������� ����� ����� (���������� ���).
int GCD(int a, int b);

// ������� ��������� ���������� ����� ������� (���������� ���).
int LCM(int a, int b);

// ������� ���������� ������.
CFraction FractReduction(CFraction fraction);

// ������� ����������� ������������ ����� � ��������� �����.
CFraction ConvIncorFractToMixNum(CFraction fraction);

// ������� ����������� ���������� ����� � ������������ �����.
CFraction ConvMixedNumToIncorrFract(CFraction fraction);

// ������� ����������� �������� ��������.
CFraction AdditionOfFractions(CFraction fraction1, CFraction fraction2);

// ������� ��� ����� �����.
void Input(CFraction& fraction);

// ������� ��� ������ �����.
void Print(CFraction fraction);

// ������� ��������� ��������� ������.
CFraction FractionSubtraction(CFraction fraction1, CFraction fraction2);

// ������� ����������� �������� ���������.
CFraction Multiplication(CFraction fraction1, CFraction fraction2);

// ������� ����������� �������� �������.
CFraction Division(CFraction fraction1, CFraction fraction2);

// ���������� �������������� ���������� � ������� ���������� �������:
// ���������� ��������� "+" ��� "object + object".
CFraction operator + (const CFraction& fraction1, const CFraction& fraction2);

// ���������� ��������� "-" ��� "object - object".
CFraction operator - (const CFraction& fraction1, const CFraction& fraction2);

// ���������� ��������� "*" ��� "object * object".
CFraction operator * (const CFraction& fraction1, const CFraction& fraction2);

// ���������� ��������� "/" ��� "object / object".
CFraction operator / (const CFraction& fraction1, const CFraction& fraction2);

// ���������� ���������� ��������� � ������� ���������� �������:
// ���������� ��������� "==" ��� "object == object".
bool operator == (const CFraction& fraction1, const CFraction& fraction2);

// ���������� ��������� "!=" ��� "object != object".
bool operator != (const CFraction& fraction1, const CFraction& fraction2);

// ���������� ��������� ">" ��� "object > object".
bool operator > (const CFraction& fraction1, const CFraction& fraction2);

// ���������� ��������� ">=" ��� "object >= object".
bool operator >= (const CFraction& fraction1, const CFraction& fraction2);

// ���������� ��������� "<" ��� "object < object".
bool operator < (const CFraction& fraction1, const CFraction& fraction2);

// ���������� ��������� "<=" ��� "object <= object".
bool operator <= (const CFraction& fraction1, const CFraction& fraction2);