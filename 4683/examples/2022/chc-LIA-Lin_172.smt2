; ./vmt/./ctigar/up-nested.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) ) 
    (=>
      (and
        (and (not B) (= A true) (not H) (not C))
      )
      (state C A B H D E F G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) ) 
    (=>
      (and
        (state C A B P I K M O)
        (let ((a!1 (and (not G) F (not E) (not D) (= I H) (= K J) (= M L) (= O N)))
      (a!2 (and (not G) (not F) (not E) (not D) (= I H) (= K J) (= M L) (= O N)))
      (a!3 (and (not G)
                F
                E
                D
                (= I H)
                (= M L)
                (= O N)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!4 (and G (not F) E D (= I H) (= K J) (= M L) (= O N))))
  (and (or A
           B
           C
           (not P)
           (not (<= 0 I))
           (and G (not F) (not E) D (= I H) (= K J) (= M L) (= O N)))
       (or A
           C
           P
           (not B)
           (<= K O)
           (and G (not F) (not E) (not D) (= I H) (= K J) (= M L) (= O N)))
       (or C
           P
           (not B)
           (not A)
           (not (<= 0 I))
           (and (not G) F E (not D) (= I H) (= K J) (= M L) (= O N)))
       (or A
           C
           P
           (not B)
           (not (<= K O))
           (and (not G) F (not E) D (= I H) (= K J) (= M L) (= O N)))
       (or B P (not C) (not A) (not (<= K O)) a!1)
       (or C P (not B) (not A) (<= 0 I) a!2)
       (or B P (not C) (not A) (<= K O) a!2)
       (or A P (not B) (not C) a!3)
       (or B (not P) (not C) (not A) a!4)
       (or B
           C
           (not P)
           (not A)
           (and G (not F) E (not D) (= I H) (= K J) (= M L) (= O N)))
       (or P (not B) (not C) (not A) a!1)
       (or A B C P a!2)
       (or A B (not P) (not C) a!2)
       (or B
           C
           P
           (not A)
           (and (not G) (not F) E (not D) (= H 0) (= K J) (= M L) (= O N)))
       (or A
           B
           P
           (not C)
           (and (not G) (not F) E D (= L 0) (= I H) (= K J) (= O N)))
       (or A B C (not P) (<= 0 I) a!4)))
      )
      (state E D F G H J L N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) ) 
    (=>
      (and
        (state C A B H D E F G)
        (and (not B) (= A true) (= H true) (= C true))
      )
      false
    )
  )
)

(check-sat)
(exit)
