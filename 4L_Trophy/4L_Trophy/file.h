#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>

#define MAX_PATH 1024

typedef struct
{
	char cFilePath[MAX_PATH];
	char cFileName[MAX_PATH];
	unsigned int dwFileAttributes;
	time_t st_creationTime;
	time_t st_lastAccessTime;
	time_t st_lastWriteTime;
	off_t nFileSize;
}FILE_DATA, *PFILE_DATA;

int getFileData(const char* path,PFILE_DATA fd)
{
	struct stat st;
	stat(path, &st);
	if (S_ISREG(st.st_mode))
	{
		fd->st_creationTime = st.st_ctime;
		fd->st_lastAccessTime = st.st_atime;
		fd->st_lastWriteTime = st.st_mtime;
		fd->nFileSize = st.st_size;
		fd->
	}

}

int searchstr(const char* m_str1, const char* m_str2)
{
	size_t strlen1 = strlen(m_str1);
	size_t strlen2 = strlen(m_str2);
	char* str1 = new char[strlen1];
	char* str2 = new char[strlen2];
	for (int i = 0; i < strlen1; i++)
	{
		if (i < strlen2)
		{
			str2[i] = (m_str2[i] >= 'A' && m_str2[i] <= 'Z') ? m_str2[i] - 'A' + 'a' : m_str2[i];
		}
		str1[i] = (m_str1[i] >= 'A' && m_str1[i] <= 'Z') ? m_str1[i] - 'A' + 'a' : m_str1[i];
	}
	if (strlen1 > strlen2)
	{
		for (int i = strlen1 - 1; i >= 0; i--)
		{
			if (str1[i] == str2[strlen2 - 1])
			{
				bool test = true;
				for (int j = 1; j<strlen2; j++)
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
}
bool CheckExtention(const char* str1, const char* str2)
{
	return !((searchstr(str1, str2) + strlen(str2))<strlen(str1));
}