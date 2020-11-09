#include "System.h"

System::System():users(std::vector<User>())
{
}

void System::login() const
{
	std::string username, password;
	std::cout << "Username:";
	std::cin >> username;
	std::cout << "\nPassword:";
	std::cin >> password;

}

void System::signin()
{
	std::string username, password, name, birth, genres;
	std::vector<std::string> favGenres;
	std::cout << "Username:";
	std::getline(std::cin, username);
	std::cout << "Password:";
	std::getline(std::cin, password);
	std::cout << "Full name:";
	std::getline(std::cin, name);
	std::cout << "Date of birth:";
	std::getline(std::cin, birth);
	std::cout << "Favourite genres:";
	std::getline(std::cin, genres);
	std::string current;
	int i = 0;
	while (i < genres.size())
	{
		while (i < genres.size() && genres[i] != ' ')
		{
			current.push_back(genres[i]);
			i++;
		}
		favGenres.push_back(current);
		current = "";
		i++;
	}

	users.push_back(User(username, password, name, birth, favGenres));

}

void System::print() const
{
	for (int i = 0; i < users.size(); i++)
	{
		std::cout << users[i].getUsername() << " " << users[i].getPassword() << " " << users[i].getFullName() << " "
			<< users[i].getDateOfBirth() << " ";
		for (int j = 0; j < users[i].getFavouriteGenres().size(); j++)
		{
			std::cout << users[i].getFavouriteGenres()[j] << " ";
		}
	}
}

