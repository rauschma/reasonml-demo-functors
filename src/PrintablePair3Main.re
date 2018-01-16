module PrintableString = {
  type t=string;
  let print = (s: t) => s;
};
module PrintableInt = {
  type t=int;
  let print = (i: t) => string_of_int(i);
};
module PrintableSI = PrintablePair3.Make(PrintableString, PrintableInt);

let () = PrintableSI.(print_string(print(make("Jane", 53))));