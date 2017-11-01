#include <cstdio>
#include <dirent.h>

int main()
{
	DIR *rep = opendir(".");
	struct dirent* fichierLu = NULL;
	while ((fichierLu = readdir(rep)) != NULL)
		printf("%ld -> %s\n", telldir(rep), fichierLu->d_name);
    return 0;
}