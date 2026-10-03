# Makefile для библиотеки MathLibrary

CXX      = g++
CXXFLAGS = -Wall -O2 -DMATHLIBRARY_EXPORTS
TARGET   = MathLibrary.dll
IMPLIB   = libMathLibrary.a
SRCS     = MatrixOperations.cpp
OBJS     = $(SRCS:.cpp=.o)

# Куда устанавливать (относительно корня Lab1)
PREFIX          ?= ..
INSTALL_LIB     = $(PREFIX)/lib
INSTALL_INCLUDE = $(PREFIX)/include

all: compile

compile: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -shared -o $@ $^ -Wl,--out-implib,$(IMPLIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install: $(TARGET)
	mkdir -p $(INSTALL_LIB) $(INSTALL_INCLUDE)
	cp $(TARGET) $(IMPLIB) $(INSTALL_LIB)
	cp MatrixOperations.h $(INSTALL_INCLUDE)

clean:
	rm -f $(OBJS) $(TARGET) $(IMPLIB)

uninstall:
	rm -f $(INSTALL_LIB)/$(TARGET) $(INSTALL_LIB)/$(IMPLIB)
	rm -f $(INSTALL_INCLUDE)/MatrixOperations.h

.PHONY: all compile install clean uninstall