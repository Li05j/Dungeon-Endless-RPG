near future:
- make combatunits with id 0 a dummy default character
- subclass for skill, enemy and ally, see next point for reason
- i.e. getting enemy is returning a reference because we need to create a battle enemy class with dynamic stats for battle; the battle enemy class will likely take in a enemy reference in its constructor; enemy class is NOT the actual individual enemy data.

far future:
- switch to json/xml for enemy data.
- panic(string message, int type): message is probably function name, and type is exception type (enum); then will do something like: try -> throw exception error type then catch it immediately, in order to guarantee an error to throw, then display error message by overriding what()... this also makes code cleaner? since i dont have to plug try catch blocks everywhere.
- probably just catch in main is better, and just throw when error.

next:
- skill manager
- battle logic and battle demo (including dummy damange formula)
- idea: skill have formula type, battle manager will prob store array of formulas (maybe need a formula class?)