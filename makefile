##############################################################################
#
# Makefile for assignment 5 of CMPT 135 Spring 2022, SFU Surrey.
#
# Commands for this makefile that can be typed at the command line:
#
#   make
#      Build the executable program a5_main_test. 
#
#   make -j
#      Build a5_main_test possibly a little more quickly. The "-j" option
#      tells make to try to use multiple CPUs when compiling two, or more,
#      files.
#
#   make clean
#      Delete a5_main_test, and all the .o object files.
#
#   make <name>
#      Compiles a specific file, where <name> is the name of one of the rules
#      listed in the makefile below, i.e. a5, a5_main, etc.
#
##############################################################################

# Set the C++ compiler options:
#   -std=c++17 compiles using the C++17 standard (or at least as 
#    much as is implemented by the compiler, e.g. for g++ see
#    http://gcc.gnu.org/projects/cxx0x.html)
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g 

a5_main_test: a5_main.o a5_book.o a5_database.o a5_menu.o 
	g++ -o a5_main_test a5_main.o a5_book.o a5_database.o a5_menu.o -lncurses

a5_main:
	g++ -c $(CPPFLAGS) a5_main.cpp

a5_book:
	g++ -c $(CPPFLAGS) a5_book.cpp

a5_database:
	g++ -c $(CPPFLAGS) a5_database.cpp

a5_menu:
	g++ -c $(CPPFLAGS) a5_menu.cpp 

clean:
	rm -f a5_main_test a5.o a5_main.o a5_book.o a5_database.o a5_menu.o 
