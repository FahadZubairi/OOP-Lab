// Create a class called Date that includes three pieces of information as instance variables—a month (typeint), a day
// (typeint) and a year (typeint). Provide a method displayDate that displays the month, day and year separated by
// forward slashes(/). Write a test application named DateTest that demonstrates classDate’s capabilities.
#include<iostream>
using namespace std;
class Date{
    public:
    int month;
    int day;
    int year;
    
    void DisplayDate(){
        cout<<month<<"/"<<day<<"/"<<year;
    }
};
int main(){
    Date date;
    cout<<"Enter the Month, Day and Year: "<<endl;
    cin>>date.month >>date.day >>date.year; 
    date.DisplayDate();
}