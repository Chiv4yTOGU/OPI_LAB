# Makefile дл€ консольного приложени€ ConsoleApp

CXX      = g++
CXXFLAGS = -Wall -O2 -finput-charset=UTF-8 -fexec-charset=UTF-8
TARGET   = ConsoleApp.exe
SRCS     = ConsoleApp.cpp
OBJS     = $(SRCS:.cpp=.o)

# –асположение библиотеки задаЄтс€ переменной (относительно корн€ Lab1)
LIB_DIR     ?= ../lib
INCLUDE_DIR ?= ../include

LDFLAGS = -L$(LIB_DIR) -lMathLibrary

all: compile

compile: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

install: $(TARGET)
	mkdir -p ../bin
	cp $(TARGET) ../bin
	cp $(LIB_DIR)/MathLibrary.dll ../bin

clean:
	rm -f $(OBJS) $(TARGET)

uninstall:
	rm -f ../bin/$(TARGET) ../bin/MathLibrary.dll

.PHONY: all compile install clean uninstall