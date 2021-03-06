inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","call hammer of faith");
    set_property("skill","worship of k'thach");
    set_property("casting time",10);
    set_property("base mp cost",35);
    set_property("dev cost", 52);
    set_property("fast dev cost", 151);
    set_property("spell level", 10);
    set_property("moon","luna");
    set_property("caster message","You call the Hammer of Faith to your hands.");
    set_property("target message","");
    set_property("observer message","$C calls the Hammer of Faith into creation.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", 660);
    set_property("prereq", "call spirit sword");
    return;
}

void info() {
message("help",
"This spell summons the Hammer of Faith into your possession.  The hammer "
"is imbued with holy power.  In addition, the spell provides you "
"with the necessary skill to use the weapon as well!  Your skill "
"with the hammer of faith depends mainly on the power of the spell, "
"but also slightly on two handed blunt skill.\n"
"NOTE: If you unwield the weapon, it will disappear.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob, ob2, *weps;
  string *limbs;

  if(flag) {
    message("info", "The fumble causes you to be drained of "
      "half of your remaining mp!", caster);
    caster->add_mp(-1 * (int)caster->query_mp() / 2);
    remove();
    return;
  }
  weps = map_array((string *)caster->query_wielding_limbs(),
    (: call_other($2, $3, $1) :), caster, "query_weapon");
  weps = filter_array(weps, (: objectp :));
  if(weps && sizeof(weps)) {
    message("info", "In order to cast this spell, you must be "
      "wielding no weapons.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  ob = new("/wizards/diewarzau/obj/weapons/hammer_of_faith");
  ob->move(caster);
  limbs = (string *)caster->query_wielding_limbs();
  if(sizeof(limbs) < 2) {
    message("info", "You must have 2 wielding limbs to cast this "
      "spell.", caster);
    caster->add_mp(props["mp cost"]);
    ob->remove();
    remove();
    return;
  }
  if(!caster->query_property("ambidextry") &&
    caster->query_property("handedness") &&
    (member_array((string)caster->query_property("handedness"),
    limbs) > -1)) {
    limbs -= ({ (string)caster->query_property("handedness") });
    caster->force_me("wield hammer in "+
      (string)caster->query_property("handedness") + " and "+
      limbs[0]);
  }
  else caster->force_me("wield hammer in "+
      limbs[0] + " and " + limbs[1]);
  ob->set_dur(props["duration"]);
  ob->set_property("enchantment", 4*power);
  ob2 = new("/std/spells/shadows/skill_shadow");
  ob2->add_skill("two handed holy", 50+7*power);
  ob2->add_new_skill_bonus("two handed holy",
    (int)caster->query_skill("two handed blunt") / 3);
  ob2->start_shadow(caster, props["duration"]+30, 0);
  ob->set_shadow(ob2);
  remove();
  return;
}
