#ifndef OUTPUT_MANAGER_H
#define OUTPUT_MANAGER_H

class BoxManager;
class OutputManager;

#include "iostream"
#include "../libs/string_lib.h"
#include "../libs/clear_scr.h"
#include "../libs/delay.h"
#include "MasterPage.h"

using namespace std;

// Helpers
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
    void r_start(){
      // Start
      repeat_chr(' ', initial_spaces);
      cout << '|';
      repeat_chr(' ', inner_padding);
    }
    void r_end(int l){
      // End
      repeat_chr(' ', l);
      cout << '|' << "\n";
    }

  public:
    //> Constructors

    // Default Constructor
    BoxManager(){
      box_width =
      initial_spaces =
      inner_padding =
      0;
    }
    
    //> Param-Constructor
    BoxManager(
      int bw, int is, int ip
    ){
      box_width = bw;
      initial_spaces = is;      
      inner_padding = ip;
    }

    // Start Box
    void draw_header(){
      hf_mutual(',');
    }
    // End Box
    void draw_footer(){
      hf_mutual('|');
    }
    // Empty Row
    void draw_row(){
      repeat_chr(' ', initial_spaces);
      cout << '|';
      repeat_chr(' ', box_width);
      cout << '|' << "\n";
    }
    // Row With Content
    void draw_row(string text){
      bool over = false; // flag for overflow

      // Start
      r_start();

      // Content with Overflow Handeling
      if(text.length() > box_width-3-inner_padding){
        cout << text.substr(0, box_width-3-inner_padding) << "   ";
        over = true;
      } else {
        cout << text;
      }

      // End
      r_end(box_width - text.length()-3);

      // Over
      if(over){
        draw_row(text.substr(box_width-3-inner_padding));
      }
    }
    // Center Aligned Content
    void draw_center(string text){
      bool over = false; // flag for overflow

      int sl, sr = box_width - inner_padding * 2 - text.length();
      sl = (int)(sr / 2);
      sr -= sl;
      sl = sl < 0 ? 0 : sl;
      sr = sr < 0 ? 0 : sr;

      // Start
      r_start();

      // Content with Overflow Handeling
      cout << get_repeat_chr(' ', sl);
      if(text.length() > box_width-3-inner_padding){
        cout << text.substr(0, box_width-3-inner_padding) << "   ";
        over = true;
      } else {
        cout << text;
      }
      cout << get_repeat_chr(' ', sr);

      // End
      r_end(3);

      // Over
      if(over){
        draw_center(text.substr(box_width-3-inner_padding));
      }
    }
    // Right Aligned Content
    void draw_right(string text){
      bool over = false; // flag for overflow

      int sp = box_width - inner_padding * 2 - text.length();

      // Start
      r_start();

      // Content with Overflow Handeling
      cout << get_repeat_chr(' ', sp);
      if(text.length() > box_width-3-inner_padding){
        cout << text.substr(0, box_width-3-inner_padding) << "   ";
        over = true;
      } else {
        cout << text;
      }

      // End
      r_end(3);

      // Over
      if(over){
        draw_right(text.substr(box_width-3-inner_padding));
      }
    }
};

// Output Manager : Main Class
class OutputManager{
  private:
    // Menu m;
    BoxManager bm;
    bool center = false;
    bool right = false;

  protected:
  
  public:
    OutputManager(){
      bm = *(new BoxManager(100, 3, 3));
    }

    // welcome
    void welcome(int sec){
      cout << "\n\n\n";

      bm.draw_header();
      bm.draw_row(); delay_millis(200);
      bm.draw_row("                __        __   _                               _"); delay_millis(200);
      bm.draw_row("                \\ \\      / /__| | ___ ___  _ __ ___   ___     | |_ ___  "); delay_millis(200);
      bm.draw_row("                 \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\    | __/ _ \\ "); delay_millis(200);
      bm.draw_row("                  \\ V  V /  __/ | (_| (_) | | | | | |  __/    | || (_) |"); delay_millis(200);
      bm.draw_row("                   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|     \\__\\___/ "); delay_millis(200);
      bm.draw_row(); delay_millis(200);
      bm.draw_row("     ____  _     _        _ _           _           _      _____                    "); delay_millis(200);
      bm.draw_row("    |  _ \\(_)___| |_ _ __(_) |__  _   _| |_ ___  __| |    |  ___|__  _ __ _ __ ___  "); delay_millis(200);
      bm.draw_row("    | | | | / __| __| '__| | '_ \\| | | | __/ _ \\/ _` |    | |_ / _ \\| '__| '_ ` _ \\ "); delay_millis(200);
      bm.draw_row("    | |_| | \\__ \\ |_| |  | | |_) | |_| | ||  __/ (_| |    |  _| (_) | |  | | | | | |"); delay_millis(200);
      bm.draw_row("    |____/|_|___/\\__|_|  |_|_.__/ \\__,_|\\__\\___|\\__,_|    |_|  \\___/|_|  |_| |_| |_|"); delay_millis(200);
      bm.draw_row(); delay_millis(200);
      bm.draw_footer();
      
      delay_seconds(sec);
      cout << "\n\n\n";
    }
    void welcome(){ welcome(1); }

    // clear
    void clear(){
      clear_scr();
    }

    // Start, Feed, End
    void start(){
      bm.draw_header();
    }
    void feed(){
      bm.draw_row();
    }
    void feed(string dat){
      if (center)       bm.draw_center(dat);
      else if (right)   bm.draw_right(dat);
      else              bm.draw_row(dat);
    }
    void end(){
      bm.draw_footer();
    }

    void execute(MasterPage* page, bool clear){
      if(clear) this->clear();
      
      string chunk;
      while(page->available()){
        chunk = page->out();
        if(!this->command(chunk)){
          this->feed(chunk);
        }
      }
    }

    void execute(MasterPage* page){
      this->execute(page, true);
    }

    bool command(string cmd){
           if ( cmd == "__START__"      ){  this->start();         }
      else if ( cmd == "__END__"        ){  this->end();           }
      else if ( cmd == "__CENTER__"     ){  this->center = true;   }
      else if ( cmd == "__END_CENTER__" ){  this->center = false;  }
      else if ( cmd == "__RIGHT__"      ){  this->right = true;    }
      else if ( cmd == "__END_RIGHT__"  ){  this->right = false;   }
      else return false;
      return true;
    }

    // void _for(int sec){
    //   delay_seconds(sec);
    // }
};


#endif