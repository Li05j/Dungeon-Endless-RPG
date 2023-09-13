near future:
- stat debuffs need to be created on the fly (dynamic because debuff strength)

far future:
- switch to json/xml for enemy data.
- panic(string message, int type): message is probably function name, and type is exception type (enum); then will do something like: try -> throw exception error type then catch it immediately, in order to guarantee an error to throw, then display error message by overriding what()... this also makes code cleaner? since i dont have to plug try catch blocks everywhere.
- probably just catch in main is better, and just throw when error.

next:
- make combatunits with id 0 a dummy default character
- extend ally, enemy, skill to contain base stats and changing stats, store one copy of each in managers, then, copy the entire thing on demand when needed.
- partyally will be under player, realenemy will be in battlemanager
- reserve space for vectors in managers (need to get max ally, enemy and skill count)
- battle logic and battle demo (including dummy damange formula)
- idea: skill have formula type, battle manager will prob store array of formulas (maybe need a formula class?)


scraped:
- another for skill, enemy and ally (enemy and ally for now), see next point for reason
- i.e. getting enemy is returning a reference because we need to create a battle enemy class with dynamic stats for battle; the battle enemy class will likely take in a enemy reference in its constructor; enemy class is NOT the actual individual enemy data.
- another class will have reference to original one. original is just a constant data class that hold data. another class will be the one with dynamic data representing the actual unit.