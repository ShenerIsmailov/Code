#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Константи
const int MAX_ORDERS = 100;
const int MAX_PROBLEM_REPAIRS = 10;
const int MAX_TYPE_ORDER = 3;
const float price_Repairs[MAX_PROBLEM_REPAIRS] = { 20,17,25,30,10,60,10,32,50,15 };
const int service_days[] = { 2,5,10 };
const string problems[MAX_PROBLEM_REPAIRS] = { "Dusty device", "Black screen on device when start","High tempreture while device is on load",
				"Slow startup", "Viruses in device","Broken screen", "The device doesn't charge",
				"Low battery life","Blue screen errors","Noisy hard drive" };
const string repairs[MAX_PROBLEM_REPAIRS] = { "Cleaning device","Installing lastes graphics drivers","Replacing thermal paste","Reinstall operating system",
				"Cleaning malwares","Replacing screen","Cleaning charging port","Replacing battery",
				"Windows repair","Mounted new hard drive" };
const string typeOfOrders[MAX_TYPE_ORDER] = { "express","fast","normal" };

//Структура
struct Order {
	int orderNumber;
	int dayOfMounth;
	char clientName[20];
	char type_Device[15];
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
bool isFill(int& n, int& sum) {
	if (sum > MAX_ORDERS)
	{
		return false;
	}
	return true;
}
//Фунцкия за проверка 
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
void preorderInput(Order order[], int& n, int& sum, int& sizeOfOrder) {
	int choice;
	cout << "Enter order count: ";	cin >> n;
	sum = n + sizeOfOrder;
	if (isFill(n, sum))
	{
		for (int i = sizeOfOrder; i < sizeOfOrder + n; i++)
		{
			cout << "Order number: "; cin >> order[i].orderNumber;
			cout << "Enter day of mounth: "; cin >> order[i].dayOfMounth;
			cin.ignore();
			cout << "Enter client name: "; cin.getline(order[i].clientName, sizeof(order[i].clientName));
			cout << "Enter type of device: "; cin.getline(order[i].type_Device, sizeof(order[i].type_Device));
			cout << "Enter a serial number of device: "; cin.getline(order[i].serialNumberOfDevice, sizeof(order[i].serialNumberOfDevice));
			cout << "Problem that you might have with a device:\n";
			for (int j = 0; j < MAX_PROBLEM_REPAIRS; j++)
			{
				cout << j + 1 << "." << problems[j] << endl;
			}
			Choice(choice);
			strcpy_s(order[i].possibleProblem, problems[choice - 1].c_str());
			strcpy_s(order[i].service_Technician_Name, " ");
			strcpy_s(order[i].repair, " ");
			order[i].price = 0.00;
			order[i].stay_Time = 0;
			strcpy_s(order[i].status_Order, "accepted");
			strcpy_s(order[i].type_Order, " ");
		}
	}
	else {
		cout << "Enter valid count of orders!\n";
		sum = 0;
	}
	sizeOfOrder += n;
}

//Таблица за извеждане на данни
void table(Order order[], int& i) {
	cout << left << setw(30) << "Order number" << "| " << setw(48) << order[i].orderNumber << "|" << endl;
	cout << '-' << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
	cout << setw(30) << "Day of mounth" << "| " << setw(48) << order[i].dayOfMounth << "|" << endl;
	cout << setw(30) << "Client name" << "| " << setw(48) << order[i].clientName << "|" << endl;
	cout << setw(30) << "Type of device" << "| " << setw(48) << order[i].type_Device << "|" << endl;
	cout << setw(30) << "Serial number of device" << "| " << setw(48) << order[i].serialNumberOfDevice << "|" << endl;
	cout << setw(30) << "Problem with a device" << "| " << setw(48) << order[i].possibleProblem << "|" << endl;
	cout << setw(30) << "Name of service technician" << "| " << setw(48) << order[i].service_Technician_Name << "|" << endl;
	cout << setw(30) << "Repair" << "| " << setw(48) << order[i].repair << "|" << endl;
	cout << setw(30) << "Price of repair" << "| " << setw(5) << fixed << setprecision(2) << order[i].price << setw(43) << " lv" << "|" << endl;
	cout << setw(30) << "Days of servicer" << "| " << setw(2) << order[i].stay_Time << setw(46) << "days" << "|" << endl;
	cout << setw(30) << "Order status" << "| " << setw(10) << setw(48) << order[i].status_Order << "|" << endl;
	cout << setw(30) << "Order type" << "| " << setw(10) << setw(48) << order[i].type_Order << "|" << endl;
	cout << '-' << setfill('-') << setw(80) << '-' << setfill(' ') << endl;

}
//Функция за извеждане на всички поръчки от масива
void printAllOrders(Order order[], int& sizeOfOrder) {
	system("cls");
	if (sizeOfOrder == 0) cout << "No orders found!\n";
	else
	{
		cout << "Orders" << endl;
		cout << '-' << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
		for (int i = 0; i < sizeOfOrder; i++) {
			table(order, i);
		}
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
		if (order[i].type_Device == type_Device)
		{
			cout << '-' << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
			table(order, i);
		}
	}
}
//Функция за търсене и извеждане на устройства по статус
void search_DisplayBy_status(Order order[], const int& sizeOfОrder) {
	string status = " ";
	cout << "Enter status: ";
	cin.ignore();
	getline(cin, status);
	cout << '-' << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
	for (int i = 0; i < sizeOfОrder; i++)
	{
		if (order[i].status_Order == status)
		{
			table(order, i);
		}
		else cout << "No orders found with this status !\n";
	}
}
//Функция за преместване на дании от една променлива в друга
void swap(int& a, int& b) {
	int buff = 0;
	buff = a;
	a = b;
	b = buff;
}
//Функция за сортиране във възходящ ред и извеждане
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
	cout << '-' << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
	for (int i = 0; i < sizeOfOrder; i++)
	{
		table(order, i);
	}
}
//Функция за отделяне на завършени поръчки по техник
void Separating_returned_orders_by_technician(Order order[], Order returned_order_arr_technician[], int& sizeOfOrder) {
	int countReturned_orders = 0;
	char technician_name[20] = " ";
	cin.ignore(); cout << "Enter technician name: ";
	cin.getline(technician_name, sizeof(technician_name));
	for (int i = 0; i < sizeOfOrder; i++)
	{
		if (strcmp(order[i].status_Order, "returned") == 0) {

			if (strcmp(order[i].service_Technician_Name, technician_name) == 0)
			{
				returned_order_arr_technician[i] = order[i];
				countReturned_orders++;
				sort_arrayByDay(returned_order_arr_technician, countReturned_orders);
			}
			else cout << "No orders found with this technician !\n";
		}
	}

}
//Функция за сортиране в низходящ ред 
void sort_descendingOrder(Order order[], int& countReturned_orders) {
	bool flag = true;
	for (int i = 0; i < countReturned_orders; i++)
	{
		if (flag == false)break; else flag = false;
		for (int j = countReturned_orders - 1; j > i; j--)
		{
			int higher = atoi(order[j].type_Device);
			int lower = atoi(order[j + 1].type_Device);
			if (higher > lower)
			{
				swap(higher, lower);
				flag = true;
			}
		}
	}
}
//Функция за отделяне на завършени поръчки по устройство
void Separating_returned_orders_by_device(Order order[], Order returned_order_arr_byProblem[], int& sizeOfOrder) {
	int countReturned_orders = 0;
	char device[20] = " ";
	cin.ignore(); cout << "Enter device name: ";
	cin.getline(device, sizeof(device));
	for (int i = 0; i < sizeOfOrder; i++)
	{
		if (strcmp(order[i].type_Device, device) == 0)
		{
			returned_order_arr_byProblem[countReturned_orders] = order[i];
			countReturned_orders++;
		}
	}
	sort_descendingOrder(returned_order_arr_byProblem, countReturned_orders);
	cout << '-' << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
	for (int i = 0; i < countReturned_orders; i++)
	{
		table(returned_order_arr_byProblem, i);
	}
}
//Функция за актуализация на поръчка
void updateOrder(Order order[], int& sizeOfOrder) {
	int choice_repair;
	int choice = 0;
	int numberOrder;
	cout << "Enter number of order to update: "; cin >> numberOrder;
	for (int i = 0; i < sizeOfOrder; i++)
	{
		if (order[i].orderNumber == numberOrder)
		{
			if (strcmp(order[i].status_Order, "returned") == 0)
			{
				cout << "You couldn't update order !\n";
				choice = 1;
			}
			else
			{
				cout << "Enter technician name: ";
				cin.ignore();
				cin.getline(order[i].service_Technician_Name, sizeof(order[i].service_Technician_Name));
				cout << "Solutions:\n";
				for (int i = 0; i < MAX_PROBLEM_REPAIRS; i++)
				{
					cout << i + 1 << "." << repairs[i] << endl;
				}
				Choice(choice_repair);
				strcpy_s(order[i].repair, repairs[choice_repair - 1].c_str());
				for (int i = 0; i < MAX_TYPE_ORDER; i++)
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
				strcpy_s(order[i].type_Order, typeOfOrders[choice - 1].c_str());
				if (choice == 1)
				{
					order[i].price = price_Repairs[choice_repair - 1] + (price_Repairs[choice_repair - 1] * 0.5f);
				}
				else if (choice == 2) {
					order[i].price = price_Repairs[choice_repair - 1] + (price_Repairs[choice_repair - 1] * 0.2f);
				}
				else {
					order[i].price = price_Repairs[choice_repair - 1];
				}
				order[i].stay_Time = service_days[choice - 1];
				strcpy_s(order[i].status_Order, "returned");
				fstream file;
				file.open("file.dat", ios::binary | ios::out);
				if (file.is_open())
				{
					file.write(reinterpret_cast<char*>(order), numberOrder * sizeof(Order));
					file.close();
				}
				else cout << "File couldn't be found !";
			}
		}
	}
	if (choice == 0)
	{
		cout << "Order couldn't found !\n";
	}
}
//Функция за запис на данни
void writeBinaryFile(Order order[], int& sizeOfOrder) {
	fstream file;
	file.open("file.dat", ios::binary | ios::out);


	if (file.is_open())
	{
		file.write(reinterpret_cast<char*>(order), sizeOfOrder * sizeof(Order));
		file.close();
		cout << "The data was recorded !\n";
	}
	else cout << "File couldn't be found !\n";
}
//Функция за прочитане на данни
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
		cout << "The data was readed !\n";
	}
	else cout << "File couldn't be found !\n";
}

int main()
{
	Order order[MAX_ORDERS];
	int choice = 0;
	int sum = 0;
	int n = 0;
	int sizeOfOrder = 0;
	readBinaryFile(order, sizeOfOrder);
	do
	{	//меню
		cout << "1.Add a new service order" << endl
			<< "2.Display all orders on screen" << endl
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
				preorderInput(order, n, sum, sizeOfOrder);
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
				while (option != 'a' && option != 'b') {
					cout << "Please enter valid option: "; cin >> option;
				}
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
				while (option != 'a' && option != 'b' && option != 'c') {
					cout << "Please enter valid option: "; cin >> option;
				}
				switch (option)
				{
				case 'a':
					sort_arrayByDay(order, sizeOfOrder);
					system("pause");
					system("cls");
					break;
				case 'b':
					Order returned_order_arr_technician[MAX_ORDERS];
					Separating_returned_orders_by_technician(order, returned_order_arr_technician, sizeOfOrder);
					system("pause");
					system("cls");
					break;
				case 'c':
					Order returned_order_arr_byProblem[MAX_ORDERS];
					Separating_returned_orders_by_device(order, returned_order_arr_byProblem, sizeOfOrder);
					system("pause");
					system("cls");
					break;
				}
				break;
			case 5:
				cout << "a.Output the order array to a file." << endl
					<< "b.Entering the order array from a file." << endl
					<< "Enter option: ";
				cin >> option;
				while (option != 'a' && option != 'b') {
					cout << "Please enter valid option: "; cin >> option;
				}
				switch (option)
				{
				case 'a':
					writeBinaryFile(order, sizeOfOrder);
					system("pause");
					system("cls");
					break;
				case 'b':
					readBinaryFile(order, sizeOfOrder);
					system("pause");
					system("cls");
					break;
				}
				break;
			case 6:updateOrder(order, sizeOfOrder);
				system("pause");
				break;
			case 7:
				writeBinaryFile(order, sizeOfOrder);
				system("pause");
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
	return 0;
}
