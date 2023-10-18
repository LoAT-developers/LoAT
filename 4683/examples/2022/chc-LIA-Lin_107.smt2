; ./eldarica-misc/./LIA/llreve/while_after_while_if_merged_safe.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main15| ( Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main12| ( Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main7| ( Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main20| ( Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main3| ( Int Int ) Bool)
(declare-fun |inv_main8| ( Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (v_0 Int) (v_1 Int) ) 
    (=>
      (and
        (and true (= 0 v_0) (= 0 v_1))
      )
      (inv_main3 v_0 v_1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main8 A C E B D I G H F)
        (not (<= 1 B))
      )
      (inv_main7 A C E B D I G H F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main7 A C E B D I G H F)
        (not (<= 1 H))
      )
      (inv_main12 A C E B D I G H F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main12 A C E B D I G H F)
        (not (<= 1 D))
      )
      (inv_main15 A C E B D I G H F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main15 A C E B D I G H F)
        (not (<= 1 F))
      )
      (inv_main20 A C E B D I G H F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (inv_main8 C E G D F K I J H)
        (and (= B (+ 1 C)) (<= 1 D) (= A (+ (- 1) D)))
      )
      (inv_main8 B E G A F K I J H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (inv_main7 C E G D F K I J H)
        (and (= B (+ 2 C)) (<= 1 J) (= A (+ (- 1) J)))
      )
      (inv_main7 B E G D F K I A H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (inv_main15 C E G D F K I J H)
        (and (= B (+ 2 E)) (<= 1 H) (= A (+ (- 1) H)))
      )
      (inv_main15 C B G D F K I J A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) ) 
    (=>
      (and
        (inv_main12 C E G D F K I J H)
        (and (= B (+ 1 E)) (<= 1 F) (<= 1 K) (= A (+ (- 1) F)))
      )
      (inv_main12 C B G D A K I J H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (inv_main12 B D F C E J H I G)
        (and (<= 1 E) (not (<= 1 J)) (= A (+ (- 1) E)))
      )
      (inv_main12 B D F C A J H I G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (v_5 Int) (v_6 Int) (v_7 Int) (v_8 Int) ) 
    (=>
      (and
        (inv_main3 B D)
        (and (<= 1 A) (= v_5 E) (= v_6 E) (= v_7 C) (= v_8 C))
      )
      (inv_main8 B D E v_5 v_6 A C v_7 v_8)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (v_5 Int) (v_6 Int) (v_7 Int) (v_8 Int) ) 
    (=>
      (and
        (inv_main3 B C)
        (and (not (<= 1 A)) (= v_5 E) (= v_6 E) (= v_7 D) (= v_8 D))
      )
      (inv_main7 B C E v_5 v_6 A D v_7 v_8)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main20 A C E B D I G H F)
        (not (= A C))
      )
      false
    )
  )
)

(check-sat)
(exit)
