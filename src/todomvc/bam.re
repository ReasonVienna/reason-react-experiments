type foo = string;

module Bam = {
  include ReactRe.Component;

  let name = "Bam";
  type props = {
    title: string,
    description: string
  };

  let render {props} => {
    <div>
      <h1>(ReactRe.stringToElement props.title)</h1>
      (ReactRe.stringToElement props.description)
    </div>
  };
};

include ReactRe.CreateComponent Bam;

let createElement ::title ::description => wrapProps {title, description};
