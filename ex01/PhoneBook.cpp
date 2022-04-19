#include "PhoneBook.h"

PhoneBook::PhoneBook() {
	this->_count = 0;
	this->_oldest = 0;
}

PhoneBook::PhoneBook(PhoneBook const & phone_book) {
	*this = phone_book;
}

PhoneBook::~PhoneBook() {
}

PhoneBook &	PhoneBook::operator=(PhoneBook const & phone_book) {
	if (this != &phone_book) {
		std::copy(std::begin(phone_book._array), std::end(phone_book._array),
				  std::begin(this->_array));
	}
	this->_count = phone_book._count;
	this->_oldest = phone_book._oldest;
	return *this;
}

Contact const & PhoneBook::get_contact(int i) const {
	return this->_array[i];
}

Contact & PhoneBook::get_oldest_contact() {
	return this->_array[this->_oldest];
}

int PhoneBook::get_count() const {
	return this->_count;
}

int PhoneBook::get_oldest() const {
	return this->_oldest;
}

void	PhoneBook::increment() {
	this->_oldest++;
	if (this->_oldest >= PHONEBOOK_CONTACTS_COUNT) {
		this->_oldest = 0;
	}
	if (this->_count < PHONEBOOK_CONTACTS_COUNT){
		this->_count++;
	}
}

std::string	truncate(std::string const & str) {
	if (str.length() > 10) {
		return str.substr(0, 9).append(".");
	}
	return str;
}

void	PhoneBook::display() const {
	std::cout << "\033[1;7m|     index";
	std::cout << "|First name";
	std::cout << "| Last name";
	std::cout << "|  Nickname";
	std::cout << "|\033[0m" << std::endl;
	for (int i = 0; i < this->_count; i++) {
		std::cout << "|";
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << truncate(this->_array[i].get_first_name());
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << truncate(this->_array[i].get_last_name());
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << truncate(this->_array[i].get_nickname());
		std::cout << "|" << std::endl;
	}
}
//---------------------------------------------
