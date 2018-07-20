import Grid from './Grid';
import { generateCoordinate } from './utils';

export default class BoardWorker {
  constructor() {
    this.board = [];
    this._bombs = [];
    this._bombCount = 0;
    this._size = 0;
  }

  populateBoard(boardSize, bombCount) {
    this._size = boardSize;
    this._bombCount = bombCount;

    for (let x = 0; x < boardSize; x++) {
      const tempArr = [];
      for (let y = 0; y < boardSize; y++) {
        tempArr.push(new Grid(x, y, Number(boardSize), this.board));
      }
      this.board.push(tempArr);
    }

    this._populateBomb();
    this._populateNumbers();
  }

  _populateBomb() {
    const bombCoordinates = generateCoordinate(this._bombCount, this._size);
    for (const coordinate of bombCoordinates) {
      const { x, y } = coordinate;
      this.board[x][y].setToBomb();
      this._bombs.push(this.board[x][y]);
      console.log(`DEBUG: Coordinate bomb`, x, y);
    }
  }

  _populateNumbers() {
    this.board.forEach(rows => {
      rows.forEach(grid => {
        if (!grid.isBomb()) {
          const adjacentGrids = grid.getAdjacent();
          for (const adjacentGrid of adjacentGrids) {
            if (adjacentGrid.isBomb()) grid.incrementNumber();
          }
        }
      });
    });
  }

  printBoard() {
    const grids = this.board.map(x => x.map(y => y.isOpen ? y.value : '_'));
    console.table(grids);
  }

  openGrid({ x, y }) {
    const currentDot = this.board[x][y];
    currentDot.open();
    return currentDot;
  }

  openAllBomb() {
    for (const bomb of this._bombs) {
      bomb.open();
    }
  }

}
