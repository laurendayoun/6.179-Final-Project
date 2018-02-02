#include <iostream>
#include <map>
#include <time.h>
#include <string>
#include "Entry.cpp"

using namespace std;

class Journal
{
    private:
        map<Entry, string> entries;
    public: 
        Journal(map<Entry, string> m)
        {
            entries = m;
        }

        string get_timestamp()
        {
            time_t rawtime;
            struct tm * timeinfo;
            time ( &rawtime );
            timeinfo = localtime ( &rawtime );
            return asctime (timeinfo);
        }

        void create_entry(string title, string text, string password)
        {
            string ts = get_timestamp();
            Entry newentry = Entry(title, ts, text);
            entries.insert ( pair<Entry, string>(newentry,password) );
        }
        
        void create_user()
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
        
        string search_time(string ttime)  
        {
        // loops through map searching for match
            bool istrue = false;
            for (map<Entry, string>::iterator iter = entries.begin(); iter!= entries.end(); ++iter)
            {
                Entry e = iter->first;
                if (e.get_month() == ttime.substr(0,3) && e.get_year() == ttime.substr(-4,4) && e.get_day() == ttime.substr(3,2)) {
                cout << e.getTitle();
                istrue = true;
                }
            }
            if (!istrue)
            {
                cout << "No journal entry from that time exists.\n";
            }
        }

        string search_title(string title)
        {
            bool istrue = false;
            for (map<Entry, string>::iterator iter = entries.begin(); iter!= entries.end(); ++iter)
            {
                Entry e = iter->first;
                if (e.getTitle() == title) 
                {
                    cout << "What is your password? \n";
                    string pswd;
                    cin >> pswd;
                    string comp = iter->second;
                    if (comp == pswd)
                    {
                       cout<< e.getText();
                    }
                else
                {
                    cout << "Incorrect password.\n";
                }
                }
            } 

            if(!istrue)
            {
                cout << "There are no entries with the title " << title << ".\n";
            } 
        }
        
        void return_entries(string password)
        {
            bool istrue = false;
            for(map<Entry, string>::iterator iter = entries.begin(); iter!= entries.end(); ++iter)
            {
                Entry e = iter->first;
                string comp = iter->second;
                if(comp == password)
                {
                    cout << e.getTitle() << "\n";
                    istrue = true;
                }
            }
            if (!istrue)
            {
                cout << "There are no entries with the password " << password << ".\n";
            }
        }

        void return_year(string year)
        {
            bool istrue = false;
            for(map<Entry, string>::iterator iter = entries.begin(); iter!= entries.end(); ++iter)
            {
                Entry e = iter->first;
                if(e.get_year() == year)
                {
                    cout << e.getTitle() << "\n";
                    istrue = true;
                }
            }
            if (!istrue)
            {
                cout << "There are no entries from " << year << ".\n";
            }
        }

        void return_month(string month, string year)
        {
            bool istrue = false;
            for(map<Entry, string>::iterator iter = entries.begin(); iter!= entries.end(); ++iter)
            {
                Entry e = iter->first;
                if(e.get_year() == year && e.get_month() == month)
                {
                    cout << e.getTitle() << "\n";
                    istrue = true;
                }
            }
            if (!istrue)
            {
                cout << "There are no entries from " << month << " " << year << ".\n";
            }
        }
        
        void return_day_of_week(string dayofweek)
        {
            bool istrue = false;
            for(map<Entry, string>::iterator iter = entries.begin(); iter!= entries.end(); ++iter)
            {
                Entry e = iter->first;
                if(e.get_dayofweek() == dayofweek)
                {
                    cout << e.getTitle() << "\n";
                    istrue = true;
                }
            }

            if(!istrue)
            {
                cout << "There are no entries from " << dayofweek << " " << ".\n";
            }
        }

        void print_text(Entry e)
        {
            cout << e.getText();
        }
  
};



//Format: Wed Feb 13 15:46:11 2013
