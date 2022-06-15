#include <iostream>
#include <fstream>
#include "Math.h"
#include "ComplexNumbers.h"
#include "MVector.h"
#include "Matrix.h"

using namespace std;

Math** add_element(Math**& arr, int& size);			// ��������� ������� � ������
void from_files(Math**& arr, int& size);		// ���������� ������ �� ����� � ������
void keyboard(Math**& arr, int& size);	// ���������� ������ � ���������� � ������
void calculate(Math**& arr, int& size);	// ������� ������� ��� ���� ��������� �������
void in_files(Math**& arr, int& size);		// ���������� ����������� ������� � ����
void delete_arr(Math**& arr, int& size);				// ������� ��� �������� �������

int main()
{
	setlocale(0, "rus");
	char pub;							// ���������� ��� switch
	int size = 0;						// ������ �������
	Math** arr = new Math * [size];	// ������������ ������ ���������� �� ������� �����

	bool i1 = true;
	while (i1)
	{
		cout << "����"
			<< "\n1.������� �� ����� "
			<< "\n2.������ ������ � ���������� "
			<< "\n3.��������� "
			<< "\n4.�������� � ���� "
			<< "\n0.�����.\n-> ";
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
			cout << "����������� ������\n";
		case '0':
			delete_arr(arr, size);
			delete[] arr; // ������� ������
			i1 = false;
		}

	}
}

Math** add_element(Math**& arr, int& size)
{
	Math** updt_arr = new Math * [size + 1];// ������ ����� �� ������ �� �� 1 ������� ������
	for (int i = 0; i < size; i++)				// �������� �������� �� ��������� � �����
		updt_arr[i] = arr[i];
	delete[] arr;				// ������� �������� ������
	size++;
	return updt_arr;  // ���������� ����� ������
}

void from_files(Math**& arr, int& size)
{
	ifstream fin("input.txt");	// ��������� ����
	if (!fin)					// ���� �� �������� �������� � �������
	{
		cout << "����? ��� �����!" << endl;
		cin.ignore();
		return;
	}

	int type;	// ���������� ��� ������, ����������� �� �����

	for (int i = size; !fin.eof(); i++)
	{
		fin >> type; // ���������� �� �����

		// � ����������� �� ���� ������ ������ ����� ������� � ����������� ���
		// ������ ���������������� ������ �������������� ������ ��� ���������
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
	for (int i = 0; i < size; i++) // �������� ����� ��� ������� �������� �������
		arr[i]->Count_Norm();
}

void in_files(Math**& arr, int& size)
{
	ofstream fout("output.txt");	// ��������� ����
	if (!fout)						// ���� �� �������� �������� � �������
	{
		cout << "����? ��� �����!" << endl;
		cin.ignore();
		return;
	}

	for (int i = 0; i < size; i++) // ���������� � ���� ����� ��� ������� ��������
		fout << arr[i]->Get_Norm() << endl;
	fout.close();
}

void keyboard(Math**& arr, int& size)
{
	char type; // ���������� ��� switch

		// � ����������� �� ������ ������  ����� ������� � ����������� ���
		// ������ ���������������� ������ �������������� ������ ��� ���������
	bool i2 = true;
	while (i2)
	{

		cout << "����"
			<< "\n  1.����������� ����� "
			<< "\n  2.������ �� 10 ��������� "
			<< "\n  3.������� (2�2) "
			<< "\n  0.�����.\n-> ";
		cin >> type;

		system("cls");

		switch (type)
		{
		case '1': {
			double a, b;
			cout << "\n������� �������������� ����� ������������ ����� (�): ";
			cin >> a;
			cout << "\n������� ������ ����� ������������ ����� (b): ";
			cin >> b;
			arr = add_element(arr, size);
			arr[size - 1] = new ComplexNumbers(a, b);
			break; }
		case '2': {
			double _arr[10];
			cout << "\n������� 10 �����: ";
			for (int i = 0; i < 10; i++)
				cin >> _arr[i];
			arr = add_element(arr, size);
			arr[size - 1] = new MVector(_arr);
			break; }
		case '3': {
			double M[2][2];
			cout << "\n������� 4 �����: ";
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
