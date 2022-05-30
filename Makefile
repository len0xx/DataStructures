CC = g++
BDIR = bin
IDIR = headers
STD = c++20

.PHONY: clean

test-binary-tree:
	$(CC) tests/binary_tree.cpp -o $(BDIR)/tests/binary_tree -I $(IDIR) -std=$(STD)

test-dictionary:
	$(CC) tests/dictionary.cpp -o $(BDIR)/tests/dictionary -I $(IDIR) -std=$(STD)

test-list:
	$(CC) tests/list.cpp -o $(BDIR)/tests/list -I $(IDIR) -std=$(STD)

example-binary-tree:
	$(CC) examples/tree.cpp -o $(BDIR)/examples/tree -I $(IDIR) -std=$(STD)

example-dictionary:
	$(CC) examples/dictionary.cpp -o $(BDIR)/examples/dictionary -I $(IDIR) -std=$(STD)

example-list:
	$(CC) examples/list.cpp -o $(BDIR)/examples/list -I $(IDIR) -std=$(STD)

example-strings:
	$(CC) examples/strings.cpp -o $(BDIR)/examples/strings -I $(IDIR) -std=$(STD)

example-stacks:
	$(CC) examples/stacks.cpp -o $(BDIR)/examples/stacks -I $(IDIR) -std=$(STD)

tests: test-binary-tree test-dictionary test-list

examples: example-binary-tree example-dictionary example-list example-strings example-stacks

run-tests:
	./bin/tests/binary_tree
	./bin/tests/dictionary
	./bin/tests/list

run-examples:
	./bin/examples/tree
	./bin/examples/dictionary
	./bin/examples/list
	./bin/examples/strings
	./bin/examples/stacks

clean:
	rm ./*.o
