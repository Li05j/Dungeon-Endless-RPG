"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const jsx_runtime_1 = require("react/jsx-runtime");
const react_1 = require("react");
var UNIT_TYPE;
(function (UNIT_TYPE) {
    UNIT_TYPE[UNIT_TYPE["TYPE_ALLY_UNIT"] = 0] = "TYPE_ALLY_UNIT";
    UNIT_TYPE[UNIT_TYPE["TYPE_ENEMY_UNIT"] = 1] = "TYPE_ENEMY_UNIT";
})(UNIT_TYPE || (UNIT_TYPE = {}));
const TestCrow = () => {
    const allyName = "MC 1";
    const enemyName = "Slime";
    const [allyHp, setAllyHp] = (0, react_1.useState)(100); // Initialize with dummy value
    const [enemyHp, setEnemyHp] = (0, react_1.useState)(100); // Initialize with dummy value
    // Function to update health points, for example, when the unit takes damage
    const takeDamage = (who, damage) => {
        if (who === UNIT_TYPE.TYPE_ALLY_UNIT) {
            setAllyHp((prevAllyHp) => prevAllyHp - damage);
        }
        else {
            setEnemyHp((prevEnemyHp) => prevEnemyHp - damage);
        }
    };
    return ((0, jsx_runtime_1.jsxs)("div", { children: [(0, jsx_runtime_1.jsxs)("p", { children: [allyName, ": ", allyHp, "/100"] }), (0, jsx_runtime_1.jsxs)("p", { children: [enemyName, ": ", enemyHp, "/100"] }), (0, jsx_runtime_1.jsx)("button", Object.assign({ onClick: () => takeDamage(UNIT_TYPE.TYPE_ALLY_UNIT, 10) }, { children: "Take 10 Damage" }))] }));
};
exports.default = TestCrow;
