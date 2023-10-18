; ./prepared/llreve/./smt2/clausified/loop__loop3_000.smt2
(set-logic HORN)


(declare-fun |INV_MAIN_42| ( Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (and (= E 1) (= D 1) (= C 0) (= B 1) (= A G) (<= G 0) (not (<= A 0)) (= F 2))
      )
      (INV_MAIN_42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (and (= E 1) (= C 0) (= B 1) (= A D) (not (<= D 0)) (not (<= A 0)) (= F 2))
      )
      (INV_MAIN_42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (and (= H G) (= F 2) (= E 1) (= D 1) (= C 0) (= B 1) (<= H 0) (<= G 0) (= A 1))
      )
      (INV_MAIN_42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (and (= F 2) (= E 1) (= C 0) (= B 1) (= A 1) (<= G 0) (not (<= D 0)) (= G D))
      )
      (INV_MAIN_42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (INV_MAIN_42 A G H D I J)
        (and (= I (+ (- 1) E))
     (= H (+ (- 2) C))
     (= G (+ (- 1) B))
     (>= (+ D (* (- 1) I)) 1)
     (>= A G)
     (= J (+ (- 2) F)))
      )
      (INV_MAIN_42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (INV_MAIN_42 A G H D E F)
        (let ((a!1 (not (>= (+ D (* (- 1) E)) 1))))
  (and (= G (+ (- 1) B)) a!1 (>= A G) (= H (+ (- 2) C))))
      )
      (INV_MAIN_42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (INV_MAIN_42 A B C D G H)
        (and (= G (+ (- 1) E))
     (>= (+ D (* (- 1) G)) 1)
     (not (>= A B))
     (= H (+ (- 2) F)))
      )
      (INV_MAIN_42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (INV_MAIN_42 E F A C D B)
        (let ((a!1 (not (>= (+ C (* (- 1) D)) 1))))
  (and a!1 (not (>= E F)) (not (= A B))))
      )
      false
    )
  )
)

(check-sat)
(exit)
