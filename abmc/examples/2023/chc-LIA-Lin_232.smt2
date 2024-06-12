; ./prepared/vmt/./ctigar/dillig20.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not L) (not D))
      )
      (state D C A B L E F G H I J K)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) ) 
    (=>
      (and
        (state D C A B Y K M O Q S U W)
        (let ((a!1 (and I
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
      (a!2 (= (+ O (* (- 1) Q) (* (- 1) W)) 0))
      (a!3 (and I
                H
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
      (a!4 (or B
               D
               Y
               (not A)
               (not C)
               (<= (+ M (* (- 1) U)) (- 1))
               (and I
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
                    (= W V))))
      (a!5 (and (not I)
                H
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
      (a!6 (not (<= (+ M (* (- 1) U)) (- 1))))
      (a!7 (and (not I)
                H
                (not G)
                F
                E
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!8 (and (not I)
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= S R)
                (= U T)
                (= W V)
                (= (+ Q (* (- 1) P)) (- 1))))
      (a!9 (and I
                (not H)
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= S R)
                (= U T)
                (= W V)
                (= (+ Q (* (- 1) P)) 1)))
      (a!10 (and (not I)
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
                 (= (+ W (* (- 1) V)) (- 1))))
      (a!11 (and (not I)
                 H
                 (not G)
                 F
                 (not E)
                 (= K J)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= (+ W (* (- 1) V)) 1)))
      (a!12 (and I
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
      (a!13 (and (not I)
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
  (and (or B (not Y) (not A) (not D) (not C) (not (<= 1 U)) (not (<= U S)) a!1)
       (or A B (not Y) (not D) (not C) a!2 a!3)
       (or A
           B
           D
           (not Y)
           (not C)
           (not (<= U M))
           (and I
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
           D
           (not Y)
           (not C)
           (<= U M)
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
       a!4
       (or A
           B
           (not Y)
           (not D)
           (not C)
           (not a!2)
           (and I
                (not H)
                (not G)
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
           C
           Y
           (not A)
           (not D)
           (= K M)
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
       (or A
           D
           Y
           (not B)
           (not C)
           (not (= X 0))
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
       (or A D Y (not B) (not C) (= X 0) a!5)
       (or B
           C
           Y
           (not A)
           (not D)
           (not (= K M))
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
       (or A
           B
           C
           Y
           (not D)
           a!2
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
       (or B
           D
           Y
           (not A)
           (not C)
           a!6
           (and (not I)
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
       (or A
           B
           C
           Y
           (not D)
           (not a!2)
           (and (not I)
                (not H)
                (not G)
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
           (not Y)
           (not A)
           (not D)
           (not C)
           (and (<= U S) (<= 1 U))
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
                (= W V)))
       (or B
           D
           (not Y)
           (not A)
           (not C)
           (and (<= S (- 1)) (<= 1 U))
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
       (or C D Y (not B) (not A) a!7)
       (or B Y (not A) (not D) (not C) a!8)
       (or Y (not B) (not A) (not D) (not C) a!9)
       (or C Y (not B) (not A) (not D) a!10)
       (or A C D Y (not B) a!11)
       (or A (not Y) (not B) (not D) (not C) a!12)
       (or A C (not Y) (not B) (not D) a!1)
       (or A
           C
           D
           (not Y)
           (not B)
           (and I
                H
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
       (or C D (not Y) (not B) (not A) a!3)
       (or B
           C
           (not Y)
           (not A)
           (not D)
           (and I
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
           C
           D
           (not Y)
           (not A)
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
       (or A
           B
           C
           D
           (not Y)
           (and (not I)
                H
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
       (or A Y (not B) (not D) (not C) a!5)
       (or D
           Y
           (not B)
           (not A)
           (not C)
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
       (or A B C D Y a!13)
       (or A B C (not Y) (not D) a!13)
       (or A B Y (not D) (not C) a!13)
       (or A D (not Y) (not B) (not C) a!13)
       (or A
           C
           Y
           (not B)
           (not D)
           (and (not I)
                H
                G
                F
                (not E)
                (= K J)
                (= M R)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)))
       (or B
           C
           D
           Y
           (not A)
           (and (not I)
                (not H)
                (not G)
                F
                E
                (= K J)
                (= L 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           B
           D
           Y
           (not C)
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= R 0)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)))
       (or B D (not Y) (not A) (not C) (not (<= 1 U)) (not (<= S (- 1))) a!12)))
      )
      (state G F E H I J L N P R T V)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (state D C A B L E F G H I J K)
        (and (= B true)
     (= L true)
     (or (and (not A) (not C) D) (and (not A) C D) (and A (not C) (not D))))
      )
      false
    )
  )
)

(check-sat)
(exit)
