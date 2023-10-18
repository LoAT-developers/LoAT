; ./eldarica-misc/./LIA/llreve/loop_unswitching_merged_safe.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main2| ( ) Bool)
(declare-fun |inv_main6| ( Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main12| ( Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main8| ( Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main15| ( Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main20| ( Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main9| ( Int Int Int Int Int Int ) Bool)
(declare-fun |CHC_COMP_FALSE| ( ) Bool)
(declare-fun |inv_main7| ( Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        true
      )
      inv_main2
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main7 F A B D C E)
        (not (<= 1 B))
      )
      (inv_main9 F A B D C E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main9 F A B D C E)
        true
      )
      (inv_main6 F A B D C E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main8 F A B D C E)
        (not (<= 1 B))
      )
      (inv_main12 F A B D C E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main12 F A B D C E)
        true
      )
      (inv_main6 F A B D C E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main6 F A B D C E)
        (not (<= 1 D))
      )
      (inv_main15 F A B D C E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main15 F A B D C E)
        true
      )
      (inv_main20 F A B D C E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main7 H C D F E G)
        (and (= B (+ (- 1) D)) (<= 1 D) (= A (+ 1 E)))
      )
      (inv_main7 H C B F A G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main8 H C D F E G)
        (and (= B (+ (- 1) D)) (<= 1 D) (= A (+ (- 1) E)))
      )
      (inv_main8 H C B F A G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main6 H C D F E G)
        (and (= B (+ (- 1) F)) (<= 1 F) (<= 1 H) (= A (+ 1 G)))
      )
      (inv_main6 H C D B E A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main6 H C D F E G)
        (and (= B (+ (- 1) F)) (<= 1 F) (not (<= 1 H)) (= A (+ (- 1) G)))
      )
      (inv_main6 H C D B E A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (v_2 Int) (v_3 Int) (v_4 Int) (v_5 Int) ) 
    (=>
      (and
        inv_main2
        (and (<= 1 B) (= v_2 A) (= v_3 A) (= 0 v_4) (= 0 v_5))
      )
      (inv_main7 B A v_2 v_3 v_4 v_5)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (v_2 Int) (v_3 Int) (v_4 Int) (v_5 Int) ) 
    (=>
      (and
        inv_main2
        (and (not (<= 1 B)) (= v_2 A) (= v_3 A) (= 0 v_4) (= 0 v_5))
      )
      (inv_main8 B A v_2 v_3 v_4 v_5)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main9 F A B D C E)
        (and (not (<= A 0)) (not (= C A)))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main12 F A B D C E)
        (and (not (<= A 0)) (not (= (+ C A) 0)))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main15 F A B D C E)
        (let ((a!1 (or (not (<= 1 A)) (not (<= F 0)) (not (= (+ E A) 0)))))
  (and (or (not (<= 1 F)) (not (<= 1 A)) (not (= E A))) a!1 (not (<= A 0))))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main20 F A B D C E)
        (not (= C E))
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
