#include "List.h"
#include "Definitions.h"

void list::addInCertainPlace(list::List<records::DataAboutTheChampion> **list, int placeNumber, records::DataAboutTheChampion newChampion)       // ������� �������� ������ � ����� ������������ �� ��������������� ����� 
{
	if (placeNumber == 0)
	{
		list::addBegin(list, newChampion);           // ������� � ������ ������
	}
	else
	{
		list::List<records::DataAboutTheChampion> *insert = *list;         // ����� ��������� �� ������ ������

		for (int i = 0; i < placeNumber - 1; i++)
		{
			insert = insert->next;      // ������������� �� ������� �����
		}

		list::List<records::DataAboutTheChampion> *end = insert->next;       // ��������� �� ������� �� ������� ����� ��������� ����� ������� ������ 
		list::List<records::DataAboutTheChampion> *add = new list::List<records::DataAboutTheChampion>;           // ����� �������
		insert->next = add;             // ��������� ����������� �������� �� ����� �������

		add->value = newChampion;       // ������������� ������ ��������
		add->next = end;                // ��������� ������ �������� � ���������� �������� ������
	}
}

void list::freeMemory(list::List<records::DataAboutTheChampion> *begin)       // ������������ ������ �� ������ 
{
	list::List<records::DataAboutTheChampion> *cleaner = begin;        // ����� ��������� �� ������ ������

	while (begin)
	{
		cleaner = begin;
		begin = begin->next;
		delete cleaner;
	}
}


void list::deleteCurrentElement(list::List<char> **types, char element)
{
	bool isCurrentElementFound = true;
	list::List<char> *del = *types;
	list::List<char> *temp = del->next;

	//���� ��������� ������� ������ � ��������� � ������
	if ((*types)->value == element)	
	{
		*types = (*types)->next;
		delete del;
	}
	else
	{
		// ���� �� ������ ��������� ������� ��� �� �������� ����� ������
		while (isCurrentElementFound)
		{
			temp = del;
			del = del->next;
			//���� ��������� ������� ������ � ��������� � ������
			if (del->value == element)
			{
				temp->next = del->next;
				delete del;
				isCurrentElementFound = false;
			}
		}
	}
}