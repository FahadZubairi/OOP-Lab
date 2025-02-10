// Create a class called Book to represent a book. A Book should include four pieces of information as instance
// variables‐a book name, an ISBN number, an author name and a publisher. Provide methods (query method) for
// each instance variable. Inaddition, provide a method named getBookInfo that returns the description of the book
// as a String (the description should include all the information about the book). You should use this keyword in
// member methods and constructor. Write a test application named BookTest to create an array of object for 5
// elements for class Book to demonstrate the class Book&#39;s capabilities.

#include<iostream>
using namespace std;
class Book{
public:
    string BookName;
    int ISBN_number;
    string AuthorName;
    string Publisher;
    
Book() {
    this->BookName = "";
    this->ISBN_number = 0;
    this->AuthorName = "";
    this->Publisher = "";
}

Book(string bname, int isbn, string author, string pub) {
    this->BookName = bname;
    this->ISBN_number = isbn;
    this->AuthorName = author;
    this->Publisher = pub;
}

string GetBookinfo() {
    return "Book Name: " + this->BookName + 
           "\nISBN: " + to_string(this->ISBN_number) + 
           "\nAuthor: " + this->AuthorName + 
           "\nPublisher: " + this->Publisher + "\n";
}

};
int main(){
    Book book[5];
    for (int i =0;i<5;i++){
        cin.ignore();
        cout<<"Enter Book "<<i+1<<" Details: ";
        cout << "Book Name: ";
        getline(cin, book[i].BookName);

        cout << "ISBN Number: ";
        cin>>book[i].ISBN_number;

        cout << "Author Name: ";
        getline(cin, book[i].AuthorName);

        cout << "Publisher: ";
        getline(cin, book[i].Publisher);
    }
    for (int i=0;i<5;i++){
        cout<<book[i].GetBookinfo()<<endl;
    }
    return 0;
}