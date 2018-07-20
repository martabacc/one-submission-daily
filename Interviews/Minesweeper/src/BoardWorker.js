import Dot from './Dot';
import { generateCoordinate, getAdjacentCoordinates } from './utils';

export default class BoardWorker {
  constructor() {
    this.board = [];
    this.size = 0;
    this._bombs = [];
    this.bombCount = 0;
  }

  populateBoard(boardSize, bombCount) {
    this.size = boardSize;
    this.bombCount = bombCount;

    for (let x = 0; x < boardSize; x++) {
      const tempArr = [];
      for (let y = 0; y < boardSize; y++) {
        tempArr.push(new Dot(x, y, Number(boardSize), this.board));
      }
      this.board.push(tempArr);
    }

    this._populateBomb();
    this._populateNumbers();
  }

  _populateBomb() {
    const bombCoordinates = generateCoordinate(this.bombCount, this.size);
    for (const coordinate of bombCoordinates) {
      const { x, y } = coordinate;
      this.board[x][y].setToBomb();
      this._bombs.push(this.board[x][y]);
      console.log(`DEBUG: Coordinate bomb`, x, y);
    }
  }

  _populateNumbers() {
    for (let x = 0; x < this.size; x++) {
      for (let y = 0; y < this.size; y++) {
        const currentDot = this.board[x][y];
        if (!currentDot.isBomb()) {
          const adjacentCoordinates = getAdjacentCoordinates({ x, y, size: this.size });
          for (const coordinate of adjacentCoordinates) {
            const adjacentDot = this.board[coordinate.x][coordinate.y];
            if (adjacentDot.isBomb()) currentDot.incrementNumber();
          }
        }
      }
    }
  }

  printBoard() {
    for (let x = 0; x < this.size; x++) {
      let row = '';
      for (let y = 0; y < this.size; y++) {
        const currentDot = this.board[x][y];
        row = `${row} ${currentDot.isOpen ? currentDot.value : '_'}`;
      }
      console.log(row);
    }
  }

  openDot({ x, y }) {
    const currentDot = this.board[x][y];
    currentDot.open();
    return currentDot;
  }

  openAllBomb(){
    for(const bomb of this._bombs){
      bomb.open();
    }
  }

}
