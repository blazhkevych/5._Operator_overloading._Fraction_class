/*
	Для разработанного ранее класса CFraction
перегрузить арифметические операции :
	* сложения;
	* вычитания;
	* умножения;
	* деления;
	* операции отношения.
	Предусмотреть два способа перегрузки:
	• методами класса;
	• глобальными функциями.
################################################
		СТАТУС : Не готово.
		ВОЗМОЖНЫЕ ДОРАБОТКИ:
* Преобразование из double в объект классаи наоборот.
* Вывести все тесты в консоль.
* Предусмотреть вывод в консоль как тру значения перегрузки оператора, так и фолс,
ситуации когда значение левое меньше или больше правого и когда они равны.
* Переработать старые функции, используя новые знания.
* Доперегрузить operator >= и operator <= (ПРОТЕСТИРОВАТЬ ситуацию когда значение меньше
и когда значения равны)
*
		ИЗВЕСТНЫЕ ОШИБКИ:
*
		ПРОТЕСТИРОВАТЬ:
* CFraction() :CFraction(0, 0, 0) {}; - установил новые значения "0,0,0" вместо старого "0,1,2"
		ВИДЕО: 03:07:55(начало дз)
################################################
*/

#include <iostream>
#include "CFraction.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	CFraction fraction1{ 1,1,2 }, fraction2{ 1,1,8 }, result{};

	CFraction fraction3 = 10; 	//  Преобразование из этого типа в объект класса.

	// Перегрузка арифметических операторов с помощью методов класса:
	// Перегрузка оператора "+" для "object + object"
	CFraction fraction4 = fraction1 + fraction2; // 1,1,2 + 1,1,8 = 2,5,8

	// Перегрузка оператора "-" для "object - object"
	CFraction fraction5 = fraction1 - fraction2; // 1,1,2 - 1,1,8 = 0,3,8

	// Перегрузка оператора "*" для "object * object"
	CFraction fraction6 = fraction1 * fraction2; // 1,1,2 * 1,1,8 = 1,11,16

	// Перегрузка оператора "/" для "object / object"
	CFraction fraction7 = fraction1 / fraction2; // 1,1,2 / 1,1,8 = 1,1,3

	// Перегрузка операторов отношения с помощью методов класса:	
	// Перегрузка оператора ">" для "object > object"
	CFraction fraction8{ 1,3,4 };
	CFraction fraction9{ 1,2,4 };
	bool res = fraction8 > fraction9; // true // Сравнение дробей с одинаковыми знаменателями.
	CFraction fraction10{ 0,2,3 };
	CFraction fraction11{ 0,2,4 };
	bool res2 = fraction10 > fraction11; // true // Сравнение дробей с одинаковыми числителями.
	CFraction fraction12{ 0,5,2 };
	CFraction fraction13{ 0,2,3 };
	bool res3 = fraction12 > fraction13; // true // Сравнение дробей с разными числителями и разными знаменателями.

	// Перегрузка оператора "<" для "object < object"
	bool res4 = fraction12 < fraction13; // false 

	// Перегрузка оператора "==" для "object == object".
	CFraction fraction14{ 5,3,4 };
	CFraction fraction15{ 5,3,4 };
	bool res5 = fraction14 == fraction15; // true

	// Перегрузка оператора "!=" для "object != object".
	CFraction fraction16{ 5,3,4 };
	CFraction fraction17{ 6,4,3 };
	bool res6 = fraction16 != fraction17; // true

	// Перегрузка оператора "<=" для "object <= object"
	CFraction fraction18{ 6,4,3 };
	CFraction fraction19{ 7,4,3 };
	bool res7 = fraction18 <= fraction19; // true

	// Перегрузка оператора ">=" для "object >= object"
	CFraction fraction20{ 10,4,3 };
	CFraction fraction21{ 7,4,3 };
	bool res8 = fraction18 >= fraction19; // true


	char action; // Действие с дробями.

	char answer{ 0 }; // Do you want to continue?.

	do
	{
		cout << "Enter first fraction.\n";
		Input(fraction1);

		cout << "Enter an action: ";
		cin >> action;

		cout << "Enter second fraction.\n";
		Input(fraction2);

		switch (action)
		{
		case '+':
			result = AdditionOfFractions(fraction1, fraction2);
			break;

		case '-':
			result = FractionSubtraction(fraction1, fraction2);
			break;

		case '*':
			result = Multiplication(fraction1, fraction2);
			break;

		case '/':
			result = Division(fraction1, fraction2);
			break;
		}

		Print(result);

		cout << endl;
		cout << "Do you want to continue? ( y (yes) / n (no) )\n";
		cin >> answer;
		cout << endl;

	} while (answer == 'y');

	return 0;
}