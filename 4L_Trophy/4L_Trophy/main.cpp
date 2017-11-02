#include <iostream>
#include "Config.h"
#include "Fichier.h"

int main()
{
	Config cfg;
	Fichier  fch(&cfg);
	int j = 0;
	for (auto i : fch.getFileName())
	{
		std::cout << "Fichier n°" << j << " : " << i << std::endl;
		j++;
	}
    return 0;
}