"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const jsx_runtime_1 = require("react/jsx-runtime");
// import './App.css';
const react_1 = require("react");
function GameButton() {
    const [gameStarted, setGameStarted] = (0, react_1.useState)(false);
    return ((0, jsx_runtime_1.jsx)("div", { children: !gameStarted ? ((0, jsx_runtime_1.jsx)("button", Object.assign({ onClick: () => setGameStarted(true) }, { children: "Start Game" }))) : (
        // Render your game content here when gameStarted is true
        (0, jsx_runtime_1.jsx)("div", { children: "WOW! Time to start game owo" })) }));
}
exports.default = GameButton;
