; ./vmt/./ctigar/fragtest_simple.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not K) (not D))
      )
      (state D C A B K E F G H I J)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) ) 
    (=>
      (and
        (state D C A B W K M O Q S U)
        (let ((a!1 (and I
                H
                (not G)
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
      (a!2 (and (not I)
                H
                G
                (not F)
                E
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
      (a!3 (and (not I)
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
      (a!4 (and (not I)
                H
                (not G)
                (not F)
                E
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!5 (and (not I)
                (not H)
                (not G)
                (not F)
                E
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!6 (and I
                (not H)
                G
                F
                E
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ K (* (- 1) J)) 1)))
      (a!7 (and I
                H
                (not G)
                (not F)
                (not E)
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!8 (and (not I)
                H
                (not G)
                F
                E
                (= K J)
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!9 (and I
                (not H)
                G
                (not F)
                E
                (= K J)
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ O (* (- 1) N)) 1)))
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
                 (= U T))))
  (and (or A
           C
           D
           (not W)
           (not B)
           (not (<= U M))
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
                (= U T)))
       (or A B (not W) (not D) (not C) (<= 0 O) a!1)
       (or A
           B
           (not W)
           (not D)
           (not C)
           (not (<= 0 O))
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
                (= U T)))
       (or C
           W
           (not B)
           (not A)
           (not D)
           (= V 0)
           (and I
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
       (or C
           W
           (not B)
           (not A)
           (not D)
           (not (= V 0))
           (and (not I) H G F E (= K J) (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or A D W (not B) (not C) (= V 0) a!2)
       (or A
           D
           W
           (not B)
           (not C)
           (not (= V 0))
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
       (or B D W (not A) (not C) (not (<= K Q)) a!3)
       (or A
           B
           C
           W
           (not D)
           (not (= V 0))
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
       (or B
           D
           W
           (not A)
           (not C)
           (<= K Q)
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
                (= U T)))
       (or A
           B
           C
           W
           (not D)
           (= V 0)
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
       (or A W (not B) (not D) (not C) a!4)
       (or A B W (not D) (not C) a!5)
       (or B C (not W) (not A) (not D) a!6)
       (or A
           C
           D
           W
           (not B)
           (and (not I)
                H
                (not G)
                F
                (not E)
                (= J 0)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B (not W) (not A) (not D) (not C) a!7)
       (or C D W (not B) (not A) a!8)
       (or B D (not W) (not A) (not C) a!9)
       (or A
           D
           (not W)
           (not B)
           (not C)
           (and I
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
       (or C D (not W) (not B) (not A) a!1)
       (or A
           B
           C
           (not W)
           (not D)
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
                (= U T)))
       (or A
           (not W)
           (not B)
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
                (= U T)))
       (or B
           C
           D
           (not W)
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
                (= U T)))
       (or W (not B) (not A) (not D) (not C) a!2)
       (or D
           W
           (not B)
           (not A)
           (not C)
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
                (= U T)))
       (or B W (not A) (not D) (not C) a!3)
       (or B
           C
           D
           W
           (not A)
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A B C D W a!10)
       (or A C (not W) (not B) (not D) a!10)
       (or B
           C
           W
           (not A)
           (not D)
           (and (not I)
                (not H)
                G
                F
                E
                (= K P)
                (= K J)
                (= M L)
                (= O N)
                (= S R)
                (= U T)))
       (or A
           C
           W
           (not B)
           (not D)
           (and (not I)
                H
                G
                F
                (not E)
                (= K R)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)))
       (or A
           B
           D
           (not W)
           (not C)
           (and I
                (not H)
                G
                (not F)
                (not E)
                (= K T)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           C
           D
           (not W)
           (and I
                (not H)
                (not G)
                F
                (not E)
                (= L 0)
                (= K J)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           D
           W
           (not C)
           (and (not I)
                (not H)
                G
                (not F)
                (not E)
                (= N 0)
                (= J 0)
                (= M L)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           C
           D
           (not W)
           (not B)
           (<= U M)
           (and I H G F (not E) (= K J) (= M L) (= O N) (= Q P) (= S R) (= U T)))))
      )
      (state G F E H I J L N P R T)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) ) 
    (=>
      (and
        (state D C A B K E F G H I J)
        (and (not C) (= B true) (= A true) (= K true) (not D))
      )
      false
    )
  )
)

(check-sat)
(exit)
