#ifndef _INCL_DUKEUNIX_H_
#define _INCL_DUKEUNIX_H_ 1

#define cdecl
#define __far
#define __interrupt

#ifdef __GNUC__
typedef long long __int64;
#endif

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
#include <assert.h>

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

#define FP_OFF(x) ((long) (x))

#ifndef strcmpi
#define strcmpi(x, y) strcasecmp(x, y)
#endif

#ifdef DC
#undef stderr
#undef stdout
#undef getchar
/* kos compat */
#define stderr ((FILE*)2)
#define stdout ((FILE*)2)
#define Z_AvailHeap() ((10 * 1024) * 1024)
#else
// 64 megs should be enough for anybody.  :)  --ryan.
#define Z_AvailHeap() ((64 * 1024) * 1024)
#endif

#define printchrasm(x,y,ch) printf("%c", (char) (ch & 0xFF))

#ifdef __GNUC__
#define GCC_PACK1_EXT __attribute__((packed,aligned(1)))
#endif

#endif
