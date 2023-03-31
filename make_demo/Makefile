CC=g++
CFLAGS=-c -Wall
LDFLAGS=-L. -lmylib
SOURCES=hello.cpp greeting.cpp helper.cpp
HEADERS=greeting.hpp helper.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello.out # You can change this output executable name

INSTALL_PREFIX = ./install

all: $(SOURCES) $(HEADERS) libmylib.a $(EXECUTABLE)

noArtifacts: $(SOURCES)
	$(CC) $(LDFLAGS) $(SOURCES) -o $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

libmylib.a: greeting.o helper.o
	ar rcs libmylib.a greeting.o helper.o

greeting.o: greeting.cpp greeting.hpp
	$(CC) $(CFLAGS) greeting.cpp

helper.o: helper.cpp helper.hpp
	$(CC) $(CFLAGS) helper.cpp

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) libmylib.a

# VVVVV Specify installation rules here VVVVV
