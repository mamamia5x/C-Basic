#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "make.h"

using namespace std;

string command;
string numname;
int comnum;
int linename = 0;

void coding ()
{
  ++ linename;
  if (linename == 1)
  {
    system ("clear");
    cout << linename << ". ";
  }
  if (linename > 1)
  {
    cout << linename << ". ";
  }
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
  else if (command == "math")
  {
    ofstream code;
    code.open ("code.cpp",ios::app);
    cin >> numname;
    code << numname << " = ";
    cin >> command;
    code << command << ";";
    code.close ();
    coding ();
  }
  else if (command == "number")
  {
    ofstream code;
    code.open ("code.cpp",ios::app);
    code << "\nlong double ";
    cin >> numname;
    code << numname << ";\n";
    code.close ();
    coding ();
  }
  else if (command == "wait")
  {
    ofstream code;
    code.open ("code.cpp",ios::app);
    code << "\nsleep (" ;
    cin >> comnum;
    code << comnum << ");";
    code.close();
    coding (); 
  }
  else if (command == "done")
  {
    ofstream code;
    code.open ("code.cpp",ios::app);
    code << "\n\n}";
    code.close ();
    system ("clear");
    cout << "You've finished your code. \nIn order to play it,\nyou'll need to reset the program and say you want to run it." << endl;
    exit (-1);
  }
  else
  {
    -- linename ;
    coding ();
  }
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
