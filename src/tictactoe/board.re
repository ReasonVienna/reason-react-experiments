module Board = {
  include ReactRe.Component;
  type props = {squares: list Square.squareState};
  let name = "Board";
  let handleClick _ _ => {
    Js.log "JAVA";
    None
  };
  let mod3 i => i mod 3 == 0 ? <br /> : <span />;
  let render {props, updater} => {
    let foo =
      props.squares |>
      List.mapi (
        fun i s => <span> (mod3 i) <Square value=s handleClick=(updater handleClick) /> </span>
      );
    <div> (ReactRe.arrayToElement (Array.of_list foo)) </div>
  };
};

include ReactRe.CreateComponent Board;

let createElement ::squares => wrapProps {squares: squares};
