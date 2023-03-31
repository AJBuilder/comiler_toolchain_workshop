CMake doesn't really do any actual building/install/operations. It generates a Makefile that does.

# Task 1 - Compile using Cmake

```
mkdir build
cd build
cmake ..
make
```

# Task 2 - Install

Maybe rename the executable target from "hello" to something unique within CMakeLists.txt? Check out the add_executable() command. If you do, make sure to run `cmake` again.

In order to generate install directives into the Makefile, add:
```
install(TARGETS hello DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include)
install(TARGETS mylib DESTINATION lib)
```
Rerun `cmake ..`

Now to install:
```
make install
```
If installing failed, you might not have permissions to install int "/usr/local/" which is the default install prefix. To change, either add
```
set(CMAKE_INSTALL_PREFIX /some/other/path)
```
to your CMakeList, or modify the prefix when you run cmake like
```
cmake -DCMAKE_INSTALL_PREFIX=/some/other/path ..
```
I recomend using the path `./install`

Your custom location probably won't be in the PATH variable. (ie, you can't  run it directly from the command line)


