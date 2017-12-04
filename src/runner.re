let run = (name) =>
  switch name {
  | "day1"
  | "day01" => Day01.run()
  | "day2"
  | "day02" => Day02.run()
  | _ => Js.log("not yet implemented")
  };

let argv: array(string) = [%bs.raw {| process.argv |}];

Array.to_list(argv)
|> List.iteri(
     (index, name) =>
       if (index >= 2) {
         Js.log("Running " ++ name);
         run(name)
       }
   );