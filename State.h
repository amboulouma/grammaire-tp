#include "Automate.h"
#include <string>
using namespace std;

class State0;
class State1;
class State2;
class State3;
class State4;
class State5;
class State6;
class State7;
class State8;
class State9;

class State {

public:
  State();
  State(string name);
  virtual ~State();
  void print() const;
  virtual bool transition(Automate &automate, Symbole *s) = 0;

protected:
  string name;
};


class State0 : public State {
public:
  State0();
  bool transition(Automate &automate, Symbole *s);
};

class State1 : public State {
public:
  State1();
  bool transition(Automate &automate, Symbole *s);
};

class State2 : public State {
public:
  State2();
  bool transition(Automate &automate, Symbole *s);
};

class State3 : public State {
public:
  State3();
  bool transition(Automate &automate, Symbole *s);
};

class State4 : public State {
public:
  State4();
  bool transition(Automate &automate, Symbole *s);
};

class State5 : public State {
public:
  State5();
  bool transition(Automate &automate, Symbole *s);
};

class State6 : public State {
public:
  State6();
  bool transition(Automate &automate, Symbole *s);
};

class State7 : public State {
public:
  State7();
  bool transition(Automate &automate, Symbole *s);
};

class State8 : public State {
public:
  State8();
  bool transition(Automate &automate, Symbole *s);
};

class State9 : public State {
public:
  State9();
  bool transition(Automate &automate, Symbole *s);
};
