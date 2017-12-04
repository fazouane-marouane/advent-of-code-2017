let zip_map = (f, acc, length, accessor1, accessor2) => {
  let rec zip_map_helper = (n, acc) => {
    if (n == length) {
      acc;
    }
    else {
      zip_map_helper(n + 1, f(accessor1(n), accessor2(n), acc));
    }
  };
  zip_map_helper(0, acc)
};

let captcha = (str, shift) => {
  let compare_accumulate = (c1, c2, acc) => {
    acc + (c1 == c2 ? int_of_string(Char.escaped(c1)) : 0)
  };
  let length = String.length(str);
  let accessor1 = (i) => str.[i];
  let accessor2 = (i) => str.[(i + shift) mod length];
  zip_map(compare_accumulate, 0, length, accessor1, accessor2)
};

[@bs.module "fs"] external readFileSync : (string, Js.t('a)) => string = "readFileSync";

let content: string = readFileSync("./src/input01.txt", { "encoding": "utf-8"});

let run = () => {
  Js.log("result first step: " ++ string_of_int(captcha(content, 1)));
  Js.log("result second step: " ++ string_of_int(captcha(content, String.length(content)/2)));
};
