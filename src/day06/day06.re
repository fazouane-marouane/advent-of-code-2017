open AdventHelpers;

[@bs.val] external dirname : string = "__dirname";

let memory_reallocation = (config) => {
  let length = Array.length(config);
  let (maxIndex, _) =
    config
    |> Array.fold_left(
         ((maxIdx, index), value) => (value > config[maxIdx] ? index : maxIdx, index + 1),
         (0, 0)
       );
  let nextConfig = Array.copy(config);
  nextConfig[maxIndex] = 0;
  let rec redistribute = (amount, index) =>
    if (amount > 0) {
      nextConfig[index] = nextConfig[index] + 1;
      redistribute(amount - 1, (index + 1) mod length)
    };
  redistribute(config[maxIndex], (maxIndex + 1) mod length);
  nextConfig
};

let find_memory_reallocation_loop = (initialConfig) => {
  let getSignature = (config) => config |> Array.map(string_of_int) |> Js.Array.joinWith(",");
  let knownConfigs = Hashtbl.create(1);
  Hashtbl.add(knownConfigs, getSignature(initialConfig), 0);
  Js.log(getSignature(initialConfig));
  let rec helper = (config, counter) => {
    let nextConfig = memory_reallocation(config);
    let signature = getSignature(nextConfig);
    if (Hashtbl.mem(knownConfigs, signature)) {
      (counter, counter - Hashtbl.find(knownConfigs, signature))
    } else {
      Hashtbl.add(knownConfigs, signature, counter);
      helper(nextConfig, counter + 1)
    }
  };
  helper(initialConfig, 1)
};

let run = () => {
  let content =
    readFileSync(joinPaths(dirname, "input.txt"), {"encoding": "utf-8"})
    |> Js.String.splitByRe([%bs.re "/\\s+/"])
    |> Array.map(int_of_string);
  let (counter, size) = find_memory_reallocation_loop(content);
  Js.log("result first step: " ++ string_of_int(counter));
  Js.log("result second step: " ++ string_of_int(size))
};