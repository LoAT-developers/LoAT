; ./vmt/./ctigar/fig2.c_000.smt2
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
        (let ((a!1 (and I (not H) G F E (= K J) (= M L) (= O N) (= Q P)))
      (a!3 (not (<= 0 (+ (* 3 M) (* (- 1) O)))))
      (a!4 (and (not I) H G F (not E) (= K J) (= M L) (= O N) (= Q P)))
      (a!5 (and I (not H) (not G) F E (= K J) (= M L) (= O N) (= Q P)))
      (a!7 (and (not I)
                H
                G
                (not F)
                E
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J)) (- 10))))
      (a!8 (and (not I)
                H
                (not G)
                F
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!9 (and (not I)
                (not H)
                G
                (not F)
                E
                (= K J)
                (= O N)
                (= Q P)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!10 (or A
                B
                C
                D
                (not S)
                (and I
                     (not H)
                     (not G)
                     (not F)
                     E
                     (= K J)
                     (= O N)
                     (= Q P)
                     (= (+ M L) 0))))
      (a!11 (and (not I)
                 H
                 (not G)
                 F
                 E
                 (= K J)
                 (= M L)
                 (= Q P)
                 (= (+ O (* (- 1) N)) (- 3))))
      (a!12 (and (not I)
                 (not H)
                 G
                 F
                 (not E)
                 (= K J)
                 (= M L)
                 (= Q P)
                 (= (+ O (* (- 1) N)) (- 2))))
      (a!13 (or A
                B
                D
                (not S)
                (not C)
                (and I
                     (not H)
                     (not G)
                     F
                     (not E)
                     (= K J)
                     (= M L)
                     (= Q P)
                     (= (+ O N) 0))))
      (a!14 (and (not I)
                 H
                 G
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= (+ Q (* (- 1) P)) (- 10))))
      (a!15 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P))))
(let ((a!2 (or B C D (not S) (not A) (<= 0 (+ (* 3 M) (* (- 1) O))) a!1))
      (a!6 (or S
               (not B)
               (not A)
               (not D)
               (not C)
               (and (not (<= K O)) (<= Q M))
               a!5)))
  (and a!2
       (or B
           C
           D
           (not S)
           (not A)
           a!3
           (and I (not H) G (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           C
           S
           (not D)
           (= R 0)
           (and I (not H) G (not F) (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or B
           S
           (not A)
           (not D)
           (not C)
           (= R 0)
           (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P)))
       (or A C D S (not B) (<= 4 M) a!4)
       (or A
           C
           D
           S
           (not B)
           (not (<= 4 M))
           (and (not I) H (not G) (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or B
           S
           (not A)
           (not D)
           (not C)
           (not (= R 0))
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
           S
           (not D)
           (not C)
           (= R 0)
           (and (not I) (not H) G F E (= K J) (= M L) (= O N) (= Q P)))
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
       a!6
       (or C D S (not B) (not A) a!7)
       (or A D S (not B) (not C) a!8)
       (or B C D S (not A) a!9)
       a!10
       (or A C S (not B) (not D) a!11)
       (or B D S (not A) (not C) a!12)
       a!13
       (or A S (not B) (not D) (not C) a!14)
       (or B (not S) (not A) (not D) (not C) a!1)
       (or B
           D
           (not S)
           (not A)
           (not C)
           (and I (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A B C (not S) (not D) a!5)
       (or A B (not S) (not D) (not C) a!4)
       (or D S (not B) (not A) (not C) a!4)
       (or C
           S
           (not B)
           (not A)
           (not D)
           (and (not I) (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or B
           C
           S
           (not A)
           (not D)
           (and (not I)
                (not H)
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A B C D S a!15)
       (or B C (not S) (not A) (not D) a!15)
       (or A
           B
           D
           S
           (not C)
           (and (not I)
                (not H)
                (not G)
                F
                (not E)
                (= P 0)
                (= N 0)
                (= L 0)
                (= J 0)))
       (or S
           (not B)
           (not A)
           (not D)
           (not C)
           (<= K O)
           (and I
                (not H)
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P))
           (not (<= Q M))))))
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
