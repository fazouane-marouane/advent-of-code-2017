open AdventHelpers;

let is_valid = (passph) => {
  let visitedWords = Hashtbl.create(List.length(passph));
  switch (
    passph
    |> List.find(
         (word) =>
           if (Hashtbl.mem(visitedWords, word)) {
             true
           } else {
             Hashtbl.add(visitedWords, word, true);
             false
           }
       )
  ) {
  | exception Not_found => true
  | v =>
    /* Remove the following line to trigger the 'bug' */
    Js.log({j|hum $v -- $visitedWords|j});
    false
  }
};

let validPassphrasesCount = (passphrases) =>
  passphrases |> List.fold_left((counter, passph) => counter + (is_valid(passph) ? 1 : 0), 0);

[@bs.val] external dirname : string = "__dirname";

let run = () => {
  let content =
    readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"})
    |> Js.String.split("\n")
    |> Array.map((str) => str |> Js.String.split(" ") |> Array.to_list)
    |> Array.to_list;
  Js.log("result first step: " ++ string_of_int(validPassphrasesCount(content)));
  Js.log("result second step: ")
};