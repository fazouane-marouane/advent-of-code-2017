open AdventHelpers;

/** Lazily evaluated lists with fold capabilities */
module ImplicitList = {
  type t('a) =
    | Nil
    | Cons('a, unit => t('a));
  let rec fold_left = (f, acc, l) =>
    switch l {
    | Nil => acc
    | Cons(head, rest) => fold_left(f, f(head, acc), rest())
    };
};

let captcha = (str, shift) => {
  open ImplicitList;
  let length = String.length(str);
  /* function to compute the sum of matching pairs of characters */
  let accumulator = ((c1, c2), acc) => acc + (c1 == c2 ? int_of_string(Char.escaped(c1)) : 0);
  /* function producing the two characters that should be paired together */
  let nthElement = (i) => (str.[i], str.[(i + shift) mod length]);
  let implicitList = {
    let rec rest = (i, ()) => i < length ? Cons(nthElement(i), rest(i + 1)) : Nil;
    rest(0, ())
  };
  implicitList |> fold_left(accumulator, 0)
};

[@bs.val] external dirname : string = "__dirname";

let run = () => {
  let content: string = readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"});
  Js.log("result first step: " ++ string_of_int(captcha(content, 1)));
  Js.log("result second step: " ++ string_of_int(captcha(content, String.length(content) / 2)))
};