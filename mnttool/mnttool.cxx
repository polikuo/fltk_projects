// generated by Fast Light User Interface Designer (fluid) version 1.0110

#include "mnttool.h"
// (c) Robert Shingledecker 2008
#include <iostream>
#include <fstream>
#include <vector>
static int cycle; 
static int size; 
static int selected; 
using namespace std;
vector<string> mountList; 
static vector<int> mountState; 

int getMountables() {
  mountList.clear();
mountState.clear();

system("/usr/bin/mountables.sh");

ifstream fin("/tmp/mountables");
string line;
string commandHead = "grep /mnt/";
string commandTail = " /etc/mtab >/dev/null";

while ( getline(fin,line) )
{
   mountList.push_back(line);
   mountState.push_back(system((commandHead + line + commandTail).c_str()));
}   
fin.close();

size = mountList.size();
}

void btnCallback(Fl_Widget*, void* userdata) {
  if (userdata == "R" or userdata == "L")
{
   if (userdata == "R" )
   {
      cycle++;
      if ( cycle >= size )
      {
        getMountables();
        cycle = 0;
      }
   } else 
   {
      cycle--;
      if (cycle < 0 )
      {
        getMountables();
        cycle = size-1;
      }
   }
       
   btnState->label(mountList.at(cycle).c_str());
   if ( mountState[cycle] == 0)
      btnState->color((Fl_Color)2);
   else
      btnState->color((Fl_Color)1);      
      
   selected = cycle;
}
       
if (userdata == "state")
{
   int results;
   if (mountState.at(selected) == 0)   // mounted
   {
      results = system(("sudo umount /dev/" + mountList.at(selected)).c_str());
      if (results == 0)
      {
         btnState->color((Fl_Color)1);         
         btnState->redraw_label();        
         mountState.at(selected)=256;
      }    
   }   
   else
   {
      results = system(("sudo mount /dev/" + mountList.at(selected)).c_str());
      if (results == 0)
      {
         btnState->color((Fl_Color)2);         
         btnState->redraw_label();        
         mountState.at(selected)=0;
      }
   }
}
}

Fl_Button *btnState=(Fl_Button *)0;

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(120, 20);
    w = o;
    { Fl_Button* o = new Fl_Button(0, 0, 18, 20, "@<");
      o->callback((Fl_Callback*)btnCallback, (void*)("L"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(100, 0, 18, 20, "@>");
      o->callback((Fl_Callback*)btnCallback, (void*)("R"));
    } // Fl_Button* o
    { btnState = new Fl_Button(19, 0, 80, 20, "button");
      btnState->callback((Fl_Callback*)btnCallback, (void*)("state"));
    } // Fl_Button* btnState
    o->end();
  } // Fl_Double_Window* o
  getMountables();
if ( size == 0 ) 
  exit(1);
  
cycle = 0;
btnState->label(mountList[0].c_str());

if ( mountState[0] == 0)
   btnState->color((Fl_Color)2);
else
   btnState->color((Fl_Color)1);

selected = 0;
  w->show(argc, argv);
  return Fl::run();
}