; ./prepared/vmt/./ctigar/seq.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not K) (not D))
      )
      (state D C A B K J I H G F E)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Bool) ) 
    (=>
      (and
        (state D C A B V U S Q O M K)
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
                (= U T)))
      (a!2 (or C
               D
               V
               (not B)
               (not A)
               (<= (+ U O (* (- 1) K)) 0)
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
                    (= U T))))
      (a!3 (and I
                (not H)
                (not G)
                (not F)
                (not E)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!4 (and (not I)
                H
                (not G)
                F
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!5 (and (not I)
                (not H)
                G
                (not F)
                E
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) (- 1))))
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
                (= (+ M (* (- 1) L)) 1)))
      (a!7 (and (not I)
                H
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= S R)
                (= U T)
                (= (+ Q (* (- 1) P)) (- 1))))
      (a!8 (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)
                (= (+ S (* (- 1) R)) (- 1))))
      (a!9 (and (not I)
                (not H)
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
      (a!10 (not (<= (+ U O (* (- 1) K)) 0))))
  (and (or D V (not B) (not A) (not C) (not (<= M 0)) a!1)
       (or D
           V
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
                (= U T)))
       a!2
       (or B
           V
           (not A)
           (not D)
           (not C)
           (not (<= U Q))
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
                (= U T)))
       (or B
           V
           (not A)
           (not D)
           (not C)
           (<= U Q)
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
                (= U T)))
       (or A
           B
           C
           V
           (not D)
           (not (<= O S))
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
                (= U T)))
       (or A
           B
           C
           V
           (not D)
           (<= O S)
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
                (= U T)))
       (or V (not B) (not A) (not D) (not C) a!3)
       (or A D V (not B) (not C) a!4)
       (or B C D V (not A) a!5)
       (or A B C D (not V) a!6)
       (or A C D V (not B) a!7)
       (or A B V (not D) (not C) a!8)
       (or A B C (not V) (not D) a!1)
       (or C
           V
           (not B)
           (not A)
           (not D)
           (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or A
           B
           D
           (not V)
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
                (= U T)))
       (or A
           C
           V
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
                (= U T)))
       (or B
           D
           V
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
                (= U T)))
       (or A B C D V a!9)
       (or A B (not V) (not D) (not C) a!9)
       (or A
           V
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
                (= U T)))
       (or B
           C
           V
           (not A)
           (not D)
           (and (not I)
                (not H)
                G
                F
                E
                (= P 0)
                (= K J)
                (= M L)
                (= O N)
                (= S R)
                (= U T)))
       (or A
           B
           D
           V
           (not C)
           (and (not I)
                (not H)
                (not G)
                F
                (not E)
                (= R 0)
                (= L 0)
                (= K J)
                (= O N)
                (= Q P)
                (= U T)))
       (or C
           D
           V
           (not B)
           (not A)
           a!10
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
                (= U T)))))
      )
      (state F E G H I T R P N L J)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) ) 
    (=>
      (and
        (state D C A B K J I H G F E)
        (and (not C) (not B) (not A) (= K true) (= D true))
      )
      false
    )
  )
)

(check-sat)
(exit)
