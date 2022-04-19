#include "main.h"

std::string sanitise(std::string const & str) {
	char		prev = ' ';
	std::string	new_str;
	bool 		not_empty = false;
	bool		space = false;

	for (unsigned long i = 0; i < str.length(); i++) {
		if (!std::isspace(str[i]) || !std::isspace(prev)) {
			if (!std::isspace(str[i])) {
				if (space) {
					new_str += " ";
				}
				new_str += str.substr(i, 1);
				not_empty = true;
			}
			else {
				space = true;
			}
		}
		prev = str[i];
	}
	if (not_empty) {
		return new_str;
	}
	std::string empty_str;
	return empty_str;
}

std::string	prompt(std::string const & message) {
	std::string	readline;
	while (readline.empty()) {
		std::cout << message;
		std::getline(std::cin, readline);
		readline = sanitise(readline);
	}
	return readline;
}

void	add_contact(PhoneBook & phone_book) {
	if (phone_book.get_count() == PHONEBOOK_CONTACTS_COUNT) {
		std::cout << "Memory full, contact " + std::to_string(
				phone_book.get_oldest() + 1) + " will be overwritten..." << std::endl;
	}
	Contact & contact = phone_book.get_oldest_contact();
	contact.set_first_name(prompt("First name: "));
	contact.set_last_name(prompt("Last name: "));
	contact.set_nickname(prompt("Nickname: "));
	contact.set_phone_number(prompt("Phone number: "));
	contact.set_darkest_secret(prompt("Darkest secret: "));
	phone_book.increment();
	std::cout << "Contact saved! " + std::to_string(phone_book.get_count())
	+ "/" + std::to_string(PHONEBOOK_CONTACTS_COUNT) << std::endl;
}

int safe_stoi(std::string const & str) {
	int	i = 0;
	try {
		i = stoi(str);
	}
	catch(const std::exception& e) {

	}
	return i;
}

void	search_contact(PhoneBook & phone_book) {
	phone_book.display();
	if (phone_book.get_count() <= 0) {
		std::cout << "No contacts found. Use ADD to create a contact." << std::endl;
		return;
	}
	std::string	min;
	if (phone_book.get_count() > 1) {
		min = "1-";
	}
	std::string message = "Enter " + min + std::to_string(phone_book.get_count()) + " to select: ";
	int	i = safe_stoi(prompt(message));
	while (i < 1 || i > phone_book.get_count()) {
		i = safe_stoi(prompt(message));
	}
	Contact	const & contact = phone_book.get_contact(i - 1);
	std::cout << std::setw(16) << "First name: ";
	std::cout << contact.get_first_name() << std::endl;
	std::cout << std::setw(16) << "Last name: ";
	std::cout << contact.get_last_name() << std::endl;
	std::cout << std::setw(16) << "Nickname: ";
	std::cout << contact.get_nickname() << std::endl;
	std::cout << std::setw(16) << "Phone number: ";
	std::cout << contact.get_phone_number() << std::endl;
	std::cout << std::setw(16) << "Darkest secret: ";
	std::cout << contact.get_darkest_secret() << std::endl;
}

int main() {
	PhoneBook	phone_book;
	std::cout << "Use commands ADD, SEARCH and EXIT" << std::endl;
	std::string	readline = prompt("PhoneBook> ");
	while (readline != "EXIT") {
		if (readline == "ADD") {
			add_contact(phone_book);
		}
		else if (readline == "SEARCH") {
			search_contact(phone_book);
		}
		readline = prompt("PhoneBook> ");
	}
	return 0;
}
