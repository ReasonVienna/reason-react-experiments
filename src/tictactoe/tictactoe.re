let namespace = "reason-react-tictactoe";

module Top = {
  module TicTacToe = {
    include ReactRe.Component.Stateful;
    let name = "TicTacToe";
    type props = unit;
    type state = {squares: list Square.squareState};
    let getInitialState _ => {
      squares: [Circle, Circle, Circle, Empty, Empty, Empty, Cross, Cross, Cross]
    };
    let handleSquareClick i => {
      Js.log i;
      ()
    };
    let render {state, updater} =>
      <div className="game">
        <div className="game-board"> <Board squares=state.squares handleSquareClick /> </div>
        <div className="game-info"> <div /> <ol /> </div>
      </div>;
  };
  include ReactRe.CreateComponent TicTacToe;
  let createElement = wrapProps ();
};

ReactDOMRe.renderToElementWithClassName <Top /> "tictactoe";
