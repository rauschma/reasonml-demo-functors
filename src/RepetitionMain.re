module CountThree: Repetition.Count = {
  let count=3;
};
module RepetitionThree = Repetition.Make(CountThree);

let () = print_string(RepetitionThree.repeat("abc\n"));