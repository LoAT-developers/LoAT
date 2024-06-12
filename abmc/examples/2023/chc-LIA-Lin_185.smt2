; ./prepared/vmt/./ctigar/up2.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) ) 
    (=>
      (and
        (and (not B) (= A true) (not H) (not C))
      )
      (state C A B H G F E D)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) ) 
    (=>
      (and
        (state C A B P O M K I)
        (let ((a!1 (and G F (not E) D (= I H) (= K J) (= M L) (= O N)))
      (a!2 (and (not G)
                F
                (not E)
                (not D)
                (= K J)
                (= M L)
                (= O N)
                (= (+ I (* (- 1) H)) (- 1))))
      (a!3 (and G
                (not F)
                E
                D
                (= I H)
                (= M L)
                (= O N)
                (= (+ K (* (- 1) J)) (- 2))))
      (a!4 (and (not G)
                F
                (not E)
                D
                (= I H)
                (= K J)
                (= O N)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!5 (and G
                F
                (not E)
                (not D)
                (= I H)
                (= K J)
                (= O N)
                (= (+ M (* (- 1) L)) 1)))
      (a!6 (and (not G) (not F) (not E) (not D) (= I H) (= K J) (= M L) (= O N))))
  (and (or A B C (not P) (not (<= M 0)) a!1)
       (or A
           B
           C
           (not P)
           (<= M 0)
           (and G (not F) (not E) D (= I H) (= K J) (= M L) (= O N)))
       (or P
           (not B)
           (not C)
           (not A)
           (<= O K)
           (and G (not F) (not E) (not D) (= I H) (= K J) (= M L) (= O N)))
       (or A
           B
           P
           (not C)
           (not (<= O I))
           (and (not G) F E (not D) (= I H) (= K J) (= M L) (= O N)))
       (or A
           B
           P
           (not C)
           (<= O I)
           (and (not G) (not F) E D (= I H) (= K J) (= M L) (= O N)))
       (or B P (not C) (not A) a!2)
       (or A B (not P) (not C) a!3)
       (or A C P (not B) a!4)
       (or B (not P) (not C) (not A) a!5)
       (or C (not P) (not B) (not A) a!1)
       (or B
           C
           (not P)
           (not A)
           (and G (not F) E (not D) (= I H) (= K J) (= M L) (= O N)))
       (or A
           C
           (not P)
           (not B)
           (and (not G) F E D (= I H) (= K J) (= M L) (= O N)))
       (or C
           P
           (not B)
           (not A)
           (and (not G) (not F) E (not D) (= I H) (= K J) (= M L) (= O N)))
       (or A B C P a!6)
       (or A (not P) (not B) (not C) a!6)
       (or A
           P
           (not B)
           (not C)
           (and (not G) F E D (= J 0) (= I H) (= M L) (= O N)))
       (or B
           C
           P
           (not A)
           (and (not G) (not F) E (not D) (= L 0) (= H 0) (= K J) (= O N)))
       (or P
           (not B)
           (not C)
           (not A)
           (not (<= O K))
           (and G F E (not D) (= I H) (= K J) (= M L) (= O N)))))
      )
      (state E D F G N L J H)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) ) 
    (=>
      (and
        (state C A B H G F E D)
        (and (= B true) (= A true) (= H true) (not C))
      )
      false
    )
  )
)

(check-sat)
(exit)
