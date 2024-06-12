; ./prepared/aeval/./multi-phase/s_split_31_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)
(declare-fun |fail| ( ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= C 0) (not (<= B 53736239)) (= A 0))
      )
      (inv A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv A D B)
        (let ((a!1 (ite (or (not (<= D A)) (= 0 (mod A 2))) (+ 1 B) (+ (- 1) B))))
  (and (= E a!1) (= C (+ 1 A))))
      )
      (inv C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv A B C)
        (and (not (<= A B)) (not (>= C 0)))
      )
      fail
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        fail
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
