open AdventHelpers;

let minmax_checksum = (line) => {
  let (minValue, maxValue) =
    switch line {
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

let division_checksum = (line: list(int)) => 0;

let ints_of_line_string = (str) =>
  Js.String.split("\t", str) |> Array.map(int_of_string) |> Array.to_list;

type checksumMode =
  | MinMax
  | Division;

let checksum = (str, mode) => {
  let checksumMethod =
    switch mode {
    | MinMax => minmax_checksum
    | Division => division_checksum
    };
  Js.String.split("\n", str)
  |> Array.map((l) => l |> ints_of_line_string |> checksumMethod)
  |> Array.fold_left((+), 0)
};

[@bs.val] external dirname : string = "__dirname";

let run = () => {
  let content: string = readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"});
  Js.log("result first step: " ++ string_of_int(checksum(content, MinMax)));
  Js.log("result second step: " ++ string_of_int(checksum(content, Division)))
};