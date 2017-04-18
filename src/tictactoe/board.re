module Board = {
  include ReactRe.Component;
  type props = {squares: list Square.squareState};
  let name = "Board";
  let handleClick _ _ => {
    Js.log "JAVA";
    None
  };
  let render {props, updater} => {
    let foo =
      props.squares |> List.map (fun s => <Square value=s handleClick=(updater handleClick) />);
    <div> (ReactRe.arrayToElement (Array.of_list foo)) </div>
  };
};

include ReactRe.CreateComponent Board;

let createElement ::squares => wrapProps {squares: squares};
