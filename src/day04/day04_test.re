/* Reason */
open Jest;

describe(
  "string validation",
  () => {
    open Expect;
    open Day04;
    test(
      "line 1",
      () =>
        expect(is_valid(["nyot", "babgr", "babgr", "kqtu", "kqtu", "kzshonp", "ylyk", "psqk"]))
        |> toBe(false)
    );
    test("line 2", () => expect(is_valid(["wchrl", "pzibt", "nvcae", "wceb"])) |> toBe(true))
  }
);