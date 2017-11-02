#pragma once
#ifndef DEFINE_FICHIER

#define DEFINE_FICHIER

#include <dirent.h>
#include <stack>
#include <vector>
#include <string>

class Fichier
{
public:
	Fichier();
	~Fichier();



protected:
	std::string base_dir;
};

#endif // !DEFINE_FICHIER