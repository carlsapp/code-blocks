# This makefile was built from Arash Partow's great template at
# http://www.partow.net/programming/makefile/index.html
# GNU Makefile Documentation: https://www.gnu.org/software/make/manual/make.html


# CXX      := -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror -O3
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
# Change TARGET to be what you want your executable file to be called
TARGET   := program
INCLUDE  := -I../../include/
SRC      :=                      \
   $(wildcard src/module1/*.cpp) \
   $(wildcard *.cpp) \
   $(wildcard ../../src/*.cpp)

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/$(notdir %.o))

#all: build $(PROGRAMS:%.cpp)
all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/$(notdir %.o): %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf build/*