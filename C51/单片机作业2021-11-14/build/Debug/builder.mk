EIDE_UNIFY_BUILDER := 1
CFLAGS := PRINT(.\build\Debug\${c}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(c:\Software\Keil_v5\C51\INC\STC;c:\Software\Keil_v5\C51\INC\Atmel;C:\Software\Keil_v5\C51\INC;.\src) DEFINE(__UVISION_VERSION='526')
CXXFLAGS := PRINT(.\build\Debug\${cpp}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(c:\Software\Keil_v5\C51\INC\STC;c:\Software\Keil_v5\C51\INC\Atmel;C:\Software\Keil_v5\C51\INC;.\src) DEFINE(__UVISION_VERSION='526')
ASMFLAGS := PRINT(.\build\Debug\${asm}.lst) SET(SMALL) INCDIR(c:\Software\Keil_v5\C51\INC\STC;c:\Software\Keil_v5\C51\INC\Atmel;C:\Software\Keil_v5\C51\INC;.\src)
LDFLAGS :=  PRINT(.\build\Debug\Template.map) REMOVEUNUSED
LDLIBS := 
