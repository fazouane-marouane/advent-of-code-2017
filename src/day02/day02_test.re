/* Reason */
open Jest;

describe(
  "MinMax Checksum",
  () => {
    open Expect;
    test("5\t1\t9\t5", () => expect(Day02.checksum("5\t1\t9\t5", Day02.MinMax)) |> toBe(8));
    test("7\t5\t3", () => expect(Day02.checksum("7\t5\t3", Day02.MinMax)) |> toBe(4));
    test("2\t4\t6\t8", () => expect(Day02.checksum("2\t4\t6\t8", Day02.MinMax)) |> toBe(6));
    test(
      "multi lines",
      () => expect(Day02.checksum("5\t1\t9\t5\n7\t5\t3\n2\t4\t6\t8", Day02.MinMax)) |> toBe(18)
    )
  }
);

describe(
  "Division Checksum",
  () => {
    open Expect;
    test("5\t9\t2\t8", () => expect(Day02.checksum("5\t9\t2\t8", Day02.Division)) |> toBe(4));
    test("9\t4\t7\t3", () => expect(Day02.checksum("9\t4\t7\t3", Day02.Division)) |> toBe(3));
    test("3\t8\t6\t5", () => expect(Day02.checksum("3\t8\t6\t5", Day02.Division)) |> toBe(2));
    test(
      "multi lines",
      () => expect(Day02.checksum("5\t9\t2\t8\n9\t4\t7\t3\n3\t8\t6\t5", Day02.Division)) |> toBe(9)
    )
  }
);