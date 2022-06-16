#ifndef OUTPUT_MANAGER_H
#define OUTPUT_MANAGER_H

#include "iostream"
#include "Menu.h"
#include "../libs/animate.h"
#include "../libs/string_lib.h"

using namespace std;

class BoxManager{
  private:
    int
      box_width,
      initial_spaces,
      inner_padding;

    // Helpers
    void hf_mutual(char c){
      repeat_chr(' ', initial_spaces);
      cout << c;
      repeat_chr('_', box_width);
      cout << c << "\n";
    }

  public:
    // Constructors
    BoxManager(){ box_width = initial_spaces = inner_padding = 0; }
    BoxManager(
      int bw, int is, int ip
    ){
      box_width = bw;
      initial_spaces = is;      
      inner_padding = ip;
    }

    // Draw Methods
    void draw_header(){
      hf_mutual(',');
    }
    void draw_footer(){
      hf_mutual('|');
    }
    void draw_row(){
      repeat_chr(' ', initial_spaces);
      cout << '|';
      repeat_chr(' ', box_width);
      cout << '|' << "\n";
    }
    void draw_row(string text){
      bool over = false;

      repeat_chr(' ', initial_spaces);
      cout << '|';
      repeat_chr(' ', inner_padding);

      if(text.length() > box_width-3-inner_padding){
        cout << text.substr(0, box_width-3-inner_padding) << "   ";
        over = true;
      } else {
        cout << text;
      }

      repeat_chr(' ', box_width - text.length()-3);
      cout << '|' << "\n";
      if(over){
        draw_row(text.substr(box_width-3-inner_padding));
      }
    }
};

class OutputManager{
  private:
    Menu m;
    BoxManager bm;

  protected:
  
  public:
    OutputManager(){
      bm = *(new BoxManager(100, 3, 3));
    }

    // welcome
    void welcome(){
      cout << "\n\n\n";

      bm.draw_header();
      bm.draw_row();
      bm.draw_row("                __        __   _                               _");
      bm.draw_row("                \\ \\      / /__| | ___ ___  _ __ ___   ___     | |_ ___  ");
      bm.draw_row("                 \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\    | __/ _ \\ ");
      bm.draw_row("                  \\ V  V /  __/ | (_| (_) | | | | | |  __/    | || (_) |");
      bm.draw_row("                   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|     \\__\\___/ ");
      bm.draw_row("     ____  _     _        _ _           _           _      _____                    ");
      bm.draw_row("    |  _ \\(_)___| |_ _ __(_) |__  _   _| |_ ___  __| |    |  ___|__  _ __ _ __ ___  ");
      bm.draw_row("    | | | | / __| __| '__| | '_ \\| | | | __/ _ \\/ _` |    | |_ / _ \\| '__| '_ ` _ \\ ");
      bm.draw_row("    | |_| | \\__ \\ |_| |  | | |_) | |_| | ||  __/ (_| |    |  _| (_) | |  | | | | | |");
      bm.draw_row("    |____/|_|___/\\__|_|  |_|_.__/ \\__,_|\\__\\___|\\__,_|    |_|  \\___/|_|  |_| |_| |_|");
      bm.draw_row();
      bm.draw_footer();

      cout << "\n\n\n";

    }
};

#endif