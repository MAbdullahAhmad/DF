#include "functional"
#include "iostream"

using namespace std;

// Global Menu Config
string menu_item_delim = " for ";

class MenuItem{
  private:
    // Props
    bool active;                  // This Menu-Item is disabled if it is false
    bool functional;              // Activates / De-Activates Function Execution
    string label;                 // Label (e.g. A)
    string menu_name;             // Command Name (e.g Accounts)
    function<void()> action;      // Action Function

  public:
    //> Constructors

    // Default Constructor
    MenuItem(){
      this->active = true;
      this->functional = false;
      this->label = "";
      this->menu_name = "";
    }

    // MenuItem without Function
    MenuItem(
      string label,
      string menu_name
    ){
      this->active = true;
      this->functional = false;
      this->label = label;
      this->menu_name = menu_name;
      this->action = action;
    }

    // MenuItem with Function
    MenuItem(
      string label,
      string menu_name,
      function<void()> action
    ){
      this->active = true;
      this->functional = true;
      this->label = label;
      this->menu_name = menu_name;
      this->action = action;
    }

    // MenuItem without Function and User Provided Activity
    MenuItem(
      bool active,
      string label,
      string menu_name
    ){
      this->active = active;
      this->functional = true;
      this->label = label;
      this->menu_name = menu_name;
    }

    // MenuItem with Function and User Provided Activity
    MenuItem(
      bool active,
      string label,
      string menu_name,
      function<void()> action
    ){
      this->active = active;
      this->functional = true;
      this->label = label;
      this->menu_name = menu_name;
      this->action = action;
    }

    // MenuItem with Function and  User Provided Functionality
    MenuItem(
      string label,
      string menu_name,
      function<void()> action,
      bool functional
    ){
      this->active = true;
      this->functional = functional;
      this->label = label;
      this->menu_name = menu_name;
      this->action = action;
    }

    // MenuItem with Function and  User Provided Activity & Functionality both
    MenuItem(
      bool active,
      string label,
      string menu_name,
      function<void()> action,
      bool functional
    ){
      this->active = active;
      this->functional = functional;
      this->label = label;
      this->menu_name = menu_name;
      this->action = action;
    }

    // Setters
    void set_activity(bool active){
      this->active = active;
    }
    void set_functionality(bool functional){
      this->functional = functional;
    }
    void set_label(string label){
      this->label = label;
    }
    void set_menu_name(string menu_name){
      this->menu_name = menu_name;
    }
    void set_action(function<void()> action){
      this->action = action;
    }

    //> Outputs

    // Base
    string row(int tab, bool custom_delim, string delim, bool new_line){
      string r = "";

      // Tabs
      for(int i=0; i<tab; i++) r += "\t";

      // Item
      r += this->label;
      r += (custom_delim ? delim : menu_item_delim);
      r += menu_name;

      // New Line
      if(new_line) r+= "\n";

      return r;
    }

    // Extension : Tab, Delim, NewLine
    string row(int tab, string delim, bool nl){
      return row(tab, true, delim, nl);
    }

    // Extension : Tab, Delim
    string row(int tab, string delim){
      return row(tab, delim, false);
    }

    // Extension : Tab, NewLine
    string row(int tab, bool nl){
      return row(tab, false, "", nl);
    }

    // Extension : Tab
    string row(int tab){
      return row(tab, true);
    }

    // Extension : Delim, NewLine
    string row(string delim, bool nl){
      return row(1, true, delim, nl);
    }

    // Extension : Delim
    string row(string delim){
      return row(delim, false);
    }

    // Extension : NewLine
    string row(bool nl){
      return row(1, false, "", nl);
    }

    // Extension : Defailt
    string row(){
      return row(1);
    }

    // Display Instead of Return (All Extensions of above row() methods)
    void print_row(int tab, bool custom_delim, string delim, bool new_line){
      row(tab, custom_delim, delim, new_line);
    }
    void print_row(int tab, string delim, bool nl){
      cout << row(tab, delim, nl);
    }
    void print_row(int tab, string delim){
      cout << row(tab, delim);
    }
    void print_row(int tab, bool nl){
      cout << row(tab, nl);
    }
    void print_row(int tab){
      cout << row(tab);
    }
    void print_row(string delim, bool nl){
      cout << row(delim, nl);
    }
    void print_row(string delim){
      cout << row(delim);
    }
    void print_row(bool nl){
      cout << row(nl);
    }
    void print_row(){
      cout << row();
    }
    friend ostream& operator<<(ostream& out, MenuItem& MI){
      out << "[MenuItem ";
      out << MI.label;
      out << menu_item_delim;
      out << MI.menu_name;
      out << " : ";
      out << (MI.active ? "Yes" : "No");
      out << ",";
      out << (MI.functional ? "Yes" : "No");
      out << "]";
      return out;
    }
};

int main()
{
  MenuItem MI("B","Books");
  cout << MI << '\n';
  return 0;
}