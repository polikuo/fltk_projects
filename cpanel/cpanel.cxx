// generated by Fast Light User Interface Designer (fluid) version 1.0110

#include <libintl.h>
#include "cpanel.h"
// (c) Robert Shingledecker 2008-2010
#include <cstdlib>
#include <iostream>
#include <locale.h>
using namespace std;

void btn_callback(Fl_Widget* w, void* userdata) {
  system((const char*)userdata);
}

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  setlocale(LC_ALL, "");
bindtextdomain("tinycore","/usr/local/share/locale");
textdomain("tinycore");
  { Fl_Double_Window* o = new Fl_Double_Window(405, 215, gettext("ControlPanel"));
    w = o;
    { Fl_Button* o = new Fl_Button(10, 10, 120, 30, gettext("Apps Audit"));
      o->callback((Fl_Callback*)btn_callback, (void*)("appsaudit &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 10, 120, 30, gettext("Backup/Restore"));
      o->callback((Fl_Callback*)btn_callback, (void*)("filetool &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 10, 120, 30, gettext("Mount Tool"));
      o->callback((Fl_Callback*)btn_callback, (void*)("mnttool &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(10, 50, 120, 30, gettext("Date/Time"));
      o->callback((Fl_Callback*)btn_callback, (void*)("datetool &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 50, 120, 30, gettext("Wallpaper"));
      o->callback((Fl_Callback*)btn_callback, (void*)("wallpaper &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 50, 120, 30, gettext("Swapfile Tool"));
      o->callback((Fl_Callback*)btn_callback, (void*)("swapfile &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(10, 90, 120, 30, gettext("Set TCE Drive"));
      o->callback((Fl_Callback*)btn_callback, (void*)("aterm +tr +sb -e tce-setdrive &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 90, 120, 30, gettext("Network"));
      o->callback((Fl_Callback*)btn_callback, (void*)("sudo network &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 90, 120, 30, gettext("Xvesa Setup"));
      o->callback((Fl_Callback*)btn_callback, (void*)("aterm +tr +sb -e xsetup.sh &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(10, 130, 120, 30, gettext("Floppy Tool"));
      o->callback((Fl_Callback*)btn_callback, (void*)("fdtool&"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 130, 120, 30, gettext("Mouse Tool"));
      o->callback((Fl_Callback*)btn_callback, (void*)("mousetool &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 130, 120, 30, gettext("System Stats"));
      o->callback((Fl_Callback*)btn_callback, (void*)("stats &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(10, 170, 120, 30, gettext("Update Apps"));
      o->callback((Fl_Callback*)btn_callback, (void*)("aterm +tr +sb -e tce-update &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 170, 120, 30, gettext("USB Install"));
      o->callback((Fl_Callback*)btn_callback, (void*)("aterm +tr +sb -e sudo usbinstall &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 170, 120, 30, gettext("Run Command"));
      o->callback((Fl_Callback*)btn_callback, (void*)("flrun &"));
    } // Fl_Button* o
    o->end();
  } // Fl_Double_Window* o
  w->show(argc, argv);
  return Fl::run();
}
