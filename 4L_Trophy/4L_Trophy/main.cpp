#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include <vector>

#define MAX_PATH 1024

int extractName(const char*, char*);

typedef struct
{
	char cFilePath[MAX_PATH];
	char cFileName[MAX_PATH];
	mode_t st_fileAttributes;
	time_t st_creationTime;
	time_t st_lastAccessTime;
	time_t st_lastWriteTime;
	off_t nFileSize;
}FILE_DATA, *PFILE_DATA;

int getFileData(const char* path, PFILE_DATA fd)
{
	struct stat st;
	stat(path, &st);
	if (S_ISREG(st.st_mode))
	{
		fd->st_creationTime = st.st_ctime;
		fd->st_lastAccessTime = st.st_atime;
		fd->st_lastWriteTime = st.st_mtime;
		fd->nFileSize = st.st_size;
		fd->st_fileAttributes = st.st_mode;
		strcpy(fd->cFilePath, path);
		extractName(path, fd->cFileName);
	}
	return 0;
}

bool is_dir(const char* path)
{
	struct stat st;
	stat(path, &st);
	return S_ISDIR(st.st_mode);
}

int searchstr(const char* m_str1, const char* m_str2)
{
	size_t strlen1 = strlen(m_str1);
	size_t strlen2 = strlen(m_str2);
	char* str1 = new char[strlen1];
	char* str2 = new char[strlen2];
	for (size_t i = 0; i < strlen1; i++)
	{
		if (i < strlen2)
		{
			str2[i] = (m_str2[i] >= 'A' && m_str2[i] <= 'Z') ? m_str2[i] - 'A' + 'a' : m_str2[i];
		}
		str1[i] = (m_str1[i] >= 'A' && m_str1[i] <= 'Z') ? m_str1[i] - 'A' + 'a' : m_str1[i];
	}
	if (strlen1 > strlen2)
	{
		for (size_t i = strlen1 - 1; i >= 0; i--)
		{
			if (str1[i] == str2[strlen2 - 1])
			{
				bool test = true;
				for (size_t j = 1; j<strlen2; j++)
				{
					if (str1[i - j] != str2[strlen2 - 1 - j])
					{
						test = false;
						break;
					}
				}
				if (test)
				{
					return i - strlen2 + 1;
				}
			}
		}
		return -1;
	}
	return -1;
}

bool CheckExtention(const char* str1, const char* str2)
{
	return !((searchstr(str1, str2) + strlen(str2))<strlen(str1));
}

int extractName(const char* path, char* out)
{
	size_t pathlen = strlen(path);
	size_t i = pathlen - 1;
	while (i >= 0 && path[i] != '/')
		i--;
	strcpy(out, &path[i + 1]);
	return 0;
}

int listFile(const char* path, std::vector<FILE_DATA> *list_fd)
{
	if (!access(path, R_OK))
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
				listFile(file_name, list_fd);
			}
			else
			{
				FILE_DATA fd;
				getFileData(file_name, &fd);
				list_fd->push_back(fd);
				break;
			}

		}

	}
	return -1;
}

using namespace std;
vector<FILE_DATA> fd;

int main()
{
	listFile("/home/visual/test",&fd);
	for (auto i = 0;i<fd.size();i++)
	{
		cout << "File n°" << i << " : " << fd[i].cFileName << endl;
	}
    return 0;
}


