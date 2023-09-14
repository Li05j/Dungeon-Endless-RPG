import { useEffect, useState } from 'react';
import { BattleDataIFace } from '../interface/battleDataIFace'

function BattleScene() {
    const [data, setData] = useState<BattleDataIFace | null>(null);

    useEffect(() => {
        // Function to fetch and update data
        const fetchBattleStartData = () => {
            fetch('http://localhost:18080/start')
                .then((response) => response.json())
                .then((responseData) => setData(responseData));
        };
        const fetchNextTurnData = () => {
            fetch('http://localhost:18080/nextTurn')
                .then((response) => response.json())
                .then((responseData) => setData(responseData));
        };

        // Fetch data initially
        fetchBattleStartData();

        // Set up interval to fetch data every 1 second
        const intervalId = setInterval(fetchNextTurnData, 1000);

        // Clean up the interval on unmount to prevent memory leaks
        return () => clearInterval(intervalId);
    }, []); // The empty array means this effect runs once on mount and not on updates

    console.log(data);
    console.log("hello owo: " + data?.battleEnd);
    return <div className='battle-scene'>
        {data ? (
            data.battleEnd ? (
                <p>Battle Ended! Now you can close the browser. Additional gameplay will be added in the future.</p>
            ) : (
                <>
                    <p>{data.turn}</p>
                    <p>
                        {data.enemyName} {data.enemyCurrHp}/{data.enemyMaxHp}
                    </p>
                    <p>
                        {data.allyName} {data.allyCurrHp}/{data.allyMaxHp}
                    </p>
                    {data.battleLogs.map((log, index) => (
                        <p key={index}>{log}</p>
                    ))}
                </>
            )
        ) : (
            <p>Loading...</p>
        )}
    </div>
}

export default BattleScene;
