//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------

/* sounds.c */
extern void SoundStartup(void);
extern void SoundShutdown(void);
extern void MusicStartup(void);
extern void MusicShutdown(void);
extern int USRHOOKS_GetMem(char **ptr, unsigned long size);
extern int USRHOOKS_FreeMem(char *ptr);
extern void intomenusounds(void);
extern void playmusic(char *fn);
extern char loadsound(unsigned short num);
extern int xyzsound(short num, short i, long x, long y, long z);
extern void sound(short num);
extern int spritesound(unsigned short num, short i);
extern void stopsound(short num);
extern void stopenvsound(short num, short i);
extern void pan3dsound(void);
extern void testcallback(unsigned long num);
extern void clearsoundlocks(void);

/* sector.c */
extern short callsound(short sn, short whatsprite);
extern short check_activator_motion(short lotag);
extern char isadoorwall(short dapic);
extern char isanunderoperator(short lotag);
extern char isanearoperator(short lotag);
extern short checkcursectnums(short sect);
extern long ldist(spritetype *s1, spritetype *s2);
extern long dist(spritetype *s1, spritetype *s2);
extern short findplayer(spritetype *s, long *d);
extern short findotherplayer(short p, long *d);
extern void doanimations(void);
extern long getanimationgoal(long *animptr);
extern void animatecamsprite(void);
extern void animatewalls(void);
extern char activatewarpelevators(short s, short d);
extern void operatesectors(short sn, short ii);
extern void operaterespawns(short low);
extern void operateactivators(short low, short snum);
extern void operatemasterswitches(short low);
extern void operateforcefields(short s, short low);
extern char checkhitswitch(short snum, long w, char switchtype);
extern void activatebysector(short sect, short j);
extern void breakwall(short newpn, short spr, short dawallnum);
extern void checkhitwall(short spr, short dawallnum, long x, long y, long z, short atwith);
extern void checkplayerhurt(struct player_struct *p, short j);
extern char checkhitceiling(short sn);
extern void checkhitsprite(short i, short sn);
extern void allignwarpelevators(void);
extern void cheatkeys(short snum);
extern void checksectors(short snum);

/* rts.c */
extern void RTS_AddFile(char *filename);
extern void RTS_Init(char *filename);
extern int32 RTS_NumSounds(void);
extern int32 RTS_SoundLength(int32 lump);
extern char *RTS_GetSoundName(int32 i);
extern void RTS_ReadLump(int32 lump, void *dest);
extern void *RTS_GetSound(int32 lump);

/* premap.c */
extern void cachespritenum(short i);
extern void cachegoodsprites(void);
extern char getsound(unsigned short num);
extern void precachenecessarysounds(void);
extern void cacheit(void);
extern void docacheit(void);
extern void xyzmirror(short i, short wn);
extern void vscrn(void);
extern void pickrandomspot(short snum);
extern void resetplayerstats(short snum);
extern void resetweapons(short snum);
extern void resetinventory(short snum);
extern void resetprestat(short snum, char g);
extern void setupbackdrop(short sky);
extern void prelevel(char g);
extern void newgame(char vn, char ln, char sk);
extern void resetpspritevars(char g);
extern void clearfrags(void);
extern void resettimevars(void);
extern void genspriteremaps(void);
extern void waitforeverybody(void);
extern void dofrontscreens(void);
extern void clearfifo(void);
extern void resetmys(void);
extern void enterlevel(char g);

/* player.c */
extern void setpal(struct player_struct *p);
extern void incur_damage(struct player_struct *p);
extern void quickkill(struct player_struct *p);
extern void forceplayerangle(struct player_struct *p);
extern void tracers(long x1, long y1, long z1, long x2, long y2, long z2, long n);
extern long hits(short i);
extern long hitasprite(short i, short *hitsp);
extern long hitawall(struct player_struct *p, short *hitw);
extern short aim(spritetype *s, short aang);
extern void shoot(short i, short atwith);
extern void displayloogie(short snum);
extern char animatefist(short gs, short snum);
extern char animateknee(short gs, short snum);
extern char animateknuckles(short gs, short snum);
extern void displaymasks(short snum);
extern char animatetip(short gs, short snum);
extern char animateaccess(short gs, short snum);
extern void displayweapon(short snum);
extern void getinput(short snum);
extern char doincrements(struct player_struct *p);
extern void checkweapons(struct player_struct *p);
extern void processinput(short snum);
extern void computergetinput(long snum, input *syn);

/* menues.c */
extern void dummyfunc(void);
extern void dummymess(int i, char *c);
extern void cmenu(short cm);
extern void savetemp(char *fn, long daptr, long dasiz);
extern void getangplayers(short snum);
extern int loadplayer(signed char spot);
extern int saveplayer(signed char spot);
extern int probe(int x, int y, int i, int n);
extern int menutext(int x, int y, short s, short p, char *t);
extern int menutextc(int x, int y, short s, short p, char *t);
extern void bar(int x, int y, short *p, short dainc, char damodify, short s, short pa);
extern void dispnames(void);
extern int getfilenames(char kind[6]);
extern void sortfilenames(void);
extern void menus(void);
extern void palto(char r, char g, char b, long e);
extern void drawoverheadmap(long cposx, long cposy, long czoom, short cang);
extern void endanimsounds(long fr);
extern void logoanimsounds(long fr);
extern void intro4animsounds(long fr);
extern void first4animsounds(long fr);
extern void intro42animsounds(long fr);
extern void endanimvol41(long fr);
extern void endanimvol42(long fr);
extern void endanimvol43(long fr);
extern void playanm(char *fn, char t);

/* gamedef.c */
extern short getincangle(short a, short na);
extern char ispecial(char c);
extern char isaltok(char c);
extern void getglobalz(short i);
extern void makeitfall(short i);
extern void getlabel(void);
extern long keyword(void);
extern long transword(void);
extern void transnum(void);
extern char parsecommand(void);
extern void passone(void);
extern void copydefaultcons(void);
extern void loadefs(char *filenam, char *mptr);
extern char dodge(spritetype *s);
extern short furthestangle(short i, short angs);
extern short furthestcanseepoint(short i, spritetype *ts, long *dax, long *day);
extern void alterang(short a);
extern void move(void);
extern void parseifelse(long condition);
extern char parse(void);
extern void execute(short i, short p, long x);

/* config.c */
extern void CONFIG_GetSetupFilename(void);
extern int32 CONFIG_FunctionNameToNum(char *func);
extern char *CONFIG_FunctionNumToName(int32 func);
extern int32 CONFIG_AnalogNameToNum(char *func);
extern void CONFIG_SetDefaults(void);
extern void CONFIG_ReadKeys(void);
extern void CONFIG_SetupMouse(int32 scripthandle);
extern void CONFIG_SetupGamePad(int32 scripthandle);
extern void CONFIG_SetupJoystick(int32 scripthandle);
extern void readsavenames(void);
extern void CONFIG_ReadSetup(void);
extern void CONFIG_WriteSetup(void);

/* animlib.c */
extern void CheckAnimStarted(char *funcname);
extern uint16 findpage(uint16 framenumber);
extern void loadpage(uint16 pagenumber, uint16 *pagepointer);
extern void CPlayRunSkipDump(char *srcP, char *dstP);
extern void renderframe(uint16 framenumber, uint16 *pagepointer);
extern void drawframe(uint16 framenumber);
extern void ANIM_LoadAnim(char *buffer);
extern void ANIM_FreeAnim(void);
extern int32 ANIM_NumFrames(void);
extern byte *ANIM_DrawFrame(int32 framenumber);
extern byte *ANIM_GetPalette(void);

/* game.c */
extern void timerhandler(void);
extern int gametext(int x, int y, char *t, char s, short dabits);
extern int gametextpal(int x, int y, char *t, char s, char p);
extern int gametextpart(int x, int y, char *t, char s, short p);
extern int minitext(int x, int y, char *str, char p, char sb);
extern int minitextshade(int x, int y, char *t, char s, char p, char sb);
extern void gamenumber(long x, long y, long n, char s);
extern void allowtimetocorrecterrorswhenquitting(void);
extern void getpackets(void);
extern void faketimerhandler(void);
extern void caches(void);
extern void checksync(void);
extern void check_fta_sounds(short i);
extern short inventory(spritetype *s);
extern short badguy(spritetype *s);
extern short badguypic(short pn);
extern void myos(long x, long y, short tilenum, signed char shade, char orientation);
extern void myospal(long x, long y, short tilenum, signed char shade, char orientation, char p);
extern void invennum(long x, long y, char num1, char ha, char sbits);
extern void weaponnum(short ind, long x, long y, long num1, long num2, char ha);
extern void weaponnum999(char ind, long x, long y, long num1, long num2, char ha);
extern void weapon_amounts(struct player_struct *p, long x, long y, long u);
extern void digitalnumber(long x, long y, long n, char s, char cs);
extern void displayinventory(struct player_struct *p);
extern void displayfragbar(void);
extern void coolgaugetext(short snum);
extern void tics(void);
extern void coords(short snum);
extern void operatefta(void);
extern void FTA(short q, struct player_struct *p);
extern void showtwoscreens(void);
extern void binscreen(void);
extern void gameexit(char *msg);
extern short strget(short x, short y, char *t, short dalen, short c);
extern void typemode(void);
extern void moveclouds(void);
extern void displayrest(long smoothratio);
extern void updatesectorz(long x, long y, long z, short *sectnum);
extern void view(struct player_struct *pp, long *vx, long *vy, long *vz, short *vsectnum, short ang, short horiz);
extern void drawbackground(void);
extern void displayrooms(short snum, long smoothratio);
extern short LocateTheLocator(short n, short sn);
extern short EGS(short whatsect, long s_x, long s_y, long s_z, short s_pn, signed char s_s, signed char s_xr, signed char s_yr, short s_a, short s_ve, long s_zv, short s_ow, signed char s_ss);
extern char wallswitchcheck(short i);
extern short spawn(short j, short pn);
extern void animatesprites(long x, long y, short a, long smoothratio);
extern void cheats(void);
extern void nonsharedkeys(void);
extern void comlinehelp(char **argv);
extern void checkcommandline(int argc, char **argv);
extern void printstr(short x, short y, char string[81], char attribute);
extern void Logo(void);
extern void loadtmb(void);
extern void ShutDown(void);
extern void compilecons(void);
extern void Startup(void);
extern void sendscore(char *s);
extern void getnames(void);
extern void writestring(long a1, long a2, long a3, short a4, long vx, long vy, long vz);
extern char testcd(char *fn);
extern void copyprotect(void);
extern char opendemoread(char which_demo);
extern void opendemowrite(void);
extern void record(void);
extern void closedemowrite(void);
extern long playback(void);
extern char moveloop(void);
extern void fakedomovethingscorrect(void);
extern void fakedomovethings(void);
extern char domovethings(void);
extern void doorders(void);
extern void dobonus(char bonusonly);
extern void cameratext(short i);
extern void vglass(long x, long y, short a, short wn, short n);
extern void lotsofglass(short i, short wallnum, short n);
extern void spriteglass(short i, short n);
extern void ceilingglass(short i, short sectnum, short n);
extern void lotsofcolourglass(short i, short wallnum, short n);
extern void SetupGameButtons(void);
extern void CenterCenter(void);
extern void UpperLeft(void);
extern void LowerRight(void);
extern void CenterThrottle(void);
extern void CenterRudder(void);

/*
 * (This was originally "GetTime", but that conflicts with a function in
 *  in MacOSX's Carbon. --ryan.)
 */
extern long DUKE3D_GetTime(void);


/* Global.c */
extern void FixFilePath(char *filename);
extern int _dos_findfirst(char *filename, int x, struct find_t *f);
extern int _dos_findnext(struct find_t *f);
extern void _dos_getdate(struct dosdate_t *date);
extern int FindDistance2D(int ix, int iy);
extern int FindDistance3D(int ix, int iy, int iz);
extern void Error(char *error, ...);
extern int32 SafeOpenAppend(const char *_filename, int32 filetype);
extern boolean SafeFileExists(const char *_filename);
extern int32 SafeOpenWrite(const char *_filename, int32 filetype);
extern int32 SafeOpenRead(const char *_filename, int32 filetype);
extern void SafeRead(int32 handle, void *buffer, int32 count);
extern void SafeWrite(int32 handle, void *buffer, int32 count);
extern void SafeWriteString(int handle, char *buffer);
extern void *SafeMalloc(long size);
extern void SafeRealloc(void **x, int32 size);
extern void *SafeLevelMalloc(long size);
extern void SafeFree(void *ptr);
extern short MotoShort(short l);
extern short IntelShort(short l);
extern long MotoLong(long l);
extern long IntelLong(long l);
extern void SwapIntelLong(long *l);
extern void SwapIntelShort(short *s);
extern void SwapIntelLongArray(long *l, int num);
extern void SwapIntelShortArray(short *s, int num);
extern int setup_homedir(void);
extern char CheckParm(char *check);
extern void RegisterShutdownFunction(void (*shutdown)(void));
extern void Shutdown(void);
extern char *ltoa(long value, char *string, int radix);
extern char *ultoa(unsigned long value, char *string, int radix);
extern int dukescreencapture(char *str, char inverseit);

/* actors.c */
extern void updateinterpolations(void);
extern void setinterpolation(long *posptr);
extern void stopinterpolation(long *posptr);
extern void dointerpolations(long smoothratio);
extern void restoreinterpolations(void);
extern long ceilingspace(short sectnum);
extern long floorspace(short sectnum);
extern void addammo(short weapon, struct player_struct *p, short amount);
extern void addweapon(struct player_struct *p, short weapon);
extern void checkavailinven(struct player_struct *p);
extern void checkavailweapon(struct player_struct *p);
extern long ifsquished(short i, short p);
extern void hitradius(short i, long r, long hp1, long hp2, long hp3, long hp4);
extern short movesprite(short spritenum, long xchange, long ychange, long zchange, unsigned long cliptype);
extern short ssp(short i, unsigned long cliptype);
extern void insertspriteq(short i);
extern void lotsofmoney(spritetype *s, short n);
extern void lotsofmail(spritetype *s, short n);
extern void lotsofpaper(spritetype *s, short n);
extern void guts(spritetype *s, short gtype, short n, short p);
extern void gutsdir(spritetype *s, short gtype, short n, short p);
extern void setsectinterpolate(short i);
extern void clearsectinterpolate(short i);
extern void ms(short i);
extern void movefta(void);
extern short ifhitsectors(short sectnum);
extern short ifhitbyweapon(short sn);
extern void movecyclers(void);
extern void movedummyplayers(void);
extern void moveplayers(void);
extern void movefx(void);
extern void movefallers(void);
extern void movestandables(void);
extern void bounce(short i);
extern void moveweapons(void);
extern void movetransports(void);
extern void moveactors(void);
extern void moveexplosions(void);
extern void moveeffectors(void);
