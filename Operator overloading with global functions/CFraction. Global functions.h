#pragma once
class CFraction
{
private:
	// Данные - члены(поля) :
	int m_whole;			// Целое.
	int m_numerator;		// Числитель.
	int m_denominator;		// Знаменатель.
public:
	// Методы-аксессоры:
	// Инспекторы (позволяют получить значения полей).
	int getWhole() { return m_whole; }
	int getNumerator() { return m_numerator; }
	int getDenominator() { return m_denominator; }

	// Модификаторы (позволяют установить значения полей).
	void setWhole(int whole) { m_whole = whole; }
	void setNumerator(int numerator) { m_numerator = numerator; }
	void setDenominator(int denominator) { m_denominator = denominator; }

	// Конструкторы:
	// Конструктор по умолчанию (задает начальное значение).
	CFraction() :CFraction(0, 0, 0) {};

	// Конструктор с одним параметром стандартного типа является конструктором преобразования из этого типа в объект класса.
	CFraction(int whole) :CFraction(whole, 0, 0) {};

	// Конструктор без целой части.
	CFraction(int numerator, int denominator) :CFraction(0, numerator, denominator) {};

	// Конструктор с целой частью.
	CFraction(int whole, int numerator, int denominator)
		:m_whole(whole), m_numerator(numerator), m_denominator(denominator) {};	
};

// Функция вычисляет наибольший общий делитель целых чисел (сокращенно НОД).
int GCD(int a, int b);

// Функция вычисляет наименьшее общее кратное (сокращенно НОК).
int LCM(int a, int b);

// Функция сокращения дробей.
CFraction FractReduction(CFraction fraction);

// Функция превращения неправильной дроби в смешанное число.
CFraction ConvIncorFractToMixNum(CFraction fraction);

// Функция превращения смешанного числа в неправильную дробь.
CFraction ConvMixedNumToIncorrFract(CFraction fraction);

// Функция реализующая операцию сложения.
CFraction AdditionOfFractions(CFraction fraction1, CFraction fraction2);

// Функция для ввода дроби.
void Input(CFraction& fraction);

// Функция для вывода дроби.
void Print(CFraction fraction);

// Функция выполняет вычитание дробей.
CFraction FractionSubtraction(CFraction fraction1, CFraction fraction2);

// Функция реализующая операцию умножения.
CFraction Multiplication(CFraction fraction1, CFraction fraction2);

// Функция реализующая операцию деления.
CFraction Division(CFraction fraction1, CFraction fraction2);

// Перегрузка арифметических операторов с помощью глобальных функций:
// Перегрузка оператора "+" для "object + object".
CFraction operator + (const CFraction& fraction1, const CFraction& fraction2);

// Перегрузка оператора "-" для "object - object".
CFraction operator - (const CFraction& fraction1, const CFraction& fraction2);

// Перегрузка оператора "*" для "object * object".
CFraction operator * (const CFraction& fraction1, const CFraction& fraction2);

// Перегрузка оператора "/" для "object / object".
CFraction operator / (const CFraction& fraction1, const CFraction& fraction2);

// Перегрузка операторов отношения с помощью глобальных функций:
// Перегрузка оператора "==" для "object == object".
bool operator == (const CFraction& fraction1, const CFraction& fraction2);

// Перегрузка оператора "!=" для "object != object".
bool operator != (const CFraction& fraction1, const CFraction& fraction2);

// Перегрузка оператора ">" для "object > object".
bool operator > (const CFraction& fraction1, const CFraction& fraction2);

// Перегрузка оператора ">=" для "object >= object".
bool operator >= (const CFraction& fraction1, const CFraction& fraction2);

// Перегрузка оператора "<" для "object < object".
bool operator < (const CFraction& fraction1, const CFraction& fraction2);

// Перегрузка оператора "<=" для "object <= object".
bool operator <= (const CFraction& fraction1, const CFraction& fraction2);