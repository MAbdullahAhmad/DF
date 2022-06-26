#ifndef MENU_H
#define MENU_H

#include "iostream"

using namespace std;

class Menu{
  private:
    // Menu Configuration
    bool menu_prefix;                 // in `Menu : <menu_name>`, show `Menu : ` or not
    string menu_name;                 // name of menu
    string* labels; int labels_size;  // A, P etc.
    string* items; int items_size;    // Accounts, Profile etc.
    string exit_label;                // set exit label. set "" if do not want exit
    string exit;                      // set exit item
  
  protected:
  
  public:
    //> Constructors

    // Default
    Menu(){
      this->items_size =
      this->labels_size =
      0;

      this->menu_prefix = true;
      this->menu_name = "Default Menu";
      this->exit_label = "E";
      this->exit = "Exit";
    }

    // Menu Name and Items
    Menu(
      string menu_name,
      string* labels, int labels_size,
      string* items, int items_size
    ){
      this->menu_name = menu_name;
      this->menu_prefix = true; // Default
      
      this->labels = labels;
      this->labels_size = labels_size;
      
      this->items = items;
      this->items_size = items_size;

      // Default for Exit
      this->exit_label = "E";
      this->exit = "Exit";
    }

    // Menu Name and Items (with specified prefix bool)
    Menu(
      string menu_name,
      bool menu_prefix,
      string* labels, int labels_size,
      string* items, int items_size
    ){
      this->menu_name = menu_name;
      this->menu_prefix = menu_prefix;
      
      this->labels = labels;
      this->labels_size = labels_size;
      
      this->items = items;
      this->items_size = items_size;

      // Default for Exit
      this->exit_label = "E";
      this->exit = "Exit";
    }

    // Menu Name, Items And Exit
    Menu(
      string menu_name,
      string* labels, int labels_size,
      string* items, int items_size,
      string exit_label, string exit_item
    ){
      this->menu_name = menu_name;
      this->menu_prefix = true; // Default
      
      this->labels = labels;
      this->labels_size = labels_size;
      
      this->items = items;
      this->items_size = items_size;

      this->exit_label = exit_label;
      this->exit = exit_item;
    }

    // Menu Name, Items and Exit (with specified prefix bool)
    Menu(
      string menu_name,
      bool menu_prefix,
      string* labels, int labels_size,
      string* items, int items_size,
      string exit_label, string exit_item
    ){
      this->menu_name = menu_name;
      this->menu_prefix = menu_prefix;
      
      this->labels = labels;
      this->labels_size = labels_size;
      
      this->items = items;
      this->items_size = items_size;

      this->exit_label = exit_label;
      this->exit = exit_item;
    }

    //> Setters

    // Set Menu-Name
    void set_menu_name(string name){
      this->menu_name = name;
    }

    // Set Labels
    void set_labels(
      string* labels,
      int size
    ){
      this->labels = labels;
      this->labels_size = size;
    }

    // Set Items
    void set_items(
      string* items,
      int size
    ){
      this->items = items;
      this->items_size = size;
    }

    // Set Exit
    void set_exit(
      string label,
      string item
    ){
      this->exit_label = label;
      this->exit = item;
    }

    // Getter
};

#endif

/*
  class Menu:

    | - what are items and labels ?
    | > In a menu as follow
    |  
    |   A for Accounts
    |   B for Boxes
    |   C for Cats
    |   D for Drag
    |   
    |   A, B, C, D are `labels`
    |   Accounts, Boxes, Cats, Drag are `items`

*/