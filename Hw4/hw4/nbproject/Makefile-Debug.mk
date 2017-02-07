#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_mainTester.o \
	${OBJECTDIR}/computer.o \
	${OBJECTDIR}/cpu.o \
	${OBJECTDIR}/cpuprog.o \
	${OBJECTDIR}/helper.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/memory.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw4

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw4: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw4 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_mainTester.o: _mainTester.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_mainTester.o _mainTester.cpp

${OBJECTDIR}/computer.o: computer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/computer.o computer.cpp

${OBJECTDIR}/cpu.o: cpu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/cpu.o cpu.cpp

${OBJECTDIR}/cpuprog.o: cpuprog.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/cpuprog.o cpuprog.cpp

${OBJECTDIR}/helper.o: helper.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/helper.o helper.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/memory.o: memory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/memory.o memory.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw4

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
