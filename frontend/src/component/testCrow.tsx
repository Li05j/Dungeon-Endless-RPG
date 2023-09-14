import React, { useEffect, useState } from 'react';
import { BattleDataIFace } from '../interface/battleDataIFace'

enum UNIT_TYPE {
    TYPE_ALLY_UNIT,
    TYPE_ENEMY_UNIT,
}

const TestCrow = () => {
    const allyName: string = "MC 1";
    const enemyName: string = "Slime";
    const [allyHp, setAllyHp] = useState(100); // Initialize with dummy value
    const [enemyHp, setEnemyHp] = useState(100); // Initialize with dummy value

    // Function to update health points, for example, when the unit takes damage
    const takeDamage = (who: UNIT_TYPE, damage: number) => {
        if (who === UNIT_TYPE.TYPE_ALLY_UNIT) {
            setAllyHp((prevAllyHp) => prevAllyHp - damage);
        }
        else {
            setEnemyHp((prevEnemyHp) => prevEnemyHp - damage);
        }
    };

    return (
        <div>
            <p>{allyName}: {allyHp}/100</p>
            <p>{enemyName}: {enemyHp}/100</p>
            <button onClick={() => takeDamage(UNIT_TYPE.TYPE_ALLY_UNIT, 10)}>Take 10 Damage</button>
        </div>
    );
};

export default TestCrow;