import BoardWorker from './BoardWorker';

export default class BoardManager {
  constructor(gameEventEmitter) {
    this.totalSize = 0;
    this.openedDotCount = 0;
    this.gameEventEmitter = gameEventEmitter;
    this.boardWorker = new BoardWorker();
  }

  initBoard({ size, bomb }) {
    this.totalSize = (size * size) - bomb;
    this.boardWorker.populateBoard(size, bomb);
  }

  openCoordinate({ x, y }) {
    const openedDot = this.boardWorker.openDot({ x, y });

    if (openedDot.isBomb())
    {
      this.boardWorker.openAllBomb();
      this.gameEventEmitter.emit('isGameOver');
    }
    else if (openedDot.isEmpty())
    {
      this.gameEventEmitter.emit('isEmptyCell');
      openedDot.openAdjacent();
    }

    this.boardWorker.printBoard();
  }
}
