"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const jsx_runtime_1 = require("react/jsx-runtime");
const react_1 = require("react");
function BattleScene() {
    const [data, setData] = (0, react_1.useState)(null);
    (0, react_1.useEffect)(() => {
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
    console.log("hello owo: " + (data === null || data === void 0 ? void 0 : data.battleEnd));
    return (0, jsx_runtime_1.jsx)("div", Object.assign({ className: 'battle-scene' }, { children: data ? (data.battleEnd ? ((0, jsx_runtime_1.jsx)("p", { children: "Battle Ended! Now you can close the browser. Additional gameplay will be added in the future." })) : ((0, jsx_runtime_1.jsxs)(jsx_runtime_1.Fragment, { children: [(0, jsx_runtime_1.jsx)("p", { children: data.turn }), (0, jsx_runtime_1.jsxs)("p", { children: [data.enemyName, " ", data.enemyCurrHp, "/", data.enemyMaxHp] }), (0, jsx_runtime_1.jsxs)("p", { children: [data.allyName, " ", data.allyCurrHp, "/", data.allyMaxHp] }), data.battleLogs.map((log, index) => ((0, jsx_runtime_1.jsx)("p", { children: log }, index)))] }))) : ((0, jsx_runtime_1.jsx)("p", { children: "Loading..." })) }));
}
exports.default = BattleScene;
