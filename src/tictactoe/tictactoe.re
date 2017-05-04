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
    let handleSquareClick state i => {
      switch (List.nth state.squares i) {
      | Circle => Js.log "circle!"
      | Cross => Js.log "cross!"
      | Empty => Js.log "empty!" /* now do a function like this guys! state.squares[i] = Circle */
      };
      ()
    };
    let render {state} =>
      <div className="game">
        <div className="game-board">
          <Board squares=state.squares handleSquareClick=(handleSquareClick state) />
        </div>
        <div className="game-info"> <div /> <ol /> </div>
      </div>;
  };
  include ReactRe.CreateComponent TicTacToe;
  let createElement = wrapProps ();
};

ReactDOMRe.renderToElementWithClassName <Top /> "tictactoe";
