export interface BattleDataIFace {
    turn: number;
    allyName: string;
    allyCurrHp: number;
    allyMaxHp: number;
    enemyName: string;
    enemyCurrHp: number;
    enemyMaxHp: number;
    battleLogs: string[];
    battleEnd: boolean;
}