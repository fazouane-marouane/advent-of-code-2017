open AdventHelpers;

let partial_checksum = (line) => {
  let (minValue, maxValue) =
    switch (Array.to_list(line) |> List.map(int_of_string)) {
    | [head, ...rest] =>
      List.fold_left(
        ((minValue, maxValue), value) => (min(minValue, value), max(maxValue, value)),
        (head, head),
        rest
      )
    | [] => (0, 0)
    };
  maxValue - minValue
};

let checksum = (str) =>
  Js.String.split("\n", str)
  |> Array.map((line) => Js.String.split("\t", line) |> partial_checksum)
  |> Array.fold_left((+), 0);

[@bs.val] external dirname : string = "__dirname";

let run = () => {
  let content: string = readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"});
  Js.log("result first step: " ++ string_of_int(checksum(content)))
};