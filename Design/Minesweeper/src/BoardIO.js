import BoardManager from './BoardManager';

export default class BoardIO {
  constructor(gameEventEmitter) {
    this.boardManager = new BoardManager(gameEventEmitter);
  }

  setData({ boardSize, bombCount }) {
    this.boardManager.initBoard({ size: boardSize, bomb: bombCount });
  }

  playGame({ x, y }) {
    this.boardManager.openGrid({ x: Number(x), y: Number(y) });
  }
}
