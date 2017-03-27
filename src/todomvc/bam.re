module Bam = {
  include ReactRe.Component;

  let name = "BAM";
  type props = unit;

  let render {props} => {
    <div>
      <h1>(ReactRe.stringToElement "FU")</h1>
    </div>
  };
};

include ReactRe.CreateComponent Bam;

let createElement ::foo => wrapProps ();
