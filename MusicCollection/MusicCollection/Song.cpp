#include "Song.h"

Song::Song(const std::string& n, const std::string& a, const std::string& g, const std::string& album,
	const std::string& date) : name(n), artist(a), genre(g), album(album), dateOfRelease(date)
{
	rating = 5;
	votes = 0;
}

void Song::rate(int n)
{
	votes++;
	rating = (rating + n) / votes;
}
