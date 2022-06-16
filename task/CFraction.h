#pragma once
class CFraction
{
private:
	int whole; // целое
	int numerator; // числитель
	int denominator; // знаменатель
public:
	int getWhole() { return whole; }
	int getNumerator() { return numerator; }
	int getDenominator() { return denominator; }
	void setWhole(int whl) { whole = whl; }
	void setNumerator(int nmrtr) { numerator = nmrtr; }
	void setDenominator(int dnmntr) { denominator = dnmntr; }

	// конструктор по умолчанию
	CFraction()
	{
		whole = 0;
		numerator = 1;
		denominator = 2;
	};
	// конструктор без целой части
	CFraction(int nmrtr, int dnmntr)
	{
		whole = 0;
		numerator = nmrtr;
		denominator = dnmntr;
	};
	// конструктор с целой частью
	CFraction(int whl, int nmrtr, int dnmntr)
	{
		whole = whl;
		numerator = nmrtr;
		denominator = dnmntr;
	};
};

// Функция вычисляет наибольший общий делитель целых чисел (сокращенно НОД)
int GCD(int a, int b);

// Функция вычисляет наименьшее общее кратное (сокращенно НОК)
int LCM(int a, int b);

// Функция сокращения дробей
CFraction FractReduction(CFraction f);

// Функция превращения неправильной дроби в смешанное число.
CFraction ConvIncorFractToMixNum(CFraction f);

// Функция превращения смешанного числа в неправильную дробь.
CFraction ConvMixedNumToIncorrFract(CFraction f);

// Функция реализующая операцию сложения
CFraction AdditionOfFractions(CFraction f1, CFraction f2);

// Функция для ввода дроби
void Input(CFraction& f);

// Функция для вывода дроби
void Print(CFraction f);

// Функция выполняет вычитание дробей
CFraction FractionSubtraction(CFraction f1, CFraction f2);

// Функция реализующая операцию умножения
CFraction Multiplication(CFraction f1, CFraction f2);

// Функция реализующая операцию деления
CFraction Division(CFraction f1, CFraction f2);