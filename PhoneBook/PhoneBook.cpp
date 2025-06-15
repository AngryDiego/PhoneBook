// ��� ����� �������� ����� "��������� �����". 
/*
- ��� ����� - Contact �� PhoneBook
- Contact: ���� ����� (�������, ��`�, ����� ��������, �����), ������ � ������ ����������, �������, �����??
- PhoneBook: ������ ��������, ��������� ������ ��������, ��������� ������ �� ������� ��������/��� �� ��������, �������� �� ��������
- ������� ���������� �����: ���� �����䳿
- �������� ����� ������


*/

#include <iostream>
#include <vector>

class Contact {
	std::string lastName;
	std::string firstName;
	std::string phoneNumber;
	std::string email;
	

	// --------------------------------- SETTERS
	void setLN (std::string lasNam) {
		if (lasNam.size() < 10) {
			lastName = lasNam;
		}
		else {
			std::cout << "Ti balbes" << std::endl ;
		}
	}

	void setFN (std::string firNam) {
		if (firNam.size() < 10) {
			firstName = firNam;
		}
		else {
			std::cout << "Ti balbes" << std::endl;
		}
	}

	void setPN(std::string phnNum) {
		if (phnNum.size() > 16 && phnNum.size() < 0 && phnNum[0] == '+') {
			phoneNumber = phnNum;
		}
		else {
			std::cout << "Ti balbes" << std::endl;
		}
		
	}

	void setEmail(std::string eml) {
		email = eml;
	}
	
public:
	// ---------------------------------- GETTERS
	std::string getLN() { return lastName; }

	std::string getFN() { return firstName; }

	std::string getPN() { return phoneNumber; }

	std::string getEM() { return email; }

	// ----------------------------------- METHODS
	void PrintInfo() {
		std::cout << lastName << '\t' << firstName << '\t' << phoneNumber << '\t' << email << std::endl;
	}

	Contact(std::string Lname, std::string Fname, std::string PN, std::string EM) {
		setLN(Lname);
		setFN(Fname);
		setPN(PN);
		setEmail(EM);
	}
};

class PhoneBooK {
	std::vector <Contact> contacts{};

	void AddNumber(Contact number) {
		contacts.push_back(number);
		std::cout << number.getPN() << " was succesfully added to phonebook." << std::endl ;
	}

	void FindNumber(std::string value) {
		for (auto& contact : contacts) {
			if (contact.getFN() == value || contact.getPN() == value) {
				std::cout << "Contact was found." << std::endl;
				contact.PrintInfo();
				return;
			}
		}
		std::cout << "This contact was not found" << std::endl;
	}

	void ShowAll() {
		if (contacts.empty()) {
			std::cout << "Ti balbes (u tebe poosta knishka)" << std::endl;
		}
		else {
			for (auto& contact : contacts) {
				contact.PrintInfo();
				std::cout << std::endl;
			}
		}
	}
};

void menu () {
	std::cout << "1. Create number" << std::endl;
	std::cout << "2. Add number" << std::endl;
	std::cout << "3. Find number" << std::endl;
	std::cout << "4. Show all numbers" << std::endl;
	std::cout << "0. exit" << std::endl;
}


int main() {
	PhoneBooK book1;
	int choice;

	do {
		if (choice == 1) {
			std::string firstName, lastName, phonenumber, email;
			
			std::cout << "Enter first name :" << std::endl;

			std::cin >> firstName;
			
			std::cout << "Enter last name :" << std::endl;

			std::cin >> lastName;

			std::cout << "Enter phone-number name :" << std::endl;

			std::cin >> phonenumber;

			std::cout << "Enter first email :" << std::endl;

			std::cin >> email;

			Contact(lastName, firstName, phonenumber, email);
		}


	} while (choice != 0);
}
