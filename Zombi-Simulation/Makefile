# Program name for executable
PROGRAM = Zombi_Simulation

# Project Home Directoy
PROJECT_HOME_DIR ?= .

# Build Directoy
BUILD_DIR ?= $(PROJECT_HOME_DIR)/build

# Compiler
CXX = g++

# Source files
SRC := $(wildcard *.cpp)

# Object files
OBJ := $(SRC:%=$(BUILD_DIR)/%.o)

# Dependencies
DEP := $(OBJ:.o=.d)

# Links all the
$(BUILD_DIR)/$(PROGRAM): $(OBJ)
	$(CXX) $(OBJ) $(shell wx-config --libs all) -o $(PROGRAM)

# c++ Source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(shell wx-config --cxxflags --libs all) -c $< -o $@

# Cleans all the object files and program executable
clean:
	rm $(PROGRAM)
	rm -r $(BUILD_DIR)

# include all Dependencies
-include $(DEP)

MKDIR_P ?= mkdir -p
