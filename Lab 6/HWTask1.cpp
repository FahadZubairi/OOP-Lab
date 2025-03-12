#include<iostream>
#include<cstring>
using namespace std;
class Book{
    string Genre;
    public:
    Book(){
        Genre = "";
    }
    Book(string Genre){
        this->Genre = Genre;
    }
    void setGenre(string g){
        Genre = g;

    }
    string getGenre(){
        return Genre;
    }
};
class Novel: public Book{
    string title;
    string author;
    public:
    Novel(){
        title = "";
        author = "";
    }
    Novel(string t,string a,string Genre): Book(Genre), title(t), author(a) {};
    void setTitle(string t){
        title = t;
    }
    void setauthor(string a){
        author = a;
    }
    void ShowDetails(){
        cout<<"Book details: "<<endl;
        
        cout<<"Title: "<<title<<endl;
        
        cout<<"Author: "<<author<<endl;
        cout<<"Genre: "<<getGenre()<<endl;

    }
};
int main(){
    Novel novel;
    novel.setauthor("JK Rowling");
    novel.setTitle("Harry Potter");
    novel.setGenre("Novel");
    novel.ShowDetails();
}