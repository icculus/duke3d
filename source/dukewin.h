#ifndef _INCL_DUKEWIN_H_
#define _INCL_DUKEWIN_H_ 1

#ifndef _MSC_VER  /* might need this. */
typedef long long __int64;
#endif

#define __far
#define __interrupt

#define PATH_SEP_CHAR '\\'
#define PATH_SEP_STR  "\\"

#include <io.h>
struct find_t
{
	long handle;
    struct _finddata_t data;
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

#ifdef FP_OFF
#undef FP_OFF
#endif
#define FP_OFF(x) ((long) (x))

// 64 megs should be enough for anybody.  :)  --ryan.
#define Z_AvailHeap() ((64 * 1024) * 1024)

#define printchrasm(x,y,ch) printf("%c", (char) (ch & 0xFF))

#endif
