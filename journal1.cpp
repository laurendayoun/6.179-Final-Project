#include <iostream>
#include <map>
#include <time.h>
#include <string>
#include "Journal.cpp"

using namespace std;


int main(int argc, char *argv[])
{
  map<Entry, string> m;
  Journal J(m);
  char task;
  cout << "What would you like to do today?\n";
  cout << "Type 'e' to start a new entry, or type 's' to search the existing entries.";
  cin >> task;
  while (task != 'e' && task != 's')
  {
    cout << "Invalid input, please enter 'e' or 's'.\n";
    cin >> task;
  }
    
  if (task == 'e')
  {
    string title;
    string text;
          
    cout << "Please enter the title of your new entry.";
    cin >> title;
    cout << "Please enter your text:";
    cin >> text;
    J.create_entry(title,text,text);
  }  
  else
  {
    char search_by;
    cout << "Type 't' to search by title, or 'd' to search by date.";
    cin >> search_by;
    while (search_by != 't' && search_by != 'd')
    {
      cout << "Invalid input, please enter 't' or 'd'.\n";
      cin >> search_by;
    }
        
    if (search_by == 't')
    {
      string key;
      cout << "Search titles by term:";
      cin >> key;
      J.search_title(key);
    }
    else
    {
      string day,month,year;
      cout << "Day (please enter in 2 digits):";
      cin >> day;
      cout << "Month:";
      cin >> month;
      cout << "Year:";
      cin >> year;
      month = month.substr(0, 3);
      string ttime = "";
      ttime.append(month);
      ttime.append(day);
      ttime.append(year);
      J.search_time(ttime);
    }
  }
}