#ifndef SYSTEM_H
#define SYSTEM_H

#include "User.h"
#include <fstream>

class System
{
private:
	std::vector<User> users;

public:
	System();

	void login()const;
	void signin();
	void logout() const;

	void print()const;
};
#endif // !SYSTEM_H
