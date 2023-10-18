; ./vmt/./ctigar/xyz2.c_000.smt2
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
        (let ((a!1 (and I (not H) G (not F) (not E) (= K J) (= M L) (= O N)))
      (a!2 (and (not I) (not H) G F E (= K J) (= M L) (= O N)))
      (a!3 (and (not I)
                (not H)
                (not G)
                (not F)
                E
                (= M L)
                (= O N)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!4 (and (not I) H G F (not E) (= M L) (= O N) (= (+ K (* (- 1) J)) 1)))
      (a!5 (and (not I)
                (not H)
                (not G)
                F
                E
                (= K J)
                (= O N)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!6 (and (not I)
                H
                (not G)
                (not F)
                E
                (= K J)
                (= O N)
                (= (+ M (* (- 1) L)) 1)))
      (a!7 (and (not I)
                H
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!8 (and (not I)
                H
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!9 (and (not I)
                (not H)
                G
                (not F)
                E
                (= K J)
                (= M L)
                (= (+ O (* (- 1) N)) 2)))
      (a!10 (and I (not H) G F (not E) (= K J) (= M L) (= O N)))
      (a!11 (and I (not H) (not G) (not F) E (= K J) (= M L) (= O N)))
      (a!12 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N))))
  (and (or C Q (not B) (not A) (not D) (<= 1 O) a!1)
       (or C
           Q
           (not B)
           (not A)
           (not D)
           (not (<= 1 O))
           (and (not I) H G F E (= K J) (= M L) (= O N)))
       (or D
           Q
           (not B)
           (not A)
           (not C)
           (not (<= K 0))
           (and (not I) H G (not F) E (= K J) (= M L) (= O N)))
       (or B
           Q
           (not A)
           (not D)
           (not C)
           (<= 1 K)
           (and (not I) H (not G) F E (= K J) (= M L) (= O N)))
       (or B
           Q
           (not A)
           (not D)
           (not C)
           (not (<= 1 K))
           (and (not I) H (not G) (not F) (not E) (= K J) (= M L) (= O N)))
       (or A B C Q (not D) (= P 0) a!2)
       (or A
           B
           C
           Q
           (not D)
           (not (= P 0))
           (and (not I) (not H) G F (not E) (= K J) (= M L) (= O N)))
       (or A B Q (not D) (not C) a!3)
       (or A C Q (not B) (not D) a!4)
       (or B C D Q (not A) a!5)
       (or A Q (not B) (not D) (not C) a!6)
       (or A D Q (not B) (not C) a!7)
       (or A C D Q (not B) a!8)
       (or B D Q (not A) (not C) a!9)
       (or A B C (not Q) (not D) a!10)
       (or A B D (not Q) (not C) a!1)
       (or A
           B
           C
           D
           (not Q)
           (and I (not H) (not G) F (not E) (= K J) (= M L) (= O N)))
       (or B C D (not Q) (not A) a!11)
       (or Q (not B) (not A) (not D) (not C) a!11)
       (or C D Q (not B) (not A) a!2)
       (or B
           C
           Q
           (not A)
           (not D)
           (and (not I) (not H) G (not F) (not E) (= K J) (= M L) (= O N)))
       (or A B C D Q a!12)
       (or A B (not Q) (not D) (not C) a!12)
       (or A
           B
           D
           Q
           (not C)
           (and (not I) (not H) G (not F) (not E) (= N 0) (= L 0) (= J 0)))
       (or D Q (not B) (not A) (not C) (<= K 0) a!10)))
      )
      (state G F E H I J L N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Bool) ) 
    (=>
      (and
        (state D C A B H E F G)
        (and (not C) (not B) (= A true) (= H true) (not D))
      )
      false
    )
  )
)

(check-sat)
(exit)
