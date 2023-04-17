; ./vmt/./ctigar/seq4.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not L) (not D))
      )
      (state D C A B L K J I H G F E)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Bool) ) 
    (=>
      (and
        (state D C A B X W U S Q O M K)
        (let ((a!1 (and I
                (not H)
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
      (a!2 (and I
                (not H)
                (not G)
                (not F)
                (not E)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!3 (and (not I)
                H
                (not G)
                F
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!4 (and (not I)
                (not H)
                G
                (not F)
                E
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!5 (and I
                (not H)
                G
                F
                E
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ M (* (- 1) L)) 1)))
      (a!6 (and I
                (not H)
                (not G)
                (not F)
                E
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ M (* (- 1) L)) 1)))
      (a!7 (and I
                (not H)
                G
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= S R)
                (= U T)
                (= W V)
                (= (+ Q (* (- 1) P)) (- 1))))
      (a!8 (and (not I)
                H
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)
                (= (+ S (* (- 1) R)) (- 1))))
      (a!9 (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= W V)
                (= (+ U (* (- 1) T)) (- 1))))
      (a!10 (and (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V))))
  (and (or B
           C
           D
           (not X)
           (not A)
           (<= O Q)
           (and I
                (not H)
                G
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or C
           D
           X
           (not B)
           (not A)
           (not (<= W K))
           (and I
                (not H)
                (not G)
                F
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or D X (not B) (not A) (not C) (not (<= M 0)) a!1)
       (or D
           X
           (not B)
           (not A)
           (not C)
           (<= M 0)
           (and (not I)
                H
                G
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or C
           D
           X
           (not B)
           (not A)
           (<= W K)
           (and (not I)
                H
                G
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or B
           X
           (not A)
           (not D)
           (not C)
           (not (<= W S))
           (and (not I)
                H
                (not G)
                F
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or B
           X
           (not A)
           (not D)
           (not C)
           (<= W S)
           (and (not I)
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           B
           C
           X
           (not D)
           (not (<= O U))
           (and (not I)
                (not H)
                G
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           B
           C
           X
           (not D)
           (<= O U)
           (and (not I)
                (not H)
                (not G)
                F
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or X (not B) (not A) (not D) (not C) a!2)
       (or A
           X
           (not B)
           (not D)
           (not C)
           (and (not I)
                H
                G
                (not F)
                (not E)
                (= J 0)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A D X (not B) (not C) a!3)
       (or B C D X (not A) a!4)
       (or B C (not X) (not A) (not D) a!5)
       (or A B C D (not X) a!6)
       (or B D (not X) (not A) (not C) a!7)
       (or A C D X (not B) a!8)
       (or A B X (not D) (not C) a!9)
       (or B
           (not X)
           (not A)
           (not D)
           (not C)
           (and I
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A B C (not X) (not D) a!1)
       (or C
           X
           (not B)
           (not A)
           (not D)
           (and (not I)
                H
                G
                F
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           B
           D
           (not X)
           (not C)
           (and (not I)
                H
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           C
           X
           (not B)
           (not D)
           (and (not I)
                (not H)
                G
                F
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or B
           D
           X
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
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A B C D X a!10)
       (or A C D (not X) (not B) a!10)
       (or A
           B
           (not X)
           (not D)
           (not C)
           (and I
                (not H)
                G
                (not F)
                (not E)
                (= P 0)
                (= K J)
                (= M L)
                (= O N)
                (= S R)
                (= U T)
                (= W V)))
       (or B
           C
           X
           (not A)
           (not D)
           (and (not I)
                (not H)
                G
                F
                E
                (= R 0)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)))
       (or A
           B
           D
           X
           (not C)
           (and (not I)
                (not H)
                (not G)
                F
                (not E)
                (= T 0)
                (= L 0)
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= W V)))
       (or B
           C
           D
           (not X)
           (not A)
           (not (<= O Q))
           (and I
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))))
      )
      (state F E G H I V T R P N L J)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (state D C A B L K J I H G F E)
        (and (not C) (not B) (not A) (= L true) (= D true))
      )
      false
    )
  )
)

(check-sat)
(exit)
