#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "make.h"

using namespace std;

string command;
int comnum;

void coding ()
{
  getline (cin, command);
  if (command == "say") //cout
  {
    ofstream code;
    code.open ("code.cpp",ios::app);
    code << "\ncout << \"";
    getline (cin, command);
    code <<"\\n"<<command << "\";";
    code.close ();
    coding ();
  }
  if (command == "wait")
  {
    ofstream code;
    code.open ("code.cpp",ios::app);
    code << "\nusleep (" ;
    cin >> comnum;
    comnum = comnum * 1000000;
    code << comnum << ");";
    code.close();
    coding (); 
  }
  if (command == "iamdone")
  {
    ofstream code;
    code.open ("code.cpp",ios::app);
    code << "\n\n}";
    code.close ();
    system ("clear");
    cout << "You've finished your code. \nIn order to play it,\nyou'll need to reset the program and say you want to run it." << endl;
    exit (-1);
  }
  coding ();
}
void maker ()
{
  ofstream code;
  code.open ("code.cpp",ios::trunc);
  code << "#include \"code.h\"\n";
  code << "#include <iostream>\n";
  code << "#include <unistd.h>\n";
  code << "#include <stdlib.h>\n\n";
  code << "using namespace std;\n\n";
  code << "void usercode()\n{\nsystem (\"clear\");";
  code.close ();
  system ("clear");
  coding ();
}
