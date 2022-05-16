#include "Header.h"
class MyList
{
	MyList* next = NULL;
	MyList* prev = NULL;

	friend void Save_Info(MyList*&);
	friend void Load_Info(MyList*&, MyList*&);

public:

	class Info
	{
		string	Carrier;
		float	Amount;
		string	Name;
		string	Author;
	public:
		void SetCarrier(string c)
		{
			Carrier = c;
		}

		string GetCarrier()
		{
			return Carrier;
		}

		void SetAmount(float a)
		{
			Amount = a;
		}

		float GetAmount()
		{
			return Amount;
		}

		void SetName(string n)
		{
			Name = n;
		}

		string GetName()
		{
			return Name;
		}

		void SetAuthor(string a)
		{
			Author = a;
		}

		string GetAuthor()
		{
			return Author;
		}

		virtual void Add(MyList*& tail, MyList*& current)
		{
			cout << "\nВведите следующие данные для добавления\n";
			
			string buf1;
			float buf2;
			string buf3;
			string buf4;

			cout << "\nНоситель: ";
			cin.get();
			getline(cin, buf1);
			int size = buf1.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(buf1[i]))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
			}
			cout << "\nОбъём: ";
			cin >> buf2;
			if (isdigit(buf2))
			{
				throw exception("\nВведены неккоректные данные\n");
			}
			cin.get();
			cout << "\nНазвание: ";
			getline(cin, buf3);
			size = buf3.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(buf3[i]))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
			}
			cout << "\nАвтор: ";
			getline(cin, buf4);
			size = buf4.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(buf4[i]))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
			}

			current = tail;
			current->next = new MyList;
			current->next->prev = current;
			current = current->next;
			tail = current;

			current->info.SetCarrier(buf1);
			current->info.SetAmount(buf2);
			current->info.SetName(buf3);
			current->info.SetAuthor(buf4);
		}

		void Delete(MyList*& head, MyList*& tail, MyList*& current)
		{
			cout << "\nВведите номер записи, которую нужно удалить: ";
			int numStr;
			cin >> numStr;
			bool isCurrent = true;
			current = head;
			for (int i = 0; i < numStr - 1; i++)
			{
				current = current->next;
				if (!current)
				{
					isCurrent = false;
					throw exception("Такой записи не существует");
					break;
				}
			}
			if (isCurrent == true)
			{
				if (current != head && current != tail)
				{
					current->prev->next = current->next;
					current->next->prev = current->prev;
				}
				else if (current == head && current != tail)
				{
					head = current->next;
					head->prev = NULL;
				}
				else if (current == tail && current != head)
				{
					tail = current->prev;
					tail->next = NULL;
				}
				else if (current == tail && current == head)
				{
					head = NULL;
					tail = NULL;
					current = NULL;
					cout << "\nУдалена последняя запись, больше удалять нечего\n";
					return;
				}
				delete current;
				current = head;
				cout << "\nЗапись успешно удалена\n";
			}
		}

		virtual void Change(MyList*& current)
		{
			cout << "\nВведите номер записи, которую нужно изменить: ";
			int numStr;
			cin >> numStr;
			bool isCurrent = true;
			for (int i = 0; i < numStr - 1; i++)
			{
				current = current->next;
				if (!current)
				{
					isCurrent = false;
					throw exception("Такой записи не существует");
					break;
				}
			}
			if (isCurrent = true)
			{
				cout << "\nВведите следующие данные для изменения\n";

				string buf1;
				float buf2;
				string buf3;
				string buf4;

				cout << "\nНоситель: ";
				cin.get();
				getline(cin, buf1);
				int size = buf1.size();
				for (int i = 0; i < size; i++)
				{
					if (isdigit(buf1[i]))
					{
						throw exception("\nВведены неккоректные данные\n");
					}
				}
				cout << "\nОбъём: ";
				cin >> buf2;
				if (isdigit(buf2))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
				cin.get();
				cout << "\nНазвание: ";
				getline(cin, buf3);
				size = buf3.size();
				for (int i = 0; i < size; i++)
				{
					if (isdigit(buf3[i]))
					{
						throw exception("\nВведены неккоректные данные\n");
					}
				}
				cout << "\nАвтор: ";
				getline(cin, buf4);
				size = buf4.size();
				for (int i = 0; i < size; i++)
				{
					if (isdigit(buf4[i]))
					{
						throw exception("\nВведены неккоректные данные\n");
					}
				}

				current->info.SetCarrier(buf1);
				current->info.SetAmount(buf2);
				current->info.SetName(buf3);
				current->info.SetAuthor(buf4);
			}
		}

		virtual void Output(MyList*& head, MyList*& current)
		{
			cout << "|---------------------------------------------------------------------------------------|" << endl;
			cout << "| Таблица 'Общая Информация'                                                            |" << endl;
			cout << "|---------------------|---------------------|---------------------|---------------------|" << endl;
			cout << "|      Ноститель      |        Объём        |       Название      |        Автор        |" << endl;
			cout << "|---------------------|---------------------|---------------------|---------------------|" << endl;
		
			current = head;
			float sumAmounts = 0;
			while (true) {
				sumAmounts += current->info.GetAmount();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetCarrier().c_str();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetAmount();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetName().c_str();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetAuthor().c_str();
				cout << "|" << endl;
				cout << "|---------------------|---------------------|---------------------|---------------------|" << endl;
				if (current->next == NULL) break;
				current = current->next;
			}
			cout.width(22);
			cout << "|     Общий объём";
			cout << "| ";
			cout.width(20);
			cout << left << sumAmounts;
			cout << "|" << endl;
			cout << "|---------------------|---------------------|";
			sumAmounts = 0;
			current = head;
		}

		virtual void Sort(MyList*& head, MyList*& tail, MyList*& current)
		{
			current = head;
			int counter = 1;
			MyList* temp = NULL;
			temp = new MyList;
			while (true)
			{
				counter++;
				current = current->next;
				if (current == tail)
					break;
			}
			current = head;
			for (int i = 1; i < counter; i++)
			{
				current = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (current->info.GetAuthor() > current->next->info.GetAuthor())
					{
						temp->info = current->info;
						current->info = current->next->info;
						current->next->info = temp->info;
					}
					current = current->next;
				}
			}
			cout << "\nЗаписи успешно отсортированы по автору (По алфавиту)\n";
		}

		virtual void Search(MyList*& head, MyList*& current)
		{
			string searchName;
			cout << "\nВведите Название информации, которую нужно найти в списке: ";
			cin >> searchName;
			current = head;
			bool SuccesSearch = false;
			while (true)
			{
				if (searchName == current->info.GetName())
				{
					cout << "\nРЕЗУЛЬТАТ ПОИСКА\n";
					SuccesSearch = true;
					cout << "\nНоситель: " << current->info.GetCarrier()
						<< "\nОбъём: " << current->info.GetAmount()
						<< "\nНазвание: " << current->info.GetName()
						<< "\nАвтор: " << current->info.GetAuthor();
				}
				current = current->next;
				if (current->next == NULL)
					break;
			}
			current = head;
			if (SuccesSearch == true)
			{
				cout << "\nПоиск успешно завершён\n";
			}
			else
			{
				cout << "\nИнформация не найдена\n";
			}
		}

	} info;

	class AudioInfo :Info
	{
		float Duration;
		int Quality;

	public:
		void SetDuration(float d)
		{
			Duration = d;
		}

		void SetQuality(int f)
		{
			Quality = f;
		}

		float GetDuration()
		{
			return Duration;
		}

		int GetQuality()
		{
			return Quality;
		}

		void Add(MyList*& tail, MyList*& current) override
		{
			cout << "\nВведите следующие данные для добавления\n";
		
			string buf1;
			float buf2;
			string buf3;
			string buf4;
			int buf5;
			float buf6;
			string buf7;
			int buf8;
			cout << "\nНоситель: ";

			cin.get();
			getline(cin, buf1);
			int size = buf1.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(buf1[i]))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
			}
			cout << "\nОбъём: ";
			cin >> buf2;
			if (isdigit(buf2))
			{
				throw exception("\nВведены неккоректные данные\n");
			}
			cin.get();
			cout << "\nНазвание: ";
			getline(cin, buf3);
			size = buf3.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(buf3[i]))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
			}
			cout << "\nАвтор: ";
			getline(cin, buf4);
			size = buf4.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(buf4[i]))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
			}
			cout << "\nДлительность: ";
			cin >> buf5;
			cout << "\nЧастота: ";
			cin >> buf6;

			current = tail;
			current->next = new MyList;
			current->next->prev = current;
			current = current->next;
			tail = current;

			current->info.SetCarrier(buf1);
			current->info.SetAmount(buf2);
			current->info.SetName(buf3);
			current->info.SetAuthor(buf4);
			current->audioInfo.SetDuration(buf5);
			current->audioInfo.SetQuality(buf6);
		}

		void Change(MyList*& current) override
		{
			cout << "\nВведите номер записи, которую нужно изменить: ";
			int numStr;
			cin >> numStr;
			bool isCurrent = true;
			for (int i = 0; i < numStr - 1; i++)
			{
				current = current->next;
				if (!current)
				{
					isCurrent = false;
					throw exception("Такой записи не существует");
					break;
				}
			}
			if (isCurrent = true)
			{
				cout << "\nВведите следующие данные для изменения\n";

				string buf1;
				float buf2;
				string buf3;
				string buf4;
				int buf5;
				float buf6;
				string buf7;
				int buf8;
				cout << "\nНоситель: ";

				cin.get();
				getline(cin, buf1);
				int size = buf1.size();
				for (int i = 0; i < size; i++)
				{
					if (isdigit(buf1[i]))
					{
						throw exception("\nВведены неккоректные данные\n");
					}
				}
				cout << "\nОбъём: ";
				cin >> buf2;
				if (isdigit(buf2))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
				cin.get();
				cout << "\nНазвание: ";
				getline(cin, buf3);
				size = buf3.size();
				for (int i = 0; i < size; i++)
				{
					if (isdigit(buf3[i]))
					{
						throw exception("\nВведены неккоректные данные\n");
					}
				}
				cout << "\nАвтор: ";
				getline(cin, buf4);
				size = buf4.size();
				for (int i = 0; i < size; i++)
				{
					if (isdigit(buf4[i]))
					{
						throw exception("\nВведены неккоректные данные\n");
					}
				}
				cout << "\nДлительность: ";
				cin >> buf5;
				cout << "\nЧастота: ";
				cin >> buf6;

				current->info.SetCarrier(buf1);
				current->info.SetAmount(buf2);
				current->info.SetName(buf3);
				current->info.SetAuthor(buf4);
				current->audioInfo.SetDuration(buf5);
				current->audioInfo.SetQuality(buf6);
			}
		}

		void Output(MyList*& head, MyList*& current) override
		{
			cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| Таблица 'Аудио Информация'                                                                                                        |" << endl;
			cout << "|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|" << endl;
			cout << "|      Ноститель      |        Объём        |       Название      |        Автор        |     Длительность    |       Частота       |" << endl;
			cout << "|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|" << endl;

			current = head;
			float sumAmounts = 0;
			while (true) {
				sumAmounts += current->info.GetAmount();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetCarrier().c_str();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetAmount();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetName().c_str();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetAuthor().c_str();
				cout << "| ";
				cout.width(20);
				cout << left << current->audioInfo.GetDuration();
				cout << "| ";
				cout.width(20);
				cout << left << current->audioInfo.GetQuality();
				cout << "|" << endl;
				cout << "|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|" << endl;
				if (current->next == NULL) break;
				current = current->next;
			}
			cout.width(22);
			cout << "|     Общий объём";
			cout << "| ";
			cout.width(20);
			cout << left << sumAmounts;
			cout << "|" << endl;
			cout << "|---------------------|---------------------|";
			sumAmounts = 0;
			current = head;
		}

		void Sort(MyList*& head, MyList*& tail, MyList*& current) override
		{
			current = head;
			int counter = 1;
			MyList* temp = NULL;
			temp = new MyList;
			while (true)
			{
				counter++;
				current = current->next;
				if (current == tail)
					break;
			}
			current = head;
			for (int i = 1; i < counter; i++)
			{
				current = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (current->info.GetAuthor() > current->next->info.GetAuthor())
					{
						temp->info = current->info;
						current->info = current->next->info;
						current->next->info = temp->info;
						temp->audioInfo = current->audioInfo;
						current->audioInfo = current->next->audioInfo;
						current->next->audioInfo = temp-> audioInfo;
					}
					current = current->next;
				}
			}
			cout << "\nЗаписи успешно отсортированы по автору (По алфавиту)\n";
		}

		void Search(MyList*& head, MyList*& current) override
		{
			string searchName;
			cout << "\nВведите Название информации, которую нужно найти в списке: ";
			cin >> searchName;
			current = head;
			bool SuccesSearch = false;
			while (true)
			{
				if (searchName == current->info.GetName())
				{
					cout << "\nРЕЗУЛЬТАТ ПОИСКА\n";
					SuccesSearch = true;
					cout << "\nНоситель: " << current->info.GetCarrier()
						<< "\nОбъём: " << current->info.GetAmount()
						<< "\nНазвание: " << current->info.GetName()
						<< "\nАвтор: " << current->info.GetAuthor();
					cout << "\nДлительность: " << current->audioInfo.GetDuration()
							<< "\nЧастота: " << current->audioInfo.GetQuality();
				}
				current = current->next;
				if (current->next == NULL)
					break;
			}
			current = head;
			if (SuccesSearch == true)
			{
				cout << "\nПоиск успешно завершён\n";
			}
			else
			{
				cout << "\nИнформация не найдена\n";
			}
		}

	} audioInfo;

	class TextInfo :Info
	{
		string Text;
		int countSym;

	public:
		void SetText(string t)
		{
			Text = t;
		}

		void SetCountSym(int c)
		{
			countSym = c;
		}

		string GetText()
		{
			return Text;
		}

		int GetCountSym()
		{
			return countSym;
		}

		void Add(MyList*& tail, MyList*& current) override
		{
			cout << "\nВведите следующие данные для добавления\n";

			string buf1;
			float buf2;
			string buf3;
			string buf4;
			string buf7;
			int buf8;

			cout << "\nНоситель: ";
			cin.get();
			getline(cin, buf1);
			int size = buf1.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(buf1[i]))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
			}
			cout << "\nОбъём: ";
			cin >> buf2;
			if (isdigit(buf2))
			{
				throw exception("\nВведены неккоректные данные\n");
			}
			cin.get();
			cout << "\nНазвание: ";
			getline(cin, buf3);
			size = buf3.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(buf3[i]))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
			}
			cout << "\nАвтор: ";
			getline(cin, buf4);
			size = buf4.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(buf4[i]))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
			}
			cout << "\nТекст: ";
			getline(cin, buf7);
			cout << "\nКоличество символов: ";
			cin >> buf8;

			current = tail;
			current->next = new MyList;
			current->next->prev = current;
			current = current->next;
			tail = current;

			current->info.SetCarrier(buf1);
			current->info.SetAmount(buf2);
			current->info.SetName(buf3);
			current->info.SetAuthor(buf4);
			current->textInfo.SetText(buf7);
			current->textInfo.SetCountSym(buf8);
		}

		void Change(MyList*& current) override
		{
			cout << "\nВведите номер записи, которую нужно изменить: ";
			int numStr;
			cin >> numStr;
			bool isCurrent = true;
			for (int i = 0; i < numStr - 1; i++)
			{
				current = current->next;
				if (!current)
				{
					isCurrent = false;
					throw exception("Такой записи не существует");
					break;
				}
			}
			if (isCurrent = true)
			{
				cout << "\nВведите следующие данные для изменения\n";

				string buf1;
				float buf2;
				string buf3;
				string buf4;
				string buf7;
				int buf8;

				cout << "\nНоситель: ";
				cin.get();
				getline(cin, buf1);
				int size = buf1.size();
				for (int i = 0; i < size; i++)
				{
					if (isdigit(buf1[i]))
					{
						throw exception("\nВведены неккоректные данные\n");
					}
				}
				cout << "\nОбъём: ";
				cin >> buf2;
				if (isdigit(buf2))
				{
					throw exception("\nВведены неккоректные данные\n");
				}
				cin.get();
				cout << "\nНазвание: ";
				getline(cin, buf3);
				size = buf3.size();
				for (int i = 0; i < size; i++)
				{
					if (isdigit(buf3[i]))
					{
						throw exception("\nВведены неккоректные данные\n");
					}
				}
				cout << "\nАвтор: ";
				getline(cin, buf4);
				size = buf4.size();
				for (int i = 0; i < size; i++)
				{
					if (isdigit(buf4[i]))
					{
						throw exception("\nВведены неккоректные данные\n");
					}
				}
				cout << "\nТекст: ";
				getline(cin, buf7);
				cout << "\nКоличество символов: ";
				cin >> buf8;

				current->info.SetCarrier(buf1);
				current->info.SetAmount(buf2);
				current->info.SetName(buf3);
				current->info.SetAuthor(buf4);
				current->textInfo.SetText(buf7);
				current->textInfo.SetCountSym(buf8);
			}
		}

		void Output(MyList*& head, MyList*& current) override
		{
			cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| Таблица 'Текстовая Информация'                                                                                                    |" << endl;
			cout << "|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|" << endl;
			cout << "|      Ноститель      |        Объём        |       Название      |        Автор        |        Текст        | Количество символов |" << endl;
			cout << "|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|" << endl;

			current = head;
			float sumAmounts = 0;
			while (true) {
				sumAmounts += current->info.GetAmount();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetCarrier().c_str();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetAmount();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetName().c_str();
				cout << "| ";
				cout.width(20);
				cout << left << current->info.GetAuthor().c_str();
				cout << "| ";
				cout.width(20);
				cout << left << current->textInfo.GetText().c_str();
				cout << "| ";
				cout.width(20);
				cout << left << current->textInfo.GetCountSym();
				cout << "|" << endl;
				cout << "|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|" << endl;
				if (current->next == NULL) break;
				current = current->next;
			}
			cout.width(22);
			cout << "|     Общий объём";
			cout << "| ";
			cout.width(20);
			cout << left << sumAmounts;
			cout << "|" << endl;
			cout << "|---------------------|---------------------|";
			sumAmounts = 0;
			current = head;
		}

		void Search(MyList*& head, MyList*& current) override
		{
			string searchName;
			cout << "\nВведите Название информации, которую нужно найти в списке: ";
			cin >> searchName;
			current = head;
			bool SuccesSearch = false;
			while (true)
			{
				if (searchName == current->info.GetName())
				{
					cout << "\nРЕЗУЛЬТАТ ПОИСКА\n";
					SuccesSearch = true;
					cout << "\nНоситель: " << current->info.GetCarrier()
						<< "\nОбъём: " << current->info.GetAmount()
						<< "\nНазвание: " << current->info.GetName()
						<< "\nАвтор: " << current->info.GetAuthor();
					cout << "\nТекст: " << current->textInfo.GetText()
						<< "\nКоличество символов: " << current->textInfo.GetCountSym();
				}
				current = current->next;
				if (current->next == NULL)
					break;
			}
			current = head;
			if (SuccesSearch == true)
			{
				cout << "\nПоиск успешно завершён\n";
			}
			else
			{
				cout << "\nИнформация не найдена\n";
			}
		}

		void Sort(MyList*& head, MyList*& tail, MyList*& current) override
		{
			current = head;
			int counter = 1;
			MyList* temp = NULL;
			temp = new MyList;
			while (true)
			{
				counter++;
				current = current->next;
				if (current == tail)
					break;
			}
			current = head;
			for (int i = 1; i < counter; i++)
			{
				current = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (current->info.GetAuthor() > current->next->info.GetAuthor())
					{
						temp->info = current->info;
						current->info = current->next->info;
						current->next->info = temp->info;
						temp->textInfo = current->textInfo;
						current->textInfo = current->next->textInfo;
						current->next->textInfo = temp->textInfo;
					}
					current = current->next;
				}
			}
			cout << "\nЗаписи успешно отсортированы по автору (По алфавиту)\n";
		}

	} textInfo;

	MyList()
	{
		info.SetCarrier("");
		info.SetAmount(0);
		info.SetName("");
		info.SetAuthor("");
		audioInfo.SetDuration(0);
		audioInfo.SetQuality(0.0);
		textInfo.SetCountSym(0);
		textInfo.SetText("");
	};

	MyList(string Carrier, float Amount, string Name, string Author, int Duration, float Quality, string Text, int CountSym)
	{
		info.SetCarrier(Carrier);
		info.SetAmount(Amount);
		info.SetName(Name);
		info.SetAuthor(Author);
		if (ListNum == 2)
		{
			audioInfo.SetDuration(Duration);
			audioInfo.SetQuality(Quality);
		}
		else if (ListNum == 3)
		{
			textInfo.SetText(Text);
			textInfo.SetCountSym(CountSym);
		}
	};

	void Ready(MyList*& head, MyList*& tail, MyList*& current)
	{
		while (true)
		{
			if (current->next == NULL)
				break;
			current = current->next;
			tail = current;
		}

		string Carriers[4] = { "Флешка", "Флешка", "HDD", "HDD" };
		float Amounts[4] = { 533, 444, 124, 55352 };
		string Names[4] = { "jjksd", "hgf", "asdasd", "qwe" };
		string Authos[4] = { "Никита", "Эмма",	"Екатерина", "Александр" };
		int Durations[4] = { 130, 40, 540, 8100 };
		float Qualitys[4] = { 320, 190, 220, 190 };
		string Texts[4] = { "Файл№1", "Файл№2", "Файл№3", "Файл№4" };
		int Counts[4] = { 531, 541, 3444, 20000 };

		for (int i = 0; i < 4; i++) {
			current->next = new MyList(Carriers[i], Amounts[i], Names[i], Authos[i], Durations[i], Qualitys[i], Texts[i], Counts[i]);
			current->next->prev = current;
			current = current->next;
			tail = current;
		}
	}

};

void Save_Info(MyList*& head)
{
#if VER == 2
	int Name = -5;
	while (Name < 1 || Name > 2)
	{
		cout << "Сохранить в?" << endl;
		cout << "1 - MyList.txt" << endl;
		cout << "2 - В другой файл" << endl;
		cout << "Действие: ";
		cin >> Name;
		if (Name < 1 || Name > 2)
		{
			cout << "Некоректный номер действия";
		}
	}
	switch (Name)
	{
	case 1:
	{
		ofstream inFile;
		inFile.open("MyList.txt");
		if (!inFile)
		{
			throw exception("Неудачное открытие файла");
			break;
		}
		else
		{
			MyList* thatRecord = head;
			while (thatRecord)
			{
				MyList Informat = *thatRecord;
				inFile << Informat.info.GetCarrier() << ' ' << Informat.info.GetAmount() << ' ' << Informat.info.GetName() << ' ' << Informat.info.GetAuthor();
				if (ListNum == 2)
				{
					inFile << ' ' << Informat.audioInfo.GetDuration() << ' ' << Informat.audioInfo.GetQuality();
				}
				else if (ListNum == 3)
				{
					inFile << ' ' << Informat.textInfo.GetText() << ' ' << Informat.textInfo.GetCountSym();
				}
				thatRecord = thatRecord->next;
				if (thatRecord)
					inFile << endl;
			}
		}
		break;
	}
	case 2:
	{
		cout << "Введите название файла для сохранения данных: ";
		string filename;
		cin >> filename;
		filename += ".txt";
		ofstream inFile;
		inFile.open(filename);
		if (!inFile)
		{
			throw exception("Неудачное открытие файла");
			break;
		}
		else
		{
			MyList* thatRecord = head;
			while (thatRecord)
			{
				MyList Informat = *thatRecord;
				inFile << Informat.info.GetCarrier() << ' ' << Informat.info.GetAmount() << ' ' << Informat.info.GetName() << ' ' << Informat.info.GetAuthor();
				if (ListNum == 2)
				{
					inFile << ' ' << Informat.audioInfo.GetDuration() << ' ' << Informat.audioInfo.GetQuality();
				}
				else if (ListNum == 3)
				{
					inFile << ' ' << Informat.textInfo.GetText() << ' ' << Informat.textInfo.GetCountSym();
				}
				thatRecord = thatRecord->next;
				if (thatRecord)
					inFile << endl;
			}
		}
		break;
	}
	}
#else
	cout << "\nУ вас ограниченная версия приложения, эта функция недоступна\n";
#endif
	}

void Load_Info(MyList*& tail, MyList*& current)
{
#if VER == 2
	int Name = -5;
	while (Name < 1 || Name > 2)
	{
		cout << "Загрузить из?" << endl;
		cout << "1 - MyList.txt" << endl;
		cout << "2 - Из другого файла" << endl;
		cout << "Действие: ";
		cin >> Name;
		if (Name < 1 || Name > 2)
		{
			cout << "Некоректный номер действия";
		}
	}
	switch (Name)
	{
	case 1:
	{
		ifstream outFile;
		outFile.open("MyList.txt");
		if (!outFile)
		{
			throw exception("Неудачное открытие файла");
			break;
		}
		else
		{
			while (outFile.eof() == false)
			{
				string buf1;
				float buf2;
				string buf3;
				string buf4;
				int buf5;
				float buf6;
				string buf7;
				int buf8;
				MyList* thatRecord = new MyList;
				outFile >> buf1 >> buf2 >> buf3 >> buf4;
				thatRecord->info.SetCarrier(buf1);
				thatRecord->info.SetAmount(buf2);
				thatRecord->info.SetName(buf3);
				thatRecord->info.SetAuthor(buf4);
				if (ListNum == 2)
				{
					outFile >> buf5 >> buf6;
					thatRecord->audioInfo.SetDuration(buf5);
					thatRecord->audioInfo.SetQuality(buf6);
				}
				else if (ListNum == 3)
				{
					outFile >> buf7 >> buf8;
					thatRecord->textInfo.SetText(buf7);
					thatRecord->textInfo.SetCountSym(buf8);
				}
				current = tail;
				current->next = new MyList;
				current = current->next;
				tail = current;

				current->info.SetCarrier(thatRecord->info.GetCarrier());
				current->info.SetAmount(thatRecord->info.GetAmount());
				current->info.SetName(thatRecord->info.GetName());
				current->info.SetAuthor(thatRecord->info.GetAuthor());
				if (ListNum == 2)
				{
					current->audioInfo.SetDuration(thatRecord->audioInfo.GetDuration());
					current->audioInfo.SetQuality(thatRecord->audioInfo.GetQuality());
				}
				else if (ListNum == 3)
				{
					current->textInfo.SetText(thatRecord->textInfo.GetText());
					current->textInfo.SetCountSym(thatRecord->textInfo.GetCountSym());
				}
			}
			outFile.close();
		}
		break;
	}
	case 2:
	{
		cout << "Введите название файла для загрузки данных: ";
		string filename;
		cin >> filename;
		filename += ".txt";
		ifstream outFile;
		outFile.open(filename);
		if (!outFile)
		{
			throw exception("Неудачное открытие файла");
			break;
		}
		else
		{
			while (outFile.eof() == false)
			{
				string buf1;
				float buf2;
				string buf3;
				string buf4;
				int buf5;
				float buf6;
				string buf7;
				int buf8;
				MyList* thatRecord = new MyList;
				outFile >> buf1 >> buf2 >> buf3 >> buf4;
				thatRecord->info.SetCarrier(buf1);
				thatRecord->info.SetAmount(buf2);
				thatRecord->info.SetName(buf3);
				thatRecord->info.SetAuthor(buf4);
				if (ListNum == 2)
				{
					outFile >> buf5 >> buf6;
					thatRecord->audioInfo.SetDuration(buf5);
					thatRecord->audioInfo.SetQuality(buf6);
				}
				else if (ListNum == 3)
				{
					outFile >> buf7 >> buf8;
					thatRecord->textInfo.SetText(buf7);
					thatRecord->textInfo.SetCountSym(buf8);
				}
				current = tail;
				current->next = new MyList;
				current = current->next;
				tail = current;

				current->info.SetCarrier(thatRecord->info.GetCarrier());
				current->info.SetAmount(thatRecord->info.GetAmount());
				current->info.SetName(thatRecord->info.GetName());
				current->info.SetAuthor(thatRecord->info.GetAuthor());
				if (ListNum == 2)
				{
					current->audioInfo.SetDuration(thatRecord->audioInfo.GetDuration());
					current->audioInfo.SetQuality(thatRecord->audioInfo.GetQuality());
				}
				else if (ListNum == 3)
				{
					current->textInfo.SetText(thatRecord->textInfo.GetText());
					current->textInfo.SetCountSym(thatRecord->textInfo.GetCountSym());
				}
			}
			outFile.close();
		}
		break;
	}
	break;
	}
#else
	cout << "\nУ вас ограниченная версия приложения, эта функция недоступна\n";
#endif
}