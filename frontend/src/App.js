"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const jsx_runtime_1 = require("react/jsx-runtime");
// import './App.css';
const react_1 = require("react");
const testCrow_1 = __importDefault(require("./component/testCrow"));
function App() {
    const [gameStarted, setGameStarted] = (0, react_1.useState)(false);
    return ((0, jsx_runtime_1.jsx)("div", { children: !gameStarted ? ((0, jsx_runtime_1.jsx)("button", Object.assign({ onClick: () => setGameStarted(true) }, { children: "Start Game" }))) : (
        // Render your game content here when gameStarted is true
        (0, jsx_runtime_1.jsx)("div", { children: (0, jsx_runtime_1.jsx)(testCrow_1.default, {}) })) }));
}
exports.default = App;
