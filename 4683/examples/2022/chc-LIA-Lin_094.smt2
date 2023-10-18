; ./eldarica-misc/./LIA/reve/023b-horn_000.smt2
(set-logic HORN)

(declare-fun |INV1| ( Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (INV1 A B C G E F)
        (and (= E F) (<= G 10) (not (<= B 10)) (= G (+ (- 1) D)))
      )
      (INV1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (INV1 A G C H E F)
        (and (= G (+ (- 1) B)) (= E F) (<= H 10) (<= G 10) (= H (+ (- 1) D)))
      )
      (INV1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (INV1 A G C D E F)
        (and (= E F) (<= G 10) (not (<= D 10)) (= G (+ (- 1) B)))
      )
      (INV1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) (v_5 Int) ) 
    (=>
      (and
        (and (= B 0) (= A C) (= D 1) (= v_4 A) (= v_5 C))
      )
      (INV1 A B C D v_4 v_5)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (INV1 C A D B E F)
        (and (not (= A B)) (not (<= B 10)) (not (<= A 10)) (= E F))
      )
      false
    )
  )
)

(check-sat)
(exit)
