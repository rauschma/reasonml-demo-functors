// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';


function Make(RC) {
  var repeat = function ($staropt$star, str) {
    var times = $staropt$star ? $staropt$star[0] : RC[/* count */0];
    if (times <= 0) {
      return "";
    } else {
      return str + repeat(/* Some */[times - 1 | 0], str);
    }
  };
  return /* module */[/* repeat */repeat];
}

exports.Make = Make;
/* No side effect */