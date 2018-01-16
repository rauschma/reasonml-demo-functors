module type PrintableType = {
  type t;
  let print: t => string;
};

module type S = (Fst: PrintableType, Snd: PrintableType) => {
  type t;
  let make: (Fst.t, Snd.t) => t;
  let print: (t) => string;
};

module Make: S = (Fst: PrintableType, Snd: PrintableType) => {
  type t = (Fst.t, Snd.t);
  let make = (f: Fst.t, s: Snd.t) => (f, s);
  let print = ((f, s): t) =>
    "(" ++ Fst.print(f) ++ ", " ++ Snd.print(s) ++ ")";
};


/*
Alternate version:
– Omit `S`: Then `Make.t` is not abstract.
*/