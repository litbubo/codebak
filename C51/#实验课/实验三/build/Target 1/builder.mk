EIDE_UNIFY_BUILDER := 1
CFLAGS := PRINT(".\build\Target 1\${c}.lst") OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\Software\Keil_v5\C51\INC\STC;.\..\..\..\..\Software\Keil_v5\C51\INC\Atmel;.\..\..\..\..\Software\Keil_v5\C51\INC) DEFINE(__UVISION_VERSION='526')
CXXFLAGS := PRINT(".\build\Target 1\${cpp}.lst") OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\Software\Keil_v5\C51\INC\STC;.\..\..\..\..\Software\Keil_v5\C51\INC\Atmel;.\..\..\..\..\Software\Keil_v5\C51\INC) DEFINE(__UVISION_VERSION='526')
ASMFLAGS := PRINT(.\build\Target 1\${asm}.lst) SET(SMALL) INCDIR(.\..\..\..\..\Software\Keil_v5\C51\INC\STC;.\..\..\..\..\Software\Keil_v5\C51\INC\Atmel;.\..\..\..\..\Software\Keil_v5\C51\INC)
LDFLAGS :=  PRINT(".\build\Target 1\#Template_Common.map") REMOVEUNUSED
LDLIBS := 
