// generated by Fast Light User Interface Designer (fluid) version 1.0109

#include "datetool.h"
// (c) Robert Shingledecker 2008
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string fmtoutput(const string target, char action, int min, int max, int width) {
  istringstream iss;
ostringstream oss;
int result;
iss.str(target);
iss >> result;

if (action == '+')
   result++;
else
   result--;
   
if (max > 0)
{
   if ( result < min )
      result = max;
   if ( result > max )
      result = min;
}           
      
if (width > 0) 
{
  oss.fill('0');
  oss.width(width);
}
oss << result;
return oss.str();
}

void btnCallback(Fl_Widget*, void* userdata) {
  if (userdata == "cancel" )
   exit(1);
string target;
if (userdata == "yearDown")
{
   target = fmtoutput(yearInput->value(),'-',0,0,0);
   yearInput->value(target.c_str());
}
if (userdata == "yearUp")
{
   target = fmtoutput(yearInput->value(),'+',0,0,0);
   yearInput->value(target.c_str());
}
if (userdata == "monthDown")
{
   target = fmtoutput(monthInput->value(),'-',1,12,2);
   monthInput->value(target.c_str());
}
if (userdata == "monthUp")
{
   target = fmtoutput(monthInput->value(),'+',1,12,2);
   monthInput->value(target.c_str());
}
if (userdata == "dayDown")
{
   target = fmtoutput(dayInput->value(),'-',1,31,2);
   dayInput->value(target.c_str());
}
if (userdata == "dayUp")
{
   target = fmtoutput(dayInput->value(),'+',1,31,2);
   dayInput->value(target.c_str());
}
if (userdata == "hourDown")
{
   target = fmtoutput(hourInput->value(),'-',0,23,2);
   hourInput->value(target.c_str());
}
if (userdata == "hourUp")
{
   target = fmtoutput(hourInput->value(),'+',0,23,2);
   hourInput->value(target.c_str());
}
if (userdata == "minDown")
{
   target = fmtoutput(minInput->value(),'-',0,59,2);
   minInput->value(target.c_str());
}
if (userdata == "minUp")
{
   target = fmtoutput(minInput->value(),'+',0,59,2);
   minInput->value(target.c_str());
}
if (userdata == "ok")
{
   string command;
   string month = monthInput->value();
   string day = dayInput->value();
   string hour = hourInput->value();
   string min = minInput->value();
   string year = yearInput->value();
   command = "sudo date " + month + day + hour + min + year;
   system(command.c_str());
   command = "sudo hwclock --systohc";
   system(command.c_str());
   exit(0);
}
}

Fl_Input *yearInput=(Fl_Input *)0;

Fl_Input *monthInput=(Fl_Input *)0;

Fl_Input *dayInput=(Fl_Input *)0;

Fl_Input *hourInput=(Fl_Input *)0;

Fl_Input *minInput=(Fl_Input *)0;

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(195, 195, "Datetool");
    w = o;
    { yearInput = new Fl_Input(60, 11, 60, 25, "Year:");
    } // Fl_Input* yearInput
    { Fl_Button* o = new Fl_Button(125, 10, 25, 25, "@<");
      o->callback((Fl_Callback*)btnCallback, (void*)("yearDown"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(155, 10, 25, 25, "@>");
      o->callback((Fl_Callback*)btnCallback, (void*)("yearUp"));
    } // Fl_Button* o
    { monthInput = new Fl_Input(60, 40, 60, 25, "Month:");
    } // Fl_Input* monthInput
    { Fl_Button* o = new Fl_Button(125, 39, 25, 25, "@<");
      o->callback((Fl_Callback*)btnCallback, (void*)("monthDown"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(155, 39, 25, 25, "@>");
      o->callback((Fl_Callback*)btnCallback, (void*)("monthUp"));
    } // Fl_Button* o
    { dayInput = new Fl_Input(60, 70, 60, 25, "Day:");
    } // Fl_Input* dayInput
    { Fl_Button* o = new Fl_Button(125, 69, 25, 25, "@<");
      o->callback((Fl_Callback*)btnCallback, (void*)("dayDown"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(155, 69, 25, 25, "@>");
      o->callback((Fl_Callback*)btnCallback, (void*)("dayUp"));
    } // Fl_Button* o
    { hourInput = new Fl_Input(60, 100, 60, 25, "Hour:");
    } // Fl_Input* hourInput
    { Fl_Button* o = new Fl_Button(125, 99, 25, 25, "@<");
      o->callback((Fl_Callback*)btnCallback, (void*)("hourDown"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(155, 99, 25, 25, "@>");
      o->callback((Fl_Callback*)btnCallback, (void*)("hourUp"));
    } // Fl_Button* o
    { minInput = new Fl_Input(60, 130, 60, 25, "Min:");
    } // Fl_Input* minInput
    { Fl_Button* o = new Fl_Button(125, 129, 25, 25, "@<");
      o->callback((Fl_Callback*)btnCallback, (void*)("minDown"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(155, 129, 25, 25, "@>");
      o->callback((Fl_Callback*)btnCallback, (void*)("minUp"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(28, 163, 64, 25, "&OK");
      o->callback((Fl_Callback*)btnCallback, (void*)("ok"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(103, 163, 64, 25, "&Cancel");
      o->callback((Fl_Callback*)btnCallback, (void*)("cancel"));
    } // Fl_Button* o
    o->end();
  } // Fl_Double_Window* o
  FILE *CMD_fp = NULL;
if ((CMD_fp = popen("date +'%Y %m %d %H %M'","r"))==NULL)
{
   cerr << "popen failed" << endl;
   return 1;
}
char result[1024];
if ( fgets(result,1023,CMD_fp)==NULL)
{
   cerr << "popen results returned NULL" << endl;
   return 1;
}
string results = result;
yearInput->value(results.substr(0,4).c_str());
monthInput->value(results.substr(5,2).c_str());
dayInput->value(results.substr(8,2).c_str());
hourInput->value(results.substr(11,2).c_str());
minInput->value(results.substr(14,2).c_str());
  w->show(argc, argv);
  return Fl::run();
}