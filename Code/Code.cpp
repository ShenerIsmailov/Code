#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Константи
const int SizeOfArray_Struct = 100;
const int countOfProblems_Repairs = 10;
const int count_TypeOfOrder = 3;
const float priceOfRepairs[countOfProblems_Repairs] = { 20,17,25,30,10,60,10,32,50,15 };
const int service_days[] = { 2,5,10 };
const string problems[countOfProblems_Repairs] = { "Dusty device", "Black screen on device when start","High tempreture while device is on load",
				"Slow startup", "Viruses in device","Broken screen", "The device doesn't charge",
				"Low battery life","Blue screen errors","Noisy hard drive" };
const string solutions[countOfProblems_Repairs] = { "Cleaning device","Installing lastes graphics drivers","Replacing thermal paste","Reinstall operating system",
				"Cleaning malwares","Replacing screen","Cleaning charging port","Replacing battery",
				"Windows repair","Mounted new hard drive" };
const string typeOfOrders[count_TypeOfOrder] = { "express","fast","normal" };

//Структура
struct Order {
	int orderNumber;
	int dayOfMounth;
	char clientName[20];
	char device_Type[15];
	char serialNumberOfDevice[30];
	char possibleProblem[50];
	char service_Technician_Name[20];
	char repair[50];
	float price;
	int stay_Time;
	char status_Order[20];
	char type_Order[20];
};

//Функции
//Функция за проверка дали броят поръчки, които искаме да въведем е по-голям от броя празните елементи в масива
bool isFill(const int& SizeOfArray_Struct, int& n, int& sum) {
	if (sum > SizeOfArray_Struct)
	{
		return false;
	}
	return true;
}
void Choice(int& choice) {
	cout << "Enter choice: ";
	cin >> choice;
	while ((choice - 1) < 0 || (choice - 1) > 9)
	{
		cout << "Please enter number between 1 and 10: ";
		cin >> choice;
	}
}
//функция за въвеждане на поръчки в масив
void preorderInput(Order order[], int& n, int& sum, int& sizeOfOrder, const string problems[]) {
	int choice;
	cout << "Enter order count: ";	cin >> n;
	sum += n;
	if (isFill(SizeOfArray_Struct, n, sum))
	{
		for (int i = sizeOfOrder; i < sizeOfOrder + n; i++)
		{
			cout << "Order " << i + 1 << endl;
			cout << "Order number: "; cin >> order[i].orderNumber;
			cout << "Enter day of mounth: "; cin >> order[i].dayOfMounth;
			cin.ignore();
			cout << "Enter client name: "; cin.getline(order[i].clientName, sizeof(order[i].clientName));
			cout << "Enter type of device: "; cin.getline(order[i].device_Type, sizeof(order[i].device_Type));
			cout << "Enter a serial number of device: "; cin.getline(order[i].serialNumberOfDevice, sizeof(order[i].serialNumberOfDevice));
			cout << "Problem that you might have with a device:\n";
			for (int j = 0; j < countOfProblems_Repairs; j++)
			{
				cout << j + 1 << "." << problems[j] << endl;
			}
			Choice(choice);
			strcpy_s(order[i].possibleProblem, problems[choice - 1].c_str());
			strcpy_s(order[i].service_Technician_Name, " ");
			strcpy_s(order[i].repair, " ");
			order[i].price = 0.0;
			order[i].stay_Time = 0;
			strcpy_s(order[i].status_Order, "accepted");
			strcpy_s(order[i].type_Order, " ");
		}
	}
	else {
		cout << "Enter valid count of orders!\n";
		sum = 0;
		sizeOfOrder = 0;
	}
	sizeOfOrder += n;
}

void table(Order order[], int& i) {
	cout << '-' << setfill('-') << setw(40) << '-' << setfill(' ') << endl;
	cout << left << setw(30) << "Order number" << setw(70) << order[i].orderNumber << endl;
	cout << setw(30) << "Day of mounth" << setw(70) << order[i].dayOfMounth << endl;
	cout << setw(30) << "Client name" << setw(70) << order[i].clientName << endl;
	cout << setw(30) << "Type of device" << setw(70) << order[i].device_Type << endl;
	cout << setw(30) << "Serial number of device" << setw(75) << order[i].serialNumberOfDevice << endl;
	cout << setw(30) << "Problem with a device" << setw(75) << order[i].possibleProblem << endl;
	cout << setw(30) << "Name of service technician" << setw(75) << order[i].service_Technician_Name << endl;
	cout << setw(30) << "Repair" << setw(75) << order[i].repair << endl;
	cout << setw(30) << "Price of repair" << setw(75) << order[i].price << endl;
	cout << setw(30) << "Days of servicer" << setw(75) << order[i].stay_Time << endl;
	cout << setw(30) << "Order status" << setw(75) << order[i].status_Order << endl;
	cout << setw(30) << "Order type" << setw(75) << order[i].type_Order << endl;
	cout << "\n";
}
//Функция за извеждане на всички поръчки от масива
void printAllOrders(Order order[], int& sizeOfOrder) {
	system("cls");
	if (sizeOfOrder == 0) cout << "No orders found!\n";
	else
	{
		cout << "Orders" << endl;
		for (int i = 0; i < sizeOfOrder; i++) {
			table(order, i);
		}
		cout << "\n";
	}
}
//Фунцкия за търсене и извеждане на устройства по вид
void search_DisplayByType_Device(Order order[], const int& sizeOfОrder) {
	string type_Device = " ";
	cout << "Enter type device: ";
	cin.ignore();
	getline(cin, type_Device);
	for (int i = 0; i < sizeOfОrder; i++)
	{
		if (order[i].device_Type == type_Device)
		{
			table(order, i);
		}
	}
}

void search_DisplayBy_status(Order order[], const int& sizeOfОrder) {
	string status = " ";
	cout << "Enter status: ";
	cin.ignore();
	getline(cin, status);
	for (int i = 0; i < sizeOfОrder; i++)
	{
		if (order[i].status_Order == status)
		{
			table(order, i);
		}
	}
}
//Функция за сортиране във възходящ ред
void sort_arrayByDay(Order order[], const int& sizeOfOrder) {
	bool flag = true;
	for (int i = sizeOfOrder; i > 1; i--)
	{
		if (flag == false)break; else flag = false;
		for (int j = 0; j < i - 1; j++)
		{
			if (order[j].dayOfMounth > order[j + 1].dayOfMounth)
			{
				swap(order[j], order[j + 1]);
				flag = true;
			}
		}
	}
}
//Функция за 
void swap(int& a, int& b) {
	int buff = 0;
	buff = a;
	a = b;
	b = buff;
}

void Separating_returned_orders_by_technician(Order order[], Order returned_order_arr[], int& sizeOfOrder) {
	int countReturned_orders = 0;
	char technician_name[20] = " ";
	cin.ignore();cout << "Enter technician name: ";
	cin.getline(technician_name, sizeof(technician_name));
	for (int i = 0; i < sizeOfOrder; i++)
	{
		if (strcmp(order[i].status_Order, "returned") == 0) {
			
			if (strcmp(order[i].service_Technician_Name, technician_name) == 0)
			{
				returned_order_arr[i] = order[i];
				countReturned_orders++;
			}
		}
	}
	sort_arrayByDay(returned_order_arr, countReturned_orders);
	for (int i = 0; i < countReturned_orders; i++)
	{
		cout << '-' << setfill('-') << setw(40) << '-' << setfill(' ') << endl;
		cout << left << setw(30) << "Order number" << setw(70) << order[i].orderNumber << endl;
		cout << setw(30) << "Day of mounth" << setw(70) << order[i].dayOfMounth << endl;
		cout << setw(30) << "Client name" << setw(70) << order[i].clientName << endl;
		cout << setw(30) << "Type of device" << setw(70) << order[i].device_Type << endl;
		cout << setw(30) << "Serial number of device" << setw(75) << order[i].serialNumberOfDevice << endl;
		cout << setw(30) << "Problem with a device" << setw(75) << order[i].possibleProblem << endl;
		cout << setw(30) << "Name of service technician" << setw(75) << order[i].service_Technician_Name << endl;
		cout << setw(30) << "Repair" << setw(75) << order[i].repair << endl;
		cout << setw(30) << "Price of repair" << setw(75) << order[i].price << endl;
		cout << setw(30) << "Days of servicer" << setw(75) << order[i].stay_Time << endl;
		cout << setw(30) << "Order status" << setw(75) << order[i].status_Order << endl;
		cout << setw(30) << "Order type" << setw(75) << order[i].type_Order << endl;
		cout << "\n";
	}
}
void updateOrder(Order order[], int& sizeOfOrder) {
	int choice_repair;
	int choice;
	int numberOrder = 0;
	cout << "Enter number of order to update: "; cin >> numberOrder;
	if (order[numberOrder].orderNumber = numberOrder)
	{
		if (strcmp(order[numberOrder - 1].status_Order, "returned") == 0)
		{
			cout << "You couldn't update order !\n";
		}
		else
		{
			cout << "Enter technician name: ";
			cin.ignore();
			cin.getline(order[numberOrder - 1].service_Technician_Name, sizeof(order[numberOrder - 1].service_Technician_Name));
			cout << "Solutions:\n";
			for (int i = 0; i < countOfProblems_Repairs; i++)
			{
				cout << i + 1 << "." << solutions[i] << endl;
			}
			Choice(choice_repair);
			strcpy_s(order[numberOrder - 1].repair, solutions[choice_repair - 1].c_str());
			for (int i = 0; i < count_TypeOfOrder; i++)
			{
				cout << i + 1 << "." << typeOfOrders[i] << endl;
			}
			cout << "Enter choice: ";
			cin >> choice;
			while ((choice - 1) < 0 || (choice - 1) > 3)
			{
				cout << "Please enter number between 1 and 3: ";
				cin >> choice;
			}
			strcpy_s(order[numberOrder - 1].type_Order, typeOfOrders[choice - 1].c_str());
			if (choice == 1)
			{
				order[numberOrder - 1].price = priceOfRepairs[choice_repair - 1] + (priceOfRepairs[choice_repair - 1] * 0.5);
			}
			else if (choice == 2) {
				order[numberOrder - 1].price = priceOfRepairs[choice_repair - 1] + (priceOfRepairs[choice_repair - 1] * 0.2);
			}
			else {
				order[numberOrder - 1].price = priceOfRepairs[choice_repair - 1];
			}
			order[numberOrder - 1].stay_Time = service_days[choice - 1];
			strcpy_s(order[numberOrder - 1].status_Order, "returned");
			fstream file;
			file.open("file.dat", ios::binary | ios::out);
			if (file.is_open())
			{
				file.write(reinterpret_cast<char*>(order), numberOrder * sizeof(Order));
				file.close();
			}
			else cout << "File could't be found !";
		}
	}
	else cout << "Order could't be found !\n";
}
void writeBinaryFile(Order order[], int& sizeOfOrder) {
	fstream file;
	file.open("file.dat", ios::binary | ios::out);
	if (file.is_open())
	{
		file.write(reinterpret_cast<char*>(order), sizeOfOrder * sizeof(Order));
		file.close();
	}
	else cout << "File could't be found !\n";
}
void readBinaryFile(Order order[], int& sizeOfOrder) {
	fstream file;
	file.open("file.dat", ios::binary | ios::in);
	if (file.is_open())
	{
		file.seekg(0L, ios::end);
		long pos = (long)file.tellg();
		file.close();
		sizeOfOrder = pos / (sizeof(Order));

		file.open("file.dat", ios::binary | ios::in);
		file.read((char*)order, sizeOfOrder * (sizeof(Order)));
		file.close();
	}
	else cout << "File could't be found !\n";
}

int main()
{
	Order order[SizeOfArray_Struct];
	int choice = 0;
	int sum = 0;
	int n = 0;
	int sizeOfOrder = 0;
	readBinaryFile(order, sizeOfOrder);
	do
	{	//меню
		cout << "1.Add a new service order" << endl
			<< "2.Display all devices on screen" << endl
			<< "3.Search and Display" << endl
			<< "4.Sort and display orders" << endl
			<< "5.Working with an external file" << endl
			<< "6.Entering/updating service order data" << endl
			<< "7.Exit" << endl;
		cout << '-' << setfill('-') << setw(38) << '-' << setfill(' ') << endl
			<< "Enter choice: ";
		cin >> choice;
		//валидация
		if (choice >= 1 && choice <= 7) {
			char option = ' ';
			switch (choice)
			{
			case 1:
				preorderInput(order, n, sum, sizeOfOrder, problems);
				system("pause");
				system("cls");
				break;
			case 2:
				printAllOrders(order, sizeOfOrder);
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "a.Search and display devices by type" << endl
					<< "b.Search and display devices by status" << endl
					<< "Enter option: ";
				cin >> option;
				switch (option)
				{
				case'a':
					search_DisplayByType_Device(order, sizeOfOrder);
					system("pause");
					system("cls");
					break;
				case 'b':
					search_DisplayBy_status(order, sizeOfOrder);
					system("pause");
					system("cls");
					break;
				}
				break;
			case 4:
				cout << "a.Sort orders by date received" << endl
					<< "b.Separation of completed orders to a specific technician and sorted by day of receipt" << endl
					<< "c.Separate orders with a specific problem for a device and sort in descending order by device type." << endl
					<< "Enter option: ";
				cin >> option;
				switch (option)
				{
				case 'a':
					sort_arrayByDay(order, sizeOfOrder);
					system("pause");
					system("cls");
					break;
				case 'b':
					Order returned_order_arr[SizeOfArray_Struct];
					Separating_returned_orders_by_technician(order, returned_order_arr, sizeOfOrder);
					system("pause");
					system("cls");
					//предавам и двата масива
					//създаване на масив 
					//въвеждане на име на техник
					//търсене
					//сортиране
					//извеждане на всички намерени
					//запазване в текстов файл
					break;
				case 'c':
					break;
				}
				break;
			case 5:
				cout << "a.Output the order array to a file." << endl
					<< "b.Entering the order array from a file." << endl
					<< "Enter option: ";
				cin >> option;
				switch (option)
				{
				case 'a':
					writeBinaryFile(order, sizeOfOrder);
					break;
				case 'b':
					readBinaryFile(order, sizeOfOrder);
					break;
				}
				break;
			case 6:updateOrder(order, sizeOfOrder);
				break;
			case 7:
				writeBinaryFile(order, sizeOfOrder);
				exit(1);
			}
		}
		else
		{
			system("cls");
			cout << "Please enter valid choice!\n";
			cout << '-' << setfill('-') << setw(40) << '-' << setfill(' ') << endl;
		}
	} while (choice != 7);
}