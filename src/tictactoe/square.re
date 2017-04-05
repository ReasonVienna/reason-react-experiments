type squareState =
  | Cross
  | Circle
  | Empty;

module Square = {
  include ReactRe.Component;
  type props = {value: squareState, handleClick: ReactEventRe.Mouse.t => unit};
  let name = "Square";
  let squareStyle =
    ReactDOMRe.Style.make width::"25px" backgroundColor::"blue" fontSize::"100pt" ();
  let render {props, updater} =>
    <span style=squareStyle onClick=props.handleClick>
      (
        switch props.value {
        | Cross => ReactRe.stringToElement "X"
        | Circle => ReactRe.stringToElement "O"
        | Empty => ReactRe.stringToElement "?"
        }
      )
    </span>;
};

include ReactRe.CreateComponent Square;

let createElement ::value ::handleClick => wrapProps {value, handleClick};
