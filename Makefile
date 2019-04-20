# Set this to @ to keep the makefile quiet
SILENCE ?= @

PROJECT_HOME_DIR ?= .

PROJECT_NAME ?= Zombie-Simulation
COMPONENT_NAME ?= $(PROJECT_NAME)

TESTING_DIR ?= $(PROJECT_HOME_DIR)/Testing
TESTS_DIR = $(TESTING_DIR)/Tests
TEST_TARGET = $(CPPUTEST_OBJS_DIR)/$(COMPONENT_NAME)_Tests

CPPUTEST_OBJS_DIR = $(TESTING_DIR)/Build
CPPUTEST_LIB_DIR = $(CPPUTEST_OBJS_DIR)/Lib/

CPPUTEST_HOME = Testing/CppUTest
CPP_PLATFORM ?= Gcc

ifeq ($(shell $(CC) -v 2>&1 | grep -c "clang"), 1)
CPPUTEST_WARNINGFLAGS += -Wno-unknown-warning-option
CPPUTEST_WARNINGFLAGS += -Wno-covered-switch-default
CPPUTEST_WARNINGFLAGS += -Wno-reserved-id-macro
CPPUTEST_WARNINGFLAGS += -Wno-keyword-macro
CPPUTEST_WARNINGFLAGS += -Wno-documentation
CPPUTEST_WARNINGFLAGS += -Wno-missing-noreturn
endif

# Turns on CppMock
CPPUTEST_USE_EXTENSIONS = Y

# C and C++ Compiler Flags
CPPUTEST_WARNINGFLAGS += -Wall
CPPUTEST_WARNINGFLAGS += -Werror
CPPUTEST_WARNINGFLAGS += -Wswitch-default
CPPUTEST_WARNINGFLAGS += -Wno-format-nonliteral
CPPUTEST_WARNINGFLAGS += -Wno-sign-conversion
CPPUTEST_WARNINGFLAGS += -Wno-pedantic
CPPUTEST_WARNINGFLAGS += -Wno-shadow
CPPUTEST_WARNINGFLAGS += -Wno-missing-field-initializers
CPPUTEST_WARNINGFLAGS += -Wno-unused-parameter
CPPUTEST_CFLAGS += -std=c++11
CPPUTEST_CFLAGS += -std=gnu89
CPPUTEST_CFLAGS += -Wextra
CPPUTEST_CFLAGS += -Wstrict-prototypes
CPPUTEST_CFLAGS += -Werror=pointer-arith
CPPUTEST_CFLAGS += -Wcast-align
CPPUTEST_CFLAGS += -Werror=missing-prototypes
CPPUTEST_CFLAGS += -g -O0 --coverage
CPPUTEST_CXXLAGS += -Wextra
CPPUTEST_CPPFLAGS += -D__STDC_LIMIT_MACROS
CPPUTEST_LDFLAGS += -ftest-coverage
CPPUTEST_LDFLAGS += -fprofile-arcs

# --- MOCKS_SRC_DIRS ---
# MOCKS_SRC_DIRS specifies a directories where you can put your
# mocks, stubs and fakes.  You can also just put them
# in TEST_SRC_DIRS
MOCKS_SRC_DIRS += \

# --- SRC_FILES ---
# Use SRC_FILES to specifiy individual production
# code files.
# These files are compiled and put into the
# a library and links with the test runner.
# This is so that test code can override production code at link time.
SRC_FILES += \

# --- SRC_DIRS ---
# Use SRC_DIRS to specifiy production directories
# code files.
# These files are compiled and put into a the
# ProductionCode library and links with the test runner
SRC_DIRS += \
	Source/ \
	Source/Environment/ \
	Source/Cell/ \
	Source/Obstacle/ \
	Source/Resource/ \
	Source/Trap/ \
	Source/EmptyCell/ \
	Source/Continent/ \
	Source/Actor/ \
	Source/Zombie/ \
	Source/Random/ \
	Source/Mock/ \
	Source/Utils/ \
	Source/Human/ \

# --- TEST_SRC_FILES ---
# TEST_SRC_FILES specifies individual test files to build.  Test
# files are always included in the build and they
# pull in production code from the library
TEST_SRC_FILES +=

# --- TEST_SRC_DIRS ---
# Like TEST_SRC_FILES, but biulds everyting in the directory
TEST_SRC_DIRS += \
	Testing/Tests/ \
	Testing/Tests/Environment \
	Testing/Tests/Cell \
	Testing/Tests/Obstacle \
	Testing/Tests/Resource \
	Testing/Tests/Trap \
	Testing/Tests/EmptyCell \
	Testing/Tests/Continent \
	Testing/Tests/Actor \
	Testing/Tests/Zombie \
	Testing/Tests/Human \

INCLUDE_DIRS += \
	$(SRC_DIRS) \
	$(TEST_SRC_DIRS) \
	$(CPPUTEST_HOME)/include \

LD_LIBRARIES += -lm -ldl

# Look at $(CPPUTEST_HOME)/build/MakefileWorker.mk for more controls
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

# Automatically build CppUTest for current environment
$(CPPUTEST_HOME)/lib/libCppUTest.a:
	cd $(CPPUTEST_HOME) ; ./configure
	make -C $(CPPUTEST_HOME)

# Deletes CppUtest Automatically
upgrade:
	rm -rf $(CPPUTEST_HOME)/lib

# Cleans everything
distclean: clean upgrade
	make -C $(CPPUTEST_HOME) clean distclean

$(CPPUTEST_HOME)/lib/libCppUTestExt.a: $(CPPUTEST_HOME)/lib/libCppUTest.a
