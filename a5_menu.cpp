// a5_manu.cpp

#include "a5.h"  
#include <ncurses.h>


void Menu::main_menu(Database & database) {
    string input;
    cout << endl << "Welcome to the Book Database!" << endl;
    cout << "-----------------------------" << endl << endl;
    cout << "(1) Add a book" << endl;
    cout << "(2) Find a book" << endl;
    cout << "(3) Delete a book" << endl;
    cout << "(4) List books" << endl;
    cout << "(5) Quit" << endl << endl;
    cout << "Enter the number of your choice: ";
    getline(cin, input);
    cout << endl;

    // input checking
    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5") {
        cin.clear();

		cout << "\nPlease enter a valid choice: ";
		getline(cin, input);
    }

    if (input == "1") {
        Menu::add_book(database);
    } else if (input == "2") {
        Menu::find_book(database);
    } else if (input == "3") {
        Menu::delete_book(database);
    } else if (input == "4") {
        Menu::list_books(database);
    } else {
        return;
    } 
}

void Menu::add_book(Database & database) {
    string name;
    string author;
    string year;
    string genre;
    string num_pages;

   cout << endl << endl << "Add a Book:" << endl;
   cout << "-----------" << endl << endl;
   cout << "Book name: ";
   getline(cin, name);

   for (int i = 0; i < database.get_size(); i++) {
       if (name == database.name_at(i))  {
           string input;
           cout << "This book already exists in the database." << endl;
           cout << "Would you like to enter a different book name? (Y/N)";
           getline(cin, input);

           while (input != "Y" && input != "N") {
           cin.clear();
		   cout << "Please enter a valid choice: ";
		   getline(cin, input);
           }

           if (input == "Y") {
               Menu::add_book(database);
           } else {
               Menu::main_menu(database);
           }
           
       }
   }

   cout << "Book author: ";
   getline(cin, author);

   cout << "Year Published: ";
   getline(cin, year);

   while(!is_num(year) || stoi(year) < 0 || stoi(year) > 2022) {
        cin.clear();
		cout << "Please enter a valid year: ";
		getline(cin, year);
   }

   cout << "Book Genre: ";
   getline(cin, genre);

   cout << "Number of Pages: ";
   getline(cin, num_pages);

   while(!is_num(num_pages) || stoi(num_pages) < 0) {
        cin.clear();
		cout << "Please enter a valid number: ";
		getline(cin, num_pages);
    }

   Book new_book(name, author, stoi(year), genre, stoi(num_pages));

   database.add_record(new_book);
   cout << endl << "Book successfully added!" << endl << endl;
   Menu::main_menu(database);
}

bool Menu::is_num(string & str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false) {
      return false;
   }
      return true;
}

void Menu::find_book(Database & database) {
    string input = "";
    cout << endl << "Find a Book:" << endl;
    cout << "----------" << endl << endl;
    cout << "You can search by:" << endl << endl;
    cout << "(1) Book Name" << endl;
    cout << "(2) Author" << endl;
    cout << "(3) Year Published" << endl;
    cout << "(4) Book Genre" << endl;
    cout << "(5) Number of Pages" << endl << endl;
    cout << "(6) Return to Main Menu" << endl << endl;
    cout << "Enter the number of your choice: ";
    getline(cin, input);
    cout << endl;

    // input checking
    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6") {
        cin.clear();
		cout << "\nPlease enter a valid choice: ";
		getline(cin, input);
    }

    if (input == "1") {
        Menu::list_by_name(database);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "2") {
        Menu::list_by_author(database);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "3") {
        Menu::list_by_year(database);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "4") {
        Menu::list_by_genre(database);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "5") {
        Menu::list_by_pages(database);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    } else if (input == "6") {
        Menu::main_menu(database);
    }
}

vector <Book> Menu::list_by_name(Database & database) {
    vector <Book> records_selected;
    string input = "";
    cout << "Search by: " << endl;
    cout << "(1) Exact Name" << endl;
    cout << "(2) Partial Name" << endl << endl;
    cout << "Enter the number of your choice: ";
    getline(cin, input);
    cout << endl;

    while (input != "1" && input != "2") {
        cin.clear();
		cout << "\nPlease enter a valid choice: ";
		getline(cin, input);
    }

    if (input == "1") {
        string word = "";
        cout << endl << "Search for: ";
        getline(cin, word);

        cout << endl << "Records found: " << endl << endl;
        int count = 0;

        for (int i = 0; i < database.get_size(); i++) {
            if (database.name_at(i) == word) {
                list_record(database, i);
                records_selected.push_back(database.book_at(i));
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    }

    if (input == "2") {
        string word = "";
        cout << "Search for: ";
        getline(cin, word);
        cout << endl << "Records found: " << endl << endl;
        int count = 0;
        long long fail = string::npos;

        for (int i = 0; i < database.get_size(); i++) {
            if (database.name_at(i).find(word) != fail) {
                list_record(database, i);
                records_selected.push_back(database.book_at(i));
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    } 
    return records_selected;
}

vector <Book> Menu::list_by_author(Database & database) {
    vector <Book> records_selected;
    string input = "";
    cout << "Search by: " << endl;
    cout << "(1) Exact Name" << endl;
    cout << "(2) Partial Name" << endl << endl;
    cout << "Enter the number of your choice: ";
    getline(cin, input);
    cout << endl;

    while (input != "1" && input != "2") {
        cin.clear();
		cout << "\nPlease enter a valid choice: ";
		getline(cin, input);
    }

    if (input == "1") {
        string word = "";
        cout << endl << "Search for: ";
        getline(cin, word);

        cout << endl << "Records found: " << endl << endl;
        int count = 0;

        for (int i = 0; i < database.get_size(); i++) {
            if (database.author_at(i) == word) {
                list_record(database, i);
                records_selected.push_back(database.book_at(i));
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    }

    if (input == "2") {
        string word = "";
        cout << "Search for: ";
        getline(cin, word);
        cout << endl << "Records found: " << endl << endl;
        int count = 0;
        long long fail = string::npos;

        for (int i = 0; i < database.get_size(); i++) {
            if (database.author_at(i).find(word) != fail) {
                list_record(database, i);
                records_selected.push_back(database.book_at(i));
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    } 
    return records_selected;
}

vector <Book> Menu::list_by_year(Database & database) {
    vector <Book> records_selected;
    string input = "";
    cout << "Search by: " << endl;
    cout << "(1) Exact Year" << endl;
    cout << "(2) Range of Years" << endl << endl;
    cout << "Enter the number of your choice: ";
    getline(cin, input);
    cout << endl;

    while (input != "1" && input != "2") {
        cin.clear();
		cout << "\nPlease enter a valid choice: ";
		getline(cin, input);
    }

    if (input == "1") {
        string year = "";
        cout << endl << "Search for: ";
        getline(cin, year);

        while(!is_num(year) || stoi(year) < 0 || stoi(year) > 2022) {
            cin.clear();
            cout << "Please enter a valid year: ";
            getline(cin, year);
        }

        cout << endl << "Records found: " << endl << endl;
        int count = 0;

        for (int i = 0; i < database.get_size(); i++) {
            if (database.year_at(i) == stoi(year)) {
                list_record(database, i);
                records_selected.push_back(database.book_at(i));
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    }

    if (input == "2") {
        string start = "";
        string end = "";
        cout << endl << "Start year: ";
        getline(cin, start);

        while(!is_num(start) || stoi(start) < 0 || stoi(start) > 2022) {
            cin.clear();
            cout << "Please enter a valid year: ";
            getline(cin, start);
        }

        cout << "End year: ";
        getline(cin, end);

        while(!is_num(end) || stoi(end) < 0 || stoi(end) > 2022 || stoi(end) < stoi(start)) {
            cin.clear();
            cout << "Please enter a valid year that follows the start year: ";
            getline(cin, end);
        }

        cout << endl << "Records found: " << endl << endl;
        int count = 0;

        database.sort_year();

        for (int i = 0; i < database.get_size(); i++) {
            if (database.year_at(i) >= stoi(start) && database.year_at(i) <= stoi(end)) {
                list_record(database, i);
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    } 
    return records_selected;
}

vector <Book> Menu::list_by_genre(Database & database) {
    vector <Book> records_selected;
    string input = "";
    cout << "Search by: " << endl;
    cout << "(1) Exact Word" << endl;
    cout << "(2) Partial Word" << endl << endl;
    cout << "Enter the number of your choice: ";
    getline(cin, input);
    cout << endl;

    while (input != "1" && input != "2") {
        cin.clear();
		cout << "\nPlease enter a valid choice: ";
		getline(cin, input);
    }

    if (input == "1") {
        string word = "";
        cout << endl << "Search for: ";
        getline(cin, word);

        cout << endl << "Records found: " << endl << endl;
        int count = 0;

        for (int i = 0; i < database.get_size(); i++) {
            if (database.genre_at(i) == word) {
                list_record(database, i);
                records_selected.push_back(database.book_at(i));
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    }

    if (input == "2") {
        string word = "";
        cout << "Search for: ";
        getline(cin, word);
        cout << endl << "Records found: " << endl << endl;
        int count = 0;
        long long fail = string::npos;

        for (int i = 0; i < database.get_size(); i++) {
            if (database.genre_at(i).find(word) != fail) {
                list_record(database, i);
                records_selected.push_back(database.book_at(i));
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    } 
    return records_selected;
}

vector <Book> Menu::list_by_pages(Database & database) {
    vector <Book> records_selected;
    string input = "";
    cout << "Search by: " << endl;
    cout << "(1) Exact Number of Pages" << endl;
    cout << "(2) Range of Pages" << endl << endl;
    cout << "Enter the number of your choice: ";
    getline(cin, input);
    cout << endl;

    while (input != "1" && input != "2") {
        cin.clear();
		cout << "\nPlease enter a valid choice: ";
		getline(cin, input);
    }

    if (input == "1") {
        string page = "";
        cout << endl << "Search for: ";
        getline(cin, page);

        while(!is_num(page) || stoi(page) < 0) {
            cin.clear();
            cout << "Please enter a valid page: ";
            getline(cin, page);
        }

        cout << endl << "Records found: " << endl << endl;
        int count = 0;

        for (int i = 0; i < database.get_size(); i++) {
            if (database.num_pages_at(i) == stoi(page)) {
                list_record(database, i);
                records_selected.push_back(database.book_at(i));
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    }

    if (input == "2") {
        string start = "";
        string end = "";
        cout << endl << "Start page: ";
        getline(cin, start);

        while(!is_num(start) || stoi(start) < 0) {
            cin.clear();
            cout << "Please enter a valid number:";
            getline(cin, start);
        }

        cout << "End page: ";
        getline(cin, end);

        while(!is_num(end) || stoi(end) < stoi(start)) {
            cin.clear();
            cout << "Please enter a valid number that follows the start page: ";
            getline(cin, end);
        }

        cout << endl << "Records found: " << endl << endl;
        int count = 0;
        database.sort_pages();

        for (int i = 0; i < database.get_size(); i++) {
            if (database.num_pages_at(i) >= stoi(start) && database.num_pages_at(i) <= stoi(end)) {
                list_record(database, i);
                count++;
            }
        }

        if (count == 0) {
            cout << "No matching records are found" << endl << endl;
        }
    } 
    return records_selected;
}

void Menu::delete_book(Database & database) {
    string input = "";
    cout << endl << "Delete a Book:" << endl;
    cout << "----------" << endl << endl;
    cout << "You can search by:" << endl << endl;
    cout << "(1) Book Name" << endl;
    cout << "(2) Author" << endl;
    cout << "(3) Year Published" << endl;
    cout << "(4) Book Genre" << endl;
    cout << "(5) Number of Pages" << endl << endl;
    cout << "(6) Return to Main Menu" << endl << endl;
    cout << "Enter the number of your choice: ";
    getline(cin, input);
    cout << endl;

    // input checking
    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6") {
        cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nPlease enter a valid choice: ";
		getline(cin, input);
    }

    if (input == "1") {
        vector <Book> records_selected = Menu::list_by_name(database);
        delete_selected_records(database, records_selected);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "2") {
        vector <Book> records_selected = Menu::list_by_author(database);
        delete_selected_records(database, records_selected);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "3") {
        vector <Book> records_selected = Menu::list_by_year(database);
        delete_selected_records(database, records_selected);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "4") {
        vector <Book> records_selected = Menu::list_by_genre(database);
        delete_selected_records(database, records_selected);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "5") {
        vector <Book> records_selected = Menu::list_by_pages(database);
        delete_selected_records(database, records_selected);
        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    } else if (input == "6") {
        Menu::main_menu(database);
    }
}

void Menu::delete_selected_records(Database & database, vector <Book> & records_selected) {
    string input;
    cout << "Are you sure you want to delete the records listed above? (Y/N)";
    getline(cin, input);
    cout << endl;

    while (input != "Y" && input != "N") {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid choice: ";
        getline(cin, input);
    }

    if (input == "Y") {
        for (int i = 0; i < records_selected.size(); i++) {
            for (int j = 0; j < database.get_size(); j++) {
                if (records_selected[i].get_name() == database.name_at(j)) {
                    database.delete_record_at(j);
                }
            }
        }
        cout << "Records successfully deleted!" << endl;
    } else {
        return;
    }
}

void Menu::list_books(Database & database) {
    string input = "";
    cout << endl << "List Books:" << endl;
    cout << "----------" << endl << endl;
    cout << "You can list by:" << endl << endl;
    cout << "(1) Book Name" << endl;
    cout << "(2) Author" << endl;
    cout << "(3) Year Published" << endl;
    cout << "(4) Book Genre" << endl;
    cout << "(5) Number of Pages" << endl << endl;
    cout << "(6) Return to Main Menu" << endl << endl;
    cout << "Enter the number of your choice: ";
    getline(cin, input);
    cout << endl;

    // input checking
    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6") {
        cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nPlease enter a valid choice: ";
		getline(cin, input);
    }

    if (input == "1") {
        string choice = "";
        cout << "Sort By:" << endl;
        cout << "(1) Alphabetical Order" << endl;
        cout << "(2) Reverse Alphabetical Order" << endl << endl;
        cout << "Enter the number of your choice: ";
        getline(cin, choice);
        cout << endl;

        while (choice != "1" && choice != "2") {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nPlease enter a valid choice: ";
            getline(cin, choice);
        }

        if (choice == "1") {
            database.sort_name();
        } else if (choice == "2") {
            database.sort_name();
            database.reverse_vec();
        }

        // print
        for (int i = 0; i < database.get_size(); i++) {
            list_record(database, i);
        }

        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "2") {
        string choice = "";
        cout << "Sort By:" << endl;
        cout << "(1) Alphabetical Order" << endl;
        cout << "(2) Reverse Alphabetical Order" << endl << endl;
        cout << "Enter the number of your choice: ";
        getline(cin, choice);
        cout << endl;

        while (choice != "1" && choice != "2") {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nPlease enter a valid choice: ";
            getline(cin, choice);
        }

        if (choice == "1") {
            database.sort_author();
        } else if (choice == "2") {
            database.sort_author();
            database.reverse_vec();
        }

        // print
        for (int i = 0; i < database.get_size(); i++) {
            list_record(database, i);
        }

        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "3") {
        string choice = "";
        cout << "Sort By:" << endl;
        cout << "(1) Ascending Order" << endl;
        cout << "(2) Descending Order" << endl << endl;
        cout << "Enter the number of your choice: ";
        getline(cin, choice);
        cout << endl;

        while (choice != "1" && choice != "2") {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nPlease enter a valid choice: ";
            getline(cin, choice);
        }

        if (choice == "1") {
            database.sort_year();
        } else if (choice == "2") {
            database.sort_year();
            database.reverse_vec();
        }

        // print
        for (int i = 0; i < database.get_size(); i++) {
            list_record(database, i);
        }

        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "4") {
        string choice = "";
        cout << "Sort By:" << endl;
        cout << "(1) Alphabetical Order" << endl;
        cout << "(2) Reverse Alphabetical Order" << endl << endl;
        cout << "Enter the number of your choice: ";
        getline(cin, choice);
        cout << endl;

        while (choice != "1" && choice != "2") {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nPlease enter a valid choice: ";
            getline(cin, choice);
        }

        if (choice == "1") {
            database.sort_genre();
        } else if (choice == "2") {
            database.sort_genre();
            database.reverse_vec();
        }

        // print
        for (int i = 0; i < database.get_size(); i++) {
            list_record(database, i);
        }

        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    }  else if (input == "5") {
        string choice = "";
        cout << "Sort By:" << endl;
        cout << "(1) Ascending Order" << endl;
        cout << "(2) Descending Order" << endl << endl;
        cout << "Enter the number of your choice: ";
        getline(cin, choice);
        cout << endl;

        while (choice != "1" && choice != "2") {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nPlease enter a valid choice: ";
            getline(cin, choice);
        }

        if (choice == "1") {
            database.sort_pages();
        } else if (choice == "2") {
            database.sort_pages();
            database.reverse_vec();
        }

        // print
        for (int i = 0; i < database.get_size(); i++) {
            list_record(database, i);
        }

        cout << endl << "Returning to main menu..." << endl << endl;
        Menu::main_menu(database);
    } else if (input == "6") {
        Menu::main_menu(database);
    }
}

void Menu::list_record(Database & database, int i) {
    cout << endl << "Book Name: " << database.name_at(i) << endl;
    cout << "Author: " << database.author_at(i) << endl;
    cout << "Year Published: " << database.year_at(i) << endl;
    cout << "Book Genre: " << database.genre_at(i) << endl;
    cout << "Number of Pages: " << database.num_pages_at(i) << endl;
}