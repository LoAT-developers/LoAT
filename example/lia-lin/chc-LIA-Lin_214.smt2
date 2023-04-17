; ./vmt/./ctigar/ken-imp.c_000.smt2
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
        (let ((a!1 (and G (not F) (not E) D (= I H) (= K J) (= M L) (= O N)))
      (a!2 (and (not G)
                (not F)
                E
                D
                (= I H)
                (= K J)
                (= O N)
                (= (+ M (* (- 1) L)) 1)))
      (a!3 (and (not G)
                F
                (not E)
                D
                (= I H)
                (= K J)
                (= M L)
                (= (+ O (* (- 1) N)) 1)))
      (a!4 (and G F E (not D) (= I H) (= K J) (= M L) (= O N)))
      (a!5 (and (not G) (not F) (not E) (not D) (= I H) (= K J) (= M L) (= O N))))
  (and (or A
           B
           C
           (not P)
           (not (= O 0))
           (and G (not F) E (not D) (= I H) (= K J) (= M L) (= O N)))
       (or A B C (not P) (= O 0) a!1)
       (or P
           (not B)
           (not C)
           (not A)
           (not (= I K))
           (and G (not F) (not E) (not D) (= I H) (= K J) (= M L) (= O N)))
       (or B
           P
           (not C)
           (not A)
           (not (= M 0))
           (and (not G) F E D (= I H) (= K J) (= M L) (= O N)))
       (or B
           P
           (not C)
           (not A)
           (= M 0)
           (and (not G) (not F) (not E) D (= I H) (= K J) (= M L) (= O N)))
       (or A C P (not B) a!2)
       (or C P (not B) (not A) a!3)
       (or A B (not P) (not C) a!4)
       (or B
           C
           (not P)
           (not A)
           (and G F (not E) (not D) (= I H) (= K J) (= M L) (= O N)))
       (or A C (not P) (not B) a!1)
       (or A
           P
           (not B)
           (not C)
           (and (not G) F E (not D) (= I H) (= K J) (= M L) (= O N)))
       (or A B C P a!5)
       (or B (not P) (not C) (not A) a!5)
       (or A
           B
           P
           (not C)
           (and (not G) F E (not D) (= I H) (= K N) (= K J) (= M L)))
       (or B
           C
           P
           (not A)
           (and (not G) F (not E) (not D) (= I L) (= I H) (= K J) (= O N)))
       (or P (not B) (not C) (not A) (= I K) a!4)))
      )
      (state F E D G H J L N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) ) 
    (=>
      (and
        (state C A B H D E F G)
        (and (= B true) (not A) (= H true) (not C))
      )
      false
    )
  )
)

(check-sat)
(exit)
