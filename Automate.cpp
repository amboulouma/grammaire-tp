#include "State.h"
#include <iostream>
#include <stdio.h>

Automate::Automate(string flux) {
  lexer = new Lexer(flux);
  State0 *depart = new State0();
  statestack.push(depart);
}

void Automate::decalage(Symbole *s, State *e) {
  symbolstack.push(s);
  statestack.push(e);
}

