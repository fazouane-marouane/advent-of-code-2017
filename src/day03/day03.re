open AdventHelpers;

let maxIndexOfLayer = (layer) => (layer * 2 + 1) * (layer * 2 + 1);

let inner_coordinates_of_index = (index) =>
  if (index == 1) {
    (0, 0, 0)
  } else {
    let layer = ((sqrt(float_of_int(index - 1)) -. 1.) /. 2. |> floor |> int_of_float) + 1;
    let innerIndex = index - maxIndexOfLayer(layer - 1) - 1;
    let subdivisionUnit = 2 * layer;
    (layer, innerIndex mod subdivisionUnit, innerIndex / subdivisionUnit)
  };

let index_of_inner_coordinates = ((layer, idx, subdivision)) =>
  layer == 0 ? 1 : idx + subdivision * 2 * layer + maxIndexOfLayer(layer - 1) + 1;

let coordinates_of_index = (index) =>
  if (index == 1) {
    (0, 0)
  } else {
    let (layer, idx, subDiv) = inner_coordinates_of_index(index);
    let x = idx - layer + 1;
    switch subDiv {
    | 0 => (layer, x)
    | 1 => (- x, layer)
    | 2 => (- layer, - x)
    | _ => (x, - layer)
    }
  };

let index_of_coordinates = ((x, y)) => {
  let layer = max(abs(x), abs(y));
  let (idx, subDiv) =
    if (abs(x) < layer || x == - y) {
      y > 0 ? (layer - 1 - x, 1) : (layer - 1 + x, 3)
    } else {
      x > 0 ? (layer - 1 + y, 0) : (layer - 1 - y, 2)
    };
  index_of_inner_coordinates((layer, idx, subDiv))
};

let manhattanDistanceToCenter = (index) =>
  if (index == 1) {
    0
  } else {
    let (x, y) = coordinates_of_index(index);
    abs(x) + abs(y)
  };

let past_neighbours = (index) => {
  let (x, y) = coordinates_of_index(index);
  List.map((i) => List.map((j) => (x + i, y + j), [(-1), 0, 1]), [(-1), 0, 1])
  |> List.flatten
  |> List.map(index_of_coordinates)
  |> List.filter((k) => k > 0 && k < index)
};

let firstValueToGoBeyondThreshold = (threshold) => {
  let rec helper = (index, scores) => {
    let (s, nextScores) =
      if (index - 1 == Array.length(scores)) {
        let computedScore =
          past_neighbours(index) |> List.fold_left((acc, i) => acc + scores[i - 1], 0);
        (computedScore, Array.append(scores, [|computedScore|]))
      } else {
        (scores[index - 1], scores)
      };
    s >= threshold ? s : helper(index + 1, nextScores)
  };
  helper(1, [|1|])
};

[@bs.val] external dirname : string = "__dirname";

let run = () => {
  let content: int =
    int_of_string(readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"}));
  Js.log("result first step: " ++ string_of_int(manhattanDistanceToCenter(content)));
  Js.log("result second step: " ++ string_of_int(firstValueToGoBeyondThreshold(content)))
};