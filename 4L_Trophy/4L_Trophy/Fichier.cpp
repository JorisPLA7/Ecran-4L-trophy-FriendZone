#include "Fichier.h"



Fichier::Fichier(Config *cfg) :
	p_cfg(cfg)
{
	Fichier::listPotentialFile(p_cfg->base_path().c_str());
}


Fichier::~Fichier()
{
}

std::vector<std::string> Fichier::getFileName() const
{
	std::vector<std::string> rep;
	rep.resize(list_fd.size());
	for (auto fd : list_fd)
	{
		rep.push_back(std::string(fd.cFileName));
	}
	return rep;
}

int Fichier::listPotentialFile(const char* path)
{
	if (access(path, R_OK))
	{
		DIR *rep = opendir(path);
		struct dirent*  file;
		while ((file = readdir(rep)) != NULL)
		{
			char file_name[MAX_PATH];
			strcpy(file_name, path);
			strcpy(file_name + strlen(path) - 1, file->d_name);
			if (is_dir(file_name))
			{
				listPotentialFile(file_name);
			}
			else
			{
				for (auto ext : p_cfg->music_extention())
				{
					if (CheckExtention(file->d_name, ext.c_str()))
					{
						FILE_DATA fd;
						getFileData(file_name, &fd);
						list_fd.push_back(fd);
						break;
					}
				}
			}
			
		}

	}
	return -1;
}
