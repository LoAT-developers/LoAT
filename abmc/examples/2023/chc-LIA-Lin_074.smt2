; ./prepared/eldarica-misc/./LIA/llreve/loop2_merged_safe.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main15| ( Int Int Int Int Int ) Bool)
(declare-fun |inv_main10| ( Int Int Int Int Int ) Bool)
(declare-fun |inv_main7| ( Int Int Int Int Int ) Bool)
(declare-fun |CHC_COMP_FALSE| ( ) Bool)
(declare-fun |inv_main12| ( Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (v_1 Int) (v_2 Int) (v_3 Int) (v_4 Int) ) 
    (=>
      (and
        (and true (= 1 v_1) (= 0 v_2) (= 0 v_3) (= 0 v_4))
      )
      (inv_main7 A v_1 v_2 v_3 v_4)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main7 E B D F C)
        (and (<= 0 (+ E (* (- 1) B))) (= A (+ 2 D)))
      )
      (inv_main10 E B A F C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main10 E B D F C)
        (= A (+ 1 B))
      )
      (inv_main7 E A D F C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main7 D A C E B)
        (let ((a!1 (not (<= 1 (+ D (* (- 1) E))))) (a!2 (not (<= 0 (+ D (* (- 1) A))))))
  (and a!1 a!2))
      )
      (inv_main12 D A C E B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv_main7 F C E G D)
        (let ((a!1 (not (<= 0 (+ F (* (- 1) C))))))
  (and (= B (+ 1 G)) a!1 (<= 1 (+ F (* (- 1) G))) (= A (+ 2 D))))
      )
      (inv_main15 F C E B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main15 D A C E B)
        (not (<= 1 (+ D (* (- 1) E))))
      )
      (inv_main12 D A C E B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv_main15 F C E G D)
        (and (= B (+ 1 G)) (<= 1 (+ F (* (- 1) G))) (= A (+ 2 D)))
      )
      (inv_main15 F C E B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main10 D A C E B)
        (not (= (+ C (* (- 2) A)) 0))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main15 D A C E B)
        (not (= (+ B (* (- 2) E)) 0))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main12 D A C E B)
        (not (= C B))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        CHC_COMP_FALSE
      )
      false
    )
  )
)

(check-sat)
(exit)
