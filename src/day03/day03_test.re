/* Reason */
open Jest;

describe(
  "coordinates",
  () => {
    open Expect;
    open Day03;
    test("center", () => expect(inner_coordinates_of_index(1)) |> toEqual((0, 0, 0)));
    test("2", () => expect(inner_coordinates_of_index(2)) |> toEqual((1, 0, 0)));
    test("12", () => expect(inner_coordinates_of_index(12)) |> toEqual((2, 2, 0)));
    test("23", () => expect(inner_coordinates_of_index(23)) |> toEqual((2, 1, 3)));
    test("25", () => expect(inner_coordinates_of_index(25)) |> toEqual((2, 3, 3)));
    test("1024", () => expect(inner_coordinates_of_index(1024)) |> toEqual((16, 30, 1)))
  }
);

describe(
  "x-y-coordinates",
  () => {
    open Expect;
    open Day03;
    test("center", () => expect(coordinates_of_index(1)) |> toEqual((0, 0)));
    test("2", () => expect(coordinates_of_index(2)) |> toEqual((1, 0)));
    test("3", () => expect(coordinates_of_index(3)) |> toEqual((1, 1)));
    test("4", () => expect(coordinates_of_index(4)) |> toEqual((0, 1)));
    test("5", () => expect(coordinates_of_index(5)) |> toEqual(((-1), 1)));
    test("6", () => expect(coordinates_of_index(6)) |> toEqual(((-1), 0)));
    test("7", () => expect(coordinates_of_index(7)) |> toEqual(((-1), (-1))));
    test("8", () => expect(coordinates_of_index(8)) |> toEqual((0, (-1))));
    test("9", () => expect(coordinates_of_index(9)) |> toEqual((1, (-1))));
    test("12", () => expect(coordinates_of_index(12)) |> toEqual((2, 1)));
    test("23", () => expect(coordinates_of_index(23)) |> toEqual((0, (-2))));
    test("25", () => expect(coordinates_of_index(25)) |> toEqual((2, (-2))))
  }
);

describe(
  "x-y-coordinates_index",
  () => {
    open Expect;
    open Day03;
    test("center", () => expect(index_of_coordinates((0, 0))) |> toEqual(1));
    test("2", () => expect(index_of_coordinates((1, 0))) |> toEqual(2));
    test("3", () => expect(index_of_coordinates((1, 1))) |> toEqual(3));
    test("4", () => expect(index_of_coordinates((0, 1))) |> toEqual(4));
    test("5", () => expect(index_of_coordinates(((-1), 1))) |> toEqual(5));
    test("6", () => expect(index_of_coordinates(((-1), 0))) |> toEqual(6));
    test("7", () => expect(index_of_coordinates(((-1), (-1)))) |> toEqual(7));
    test("8", () => expect(index_of_coordinates((0, (-1)))) |> toEqual(8));
    test("9", () => expect(index_of_coordinates((1, (-1)))) |> toEqual(9));
    test("12", () => expect(index_of_coordinates((2, 1))) |> toEqual(12));
    test("23", () => expect(index_of_coordinates((0, (-2)))) |> toEqual(23));
    test("25", () => expect(index_of_coordinates((2, (-2)))) |> toEqual(25))
  }
);

describe(
  "Manhattan distance",
  () => {
    open Expect;
    test("center", () => expect(Day03.manhattanDistanceToCenter(1)) |> toBe(0));
    test("12", () => expect(Day03.manhattanDistanceToCenter(12)) |> toBe(3));
    test("23", () => expect(Day03.manhattanDistanceToCenter(23)) |> toBe(2));
    test("1024", () => expect(Day03.manhattanDistanceToCenter(1024)) |> toBe(31))
  }
);