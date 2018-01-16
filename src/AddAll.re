/********** Functor AddAll */

module type AddSingle = {
  type elt;
  type t; /* type of data structure */
  
  let empty: t;
  let fold: ((elt, 'r) => 'r, t, 'r) => 'r;
  let add: (elt, t) => t;
};
module AddAll = (A: AddSingle) => {
  let addAll = (~from: A.t, into: A.t) => {
    A.fold((x, result) => A.add(x, result), from, into);
  };
};

/* Alternative: separate interface for reasult of AddAll, destructively substitute t := A.t */

/********** StringSetPlus */

module StringSet = Set.Make({
  type t = string;
  let compare = Pervasives.compare;
});

module StringSetPlus = {
  include StringSet;
  include AddAll(StringSet);
};

let s1 = StringSetPlus.of_list(["a", "b", "c"]);
let s2 = StringSetPlus.of_list(["b", "c", "d"]);
StringSetPlus.(elements(addAll(~from=s2, s1)));
  /* list(string) = ["a", "b", "c", "d"] */

/********** StringListPlus */

module AddSingleStringList
: AddSingle with type t = list(string) = {
  type elt = string;
  type t = list(elt);
  let empty = [];
  let fold = List.fold_right;
  let add = (x: elt, coll: list(elt)) => [x, ...coll];
};

/* Alternative – omit:
: AddSingle with type t = list(string)
*/

module StringListPlus = {
  include List;
  include AddAll(AddSingleStringList);
};

StringListPlus.addAll(~from=["a", "b"], ["c", "d"]);
  /* list(string) = ["a", "b", "c", "d"] */
