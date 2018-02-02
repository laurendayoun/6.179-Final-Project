#include <iostream>
#include <map>
#include <time.h>
#include <string>

using namespace std;

class Entry
{
	public: 
		Entry(string, string, string);
		string getTitle();
		string getTime();
		string getText();
		string get_month();
		string get_year();
        string get_dayofweek();
        string get_day();
        bool operator==(Entry i) 
        {
            if (i.m_title==this->m_title && i.m_timestamp==this->m_timestamp &&i.m_text==this->m_text ) 
            {
                return true;
            } 
            else 
            {
                return false;
            }
        }
    private:
		string m_title;
		string m_timestamp;
		string m_text;
};

Entry(string title, string timestamp, string text) 
{
	m_title = title;
	m_timestamp = timestamp;
	m_text = text;
}

string getTitle() {
	return m_title;
}

string getTime(){
  return m_timestamp;
}

string getText(){
  return m_text;
}

string get_month()
{
  return m_timestamp.substr(4,3);
}

string get_year()
{
  return m_timestamp.substr(-4, 4);
}

string get_dayofweek()
{
  return m_timestamp.substr(0, 3);
}

string get_day()
{
  return m_timestamp.substr(8,2);
}