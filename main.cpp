#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

#include "code.h"
#include "make.h"

using namespace std;


string answer;



int main ()
{
  system ("clear");
  cout << "Are you here to (C)ode or (R)un your program?" << endl;
  cin >> answer;
  
  if (answer == "C" || answer == "c")
  {
    maker ();
  }
  else if (answer == "r" || answer == "R")
  {
    usercode();
    return 0;
  }
} 
