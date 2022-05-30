CC = g++
BDIR = bin
IDIR = headers
TDIR = tests
EDIR = examples
STD = c++20

.PHONY: clean

test-binary-tree:
	$(CC) $(TDIR)/binary_tree.cpp -o $(BDIR)/$(TDIR)/binary_tree -I $(IDIR) -std=$(STD)

test-dictionary:
	$(CC) $(TDIR)/dictionary.cpp -o $(BDIR)/$(TDIR)/dictionary -I $(IDIR) -std=$(STD)

test-list:
	$(CC) $(TDIR)/list.cpp -o $(BDIR)/$(TDIR)/list -I $(IDIR) -std=$(STD)

example-binary-tree:
	$(CC) $(EDIR)/tree.cpp -o $(BDIR)/$(EDIR)/tree -I $(IDIR) -std=$(STD)

example-dictionary:
	$(CC) $(EDIR)/dictionary.cpp -o $(BDIR)/$(EDIR)/dictionary -I $(IDIR) -std=$(STD)

example-list:
	$(CC) $(EDIR)/list.cpp -o $(BDIR)/$(EDIR)/list -I $(IDIR) -std=$(STD)

example-strings:
	$(CC) $(EDIR)/strings.cpp -o $(BDIR)/$(EDIR)/strings -I $(IDIR) -std=$(STD)

example-stacks:
	$(CC) $(EDIR)/stacks.cpp -o $(BDIR)/$(EDIR)/stacks -I $(IDIR) -std=$(STD)

tests: test-binary-tree test-dictionary test-list

examples: example-binary-tree example-dictionary example-list example-strings example-stacks

run-tests:
	./$(BDIR)/$(TDIR)/binary_tree
	./$(BDIR)/$(TDIR)/dictionary
	./$(BDIR)/$(TDIR)/list

run-examples:
	./$(BDIR)/$(EDIR)/tree
	./$(BDIR)/$(EDIR)/dictionary
	./$(BDIR)/$(EDIR)/list
	./$(BDIR)/$(EDIR)/strings
	./$(BDIR)/$(EDIR)/stacks

clean:
	rm ./*.o
