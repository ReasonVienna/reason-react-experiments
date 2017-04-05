module Board = {
  include ReactRe.Component;
  type props = unit;
  let name = "Board";
  let handleClick _ _ => {
    Js.log "JAVA";
    None
  };
  let render {props, updater} => <Square value=Empty handleClick=(updater handleClick) />;
};

include ReactRe.CreateComponent Board;

let createElement = wrapProps ();
