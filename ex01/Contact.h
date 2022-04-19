#ifndef PHONEBOOK_CONTACT_H
#define PHONEBOOK_CONTACT_H
#include <iostream>

class Contact {

public:
	Contact();
	Contact(std::string const & first_name, std::string const & last_name,
			std::string const & nickname, std::string const & phone_number,
			std::string const & darkest_secret);
	Contact(Contact const & contact);
	virtual ~Contact();
	Contact &	operator=(Contact const & contact);

	std::string const & get_first_name() const;
	std::string const & get_last_name() const;
	std::string const & get_nickname() const;
	std::string const & get_phone_number() const;
	std::string const & get_darkest_secret() const;
	void	set_first_name(std::string const & first_name);
	void	set_last_name(std::string const & last_name);
	void	set_nickname(std::string const & nickname);
	void	set_phone_number(std::string const & phone_number);
	void	set_darkest_secret(std::string const & darkest_secret);

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

};

#endif //PHONEBOOK_CONTACT_H
