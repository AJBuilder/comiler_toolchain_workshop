# Task 1 - Compile everything in one line
You can compile an executable if you have access to all source code.
```
g++ -o hello.out hello.cpp greeting.cpp helper.cpp
```

Delete hello.out.

# Task 2 - Compile library first
```
g++ -c greeting.cpp helper.cpp
ar rcs libmylib.a greeting.o helper.o
```
`ar` is a command that will bundle multiple objects together into one archive, or a "static library".
```
g++ -o hello.out hello.cpp -L. -lmylib
```
-L specifies where to look for libraries. -l specifies what libraries.

Cleanup all build artifacts.

# Task 3 - Compiling everything with Make

We can use Makefiles to simplify a build process. To utilize a Makefile, run:

```
make
```
This is the same as :
```
make all
```


Cleanup all build artifacts. You can do this with:
```
make clean
```

Don't want to create build artifacts every step of the way? Try:
```
make noArtifacts
```
(This isn't convention. I just made it up to demo that there's no magic.)

# Task 4 - Add install directive
Let's edit the Makefile a bit.

First you can change the `EXECUTABLE` variable to anything you want. This will be the name of the resulting executable.

Next, let's add an `install` directive. This directive will package all items that the end user will need and install them in the appropriate location. Since we are using a static library it actually isn't necessary to install it for your executable to run, but maybe we want to use it for other programs?

Add the following code at the bottom of the Makefile

```
install: $(EXECUTABLE)
	install -d $(INSTALL_PREFIX)/lib
	install -m 644 libmylib.a $(PREFIX)/lib/libmylib.a
	install -d $(INSTALL_PREFIX)/include
	install -m 644 greeting.hpp $(INSTALL_PREFIX)/include/greeting.hpp
	install -m 644 helper.hpp $(INSTALL_PREFIX)/include/helper.hpp
	install -d $(INSTALL_PREFIX)/bin
	install -m 755 $(EXECUTABLE) $(INSTALL_PREFIX)/bin/$(EXECUTABLE)

uninstall:
	rm -f $(INSTALL_PREFIX)/lib/libmylib.a
	rm -f $(INSTALL_PREFIX)/include/greeting.hpp
	rm -f $(INSTALL_PREFIX)/include/helper.hpp
	rm -f $(INSTALL_PREFIX)/bin/$(EXECUTABLE)
```

You can change the `INSTALL_PREFIX` to change where the files are installed.
