import BoardWorker from './BoardWorker';

export default class BoardManager {
  constructor(gameEventEmitter) {
    this.gameEventEmitter = gameEventEmitter;
    this.boardWorker = new BoardWorker();
  }

  initBoard({ size, bomb }) {
    this.boardWorker.populateBoard(size, bomb);

    console.log(`Board Set: Size = ${size}, BombCount = ${bomb}`);
    this.gameEventEmitter.emit('play');
  }

  openGrid({ x, y }) {
    const openedGrid = this.boardWorker.openGrid({ x, y });

    if (openedGrid.isBomb()) {
      this.boardWorker.openAllBomb();
      this.boardWorker.printBoard();
      this.gameEventEmitter.emit('gameOver');
    }
    else if (openedGrid.isEmpty()) {
      openedGrid.openAdjacent();
      this.boardWorker.printBoard();
    }
    else{
      this.boardWorker.printBoard();
      this.gameEventEmitter.emit('play');
    }
  }
}
