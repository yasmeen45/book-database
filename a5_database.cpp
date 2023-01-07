// a5_database.cpp

#include "a5.h"  
//vector <Book> records;

Database::Database() {}

void Database::read_database_file() {
    fstream file_in("database.txt");
	string line = "";

    while (getline(file_in, line)) {
        vector <string> v_data;
        string record = "";

        for(char ch : line) {
            if (ch == '|') {
                v_data.push_back(record);
                record = "";
            } else {
                record += ch;
            }
        }

        Book new_book(v_data.at(0), v_data.at(1), stoi(v_data.at(2)), v_data.at(3), stoi(v_data.at(4)));
        this->records.push_back(new_book);
    }
}

// getters:
int Database::get_size() const {
    return records.size();
}

Book Database::book_at(int i) const {
    return records.at(i);
}

string Database::name_at(int i) const {
    return records[i].get_name();
}

string Database::author_at(int i) const {
    return records[i].get_author();
}

int Database::year_at(int i) const {
    return records[i].get_year();
}

string Database::genre_at(int i) const {
    return records[i].get_genre();
}

int Database::num_pages_at(int i) const {
    return records[i].get_num_pages();
}

void Database::add_record(Book & book) {
    records.push_back(book);
}

void Database::delete_record_at(int i) {
    records.erase(records.begin() + i);
}

// sorting methodss

void Database::sort_name() {
    std::sort(records.begin(), records.end(),
            [](const Book a, const Book b) {
                return (a.get_name() < b.get_name());
            });
}

void Database::sort_author() {
    std::sort(records.begin(), records.end(),
            [](const Book a, const Book b) {
                return (a.get_author() < b.get_author());
            });
}

void Database::sort_genre() {
    std::sort(records.begin(), records.end(),
            [](const Book a, const Book b) {
                return (a.get_genre() < b.get_genre());
            });
}

void Database::sort_year() {
    std::sort(records.begin(), records.end(),
            [](const Book a, const Book b) {
                return (a.get_year() < b.get_year());
            });
}

void Database::sort_pages() {
    std::sort(records.begin(), records.end(),
            [](const Book a, const Book b) {
                return (a.get_num_pages() < b.get_num_pages());
            });
}

void Database::reverse_vec() {
    reverse(records.begin(), records.end());
}

void Database::save_records() {
	ofstream fileOut("database.txt");

	for (int i = 0; i < records.size(); i++) {
		fileOut << records[i].get_name() << "|";
        fileOut << records[i].get_author() << "|";
        fileOut << records[i].get_year() << "|";
        fileOut << records[i].get_genre() << "|";
        fileOut << records[i].get_num_pages() << "|";
        fileOut << endl;
	}

	fileOut.close();
}