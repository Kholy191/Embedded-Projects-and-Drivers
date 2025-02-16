#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_Layer/BUTTON/btn.c ECU_Layer/KEYPAD/KeyPad.c ECU_Layer/LCD/Lcd.c ECU_Layer/LED/ecu_led.c ECU_Layer/MOTOR/Motor.c ECU_Layer/RELAY/Relay.c ECU_Layer/SEG_7/Seg_7.c ECU_Layer/ecu_initialize.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/device_config.c Application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1 ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1 ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1 ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1 ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1 ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1 ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1 ${OBJECTDIR}/Application.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1.d ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1.d ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1.d ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1.d ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1.d ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1.d ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d ${OBJECTDIR}/Application.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1 ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1 ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1 ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1 ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1 ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1 ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1 ${OBJECTDIR}/Application.p1

# Source Files
SOURCEFILES=ECU_Layer/BUTTON/btn.c ECU_Layer/KEYPAD/KeyPad.c ECU_Layer/LCD/Lcd.c ECU_Layer/LED/ecu_led.c ECU_Layer/MOTOR/Motor.c ECU_Layer/RELAY/Relay.c ECU_Layer/SEG_7/Seg_7.c ECU_Layer/ecu_initialize.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/device_config.c Application.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1: ECU_Layer/BUTTON/btn.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1 ECU_Layer/BUTTON/btn.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/BUTTON/btn.d ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1: ECU_Layer/KEYPAD/KeyPad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1 ECU_Layer/KEYPAD/KeyPad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.d ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1: ECU_Layer/LCD/Lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1 ECU_Layer/LCD/Lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LCD/Lcd.d ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1: ECU_Layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ECU_Layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.d ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1: ECU_Layer/MOTOR/Motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1 ECU_Layer/MOTOR/Motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.d ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1: ECU_Layer/RELAY/Relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1 ECU_Layer/RELAY/Relay.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/RELAY/Relay.d ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1: ECU_Layer/SEG_7/Seg_7.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/SEG_7" 
	@${RM} ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1 ECU_Layer/SEG_7/Seg_7.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.d ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_initialize.p1: ECU_Layer/ecu_initialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 ECU_Layer/ecu_initialize.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_initialize.d ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1: MCAL_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 MCAL_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1: ECU_Layer/BUTTON/btn.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1 ECU_Layer/BUTTON/btn.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/BUTTON/btn.d ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/BUTTON/btn.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1: ECU_Layer/KEYPAD/KeyPad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1 ECU_Layer/KEYPAD/KeyPad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.d ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/KEYPAD/KeyPad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1: ECU_Layer/LCD/Lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1 ECU_Layer/LCD/Lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LCD/Lcd.d ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LCD/Lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1: ECU_Layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ECU_Layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.d ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1: ECU_Layer/MOTOR/Motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1 ECU_Layer/MOTOR/Motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.d ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/MOTOR/Motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1: ECU_Layer/RELAY/Relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1 ECU_Layer/RELAY/Relay.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/RELAY/Relay.d ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/RELAY/Relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1: ECU_Layer/SEG_7/Seg_7.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/SEG_7" 
	@${RM} ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1 ECU_Layer/SEG_7/Seg_7.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.d ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/SEG_7/Seg_7.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_initialize.p1: ECU_Layer/ecu_initialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 ECU_Layer/ecu_initialize.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_initialize.d ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1: MCAL_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 MCAL_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Simple_Calculator.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
