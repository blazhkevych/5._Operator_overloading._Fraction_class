/*
	Для разработанного ранее класса CFraction
перегрузить арифметические операции сложения
вычитания, умножения и деления, а также операции
отношения. Предусмотреть два способа перегрузки:
	• методами класса;
	• глобальными функциями.

	СТАТУС : Не готово.
	ВОЗМОЖНЫЕ ДОРАБОТКИ:
*
	ИЗВЕСТНЫЕ ОШИБКИ:
*
	ВИДЕО: 03:07:55(начало дз)
*/

#include <iostream>
#include "CFraction.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	CFraction f1{}, f2{}, result{};
	char action; // действие с дробями

	char answer{ 0 }; // Do you want to continue?

	do
	{
		cout << "Enter first fraction.\n";
		Input(f1);

		cout << "Enter an action: ";
		cin >> action;

		cout << "Enter second fraction.\n";
		Input(f2);

		switch (action)
		{
		case '+':
			result = AdditionOfFractions(f1, f2);
			break;

		case '-':
			result = FractionSubtraction(f1, f2);
			break;

		case '*':
			result = Multiplication(f1, f2);
			break;

		case '/':
			result = Division(f1, f2);
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