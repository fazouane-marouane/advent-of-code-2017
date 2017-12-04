open AdventHelpers;

let fold = (f, acc, length, nthElement) => {
  let rec fold_helper = (n, acc) =>
    if (n == length) {
      acc
    } else {
      fold_helper(n + 1, f(nthElement(n), acc))
    };
  fold_helper(0, acc);
};


let captcha = (str, shift) => {
  let accumulator = ((c1, c2), acc) => acc + (c1 == c2 ? int_of_string(Char.escaped(c1)) : 0);
  let length = String.length(str);
  let nthElement = (i) => (str.[i], str.[(i + shift) mod length]);
  fold(accumulator, 0, length, nthElement);
};

[@bs.val] external dirname : string = "__dirname";

let run = () => {
  let content: string = readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"});
  Js.log("result first step: " ++ string_of_int(captcha(content, 1)));
  Js.log("result second step: " ++ string_of_int(captcha(content, String.length(content) / 2)))
};