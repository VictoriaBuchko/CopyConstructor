#include <iostream>
using namespace std;

#define TASK 1  // поменяйте значение TASK что бы разблокировать задание 
//1 Задание Добавить конструктор копирования в класс "Контакт"
//2 Задание Добавить конструктор копирования в класс MyString

#if TASK == 1

class Contact
{
	char* Name;
	char* LastName;
	char* Surname;
	int HomePhoneNumber;
	int WorkPhoneNumber;
	int PersonalPhoneNumber;
	int Age;

public:
	Contact() : Contact(nullptr, nullptr, nullptr, 0, 0, 0, 0) {}

	Contact(const char* name, const char* lastName, const char* surname, int homePhoneNumber, int workPhoneNumber, int personalPhoneNumber, int age)
	{
		if (name != nullptr)
		{
			Name = new char[strlen(name) + 1];
			strcpy_s(Name, strlen(name) + 1, name);
		}
		else
		{
			Name = nullptr;
		}

		if (lastName != nullptr)
		{
			LastName = new char[strlen(lastName) + 1];
			strcpy_s(LastName, strlen(lastName) + 1, lastName);
		}
		else
		{
			LastName = nullptr;
		}

		if (surname != nullptr)
		{
			Surname = new char[strlen(surname) + 1];
			strcpy_s(Surname, strlen(surname) + 1, surname);
		}
		else
		{
			Surname = nullptr;
		}

		HomePhoneNumber = homePhoneNumber;
		WorkPhoneNumber = workPhoneNumber;
		PersonalPhoneNumber = personalPhoneNumber;
		Age = age;
	}

	Contact(const Contact& contact) : Name(nullptr), LastName(nullptr), Surname(nullptr),
		HomePhoneNumber(contact.HomePhoneNumber),
		WorkPhoneNumber(contact.WorkPhoneNumber),
		PersonalPhoneNumber(contact.PersonalPhoneNumber),
		Age(contact.Age) {

		if (contact.Name != nullptr) {
			Name = new char[strlen(contact.Name) + 1];
			strcpy_s(Name, strlen(contact.Name) + 1, contact.Name);
		}

		if (contact.LastName != nullptr) {
			LastName = new char[strlen(contact.LastName) + 1];
			strcpy_s(LastName, strlen(contact.LastName) + 1, contact.LastName);
		}

		if (contact.Surname != nullptr) {
			Surname = new char[strlen(contact.Surname) + 1];
			strcpy_s(Surname, strlen(contact.Surname) + 1, contact.Surname);
		}
		cout << "The copy constructor worked"<< endl;

	}



	void SetName(const char* name)
	{
		Name = new char[strlen(name) + 1];
		strcpy_s(Name, strlen(name) + 1, name);
	}

	void SetLastName(const char* lastName)
	{

		LastName = new char[strlen(lastName) + 1];
		strcpy_s(LastName, strlen(lastName) + 1, lastName);
	}

	void SetSurname(const char* surname)
	{

		Surname = new char[strlen(surname) + 1];
		strcpy_s(Surname, strlen(surname) + 1, surname);
	}

	void SetWorkPhoneNumber(int workPhoneNumber)
	{
		WorkPhoneNumber = workPhoneNumber;
	}

	void SetHomePhoneNumber(int homePhoneNumber)
	{
		HomePhoneNumber = homePhoneNumber;
	}

	void SetPersonalPhoneNumber(int personalPhoneNumber)
	{
		PersonalPhoneNumber = personalPhoneNumber;
	}
	void SetAge(int age)
	{
		Age = age;
	}


	void SetName()
	{
		if (Name != nullptr)
		{
			delete[] Name;
		}

		cout << "Enter name: ";
		char tempName[30];
		cin >> tempName;
		Name = new char[strlen(tempName) + 1];
		strcpy_s(Name, strlen(tempName) + 1, tempName);
	}

	void SetLastName()
	{

		if (LastName != nullptr)
		{
			delete[] LastName;
		}

		cout << "Enter last name: ";
		char tempLastName[30];
		cin >> tempLastName;
		LastName = new char[strlen(tempLastName) + 1];
		strcpy_s(LastName, strlen(tempLastName) + 1, tempLastName);
	}

	void SetSurname()
	{
		if (Surname != nullptr)
		{
			delete[] Surname;
		}

		cout << "Enter surname: ";
		char tempSurname[30];
		cin >> tempSurname;
		Surname = new char[strlen(tempSurname) + 1];
		strcpy_s(Surname, strlen(tempSurname) + 1, tempSurname);
	}


	void SetHomePhoneNumber() {


		do {
			cout << "Enter home phone number: ";
			cin >> HomePhoneNumber;

			if (cin.fail()) {
				cin.clear(); // Сброс флага ошибки ввода
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
			}
			else {
				break;
			}

		} while (true);

	}

	void SetWorkPhoneNumber() {

		do {
			cout << "Enter work phone number: ";
			cin >> WorkPhoneNumber;

			if (cin.fail()) {
				cin.clear(); // Сброс флага ошибки ввода
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
			}
			else {
				break;
			}

		} while (true);

	}

	void SetPersonalPhoneNumber() {

		do {
			cout << "Enter personal phone number: ";
			cin >> PersonalPhoneNumber;

			if (cin.fail()) {
				cin.clear(); // Сброс флага ошибки ввода
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
			}
			else {
				break;
			}

		} while (true);
	}

	void SetAge()
	{
		do {
			cout << "Enter age: ";
			cin >> Age;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				break;
			}
		} while (true);
	}

	void Output()
	{
		if (Name == nullptr || LastName == nullptr || Surname == nullptr)
		{
			cout << "Empty object!\n";
			return;
		}

		cout << "Name: " << Name << endl
			<< "Last Name: " << LastName << endl
			<< "Surname: " << Surname << endl
			<< "Home phone number: " << HomePhoneNumber << endl
			<< "Work phone number: " << WorkPhoneNumber << endl
			<< "Personal phone number: " << PersonalPhoneNumber << endl
			<< "Age: " << Age << endl
			<< endl;
	}


	~Contact() {//Диструктор 

		delete[] Name;
		delete[] LastName;
		delete[] Surname;
	}
};

void ContactOutPut(Contact* arr, int& size) {

	for (int i = 0; i < size; i++)//вывод всей информации
	{
		cout << "\033[1;34m------Info about " << i + 1 << " persone:------\033[0m\n\n";
		arr[i].Output();
	}
}

void ContactAdd(Contact*& arr, int& size) {

	cout << "\033[1;32mEnter a new contact:\033[0m\n " << endl;

	Contact* newArr = new Contact[size + 1];

	for (int i = 0; i < size; i++) {

		newArr[i] = arr[i];
	}

	newArr[size].SetName();
	newArr[size].SetLastName();
	newArr[size].SetSurname();
	newArr[size].SetHomePhoneNumber();
	newArr[size].SetWorkPhoneNumber();
	newArr[size].SetPersonalPhoneNumber();
	newArr[size].SetAge();

	//delete[] arr;
	arr = newArr;

	size++;
}

void ContactDelete(Contact*& arr, int& size) {

	if (size > 0) {

		int indexToDelete;

		cout << "\033[1;31mEnter the index of the contact you want to delete (1 to " << size << "):\033[0m\n ";
		cin >> indexToDelete;
		indexToDelete--;

		if (indexToDelete >= 0 && indexToDelete < size) {

			Contact* newArr = new Contact[size - 1];

			for (int i = 0, j = 0; i < size; i++) {

				if (i != indexToDelete) {

					newArr[j] = arr[i];
					j++;
				}
			}

			//delete[] arr;
			arr = newArr;

			size--;
			cout << "\033[1;31mContact at index " << indexToDelete + 1 << " deleted\033[0m\n\n\n";
		}
		else {
			cout << "\033[1;31mNo contacts deleted\033[0m\n\n\n";
		}
	}
	else {
		cout << "\033[1;31mNo contacts to delete\033[0m\n\n\n";
	}
}

int main()
{
	int size = 2;
	Contact* arr = new Contact[size];

	for (int i = 0; i < size; i++) {
		cout << "\033[1;32m------Enter info for " << i + 1 << " persone:------\033[0m\n\n\n";
		arr[i].SetName();
		arr[i].SetLastName();
		arr[i].SetSurname();
		arr[i].SetHomePhoneNumber();
		arr[i].SetWorkPhoneNumber();
		arr[i].SetPersonalPhoneNumber();
		arr[i].SetAge();//в качестве другой информации ыозраст 
		cout << endl;
	}

	cout << "\n\n";

	ContactOutPut(arr, size);
	ContactAdd(arr, size);
	ContactOutPut(arr, size);
	ContactDelete(arr, size);
	ContactOutPut(arr, size);

	Contact person = arr[0];
	person.Output();
	delete[] arr;

	return 0;
}

#elif TASK == 2


class MyString
{
	char* str;
	int size;
	static int count;//статическое поле 

public:

	MyString() : MyString(80) { }//конструктор по умолчанию

	MyString(int length) : size(length)//используем инициализатор
	{
		str = new char[size + 1];
		strcpy_s(str, size + 1, "");
		count++;
	}

	MyString(const char* Str) : MyString(strlen(Str))//при делегировании мы вызываем 2 коструктор
		//где определяем длину строки и выделяем под нее динамическую память и инициализирует ее пустой строкой
	{
		strcpy_s(str, size + 1, Str);//копирует содержимое строки Str в созданную строку(мы поручили создание этой строки коструктору 2)
		cout << "The copy constructor worked" << endl;
	}



	MyString(const MyString& string) : MyString(string.size)//использую делегирование, так как было предупреждение про неинициализированный размер
	{
		strcpy_s(str, size + 1, string.str);
	}


	void StrInput() {

		cout << "Enter a string: ";
		cin.getline(str, size + 1);
	}

	void Output()
	{
		cout << "String: " << str << endl;
	}

	static int GetCount()
	{
		return count;
	}

	~MyString() {

		delete[] str;
		count--;
	}
};

int MyString::count = 0;

int main()
{
	MyString str1;
	str1.StrInput();

	MyString str2(20);
	str2.StrInput();

	MyString str3("Hello");

	cout << "\nObjects str: \n\n";

	str1.Output();
	str2.Output();
	str3.Output();

	MyString str4 = str3;
	str4.Output();

	cout << "\nNumber of objects created " << MyString::GetCount() << endl;
	return 0;
}
#endif