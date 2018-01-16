module type Param = {
  let f: 'a => 'a;
};

module Functor = (P: Param) => {
  /* Picks up signature of Param, not signature of P: */
  include P;
};

module M = {
  let f = x => x;
  let g = x => x;
};

module L = Functor(M);

L.f(123); /* OK */
/* L.g(123); /* doesn’t work */ */
