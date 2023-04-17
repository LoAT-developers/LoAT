; ./llreve/./smt2/loop__loop2_000.smt2
(set-logic HORN)

(declare-fun |INV_MAIN_42| ( Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (v_2 Int) (v_3 Int) (v_4 Int) (v_5 Int) ) 
    (=>
      (and
        (and (= A B) (= 1 v_2) (= 0 v_3) (= 0 v_4) (= 0 v_5))
      )
      (INV_MAIN_42 v_2 v_3 A v_4 v_5 B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (INV_MAIN_42 E F G H I J)
        (and (= B (+ 1 H))
     (= C (+ 2 F))
     (= D (+ 1 E))
     (<= E G)
     (not (<= J H))
     (= A (+ 2 I)))
      )
      (INV_MAIN_42 D C G B A J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (INV_MAIN_42 C D E F G H)
        (and (= B (+ 1 C)) (<= C E) (<= H F) (= A (+ 2 D)))
      )
      (INV_MAIN_42 B A E F G H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (INV_MAIN_42 C D E F G H)
        (and (= B (+ 1 F)) (not (<= C E)) (not (<= H F)) (= A (+ 2 G)))
      )
      (INV_MAIN_42 C D E B A H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (INV_MAIN_42 A B C D E F)
        (and (not (<= A C)) (<= F D) (not (= B E)))
      )
      false
    )
  )
)

(check-sat)
(exit)
