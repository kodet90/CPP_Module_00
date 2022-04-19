#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H
#include <iostream>
#include <iomanip>
#include "Contact.h"
#ifndef PHONEBOOK_CONTACTS_COUNT
#define PHONEBOOK_CONTACTS_COUNT 8
#endif

class PhoneBook {

public:
	PhoneBook();
	PhoneBook(PhoneBook const & phone_book);
	virtual ~PhoneBook();
	PhoneBook &	operator=(PhoneBook const & phone_book);

	Contact const & get_contact(int i) const;
	Contact & get_oldest_contact();
	int		get_count() const;
	int		get_oldest() const;
	void	increment();
	void	display() const;

private:
	Contact	_array[PHONEBOOK_CONTACTS_COUNT];
	int		_count;
	int 	_oldest;

};

#endif //PHONEBOOK_PHONEBOOK_H
