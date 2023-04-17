; ./extra-small-lia/./s_multipl_12_000.smt2
(set-logic HORN)

(declare-fun |INV0| ( Int Int Int ) Bool)
(declare-fun |INV1| ( Int Int Int ) Bool)
(declare-fun |INV2| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (v_1 Int) (v_2 Int) ) 
    (=>
      (and
        (and (not (<= A 0)) (= 0 v_1) (= 0 v_2))
      )
      (INV0 A v_1 v_2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (INV0 A C D)
        (and (not (<= A 0)) (= B (+ (- 1) A)))
      )
      (INV1 B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (INV1 C A B)
        (and (= E (+ (- 1) B)) (not (<= C A)) (= D (+ 1 A)))
      )
      (INV1 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (INV1 A B C)
        (<= A B)
      )
      (INV2 A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (INV2 C A B)
        (and (= E (+ 1 B)) (not (<= C B)) (= D (+ (- 1) A)))
      )
      (INV2 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (INV2 A B C)
        (<= A C)
      )
      (INV0 A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (INV0 A B C)
        (and (= A 0) (not (= B C)))
      )
      false
    )
  )
)

(check-sat)
(exit)
