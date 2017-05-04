module Board = {
  type tstate = Tictactoe.Top.TicTacToe.state;
  include ReactRe.Component;
  type props = {
    squares: list Square.squareState,
    handleSquareClick: int => componentBag tstate 'a 'b => 'c => option tstate
  };
  let name = "Board";
  let breakOnThree i => i mod 3 =T= 0 ? <br /> : <span />;
  let render {props} => {
    let squareElements =
      props.squares |>
      List.mapi (
        fun i s =>
          <span>
            (breakOnThree i)
            <Square value=s handleClick=(props.handleSquareClick i) />
          </span>
      );
    <div> (ReactRe.arrayToElement (Array.of_list squareElements)) </div>
  };
};

include ReactRe.CreateComponent Board;

let createElement ::squares ::handleSquareClick => wrapProps {squares, handleSquareClick};
