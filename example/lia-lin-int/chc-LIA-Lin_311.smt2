; ./hopv/./lia/termination/Fibonacci00_000.smt2
(set-logic HORN)

(declare-fun |fib_1030$unknown:7| ( Int Int Int ) Bool)
(declare-fun |fail$unknown:3| ( Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (|fib_1030$unknown:7| A C B)
        (and (= D 1) (not (= 0 B)))
      )
      (|fail$unknown:3| D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 0) (= C 0))
      )
      (|fib_1030$unknown:7| A C B)
    )
  )
)
(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (|fail$unknown:3| A)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
