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
* Предусмотреть вывод в консоль как тру значения перегрузки оператора, так и фолс,
ситуации когда значение левое меньше или больше правого и когда они равны.
* Переработать старые функции, используя новые "знания".

		ИЗВЕСТНЫЕ ОШИБКИ:
*

		ПРОТЕСТИРОВАТЬ:
*

		ВИДЕО: 03:07:55(начало дз)
################################################
*/

#include <iostream>
#include "CFraction. Class methods.h"
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

int main()
{
	CFraction fraction1{ 1,1,2 }, fraction2{ 1,1,8 }, result{};
	cout << "fraction1 = "; Print(fraction1);
	cout << "fraction2 = "; Print(fraction2);
	cout << endl;

	CFraction fraction3 = 10; 	//  Преобразование из этого типа в объект класса.
	cout << "CFraction fraction3 = 10;" << endl;
	cout << "fraction3 = ";  Print(fraction3);
	cout << endl << endl;

	// Перегрузка арифметических операторов с помощью методов класса:
	// Перегрузка оператора "+" для "object + object"
	CFraction fraction4 = fraction1 + fraction2; // 1,1,2 + 1,1,8 = 2,5,8
	cout << "CFraction fraction4 = fraction1 + fraction2;" << endl;
	cout << "fraction4 = "; Print(fraction4);
	cout << endl;

	// Перегрузка оператора "-" для "object - object"
	CFraction fraction5 = fraction1 - fraction2; // 1,1,2 - 1,1,8 = 0,3,8
	cout << "CFraction fraction5 = fraction1 - fraction2;" << endl;
	cout << "fraction5 = "; Print(fraction5);
	cout << endl;

	// Перегрузка оператора "*" для "object * object"
	CFraction fraction6 = fraction1 * fraction2; // 1,1,2 * 1,1,8 = 1,11,16
	cout << "CFraction fraction6 = fraction1 * fraction2;" << endl;
	cout << "fraction6 = "; Print(fraction6);
	cout << endl;

	// Перегрузка оператора "/" для "object / object"
	CFraction fraction7 = fraction1 / fraction2; // 1,1,2 / 1,1,8 = 1,1,3
	cout << "CFraction fraction7 = fraction1 / fraction2;" << endl;
	cout << "fraction7 = "; Print(fraction7);
	cout << endl;

	// Перегрузка операторов отношения с помощью методов класса:	
	// Перегрузка оператора ">" для "object > object"
	CFraction fraction8{ 1,3,4 };
	CFraction fraction9{ 1,2,4 };
	bool res = fraction8 > fraction9; // true // Сравнение дробей с одинаковыми знаменателями.
	cout << "CFraction fraction8{ 1,3,4 };" << endl
		<< "CFraction fraction9{ 1,2,4 };" << endl
		<< "bool res = fraction8 > fraction9;" << endl
		<< "res = " << boolalpha << res << endl << endl;


	CFraction fraction10{ 0,2,3 };
	CFraction fraction11{ 0,2,4 };
	bool res2 = fraction10 > fraction11; // true // Сравнение дробей с одинаковыми числителями.
	cout << "CFraction fraction10{ 0,2,3 };" << endl
		<< "CFraction fraction11{ 0,2,4 };" << endl
		<< "bool res2 = fraction10 > fraction11;" << endl
		<< "res2 = " << boolalpha << res2 << endl << endl;

	CFraction fraction12{ 0,5,2 };
	CFraction fraction13{ 0,2,3 };
	bool res3 = fraction12 > fraction13; // true // Сравнение дробей с разными числителями и разными знаменателями.
	cout << "CFraction fraction12{ 0,5,2 };" << endl
		<< "CFraction fraction13{ 0,2,3 };" << endl
		<< "bool res3 = fraction12 > fraction13;" << endl
		<< "res3 = " << boolalpha << res3 << endl << endl;

	// Перегрузка оператора "<" для "object < object"
	CFraction fraction122{ 0,5,2 };
	CFraction fraction133{ 2,2,3 };
	bool res4 = fraction122 < fraction133; // true 
	cout << "CFraction fraction122{ 0,5,2 };" << endl
		<< "CFraction fraction133{ 2,2,3 };" << endl
		<< "bool res4 = fraction122 < fraction133;" << endl
		<< "res4 = " << res4 << endl << endl;

	// Перегрузка оператора "==" для "object == object".
	CFraction fraction14{ 5,3,4 };
	CFraction fraction15{ 5,3,4 };
	bool res5 = fraction14 == fraction15; // true
	cout << "CFraction fraction14{ 5,3,4 };" << endl
		<< "CFraction fraction15{ 5,3,4 };" << endl
		<< "bool res5 = fraction14 == fraction15;" << endl
		<< "res5 = " << boolalpha << res5 << endl << endl;

	// Перегрузка оператора "!=" для "object != object".
	CFraction fraction16{ 5,3,4 };
	CFraction fraction17{ 6,4,3 };
	bool res6 = fraction16 != fraction17; // true
	cout << "CFraction fraction16{ 5,3,4 };" << endl
		<< "CFraction fraction17{ 6,4,3 };" << endl
		<< "bool res6 = fraction16 != fraction17;" << endl
		<< "res6 = " << boolalpha << res6 << endl << endl;

	// Перегрузка оператора "<=" для "object <= object"
	CFraction fraction18{ 6,4,3 };
	CFraction fraction19{ 7,4,3 };
	bool res7 = fraction18 <= fraction19; // true
	cout << "CFraction fraction18{ 6,4,3 };" << endl
		<< "CFraction fraction19{ 7,4,3 };" << endl
		<< "bool res7 = fraction18 <= fraction19;" << endl
		<< "res7 = " << boolalpha << res7 << endl << endl;

	// Перегрузка оператора ">=" для "object >= object"
	CFraction fraction20{ 8,4,3 };
	CFraction fraction21{ 7,4,3 };
	bool res8 = fraction20 >= fraction21;
	cout << "CFraction fraction20{ 8,4,3 };" << endl
		<< "CFraction fraction21{ 7,4,3 };" << endl
		<< "bool res8 = fraction20 >= fraction21;" << endl
		<< "res8 = " << boolalpha << res8 << endl << endl;

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