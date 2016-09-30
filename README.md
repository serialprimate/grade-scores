# grade-scores
Requirements test implementation for Transmax.

## Development Environment
As this code was developed in standard C++14 and using Boost.Test it should build for many platforms and IDEs.
The supplied build system is CMake which will also produce build configurations for many build environments. The
development platform in this case was Arch Linux.

### Dependencies
The build dependencies are as follows:
* CMake 3.6.2 (using 2.8.9 compatibility)
* Boost.Test 1.61 (using features available from 1.51)
As this is a simple and vanilla application the earlier versions noted are likely to work.

## Build Instructions for An Out-Of-Tree Build (Linux)
It is easy to configure an out-of-tree build with CMake.
To (re)configure a CMake out-of-tree build using Makefiles under a `build` directory and installing
to an `install` directory use the following command:

`$ rm -rf build && rm -rf install && mkdir build && cd build && cmake -Wdev --warn-unitialized -D CMAKE_BUILD_TYPE=DEBUG -D CMAKE_CXX_COMPILER=g++ -D CMAKE_C_COMPILER=gcc -D CMAKE_INSTALL_PREFIX=../install -G "Unix Makefiles" -D CMAKE_VERBOSE_MAKEFILE=TRUE ..`

With this configuration the following standard build targets are then:

Target | Command | Description
------ | ------- | -----------
all | `make -C build all` | Build everything, including dependencies.
clean | `make -C build clean` | Clean the build.
install | `make -C build install` | Install the build to the configured installation directory.
purge | `rm -rf <build-dir> && rm -rf <install-dir>` | Delete the build configuration leaving only the original source files.
test | `make -C build ARGS="--output-on-failure --verbose"` | Run all tests with as much output as possible.

## Build Instructions (Windows)

A windows machine for development and testing was not available but CMake is easy to use.
Here I describe how to make an in-tree build using CMake for visual studio.
The information in this section is untested but provided for convenience.

To generate a visual studio projects simply use a command similar to the following:

`C:\> cmake -G "Visual Studio 14 2015 Win64" .`

It is necessary to ensure that path to CMake is correct and the current working directory is
where the code is checked out.

## Sample Test Output
```
17:19:54 **** Build of configuration Default for project GradeScores ****
make -C build "ARGS=--output-on-failure --verbose" test
make: Entering directory '/home/matt/workspace/GradeScores/build'
Running tests...
/usr/bin/ctest --force-new-ctest-process --output-on-failure --verbose
UpdateCTestConfiguration  from :/home/matt/workspace/GradeScores/build/DartConfiguration.tcl
UpdateCTestConfiguration  from :/home/matt/workspace/GradeScores/build/DartConfiguration.tcl
Test project /home/matt/workspace/GradeScores/build
Constructing a list of tests
Done constructing a list of tests
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: test-library-grade

1: Test command: /home/matt/workspace/GradeScores/build/test/library/grade/test-library-grade "--log_level=all" "--report_level=detailed"
1: Test timeout computed to be: 9.99988e+06
1:
1: Test module "test-library-grade" has passed with:
1:   8 test cases out of 8 passed
1:   27 assertions out of 27 passed
1:
1:   Test suite "GradeScoreClass" has passed with:
1:     8 test cases out of 8 passed
1:     27 assertions out of 27 passed
1:
1:     Test case "GradeScoreClass/defaultConstructor" has passed with:
1:       3 assertions out of 3 passed
1:
1:     Test case "GradeScoreClass/constructor" has passed with:
1:       3 assertions out of 3 passed
1:
1:     Test case "GradeScoreClass/fromCSV" has passed with:
1:       12 assertions out of 12 passed
1:
1:     Test case "GradeScoreClass/toCSV" has passed with:
1:       2 assertions out of 2 passed
1:
1:     Test case "GradeScoreClass/operatorLT" has passed with:
1:       4 assertions out of 4 passed
1:
1:     Test case "GradeScoreClass/lastName" has passed with:
1:       1 assertion out of 1 passed
1:
1:     Test case "GradeScoreClass/firstName" has passed with:
1:       1 assertion out of 1 passed
1:
1:     Test case "GradeScoreClass/score" has passed with:
1:       1 assertion out of 1 passed
1:
1/3 Test #1: test-library-grade ...............   Passed    0.00 sec
test 2
    Start 2: test-grade-scores

2: Test command: /home/matt/workspace/GradeScores/build/application/grade-scores/grade-scores "scores.txt"
2: Test timeout computed to be: 9.99988e+06
2: BUNDY,TERESSA,88
2: KING,MADISON,88
2: SMITH,FRANCIS,85
2: SMITH,ALLAN,70
2: Finished: created scores-graded.txt
2/3 Test #2: test-grade-scores ................   Passed    0.00 sec
test 3
    Start 3: test-grade-scores-output-file

3: Test command: /usr/bin/cmake "-E" "compare_files" "scores-graded.txt" "scores-graded.txt.expected"
3: Test timeout computed to be: 9.99988e+06
3/3 Test #3: test-grade-scores-output-file ....   Passed    0.00 sec

100% tests passed, 0 tests failed out of 3

Total Test time (real) =   0.01 sec
make: Leaving directory '/home/matt/workspace/GradeScores/build'
```
