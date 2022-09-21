cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE /buildtools/cmake/toolchain.cmake CACHE FILEPATH "")
set(SDK_PATH             /SDK)
set(TARGET_CPU           MC56F83789)

set(CPU_SDK_PATH ${SDK_PATH}/devices/${TARGET_CPU})

set(SUPPORT_ROOT_PATH "/buildtools/MCU/M56800E_Support")
set(SUPPORT_MSL_PATH "${SUPPORT_ROOT_PATH}/msl/MSL_C")
set(SUPPORT_MSL_COMMON_PATH "${SUPPORT_MSL_PATH}/MSL_Common")
set(SUPPORT_MSL_DSP_PATH "${SUPPORT_MSL_PATH}/DSP_56800E")
set(SUPPORT_MSL_RUNTIME_PATH "${SUPPORT_ROOT_PATH}/runtime_56800E")

project("Test 56800" C ASM)

include_directories(
	"${CPU_SDK_PATH}/"
	"${CPU_SDK_PATH}/drivers"
	"${CPU_SDK_PATH}/codewarrior"

	"${SUPPORT_MSL_COMMON_PATH}/Include"
	"${SUPPORT_MSL_DSP_PATH}/prefix"
	"${SUPPORT_MSL_DSP_PATH}/inc"
	"${SUPPORT_MSL_RUNTIME_PATH}/include"

	"${CPU_SDK_PATH}/utilities/debug_console_lite"
	"${SDK_PATH}/components/uart"
)

#add_definitions(
#    -D__SDM__
#    -D__LPM__
#    -D__DSC__
#    -D__CW__
#    -DCPU_MC56F83789VLL
#    -DMCUXPRESSO_SDK
#)

# TODO # Find how to override Flash_Config.h from SDK

set(C_SOURCES
	${CPU_SDK_PATH}/drivers/fsl_common.c
	${CPU_SDK_PATH}/drivers/fsl_clock.c
	${CPU_SDK_PATH}/drivers/fsl_gpio.c
	${CPU_SDK_PATH}/drivers/fsl_qsci.c
	${CPU_SDK_PATH}/drivers/fsl_common_dsc.c

	${CPU_SDK_PATH}/codewarrior/MC56F83789_Vectors.c
	${CPU_SDK_PATH}/codewarrior/Flash_config.c

	${SDK_PATH}/components/uart/fsl_adapter_qsci.c

	${CPU_SDK_PATH}/utilities/debug_console_lite/fsl_assert.c
	${CPU_SDK_PATH}/utilities/debug_console_lite/fsl_debug_console.c

	board/clock_config.c
	board/peripherals.c
	board/pin_mux.c
	board/board.c

	src/main.c
)

set_property(SOURCE ${C_SOURCES} PROPERTY
	COMPILE_DEFINITIONS __SDM__;__LPM__;__DSC__;__CW__;CPU_MC56F83789VLL;MCUXPRESSO_SDK
)

#set_property(SOURCE ${C_SOURCES} PROPERTY
#	COMPILE_FLAGS "-v3 -globalsInLowerMemory -requireprotos -lang c99 -Large"

add_executable(
	test

	${CPU_SDK_PATH}/codewarrior/MC56F83xxx_init.asm
	${C_SOURCES}
)

target_link_libraries(
	test
	"${SUPPORT_MSL_RUNTIME_PATH}/lib/Runtime 56800E.Lib"
	"${SUPPORT_MSL_DSP_PATH}/lib/MSL C 56800E.lib"
)

#target_compile_definitions(
#	test
#	PUBLIC
#	__SDM__
#	__LPM__
#	__DSC__
#	__CW__
#	CPU_MC56F83789VLL
#	MCUXPRESSO_SDK
#)


set(CMAKE_EXE_LINKER_FLAGS "\"${CMAKE_CURRENT_SOURCE_DIR}/MC56F83789_Internal_PFlash_SDM.cmd\"")
