#include <std.h>
#include "../walled_city.h"
inherit ROOM;

void create() {
     ::create();
     set_property("light", 2);
     set_property("outdoors", 0);

     set("short", "Dirt path.");
     set("long", "You are on a well maintained dirt path. To the west you see a rock walled city protected by a tall guard tower. The west path slopes up toward the fortified city while the path to the east decends the mountainside.");

     add_exit(ROOMS+"dirtpath3","east");
     add_exit(ROOMS+"dirtpath5","west");

     set_items(([
          ({ "dirt", "path" }) :
          "A well maintained path, picked clean of all rocks and debris.",
          ({ "city" }) :
	  "A solid rock wall encloses the city to your west.",
	  ({ "tower" }) :
	  "A tall tower protects the entrance to the city" 
     ]));
     
    

}
