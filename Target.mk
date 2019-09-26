
# Program name for executable
PROGRAM = Zombi_Simulation

# Project Home Directoy
PROJECT_HOME_DIR ?= .

# Build Directoy
BUILD_DIR ?= $(PROJECT_HOME_DIR)/Build

# Source Directories
SOURCE_DIR = $(PROJECT_HOME_DIR)/Source

# --- SRC_DIRS ---
# Use SRC_DIRS to specifiy production directories
# code files.
# These files are compiled and put into a the
# ProductionCode library and links with the test runner
SRC_DIRS += \
	$(SOURCE_DIR)/GUI/ \
	$(SOURCE_DIR)/Environment/ \
	$(SOURCE_DIR)/Cell/ \
	$(SOURCE_DIR)/Obstacle/ \
	$(SOURCE_DIR)/Resource/ \
	$(SOURCE_DIR)/Trap/ \
	$(SOURCE_DIR)/EmptyCell/ \
	$(SOURCE_DIR)/Continent/ \
	$(SOURCE_DIR)/Actor/ \
	$(SOURCE_DIR)/Zombie/ \
	$(SOURCE_DIR)/Random/ \
	$(SOURCE_DIR)/Utils/ \
	$(SOURCE_DIR)/Human/ \

# Compiler 
CXX = $(shell wx-config --cxx)
INCLUDES = $(patsubst %,-I%, $(SRC_DIRS))
CXXFLAGS = -c $(INCLUDES)

# Source files
SRC = $(wildcard ./Source/*/*.cpp)

# Object files
OBJS = $(SRC:%=$(BUILD_DIR)/%.o)

# Dependencies
DEP := $(OBJS:.o=.d)

# Links all the objects
$(BUILD_DIR)/$(PROGRAM): $(OBJS)
	@echo "Building $(PROGRAM)"
	@$(CXX) $(shell wx-config --libs all) $(OBJS) -o $(BUILD_DIR)/$(PROGRAM)
	@echo "Done with $(PROGRAM)"

# c++ Source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) $(shell wx-config --cxxflags --libs all) $< -o $@
	@echo "Done Compiling"

# Cleans all the object files and program executable
clean:
	@echo "Removing $(BUILD_DIR) folder and $(PROGRAM)";
	@rm -r $(BUILD_DIR);
	@rm $(PROGRAM)

# include all Dependencies
-include $(DEP)

MKDIR_P ?= mkdir -p
