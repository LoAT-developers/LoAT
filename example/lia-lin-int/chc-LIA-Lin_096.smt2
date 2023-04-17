; ./eldarica-misc/./LIA/reve/025c-horn_000.smt2
(set-logic HORN)

(declare-fun |REC_f_| ( Int Int ) Bool)
(declare-fun |REC__f| ( Int Int Int ) Bool)
(declare-fun |REC_f_f| ( Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (REC__f F G E)
        (and (= B 0)
     (= C (+ 1 F))
     (>= (+ C D) 17)
     (<= A 0)
     (not (<= C 0))
     (= (+ C D) (+ 31 G)))
      )
      (REC_f_f A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (REC__f F G E)
        (and (= B 0)
     (= C (+ 1 F))
     (not (>= (+ C D) 17))
     (<= A 0)
     (not (<= C 0))
     (= (+ C D) G))
      )
      (REC_f_f A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) ) 
    (=>
      (and
        (and (<= C 0) (<= A 0) (= B 0) (= v_4 D))
      )
      (REC_f_f A B C D v_4)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (REC_f_f G F H I E)
        (and (= (+ F A) (+ 32 B))
     (= A (+ 1 G))
     (= C (+ 1 H))
     (>= (+ C D) 17)
     (>= (+ F A) 16)
     (not (<= A 0))
     (not (<= C 0))
     (= (+ C D) (+ 31 I)))
      )
      (REC_f_f A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (REC_f_f G F H I E)
        (and (= (+ F A) B)
     (= A (+ 1 G))
     (= C (+ 1 H))
     (>= (+ C D) 17)
     (not (>= (+ F A) 16))
     (not (<= A 0))
     (not (<= C 0))
     (= (+ C D) (+ 31 I)))
      )
      (REC_f_f A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (REC_f_f G F H I E)
        (and (= (+ F A) (+ 32 B))
     (= A (+ 1 G))
     (= C (+ 1 H))
     (not (>= (+ C D) 17))
     (>= (+ F A) 16)
     (not (<= A 0))
     (not (<= C 0))
     (= (+ C D) I))
      )
      (REC_f_f A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (REC_f_f G F H I E)
        (and (= (+ F A) B)
     (= A (+ 1 G))
     (= C (+ 1 H))
     (not (>= (+ C D) 17))
     (not (>= (+ F A) 16))
     (not (<= A 0))
     (not (<= C 0))
     (= (+ C D) I))
      )
      (REC_f_f A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (v_6 Int) ) 
    (=>
      (and
        (REC_f_ F E)
        (and (= A (+ 1 F))
     (not (>= (+ E A) 16))
     (not (<= A 0))
     (<= C 0)
     (= (+ E A) B)
     (= v_6 D))
      )
      (REC_f_f A B C D v_6)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (v_6 Int) ) 
    (=>
      (and
        (REC_f_ F E)
        (and (= A (+ 1 F))
     (>= (+ E A) 16)
     (not (<= A 0))
     (<= C 0)
     (= (+ E A) (+ 32 B))
     (= v_6 D))
      )
      (REC_f_f A B C D v_6)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (<= A 0) (= B 0))
      )
      (REC_f_ A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (REC_f_ D C)
        (and (= A (+ 1 D)) (>= (+ C A) 16) (not (<= A 0)) (= (+ C A) (+ 32 B)))
      )
      (REC_f_ A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (REC_f_ D C)
        (and (= A (+ 1 D)) (not (>= (+ C A) 16)) (not (<= A 0)) (= (+ C A) B))
      )
      (REC_f_ A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (v_2 Int) ) 
    (=>
      (and
        (and (<= A 0) (= v_2 B))
      )
      (REC__f A B v_2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (REC__f D E C)
        (and (= A (+ 1 D)) (not (>= (+ A B) 17)) (not (<= A 0)) (= (+ A B) E))
      )
      (REC__f A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (REC__f D E C)
        (and (= A (+ 1 D)) (>= (+ A B) 17) (not (<= A 0)) (= (+ A B) (+ 31 E)))
      )
      (REC__f A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (REC_f_f D A E C B)
        (and (= C 0) (not (= A B)) (= D E))
      )
      false
    )
  )
)

(check-sat)
(exit)
