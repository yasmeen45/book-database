// a5_main.cpp

#include "a5.h"  
#include <ncurses.h>

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Yasmeen Al-Issa
// St.# : 301539066
// Email: yasmeen_al-issa@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////


int main() {
    Database database;
    database.read_database_file();
    Menu menu;
    menu.main_menu(database);
    database.save_records();
}