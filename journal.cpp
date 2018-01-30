#include <iostream>
#include <map>
#include <time.h>
#include <string>

class Entry(string title, string time, string text)
{
  
}

class Journal
{
  std::map<Entry, string> entries;
  int main(int argc, char *argv[])
  {
    
  } 
  
  void create_entry(string title, string text, string password)
  {
    // create an Entry object
    // gets timestamp --> string
    // add to the map
  }
  
  void create_user(string password)
  {
    // makes new entry
  }
  
  string search_time(string time)
  {
    // loops through map searching for match
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
    // loop through and if password matches, print title
  }
}
