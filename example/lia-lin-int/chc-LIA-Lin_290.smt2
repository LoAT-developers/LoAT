; ./llreve/./smt2/clausified/loop__simple-loop_000.smt2
(set-logic HORN)

(declare-fun |INV_MAIN_42| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= B 1) (= A 0) (= C D))
      )
      (INV_MAIN_42 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (INV_MAIN_42 C D)
        (and (= C (+ (- 1) A)) (<= D 10) (<= C 10) (= D (+ (- 1) B)))
      )
      (INV_MAIN_42 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (INV_MAIN_42 C B)
        (and (<= C 10) (not (<= B 10)) (= C (+ (- 1) A)))
      )
      (INV_MAIN_42 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (INV_MAIN_42 A C)
        (and (<= C 10) (not (<= A 10)) (= C (+ (- 1) B)))
      )
      (INV_MAIN_42 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (INV_MAIN_42 A B)
        (and (not (<= B 10)) (not (<= A 10)) (not (= A B)))
      )
      false
    )
  )
)

(check-sat)
(exit)
