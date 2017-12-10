open AdventHelpers;

let is_duplicates_free = (passph) => {
  let visitedWords = Hashtbl.create(List.length(passph));
  let isNotValid =
    passph
    |> List.map(
         (word) =>
           if (Hashtbl.mem(visitedWords, word)) {
             true
           } else {
             Hashtbl.add(visitedWords, word, true);
             false
           }
       )
    |> List.exists((p) => p);
  ! isNotValid
};

let is_anagrams_free = (passph) =>
  passph
  |> List.map((s) => Js.String.split("", s) |> Js.Array.sortInPlace |> Js.Array.joinWith(""))
  |> is_duplicates_free;

let validPassphrasesCount = (passphrases, is_valid) =>
  passphrases |> List.fold_left((counter, passph) => counter + (is_valid(passph) ? 1 : 0), 0);

[@bs.val] external dirname : string = "__dirname";

let run = () => {
  let content =
    readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"})
    |> Js.String.split("\n")
    |> Array.map((str) => str |> Js.String.split(" ") |> Array.to_list)
    |> Array.to_list;
  Js.log(
    "result first step: " ++ string_of_int(validPassphrasesCount(content, is_duplicates_free))
  );
  Js.log("result second step: " ++ string_of_int(validPassphrasesCount(content, is_anagrams_free)))
};