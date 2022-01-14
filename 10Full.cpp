#include <iostream> //подключаю библиотеку
#include <string> //подключаю библиотеку
#include <Windows.h> //подключаю библиотеку
#include <vector> //подключаю библиотеку
#include <cctype> //подключаю библиотеку
#include <set> //подключаю библиотеку
#pragma warning (disable: 4996) //Отключаю появление ошибки при использовании русского языка
using namespace std; //Объявление пространства имен
int main() //Начало тела главной функции
{
	SetConsoleCP(1251); //Подключения русского языка для ввода													
	SetConsoleOutputCP(1251); //Подключение русского языка для вывода
	cout << "Введите строку, разделенную пробелами: "; //Взаимодействие с пользователем
	string Original; //Объявление переменной для ввода строки пользователем														 
	vector <string> UserInput; //Объявление массива для последующей записи в него пользовательской строки
	vector <string> UserInputForDuplicate; //Объявление массива-дубликата UserInput для дуюлирования строки
	vector <string> UserInputForDelete; //Объявление массива-дубликата UserInput для удаления слова из строки
	vector <string> UserInputForSymmetric;
	vector <string> Symmetric;
	getline(cin, Original); //Получение строки от пользователя
	cout << endl;
	cout << "Проверим, есть ли в слове по индексу цифры" << endl; //Взаимодействие с пользователем
	cout << "Введите индекс слова, которое надо проверить: "; //Взаимодействие с пользователем
	int index; //Переменная для получения от пользователя индекса слова для исследования
	int maxi = 0; //Переменная для фиксирования длины максимального слова в массиве
	int max = 0;
	cin >> index; //Ввод переменной index от пользователя
	
	for (char* word = strtok((char*)Original.data(), " "); word != 0; word = strtok(0, " ")) //Начало цикла для разбиения строки пользователя на массив отдельных слов
	{
		UserInput.push_back(word); //Процесс добавления слова в массив UserInput
	}
	UserInputForDuplicate = UserInput; //Дублирование массива
	UserInputForDelete = UserInput; //Дублирование массива
	UserInputForSymmetric = UserInput;
	int i = 0; //Объявление вспомогательной переменной для перебора слов в массиве
	for (int q = 0; q < UserInput.size(); q++) //Начало цикла перебора слов в массиве
	{
		if (i == index) //Проверка соответсвует ли текущий индекс слова заданному от пользователя
		{
			size_t digits = UserInput[i].find_first_of("1234567890"); //Объявление массива всех цифр для последующего сверения с ним текущего слова, путем перебора
			if (digits <= UserInput[i].size()) { //Перебор слова из массива, выбранного по индексу, и ранее объявленного массива с цифрами
				cout << "Number found: " << atoi(UserInput[i].c_str() + digits) << endl; //Сообщение, если цифра была найдена
			}
			else { //Иначе
				cout << "Number is not found" << endl; //Сообщение, если цифра не найдена
			}
		}
		i++; //Изменение временной переменной согласно циклу
	}
	cout << endl; //Пропуск строки
	cout << endl;
	cout << "Строка до дублирования слов, стоящих на нечетных местах: " << endl; //Взаимодействия с пользователем
	for (string item : UserInputForDuplicate) //Цикл вывода массива слов в консоль
	{
		cout << item << " "; //Вывод слов из массива в консоль
	}
	cout << endl; //Пропуск строки
	cout << endl;
	for (int i = UserInputForDuplicate.size() - 1; i >= 0; i--) //Начало уикла дублирования слов, стоящих на нечетных местах
	{
		if (i % 2 != 0) //Проверка четности индекса слова
		{
			UserInputForDuplicate.push_back(UserInputForDuplicate[i]); //Дублирование слова в конец массива слов
		}
	}
	cout << "Строка после дублирования слов, стоящих на нечетных местах: " << endl; //Взаимодействие с пользователем
	for (string item : UserInputForDuplicate) //Цикл вывода массива слов в консоль
	{
		cout << item << " "; //Вывод слов из массива в консоль
	}
	cout << endl; //Пропуск строки
	cout << endl;
	for (int i = 0; i < UserInputForDelete.size(); i++) //Начало цикла поиска индекса максимального слова в массиве слов
	{
		if (max < UserInputForDelete[i].size()) //Проверка, является ли текущий индекс максимальным по отношению в индексу цикла
		{
			max = UserInputForDelete[i].size();
			maxi = i; //Присваивание текущего максимального индекса переменной
		}
	}
	cout << "Слово максимальной длины, которое будет удалено: " << UserInputForDelete[maxi]; //Взаимодействие с пользователем
	cout << endl; //Пропуск строки
	UserInputForDelete.erase(UserInputForDelete.begin() + maxi); //Удаление слова с максимальным индексом из массива слов
	for (string item : UserInputForDelete) //Цикл вывода массива слов в консоль
	{
		cout << item << " "; //Вывод слов из массива в консоль
	}
	cout << endl;
	
	for (string item : UserInputForSymmetric) 
	{
		string rev = item.data();
		reverse(rev.begin(), rev.end());
		if (rev.compare(item) == 0) 
		{
			Symmetric.push_back(item);
		}
	}
	cout << endl;
	cout << "Симметричные слова найденные в тексте" << endl;
	for (string item : Symmetric) 
	{
		cout << item << " ";
	}
	cout << endl;
	maxi = 0;
	for (int i = 0; i < Symmetric.size(); i++) //Начало цикла поиска индекса максимального слова в массиве слов
	{
		if (max < Symmetric[i].size()) //Проверка, является ли текущий индекс максимальным по отношению в индексу цикла
		{
			max = Symmetric[i].size();
			maxi = i; //Присваивание текущего максимального индекса переменной
		}
	}
	cout << "Симметричное слово максимальной длины, которое будет удалено: " << Symmetric[maxi];
	Symmetric.erase(Symmetric.begin() + maxi);
	cout << endl;
	for (string item : Symmetric)
	{
		cout << item << " ";
	}
	cout << endl;
	if (set<string>(UserInput.begin(), UserInput.end()).size() != UserInput.size())
	{
		cout << "The vector has duplicates" << endl;
	}
	else
	{
		cout << "The vector has not duplicates" << endl;
	}

	return 0; //Возращение 0
}