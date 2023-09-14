// import './App.css';
import { useState } from 'react';
import BattleScene from "./component/BattleScene"
import TestCrow from "./component/testCrow"

function App() {
  const [gameStarted, setGameStarted] = useState(false);

  return (
    <div>
      {!gameStarted ? (
        <button onClick={() => setGameStarted(true)}>Start Game</button>
      ) : (
        // Render your game content here when gameStarted is true
        <div>
          <BattleScene />
        </div>
      )}
    </div>
  );
}

export default App;
