#ifndef MASTER_PAGE_H
#define MASTER_PAGE_H

#include "iostream"
#include "queue"

class MasterPage{
  private:
    //> Props
    queue<string> buffers;

  public:
    //> Constructors
    MasterPage(){}
    MasterPage(queue<string> pre_def_buff){
      this->buffers = pre_def_buff;
    }

    // Buffers in out available
    void in(string chunk){
      this->buffers.push(chunk);
    }
    string out(){
      string chunk = this->buffers.front();
      this->buffers.pop();
      return chunk;
    }
    bool available(){
      return this->buffers.size() > 0;
    }
};

using namespace std;

#endif