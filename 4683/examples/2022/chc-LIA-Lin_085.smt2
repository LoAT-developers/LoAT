; ./eldarica-misc/./LIA/reve/004-horn_000.smt2
(set-logic HORN)

(declare-fun |INV1| ( Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (INV1 A B C D G H)
        (and (= I J) (= G (+ (- 1) E)) (>= D G) (not (>= A B)) (= (+ H G) F))
      )
      (INV1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (INV1 A G H D I J)
        (and (= (+ H G) C)
     (= K L)
     (= I (+ (- 1) E))
     (= G (+ (- 1) B))
     (>= A G)
     (>= D I)
     (= (+ J I) F))
      )
      (INV1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (INV1 A G H D E F)
        (and (= I J) (= G (+ (- 1) B)) (not (>= D E)) (>= A G) (= (+ H G) C))
      )
      (INV1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (and (= E 1) (= C 0) (= B 0) (= A D) (= F 0))
      )
      (INV1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (INV1 C D A E F B)
        (and (not (= A B)) (not (>= E F)) (not (>= C D)) (= G H))
      )
      false
    )
  )
)

(check-sat)
(exit)
