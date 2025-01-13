//Megan Jen
//Algorithm Course Project

#include<fstream>
#include<limits>
#include<iostream>
#include<cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
void remove(std::vector<string>& v)
{
                auto end = v.end();
                for (auto it = v.begin(); it != end; ++it) {
                                end = std::remove(it + 1, end, *it);
                }
                v.erase(end, v.end());
}

class BookList {
public:
                string title;
                string author;
                string publisher;
                string publicationDate;
                string category;
};

string book1[1];

int main() {
                string column;
                string line;
                vector<BookList> BookVector;
    		int num = 0;
                BookList Book;

    //Just realized that the date is actually a string so...

                ifstream list("booklist.csv");
//                list.open("booklist.csv");

                if (!list.is_open()) std::cout << "ERROR: File Open" << '\n';
                while (!list.eof()) {
                           getline(list, line);
//                           cout << line << endl;
                           stringstream s_stream(line);
                           while(s_stream.good()) {
                                getline(s_stream, Book.title, ','); //get first string delimited by comma
                                getline(s_stream, Book.author, ','); //get first string delimited by comma
                                getline(s_stream, Book.publisher, ','); //get first string delimited by comma
                                getline(s_stream, Book.publicationDate, ','); //get first string delimited by comma
                                getline(s_stream, Book.category, ','); //get first string delimited by comma
                                BookVector.push_back(Book);
                            }
                           for(int i = 0; i<BookVector.size(); i++) {    //print all splitted strings
                              cout << "title: " << BookVector.at(i).title << "***";
                              cout << "author: " << BookVector.at(i).author << "***";
                              cout << "publisher: " << BookVector.at(i).publisher << "***";
                              cout << "publicationDate: " <<  BookVector.at(i).publicationDate << "***";
                              cout << "category: " <<  BookVector.at(i).category << endl;
                               }

//                                cout << "test \n";
//                                list << column << '\n';
//                                cout << column << "\n";
//                                cout << book_string << "\n";

                //            list >> book1[num];

                //            ++num;
                }
                cout << book1[0];

    //I just need to getline column by column

                list.close();
}

