#pragma once
#include <dirent.h>
#include <string>


class Fichier
{
public:
	Fichier();
	~Fichier();

private:
	std::string base_dir;
};

