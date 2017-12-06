/* Reason */
open Jest;

describe(
  "Simple Captcha",
  () => {
    open Expect;
    test("1122", () => expect(Day01.captcha("1122", 1)) |> toBe(3));
    test("1111", () => expect(Day01.captcha("1111", 1)) |> toBe(4));
    test("1234", () => expect(Day01.captcha("1234", 1)) |> toBe(0));
    test("91212129", () => expect(Day01.captcha("91212129", 1)) |> toBe(9))
  }
);

describe(
  "Halfway Captcha",
  () => {
    open Expect;
    test("1212", () => expect(Day01.captcha("1212", 2)) |> toBe(6));
    test("1221", () => expect(Day01.captcha("1221", 2)) |> toBe(0));
    test("123425", () => expect(Day01.captcha("123425", 3)) |> toBe(4));
    test("123123", () => expect(Day01.captcha("123123", 3)) |> toBe(12));
    test("12131415", () => expect(Day01.captcha("12131415", 4)) |> toBe(4))
  }
);