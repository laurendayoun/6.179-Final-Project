#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_MAX_ITEMS = 200;

class Journal {
    public:
        Journal(string user)
        :m_user(user)
        {
            m_count = 0;
            arr = new Entry[DEFAULT_MAX_ITEMS];
        }
    
        // you need a destructor to delete the array!!!!
    
        void addEntry(string title, string text, string timestp, string pswd) {
            arr[m_count].m_title = title;
            arr[m_count].m_text = text;
            arr[m_count].m_timestamp = timestp;
            arr[m_count].m_password = pswd;
            m_count++;
        }
        
        bool deleteEntry(string title) {
            if (!searchTitle(title))
                return false;
            int i;
            for (i = 0; i < m_count; i++) {
                if (arr[i].m_title == title) {
                    arr[i].m_title = "";
                }
            }
            for (; i < m_count - 1; i++) {
                arr[i] = arr[i+1];
            }
            m_count--;
            return true;
        }
    
        bool searchTitle(string title) {
            for (int i = 0; i < m_count; i++) {
                if (arr[i].m_title == title)
                    return true;
            }
            return false;
        }

        bool searchTime(string timestr) {
            for (int i = 0; i < m_count; i++) {
                if (arr[i].m_timestamp == timestr)
                    return true;
            }
            return false;
        }

        string getPassword(int ind)
        {
            return arr[ind].m_password;
        }

        string getText(int ind)
        {
            return arr[ind].m_text;
        }

        int searchNumTitle(string title)
        {
            for (int i = 0; i < m_count; i++) {
                if (arr[i].m_title == title)
                    return i;
            }
        }

        int searchNumTime(string timestr)
        {
            for (int i = 0; i < m_count; i++) {
                if (arr[i].m_timestamp == timestr)
                    return i;
            }
        }
    
        void printEntries() 
        {
            for (int i = 0; i < m_count; i++) {
                cout << "Entry #" << i+1 << endl;
                cout << "Title: " << arr[i].m_title << endl;
                // idk what to do about text
            }
        }
    
        int numEntries() {
            return m_count;
        }
    
    private:
        struct Entry {
            public:
                string m_title;
                string m_timestamp;
                string m_text;
                string m_password;
            
        };
        string m_user;
        Entry *arr;
        int m_count;
        
    
};

int main() {
    string user = "Default";
    Journal diary(user);
    
    int keepRunning = 1;
    
    while (keepRunning == 1) {
        char task;
        cout << "What would you like to do today?\n";
        cout << "Type 'e' to start a new entry, type 's' to search the existing entries, type 'd' to delete an existing entry, or 'z' to exit.\n";
        cin >> task;
        while (task != 'e' && task != 's' && task != 'd' && task != 'z')
        {
          cout << task;
          cout << "Invalid input, please enter 'e', 'd', 's', or 'z'.\n";
          cin >> task;
        }
        
        if (task == 'e')
        {
            string title, text, timest, pasw;   
            
            cout << "Please enter the title of your new entry.\n";
            cin.ignore();
            std::getline (std::cin,title);
            // cin >> title;
            
            cout << "Please enter your text:\n";
            //cin.ignore();
            std::getline (std::cin,text);
            //cin >> text;
            
            cout << "Please enter the date in Month-Day-Year format. No spaces, only dashes.\n";
            //cin.ignore();
            std::getline (std::cin,timest);
            // cin >> timest;
            
            cout << "Please enter your desired password for this entry (no spaces). \n";
            //cin.ignore();
            //std::getline (std::cin,pasw);
            cin >> pasw;
    
            diary.addEntry(title,text,timest,pasw);
            cout << "New entry added!\n";
        }  
        else if(task == 'd')
        {
            string title;
            cout << "Please enter the title of the entry you want to delete.\n";
            cin.ignore();
            std::getline (std::cin,title);
            //cin >> title;
            
            cout << diary.searchTitle(title);
            cout << "\n";
            diary.deleteEntry(title);
            cout << "Entry deleted. \n";
        }
        else if (task == 's')
        {
            char search_by;
            cout << "Type 't' to search by title, or 'd' to search by date.\n";
            cin >> search_by;
            while (search_by != 't' && search_by != 'd')
            {
                cout << "Invalid input, please enter 't' or 'd'.\n";
                cin >> search_by;
            }
            
            if (search_by == 't')
            {
                string key;
                cout << "Search by title: \n";
                cin.ignore();
                std::getline (std::cin,key);
                //cin >> key;
                if (diary.searchTitle(key))
                {
                    int i = diary.searchNumTitle(key);
                    string pswd;
                    cout << "What is your password?\n";
                    cin >> pswd;
                    while(diary.getPassword(i) != pswd)
                    {
                        cout<< "Incorrect password, please try again.\n";
                        cin >> pswd;
                    }
                    cout << "Here is your entry:\n";
                    cout << diary.getText(i);
                    cout << "\n";
                    
                }
    
                else
                {
                    cout << "Not found" << endl;
                }
            }
            else
            {
                string monthdayyear;
                cout << "Please enter the day you are looking for in Month-Day-Year format:\n";
                cin.ignore();
                std::getline (std::cin,monthdayyear);

                if(diary.searchTime(monthdayyear))
                {
                    int i = diary.searchNumTime(monthdayyear);
                    string pswd;
                    cout << "What is your password?\n";
                    cin >> pswd;
                    while (diary.getPassword(i) != pswd)
                    {
                        cout<< "Incorrect password, please try again.\n";
                        cin >> pswd;
                    }
                    cout << diary.getText(i);
                    cout << "\n";
                }
            }
      }
      else if (task == 'z') {
        return 0;         
      }
      
    }
    

    
}