#include "State.h"
#include "symbole.h"
#include <iostream>
#include <stdio.h>

State::State() {}

State::~State() {}

State::State(string name) { name = name; }

State0::State0() : State("I0") {}

State1::State1() : State("I1") {}

State2::State2() : State("I2") {}

State3::State3() : State("I3") {}

State4::State4() : State("I4") {}

State5::State5() : State("I5") {}

State6::State6() : State("I6") {}

State7::State7() : State("I7") {}

State8::State8() : State("I8") {}

State9::State9() : State("I9") {}

bool State0::transition(Automate &automate, Symbole *s) {
  switch (*s) {
  case EXPR:
    automate.decalage(s, new State1);
    break;
  case OPENPAR:
    automate.decalage(s, new State2);
    break;
  case INT:
    automate.decalage(s, new State3);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}


bool State1::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.decalage(s, new State4);
    break;
  case MULT:
    automate.decalage(s, new State5);
    break;
  case FIN:
    return true;
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}


bool State2::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case INT:
    automate.decalage(s, new State3);
    break;
  case OPENPAR:
    automate.decalage(s, new State2);
    break;
  case EXPR:
    automate.decalage(s, new State6);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}


bool State3::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.reduction(1, new Symbole(PLUS));
    break;
  case MULT:
    automate.reduction(1, new Symbole(MULT));
    break;
  case CLOSEPAR:
    automate.reduction(1, new Symbole(CLOSEPAR));
    break;
  case FIN:
    automate.reduction(1, new Symbole(FIN));
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}

bool State4::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case INT:
    automate.decalage(s, new State3);
    break;
  case OPENPAR:
    automate.decalage(s, new State2);
    break;
  case EXPR:
    automate.decalage(s, new State7);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}

bool State5::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case INT:
    automate.decalage(s, new State3);
    break;
  case OPENPAR:
    automate.decalage(s, new State2);
    break;
  case EXPR:
    automate.decalage(s, new State8);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}

bool State6::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.decalage(s, new State4);
    break;
  case MULT:
    automate.decalage(s, new State5);
    break;
  case CLOSEPAR:
    automate.decalage(s, new State9);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}

bool State7::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.reduction(3, new Plus);
    break;
  case MULT:
    automate.decalage(s, new State5);
    break;
  case CLOSEPAR:
    automate.reduction(3, new Closepar);
    break;
  case FIN:
    automate.reduction(3, new Fin);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}

bool State8::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.reduction(3, new Plus);
    break;
  case MULT:
    automate.reduction(3, new Mult);
    break;
  case CLOSEPAR:
    automate.reduction(3, new Closepar);
    break;
  case FIN:
    automate.reduction(3, new Fin);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}

bool State9::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.reduction(3, new Plus);
    break;
  case MULT:
    automate.reduction(3, new Mult);
    break;
  case CLOSEPAR:
    automate.reduction(3, new Closepar);
    break;
  case FIN:
    automate.reduction(3, new Fin);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return false;
}