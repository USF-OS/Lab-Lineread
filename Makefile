# Set the following to '0' to disable log messages:
DEBUG ?= 1 

CFLAGS += -Wall -g
LDFLAGS +=

all: read_file read_file_dynamic

read_file: read_file.c liblineread.so
	$(CC) $(CFLAGS) $(LDFLAGS) -DDEBUG=$(DEBUG) -L. -Wl,-rpath='$$ORIGIN' -llineread read_file.c -o $@

read_file_dynamic: read_file_dynamic.c liblineread.so
	$(CC) $(CFLAGS) $(LDFLAGS) -DDEBUG=$(DEBUG) -L. -Wl,-rpath='$$ORIGIN' -llineread read_file_dynamic.c -o $@

liblineread.so: lineread.c lineread.h
	$(CC) $(CFLAGS) $(LDFLAGS) -DDEBUG=$(DEBUG) -shared -fPIC lineread.c -o $@

docs: Doxyfile
	doxygen

clean:
	rm -f liblineread.so read_file read_file_dynamic
	rm -rf docs

# Tests --

test: read_file read_file_dynamic ./tests/run_tests
	./tests/run_tests $(run)

testupdate: testclean test

./tests/run_tests:
	rm -rf tests
	git clone https://github.com/USF-OS/L2-Tests.git tests

testclean:
	rm -rf tests
