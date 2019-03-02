#include "Automate.h"
#include "lexer.h"
#include <iostream>


int main(void) 
{
   string chaine;

   cout << "Veuillez entrer la phrase à analyser :" << endl;
   cin >> chaine;
   Automate *a = new Automate(chaine);
   a->analyse();

   return 0;
}