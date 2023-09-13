// import './App.css';
import { useState } from 'react';

function GameButton() {
  const [gameStarted, setGameStarted] = useState(false);

  return (
    <div>
      {!gameStarted ? (
        <button onClick={() => setGameStarted(true)}>Start Game</button>
      ) : (
        // Render your game content here when gameStarted is true
        <div>
          WOW! Time to start game owo
        </div>
      )}
    </div>
  );
}

export default GameButton;
