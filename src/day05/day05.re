open AdventHelpers;

let interpretor = (tape, chooseOffset) => {
  let length = Array.length(tape);
  let rec helper = (index, counter) =>
    if (index < 0 || index >= length) {
      counter
    } else {
      let offset = tape[index];
      tape[index] = chooseOffset(offset);
      helper(index + offset, counter + 1)
    };
  helper(0, 0)
};

let first_interpretor = (tape) => interpretor(Array.copy(tape), (offset) => offset + 1);

let second_interpretor = (tape) =>
  interpretor(Array.copy(tape), (offset) => offset >= 3 ? offset - 1 : offset + 1);

[@bs.val] external dirname : string = "__dirname";

let run = () => {
  let content =
    readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"})
    |> Js.String.split("\n")
    |> Array.map(int_of_string);
  Js.log("result first step: " ++ string_of_int(first_interpretor(content)));
  Js.log("result second step: " ++ string_of_int(second_interpretor(content)))
};