; ./prepared/llreve/./smt2/clausified/loop__loop_000.smt2
(set-logic HORN)


(declare-fun |INV_MAIN_42| ( Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (= C D) (= B 0) (= A 0) (= E 0))
      )
      (INV_MAIN_42 A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (INV_MAIN_42 F G C H I)
        (and (= H (+ 1 D))
     (= G (+ (- 1) B))
     (= F (+ (- 1) A))
     (>= C F)
     (>= H 0)
     (= I (+ (- 1) E)))
      )
      (INV_MAIN_42 A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (INV_MAIN_42 F G C D E)
        (and (= F (+ (- 1) A)) (not (>= D 0)) (>= C F) (= G (+ (- 1) B)))
      )
      (INV_MAIN_42 A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (INV_MAIN_42 A B C F G)
        (and (= F (+ 1 D)) (>= F 0) (not (>= C A)) (= G (+ (- 1) E)))
      )
      (INV_MAIN_42 A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (INV_MAIN_42 E A D C B)
        (and (not (>= D E)) (not (>= C 0)) (not (= A B)))
      )
      false
    )
  )
)

(check-sat)
(exit)
