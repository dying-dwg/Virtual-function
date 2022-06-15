#include <iostream>
#include <fstream>
#include "Math.h"
#include "ComplexNumbers.h"
#include "MVector.h"
#include "Matrix.h"

using namespace std;

Math** add_element(Math**& arr, int& size);			// добавляет элемент в массив
void from_files(Math**& arr, int& size);		// записывает данные из файла в массив
void keyboard(Math**& arr, int& size);	// записывает данные с клавиатуры в массив
void calculate(Math**& arr, int& size);	// считает площадь для всех элементов массива
void in_files(Math**& arr, int& size);		// записывает посчитанные площади в файл
void delete_arr(Math**& arr, int& size);				// удаляет все элементы массива

int main()
{
	setlocale(0, "rus");
	char pub;							// переменная для switch
	int size = 0;						// размер массива
	Math** arr = new Math * [size];	// динамический массив указателей на базовый класс

	bool i1 = true;
	while (i1)
	{
		cout << "Меню"
			<< "\n1.Считать из файла "
			<< "\n2.Ввести данные с клавиатуры "
			<< "\n3.Вычислить "
			<< "\n4.Записать в файл "
			<< "\n0.Выход.\n-> ";
		cin >> pub;

		system("cls");

		switch (pub)
		{
		case '1':
			from_files(arr, size);
			break;
		case '2':
			keyboard(arr, size);
			break;
		case '3':
			calculate(arr, size);
			break;
		case '4':
			in_files(arr, size);
			break;
		default:
			cout << "Неизвестные данные\n";
		case '0':
			delete_arr(arr, size);
			delete[] arr; // удаляем массив
			i1 = false;
		}

	}
}

Math** add_element(Math**& arr, int& size)
{
	Math** updt_arr = new Math * [size + 1];// создаём такой же массив но на 1 элемент больше
	for (int i = 0; i < size; i++)				// копируем элементы из исходного в новый
		updt_arr[i] = arr[i];
	delete[] arr;				// удаляем исходный массив
	size++;
	return updt_arr;  // возвращаем новый массив
}

void from_files(Math**& arr, int& size)
{
	ifstream fin("input.txt");	// открываем файл
	if (!fin)					// если не открылся сообщаем и выходим
	{
		cout << "Файл? Нет файла!" << endl;
		cin.ignore();
		return;
	}

	int type;	// переменная тип фигуры, считывается из файла

	for (int i = size; !fin.eof(); i++)
	{
		fin >> type; // считывание из файла

		// в зависимости от типа фигуры создаём новый элемент и присваиваем ему
		// объект соответствующего класса предварительно считав его параметры
		switch (type)
		{
		case 1: {
			double a, b;
			fin >> a >> b;
			arr = add_element(arr, size);
			arr[i] = new ComplexNumbers(a, b);
			break; }
		case 2: {
			double _arr[10];
			for (int i = 0; i < 10; i++)
				fin >> _arr[i];
			arr = add_element(arr, size);
			arr[i] = new MVector(_arr);
			break; }
		case 3: {
			double M[2][2];
			fin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1];
			arr = add_element(arr, size);
			arr[i] = new Matrix(M);
			break; }
		}
	}
	fin.close();
}

void calculate(Math**& arr, int& size)
{
	for (int i = 0; i < size; i++) // вызываем метод для каждого элемента массива
		arr[i]->Count_Norm();
}

void in_files(Math**& arr, int& size)
{
	ofstream fout("output.txt");	// открываем файл
	if (!fout)						// если не открылся сообщаем и выходим
	{
		cout << "Файл? Нет файла!" << endl;
		cin.ignore();
		return;
	}

	for (int i = 0; i < size; i++) // записываем в файл ответ для каждого элемента
		fout << arr[i]->Get_Norm() << endl;
	fout.close();
}

void keyboard(Math**& arr, int& size)
{
	char type; // переменная для switch

		// в зависимости от класса создаём  новый элемент и присваиваем ему
		// объект соответствующего класса предварительно считав его параметры
	bool i2 = true;
	while (i2)
	{

		cout << "Меню"
			<< "\n  1.Комплексные числа "
			<< "\n  2.Вектор из 10 элементов "
			<< "\n  3.Матрица (2х2) "
			<< "\n  0.Назад.\n-> ";
		cin >> type;

		system("cls");

		switch (type)
		{
		case '1': {
			double a, b;
			cout << "\nВведите действительную часть комплексного числа (а): ";
			cin >> a;
			cout << "\nВведите мнимую часть комплексного числа (b): ";
			cin >> b;
			arr = add_element(arr, size);
			arr[size - 1] = new ComplexNumbers(a, b);
			break; }
		case '2': {
			double _arr[10];
			cout << "\nВведите 10 чисел: ";
			for (int i = 0; i < 10; i++)
				cin >> _arr[i];
			arr = add_element(arr, size);
			arr[size - 1] = new MVector(_arr);
			break; }
		case '3': {
			double M[2][2];
			cout << "\nВведите 4 числа: ";
			cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1];
			arr = add_element(arr, size);
			arr[size - 1] = new Matrix(M);
			break; }
		case '0':
			i2 = false;
		}
	}
}

void delete_arr(Math**& arr, int& size)
{
	for (int i = 0; i < size; i++)
		delete arr[i];
	size = 0;
}
