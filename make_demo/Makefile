CC=g++
CFLAGS=-c -Wall
LDFLAGS=-L. -lmylib
SOURCES=hello.cpp greeting.cpp helper.cpp
HEADERS=greeting.hpp helper.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

ifeq ($(wildcard libmylib.a),)
# If libmylib.a doesn't exist, compile the library from source
all: $(SOURCES) $(HEADERS) libmylib.a $(EXECUTABLE)

libmylib.a: greeting.o helper.o
	ar rcs libmylib.a greeting.o helper.o

greeting.o: greeting.cpp greeting.hpp
	$(CC) $(CFLAGS) greeting.cpp

helper.o: helper.cpp helper.hpp
	$(CC) $(CFLAGS) helper.cpp
else
# If libmylib.a exists, use it
all: $(EXECUTABLE)

endif

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) libmylib.a
