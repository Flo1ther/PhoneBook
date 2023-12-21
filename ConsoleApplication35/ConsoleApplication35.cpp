#include <iostream>
#include <fstream>
using namespace std;
const int maxContacts = 100;
class Contact
{
private:
	char* pib;
	char* homePhone;
	char* workPhone;
	char* description;


public:
	Contact(const char* pib_, const char* homePhone_, const char* workPhone_, const char* description_) : pib{ new char[strlen(pib_) + 1] }, homePhone{ new char[strlen(homePhone_) + 1] }, workPhone{ new char[strlen(workPhone_) + 1] }, description{ new char[strlen(description_) + 1] }
	{
		for (int i = 0; i < strlen(pib_)+1; i++)
		{
			this->pib[i] = pib_[i];
		}
		for (int i = 0; i < strlen(homePhone_) + 1; i++)
		{
			this->homePhone[i] = homePhone_[i];
		}
		for (int i = 0; i < strlen(workPhone_) + 1; i++)
		{
			this->workPhone[i] = workPhone_[i];
		}
		for (int i = 0; i < strlen(description_) + 1; i++)
		{
			this->description[i] = description_[i];
		}
	}
	Contact(const char* pib_, const char* homePhone_, const char* workPhone_) : Contact(pib_, homePhone_, workPhone_, "")
	{

	}
	Contact(const char* pib_, const char* homePhone_): Contact(pib_, homePhone_, "")
	{

	}
	Contact(const char* pib_) : Contact(pib_, "")
	{

	}
	Contact(): Contact("")
	{

	}
	~Contact() 
	{
		delete[]pib;
		delete[]homePhone;
		delete[]workPhone;
		delete[]description;
	}
	char* getPib()
	{
		return pib;
	}
	char* getHomePhone()
	{
		return homePhone;
	}
	char* getWorkPhone()
	{
		return workPhone;
	}
	char* getDescription()
	{
		return description;
	}
	void setPib(char* pib_)
	{
		for (int i = 0; i < strlen(pib_)+1; i++)
		{
			this->pib[i] = pib_[i];
		}
		
	}
	void setHomePhone(char* homePhone_)
	{
		for (int i = 0; i < strlen(homePhone_)+1; i++)
		{
			this->homePhone[i] = homePhone_[i];
		}
	}
	void setWorkPhone(char* workPhone_)
	{
		for (int i = 0; i < strlen(workPhone_)+1; i++)
		{
			this->workPhone[i] = workPhone_[i];
		}
		
	}
	void setDescription(char* description_)
	{
		for (int i = 0; i < strlen(description_)+1; i++)
		{
			this->description[i] = description_[i];
		}
	}
	void DisplayContact()
	{
		cout << "PIB: " << pib << endl;
		cout << "HomePhone: " << homePhone << endl;
		cout << "WorkPhone: " << workPhone << endl;
		cout << "Additional info: " << description << endl;
	}
};
class PhoneBook {

private: 
	Contact contacts[maxContacts];
	int numContacts;
public:
	PhoneBook() : numContacts{ 0 } {

	}

	void addContact(const Contact& contact)
	{
		if (numContacts<maxContacts)
		{
			cout << "Enter new Full name: \n";
			char pib[100];
			cin >> pib;
			contacts[numContacts].setPib(pib);
			cout << "Enter new homePhone: \n";
			char homePhone[15];
			cin >> homePhone;
			contacts[numContacts].setHomePhone(homePhone);
			cout << "Enter new workPhone: \n";
			char workPhone[15];
			cin >> workPhone;
			contacts[numContacts].setWorkPhone(workPhone);
			cout << "Enter new additional info: \n";
			char description[100];
			cin >> description;
			contacts[numContacts].setDescription(description);
		cout<<"Contact added."<<endl;
		numContacts++;
		}
		else
		{
			cout << "PhoneBook is fulled\n";
		}
	}
	void deleteContact(char* contact)
	{
		int removedCount = 0;
		for (int i = 0; i < numContacts; ++i)
		{
			if (strcmp(contacts[i].getPib(), contact) == 0)
			{
				for (int j = i; j < numContacts - 1; ++j)
				{
					contacts[j] = contacts[j + 1];
				}
				--numContacts;
				++removedCount;
				--i;
				cout << "Contact deleted." << endl;
				break;  
			}
		}

		if (removedCount == 0)
		{
			cout << "Contact n found." << endl;
		}
	}




	void searchContact(const char* pib)
	{
		for (int i = 0; i < numContacts; i++)
		{
			if (strcmp(contacts[i].getPib(),pib)== 0)
			{
				contacts[i].DisplayContact();
				return;
			}
		}
		cout << "Contact not found." << endl;
	}

	void DisplayAllContacts()
	{
		for (int i = 0; i < numContacts; i++)
		{
			contacts[i].DisplayContact();
		}
	}

	void saveToFile(const char* filename) const
	{
		Contact contacts;
		ofstream fout(filename);
		if (fout.is_open())
		{
			for (int i = 0; i < numContacts; i++)
			{
				fout <<contacts.getPib() << " "
					<< contacts.getHomePhone() << " "
					<< contacts.getWorkPhone() << " "
					<< contacts.getDescription() << endl;
			}
			cout << "PhoneBook saved to file." << endl;
		}
		else
		{
			cout << "Unable to open file for saving." << endl;
		}
		fout.close();
	}

	void loadFromFile(const char* filename)
	{
		numContacts = 0; // cleaning before download
		ifstream fin(filename);
		if (fin.is_open())
		{
			char pib[100];
			char homePhone[15];
			char workPhone[15];
			char description[100];

			while (fin >> pib >> homePhone >> workPhone >> description)
			{
				Contact contact(pib, homePhone, workPhone, description);
				addContact(contact);
			}

			fin.close();
			cout << "Phone book loaded from file." << endl;
		}
		else
		{
			cout << "Unable to open file for loading." << endl;
		}
	}
};
int main()
{
	Contact contacts;
	PhoneBook phoneBook;
	while (true)
	{
		cout << "______________________________" << endl;
		cout << "Welcome to PhoneBook Menu!" << endl;
		cout << "To add Contact press 1." << endl;
		cout << "To delete Contact press 2." << endl;
		cout << "To search Contact by Full name press 3." << endl;
		cout << "To display all Contacts by Full name press 4." << endl;
		cout << "To exit from menu press 5." << endl;
		cout << "_______________________________" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
				phoneBook.addContact(contacts);

			break;
		case 2:
			char contact[100];
			cout << "Enter Full name of contact to delete. " << endl;
			cin >> contact;
			phoneBook.deleteContact(contact);
			break;
		case 3:
		{
			cout << "Enter Full name of contact to search\n";
			cin >> contact;
			phoneBook.searchContact(contact);
			break;
		}
		case 4:
			phoneBook.DisplayAllContacts();
			break;
		case 5:
			cout << "Exiting from PhoneBook. Be safe!" << endl;
			return 0;
		default:
			cout << "Wrong choice. Please, choose correct number" << endl;
		}
	}
}
