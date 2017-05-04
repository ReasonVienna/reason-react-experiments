let namespace = "reason-react-tictactoe";

module Top = {
  module TicTacToe = {
    include ReactRe.Component.Stateful;
    let name = "TicTacToe";
    type props = unit;
    type state = {squares: list Square.squareState};
    let getInitialState _ => {
      squares: [Empty, Circle, Circle, Empty, Cross, Empty, Cross, Cross, Cross]
    };
    let handleSquareClick i {state} _ => {
      switch (List.nth state.squares i) {
      | Circle => Js.log "circle!"
      | Cross => Js.log "cross!"
      | Empty => Js.log "empty!" /* now do a function like this guys! state.squares[i] = Circle */
      };
      Some state
    };
    let render {state, updater} =>
      <div className="game">
        <div className="game-board">
          <Board squares=state.squares handleSquareClick=(updater handleSquareClick) />
        </div>
        <div className="game-info"> <div /> <ol /> </div>
      </div>;
  };
  include ReactRe.CreateComponent TicTacToe;
  let createElement = wrapProps ();
};

ReactDOMRe.renderToElementWithClassName <Top /> "tictactoe";
