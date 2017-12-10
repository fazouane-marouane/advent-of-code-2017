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
        expect(
          is_duplicates_free(["nyot", "babgr", "babgr", "kqtu", "kqtu", "kzshonp", "ylyk", "psqk"])
        )
        |> toBe(false)
    );
    test(
      "line 2",
      () => expect(is_duplicates_free(["wchrl", "pzibt", "nvcae", "wceb"])) |> toBe(true)
    )
  }
);