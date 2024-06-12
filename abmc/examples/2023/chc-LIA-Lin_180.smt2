; ./prepared/vmt/./ctigar/xyz.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not H) (not D))
      )
      (state D C A B H E F G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Bool) ) 
    (=>
      (and
        (state D C A B Q K M O)
        (let ((a!1 (and (not I) H (not G) F (not E) (= K J) (= M L) (= O N)))
      (a!2 (and (not I)
                (not H)
                G
                (not F)
                E
                (= M L)
                (= O N)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!3 (and (not I) H G F (not E) (= M L) (= O N) (= (+ K (* (- 1) J)) 1)))
      (a!4 (and (not I)
                (not H)
                G
                F
                E
                (= K J)
                (= O N)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!5 (and (not I) H G (not F) E (= K J) (= O N) (= (+ M (* (- 1) L)) 1)))
      (a!6 (and (not I)
                H
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!7 (and (not I)
                H
                (not G)
                F
                E
                (= K J)
                (= M L)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!8 (and (not I)
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= (+ O (* (- 1) N)) 2)))
      (a!9 (and I (not H) (not G) (not F) E (= K J) (= M L) (= O N)))
      (a!10 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N))))
  (and (or Q
           (not B)
           (not A)
           (not D)
           (not C)
           (<= O (- 1))
           (and I (not H) (not G) (not F) (not E) (= K J) (= M L) (= O N)))
       (or A
           D
           Q
           (not B)
           (not C)
           (not (<= K 0))
           (and (not I) H G F E (= K J) (= M L) (= O N)))
       (or B C D Q (not A) (= P 0) a!1)
       (or A
           D
           Q
           (not B)
           (not C)
           (<= K 0)
           (and (not I) H (not G) (not F) E (= K J) (= M L) (= O N)))
       (or B
           C
           D
           Q
           (not A)
           (not (= P 0))
           (and (not I) (not H) G F (not E) (= K J) (= M L) (= O N)))
       (or B D Q (not A) (not C) a!2)
       (or C D Q (not B) (not A) a!3)
       (or B C Q (not A) (not D) a!4)
       (or D Q (not B) (not A) (not C) a!5)
       (or A Q (not B) (not D) (not C) a!6)
       (or A C Q (not B) (not D) a!7)
       (or B Q (not A) (not D) (not C) a!8)
       (or A
           B
           C
           D
           (not Q)
           (and I (not H) (not G) F (not E) (= K J) (= M L) (= O N)))
       (or A B C (not Q) (not D) a!9)
       (or C Q (not B) (not A) (not D) a!1)
       (or A
           C
           D
           Q
           (not B)
           (and (not I) (not H) G (not F) (not E) (= K J) (= M L) (= O N)))
       (or A B C D Q a!10)
       (or A B D (not Q) (not C) a!10)
       (or A
           B
           D
           Q
           (not C)
           (and (not I) (not H) (not G) (not F) E (= J 0) (= M L) (= O N)))
       (or A
           B
           C
           Q
           (not D)
           (and (not I) (not H) (not G) F E (= L 0) (= K J) (= O N)))
       (or A
           B
           Q
           (not D)
           (not C)
           (and (not I) (not H) G (not F) (not E) (= N 0) (= K J) (= M L)))
       (or Q (not B) (not A) (not D) (not C) (not (<= O (- 1))) a!9)))
      )
      (state E F G H I J L N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Bool) ) 
    (=>
      (and
        (state D C A B H E F G)
        (and (not C) (not B) (not A) (= H true) (= D true))
      )
      false
    )
  )
)

(check-sat)
(exit)
