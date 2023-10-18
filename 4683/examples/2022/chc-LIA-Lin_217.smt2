; ./vmt/./ctigar/dillig19.c_000.smt2
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
        (let ((a!1 (or B
               C
               D
               (not R)
               (not A)
               (<= (+ K (* (- 1) Q)) (- 1))
               (and I (not H) G (not F) E (= K J) (= M L) (= O N) (= Q P))))
      (a!2 (or A
               D
               R
               (not B)
               (not C)
               (<= 1 (+ K (* (- 1) M)))
               (and I (not H) (not G) F (not E) (= K J) (= M L) (= O N) (= Q P))))
      (a!3 (or A
               R
               (not B)
               (not D)
               (not C)
               (<= 1 (+ M (* (- 1) O)))
               (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P))))
      (a!4 (not (<= 1 (+ M (* (- 1) O)))))
      (a!5 (not (<= 1 (+ K (* (- 1) M)))))
      (a!6 (not (<= 1 (+ K (* (- 1) O)))))
      (a!7 (and (not I) H (not G) (not F) E (= K J) (= M L) (= O N) (= Q P)))
      (a!8 (or B
               R
               (not A)
               (not D)
               (not C)
               (<= 1 (+ K (* (- 1) O)))
               (and (not I)
                    H
                    (not G)
                    (not F)
                    (not E)
                    (= K J)
                    (= M L)
                    (= O N)
                    (= Q P))))
      (a!9 (and (not I)
                H
                (not G)
                F
                E
                (= K J)
                (= O N)
                (= Q P)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!10 (and (not I)
                 H
                 G
                 (not F)
                 E
                 (= K J)
                 (= M L)
                 (= O N)
                 (= (+ Q (* (- 1) P)) (- 1))))
      (a!11 (and I (not H) G F E (= K J) (= M L) (= O N) (= Q P)))
      (a!12 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)))
      (a!13 (not (<= (+ K (* (- 1) Q)) (- 1)))))
  (and a!1
       (or A
           B
           C
           (not R)
           (not D)
           (not (<= K M))
           (and I (not H) G (not F) (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           C
           (not R)
           (not D)
           (<= K M)
           (and I (not H) (not G) F E (= K J) (= M L) (= O N) (= Q P)))
       a!2
       (or R
           (not B)
           (not A)
           (not D)
           (not C)
           (not (<= M O))
           (and I (not H) (not G) (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or R
           (not B)
           (not A)
           (not D)
           (not C)
           (<= M O)
           (and I
                (not H)
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       a!3
       (or A
           R
           (not B)
           (not D)
           (not C)
           a!4
           (and (not I) H G (not F) (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A
           D
           R
           (not B)
           (not C)
           a!5
           (and (not I) H (not G) F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or B R (not A) (not D) (not C) a!6 a!7)
       a!8
       (or B
           D
           R
           (not A)
           (not C)
           (not (<= 0 O))
           (and (not I) (not H) G F E (= K J) (= M L) (= O N) (= Q P)))
       (or B
           D
           R
           (not A)
           (not C)
           (<= 0 O)
           (and (not I) (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           R
           (not D)
           (not C)
           (not (<= 0 K))
           (and (not I) (not H) G (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           R
           (not D)
           (not C)
           (<= 0 K)
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A C R (not B) (not D) a!9)
       (or C D R (not B) (not A) a!10)
       (or B (not R) (not A) (not D) (not C) a!11)
       (or B
           D
           (not R)
           (not A)
           (not C)
           (and I (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or D
           R
           (not B)
           (not A)
           (not C)
           (and (not I) H G F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           D
           (not R)
           (not C)
           (and (not I) H G (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or C R (not B) (not A) (not D) a!7)
       (or A B C D R a!12)
       (or A B C D (not R) a!12)
       (or A B (not R) (not D) (not C) a!12)
       (or A C D R (not B) a!12)
       (or B C D R (not A) a!12)
       (or B C R (not A) (not D) a!12)
       (or B C (not R) (not A) (not D) a!12)
       (or A
           B
           C
           R
           (not D)
           (and (not I) (not H) (not G) F E (= K J) (= M L) (= O P) (= O N)))
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
                (= K J)
                (= O N)
                (= Q P)))
       (or B C D (not R) (not A) a!13 a!11)))
      )
      (state F E G H I J L N P)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Bool) ) 
    (=>
      (and
        (state D C A B I E F G H)
        (and (= C true) (not B) (= A true) (= I true) (= D true))
      )
      false
    )
  )
)

(check-sat)
(exit)
