module PrintableString = {
  type t=string;
  let print = (s: t) => s;
};
module PrintableInt = {
  type t=int;
  let print = (i: t) => string_of_int(i);
};
module PrintableSI = PrintablePair1.Make(PrintableString, PrintableInt);

let () = PrintableSI.({
  let pair = make("Jane", 53);
  let str = print(pair);
  print_string(str);
});


/* Alternate version:

module PrintableString: PrintablePair1.PrintableType with type t=string = {
  type t=string;
  let print = (s: t) => s;
};

*/