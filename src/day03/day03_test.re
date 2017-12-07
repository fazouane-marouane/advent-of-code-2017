/* Reason */
open Jest;

describe(
  "Manhattan distance",
  () => {
    open Expect;

    test("center", () => expect(Day03.manhattanDistanceToCenter(1)) |> toBe(0));
    test("12", () => expect(Day03.manhattanDistanceToCenter(12)) |> toBe(3));
    test("23", () => expect(Day03.manhattanDistanceToCenter(23)) |> toBe(2));
    test("1024", () => expect(Day03.manhattanDistanceToCenter(1024)) |> toBe(31));
  }
);