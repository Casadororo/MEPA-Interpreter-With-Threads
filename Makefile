# Compiler and flags
# Directories
SRCDIR := src
BUILDDIR := build
TARGET := MEPA

# Find all CPP files in src directory and its subdirectories
SOURCES := $(shell find $(SRCDIR) -type f -name *.c)

# Generate object file names based on source file names
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.c=.o))

# Build executable
$(TARGET): $(OBJECTS) flex bison headers
	gcc $(OBJECTS) $(BUILDDIR)/lex.yy.c $(BUILDDIR)/leMepa.tab.c -o $@ -ll -ly -lc

# Build object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

flex: $(SRCDIR)/leMepa.l
	@mkdir -p $(BUILDDIR)
	flex $< 
	mv lex.yy.c $(BUILDDIR)/lex.yy.c
	# mv lex.yy.h $(BUILDDIR)/lex.yy.h

bison: $(SRCDIR)/leMepa.y
	@mkdir -p $(BUILDDIR)
	bison $< -d -v
	mv leMepa.tab.c $(BUILDDIR)/leMepa.tab.c
	mv leMepa.tab.h $(BUILDDIR)/leMepa.tab.h
	mv leMepa.output $(BUILDDIR)/leMepa.output

headers: 
	@mkdir -p $(BUILDDIR)
	cp $(SRCDIR)/*.h $(BUILDDIR)

# Phony target to clean the build directory
.PHONY: clean
clean:
	-rm -r $(BUILDDIR)
	-rm $(TARGET)

# Phony target to run the program
.PHONY: run
run: $(TARGET)
	./$(TARGET) ./tests/type4.pas

# Phony target to run the program
.PHONY: valgrind
valgrind: $(TARGET)
	valgrind ./$(TARGET) < tests/teste1.pas
