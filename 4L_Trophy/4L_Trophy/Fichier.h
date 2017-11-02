#pragma once
#ifndef DEFINE_FICHIER

#define DEFINE_FICHIER

#include "file.h"
#include "Config.h"
#include <dirent.h>
#include <unistd.h>

#include <list>
#include <vector>
#include <string>

class Fichier
{
public:
	Fichier(Config *cfg);
	~Fichier();
	std::vector<std::string> getFileName() const;



protected:
	int listPotentialFile(const char* path);
	Config *p_cfg;
	std::list<FILE_DATA> list_fd;
};

#endif // !DEFINE_FICHIER