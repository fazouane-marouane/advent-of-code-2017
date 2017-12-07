open AdventHelpers;

type checksumMode =
  | MinMax
  | Division;

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

let rec division_checksum = (line: list(int)) =>
  switch line {
  | [head, ...rest] =>
    let otherValueFound = (value) => value mod head === 0 || head mod value === 0;
    let division = (value) => max(head, value) / min(head, value);
    try (List.find(otherValueFound, rest) |> division) {
    | Not_found => division_checksum(rest)
    }
  | [] => 0
  };

let ints_of_line_string = (str) =>
  Js.String.split("\t", str) |> Array.map(int_of_string) |> Array.to_list;

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