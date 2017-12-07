open AdventHelpers;

let manhattanDistanceToCenter = (index) => {
  let layer = (((sqrt(float_of_int(index - 1)) -. 1.) /. 2.) |> floor |> int_of_float) + 1;
  let pointsOfInterest = [|0, - 2 * layer, -4 * layer, -6 * layer |]
  |> Array.map(value => value + (layer*2+1) * (layer*2+1) - layer);
  let distances = pointsOfInterest |> Array.map(value => abs(value - index));
  Array.fold_left(min, distances[0], distances) + layer
};

[@bs.val] external dirname : string = "__dirname";

let run = () => {
  let content: int = int_of_string(readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"}));
  Js.log("result first step: " ++ string_of_int(manhattanDistanceToCenter(content)));
  Js.log("result second step: ")
};