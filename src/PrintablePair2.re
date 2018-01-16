module type PrintableType = {
  type t;
  let print: t => string;
};

/* Need fst, snd as parameters/glue (can’t refer to input anymore) */
module type S = {
  type fst;
  type snd;
  type t;
  let make: (fst, snd) => t;
  let print: (t) => string;
};

module Make = (Fst: PrintableType, Snd: PrintableType)
: (S with type fst = Fst.t and type snd = Snd.t) => {
  type fst = Fst.t;
  type snd = Snd.t;
  type t = (fst, snd);
  let make = (f: fst, s: snd) => (f, s);
  let print = ((f, s): t) =>
    "(" ++ Fst.print(f) ++ ", " ++ Snd.print(s) ++ ")";
};

/*
– Starting point: we need some kind of interface, because Make.t should be abstract.
– Previously: interface for whole functor
– Now: interface just for result

Caveat – redundant fst, snd (ideally, we’d use Fst.t etc. directly):

{
  type fst = Fst.t;
  type snd = Snd.t;
  type t;
  let make: (fst, snd) => t;
  let print: (t) => string;
}

Fix via a destructuring substitution: PrintablePair3

*/