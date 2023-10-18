; ./prepared/vmt/./ctigar/nested8.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not J) (not D))
      )
      (state D C A B J I H G F E)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) ) 
    (=>
      (and
        (state D C A B T S Q O M K)
        (let ((a!1 (not (<= (+ S Q (* (- 1) O)) 0)))
      (a!2 (<= 0 (+ S Q O (* (- 1) M) (* (- 1) K))))
      (a!3 (and (not I) H G (not F) E (= K J) (= M L) (= O N) (= Q P) (= S R)))
      (a!4 (or A
               C
               D
               T
               (not B)
               (<= (+ S Q (* (- 1) O)) 0)
               (and (not I)
                    H
                    (not G)
                    (not F)
                    E
                    (= K J)
                    (= M L)
                    (= O N)
                    (= Q P)
                    (= S R))))
      (a!5 (and I
                (not H)
                (not G)
                (not F)
                E
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!6 (and (not I)
                H
                G
                F
                E
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!7 (and (not I)
                H
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= Q P)
                (= S R)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!8 (and (not I)
                (not H)
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R))))
  (and (or B
           C
           T
           (not A)
           (not D)
           (not (<= S M))
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
       (or A
           C
           D
           T
           (not B)
           a!1
           (and (not I) H G F (not E) (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or A D T (not B) (not C) a!2 a!3)
       (or A
           D
           T
           (not B)
           (not C)
           (not a!2)
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
       a!4
       (or B
           C
           T
           (not A)
           (not D)
           (<= S M)
           (and (not I) (not H) G F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or B
           C
           D
           T
           (not A)
           (<= S K)
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
       (or A
           B
           D
           T
           (not C)
           (not (<= S Q))
           (and (not I)
                (not H)
                (not G)
                F
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           D
           T
           (not C)
           (<= S Q)
           (and (not I)
                (not H)
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A B C D (not T) a!5)
       (or C T (not B) (not A) (not D) a!6)
       (or A T (not B) (not D) (not C) a!7)
       (or D T (not B) (not A) (not C) a!3)
       (or A
           C
           T
           (not B)
           (not D)
           (and (not I) H (not G) F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or C
           D
           T
           (not B)
           (not A)
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
       (or T
           (not B)
           (not A)
           (not D)
           (not C)
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
       (or A
           B
           D
           (not T)
           (not C)
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A B C D T a!8)
       (or A B C T (not D) a!8)
       (or A B C (not T) (not D) a!8)
       (or A
           B
           T
           (not D)
           (not C)
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= J 0)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           D
           T
           (not A)
           (not C)
           (and (not I)
                (not H)
                G
                F
                (not E)
                (= L 0)
                (= K J)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           T
           (not A)
           (not D)
           (not C)
           (and (not I)
                H
                (not G)
                (not F)
                (not E)
                (= N M)
                (= K J)
                (= M L)
                (= Q P)
                (= S R)))
       (or B
           C
           D
           T
           (not A)
           (not (<= S K))
           (and I
                (not H)
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))))
      )
      (state F E G H I R P N L J)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (state D C A B J I H G F E)
        (and (= C true) (= B true) (= A true) (not J) (not D))
      )
      false
    )
  )
)

(check-sat)
(exit)
