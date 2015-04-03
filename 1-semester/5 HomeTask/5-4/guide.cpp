#include "guide.h"

struct GuideElement
{
	char *name;
	char *phone;
	GuideElement *next;
};

struct Guide
{
	GuideElement *head;		
};

Guide *createGuide()
{
	Guide *guide = new Guide;
	guide->head = createGuideElement("", "", NULL);
	return guide;
}

void deleteGuide(Guide *guide)
{
	GuideElement *element = guide->head;
	GuideElement *next = element->next;
	while (next != NULL)
	{
		delete element;
		element = next;
		next = element->next;
	}
	delete element;
	delete guide;
}


GuideElement *createGuideElement(char *name, char *phone, GuideElement *next)
{
	GuideElement *element = new GuideElement;
	element->name = name;
	element->phone = phone;
	element->next = next;
	return element;
}

void addElement(char *name, char *phone, Guide *guide)
{
	GuideElement *newElement = createGuideElement(name, phone, guide->head->next);
	guide->head->next = newElement;
}

char *findName(char *phone, Guide *guide)
{
	char *notFound = "\0";
	GuideElement *current = guide->head->next;
	while (current != NULL && strcmp(phone, current->phone))
		current = current->next;
	if (current != NULL)
		return current->name;
	else
		return notFound;
}

void findPhone(char *name, Guide *guide)
{
	bool isFound = false;
	GuideElement *current = guide->head->next;
	while (current != NULL)
	{
		if (!strcmp(name, current->name))
			if (isFound)
				cout << current->phone << " ";
			else
			{
				isFound = true;
				cout << "This person has these phone numbers: " <<  current->phone << " ";
			}
		current = current->next;
	}
	if (!isFound)
		cout << "Not Found";
	cout << endl;
}

void saveBook(Guide *guide, ofstream *out)
{
	GuideElement *current = guide->head->next;
	while (current != NULL)
	{
		*out << current->name << " " << current->phone << endl;
		current = current->next;
	}
}

bool isUnique(char *phone, Guide *guide)
{
	GuideElement *element = guide->head->next;
	while (element != NULL)
	{
		if (!strcmp(phone, element->phone))
			return false;
		element = element->next;
	}
	return true;
}

void addItem(Guide *notes)
{
	const int maxSize = 1000;
	char *name = new char[maxSize];
	char *phone = new char[maxSize];

	cout << "Enter a name and phone:" << endl;
	cin >> name >> phone;
	if (isUnique(phone, notes))
	{
		addElement(name, phone, notes);
		cout << "I've added" << endl;
	}
	else
		cout << "Such number already exists!" << endl;
}

void searchPhone(Guide *notes)
{
	const int maxSize = 1000;
	char name[maxSize];
	cout << "Enter a name:" << endl;
	cin >> name;
	findPhone(name, notes);
}


void searchName(Guide *notes)
{
	const int maxSize = 1000;
	char phone[maxSize];
	cout << "Enter a phone:" << endl;
	cin >> phone;
	char *name = findName(phone, notes);
	if (name != "\0")
		cout << "This phone number belongs to this person: " << name << endl;
	else
		cout << "NOT FOUND" << endl;
}

void saveData(Guide *notes, char *fileName)
{
	ofstream out;
	out.open(fileName);
	saveBook(notes, &out);
	cout << "I've saved" << endl;
	out.close();
}


void loadData(Guide *notes, char *fileName)
{
	const int maxSize = 1000;

	cout << "Enter name of file:" << endl;
	cin >> fileName;

	ifstream in;
	in.open(fileName);
	if (in.is_open())
	{
		bool isReadable = true;
		while (isReadable)
		{
			char *nameFromFile = new char[maxSize];
			char *phoneFromFile = new char[maxSize];
			in >> nameFromFile >> phoneFromFile;
			if (nameFromFile[0] != '\0')
				addElement(nameFromFile, phoneFromFile, notes);
			else
				isReadable = false;
		}
	}
	in.close();
}
