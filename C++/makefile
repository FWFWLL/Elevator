BINDIR = ./bin
SRCDIR = ./src
OBJDIR = ./obj

EXE = $(BINDIR)/elevator
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CC = g++
CPPFLAGS = -Iinclude -MMD -MP
CFLAGS = -Wall -pthread

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BINDIR) $(OBJDIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BINDIR) $(OBJDIR)

-include $(OBJ:.o=.d)


