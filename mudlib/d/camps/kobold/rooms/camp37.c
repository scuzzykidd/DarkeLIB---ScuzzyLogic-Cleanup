/* Room coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "Before you lie a dozen or so large tents that act as shelter for the "
   "kobold fighters and warriors.  Large, muscular kobold men wield "
   "poorly-crafted weapons and wear heavily-used armor.  It is strange "
   "that such a small community would desire such heavy protection.  "
   "The main trail running through the campgrounds in seen to the "
   "northwest."
   );
   set("night long",
   "Even at night the kobold fighters and warriors are busy training "
   "and sparring with one another.  The air is thick with the smell of "
   "cooking meat, and it is sometimes difficult to see through the "
   "smoke.  The trail that runs through the campgrounds is to the "
   "northwest somewhere."
   );
   set_smell("default", "The stench of sweat offends your nostrils.");
   set_listen("default", "You hear grunting and groaning.");
   set_items( ([
                "tents":
           "The ragged tents provide shelter for the kobold fighters.",
                "smoke":
           "The thick smoke stings your eyes a little.",
                ({"fighters", "warriors", "kobolds"}):
           "The kobold fighters and warriors are training here.",
                ]) );
   set_exits( ([
                "northwest": PATH+"trail08",
                "west": PATH+"camp36",
                "east": PATH+"camp40",
                "south": PATH+"camp38",
                ]) );
}
 
void reset() {
   ::reset();
      if(!present("kobold fighter"))
         new(MON_PATH+"fighter")->move(this_object());
}
