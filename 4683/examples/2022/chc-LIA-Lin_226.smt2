; ./vmt/./ctigar/gulv.c_000.smt2
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
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Bool) ) 
    (=>
      (and
        (state D C A B S K M O Q)
        (let ((a!1 (not (<= (+ (* 100 M) (* (- 1) Q)) 0)))
      (a!3 (and (not I) H G (not F) E (= K J) (= M L) (= O N) (= Q P)))
      (a!4 (not (<= 0 (+ (* 10 K) (* (- 1) O)))))
      (a!6 (and I (not H) (not G) (not F) E (= K J) (= M L) (= O N) (= Q P)))
      (a!7 (and (not I)
                (not H)
                G
                F
                E
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!8 (and (not I)
                H
                G
                (not F)
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!9 (and (not I)
                (not H)
                G
                F
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!10 (and (not I)
                 (not H)
                 G
                 (not F)
                 E
                 (= K J)
                 (= M L)
                 (= Q P)
                 (= (+ O (* (- 1) N)) (- 100))))
      (a!11 (and (not I)
                 H
                 G
                 F
                 (not E)
                 (= K J)
                 (= M L)
                 (= Q P)
                 (= (+ O (* (- 1) N)) (- 1))))
      (a!12 (or A
                B
                C
                D
                (not S)
                (and I
                     (not H)
                     (not G)
                     F
                     (not E)
                     (= K J)
                     (= M L)
                     (= Q P)
                     (= (+ O N) 0))))
      (a!13 (and (not I)
                 H
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= (+ Q (* (- 1) P)) (- 10))))
      (a!14 (and I (not H) G (not F) E (= K J) (= M L) (= O N) (= Q P)))
      (a!15 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P))))
(let ((a!2 (or S
               (not B)
               (not A)
               (not D)
               (not C)
               (<= 0 (+ (* 10 K) (* (- 1) O)))
               (and I
                    (not H)
                    (not G)
                    (not F)
                    (not E)
                    (= K J)
                    (= M L)
                    (= O N)
                    (= Q P))
               a!1))
      (a!5 (and (<= (+ (* 100 M) (* (- 1) Q)) 0) a!4)))
  (and a!2
       (or A
           B
           C
           S
           (not D)
           (= R 0)
           (and I (not H) (not G) F E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           D
           S
           (not B)
           (not C)
           (= R 0)
           (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P)))
       (or A C S (not B) (not D) (<= 4 M) a!3)
       (or A
           C
           S
           (not B)
           (not D)
           (not (<= 4 M))
           (and (not I) H (not G) F E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           S
           (not D)
           (not C)
           (= R 0)
           (and (not I) H (not G) F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A
           D
           S
           (not B)
           (not C)
           (not (= R 0))
           (and (not I) H (not G) (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           S
           (not D)
           (not C)
           (not (= R 0))
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A
           B
           C
           S
           (not D)
           (not (= R 0))
           (and (not I) (not H) (not G) F E (= K J) (= M L) (= O N) (= Q P)))
       (or S (not B) (not A) (not D) (not C) a!5 a!6)
       (or A
           B
           (not S)
           (not D)
           (not C)
           (and (<= O 2) (<= 4 M))
           (and I (not H) G (not F) (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or B C S (not A) (not D) a!7)
       (or A S (not B) (not D) (not C) a!8)
       (or B C D S (not A) a!9)
       (or B D S (not A) (not C) a!10)
       (or C D S (not B) (not A) a!11)
       a!12
       (or B S (not A) (not D) (not C) a!13)
       (or B
           C
           D
           (not S)
           (not A)
           (and I (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or B C (not S) (not A) (not D) a!14)
       (or A B D (not S) (not C) a!6)
       (or A B C (not S) (not D) a!3)
       (or D S (not B) (not A) (not C) a!3)
       (or C
           S
           (not B)
           (not A)
           (not D)
           (and (not I) (not H) G (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           C
           D
           S
           (not B)
           (and (not I)
                (not H)
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A B C D S a!15)
       (or B D (not S) (not A) (not C) a!15)
       (or A
           B
           D
           S
           (not C)
           (and (not I)
                (not H)
                (not G)
                (not F)
                E
                (= P 0)
                (= N 0)
                (= L 0)
                (= J 0)))
       (or A B (not S) (not D) (not C) (not (<= 4 M)) (not (<= O 2)) a!14))))
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
        (and (not C) (not B) (= A true) (= I true) (= D true))
      )
      false
    )
  )
)

(check-sat)
(exit)
