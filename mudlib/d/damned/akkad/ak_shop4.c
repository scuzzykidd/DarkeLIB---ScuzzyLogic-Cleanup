inherit "/std/vault";


void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("slim")) {
      new("/d/damned/akkad/obj/mon/slim")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/akkad/ak_marksw", "north");
   add_exit("/d/damned/akkad/shops/shop4_store", "east");
   set_door("iron door", "/d/damned/akkad/shops/shop4_store", "east",
            "ak shop4 store");
   set_open("iron door", 0);
   set_locked("iron door", 1);
   set_lock_level("iron door", 22);
   set("short","The Adventurer's General Store");
   set("long",
"This is the Adventurer's General Store.  Here, you can purchase "
"the various items and sundries needed for day-to-day adventuring.  "
"Several useful items are seen all about.  An imposing iron door is "
"seen to the east.");
   set_items( (["sign":"The say reads: 'say slim, help' for assistance.",
              "iron door" : "It looks very sturdy.",
              "door" : "It is a large iron door."]) );
}

