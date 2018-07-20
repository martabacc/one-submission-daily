import events from 'events';
import prompt from 'prompt';
import BoardIO from './BoardIO';

const gameEventEmitter = new events.EventEmitter();
prompt.start();

const main = () => {
  const board = new BoardIO(gameEventEmitter);

  prompt.get(['boardSize', 'bombCount'], (err, result) => {
    const { boardSize, bombCount } = result;
    board.setData({ boardSize: Number(boardSize), bombCount: Number(bombCount) });
  });

  gameEventEmitter.on('gameOver', () => {
    console.log('\nGAME OVER. The bomb has exploded.');
  });

  gameEventEmitter.on('win', () => {
    console.log('\nSUCCESS! Congratulations, you win!');
  });

  gameEventEmitter.on('play', () => {
    prompt.get(['x', 'y'], (errInputCoordinate, resultInputCoordinate) => {
      board.playGame(resultInputCoordinate);
    });
  });

};

main();
