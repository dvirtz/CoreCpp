#include <iostream>

struct S {
  S() { std::cout << "S Ctor\n"; }
  S(const S&) { std::cout << "S copy Ctor\n"; }
  ~S() { std::cout << "S Dtor\n"; }
};

// first try
// union foo {
//  int n;
//  S s;
//};

// second try
// union foo {
//  int n;
//  S s;
//  foo() { new (&s) S(); }
//  ~foo(){};
//};

// third try
struct foo {
  enum class State { INT, S };
  State state;
  union {
    int n;
    S s;
  };
  foo(int i) : state(State::INT) { new (&n) int(i); }
  foo(S s) : state(State::S) { new (&this->s) S(s); }
  foo() : foo(S{}) {}
  ~foo() {
    switch (state) {
    case State::INT:
      break;
    case State::S:
      s.~S();
      break;
    }
  };
};

int main() { foo f; }
