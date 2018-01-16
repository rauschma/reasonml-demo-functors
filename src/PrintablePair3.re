module type PrintableType = {
  type t;
  let print: t => string;
};

module type S = {
  type fst;
  type snd;
  type t;
  let make: (fst, snd) => t;
  let print: (t) => string;
};

module Make = (Fst: PrintableType, Snd: PrintableType)
: (S with type fst := Fst.t and type snd := Snd.t) => {
  type t = (Fst.t, Snd.t);
  let make = (fst: Fst.t, snd: Snd.t) => (fst, snd);
  let print = ((fst, snd): t) =>
    "(" ++ Fst.print(fst) ++ ", " ++ Snd.print(snd) ++ ")";
};

/*
Destructive substitution:

- Removed lines:
  type fst = Fst.t;
  type snd = Snd.t;

– types fst and snd are removed from interface:
{
  type t;
  let make: (Fst.t, Snd.t) => t;
  let print: (t) => string;
}

*/