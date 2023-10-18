; ./prepared/hopv/./lia/fpice/inductive2_000.smt2
(set-logic HORN)


(declare-fun |f$unknown:2| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (|f$unknown:2| E D)
        (and (not (= 0 C)) (= D (- 2)) (= A E) (= (= 0 C) (<= (- 1) B)))
      )
      (|f$unknown:2| A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (not (= (= 0 D) (<= B 0)))
     (= 0 C)
     (not (= 0 D))
     (= A (- 1))
     (= (= 0 C) (<= (- 1) B)))
      )
      (|f$unknown:2| A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (= (= 0 C) (<= (- 1) B))
     (not (= (= 0 E) (<= B 2)))
     (= 0 D)
     (= 0 C)
     (not (= 0 E))
     (= A (+ 3 (* (- 1) B)))
     (not (= (= 0 D) (<= B 0))))
      )
      (|f$unknown:2| A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (= (= 0 C) (<= (- 1) B))
     (not (= (= 0 E) (<= B 2)))
     (= 0 D)
     (= 0 C)
     (= 0 E)
     (= A B)
     (not (= (= 0 D) (<= B 0))))
      )
      (|f$unknown:2| A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (|f$unknown:2| B A)
        (and (= 0 C) (= A 3) (not (= (= 0 C) (>= B 0))))
      )
      false
    )
  )
)

(check-sat)
(exit)
