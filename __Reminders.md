near future:
- expand playerinfo (create a vector of all usable allies, with a new private var "isTeamMember").
- getting enemy is returning a reference because we need to create a battle enemy class with dynamic stats for battle; the battle enemy class will likely take in a enemy reference in its constructor; enemy class is NOT the actual individual enemy data.

far future:
- switch to json/xml for enemy data.
- panic: generates error message, saves game then gracefully exit.