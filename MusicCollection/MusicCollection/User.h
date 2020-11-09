#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
#include<vector>

class User
{
private:
	std::string username;
	std::string password;
	std::string fullName;
	std::string dateOfBirth;
	std::vector<std::string> favouriteGenres;

	void copy(const User& other);

public:
	User(const std::string& u, const std::string& p, const std::string& name, const std::string& birth,
		std::vector<std::string> fav);
	User(const User& other);

	std::string getUsername()const;
	std::string getPassword()const;
	std::string getFullName()const;
	std::string getDateOfBirth()const;
	std::vector<std::string> getFavouriteGenres()const;
};
#endif // !USER_H
