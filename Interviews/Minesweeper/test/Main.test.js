import { expect, use } from 'chai';
import events from 'events';
import SinonChai from 'sinon-chai';
import BoardIO from '../src/BoardIO';

use(SinonChai);

const dummyEventEmitter = new events.EventEmitter();

describe('Test', () => {
  it('Test', () => {
    const board = new BoardIO(dummyEventEmitter);
    board.setData({ boardSize: 3, bombCount: 1 });
    board.playGame({ x: 0, y: 1 });
  });
});

