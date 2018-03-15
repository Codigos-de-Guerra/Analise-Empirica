
# Makefile conventions
SHELL = /bin/sh

# Directories
incdir = ./include
srcdir = ./src
objdir = ./obj
bindir = ./bin

# Macros
CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -lm -I$(incdir)
RM = -rm 
OBJS = $(addprefix $(objdir)/,search.o util.o)

# Phony targets (for more information, visit https://www.gnu.org/software/make/manual/make.html#Phony-Targets)
.PHONY: clean cleanobj cleanbin
.PHONY: all main build search

# Use "make" to execute everything
all: build main 

# Use "make main" to compile the main
main: analise

# Use "make build" to build all the modules
build: util search

# Use "make util" to build only the util module
util: $(objdir)/util.o

# Use "make search" to build only the search module
search: $(objdir)/search.o

# Compiles the main
analise: $(srcdir)/main.cpp $(OBJS)
	# mkdir -p $(bindir)
	$(CC) $(CFLAGS) $^ -o $@

# Builds only the util module
$(objdir)/util.o: $(srcdir)/util.cpp $(incdir)/util.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the searching module (use "make search")
$(objdir)/search.o: $(srcdir)/search.cpp $(incdir)/search.h $(incdir)/util.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes all objects
cleanobj:
	$(RM) $(objdir)/*.o

# Removes all executables
cleanbin:
	$(RM) $(bindir)/*

# Removes all executables and all objects
clean: cleanobj cleanbin 