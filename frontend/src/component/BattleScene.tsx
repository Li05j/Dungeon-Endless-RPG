import { useEffect, useState } from 'react';
import { BattleDataIFace } from '../interface/battleDataIFace'

function BattleScene() {
    const [data, setData] = useState<BattleDataIFace | null>(null);

    useEffect(() => {
        fetch('http://localhost:18080/start')
            .then(response => response.json())
            .then(data => setData(data));
    }, []); // The empty array means this effect runs once on mount and not on updates

    return data ? (
        <div className='battle-scene'>
            <p>{data.turn}</p>
            <p>{data.enemyName} {data.enemyCurrHp}/{data.enemyMaxHp}</p>
            <p></p>
            <p>{data.allyName} {data.allyCurrHp}/{data.allyMaxHp}</p>
        </div>
    ) : (
        <p>Loading...</p>
    );
}

export default BattleScene;
