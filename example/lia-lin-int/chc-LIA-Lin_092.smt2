; ./eldarica-misc/./LIA/reve/014c-horn_000.smt2
(set-logic HORN)

(declare-fun |REC_f_| ( Int Int ) Bool)
(declare-fun |REC_f_f| ( Int Int Int Int ) Bool)
(declare-fun |CHC_COMP_FALSE| ( ) Bool)
(declare-fun |REC__f| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (v_5 Int) ) 
    (=>
      (and
        (REC__f E D)
        (and (not (= B 10))
     (= B (+ 1 E))
     (<= A 0)
     (not (<= B 1))
     (= (+ B D) C)
     (= v_5 A))
      )
      (REC_f_f A v_5 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (v_5 Int) ) 
    (=>
      (and
        (REC__f D E)
        (and (= B 10) (= B (+ 1 D)) (<= A 0) (not (<= B 1)) (= C 10) (= v_5 A))
      )
      (REC_f_f A v_5 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (v_2 Int) (v_3 Int) ) 
    (=>
      (and
        (and (<= A 0) (<= B 1) (= v_2 A) (= v_3 B))
      )
      (REC_f_f A v_2 B v_3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (REC_f_f G E H F)
        (and (= (+ C F) D)
     (= A (+ 1 G))
     (not (= C 10))
     (= C (+ 1 H))
     (not (<= A 0))
     (not (<= C 1))
     (= (+ A E) B))
      )
      (REC_f_f A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (REC_f_f F E G H)
        (and (= A (+ 1 F))
     (= D 10)
     (= C 10)
     (= C (+ 1 G))
     (not (<= A 0))
     (not (<= C 1))
     (= (+ A E) B))
      )
      (REC_f_f A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (v_5 Int) ) 
    (=>
      (and
        (REC_f_ E D)
        (and (= A (+ 1 E)) (not (<= A 0)) (<= C 1) (= (+ A D) B) (= v_5 C))
      )
      (REC_f_f A B C v_5)
    )
  )
)
(assert
  (forall ( (A Int) (v_1 Int) ) 
    (=>
      (and
        (and (<= A 0) (= v_1 A))
      )
      (REC_f_ A v_1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (REC_f_ D C)
        (and (= A (+ 1 D)) (not (<= A 0)) (= (+ A C) B))
      )
      (REC_f_ A B)
    )
  )
)
(assert
  (forall ( (A Int) (v_1 Int) ) 
    (=>
      (and
        (and (<= A 1) (= v_1 A))
      )
      (REC__f A v_1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (REC__f C D)
        (and (= A 10) (= A (+ 1 C)) (not (<= A 1)) (= B 10))
      )
      (REC__f A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (REC__f D C)
        (and (not (= A 10)) (= A (+ 1 D)) (not (<= A 1)) (= (+ A C) B))
      )
      (REC__f A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (REC_f_ D B)
        (and (= A (+ 1 D)) (= A C) (<= C 1) (not (<= A 0)) (not (= (+ A B) C)))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (REC_f_f D B E F)
        (and (= A (+ 1 D))
     (= A C)
     (= C 10)
     (= C (+ 1 E))
     (not (<= A 0))
     (not (<= C 1))
     (not (= (+ A B) 10)))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (REC_f_f E B F D)
        (and (= A (+ 1 E))
     (= A C)
     (not (= C 10))
     (= C (+ 1 F))
     (not (<= A 0))
     (not (<= C 1))
     (not (= (+ A B) (+ C D))))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (REC__f C D)
        (and (= B (+ 1 C)) (not (= A 10)) (= A B) (not (<= B 1)) (<= A 0) (= B 10))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (REC__f D C)
        (and (= B (+ 1 D))
     (not (= A (+ B C)))
     (= A B)
     (not (<= B 1))
     (<= A 0)
     (not (= B 10)))
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
