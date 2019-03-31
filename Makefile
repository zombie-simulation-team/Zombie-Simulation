# Set this to @ to keep the makefile quiet
SILENCE ?= @

PROJECT_HOME_DIR ?= .

PROJECT_NAME ?= Zombie-Simulation
COMPONENT_NAME ?= $(PROJECT_NAME)

TESTING_DIR ?= $(PROJECT_HOME_DIR)/Testing
TESTS_DIR = $(TESTING_DIR)/Tests

CPPUTEST_OBJS_DIR = $(TESTING_DIR)/Build
CPPUTEST_LIB_DIR = $(CPPUTEST_OBJS_DIR)/Lib/

TEST_TARGET = $(CPPUTEST_OBJS_DIR)/$(COMPONENT_NAME)_tests

CPPUTEST_HOME = Testing/CppUTest
CPP_PLATFORM ?= Gcc

CPPUTEST_USE_EXTENSIONS = Y
CPPUTEST_WARNINGFLAGS += -Wall
CPPUTEST_WARNINGFLAGS += -Wswitch-default
CPPUTEST_CFLAGS += -std=c++11
CPPUTEST_CFLAGS += -std=gnu89
CPPUTEST_CFLAGS += -Wextra
CPPUTEST_CFLAGS += -Wstrict-prototypes
CPPUTEST_CFLAGS += -Werror=pointer-arith
CPPUTEST_CFLAGS += -Wcast-align
CPPUTEST_CFLAGS += -Werror=missing-prototypes
CPPUTEST_CFLAGS += -g -O0 --coverage
CPPUTEST_CPPFLAGS += -D__STDC_LIMIT_MACROS
CPPUTEST_LDFLAGS += -ftest-coverage
CPPUTEST_LDFLAGS += -fprofile-arcs

SRC_FILES += \

SRC_DIRS += \
	Source/ \
	Source/Environment/ \
	Source/Cell/ \
	Source/Obstacle/ \
	Source/Resource/ \
	Source/Trap/ \
	Source/EmptyCell/ \
	Source/Actor/ \

TEST_SRC_DIRS += \
	Testing/Tests/ \
	Testing/Tests/Environment \
	Testing/Tests/Cell \
	Testing/Tests/Obstacle \
	Testing/Tests/Resource \
	Testing/Tests/Trap \
	Testing/Tests/EmptyCell \
	Testing/Tests/Actor \

INCLUDE_DIRS += \
	$(SRC_DIRS) \
	$(TEST_SRC_DIRS) \
	$(CPPUTEST_HOME)/include \

LD_LIBRARIES += -lm -ldl

# Defer to CppUTest's build system to finish build
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

# Automatically build CppUTest for current environment
$(CPPUTEST_HOME)/lib/libCppUTest.a:
	cd $(CPPUTEST_HOME) ; ./configure
	make -C $(CPPUTEST_HOME)

# Manually blow away CppUTest libs so that new libs will be built
upgrade:
	rm -rf $(CPPUTEST_HOME)/lib

# This will clean up everything including CppUTest
distclean: clean upgrade
	make -C $(CPPUTEST_HOME) clean distclean

$(CPPUTEST_HOME)/lib/libCppUTestExt.a: $(CPPUTEST_HOME)/lib/libCppUTest.a
