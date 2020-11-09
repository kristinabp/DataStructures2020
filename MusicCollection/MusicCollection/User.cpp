#include "User.h"

void User::copy(const User& other)
{
	username = other.username;
	password = other.password;
	fullName = other.fullName;
	dateOfBirth = other.dateOfBirth;
	favouriteGenres = other.favouriteGenres;
}

User::User(const std::string& u, const std::string& p, const std::string& name, const std::string& birth, std::vector<std::string> fav) :
	username(u), password(p), fullName(name), dateOfBirth(birth), favouriteGenres(fav)
{
}

User::User(const User& other)
{
	copy(other);
}

std::string User::getUsername() const
{
	return username;
}

std::string User::getPassword() const
{
	return password;
}

std::string User::getFullName() const
{
	return fullName;
}

std::string User::getDateOfBirth() const
{
	return dateOfBirth;
}

std::vector<std::string> User::getFavouriteGenres() const
{
	return favouriteGenres;
}
