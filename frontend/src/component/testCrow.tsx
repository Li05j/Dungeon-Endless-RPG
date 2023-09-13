import React, { useEffect, useState } from 'react';
import { BattleDataIFace } from '../interface/battleDataIFace'

const TestCrow = () => {
    const [data, setData] = useState<BattleDataIFace | null>(null);

    useEffect(() => {
        fetch('http://localhost:18080/api/data')
            .then(response => response.json())
            .then(data => setData(data));
    }, []); // The empty array means this effect runs once on mount and not on updates

    return data ? (
        <div>
            <p>{data.message1}</p>
            <p>{data.message2}</p>
        </div>
    ) : (
        <p>Loading...</p>
    );
};

export default TestCrow;