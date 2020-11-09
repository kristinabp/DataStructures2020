#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

class Song
{
private:
	std::string name;
	std::string artist;
	std::string genre;
	std::string album;
	std::string dateOfRelease;
	int votes;
	double rating;


public:
	Song(const std::string& n, const std::string& a, const std::string& g, const std::string& album,
		const std::string& date);

	void rate(int n);
};
#endif // !SONG_H

