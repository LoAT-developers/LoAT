; ./prepared/vmt/./ctigar/seq-sim.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not I) (not D))
      )
      (state D C A B I H G F E)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Bool) ) 
    (=>
      (and
        (state D C A B R Q O M K)
        (let ((a!1 (and I (not H) G F E (= K J) (= M L) (= O N) (= Q P)))
      (a!2 (and I
                (not H)
                G
                (not F)
                E
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!3 (and (not I)
                H
                G
                F
                (not E)
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!4 (and (not I)
                H
                (not G)
                (not F)
                E
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!5 (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!6 (and (not I)
                H
                (not G)
                F
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!7 (and (not I)
                (not H)
                G
                (not F)
                E
                (= K J)
                (= O N)
                (= Q P)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!8 (and I
                (not H)
                G
                F
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= (+ M (* (- 1) L)) 1)))
      (a!9 (and (not I) H G F E (= K J) (= O N) (= Q P) (= (+ M (* (- 1) L)) 1)))
      (a!10 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P))))
  (and (or A B C (not R) (not D) (not (<= M 0)) a!1)
       (or A
           B
           C
           (not R)
           (not D)
           (<= M 0)
           (and I (not H) (not G) F E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           D
           (not R)
           (not C)
           (<= Q K)
           (and I (not H) (not G) F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or C
           D
           R
           (not B)
           (not A)
           (not (<= O K))
           (and I
                (not H)
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or C
           D
           R
           (not B)
           (not A)
           (<= O K)
           (and (not I) H G (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or B
           R
           (not A)
           (not D)
           (not C)
           (not (<= O K))
           (and (not I) H (not G) F E (= K J) (= M L) (= O N) (= Q P)))
       (or B
           R
           (not A)
           (not D)
           (not C)
           (<= O K)
           (and (not I)
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A
           B
           C
           R
           (not D)
           (not (<= Q K))
           (and (not I) (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           C
           R
           (not D)
           (<= Q K)
           (and (not I) (not H) (not G) F E (= K J) (= M L) (= O N) (= Q P)))
       (or B C D (not R) (not A) a!2)
       (or D R (not B) (not A) (not C) a!3)
       (or A C D R (not B) a!4)
       (or A B R (not D) (not C) a!5)
       (or A D R (not B) (not C) a!6)
       (or B C D R (not A) a!7)
       (or B D (not R) (not A) (not C) a!8)
       (or C R (not B) (not A) (not D) a!9)
       (or B (not R) (not A) (not D) (not C) a!1)
       (or A
           B
           (not R)
           (not D)
           (not C)
           (and I (not H) G (not F) (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or B
           C
           (not R)
           (not A)
           (not D)
           (and I (not H) (not G) (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or R
           (not B)
           (not A)
           (not D)
           (not C)
           (and (not I) H G (not F) (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A
           C
           R
           (not B)
           (not D)
           (and (not I) (not H) G F E (= K J) (= M L) (= O N) (= Q P)))
       (or B
           D
           R
           (not A)
           (not C)
           (and (not I)
                (not H)
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A B C D R a!10)
       (or A C D (not R) (not B) a!10)
       (or A
           B
           C
           D
           (not R)
           (and I (not H) (not G) (not F) E (= J 0) (= M L) (= O N) (= Q P)))
       (or A
           R
           (not B)
           (not D)
           (not C)
           (and (not I) H G (not F) (not E) (= J 0) (= M L) (= O N) (= Q P)))
       (or B
           C
           R
           (not A)
           (not D)
           (and (not I) (not H) G F E (= J 0) (= M L) (= O N) (= Q P)))
       (or A
           B
           D
           R
           (not C)
           (and (not I)
                (not H)
                (not G)
                F
                (not E)
                (= L 0)
                (= J 0)
                (= O N)
                (= Q P)))
       (or A
           B
           D
           (not R)
           (not C)
           (not (<= Q K))
           (and I H (not G) (not F) (not E) (= K J) (= M L) (= O N) (= Q P)))))
      )
      (state F E G H I P N L J)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Bool) ) 
    (=>
      (and
        (state D C A B I H G F E)
        (and (= C true) (not B) (= A true) (= I true) (= D true))
      )
      false
    )
  )
)

(check-sat)
(exit)
