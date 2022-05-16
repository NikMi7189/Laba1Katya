#include "Sourse.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "1) Общая информация\n2) Аудио информация \n3) Текстовая информация\nВыбор:";
	cin >> ListNum;
	while (ListNum > 3 || ListNum < 1)
	{
		cout << "1) Общая информация\n2) Аудио информация \n3) Текстовая информация\nВыбор:";
		cin >> ListNum;
	}
	MyList* head = NULL;
	head = new MyList("SSD", 3435, "dsad", "Алексей", 213, 320, "Файл№5", 32);
	MyList* current = head;
	MyList* tail = NULL;
	tail = new MyList;
	current->Ready(*&head, *&tail, *&current);
#if VER == 1
	cout << "\nУ вас ограниченная версия приложения\n";
#else
	cout << "\nУ вас полная версия приложения\n";
#endif
	while (true) {
		cout << "\n1 - Добавить информацию";
		cout << "\n2 - Удалить информацию";
		cout << "\n3 - Изменить информацию";
		cout << "\n4 - Вывести информацию";
		cout << "\n5 - Сортировать информацию";
		cout << "\n6 - Поиск информации";
		cout << "\n7 - Сохранить информацию";
		cout << "\n8 - Загрузить информацию";
		cout << "\n0 - Выход \n";
		cout << "\nВведите номер действия: ";
		int action;
		cin >> action;
		current = head;
		switch (action) {
		case(0):
		{
			return 0;
			break;
		}
		case(1):
		{
			try
			{
				if(ListNum == 1)
					current->info.Add(*&tail, *&current);
				else if(ListNum == 2)
					current->audioInfo.Add(*&tail, *&current);
				else if (ListNum == 3)
					current->textInfo.Add(*&tail, *&current);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(2):
		{
			try
			{
				if (current == NULL && head == NULL && tail == NULL)
				{
					cout << "Нечего выводить\n";
					break;
				}
				current->info.Delete(*&head, *&tail, *&current);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(3):
		{
			try
			{
				if (current == NULL && head == NULL && tail == NULL)
				{
					cout << "Нечего выводить\n";
					break;
				}
				if (ListNum == 1)
					current->info.Change(*&current);
				else if (ListNum == 2)
					current->audioInfo.Change(*&current);
				else if (ListNum == 3)
					current->textInfo.Change(*&current);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(4):
		{
			try
			{
				if (current == NULL && head == NULL && tail == NULL)
				{
					cout << "Нечего выводить\n";
					break;
				}
				if (ListNum == 1)
					current->info.Output(*&head, *&current);
				else if (ListNum == 2)
					current->audioInfo.Output(*&head, *&current);
				else if (ListNum == 3)
					current->textInfo.Output(*&head, *&current);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(5):
		{
			try
			{
				if (current == NULL && head == NULL && tail == NULL)
				{
					cout << "Нечего выводить\n";
					break;
				}
				if (ListNum == 1)
					current->info.Sort(*&head, *&tail, *&current);
				else if (ListNum == 2)
					current->audioInfo.Sort(*&head, *&tail, *&current);
				else if (ListNum == 3)
					current->textInfo.Sort(*&head, *&tail, *&current);
			
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(6):
		{
			try
			{
				if (current == NULL && head == NULL && tail == NULL)
				{
					cout << "Нечего выводить\n";
					break;
				}
				if (ListNum == 1)
					current->info.Search(*&head, *&current);
				else if (ListNum == 2)
					current->audioInfo.Search(*&head, *&current);
				else if (ListNum == 3)
					current->textInfo.Search(*&head, *&current);		
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(7):
		{
			try
			{
				if (current == NULL && head == NULL && tail == NULL)
				{
					cout << "Нечего выводить\n";
					break;
				}
				Save_Info(*&head);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(8):
		{
			try
			{
				if (current == NULL && head == NULL && tail == NULL)
				{
					cout << "Нечего выводить\n";
					break;
				}
				Load_Info(*&tail, *&current);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		default:
		{
			cout << "\nВведен неверный номер команды\n";
			break;
		}
		}
	}
}