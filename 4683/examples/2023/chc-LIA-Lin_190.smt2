; ./prepared/vmt/./ctigar/dillig17.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not I) (not D))
      )
      (state D C A B I E F G H)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Bool) ) 
    (=>
      (and
        (state D C A B R K M O Q)
        (let ((a!1 (or R
               (not B)
               (not A)
               (not D)
               (not C)
               (<= (+ O (* (- 1) Q)) (- 1))
               (and I
                    (not H)
                    (not G)
                    (not F)
                    (not E)
                    (= K J)
                    (= M L)
                    (= O N)
                    (= Q P))))
      (a!2 (or A
               B
               R
               (not D)
               (not C)
               (<= (+ K (* (- 1) Q)) (- 1))
               (and (not I) H G F (not E) (= K J) (= M L) (= O N) (= Q P))))
      (a!3 (or B
               D
               R
               (not A)
               (not C)
               (<= 1 (+ K (* (- 1) M)))
               (and (not I) H (not G) F (not E) (= K J) (= M L) (= O N) (= Q P))))
      (a!4 (not (<= 1 (+ K (* (- 1) M)))))
      (a!5 (not (<= (+ K (* (- 1) Q)) (- 1))))
      (a!6 (and (not I)
                H
                G
                (not F)
                (not E)
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!7 (and (not I)
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!8 (and (not I)
                (not H)
                G
                F
                E
                (= K J)
                (= M L)
                (= Q P)
                (= (+ K (* (- 1) M) O (* (- 1) N)) 0)))
      (a!9 (and I (not H) (not G) (not F) E (= K J) (= M L) (= O N) (= Q P)))
      (a!10 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)))
      (a!11 (not (<= (+ O (* (- 1) Q)) (- 1)))))
  (and a!1
       (or D
           R
           (not B)
           (not A)
           (not C)
           (not (<= Q K))
           (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P)))
       a!2
       (or D
           R
           (not B)
           (not A)
           (not C)
           (<= Q K)
           (and (not I) H G (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           D
           R
           (not B)
           (not C)
           (not (<= K M))
           (and (not I) H (not G) F E (= K J) (= M L) (= O N) (= Q P)))
       a!3
       (or A
           D
           R
           (not B)
           (not C)
           (<= K M)
           (and (not I) H (not G) (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or B
           D
           R
           (not A)
           (not C)
           a!4
           (and (not I) (not H) G (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           R
           (not D)
           (not C)
           a!5
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A R (not B) (not D) (not C) a!6)
       (or B R (not A) (not D) (not C) a!7)
       (or B C R (not A) (not D) a!8)
       (or A
           B
           C
           D
           (not R)
           (and I (not H) (not G) F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A B C (not R) (not D) a!9)
       (or A
           C
           D
           R
           (not B)
           (and (not I) (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or C
           D
           R
           (not B)
           (not A)
           (and (not I) (not H) (not G) F E (= K J) (= M L) (= O N) (= Q P)))
       (or A B C D R a!10)
       (or A B D (not R) (not C) a!10)
       (or A C R (not B) (not D) a!10)
       (or C R (not B) (not A) (not D) a!10)
       (or B
           C
           D
           R
           (not A)
           (and (not I) (not H) G F (not E) (= L 0) (= K J) (= O N) (= Q P)))
       (or A
           B
           C
           R
           (not D)
           (and (not I) (not H) (not G) F E (= L 0) (= K J) (= O N) (= Q P)))
       (or A
           B
           D
           R
           (not C)
           (and (not I)
                (not H)
                (not G)
                (not F)
                E
                (= N 1)
                (= J 1)
                (= M L)
                (= Q P)))
       (or R (not B) (not A) (not D) (not C) a!11 a!9)))
      )
      (state E F G H I J L N P)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Bool) ) 
    (=>
      (and
        (state D C A B I E F G H)
        (and (not C) (not B) (not A) (= I true) (= D true))
      )
      false
    )
  )
)

(check-sat)
(exit)
