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
    std::string month = timeinfo.subsrt(4, 3);
    return month;
  }

  string get_year(string timeinfo)
  {
    std::string year = timeinfo.substr(-4, 4);
  }

  string get_dayofweek(timeinfo)
  {
    std::string day = timeinfo.substr(0, 3);
    return day;
  }
  
  void create_entry(string title, string text, string password)
  {
    Entry newentry;
    //get ts = timestamp
    newentry.set_values(title, ts, text);
    entries.insert ( std::pair<Entry,string>(newentry,password) );
  }
  
  void create_user(string password)
  {
    //prompt desired password
    //prompt title, text
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
        cout << e.get_title();
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
}
