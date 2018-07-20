import { getAdjacentCoordinates, openUntilNumber } from './utils';

export default class Dot {
  constructor(x, y, size, board) {
    this.isOpen = false;
    this._isBomb = false;
    this._size = size;
    this._board = board;
    this._x = x;
    this._y = y;
    this.value = 0;
  }

  setToBomb() {
    this._isBomb = true;
    this.value = 'X';
  }

  isBomb() {
    return this._isBomb;
  }

  isEmpty() {
    return this.value === 0;
  }

  isNumber() {
    return this.value > 0;
  }

  open() {
    this.isOpen = true;
  }

  incrementNumber() {
    this.value++;
  }

  openAdjacent() {
    let adjacents = this.getAdjacent(this._size, this._board);

    while (adjacents.length > 0) {
      adjacents = [...openUntilNumber(adjacents)];
      console.log(adjacents.length)
    }
  }

  getAdjacent() {
    let temp = [];

    const adjacentCoordinates = getAdjacentCoordinates({
      x: this._x,
      y: this._y,
      size: this._size
    });

    for (const coordinate of adjacentCoordinates) {
      const adjacentDot = this._board[coordinate.x][coordinate.y];
      temp.push(adjacentDot);
    }
    return temp;
  }
}
