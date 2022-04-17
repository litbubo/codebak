EIDE_UNIFY_BUILDER := 1
CFLAGS := PRINT(.\build\Debug\obj\${c}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(c:\Software\Keil_v5\C51\INC;c:\Software\Keil_v5\C51\INC\STC;C:\Software\Keil_v5\C51\INC;.\src) DEFINE(__UVISION_VERSION='526')
CXXFLAGS := PRINT(.\build\Debug\obj\${cpp}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(c:\Software\Keil_v5\C51\INC;c:\Software\Keil_v5\C51\INC\STC;C:\Software\Keil_v5\C51\INC;.\src) DEFINE(__UVISION_VERSION='526')
ASMFLAGS := PRINT(.\build\Debug\obj\${asm}.lst) SET(SMALL) INCDIR(c:\Software\Keil_v5\C51\INC;c:\Software\Keil_v5\C51\INC\STC;C:\Software\Keil_v5\C51\INC;.\src)
LDFLAGS :=  PRINT(.\build\Debug\setialport_2.map) REMOVEUNUSED
LDLIBS := 
