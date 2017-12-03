let argv: array(string) = [%bs.raw {| process.argv |}];

Array.to_list(argv)
|> List.iteri((index, name) => {
    if (index >= 2) {
        Js.log("Running " ++ name);
        switch(name) {
        | "day01" => Day01.run()
        | _ => Js.log("not yet implemented")
        };
    }
});
