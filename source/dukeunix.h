#ifndef _INCL_DUKEUNIX_H_
#define _INCL_DUKEUNIX_H_ 1

#define cdecl
typedef long long __int64;

#include <sys/types.h>
#include <dirent.h>

struct find_t
{
    DIR *dir;
    char pattern[MAX_PATH];
    char name[MAX_PATH];
};
int _dos_findfirst(char *filename, int x, struct find_t *f);
int _dos_findnext(struct find_t *f);

#endif
