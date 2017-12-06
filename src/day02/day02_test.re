/* Reason */
open Jest;

describe("Simple Checksum", () => {
  open Expect;

  test("5\t1\t9\t5", () =>
  expect(Day02.checksum("5\t1\t9\t5")) |> toBe(8));
  test("7\t5\t3", () =>
  expect(Day02.checksum("7\t5\t3")) |> toBe(4));
  test("2\t4\t6\t8", () =>
  expect(Day02.checksum("2\t4\t6\t8")) |> toBe(6));

  test("multi lines", () =>
    expect(Day02.checksum("5\t1\t9\t5\n7\t5\t3\n2\t4\t6\t8")) |> toBe(18));
});
