# Microsoft Developer Studio Project File - Name="Course_Regist" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Course_Regist - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Course_Regist.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Course_Regist.mak" CFG="Course_Regist - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Course_Regist - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Course_Regist - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Course_Regist - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Course_Regist - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /w /W0 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Course_Regist - Win32 Release"
# Name "Course_Regist - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Course_Regist.cpp
# End Source File
# Begin Source File

SOURCE=.\Course_RegistDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\Course_RegistView.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaAddCS.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaAddPro.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaAddStu.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaDelCS.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaDelPro.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaDelStu.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaGrade.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaLogin.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaMCS.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaMPassWord.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaMpro.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaMScore.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaMStu.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaSSC.cpp
# End Source File
# Begin Source File

SOURCE=.\DiaTSC.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Course_Regist.h
# End Source File
# Begin Source File

SOURCE=.\Course_RegistDoc.h
# End Source File
# Begin Source File

SOURCE=.\Course_RegistView.h
# End Source File
# Begin Source File

SOURCE=.\DiaAddCS.h
# End Source File
# Begin Source File

SOURCE=.\DiaAddPro.h
# End Source File
# Begin Source File

SOURCE=.\DiaAddStu.h
# End Source File
# Begin Source File

SOURCE=.\DiaDelCS.h
# End Source File
# Begin Source File

SOURCE=.\DiaDelPro.h
# End Source File
# Begin Source File

SOURCE=.\DiaDelStu.h
# End Source File
# Begin Source File

SOURCE=.\DiaGrade.h
# End Source File
# Begin Source File

SOURCE=.\DiaLogin.h
# End Source File
# Begin Source File

SOURCE=.\DiaMCS.h
# End Source File
# Begin Source File

SOURCE=.\DiaMPassWord.h
# End Source File
# Begin Source File

SOURCE=.\DiaMpro.h
# End Source File
# Begin Source File

SOURCE=.\DiaMScore.h
# End Source File
# Begin Source File

SOURCE=.\DiaMStu.h
# End Source File
# Begin Source File

SOURCE=.\DiaSSC.h
# End Source File
# Begin Source File

SOURCE=.\DiaTSC.h
# End Source File
# Begin Source File

SOURCE=.\Global.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\sys.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Course_Regist.ico
# End Source File
# Begin Source File

SOURCE=.\Course_Regist.rc
# End Source File
# Begin Source File

SOURCE=.\res\Course_Regist.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Course_RegistDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\mm.bmp
# End Source File
# Begin Source File

SOURCE=.\res\name.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
