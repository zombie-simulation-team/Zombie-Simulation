
# Target name for executable
TARGET = Zombie_Simulation

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
CXX = g++
INCLUDES = $(patsubst %,-I%, $(SRC_DIRS))
CXXFLAGS = -c $(INCLUDES)

# Source files
SRC = $(wildcard ./Source/*/*.cpp)

# Object files
OBJS = $(SRC:%=$(BUILD_DIR)/%.o)

# Dependencies
DEP := $(OBJS:.o=.d)

# Links all the objects
$(BUILD_DIR)/$(TARGET): $(OBJS)
	@echo "Building $(TARGET)"
	@$(CXX) $(shell wx-config --libs all) $(OBJS) -o $(BUILD_DIR)/$(TARGET)
	@echo "Done with $(TARGET)"

# c++ Source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) $(shell wx-config --cxxflags --libs all) $< -o $@

# Cleans all the object files and TARGET executable
clean:
	@echo "Removing $(BUILD_DIR) folder and $(TARGET)";
	@rm -r $(BUILD_DIR);
	@rm $(TARGET)

# include all Dependencies
-include $(DEP)

MKDIR_P ?= mkdir -p
