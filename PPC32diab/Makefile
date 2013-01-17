# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC32diab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/Users/P/Documents/GitHub
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/UltimateAscent2013



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/h -I$(WIND_BASE)/h/WPILib -I$(WIND_BASE)/h/wrn/coreip 

IDE_LIBRARIES = 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = UltimateAscent2013/$(MODE_DIR)/UltimateAscent2013.out \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/UltimateAscent2013_partialImage.o


#Rules

# UltimateAscent2013
ifeq ($(DEBUG_MODE),1)
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
UltimateAscent2013/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
UltimateAscent2013/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/h -I$(WIND_BASE)/h/WPILib -I$(WIND_BASE)/h/wrn/coreip 
UltimateAscent2013/$(MODE_DIR)/% : IDE_LIBRARIES = 
UltimateAscent2013/$(MODE_DIR)/% : IDE_DEFINES = 
UltimateAscent2013/$(MODE_DIR)/% : PROJECT_TYPE = DKM
UltimateAscent2013/$(MODE_DIR)/% : DEFINES = 
UltimateAscent2013/$(MODE_DIR)/% : EXPAND_DBG = 0
UltimateAscent2013/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
UltimateAscent2013/$(MODE_DIR)/% : CPU = PPC32
UltimateAscent2013/$(MODE_DIR)/% : TOOL_FAMILY = diab
UltimateAscent2013/$(MODE_DIR)/% : TOOL = diab
UltimateAscent2013/$(MODE_DIR)/% : TOOL_PATH = 
UltimateAscent2013/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
UltimateAscent2013/$(MODE_DIR)/% : LIBPATH = 
UltimateAscent2013/$(MODE_DIR)/% : LIBS = 
UltimateAscent2013/$(MODE_DIR)/% : OBJ_DIR := UltimateAscent2013/$(MODE_DIR)

OBJECTS_UltimateAscent2013 = UltimateAscent2013_partialImage/$(MODE_DIR)/UltimateAscent2013_partialImage.o

UltimateAscent2013/$(MODE_DIR)/UltimateAscent2013.out : $(OBJECTS_UltimateAscent2013)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_UltimateAscent2013) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_UltimateAscent2013) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

UltimateAscent2013/$(MODE_DIR)/UltimateAscent2013_compile_file : $(FILE) ;

_clean :: UltimateAscent2013/$(MODE_DIR)/UltimateAscent2013_clean

UltimateAscent2013/$(MODE_DIR)/UltimateAscent2013_clean : 
	$(TRACE_FLAG)if [ -d "UltimateAscent2013" ]; then cd "UltimateAscent2013"; rm -rf $(MODE_DIR); fi


# UltimateAscent2013_partialImage
ifeq ($(DEBUG_MODE),1)
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
UltimateAscent2013_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/h -I$(WIND_BASE)/h/WPILib -I$(WIND_BASE)/h/wrn/coreip 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
UltimateAscent2013_partialImage/$(MODE_DIR)/% : DEFINES = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
UltimateAscent2013_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
UltimateAscent2013_partialImage/$(MODE_DIR)/% : CPU = PPC32
UltimateAscent2013_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
UltimateAscent2013_partialImage/$(MODE_DIR)/% : TOOL = diab
UltimateAscent2013_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
UltimateAscent2013_partialImage/$(MODE_DIR)/% : LIBPATH = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : LIBS = 
UltimateAscent2013_partialImage/$(MODE_DIR)/% : OBJ_DIR := UltimateAscent2013_partialImage/$(MODE_DIR)

UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/CommandBase.o : $(PRJ_ROOT_DIR)/CommandBase.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Commands/AutonomousCommand.o : $(PRJ_ROOT_DIR)/Commands/AutonomousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/OI.o : $(PRJ_ROOT_DIR)/OI.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/ClimberSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/ClimberSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/DriveTrainSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/DriveTrainSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/MA3Encoder.o : $(PRJ_ROOT_DIR)/Subsystems/MA3Encoder.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/PIDSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/PIDSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/ShooterSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/ShooterSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/VisionSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/VisionSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/UltimateAscentBot.o : $(PRJ_ROOT_DIR)/UltimateAscentBot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_UltimateAscent2013_partialImage = UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/CommandBase.o \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Commands/AutonomousCommand.o \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/OI.o \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/ClimberSubsystem.o \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/DriveTrainSubsystem.o \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/MA3Encoder.o \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/PIDSubsystem.o \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/ShooterSubsystem.o \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/VisionSubsystem.o \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/UltimateAscentBot.o

UltimateAscent2013_partialImage/$(MODE_DIR)/UltimateAscent2013_partialImage.o : $(OBJECTS_UltimateAscent2013_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5  -o "$@" $(OBJECTS_UltimateAscent2013_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

UltimateAscent2013_partialImage/$(MODE_DIR)/UltimateAscent2013_partialImage_compile_file : $(FILE) ;

_clean :: UltimateAscent2013_partialImage/$(MODE_DIR)/UltimateAscent2013_partialImage_clean

UltimateAscent2013_partialImage/$(MODE_DIR)/UltimateAscent2013_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "UltimateAscent2013_partialImage" ]; then cd "UltimateAscent2013_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/CommandBase.d UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Commands/AutonomousCommand.d UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/OI.d \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/ClimberSubsystem.d UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/DriveTrainSubsystem.d UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/MA3Encoder.d \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/PIDSubsystem.d UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/ShooterSubsystem.d UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/Subsystems/VisionSubsystem.d \
	 UltimateAscent2013_partialImage/$(MODE_DIR)/Objects/UltimateAscent2013/UltimateAscentBot.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

JOBS?=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS);\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
