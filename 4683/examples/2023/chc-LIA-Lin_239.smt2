; ./prepared/vmt/./ctigar/rajamani_1.c_000.smt2
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
        (let ((a!1 (and I H (not G) (not F) E (= K J) (= M L) (= O N) (= Q P)))
      (a!2 (not (<= 0 (+ (* 10 K) (* (- 1) O)))))
      (a!3 (and I (not H) G (not F) (not E) (= K J) (= M L) (= O N) (= Q P)))
      (a!4 (and I (not H) (not G) F E (= K J) (= M L) (= O N) (= Q P)))
      (a!6 (not (<= (+ (* 100 M) (* (- 1) Q)) 0)))
      (a!7 (or S
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
                    (= Q P))))
      (a!8 (and (not I) H G (not F) E (= K J) (= M L) (= O N) (= Q P)))
      (a!9 (and (not I)
                (not H)
                G
                F
                E
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!10 (and (not I)
                 H
                 G
                 (not F)
                 (not E)
                 (= K J)
                 (= O N)
                 (= Q P)
                 (= (+ M (* (- 1) L)) (- 1))))
      (a!11 (and (not I)
                 (not H)
                 G
                 F
                 (not E)
                 (= K J)
                 (= O N)
                 (= Q P)
                 (= (+ M (* (- 1) L)) (- 1))))
      (a!12 (and (not I)
                 (not H)
                 G
                 (not F)
                 E
                 (= K J)
                 (= M L)
                 (= Q P)
                 (= (+ O (* (- 1) N)) (- 100))))
      (a!13 (and (not I)
                 H
                 G
                 F
                 (not E)
                 (= K J)
                 (= M L)
                 (= Q P)
                 (= (+ O (* (- 1) N)) (- 1))))
      (a!14 (or A
                B
                D
                (not S)
                (not C)
                (and I
                     (not H)
                     (not G)
                     (not F)
                     E
                     (= K J)
                     (= M L)
                     (= Q P)
                     (= (+ O N) 0))))
      (a!15 (and (not I)
                 H
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= (+ Q (* (- 1) P)) (- 10))))
      (a!16 (and I H (not G) F (not E) (= K J) (= M L) (= O N) (= Q P)))
      (a!17 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P))))
(let ((a!5 (or A B C D (not S) (<= (+ (* 100 M) (* (- 1) Q)) 0) a!4)))
  (and (or B C (not S) (not A) (not D) (not (<= O 2)) a!1)
       (or B
           C
           (not S)
           (not A)
           (not D)
           (<= O 2)
           (and I (not H) G F E (= K J) (= M L) (= O N) (= Q P)))
       (or A
           B
           C
           S
           (not D)
           (= R 0)
           (and I (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or B
           D
           (not S)
           (not A)
           (not C)
           (not (<= 4 M))
           (and I (not H) G (not F) E (= K J) (= M L) (= O N) (= Q P)))
       (or S (not B) (not A) (not D) (not C) a!2 a!3)
       a!5
       (or A
           B
           C
           D
           (not S)
           a!6
           (and I (not H) (not G) F (not E) (= K J) (= M L) (= O N) (= Q P)))
       a!7
       (or A
           D
           S
           (not B)
           (not C)
           (= R 0)
           (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P)))
       (or A C S (not B) (not D) (<= 4 M) a!8)
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
       (or B C S (not A) (not D) a!9)
       (or A S (not B) (not D) (not C) a!10)
       (or B C D S (not A) a!11)
       (or B D S (not A) (not C) a!12)
       (or C D S (not B) (not A) a!13)
       a!14
       (or B S (not A) (not D) (not C) a!15)
       (or A C D (not S) (not B) a!16)
       (or A C (not S) (not B) (not D) a!1)
       (or B
           (not S)
           (not A)
           (not D)
           (not C)
           (and I H (not G) (not F) (not E) (= K J) (= M L) (= O N) (= Q P)))
       (or A B (not S) (not D) (not C) a!3)
       (or A B C (not S) (not D) a!4)
       (or B C D (not S) (not A) a!8)
       (or D S (not B) (not A) (not C) a!8)
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
       (or A B C D S a!17)
       (or A D (not S) (not B) (not C) a!17)
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
       (or B D (not S) (not A) (not C) (<= 4 M) a!16))))
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
        (and (not C) (= B true) (not A) (= I true) (= D true))
      )
      false
    )
  )
)

(check-sat)
(exit)
