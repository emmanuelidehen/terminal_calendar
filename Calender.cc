#include <iostream>
// #define CATCH_CONFIG_RUNNER
// #include "catch.hpp"
using namespace std;


int printyear();
string printmonth(int input);
int numOfDaysInAMonth (int m, bool leapyearornot);
void printdays(int monthnumber, int year);
// int month;
// int leapyearornot;
void printmonthnumbers(int m, int startingDay);
// int numposition;
int dayOfTheWeek(int year, int month, int day);
int monthconversion (int input);
bool isALeapYear(int year);
string centerFunction(string input, int width);



int main(){
    // int results = Catch::Session().run();
    int year;
    char space;
    int monthnumber;
    cout << "Please enter the month and year you wish to display (ex. 1-2016)" << endl;
    cin  >> monthnumber >>space>>year;
    printmonth(monthnumber);
    cout <<year<<endl;
    bool leapYear = isALeapYear(year);
    cout << boolalpha << leapYear<< endl;
    printdays(monthnumber,year);
    
    
    
    int numOfDaysInAMonthVariable= numOfDaysInAMonth(monthnumber,leapYear);
    
    int startingDay = (dayOfTheWeek(year,monthnumber,1));
    
    printmonthnumbers(numOfDaysInAMonthVariable, startingDay);
    // return results;
}


string printmonth(int input){
    string month;
    if (input == 1){
        month = "Janurary ";
    }
    
    if (input == 2){
        month = "Feburary ";
    
    }
    if (input == 3){
        month = "March ";
    }
    if (input == 4){
        month = "April ";
    }
    if (input == 5){
        month = "May ";
    } 
    if (input == 6){
        month = "June ";
    }
    if (input == 7){
        month = "July ";
    }    
    if (input == 8){
        month = " August ";
    }
    if (input == 9){
        month = "September ";
    }
    if (input == 10){
        month = "October ";
    }
    if (input == 11){
        month = "November ";
    }
    if (input == 12){
        month = "December ";
    }
    return month;
}


bool isALeapYear( int year ){

	if ( (year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
		return true;
	else
		return false;
}

int numOfDaysInAMonth (int m, bool leapyearornot)
{
    if (m == 1)
       return(31);
    else if (m == 2){
            if  (leapyearornot == false){
                return(28);
            }
            else{
                return(29);
            }
  
         }
    else if (m == 3)
         return(31);
    else if (m == 4)
         return(30);
    else if (m == 5)
         return(31);
    else if (m == 6)
         return(30);
    else if (m == 7)
         return(31);
    else if (m == 8)
        return(31);
    else if (m == 9)
        return(30);
    else if (m == 10)
        return(31);
    else if (m == 11)
        return(30);
    else if (m == 12)
        return(31);
    }


void printdays(int monthnumber,int year){
    int month;
    
    string monthline;
    monthline = centerFunction(printmonth(monthnumber) +to_string(year),21);
    cout<<monthline<<endl;
    
    // cout<<"   "<<printmonth(monthnumber)<<year<<"         "<<endl;string centerFunction(string input, int width);center
    cout<<" Su"<<" "<<"Mo"<<" "<<"Tu"<<" "<<"We"<<" "<<"Th"<<" "<<"Fr"<<" "<<"Sa"<<endl;
    return;
}

void printmonthnumbers(int m, int startingDay){
    
    
     
    int numposition=startingDay;
    
    
    for (int i = 0; i < startingDay; i++)
    {
        cout << "   ";
    }
    
    
    for(int j=1; j<=m; j++)               //loop from 0 to 14,
    {
        
        cout << " "; 
                   //displaying the square of j
        
        if (j < 10)
        {
            cout << " ";
        }
        cout << j ; 
        if (numposition >= 6)
        {
            cout << endl;
            numposition = 0;
        } else {
        numposition ++;
        }
        

    }
}

int dayOfTheWeek(int yearIn, int monthIn, int dayIn)
{
  int year = yearIn;
  int month = monthIn;
  int day = dayIn;

  if (month == 1 || month ==2){
      
      year--; 
      
  }
  month = monthconversion(month);
  int d = (year % 100);
  int answerpartone;
  int answerparttwo;
  int century = year/100;
  
  answerpartone = day+(((13*month)-1)/5)+(d)+(d/4)+(century/4)-(2*century);
  answerparttwo = (answerpartone+49)  %7;
   return answerparttwo;
}




int monthconversion (int input){
    
    if (input ==2){
        return 12;
    }
        
    if (input ==1){
        return 11;
    }
    
    return input-2;
}

string centerFunction(string input, int width)
{
    string a = input;
    while (true)
    {
        // add space to the left
        a=" "+a;
        
        // if size of string >= width
        if (a.length() >= width)
        {
            return a;
        }
        // add space to the left
        
        a=a+" ";
        
        // if size of string >= width
        if (a.length() >= width)
        {
            return a;
        }
         
    }

}