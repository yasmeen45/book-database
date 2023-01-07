// a5_book.cpp
// Book class

#include "a5.h"  

using namespace std;

// default constructor
Book::Book() 
:name(""), author(""), year(0), genre(""), num_pages(0)
{}

// constructor
Book::Book(string n, string a, int y, string g, int p) 
:name(n), author(a), year(y), genre(g), num_pages(p)
{}

// copy constructor
Book::Book(const Book & other)
:Book(other.name, other.author, other.year, other.genre, other.num_pages)
{}

// getters:
Book Book::get_book() {return *this;}
string Book::get_name() const {return name;}
string Book::get_author() const {return author;}
int Book::get_year() const {return year;}
string Book::get_genre() const {return genre;}
int Book::get_num_pages() const {return num_pages;}


