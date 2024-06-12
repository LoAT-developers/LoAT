; ./prepared/hopv/./lia/mochi/map_000.smt2
(set-logic HORN)


(declare-fun |map$unknown:2| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (|map$unknown:2| E D)
        (and (= 0 C) (= D (+ (- 1) B)) (= A (+ 1 E)) (not (= (= 0 C) (= B 0))))
      )
      (|map$unknown:2| A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (not (= 0 C)) (= A 0) (not (= (= 0 C) (= B 0))))
      )
      (|map$unknown:2| A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (|map$unknown:2| B A)
        (and (= 0 C) (not (= (= 0 C) (= B A))))
      )
      false
    )
  )
)

(check-sat)
(exit)
