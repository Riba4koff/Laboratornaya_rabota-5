#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <Windows.h>
#pragma


using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position = { 0, 0 };

enum {NUMBERS, STRINGS};

int height = 10;
int weight = 40;

int* arrA = new int[0];
int* arrB = new int[0];
int* arrC = new int[0];

string* string_arrA = new string[0];
string* string_arrB = new string[0];
string* string_arrC = new string[0];

//Проверка на валидность
bool is_number(char number[]) {
	for (int i = 0; i < 100; i++) {
		if ((char)number[i] != -52 && number[i] != '\0') {
			if (!((char)number[i] >= 48 && (char)number[i] <= 57 && number[i]))
				return false;
		}
		else
			return true;
	}
}
//Перевод из char в int
int toInt(char number[]) {
	int number_of_digits = 0;

	for (int i = 0; number[i] != '\0'; i++) {
		if ((char)number[i] != -52) {
			number_of_digits++;
		}
	}

	if (number_of_digits == 1) {
		return ((char)(number[0] - 48));
	}
	if (number_of_digits == 2) {
		return ((char)(number[0] - 48) * 10 + (char)(number[1] - 48));
	}
	if (number_of_digits == 3) {
		return (((char)(number[0] - 48) * 100) + (((char)(number[1])) - 48) * 10 + (char)(number[2]) - 48);
	}
}


void frame(const int height, const int weight) {
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j <= weight; j++) {
			if (j == 0 || j == weight || j == 25)
				cout << "|";
			else
				cout << " ";
		}
		cout << "\n";
	}
	
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";


	for (int i = 0; i < height - 1; i++) {

		for (int j = 0; j <= weight; j++)
		{
			if (j == 0 || j == weight || j == 25) cout << "|";
			else cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}
}
void startScreen(const int height, const int weight, COORD position, HANDLE hConsole) {
	frame(height, weight);
	
	position = { 4, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Действия программы";

	position = { 26, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Ожидаемый ввод";

	position = { 6, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Начало работы";

	position = { 31, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Enter";

	position = { 4, 9 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Выход из программы";
	
	position = { 32, 9 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Esc";

	position = { 0, 13 };
	SetConsoleCursorPosition(hConsole, position);
}
void choiseScreen(const int height, const int weight, COORD position, HANDLE hConsole) {
	frame(height+4, weight);

	position = { 4, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Действия программы";

	position = { 26, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Ожидаемый ввод";

	position = { 4, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Главное меню";

	position = { 31, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Esc";

	position = { 4, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Ввод массивов";

	position = { 31, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Enter";

	position = { 4, 7 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Вывод массивов";

	position = { 31, 7 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Пробел";

	position = { 4, 9 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Сортировка массивов";

	position = { 31, 9 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "E";

	position = { 4, 11 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Ввод размера мас.";

	position = { 31, 11 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Tab";

	position = { 4, 13 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Инд. задание 1";

	position = { 31, 13 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "q";

	position = { 4, 15 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Инд. задание 2";

	position = { 31, 15 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "w";

	position = { 0, 13 };
	SetConsoleCursorPosition(hConsole, position);
}
void how_fill_arrays_screen(const int height, const int weight, COORD position, HANDLE hConsole) {
	frame(height, weight);

	position = { 4, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Способ заполнения";

	position = { 26, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Ожидаемый ввод";

	position = { 7, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "C клавиатуры";

	position = { 30, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Enter";

	position = { 5, 8 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Случайным образом";

	position = { 30, 8 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Пробел";

	position = { 0, 13 };
	SetConsoleCursorPosition(hConsole, position);

}
void how_to_fill(const int height, const int weight, COORD position, HANDLE hConsole) {
	frame(height, weight);

	position = { 4, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Способ заполнения";

	position = { 26, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Ожидаемый ввод";

	position = { 5, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Заполнить числами";

	position = { 30, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Enter";

	position = { 5, 9 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Заполнить строками";

	position = { 30, 9 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Пробел";

	position = { 0, 13 };
	SetConsoleCursorPosition(hConsole, position);

}
void show_arrays_frame(const int height, const int weight) {
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j <= weight; j++) {
			if (j == 0 || j == weight || j == 15)
				cout << "|";
			else
				cout << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";


	for (int i = 0; i < height - 1; i++) {

		for (int j = 0; j <= weight; j++)
		{
			if (j == 0 || j == weight || j == 15) cout << "|";
			else cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}
}
void show_arrays_screen(const int height, const int weight, COORD position, HANDLE hConsole) {
	show_arrays_frame(height, weight);

	position = { 4, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Arrays";

	short int weight2 = weight / 2 + 5;

	position = { weight2, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "values";

	position = { 0, 13 };
	SetConsoleCursorPosition(hConsole, position);
	

}
void write_size_arrays_frame(const int height, const int weight) {
	for (int i = 0; i <= weight - 10; i++){
		cout << "-";
	}
	cout << "\n";
	for (int i = 0; i < height - 9; i++){
		for (int j = 0; j <= weight - 10; j++){
			if (j == 0 || j == (weight - 10)) cout << "|";
			else cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i <= weight - 10; i++) {
		cout << "-";
	}

}
void write_size_arrays_screen(const int height, const int weight, COORD position, HANDLE hConsole, int &size) {
	write_size_arrays_frame(height, weight);
	
	position = { 3, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Write size: ";
	cin >> size;
	
}
void filling_arrays_from_keyboard_frame(const int height, const int weight) {
	for (int i = 0; i <= weight; i++){
		cout << "-";
	}
	cout << "\n";

	for (int i = 0; i < height - 7; i++){
		for (int j = 0;  j <= weight;  j++){
			if (i == 1) cout << "-";
			else
				if (j == 0 || j == weight || j == 15) cout << "|";
				else cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i <= weight; i++) {
		cout << "-";
	}
}
void filling_arrays_from_keyboard_screen(const int height, const int weight, COORD position, HANDLE hConsole) {
	filling_arrays_from_keyboard_frame(height, weight);
	position = { 5, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Array";

	position = { 25, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "value";

	position = { 0, 5 };
	SetConsoleCursorPosition(hConsole, position);
}
void sort_arrays_screen(const int height, const int weight, COORD position, HANDLE hConsole) {
	frame(height, weight);

	position = { 8, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Сортировка";

	position = { 26, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Ожидаемый ввод";

	position = { 8, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Шелла";

	position = { 8, 6 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Выбором";

	position = { 8, 8 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Вставками";

	position = { 8, 10 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Рекурсивный";

	position = { 31, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Enter";

	position = { 32, 6 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Tab";

	position = { 31, 8 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Space";

	position = { 33, 10 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "E";



	position = { 0, 13 };
	SetConsoleCursorPosition(hConsole, position);
	
}
void result_sorted_arrays_frame(const int height, const int weight) {
	for (int i = 0; i <= weight; i++){
		cout << "-";
	}
	cout << "\n";
	for (int i = 0; i < height - 5; i++){
		for (int j = 0; j <= weight; j++){
			if (j == 0 || j == weight) cout << "|";
			else cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i <= weight; i++) {
		cout << "-";
	}
}
void result_sorted_arrays_screen(const int height, const int weight, COORD position, HANDLE hConsole, int count_permutations, int count_comparisons, int how_array, int how_sort) {
	result_sorted_arrays_frame(height, weight);

	// how_sort = 0 - Сортировка шелла
	// how_sort = 1 - Сортировка вставками
	// how_sort = 2 - Сортировка выбором
	// how_sort = 3 - Сортировка Хоара

	// how_array = 0 - arrA
	// how_array = 1 - arrB
	// how_array = 2 - arrC


	switch (how_array) {
	case 0:
		position = { 7, 1 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Массив arrA отсортирован";
		break;
	case 1:
		position = { 7, 1 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Массив arrB отсортирован";
		break;
	case 2:
		position = { 7, 1 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Массив arrC отсортирован";
		break;
	}

	switch (how_sort) {
	case 0:
		position = { 5, 5 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Сортировка шелла";
		break;
	case 1:
		position = { 5, 5 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Сортировка: вставками";
		break;
	case 2:
		position = { 5, 5 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Сортировка: выбором";
		break;
	case 3:
		position = { 5, 5 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Сортировка: рекурсивно";
		break;

	}
	position = { 5, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Кол-во перестановок: ";

	position = { 26, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << count_permutations;

	position = { 5, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Кол-во сравнений: ";

	position = { 23, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << count_comparisons;

	position = { 1, 10 };
	SetConsoleCursorPosition(hConsole, position);
}
void fill_array_with_string_frame(const int height, const int weight) {
	for (int i = 0; i <= weight+10; i++){
		cout << "-";
	}
	cout << "\n";
	for (int i = 0; i < 3; i++){
		for (int j = 0; j <= weight+10; j++){
			if (j == 0 || j == weight+10) {
				cout << "|";
			}
			else cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i <= weight+10; i++) {
		cout << "-";
	}
}
void how_array_show_screen(const int height, const int weight, COORD position, HANDLE hConsole) {
	frame(height, weight);

	position = { 9, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Действия";

	position = { 26, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Ожидаемый ввод";

	position = { 2, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Вывести массивы чисел";

	position = { 2, 9 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Вывести массивы строк";

	position = { 31, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Enter";

	position = { 31, 9 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Space";

	position = { 1, 13 };
	SetConsoleCursorPosition(hConsole, position);
}
void frame_endScreen(const int height, const int weight) {
	for (int i = 0; i < weight; i++){
		cout << "-";
	}
	cout << "\n";
	for (int i = 0; i < height; i++){
		for (int j = 0; j <= weight; j++){
			if (j == 0 || j == weight)cout << "|";
			else cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight; i++) {
		cout << "-";
	}
}
void endScreen(const int height, const int weight, COORD position, HANDLE hConsole) {
	frame_endScreen(height, weight);

	position = { 15, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Программа";

	position = { 10, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Cортировка массивов";

	position = { 9, 6 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Завершила свою работу";

	position = { 0, 12 };
	SetConsoleCursorPosition(hConsole, position);


}

void ShellSort(int* arr, const int size, int& _count_permutations, int& _count_comparisons)
{
	int i, j, step;
	int tmp;
	int count_permutations = 0;
	int count_comparisons = 0;
	
	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++)
		{
			tmp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				count_comparisons++;
				if (tmp < arr[j - step]) {
					arr[j] = arr[j - step];
					count_permutations++;
				}
				else
					break;
			}
			arr[j] = tmp;
		}
	_count_permutations = count_permutations;
	_count_comparisons = count_comparisons;
}
void ShellSortString(string *arr, const int size, int& _count_permutations, int& _count_comparisons)
{
	int i, j, step;
	string tmp;
	int count_permutations = 0;
	int count_comparisons = 0;

	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++)
		{
			tmp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				count_comparisons++;
				if (tmp.length() < arr[j - step].length()) {
					arr[j] = arr[j - step];
					count_permutations++;
				}
				else
					break;
			}
			arr[j] = tmp;
		}
	_count_permutations = count_permutations;
	_count_comparisons = count_comparisons;
}
void insertionSort(int* arr, const int size, int& _count_permutations, int& _count_comparisons) // сортировка вставками
{
	int count_permutations = 0;
	int count_comparisons = 0;
	int temp, // временная переменная для хранения значения элемента сортируемого массива
	item; // индекс предыдущего элемента
	for (int counter = 1; counter < size; counter++)
	{
		temp = arr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arr[item + 1] = arr[item]; // перестановка элементов массива
			count_permutations++;
			arr[item] = temp;
			item--;
		}
	}
	_count_permutations = count_permutations;
	_count_comparisons = count_comparisons;
}
void insertionSortString(string* arr, const int size, int& _count_permutations, int& _count_comparisons) // сортировка вставками
{
	int count_permutations = 0;
	int count_comparisons = 0;
	string temp; // временная переменная для хранения значения элемента сортируемого массива
	int	item; // индекс предыдущего элемента
	for (int counter = 1; counter < size; counter++)
	{
		temp = arr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arr[item].length() > temp.length()) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arr[item + 1] = arr[item]; // перестановка элементов массива
			count_permutations++;
			arr[item] = temp;
			item--;
		}
	}
	_count_permutations = count_permutations;
	_count_comparisons = count_comparisons;
}
void choicesSort(int* arr, const int size, int& _count_permutations, int& _count_comparisons) // сортировка выбором
{
	int count_permutations = 0;
	int count_comparisons = 0;

	for (int repeat_counter = 0; repeat_counter < size; repeat_counter++)
	{
		int temp = arr[0]; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < size; element_counter++)
		{
			count_comparisons++;
			if (arr[repeat_counter] > arr[element_counter])
			{
				temp = arr[repeat_counter];
				arr[repeat_counter] = arr[element_counter];
				arr[element_counter] = temp;
				count_permutations++;
			}
		}

	}
	_count_permutations = count_permutations;
	_count_comparisons = count_comparisons;
}
void choicesSortString(string* arr, const int size, int& _count_permutations, int& _count_comparisons) // сортировка выбором
{
	int count_permutations = 0;
	int count_comparisons = 0;

	for (int repeat_counter = 0; repeat_counter < size; repeat_counter++)
	{
		string temp = arr[0]; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < size; element_counter++)
		{
			count_comparisons++;
			if (arr[repeat_counter].length() > arr[element_counter].length())
			{
				temp = arr[repeat_counter];
				arr[repeat_counter] = arr[element_counter];
				arr[element_counter] = temp;
				count_permutations++;
			}
		}

	}
	_count_permutations = count_permutations;
	_count_comparisons = count_comparisons;
}
void quicksort(int* arr, int first, int last, int& _count_permutations, int& _count_comparisons)
{
	int count_permutations = 0;
	int count_comparisons = 0;
	int mid, count;
	int f = first, l = last;
	mid = arr[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (arr[f] < mid) { 
			f++; 
			count_comparisons++; 
		};
		while (arr[l] > mid) {
			l--; 
			count_comparisons++; 
		};

		if (f <= l) //перестановка элементов
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
			count_permutations++;
		}
	} while (f < l);
	if (first < l) quicksort(arr, first, l, _count_permutations, _count_comparisons);
	if (f < last) quicksort(arr, f, last, _count_permutations, _count_comparisons);

	_count_permutations = count_permutations;
	_count_comparisons = count_comparisons;
}
void quicksortString(string* arr, int first, int last, int& _count_permutations, int& _count_comparisons)
{
	int count_permutations = 0;
	int count_comparisons = 0;
	string temp;
	int f = first, l = last;
	string mid = arr[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (arr[f].length() < mid.length()) {
			f++;
			count_comparisons++;
		};
		while (arr[l].length() > mid.length()) {
			l--;
			count_comparisons++;
		};

		if (f <= l) //перестановка элементов
		{
			temp = arr[f];
			arr[f] = arr[l];
			arr[l] = temp;
			f++;
			l--;
			count_permutations++;
		}
	} while (f < l);
	if (first < l) quicksortString(arr, first, l, _count_permutations, _count_comparisons);
	if (f < last) quicksortString(arr, f, last, _count_permutations, _count_comparisons);

	_count_permutations = count_permutations;
	_count_comparisons = count_comparisons;
}


void lifeCycle(int height, int weight, COORD position, HANDLE hConsole, int* arrA, int* arrB, int* arrC, string *string_arrA, string* string_arrB, string* string_arrC) {
	
	system("cls");
	bool life_cycle = true;
	char choise;
	int size;

	int cnt_elem_first_arr = 0;
	int cnt_elem_second_arr = 0;
	int cnt_elem_third_arr = 0;

	do {
		//ASCII "Esc" = 27, ASCII "Enter" = 13;

		startScreen(height, weight, position, hConsole);

		life_cycle = ((choise = _getch()) == 27) ? 0 : 1;

		if (choise == 27) {
			life_cycle = false;
			system("cls");
		}
		else if (choise == 13) {
			system("cls");

			bool go_to_menu = false;
			bool size_is_writed = false;
			bool arrays_is_empty = true;
			bool string_array_is_empty = true;
			bool not_input = true;
			int what_show_or_sort = 0;
			char number[50];
			int max_index;
			bool otrizh_net = true;
			int max_min_value = 0;

			//bool array_fulled_strings = false;

			int count_permutations;
			int count_comparisons;


			do
			{
				system("cls");
				choiseScreen(height, weight, position, hConsole);
				switch (choise = _getch()) {
				//Fill arrays
				case 13:
					if (size_is_writed) {

						char local_choise;
						do
						{
							system("cls");
							how_fill_arrays_screen(height, weight, position, hConsole);
							local_choise = _getch();
							//Fill from the keyboard

							not_input = false;

							delete[] arrA;
							delete[] arrB;
							delete[] arrC;

							arrA = new int[size];
							arrB = new int[size];
							arrC = new int[size];

							delete[] string_arrA;
							delete[] string_arrB;
							delete[] string_arrC;

							string_arrA = new string[size];
							string_arrB = new string[size];
							string_arrC = new string[size];

							if (local_choise == 13) {
								system("cls");
								how_to_fill(height, weight, position, hConsole);
								char local_local_choise = _getch();
								//Заполнение чисел
								if (local_local_choise == 13) {
									arrays_is_empty = false;
									what_show_or_sort = NUMBERS;
									for (int i = 0; i < size; i++) {
										do
										{
											system("cls");
											filling_arrays_from_keyboard_screen(height, weight, position, hConsole);
											position = { 3, 3 };
											SetConsoleCursorPosition(hConsole, position);
											cout << "arrA[" << i << "]";
											position = { 27, 3 };
											SetConsoleCursorPosition(hConsole, position);
											cin >> number;
										} while (!is_number(number));
										
										arrA[i] = toInt(number);
										number[0] = '\0';

										do
										{
											system("cls");
											filling_arrays_from_keyboard_screen(height, weight, position, hConsole);
											position = { 3, 3 };
											SetConsoleCursorPosition(hConsole, position);
											cout << "arrB[" << i << "]";
											position = { 27, 3 };
											SetConsoleCursorPosition(hConsole, position);
											cin >> number;
										} while (!is_number(number));

										arrB[i] = toInt(number);
										number[0] = '\0';

										do
										{
											system("cls");
											filling_arrays_from_keyboard_screen(height, weight, position, hConsole);
											position = { 3, 3 };
											SetConsoleCursorPosition(hConsole, position);
											cout << "arrC[" << i << "]";
											position = { 27, 3 };
											SetConsoleCursorPosition(hConsole, position);
											cin >> number;
										} while (!is_number(number));

										arrC[i] = toInt(number);
										number[0] = '\0';
									}
								}
								if (local_local_choise == 32) {
									string_array_is_empty = false;
									for (int i = 0; i < size; i++){

										what_show_or_sort = STRINGS;
										system("cls");
										fill_array_with_string_frame(height, weight);
										position = { 2, 2 };
										SetConsoleCursorPosition(hConsole, position);
										cout << "write string arrA[" << i << "]: ";
										position = { 27, 2 };
										SetConsoleCursorPosition(hConsole, position);
										cin >> string_arrA[i];

										system("cls");
										fill_array_with_string_frame(height, weight);
										position = { 2, 2 };
										SetConsoleCursorPosition(hConsole, position);
										cout << "write string arrB[" << i << "]: ";
										position = { 27, 2 };
										SetConsoleCursorPosition(hConsole, position);
										cin >> string_arrB[i];

										system("cls");
										fill_array_with_string_frame(height, weight);
										position = { 2, 2 };
										SetConsoleCursorPosition(hConsole, position);
										cout << "write string arrC[" << i << "]: ";
										position = { 27, 2 };
										SetConsoleCursorPosition(hConsole, position);
										cin >> string_arrC[i];

									}
								}
							}
							//random fill
							else if (local_choise == 32) {

								what_show_or_sort = NUMBERS;

								int random;

								for (int i = 0; i < size; i++) {
									random = rand() % 2;

									if (random) arrA[i] = rand() % 100;
									else arrA[i] = (rand() % 100) * -1;
									if (random) arrB[i] = rand() % 100;
									else arrB[i] = (rand() % 100) * -1;
									if (random) arrC[i] = rand() % 100;
									else arrC[i] = (rand() % 100) * -1;
								}

								arrays_is_empty = false;

							}
						} while (local_choise != 13 && local_choise != 32);
					}
					break;
				//Show arrays
				case 32:

					system("cls");

					if (!not_input) {
						
						switch (what_show_or_sort) {
						case NUMBERS:
							if (!arrays_is_empty) {
								system("cls");

								if (size < 15) show_arrays_screen(height, (size + 8) * 3 + 8, position, hConsole);
								else show_arrays_screen(height, (size + 13) * 3 + 1, position, hConsole);

								position = { 4, 5 };
								SetConsoleCursorPosition(hConsole, position);
								cout << "arrA";

								position = { 4, 7 };
								SetConsoleCursorPosition(hConsole, position);
								cout << "arrB";

								position = { 4, 9 };
								SetConsoleCursorPosition(hConsole, position);
								cout << "arrC";

								for (int i = 0, j = 0; i < size; i++) {
									position = { (short)(18 + i + j) , 5 };
									SetConsoleCursorPosition(hConsole, position);
									cout << arrA[i];

									position = { (short)(18 + i + j) , 7 };
									SetConsoleCursorPosition(hConsole, position);
									cout << arrB[i];

									position = { (short)(18 + i + j) , 9 };
									SetConsoleCursorPosition(hConsole, position);
									cout << arrC[i];

									j += 3;
								}
								_getch();
							}
							break;
						case STRINGS:
							//array_fulled_strings = true;
							if (!string_array_is_empty) {
								system("cls");
								cout << "string_arrA: ";
								for (int i = 0; i < size; i++) {
									cout << string_arrA[i] << " ";
								}
								cout << "\nstring_arrB: ";
								for (int i = 0; i < size; i++) {
									cout << string_arrB[i] << " ";
								}
								cout << "\nstring_arrC: ";
								for (int i = 0; i < size; i++) {
									cout << string_arrC[i] << " ";
								}
							}
							cout << "\n\nНажмите любую клавишу...";
							_getch();
							break;
						}
					}
					break;
				//Sort arrays
				case 101:
					char local_local_choise;

					system("cls");
					sort_arrays_screen(height, weight, position, hConsole);
					
					switch (local_local_choise = _getch()) {
						case 13:
							if (what_show_or_sort == NUMBERS) {
								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								ShellSort(arrA, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 0, 0);
								_getch();
								system("cls");

								count_permutations = 0;
								count_comparisons = 0;
								ShellSort(arrB, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 1, 0);
								_getch();
								system("cls");

								count_permutations = 0;
								count_comparisons = 0;
								ShellSort(arrC, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 2, 0);
								_getch();
							}
							else if (what_show_or_sort == STRINGS) {
								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								ShellSortString(string_arrA, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 0, 0);
								_getch();
								system("cls");

								count_permutations = 0;
								count_comparisons = 0;
								ShellSortString(string_arrB, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 1, 0);
								_getch();
								system("cls");

								count_permutations = 0;
								count_comparisons = 0;
								ShellSortString(string_arrC, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 2, 0);
								_getch();
							}
							break;
						case 9:
							if (what_show_or_sort == NUMBERS) {
								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								choicesSort(arrA, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 0, 2);
								_getch();

								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								choicesSort(arrB, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 1, 2);
								_getch();

								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								choicesSort(arrC, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 2, 2);
								_getch();
							}
							else if (what_show_or_sort == STRINGS) {
								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								choicesSortString(string_arrA, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 0, 2);
								_getch();

								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								choicesSortString(string_arrB, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 1, 2);
								_getch();

								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								choicesSortString(string_arrC, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 2, 2);
								_getch();
							}
							break;
						case 32:
							if (what_show_or_sort == NUMBERS) {
								count_permutations = 0;
								count_comparisons = 0;
								system("cls");
								insertionSort(arrA, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 0, 1);
								_getch();
								system("cls");

								count_permutations = 0;
								count_comparisons = 0;
								insertionSort(arrB, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 1, 1);
								_getch();
								system("cls");

								count_permutations = 0;
								count_comparisons = 0;
								insertionSort(arrC, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 2, 1);
								_getch();
							}
							else if (what_show_or_sort == STRINGS) {
								count_permutations = 0;
								count_comparisons = 0;
								system("cls");
								insertionSortString(string_arrA, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 0, 1);
								_getch();
								system("cls");

								count_permutations = 0;
								count_comparisons = 0;
								insertionSortString(string_arrB, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 1, 1);
								_getch();
								system("cls");

								count_permutations = 0;
								count_comparisons = 0;
								insertionSortString(string_arrC, size, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 2, 1);
								_getch();
							}
							
							break;
						case 101:
							system("cls");
							if (what_show_or_sort == NUMBERS) {
								count_permutations = 0;
								count_comparisons = 0;
								quicksort(arrA, 0, size - 1, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 0, 3);
								_getch();

								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								quicksort(arrB, 0, size - 1, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 1, 3);
								_getch();

								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								quicksort(arrC, 0, size - 1, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 2, 3);
								_getch();
							}
							else if (what_show_or_sort == STRINGS) {
								count_permutations = 0;
								count_comparisons = 0;
								quicksortString(string_arrA, 0, size - 1, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 0, 3);
								_getch();

								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								quicksortString(string_arrB, 0, size - 1, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 1, 3);
								_getch();

								system("cls");
								count_permutations = 0;
								count_comparisons = 0;
								quicksortString(string_arrC, 0, size - 1, count_permutations, count_comparisons);
								result_sorted_arrays_screen(height, weight, position, hConsole, count_permutations, count_comparisons, 2, 3);
								_getch();
							}

							break;
							
						}
					
					break;
				//writing size arrays
				case 9:
					system("cls");
					write_size_arrays_screen(height, weight, position, hConsole, size);
					arrays_is_empty = true;
					size_is_writed = true;
					break;
				//Индивидуальное задание 1
				case 113:
					char char_p[20];
					int int_p;

					cnt_elem_first_arr = 0;
					cnt_elem_second_arr = 0;
					cnt_elem_third_arr = 0;

					do
					{
						system("cls");
						cout << "Введите значение P: ";
						cin >> char_p;
					} while (!is_number(char_p));
					int_p = toInt(char_p);

					system("cls");
					cout << "Умножить значение P на -1?\nEnter - Да, Esc - Нет";
					
					if (_getch() == 13) {
						int_p *= -1;
					}

					for (int i = 0; i < size; i++){
						if (arrA[i] * (-1) < int_p) {
							cnt_elem_first_arr++;
						}
						if (arrB[i] * (-1) < int_p) {
							cnt_elem_second_arr++;
						}
						if (arrC[i] * (-1) < int_p) {
							cnt_elem_third_arr++;
						}
					}
					system("cls");
					if (cnt_elem_first_arr < cnt_elem_second_arr && cnt_elem_first_arr < cnt_elem_third_arr) cout << "наименьшее количество элементов, обратная величина которых меньше заданного числа Р имеет массив A: " << cnt_elem_first_arr;
					if (cnt_elem_second_arr < cnt_elem_first_arr && cnt_elem_second_arr < cnt_elem_third_arr) cout << "наименьшее количество элементов, обратная величина которых меньше заданного числа Р имеет массив B: " << cnt_elem_second_arr;
					if (cnt_elem_third_arr < cnt_elem_second_arr && cnt_elem_third_arr < cnt_elem_first_arr) cout << "наименьшее количество элементов, обратная величина которых меньше заданного числа Р имеет массив C: " << cnt_elem_third_arr;
					cout << "\n\nPress any key for continue...";
					_getch();
				//Индивидуальное задание 2
				case 119:
					int int_t;
					char char_t[20];
					max_index = 0;
					max_min_value = 0;

					do
					{
						system("cls");
						cout << "Введите значение T: ";
						cin >> char_t;
					} while (!is_number(char_t));

					int_t = toInt(char_t);

					for (int i = int_t; i < size - 1; i++){
						if (arrA[i] < 0 && arrA[i] < max_min_value) {
							max_min_value = arrA[i];
							max_index = i;
							otrizh_net = false;
						}
					}

					system("cls");

					if (otrizh_net) {
						system("cls");
						cout << "Массив не готов к заданию, обновите его данные\nPress any key for continue...";
					}
					else {
						cout << "Номер элемента значение которого максимально среди отрицательных: " << max_index << "\nЕго значение: " << arrA[max_index];
						cout << "\nPress any key for coninue..";
					}

					_getch();
					
					break;
				//Exit to menu
				case 27:
					system("cls");
					go_to_menu = true;
				}
			} while (!go_to_menu);

		}
		else {
			system("cls");
		}

	} while (life_cycle);

	endScreen(height, weight, position, hConsole);
}


int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(NULL));

    lifeCycle(height, weight, position, hConsole, arrA, arrB, arrC, string_arrA, string_arrB, string_arrC);

	return 0;
}

