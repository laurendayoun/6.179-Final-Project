#include <iostream>
#include <map>
#include <time.h>
#include <string>

class Entry
{
  std::string title, timestamp, text;
  public:
    void set_values(std::string, std::string, std::string);
    std::string get_title(){return title;}
    std::string get_time(){return timestamp;}
    std::string get_text(){return text;}
};

void Entry::set_values(std::string t1, std::string ts, std::string tx){
  title = t1;
  timestamp = ts;
  text = tx;
}

class Journal
{
  std::map<Entry, std::string> entries;
    
  int main(int argc, char *argv[])
  {
      char returning;
      std::cout << "Are you a returning user? Type 'y' or 'n':";
      std::cin >> returning;
      std::string input;
      std::cout << "Please enter your password:";
      std::cin >> input;
      //if (pass != password) check if the string is same as password: if not, return
      
      char task;
      std::cout << "What would you like to do today?\n";
      std::cout << "Type 'e' to start a new entry, or type 's' to search the existing entries.";
      std::cin >> task;
      while (task != 'e' && task != 's')
      {
          std::cout << "Invalid input, please enter 'e' or 's'.\n";
          std::cin >> task;
      }
      
      if (task == 'e')
      {
          std::string title;
          std::string text;
          
          std::cout << "Please enter the title of your new entry.";
          std::cin >> title;
          std::cout << "Please enter your text:";
          std::cin >> text;
          Journal::create_entry(title,text,input);
      }
      else
      {
          char search_by;
          std::cout << "Type 't' to search by title, or 'd' to search by date.";
          std::cin >> search_by;
          while (search_by != 't' && search_by != 'd')
          {
              std::cout << "Invalid input, please enter 't' or 'd'.\n";
              std::cin >> search_by;
          }
          
          if (search_by == 't')
          {
              char key;
              std::cout << "Search titles by term:";
              std::cin >> key;
              Journal::search_title(key);
          }
          else
          {
              std::string day,month,year;
              std::cout << "Day (press enter if unsure):";
              std::cin >> day;
              std::cout << "Month (press enter if unsure):";
              std::cin >> month.substr(0,3);
              std::cout << "Year (press enter if unsure):";
              std::cin >> year;
              Journal::search_time(day,month,year);
          }
      }
  } 

  std::string get_timestamp() const
  {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return asctime (timeinfo);
  }

  //Format: Wed Feb 13 15:46:11 2013

  std::string get_month(std::string timeinfo) const
  {
    std::string month = timeinfo.substr(4, 3);
    return month;
  }

  std::string get_year(std::string timeinfo) const
  {
    std::string year = timeinfo.substr(-4, 4);
    return year;
  }

  std::string get_dayofweek(std::string timeinfo) const
  {
    std::string day = timeinfo.substr(0, 3);
    return day;
  }
  
  void create_entry(std::string title, std::string text, std::string password)
  {
    Entry newentry;
    std::string ts = get_timestamp();
    newentry.set_values(title, ts, text);
    entries.insert ( std::pair<Entry, std::string>(newentry,password) );
  }
  
  void create_user()
  {
    std::string password, title, text;
    std::cout << "What would you like your password to be? \n";
    std::cin >> password;
    std::cout << "Please enter the title of your new entry.";
    std::cin >> title;
    std::cout << "Please enter your text:";
    std::cin >> text;
    create_entry(title, text, password);
  }
  
  std::string search_time(std::string time) const
  {
    Entry match;
    // loops through map searching for match
    for (int it=entries.begin(); it!=entries.end(); ++it) {
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

  std::string search_title(std::string title) const
  {
    // loops through map searching for match
    // prompt password if found
    // return text if match
  }
  
  void return_entries(std::string password) const
  {
    for(Entry e : entries){
      if(entries[e] == password)
      {
        std::cout << e.get_title() << "\n";
      }
    }
  };

  void return_year(std::string year) const
  {
    //print entries from year
  }

  void return_month(std::string month, std::string year) const
  {
    //print entries from specific month and year
  }
  
  void return_day_of_week(std::string dayofweek) const
  {
    // loops through map searching for match
    //if fount print entry title
  }

  void print_text(Entry e) const
  {
    std::cout << e.get_text();
  }
};
