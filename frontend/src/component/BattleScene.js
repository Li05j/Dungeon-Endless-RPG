"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const jsx_runtime_1 = require("react/jsx-runtime");
const react_1 = require("react");
function BattleScene() {
    const [data, setData] = (0, react_1.useState)(null);
    (0, react_1.useEffect)(() => {
        fetch('http://localhost:18080/start')
            .then(response => response.json())
            .then(data => setData(data));
    }, []); // The empty array means this effect runs once on mount and not on updates
    return data ? ((0, jsx_runtime_1.jsxs)("div", { children: [(0, jsx_runtime_1.jsx)("p", { children: data.turn }), (0, jsx_runtime_1.jsxs)("p", { children: [data.enemyName, " ", data.enemyCurrHp, "/", data.enemyMaxHp] }), (0, jsx_runtime_1.jsx)("p", {}), (0, jsx_runtime_1.jsxs)("p", { children: [data.allyName, " ", data.allyCurrHp, "/", data.allyMaxHp] })] })) : ((0, jsx_runtime_1.jsx)("p", { children: "Loading..." }));
}
exports.default = BattleScene;
