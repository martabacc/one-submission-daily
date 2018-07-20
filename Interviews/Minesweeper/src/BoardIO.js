import BoardManager from './BoardManager';

export default class BoardIO {
  constructor(gameEventEmitter) {
    this.boardManager = new BoardManager(gameEventEmitter);
  }

  setData({ boardSize, bombCount }) {
    this.boardManager.initBoard({ size: boardSize, bomb: bombCount });
    console.log(`Board Set: Size = ${boardSize}, BombCount = ${bombCount}`);
  }

  playGame({ x, y }) {
    this.boardManager.openCoordinate({ x: Number(x), y: Number(y) });
  }
}
