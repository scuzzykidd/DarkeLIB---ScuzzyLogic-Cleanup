#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dblw1", "north");
    add_exit(ROOMS+"dblw3","south");

    set("short","Luminous Way");
    set("long","Luminous Way runs north-south through Daybreak Ridge.");
}
