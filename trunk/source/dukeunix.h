#ifndef _INCL_DUKEUNIX_H_
#define _INCL_DUKEUNIX_H_ 1

#define cdecl
#define __far
#define __interrupt
typedef long long __int64;

//#define STUBBED(x)
#define STUBBED(x) fprintf(stderr,"STUB: %s (%s, %s:%d)\n",x,__FUNCTION__,__FILE__,__LINE__)

#define PATH_SEP_CHAR '/'
#define PATH_SEP_STR  "/"
#define ROOTDIR       "/"
#define CURDIR        "./"

#ifndef O_BINARY
#define O_BINARY 0
#endif

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
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

struct dosdate_t
{
    unsigned char day;
    unsigned char month;
    unsigned int year;
    unsigned char dayofweek;
};

void _dos_getdate(struct dosdate_t *date);

#ifndef min
#define min(x, y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x, y) ((x) > (y) ? (x) : (y))
#endif

#endif
