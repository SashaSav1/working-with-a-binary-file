//Необходимо хранить информацию о рефератах :
//-тема;
//-ФИО автора;
//-год издания;
//-количество страниц.
//Реализовать следующие функции, вызываемые из меню :
//1.	Ввод информации  о рефератах с клавиатуры и сохранение ее в бинарном файле с выбранным пользователем названием.
//2.	Просмотр содержимого бинарного файла с выбранным пользователем названием.
//3.	Вывод информации о рефератах по введенной пользователем фамилии автора из выбранного пользователем файла.
//4.	Вывод информации обо всех рефератах с количеством страниц более 100.

#include <iostream>
#include <fstream>

using namespace std;

struct referat 
{
	char topic[50];
	char username[50];
	int year;
	int scorePages;
};

void create()
{
	setlocale(LC_ALL, "ru");

	char name[15];

	cout << "Введите имя файла" << endl;
	cin >> name;

	fstream file(name, ios::binary | ios::app);
	file.seekp(0);

	int kol;

	cout << "Введите кол-во рефератов" << endl;
	cin >> kol;

	referat arr[5];

	for (int i = 0; i < kol; i++)
	{
		cout << "Тема реферата : ";
		cin >> arr[i].topic;
		cout << endl;
		cout << "ФИО автора : ";
		cin >> arr[i].username;
		cout << endl;
		cout << "Год издания : ";
		cin >> arr[i].year;
		cout << endl;
		cout << "Кол-во страниц : ";
		cin >> arr[i].scorePages;
		cout << endl;

		file.write(reinterpret_cast<char*>(&arr), sizeof(arr));
	}
	file.close();
}

void info()
{
	setlocale(LC_ALL, "ru");

	referat s;

	char name[10];

	cout << "Введите имя файла : ";
	cin >> name;
	cout << endl;

	ifstream file(name, ios::binary);

	file.read(reinterpret_cast<char*>(&s), sizeof(s));
	if (!file)
	{
		cout << "No file" << endl;
		return;
	}

	while (!file.eof())
	{
		cout << "Тема реферата : " << s.topic << endl;
		cout << "ФИО автора : " << s.username << endl;
		cout << "Год издания : " << s.year << endl;
		cout << "Кол-во страниц : " << s.scorePages << endl;
		file.read(reinterpret_cast<char*>(&s), sizeof(s));
	}
	
	file.close();
}

void search()
{
	setlocale(LC_ALL, "ru");

	referat s;

	char name[10];
	char name01[50];

	cout << "Введите имя файла : ";
	cin >> name;
	cout << endl;

	ifstream file(name, ios::binary);

	file.read(reinterpret_cast<char*>(&s), sizeof(s));

	if (!file)
	{
		cout << "No file" << endl;
		return;
	}

	cout << "Введите ФИО автора : ";
	cin >> name01;
	cout << endl;

	while (!file.eof())
	{
		if (s.username == name01)
		{
			cout << "Тема реферата : " << s.topic << endl;
			cout << "ФИО автора : " << s.username << endl;
			cout << "Год издания : " << s.year << endl;
			cout << "Кол-во страниц : " << s.scorePages << endl;
		}
		file.read(reinterpret_cast<char*>(&s), sizeof(s));
	}
}

void func()
{
	setlocale(LC_ALL, "ru");

	referat s;

	char name[10];
	char name01[50];
	int score = 100;


	ifstream file(name, ios::binary);

	file.read(reinterpret_cast<char*>(&s), sizeof(s));

	if (!file)
	{
		cout << "No file" << endl;
		return;
	}

	while (!file.eof())
	{
		if (s.scorePages > score)
		{
			cout << "Тема реферата : " << s.topic << endl;
			cout << "ФИО автора : " << s.username << endl;
			cout << "Год издания : " << s.year << endl;
			cout << "Кол-во страниц : " << s.scorePages << endl;
		}
		file.read(reinterpret_cast<char*>(&s), sizeof(s));
	}



}

int main()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{
		int input;

		cout << " 1. Ввод информации  о рефератах с клавиатуры и сохранение ее в бинарном файле с выбранным пользователем названием. " << endl;
		cout << " 2. Просмотр содержимого бинарного файла с выбранным пользователем названием. " << endl;
		cout << " 3. Вывод информации о рефератах по введенной пользователем фамилии автора из выбранного пользователем файла. " << endl;
		cout << " 4. Вывод информации обо всех рефератах с количеством страниц более 100. " << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			create();
			break;
		case 2:
			info();
			break;
		case 3:
			search();
			break;
		case 4:
			func();
			break;
		case 5:
			exit(0);
		}
	}
}

