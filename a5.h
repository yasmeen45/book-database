// a4.h

#ifndef A5_H
#define A5_H

#include "cmpt_error.h"
//#include <ncurses.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>

using namespace std;

class Book {
private:
    string name;
    string author;
    int year;
    string genre;
    int num_pages;
public:
    // default constructor
    Book();
    //constructor
    Book(string n, string a, int y, string g, int p);
    // copy constructor
    Book(const Book & other);

    // getters:
    Book get_book();
    string get_name() const;
    string get_author() const;
    int get_year() const;
    string get_genre() const;
    int get_num_pages() const;
};

class Database {
private:
    vector <Book> records;
public:
    // default constructor
    Database();

    void read_database_file();

    // getters:
    int get_size() const;
    Book book_at(int i) const;
    string name_at(int i) const;
    string author_at(int i) const;
    int year_at(int i) const;
    string genre_at(int i) const;
    int num_pages_at(int i) const;

    void add_record(Book & book);
    void delete_record_at(int i);

    // sorting:
    void sort_name();
    void sort_author();
    void sort_genre();
    void sort_year();
    void sort_pages();
    void reverse_vec();

    void save_records();
};

class Menu {
private:
public:
    void main_menu(Database & database);

    void add_book(Database & database);
    bool is_num(string & str);
    void list_record(Database & database, int i);

    void find_book(Database & database);
    vector <Book> list_by_name(Database & database);
    vector <Book> list_by_author(Database & database);
    vector <Book> list_by_genre(Database & database);
    vector <Book> list_by_year(Database & database);
    vector <Book> list_by_pages(Database & database);

    void delete_book(Database & database);
    void delete_selected_records(Database & database, vector <Book> & records_selected);

    void list_books(Database & database);
};


#endif