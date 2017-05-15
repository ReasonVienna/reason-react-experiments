let namespace = "reason-react-tictactoe";

type playerState =
  | Circle
  | Cross;

module Top = {
  module TicTacToe = {
    include ReactRe.Component.Stateful;
    let name = "TicTacToe";
    type props = unit;
    type state = {squares: list Square.squareState, player: playerState};
    let getInitialState _ => {
      squares: [Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty],
      player: Circle
    };
    let switchPlayer (current: playerState) =>
      switch current {
      | Circle => Cross
      | Cross => Circle
      };
    let isEmptySquare (square: Square.squareState) =>
      switch square {
      | Empty => true
      | _ => false
      };
    let eventuallySetSquare squares selection player =>
      List.mapi
        (
          fun i square =>
            if (i == selection && isEmptySquare square) {
              switch player {
              | Circle => Square.Circle
              | Cross => Square.Cross
              }
            } else {
              square
            }
        )
        squares;
    let playTurn {state} (selection: int) => {
      let {squares, player} = state;
      Some {
        squares: eventuallySetSquare squares selection player,
        player: switchPlayer state.player
      }
    };
    let render {state, updater} =>
      <div className="game">
        <div className="game-board">
          <Board squares=state.squares handleSquareClick=(updater playTurn) />
        </div>
        <div className="game-info"> <div /> <ol /> </div>
      </div>;
  };
  include ReactRe.CreateComponent TicTacToe;
  let createElement = wrapProps ();
};

ReactDOMRe.renderToElementWithClassName <Top /> "tictactoe";
