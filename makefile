# Makefile conventions
SHELL = /bin/sh

# Directories
incdir = ./include
srcdir = ./src
objdir = ./obj
outdir = ./out

# Macros
CC = g++
CFLAGS = -Wall -std=c++11 -lm -I$(incdir)
RM = -rm 
OBJS = $(addprefix $(objdir)/,search.o util.o write.o)

# Phony targets (for more information, visit https://www.gnu.org/software/make/manual/make.html#Phony-Targets)
.PHONY: clean cleanobj cleanout
.PHONY: all main build search

# Use "make" to execute everything
all: build main 

# Use "make main" to compile the main
main: analise

# Use "make build" to build all the modules
build: util search write

# Use "make util" to build only the util module
util: $(objdir)/util.o

# Use "make search" to build only the search module
search: $(objdir)/search.o

# Use "make write" to build only the write module
write: $(objdir)/write.o

# Compiles the main
analise: $(srcdir)/main.cpp $(OBJS)
	mkdir -p $(outdir)
	$(CC) $(CFLAGS) $^ -o $@

# Use "make plot" to compile the file generator for gnuplot
plot: $(srcdir)/script.cpp
	$(CC) -Wall -std=c++11 $^ -o $@

# Builds only the util module
$(objdir)/util.o: $(srcdir)/util.cpp $(incdir)/util.h $(incdir)/search.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the searching module (use "make search")
$(objdir)/search.o: $(srcdir)/search.cpp $(incdir)/search.h $(incdir)/util.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the writing module
$(objdir)/write.o: $(srcdir)/write.cpp $(incdir)/write.h $(incdir)/util.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes executable
cleanbin:
	$(RM) analise plot

# Removes all objects
cleanobj:
	$(RM) $(objdir)/*.o
	$(RM) -r $(objdir)

# Removes all outputs
cleanout:
	$(RM) -r -f $(outdir)

# Removes all objects, all outputs and all executables
clean: cleanobj cleanout cleanbin
