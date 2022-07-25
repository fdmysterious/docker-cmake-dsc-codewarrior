# Some variables

set(TOOLCHAIN_BIN_PATH   /buildtools/MCU/DSP56800x_EABI_Tools/command_line_tools)
set(CMAKE_FIND_ROOT_PATH /buildtools/cmake)

# Toolchain config

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_INCLUDE_FLAG_C "-I ")

find_file(CMAKE_C_COMPILER   NAMES cc   HINTS /buildtools/scripts)
find_file(CMAKE_ASM_COMPILER NAMES asm  HINTS /buildtools/scripts)
find_file(CMAKE_LINKER_PRGM  NAMES link HINTS /buildtools/scripts)

set(CMAKE_C_LINK_EXECUTABLE   "${CMAKE_LINKER_PRGM} <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_ASM_LINK_EXECUTABLE "${CMAKE_LINKER_PRGM} <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_C_COMPILE_OBJECT    "<CMAKE_C_COMPILER> <FLAGS> <DEFINES> <INCLUDES> -o <OBJECT> -c <SOURCE>")

set(CMAKE_C_FLAGS "-g -opt level=1 -opt speed -w illpragmas -w possible -w extended -w emptydecl -w structclass -w notinlined -gccdep -gccinc -MD -lang c99 -LargeAddrInSdm -v3 -requireprotos")

# Override compiler checks
set(CMAKE_C_COMPILER_WORKS   TRUE)
set(CMAKE_ASM_COMPILER_WORKS TRUE)
