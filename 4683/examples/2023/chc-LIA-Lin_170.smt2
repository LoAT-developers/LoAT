; ./prepared/vmt/./ctigar/substring1.c_000.smt2
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
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) ) 
    (=>
      (and
        (state D C A B T K M O Q S)
        (let ((a!1 (and (not I)
                H
                G
                F
                (not E)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!2 (and (not I)
                H
                G
                (not F)
                E
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!3 (and I
                (not H)
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
      (a!4 (and (not I)
                (not H)
                (not G)
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R))))
  (and (or T
           (not B)
           (not A)
           (not D)
           (not C)
           (<= 101 M)
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
           T
           (not B)
           (not D)
           (not C)
           (not (<= O K))
           (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or A
           T
           (not B)
           (not D)
           (not C)
           (<= O K)
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
       (or B
           T
           (not A)
           (not D)
           (not C)
           (not (<= S O))
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
           T
           (not A)
           (not D)
           (not C)
           (<= S O)
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
           D
           T
           (not A)
           (not C)
           (not (<= 0 S))
           (and (not I) (not H) G F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or A
           B
           T
           (not D)
           (not C)
           (not (<= O 100))
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
       (or B
           D
           T
           (not A)
           (not C)
           (<= 0 S)
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
           T
           (not D)
           (not C)
           (<= O 100)
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
       (or A
           B
           D
           T
           (not C)
           (not (<= 0 O))
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
           (<= 0 O)
           (and (not I)
                (not H)
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or C D T (not B) (not A) a!1)
       (or D T (not B) (not A) (not C) a!2)
       (or A
           B
           C
           D
           (not T)
           (and I
                (not H)
                (not G)
                F
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A B C (not T) (not D) a!3)
       (or C
           T
           (not B)
           (not A)
           (not D)
           (and (not I) H (not G) F E (= K J) (= M L) (= O N) (= Q P) (= S R)))
       (or A B C D T a!4)
       (or A B C T (not D) a!4)
       (or A B D (not T) (not C) a!4)
       (or A C D T (not B) a!4)
       (or B C D T (not A) a!4)
       (or B C T (not A) (not D) a!4)
       (or A
           D
           T
           (not B)
           (not C)
           (and (not I)
                H
                (not G)
                (not F)
                E
                (= J S)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           C
           T
           (not B)
           (not D)
           (and (not I) H (not G) F E (= L 0) (= K J) (= O N) (= Q P) (= S R)))
       (or T (not B) (not A) (not D) (not C) (not (<= 101 M)) a!3)))
      )
      (state E F G H I J L N P R)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (state D C A B J E F G H I)
        (and (not C) (not B) (not A) (= J true) (= D true))
      )
      false
    )
  )
)

(check-sat)
(exit)
