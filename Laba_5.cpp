// Laba_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <windows.h>
using namespace std;
struct date_of_registration
{
	int day = 1, mounth = 12, year = 2022;
};
struct car_number
{
	char series[6];
	int region;
	char country[3];
};
struct car
{
	struct date_of_registration date;
	char stamp[50];
	int year_of_release;
	char colour[20];
	struct car_number number;

};
void machine_data(car* cars, int counter)
{
	if (counter != 0)
	{
		cout << "Всего машин - " << counter << "\n\n";
		for (int i = 0; i < counter; i++)
		{
			cout << "Машина номер - " << i << "\n";
			cout << "Дата регистрации: " << cars[i].date.day << "." << cars[i].date.mounth << "." << cars[i].date.year << "\n";
			cout << "Марка автомобиля: " << cars[i].stamp << "\n";
			cout << "Год выпуска автомобиля: " << cars[i].year_of_release << "\n";
			cout << "Цвет автомобиля: " << cars[i].colour << "\n";
			cout << "Номер автомобиля: " << cars[i].number.series << " " << cars[i].number.region << " " << cars[i].number.country << "\n";
			cout << "\n";
		}
	}
	else
		cout << "Список пуст!\n\n";
}
void car_registration(car* cars, int& counter)
{
	if (counter > 49)
	{
		cout << "Превышена память, выделенная базой данных. Для решения проблемы удалите записи из базы или увеличьте ее вместительность.";
		return;
	}
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct car elem;
	cout << "Введите день регистрации:";
	cin >> elem.date.day;
	cout << "Введите месяц регистрации:";
	cin >> elem.date.mounth;
	cout << "Введите год регистрации:";
	cin >> elem.date.year;
	cout << "Введите марку:";
	cin >> elem.stamp;
	cout << "Введите год выпуска:";
	cin >> elem.year_of_release;
	cout << "Введите цвет:";
	cin >> elem.colour;
	cout << "Введите серию номера (6 символов):";
	cin >> elem.number.series;
	cout << "Введите номер региона:";
	cin >> elem.number.region;
	cout << "Введите страну номера (3 символа):";
	cin >> elem.number.country;
	cars[counter] = elem;
	counter += 1;
	cout << "\n";
}
int* find_a_car(car* cars, int& counter)
{
	int act, count = 0;
	int* dates = new int[51];
	cout << "По какому признаку необходимо идентифицировать автомобиль:\n";
	cout << "1 - По номеру в базе данных\n";
	cout << "2 - По дате регистрации\n";
	cout << "3 - По марку\n";
	cout << "4 - По году выпуска\n";
	cout << "5 - По цвету\n";
	cout << "6 - По серии номера\n";
	cout << "7 - По номеру региона\n";
	cout << "8 - По стране номера\n";
	cin >> act;
	if (act == 1)
	{
		int i;
		cout << "Введите значение:";
		cin >> i;
		if (i >= counter)
		{
			cout << "Данный номер не существует в базе данных!\n";
			dates[count] = '*';
			return dates;
		}
		cout << "\n";
		cout << "Машина номер - " << i << "\n";
		cout << "Дата регистрации: " << cars[i].date.day << "." << cars[i].date.mounth << "." << cars[i].date.year << "\n";
		cout << "Марка автомобиля: " << cars[i].stamp << "\n";
		cout << "Год выпуска автомобиля: " << cars[i].year_of_release << "\n";
		cout << "Цвет автомобиля: " << cars[i].colour << "\n";
		cout << "Номер автомобиля: " << cars[i].number.series << " " << cars[i].number.region << " " << cars[i].number.country << "\n\n";
		dates[count] = i;
		count += 1;
	}
	else if (act == 2)
	{
		int date, mounth, year;
		cout << "Введите день регистрации:";
		cin >> date;
		cout << "Введите месяц регистрации:";
		cin >> mounth;
		cout << "Введите год регистрации:";
		cin >> year;
		cout << "\n";
		for (int i = 0; i < counter; i++)
		{
			if (cars[i].date.day == date && cars[i].date.mounth == mounth && cars[i].date.year == year)
			{
				cout << "Машина номер - " << i << "\n";
				cout << "Дата регистрации: " << cars[i].date.day << "." << cars[i].date.mounth << "." << cars[i].date.year << "\n";
				cout << "Марка автомобиля: " << cars[i].stamp << "\n";
				cout << "Год выпуска автомобиля: " << cars[i].year_of_release << "\n";
				cout << "Цвет автомобиля: " << cars[i].colour << "\n";
				cout << "Номер автомобиля: " << cars[i].number.series << " " << cars[i].number.region << " " << cars[i].number.country << "\n\n";
				dates[count] = i;
				count += 1;
			}
		}
	}
	else if (act == 3)
	{
		string value, value2 = "";
		cout << "Введите значение:";
		cin >> value;
		cout << "\n";
		for (int i = 0; i < counter; i++)
		{
			for (int j = 0; j < (sizeof(cars[i].stamp) / sizeof(char)); j++)
			{
				value2 += cars[i].stamp;
			}
			if (value == value2)
			{
				cout << "Машина номер - " << i << "\n";
				cout << "Дата регистрации: " << cars[i].date.day << "." << cars[i].date.mounth << "." << cars[i].date.year << "\n";
				cout << "Марка автомобиля: " << cars[i].stamp << "\n";
				cout << "Год выпуска автомобиля: " << cars[i].year_of_release << "\n";
				cout << "Цвет автомобиля: " << cars[i].colour << "\n";
				cout << "Номер автомобиля: " << cars[i].number.series << " " << cars[i].number.region << " " << cars[i].number.country << "\n\n";
				dates[count] = i;
				count += 1;
			}
			value2 = "";
		}
	}
	else if (act == 4)
	{
		int value;
		cout << "Введите значение:";
		cin >> value;
		cout << "\n";
		for (int i = 0; i < counter; i++)
		{
			if (cars[i].year_of_release == value)
			{
				cout << "Машина номер - " << i << "\n";
				cout << "Дата регистрации: " << cars[i].date.day << "." << cars[i].date.mounth << "." << cars[i].date.year << "\n";
				cout << "Марка автомобиля: " << cars[i].stamp << "\n";
				cout << "Год выпуска автомобиля: " << cars[i].year_of_release << "\n";
				cout << "Цвет автомобиля: " << cars[i].colour << "\n";
				cout << "Номер автомобиля: " << cars[i].number.series << " " << cars[i].number.region << " " << cars[i].number.country << "\n\n";
				dates[count] = i;
				count += 1;
			}
		}
	}
	else if (act == 5)
	{
		string value, value2 = "";
		cout << "Введите значение:";
		cin >> value;
		cout << "\n";
		for (int i = 0; i < counter; i++)
		{
			for (int j = 0; j < (sizeof(cars[i].colour) / sizeof(char)); j++)
			{
				value2 += cars[i].colour;
			}
			if (value == value2)
			{
				cout << "Машина номер - " << i << "\n";
				cout << "Дата регистрации: " << cars[i].date.day << "." << cars[i].date.mounth << "." << cars[i].date.year << "\n";
				cout << "Марка автомобиля: " << cars[i].stamp << "\n";
				cout << "Год выпуска автомобиля: " << cars[i].year_of_release << "\n";
				cout << "Цвет автомобиля: " << cars[i].colour << "\n";
				cout << "Номер автомобиля: " << cars[i].number.series << " " << cars[i].number.region << " " << cars[i].number.country << "\n\n";
				dates[count] = i;
				count += 1;
			}
			value2 = "";
		}
	}
	else if (act == 6)
	{
		string value, value2 = "";
		cout << "Введите значение:";
		cin >> value;
		cout << "\n";
		for (int i = 0; i < counter; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				value2 += cars[i].number.series[j];
			}
			if (value == value2)
			{
				cout << "Машина номер - " << i << "\n";
				cout << "Дата регистрации: " << cars[i].date.day << "." << cars[i].date.mounth << "." << cars[i].date.year << "\n";
				cout << "Марка автомобиля: " << cars[i].stamp << "\n";
				cout << "Год выпуска автомобиля: " << cars[i].year_of_release << "\n";
				cout << "Цвет автомобиля: " << cars[i].colour << "\n";
				cout << "Номер автомобиля: " << cars[i].number.series << " " << cars[i].number.region << " " << cars[i].number.country << "\n\n";
				dates[count] = i;
				count += 1;
			}
			value2 = "";
		}
	}
	else if (act == 7)
	{
		int value;
		cout << "Введите значение:";
		cin >> value;
		cout << "\n";
		for (int i = 0; i < counter; i++)
		{
			if (cars[i].number.region == value)
			{
				cout << "Машина номер - " << i << "\n";
				cout << "Дата регистрации: " << cars[i].date.day << "." << cars[i].date.mounth << "." << cars[i].date.year << "\n";
				cout << "Марка автомобиля: " << cars[i].stamp << "\n";
				cout << "Год выпуска автомобиля: " << cars[i].year_of_release << "\n";
				cout << "Цвет автомобиля: " << cars[i].colour << "\n";
				cout << "Номер автомобиля: " << cars[i].number.series << " " << cars[i].number.region << " " << cars[i].number.country << "\n\n";
				dates[count] = i;
				count += 1;
			}
		}
	}
	else if (act == 8)
	{
		string value, value2 = "";
		cout << "Введите значение:";
		cin >> value;
		cout << "\n";
		for (int i = 0; i < counter; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				value2 += cars[i].number.country[j];
			}
			if (value == value2)
			{
				cout << "Машина номер - " << i << "\n";
				cout << "Дата регистрации: " << cars[i].date.day << "." << cars[i].date.mounth << "." << cars[i].date.year << "\n";
				cout << "Марка автомобиля: " << cars[i].stamp << "\n";
				cout << "Год выпуска автомобиля: " << cars[i].year_of_release << "\n";
				cout << "Цвет автомобиля: " << cars[i].colour << "\n";
				cout << "Номер автомобиля: " << cars[i].number.series << " " << cars[i].number.region << " " << cars[i].number.country << "\n\n";
				dates[count] = i;
				count += 1;
			}
			value2 = "";
		}
	}
	else
	{
		cout << "Некорректно выбрана команда. Повторите попытку." << "\n";
		find_a_car(cars, counter);
		dates[count] = '*';
		return dates;
	}
	if (count == 0)
		cout << "Совпадений нет!\n";
	dates[count] = '*';
	return dates;
}
void removing_the_machine(car* cars, int& counter, int* mass_del)
{
	int choice;
	if (mass_del[0] == '*')
		return;
	cout << "\n" << "Вы уверены, что хотите удалить эти данные? (1 - да, 2 - нет)\n";
	cin >> choice;
	if (choice == 1)
	{
		int i = 0;
		while (mass_del[i] != '*')
		{
			for (int j = mass_del[i] - i; j < counter; j++)
			{
				cars[j] = cars[j + 1];
			}
			i += 1;
			counter -= 1;
		}
	}
	else if (choice == 2)
	{
		return;
	}
	else
	{
		cout << "Некорректно введено значение. Повторите попытку.";
		removing_the_machine(cars, counter, mass_del);
	}
}
void Menu(car* cars, int& counter)
{
	int action;
	cout << "Меню:\n";
	cout << "1 - Получить данные о всех машинах в базе\n";
	cout << "2 - Регистрация новой машины в базе\n";
	cout << "3 - Удалить машину из базы\n";
	cout << "4 - Поиск машины по любой из комбинации признаков\n";
	cout << "5 - Завершить работу программы\n";
	cout << "Для выбора действия напишите его номер:\n";
	cin >> action;
	switch (action)
	{
	case 1:
		machine_data(cars, counter);
		Menu(cars, counter);
		break;
	case 2:
		car_registration(cars, counter);
		Menu(cars, counter);
		break;
	case 3:
		removing_the_machine(cars, counter, find_a_car(cars, counter));
		Menu(cars, counter);
		break;
	case 4:
		find_a_car(cars, counter);
		Menu(cars, counter);
		break;
	case 5:
		return;
		break;
	default:
		cout << "Вы не выбрали действие! Повторите попытку.\n";
		Menu(cars, counter);
		break;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	car* cars = new car[50];
	int counter = 0;
	Menu(cars, counter);
	delete[] cars;

}