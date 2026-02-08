CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
TARGET = cpp_compiler
SOURCES = main.cpp \
          compiler/token.cpp \
          compiler/lexer.cpp \
          compiler/ast.cpp \
          compiler/parser.cpp \
          compiler/interpreter.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f compiler/*.o

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
