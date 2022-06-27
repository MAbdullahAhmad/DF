#ifndef MENU_H
#define MENU_H

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
      init();
    }

    // MenuItem without Function
    MenuItem(
      string label,
      string menu_name
    ){
      init(label, menu_name);
    }

    // MenuItem with Function
    MenuItem(
      string label,
      string menu_name,
      function<void()> action
    ){
      init(label, menu_name, action);
    }

    // MenuItem without Function and User Provided Activity
    MenuItem(
      bool active,
      string label,
      string menu_name
    ){
      init(active, label, menu_name);
    }

    // MenuItem with Function and User Provided Activity
    MenuItem(
      bool active,
      string label,
      string menu_name,
      function<void()> action
    ){
      init(active, label, menu_name, action);
    }

    // MenuItem with Function and  User Provided Functionality
    MenuItem(
      string label,
      string menu_name,
      function<void()> action,
      bool functional
    ){
      init(label, menu_name, action, functional);
    }

    // MenuItem with Function and  User Provided Activity & Functionality both
    MenuItem(
      bool active,
      string label,
      string menu_name,
      function<void()> action,
      bool functional
    ){
      init(active, label, menu_name, action, functional);
    }

    //> Initializers
    void init(){
      this->active = true;
      this->functional = false;
      this->label = "";
      this->menu_name = "";
    }
    void init(
      string label,
      string menu_name
    ){
      this->active = true;
      this->functional = false;
      this->label = label;
      this->menu_name = menu_name;
      this->action = action;
    }
    void init(
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
    void init(
      bool active,
      string label,
      string menu_name
    ){
      this->active = active;
      this->functional = true;
      this->label = label;
      this->menu_name = menu_name;
    }
    void init(
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
    void init(
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
    void init(
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
};

class Menu{
  private:
    // Menu Configuration
    bool power;
    bool menu_prefix;                  // in `Menu : <menu_name>`, show `Menu : ` or not
    bool exit_enabled;                 // We Need `Exit` or not
    string menu_name;                  // name of menu
    MenuItem* items; int items_length; // A for Accounts, B for Books, etc...
    MenuItem exit;
  
    // Helpers
    void put_items(MenuItem* items, int items_length){
      // Make Space
      this->items_length = items_length;
      this->items = new MenuItem[this->items_length];

      // Put
      for(int i=0; i<this->items_length; i++){
        this->items[i] = items[i];
      }
    }
  
  public:
    //> Constructors

    // Default
    Menu(){
      this->power =
      this->menu_prefix =
      this->exit_enabled =
      true;
      
      this->items_length = 0;
      this->menu_name = "Default Menu";

      // Default Exit
      this->exit.init("E", "Exit");
      this->exit.set_action(this->stop_menu);
    }

    // Menu Name and Items
    Menu(
      string menu_name,
      MenuItem* items,
      int items_length
    ){
      this->power =
      this->menu_prefix =
      this->exit_enabled =
      true;

      this->menu_name = menu_name;
      this->put_items(items, items_length);

      // Default Exit
      this->exit.init("E", "Exit");
      this->exit.set_action(this->stop_menu);
    }

    // Menu Name and Items (with specified prefix bool)
    Menu(
      string menu_name,
      bool menu_prefix,
      MenuItem* items,
      int items_length
    ){
      this->power =
      this->exit_enabled =
      true;

      this->menu_prefix = menu_prefix;
      this->menu_name = menu_name;
      this->put_items(items, items_length);

      // Default Exit
      this->exit.init("E", "Exit");
      this->exit.set_action(this->stop_menu);
    }

    // Menu Name, Items And Exit
    Menu(
      string menu_name,
      bool menu_prefix,
      MenuItem* items,
      int items_length,
      MenuItem exit
    ){
      this->power =
      this->menu_prefix =
      this->exit_enabled =
      true;
      
      this->menu_name = menu_name;
      this->put_items(items, items_length);

      this->exit = exit;
      this->exit.set_action(this->stop_menu);
    }

    // Menu Name, Items And Exit Enable
    Menu(
      string menu_name,
      bool menu_prefix,
      MenuItem* items,
      int items_length,
      bool exit_enabled
    ){
      this->power =
      this->menu_prefix =
      true;
      this->exit_enabled = exit_enabled;
      
      this->menu_name = menu_name;
      this->put_items(items, items_length);

      if(this->exit_enabled)
      this->exit.init("E", "Exit");
      this->exit.set_action(this->stop_menu);
      this->exit.set_action(this->stop_menu);
    }

    // Menu Name, Items and Exit (with specified prefix bool)
    Menu(
      bool menu_prefix,
      string menu_name,
      MenuItem* items,
      int items_length,
      MenuItem exit
    ){
      this->power =
      this->exit_enabled =
      true;

      this->menu_prefix = menu_prefix;
      this->menu_name = menu_name;
      this->put_items(items, items_length);

      this->exit.init("E", "Exit");
      this->exit.set_action(this->stop_menu);
    }


    // Menu Name, Items and Exit Enable (with specified prefix bool)
    Menu(
      bool menu_prefix,
      string menu_name,
      MenuItem* items,
      int items_length,
      bool exit_enabled
    ){
      this->power = true;
      this->exit_enabled =exit_enabled;
      this->menu_prefix = menu_prefix;

      this->menu_name = menu_name;
      this->put_items(items, items_length);

      if(this->exit_enabled)
      this->exit.init("E", "Exit");
      this->exit.set_action(this->stop_menu);
    }

    //> Config Setters

    // Enable Power
    void enable_power(bool power){
      this->power = power;
    }

    // Enable Menu Prefix
    void enable_menu_prefix(bool menu_prefix){
      this->menu_prefix = menu_prefix;
    }

    // Enable Exit
    void enable_exit(bool enable){
      this->exit_enabled = enable;
    }

    //> Setters

    // Set Menu-Name
    void set_menu_name(string name){
      this->menu_name = name;
    }

    // Set Items
    void set_items(
      MenuItem* items,
      int items_length
    ){
      put_items(items, items_length);
    }

    // Set Exit
    void set_items(
      MenuItem exit
    ){
      this->exit = exit;
      this->exit.set_action(this->stop_menu);
    }

    // Stop Menu
    void stop_menu(){
      this->power = false;
    }
};

#endif