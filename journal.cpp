#include <iostream>
#include <map>
#include <time.h>
#include <string>

using namespace std;

class Entry
{
	public: 
		Entry(string title, string timestamp, string text);
		string getTitle();
		string getTime();
		string getText();
		string get_month();
		string get_year();
    string get_dayofweek();
    string get_day();
	private:
		string m_title;
		string m_timestamp;
		string m_text;
};

Entry::Entry(string title, string timestamp, string text) {
	m_title = title;
	m_timestamp = timestamp;
	m_text = text;
}

string Entry::getTitle() {
	return m_title;
}

string Entry::getTime(){
  return m_timestamp;
}

string Entry::getText(){
  return m_text;
}

string Entry::get_month()
{
  return m_timestamp.substr(4,3);
}

string Entry::get_year()
{
  return m_timestamp.substr(-4, 4);
}

string Entry::get_dayofweek()
{
  return m_timestamp.substr(0, 3);
}

string Entry::get_day()
{
  return m_timestamp.substr(8,2);
}

class Journal
{
  public: 
	  Journal(map<Entry, string> entries);
		string get_timestamp();
    void create_entry(string, string, string);
    void create_user();
    string search_time(string, string, string);
    string search_title(string);
    void return_entries(string);
    void return_year(string);
    void return_month(string, string);
    void return_day_of_week(string);
    void print_text(Entry);
  private:
    map<Entry, string> entries;
};

Journal::Journal(map<Entry, string> m)
{
  entries = m;
}

//Format: Wed Feb 13 15:46:11 2013
string Journal::get_timestamp()
{
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  return asctime (timeinfo);
}

void Journal::create_entry(string title, string text, string password)
{
  string ts = get_timestamp();
  Entry newentry = Entry(title, ts, text);
  entries.insert ( pair<Entry, string>(newentry,password) );
}
  
void Journal::create_user()
{
  string password, title, text;
  cout << "What would you like your password to be? \n";
  cin >> password;
  cout << "Please enter the title of your new entry.";
  cin >> title;
  cout << "Please enter your text:";
  cin >> text;
  create_entry(title, text, password);
}
  
string Journal::search_time(string day, string month, string year)  
{
  // loops through map searching for match
  for (map<Entry, string>::iterator iter = entries.begin(); iter!= entries.end(); ++iter)
  {
    Entry e = iter->first;
    if (e.get_month() == month && e.get_year() == year && e.get_day() == day) {
      cout << e.getTitle();
    }
  }
    // if match != NULL && password = password
    // {
      
    // }
    // prompt password if found
    // return text if match
}

string Journal::search_title(string title)
{
  // loops through map searching for match
  // prompt password if found
  // return text if match
}
  
void Journal::return_entries(string password)
{
  for(map<Entry, string>::iterator iter = entries.begin(); iter!= entries.end(); ++iter)
  {
    Entry e = iter->first;
    if(entries[e] == password)
    {
      cout << e.getTitle() << "\n";
    }
  }
}

void Journal::return_year(string year)
{
  //print entries from year
}

void Journal::return_month(string month, string year)
{
  //print entries from specific month and year
}
  
void Journal::return_day_of_week(string dayofweek)
{
  // loops through map searching for match
  //if fount print entry title
}

void Journal::print_text(Entry e)
{
  cout << e.getText();
}

int main(int argc, char *argv[])
{
  map<Entry, string> m;
  Journal J(m);
  char returning;
  cout << "Are you a returning user? Type 'y' or 'n':";
  cin >> returning;
  //string input;
  //cout << "Please enter your password:";
  //cin >> input;
  //if(pass != password) check if the string is same as password: if not, return
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
      cout << "Day (press enter if unsure):";
      cin >> day;
      cout << "Month (press enter if unsure):";
      cin >> month;
      month = month.substr(0, 3);
      cout << "Year (press enter if unsure):";
      cin >> year;

      J.search_time(day,month,year);
    }
  }
}