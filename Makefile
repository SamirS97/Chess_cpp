CXX=g++
CXXFLAGS=-std=c++11 -I./include -O3 -g -Wall

CLIBS= -lsfml-graphics  -lsfml-window -lsfml-system
INCDIR=-I//home/sasl/shared/main/c++/SFML-2.5.1/include

SRCDIR=src
SRCS= $(shell find $(SRCDIR) -name '*.cpp')

OBJDIR=src
OBJS=$(subst $(SRCDIR),$(OBJDIR), $(SRCS))
OBJS:=$(subst .cpp,.o,$(OBJS))

BIN := ./bin
TARGET=MChess

all: dir $(BIN)/$(TARGET)

dir: ${BIN}
  
${BIN}:
	mkdir -p $(BIN)

$(BIN)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $+ $(CLIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	[ -d $(OBJDIR) ] || mkdir $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCDIR) $< -c -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(TARGET)
