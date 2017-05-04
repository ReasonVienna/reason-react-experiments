let namespace = "reason-react-tictactoe";

module Top = {
  module TicTacToe = {
    include ReactRe.Component.Stateful;
    let name = "TicTacToe";
    type props = unit;
    type state = {squares: list Square.squareState, count: int};
    let getInitialState _ => {
      squares: [Circle, Circle, Circle, Empty, Empty, Empty, Cross, Cross, Cross],
      count: 0
    };
    let handleSquareClick state i => {
      switch (List.nth state.squares i) {
      | Circle => Js.log "circle!"
      | Cross => Js.log "cross!"
      | Empty => Js.log "empty!" /* now do a function like this guys! state.squares[i] = Circle */
      };
      ()
    };
    let countUp amount {state} _evt => Some {...state, count: state.count + amount};
    let render {state, updater} =>
      <div className="game">
        <div className="game-board">
          <div onClick=(updater (countUp 2))>
            (ReactRe.stringToElement (string_of_int state.count))
          </div>
          <Board squares=state.squares handleSquareClick=(handleSquareClick state) />
        </div>
        <div className="game-info"> <div /> <ol /> </div>
      </div>;
  };
  include ReactRe.CreateComponent TicTacToe;
  let createElement = wrapProps ();
};

ReactDOMRe.renderToElementWithClassName <Top /> "tictactoe";
