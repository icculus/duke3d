# Microsoft Developer Studio Project File - Name="Duke3d" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Duke3d - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Duke3d.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Duke3d.mak" CFG="Duke3d - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Duke3d - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Duke3d - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "Perforce Project"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Duke3d - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseVC6"
# PROP Intermediate_Dir "ReleaseVC6"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /GX /Ot /Ow /Oi /Op /Oy /Ob1 /I "buildengine\SDL-1.2.5\include" /I "buildengine\SDL_mixer-1.2.5\include" /I ".\buildengine" /D "_CONSOLE" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "USE_I386_ASM" /D "PLATFORM_WIN32" /D "UDP_NETWORKING" /YX /J /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0x409 /i "wsock32.lib" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib sdl.lib sdl_mixer.lib /nologo /subsystem:console /machine:I386 /out:"./ReleaseVC6/Duke3d.exe" /libpath:"buildengine\SDL-1.2.5\lib" /libpath:"buildengine\SDL_mixer-1.2.5\lib"
# SUBTRACT LINK32 /debug

!ELSEIF  "$(CFG)" == "Duke3d - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugVC6"
# PROP Intermediate_Dir "DebugVC6"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /Gm /GX /ZI /Od /I "buildengine\SDL-1.2.5\include" /I "buildengine\SDL_mixer-1.2.5\include" /I ".\buildengine" /D "_CONSOLE" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "USE_I386_ASM" /D "PLATFORM_WIN32" /D "UDP_NETWORKING" /FR /YX /J /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib sdl.lib sdl_mixer.lib /nologo /subsystem:console /debug /machine:I386 /out:"./DebugVC6/Duke3d.exe" /pdbtype:sept /libpath:"buildengine\SDL-1.2.5\lib" /libpath:"buildengine\SDL_mixer-1.2.5\lib"

!ENDIF 

# Begin Target

# Name "Duke3d - Win32 Release"
# Name "Duke3d - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\actors.c
# End Source File
# Begin Source File

SOURCE=.\animlib.c
# End Source File
# Begin Source File

SOURCE=.\config.c
# End Source File
# Begin Source File

SOURCE=.\control.c
# End Source File
# Begin Source File

SOURCE=.\audiolib\dsl.c
# End Source File
# Begin Source File

SOURCE=.\dukemusc.c
# End Source File
# Begin Source File

SOURCE=.\audiolib\fx_man.c
# End Source File
# Begin Source File

SOURCE=.\game.c
# End Source File
# Begin Source File

SOURCE=.\gamedef.c
# End Source File
# Begin Source File

SOURCE=.\global.c
# End Source File
# Begin Source File

SOURCE=.\keyboard.c
# End Source File
# Begin Source File

SOURCE=.\audiolib\ll_man.c
# End Source File
# Begin Source File

SOURCE=.\menues.c
# End Source File
# Begin Source File

SOURCE=.\audiolib\multivoc.c
# End Source File
# Begin Source File

SOURCE=.\audiolib\mv_mix.c
# End Source File
# Begin Source File

SOURCE=.\audiolib\mvreverb.c
# End Source File
# Begin Source File

SOURCE=.\audiolib\nodpmi.c
# End Source File
# Begin Source File

SOURCE=.\audiolib\pitch.c
# End Source File
# Begin Source File

SOURCE=.\player.c
# End Source File
# Begin Source File

SOURCE=.\premap.c
# End Source File
# Begin Source File

SOURCE=.\rts.c
# End Source File
# Begin Source File

SOURCE=.\scriplib.c
# End Source File
# Begin Source File

SOURCE=.\sector.c
# End Source File
# Begin Source File

SOURCE=.\sounds.c
# End Source File
# Begin Source File

SOURCE=.\audiolib\user.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\_animlib.h
# End Source File
# Begin Source File

SOURCE=.\_functio.h
# End Source File
# Begin Source File

SOURCE=.\_rts.h
# End Source File
# Begin Source File

SOURCE=.\animlib.h
# End Source File
# Begin Source File

SOURCE=.\build.h
# End Source File
# Begin Source File

SOURCE=.\config.h
# End Source File
# Begin Source File

SOURCE=.\control.h
# End Source File
# Begin Source File

SOURCE=.\develop.h
# End Source File
# Begin Source File

SOURCE=.\audiolib\dsl.h
# End Source File
# Begin Source File

SOURCE=.\duke3d.h
# End Source File
# Begin Source File

SOURCE=.\dukeunix.h
# End Source File
# Begin Source File

SOURCE=.\dukewin.h
# End Source File
# Begin Source File

SOURCE=.\file_lib.h
# End Source File
# Begin Source File

SOURCE=.\funct.h
# End Source File
# Begin Source File

SOURCE=.\function.h
# End Source File
# Begin Source File

SOURCE=.\audiolib\fx_man.h
# End Source File
# Begin Source File

SOURCE=.\fx_man.h
# End Source File
# Begin Source File

SOURCE=.\gamedefs.h
# End Source File
# Begin Source File

SOURCE=.\keyboard.h
# End Source File
# Begin Source File

SOURCE=.\audiolib\ll_man.h
# End Source File
# Begin Source File

SOURCE=.\mouse.h
# End Source File
# Begin Source File

SOURCE=.\audiolib\multivoc.h
# End Source File
# Begin Source File

SOURCE=.\music.h
# End Source File
# Begin Source File

SOURCE=.\names.h
# End Source File
# Begin Source File

SOURCE=.\audiolib\pitch.h
# End Source File
# Begin Source File

SOURCE=.\pragmas.h
# End Source File
# Begin Source File

SOURCE=.\rts.h
# End Source File
# Begin Source File

SOURCE=.\scriplib.h
# End Source File
# Begin Source File

SOURCE=.\sndcards.h
# End Source File
# Begin Source File

SOURCE=.\soundefs.h
# End Source File
# Begin Source File

SOURCE=.\sounds.h
# End Source File
# Begin Source File

SOURCE=.\task_man.h
# End Source File
# Begin Source File

SOURCE=.\types.h
# End Source File
# Begin Source File

SOURCE=.\audiolib\user.h
# End Source File
# Begin Source File

SOURCE=.\util_lib.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
