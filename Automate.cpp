#include "State.h"
#include <iostream>
#include <stdio.h>

Automate::Automate(string flux) 
{
  lexer = new Lexer(flux);
  State0 *depart = new State0();
  statestack.push(depart);
}

void Automate::decalage(Symbole *s, State *e) 
{
  symbolstack.push(s);
  statestack.push(e);
}

void Automate::reduction(int n, Symbole *s) 
{
  stack<Symbole *> aEnlever;

  for (int i = 0; i < n; i++) {
    delete (statestack.top());
    statestack.pop();
    aEnlever.push(symbolstack.top());
    symbolstack.pop();
  }

  int val;

  if (n == 1) 
  {
    val = aEnlever.top()->getValue();
  } 
  else if (n == 3) 
  {
    if (*aEnlever.top() == OPENPAR) 
    {
      aEnlever.pop();
      val = aEnlever.top()->getValue();
    } 
    else 
    {
      val = aEnlever.top()->getValue();
      aEnlever.pop();
      if (*aEnlever.top() == MULT) 
      {
        aEnlever.pop();
        val = val * aEnlever.top()->getValue();
      } 
      else
      {
        aEnlever.pop();
        val = val + aEnlever.top()->getValue();
      }
    }
  }

  statestack.top()->transition(*this, new expression(val));
  lexer->addSymbole(s);
}

void Automate::analyse() 
{
  bool nextStat = true;
  while (nextStat) 
  {
    Symbole *s = lexer->Consulter();
    lexer->Avancer();
    nextStat = statestack.top()->transition(*this, s);
  }
  if (*symbolstack.top() != ERREUR)
  {
    int result = symbolstack.top()->getValue();
    cout << "La syntaxe correct." << endl;
    cout << "Le résultat est: " << result << endl;
  } 
  else 
  {
    cout << "La syntaxe n'est pas reconnu à cause d'un caractere invalide." << endl;
  }
}