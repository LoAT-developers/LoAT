; ./vmt/./ctigar/dillig33.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not J) (not D))
      )
      (state D C A B J E F G H I)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Bool) ) 
    (=>
      (and
        (state D C A B U K M O Q S)
        (let ((a!1 (and I
                (not H)
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
      (a!2 (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
      (a!3 (= (+ K (* (- 1) O) Q (* (- 1) S)) 0))
      (a!4 (and (not I)
                H
                (not G)
                (not F)
                E
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!5 (and (not I)
                (not H)
                (not G)
                (not F)
                E
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!6 (and I
                (not H)
                (not G)
                F
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= (+ M (* (- 1) L)) 1)))
      (a!7 (and (not I)
                H
                G
                (not F)
                E
                (= K J)
                (= M L)
                (= Q P)
                (= S R)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!8 (and (not I)
                (not H)
                G
                (not F)
                E
                (= K J)
                (= M L)
                (= Q P)
                (= S R)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!9 (and (not I)
                (not H)
                (not G)
                F
                E
                (= K J)
                (= M L)
                (= O N)
                (= S R)
                (= (+ Q (* (- 1) P)) (- 1))))
      (a!10 (and I
                 (not H)
                 G
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= S R)
                 (= (+ Q (* (- 1) P)) 1)))
      (a!11 (and (not I)
                 H
                 (not G)
                 F
                 E
                 (= K J)
                 (= M L)
                 (= O N)
                 (= S R)
                 (= (+ Q (* (- 1) P)) 1)))
      (a!12 (and I
                 H
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= (+ K Q (* (- 1) R)) 0)))
      (a!13 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R))))
  (and (or A
           B
           U
           (not D)
           (not C)
           (= T 0)
           (and I H (not G) F (not E) (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or U
           (not B)
           (not A)
           (not D)
           (not C)
           (= T 0)
           (and I (not H) G F (not E) (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or B D (not U) (not A) (not C) (= M Q) a!1)
       (or U
           (not B)
           (not A)
           (not D)
           (not C)
           (not (= T 0))
           (and I
                (not H)
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B D U (not A) (not C) (= T 0) a!2)
       (or B
           C
           U
           (not A)
           (not D)
           (not a!3)
           (and (not I) H G F (not E) (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or B
           D
           U
           (not A)
           (not C)
           (not (= T 0))
           (and (not I)
                H
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           U
           (not D)
           (not C)
           (not (= T 0))
           (and (not I)
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           C
           U
           (not A)
           (not D)
           a!3
           (and (not I) (not H) G F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or A U (not B) (not D) (not C) a!4)
       (or B U (not A) (not D) (not C) a!5)
       (or A B C D (not U) a!6)
       (or D U (not B) (not A) (not C) a!7)
       (or A D U (not B) (not C) a!8)
       (or A C D U (not B) a!9)
       (or A B D (not U) (not C) a!10)
       (or C D U (not B) (not A) a!11)
       (or A B (not U) (not D) (not C) a!12)
       (or B
           C
           (not U)
           (not A)
           (not D)
           (and I H G F (not E) (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or A C D (not U) (not B) a!1)
       (or A B C (not U) (not D) a!2)
       (or A
           C
           U
           (not B)
           (not D)
           (and (not I)
                H
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           C
           D
           (not U)
           (not A)
           (and (not I)
                (not H)
                G
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or C
           U
           (not B)
           (not A)
           (not D)
           (and (not I)
                (not H)
                G
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A B C D U a!13)
       (or B (not U) (not A) (not D) (not C) a!13)
       (or A
           B
           D
           U
           (not C)
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= K R)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or B
           C
           D
           U
           (not A)
           (and (not I)
                H
                (not G)
                F
                (not E)
                (= N 0)
                (= K J)
                (= M L)
                (= Q P)
                (= S R)))
       (or A
           B
           C
           U
           (not D)
           (and (not I)
                (not H)
                G
                F
                (not E)
                (= P 0)
                (= L 0)
                (= K J)
                (= O N)
                (= S R)))
       (or B
           D
           (not U)
           (not A)
           (not C)
           (not (= M Q))
           (and I H G (not F) (not E) (= K J) (= M L) (= O N) (= Q P) (= S R)))))
      )
      (state G F H E I J L N P R)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (state D C A B J E F G H I)
        (and (not C) (= B true) (not A) (= J true) (not D))
      )
      false
    )
  )
)

(check-sat)
(exit)
