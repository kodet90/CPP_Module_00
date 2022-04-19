#include "Contact.h"

Contact::Contact() {
}

Contact::Contact(std::string const & first_name, std::string const & last_name,
				 std::string const & nickname, std::string const & phone_number,
				 std::string const & darkest_secret) : _first_name(first_name),
				 _last_name(last_name), _nickname(nickname),
				 _phone_number(phone_number), _darkest_secret(darkest_secret) {
}

Contact::Contact(Contact const & contact) {
	*this = contact;
}

Contact::~Contact() {
}

Contact &	Contact::operator=(Contact const & contact) {
	if (this != &contact) {
		this->_first_name = contact._first_name;
		this->_last_name = contact._last_name;
		this->_nickname = contact._nickname;
		this->_phone_number = contact._phone_number;
		this->_darkest_secret = contact._darkest_secret;
	}
	return *this;
}

std::string const & Contact::get_first_name() const {
	return this->_first_name;
}

std::string const & Contact::get_last_name() const {
	return this->_last_name;
}

std::string const & Contact::get_nickname() const {
	return this->_nickname;
}

std::string const & Contact::get_phone_number() const {
	return this->_phone_number;
}

std::string const & Contact::get_darkest_secret() const {
	return this->_darkest_secret;
}

void	Contact::set_first_name(std::string const & first_name) {
	this->_first_name = first_name;
}

void	Contact::set_last_name(std::string const & last_name) {
	this->_last_name = last_name;
}

void	Contact::set_nickname(std::string const & nickname) {
	this->_nickname = nickname;
}

void	Contact::set_phone_number(std::string const & phone_number) {
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string const & darkest_secret) {
	this->_darkest_secret = darkest_secret;
}
