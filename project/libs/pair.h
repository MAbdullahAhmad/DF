
#ifndef PAIR_H
#define PAIR_H

template<class Key, class Value>
struct Pair {
  Key key;
  Value value;

  Pair(){}
  Pair(Key k, Value v){
    key = k;
    value = v;
  }
};

#endif
