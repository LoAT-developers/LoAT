; ./extra-small-lia/./s_multipl_15_000.smt2
(set-logic HORN)

(declare-fun |PRE| ( Int Int Int Int ) Bool)
(declare-fun |POST| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (v_1 Int) (v_2 Int) (v_3 Int) ) 
    (=>
      (and
        (and (>= A 0) (= v_1 A) (= 0 v_2) (= 0 v_3))
      )
      (PRE A v_1 v_2 v_3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (PRE A E B C)
        (let ((a!1 (or (and (= G C) (= F (+ 1 B))) (and (= G (+ 1 C)) (= F B)))))
  (and (not (<= A 0)) a!1 (= D (+ (- 1) A))))
      )
      (PRE D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (PRE A B C D)
        (= A 0)
      )
      (POST B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (POST A B C)
        (let ((a!1 (or (and (= F C) (= E (+ (- 1) B))) (and (= F (+ (- 1) C)) (= E B)))))
  (and (not (<= A 0)) a!1 (= D (+ (- 1) A))))
      )
      (POST D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (POST A B C)
        (and (not (<= B 0)) (not (<= C 0)) (= A 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
