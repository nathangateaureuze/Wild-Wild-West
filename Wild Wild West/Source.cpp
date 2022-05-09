#include <iostream>;

#include <fstream>;
#include <map>; 
#include <string>;

int main()
{
	std::fstream paroles;
	std::fstream occurences;

	paroles.open("Paroles.txt", std::ios::in);

	std::map<std::string, int> text;


	if(paroles.is_open())
	{
		std::string ligne;
		while(std::getline(paroles,ligne))
		{
			std::string mot;
			for (int i = 0; i < ligne.size(); i++)
			{
				if (ligne[i] == 32 || ligne[i] == 34 || ligne[i] == 44)
				{
					text[mot] += 1;
					mot = "";
				}
				else
				{
					mot += ligne[i];
				}
			}
		}
		paroles.close();
	}

	occurences.open("Occurences.txt", std::ios::out);

	if (occurences.is_open())
	{
		for (std::map<std::string, int>::iterator i = text.begin(); i != text.end(); ++i)
			occurences << i->first << ": " << i->second << '\n';

		occurences.close();
	}

	return 0;
}