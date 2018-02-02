
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
    
        void addEntry(string title, string text) {
            arr[m_count].m_title = title;
            arr[m_count].m_text = text;
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
    
        void printEntries() {
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
            
        };
        string m_user;
        Entry *arr;
        int m_count;
    
};

int main() {
    string user = "Grg";
    Journal diary(user);
    diary.addEntry("Finding Nemo", "Once upon a time...");
    cout << diary.numEntries() << endl;
    diary.printEntries();
    if (diary.searchTitle("Finding Nemo"))
        cout << "Found"<< endl;
    else
        cout << "Not found" << endl;
    diary.deleteEntry("Finding Nemo");
    cout << diary.numEntries() << endl;
    if (diary.searchTitle("Finding Nemo"))
        cout << "Found"<< endl;
    else
        cout << "Not found" << endl;
    
}
