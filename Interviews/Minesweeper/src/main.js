import events from 'events';
import prompt from 'prompt';
import BoardIO from './BoardIO';

const gameEventEmitter = new events.EventEmitter();

console.log('Game started');

const main = () => {
  const board = new BoardIO(gameEventEmitter);

  prompt.start();
  prompt.get(['boardSize', 'bombCount'], (err, result) => {
    const { boardSize, bombCount } = result;
    board.setData({ boardSize: Number(boardSize), bombCount: Number(bombCount) });

    prompt.get(['x', 'y'], (errInputCoordinate, resultInputCoordinate) => {
      board.playGame(resultInputCoordinate);
    });
  });

  gameEventEmitter.on('isGameOver', () => {
    console.log('[[Game Over]]');
  });
};

main();
