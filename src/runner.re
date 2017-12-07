let run = (name) =>
  switch name {
  | "day1"
  | "day01" => Day01.run()
  | "day2"
  | "day02" => Day02.run()
  | "day3"
  | "day03" => Day03.run()
  | "day4"
  | "day04" => Day04.run()
  | "day5"
  | "day05" => Day05.run()
  | "day6"
  | "day06" => Day06.run()
  | "day7"
  | "day07" => Day07.run()
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