#include <iostream>
#include <map>
#include <time.h>
#include <string>

class Entry(string title, string timestamp, string text)
{
  string title, timestamp, text;
  public:
    void set_values(string, string, string);
    string get_title(){return title;}
    string get_time(){return timestamp;}
    string get_text(){return text;}
  }
}

void Entry::set_values(string t1, string ts, string tx){
  title = t1;
  timestamp = ts;
  text = tx;
}

class Journal
{
  std::map<Entry, string> entries;
    
  int main(int argc, char *argv[])
  {
      char returning;
      cout << "Are you a returning user? Type 'y' or 'n':";
      cin >> returning;
      string input;
      cout << "Please enter your password:";
      cin >> input;
      //if (pass != password) check if the string is same as password: if not, return
      
      char task;
      cout << "What would you like to do today?\n";
      cout << "Type 'e' to start a new entry, or type 's' to search the existing entries.";
      cin >> task;
      while (task != 'e' && task != 's')
      {
          cout << "Invalid input, please enter 'e' or 's'.\n"
          cin >> task;
      }
      
      if (task == 'e')
      {
          std::string title;
          std::string text;
          
          cout << "Please enter the title of your new entry.";
          std::cin >> title;
          cout << "Please enter your text:";
          std::cin >> text;
          create_entry(title,text,input);
      }
      else
      {
          char search_by;
          cout << "Type 't' to search by title, or 'd' to search by date."
          cin >> search_by;
          while (search_by != 't' && payrollType != 'd')
          {
              cout << "Invalid input, please enter 't' or 'd'.\n";
              cin >> search_by;
          }
          
          if (search_by == 't')
          {
              char key;
              cout << "Search titles by term:";
              cin >> key;
              search_title(key);
          }
          else
          {
              std::string day,month,year;
              cout << "Day (press enter if unsure):";
              std::cin >> day;
              cout << "Month (press enter if unsure):";
              std::cin >> month.substr(0,3);
              cout << "Year (press enter if unsure):";
              std::cin >> year;
              search_time(day,month,year);
          }
      }
  } 

  string get_timestamp(){
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return asctime (timeinfo);
  }

  //Format: Wed Feb 13 15:46:11 2013

  string get_month(string timeinfo)
  {
    std::string month = timeinfo.substr(4, 3);
    return month;
  }

  string get_year(string timeinfo)
  {
    std::string year = timeinfo.substr(-4, 4);
    return year;
  }

  string get_dayofweek(timeinfo)
  {
    std::string day = timeinfo.substr(0, 3);
    return day;
  }
  
  void create_entry(string title, string text, string password)
  {
    Entry newentry;
    std::string ts = get_timestamp();
    newentry.set_values(title, ts, text);
    entries.insert ( std::pair<Entry,string>(newentry,password) );
  }
  
  void create_user()
  {
    std::str password, title, text;
    cout << "What would you like your password to be? \n";
    cin >> password;
    cout << "Please enter the title of your new entry.";
    cin >> title;
    cout << "Please enter your text:";
    cin >> text;
    create_entry(title, text, password)
  }
  
  string search_time(string time)
  {
    Entry match;
    // loops through map searching for match
    for (it=mymap.begin(); it!=mymap.end(); ++it) {
      if (it.get_time() == time) {
        match.set_values(it.get_title(),it.get_timestamp(),it.get_text())
        std::cout << it->first << " => " << it->second << '\n'
      }
    }
    // if match != NULL && password = password
    // {
      
    // }
    // prompt password if found
    // return text if match
  }

  string search_title(string title)
  {
    // loops through map searching for match
    // prompt password if found
    // return text if match
  }
  
  void return_entries(string password)
  {
    for(entry e : entries){
      if(entries[e] == password;)
      {
        cout << e.get_title() << "\n";
      }
    }
  }

  void return_year(string year)
  {
    //print entries from year
  }

  void return_month(string month, string year)
  {
    //print entries from specific month and year
  }
  
  void return_day_of_week(string dayofweek)
  {
    // loops through map searching for match
    //if fount print entry title
  }

  void print_text(Entry e)
  {
    cout << e.get_text();
  }
}
