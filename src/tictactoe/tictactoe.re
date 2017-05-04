let namespace = "reason-react-tictactoe";

module Top = {
  module TicTacToe = {
    include ReactRe.Component.Stateful;
    let name = "TicTacToe";
    type props = unit;
    type state = {
      squares: list Square.squareState,
      turn: bool
    };
    let getInitialState _ => {
      squares: [Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty],
      turn: false
    };
    let handleSquareClick {state} i => {

      // get position in array where the user clicked on
      Js.log i;

      // easy check for whos turn it is
      switch (state.turn) {
      | false =>
        Js.log state.turn;
      | true =>
        Js.log state.turn;
      };

      // update the turn for the opposite value
      Some {...state, turn: not state.turn};
    };
    let render {state, updater} =>
      <div className="game">
        <div className="game-board">
          <Board squares=state.squares handleSquareClick=( updater handleSquareClick) />
        </div>
        <div className="game-info"> <div /> <ol /> </div>
      </div>;
  };
  include ReactRe.CreateComponent TicTacToe;
  let createElement = wrapProps ();
};

ReactDOMRe.renderToElementWithClassName <Top /> "tictactoe";
