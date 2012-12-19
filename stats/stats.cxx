// generated by Fast Light User Interface Designer (fluid) version 1.0110

#include <libintl.h>
#include "stats.h"
// (c) Robert Shingledecker 2008-2010
#include <cstdlib>
#include <iostream>
#include <locale.h>
using namespace std;
static Fl_Text_Buffer *txtBuffer = new Fl_Text_Buffer(); 

void tabsGroupCB(Fl_Widget*, void*userdata) {
  tabs->value()->do_callback();
}

void tabCB(Fl_Widget*, void*userdata) {
  if (userdata == "cpu") 
  system("cat /proc/cpuinfo > /tmp/stats.txt");
if (userdata == "mem")
  system("cat /proc/meminfo > /tmp/stats.txt");
if (userdata == "net") 
{
  system("cat /etc/resolv.conf > /tmp/stats.txt");               
  system("ifconfig >> /tmp/stats.txt"); 
}                           
if (userdata == "modules")
  system("cat /proc/modules > /tmp/stats.txt");
if (userdata == "processes")
  system("ps ax > /tmp/stats.txt");
if (userdata == "dmesg")
  system("dmesg > /tmp/stats.txt");
if (userdata == "mounts")
  system("mount > /tmp/stats.txt");
if (userdata == "filesystems")
  system("df -h > /tmp/stats.txt");
if (userdata == "boot")
  system("sed 's/ /\\n/g' /proc/cmdline > /tmp/stats.txt");
if (userdata == "installed")
  system("ls -1 /usr/local/tce.installed | sort -f >/tmp/stats.txt");
if (userdata=="big")
  system("bigHomeFiles.sh > /tmp/stats.txt");
txtBuffer->loadfile("/tmp/stats.txt");
}

Fl_Tabs *tabs=(Fl_Tabs *)0;

Fl_Text_Display *cpuDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *memDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *netDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *modulesDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *processesDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *dmesgDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *mountsDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *filesystemsDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *bootDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *extensionsDisplay=(Fl_Text_Display *)0;

Fl_Text_Display *bigDisplay=(Fl_Text_Display *)0;

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  setlocale(LC_ALL, "");
bindtextdomain("tinycore","/usr/local/share/locale");
textdomain("tinycore");
  { Fl_Double_Window* o = new Fl_Double_Window(660, 385, gettext("Tiny Core System Stats"));
    w = o;
    { tabs = new Fl_Tabs(0, 0, 660, 386);
      tabs->selection_color((Fl_Color)228);
      tabs->callback((Fl_Callback*)tabsGroupCB);
      tabs->when(FL_WHEN_CHANGED);
      { Fl_Group* o = new Fl_Group(0, 0, 660, 335, gettext("cpu"));
        o->callback((Fl_Callback*)tabCB, (void*)("cpu"));
        o->when(FL_WHEN_CHANGED);
        o->hide();
        { cpuDisplay = new Fl_Text_Display(0, 0, 660, 335);
          cpuDisplay->textfont(4);
          cpuDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* cpuDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 0, 660, 335, gettext("mem"));
        o->callback((Fl_Callback*)tabCB, (void*)("mem"));
        o->hide();
        { memDisplay = new Fl_Text_Display(0, 0, 660, 335);
          memDisplay->textfont(4);
          memDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* memDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 0, 660, 336, gettext("net"));
        o->callback((Fl_Callback*)tabCB, (void*)("net"));
        o->hide();
        { netDisplay = new Fl_Text_Display(0, 0, 660, 335);
          netDisplay->textfont(4);
          netDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* netDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 0, 660, 335, gettext("modules"));
        o->callback((Fl_Callback*)tabCB, (void*)("modules"));
        o->hide();
        { modulesDisplay = new Fl_Text_Display(0, 0, 660, 335);
          modulesDisplay->textfont(4);
          modulesDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* modulesDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 0, 660, 335, gettext("processes"));
        o->callback((Fl_Callback*)tabCB, (void*)("processes"));
        o->hide();
        { processesDisplay = new Fl_Text_Display(0, 0, 660, 335);
          processesDisplay->textfont(4);
          processesDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* processesDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 0, 660, 335, gettext("dmesg"));
        o->callback((Fl_Callback*)tabCB, (void*)("dmesg"));
        o->hide();
        { dmesgDisplay = new Fl_Text_Display(0, 0, 660, 335);
          dmesgDisplay->textfont(4);
          dmesgDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* dmesgDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 0, 660, 335, gettext("mounts"));
        o->callback((Fl_Callback*)tabCB, (void*)("mounts"));
        o->hide();
        { mountsDisplay = new Fl_Text_Display(0, 0, 660, 335);
          mountsDisplay->textfont(4);
          mountsDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* mountsDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 0, 660, 335, gettext("filesystems"));
        o->callback((Fl_Callback*)tabCB, (void*)("filesystems"));
        o->hide();
        { filesystemsDisplay = new Fl_Text_Display(0, 0, 660, 335);
          filesystemsDisplay->textfont(4);
          filesystemsDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* filesystemsDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 0, 660, 335, gettext("boot"));
        o->callback((Fl_Callback*)tabCB, (void*)("boot"));
        o->hide();
        { bootDisplay = new Fl_Text_Display(0, 0, 660, 335);
          bootDisplay->textfont(4);
          bootDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* bootDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 0, 660, 335, gettext("Installed"));
        o->callback((Fl_Callback*)tabCB, (void*)("installed"));
        o->hide();
        { extensionsDisplay = new Fl_Text_Display(0, 0, 660, 335);
          extensionsDisplay->textfont(4);
          extensionsDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* extensionsDisplay
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(0, 5, 660, 350, gettext("bigHomeFiles"));
        o->callback((Fl_Callback*)tabCB, (void*)("big"));
        o->hide();
        { bigDisplay = new Fl_Text_Display(0, 0, 660, 335);
          bigDisplay->textfont(4);
          bigDisplay->buffer(txtBuffer);
        } // Fl_Text_Display* bigDisplay
        o->end();
      } // Fl_Group* o
      tabs->end();
    } // Fl_Tabs* tabs
    o->end();
  } // Fl_Double_Window* o
  system("bigHomeFiles.sh > /tmp/stats.txt");
txtBuffer->loadfile("/tmp/stats.txt");
  w->show(argc, argv);
  return Fl::run();
}
