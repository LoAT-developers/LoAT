; ./vmt/./ctigar/lifnatprime.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Bool) ) 
    (=>
      (and
        (and (= E true) (not D) (not C) (not B) (not A) (not N) (not F))
      )
      (state F E D C B A N G H I J K L M)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) ) 
    (=>
      (and
        (state F E D C B A C1 O Q S U W Y A1)
        (let ((a!1 (<= 1 (+ O Q S U W Y A1)))
      (a!2 (and M
                L
                K
                J
                I
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
      (a!3 (or A
               D
               F
               (not C1)
               (not B)
               (not C)
               (not E)
               (not (<= (+ U Y) 1))
               (and M
                    L
                    K
                    (not J)
                    I
                    (not H)
                    (not G)
                    (= O N)
                    (= Q P)
                    (= S R)
                    (= U T)
                    (= W V)
                    (= Y X)
                    (= A1 Z))))
      (a!4 (or A
               C
               (not C1)
               (not B)
               (not D)
               (not F)
               (not E)
               (not (<= (+ S A1) 1))
               (and M
                    L
                    K
                    (not J)
                    (not I)
                    (not H)
                    (not G)
                    (= O N)
                    (= Q P)
                    (= S R)
                    (= U T)
                    (= W V)
                    (= Y X)
                    (= A1 Z))))
      (a!5 (and M
                (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
      (a!6 (= (+ O (* (- 1) N) S W A1) 0))
      (a!7 (= (+ O (* (- 1) N) Q U Y) 0))
      (a!8 (and M
                (not L)
                K
                J
                (not I)
                (not H)
                (not G)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)
                (= (+ O (* (- 1) N)) 1)))
      (a!9 (and M
                (not L)
                (not K)
                J
                (not I)
                (not H)
                (not G)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)
                (= (+ O (* (- 1) N)) 1)))
      (a!10 (and M
                 (not L)
                 (not K)
                 J
                 (not I)
                 H
                 (not G)
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= A1 Z)
                 (= (+ Q (* (- 1) P) U Y) (- 1))))
      (a!11 (and (not M)
                 L
                 K
                 J
                 (not I)
                 H
                 G
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= A1 Z)
                 (= (+ Q (* (- 1) P) U Y) (- 1))))
      (a!12 (and M
                 L
                 (not K)
                 (not J)
                 I
                 H
                 (not G)
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= A1 Z)
                 (= (+ Q (* (- 1) P)) 1)))
      (a!13 (and (not M)
                 (not L)
                 K
                 (not J)
                 I
                 H
                 G
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= A1 Z)
                 (= (+ Q (* (- 1) P)) 1)))
      (a!14 (and (not M)
                 L
                 (not K)
                 J
                 (not I)
                 (not H)
                 (not G)
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= A1 Z)
                 (= (+ S (* (- 1) R)) 1)))
      (a!15 (and (not M)
                 (not L)
                 K
                 J
                 I
                 (not H)
                 (not G)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= W V)
                 (= Y X)
                 (= A1 Z)
                 (= (+ U (* (- 1) T)) 1)))
      (a!16 (and M
                 (not L)
                 K
                 J
                 (not I)
                 H
                 (not G)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= Y X)
                 (= A1 Z)
                 (= (+ S W (* (- 1) V) A1) (- 1))))
      (a!17 (and M
                 L
                 (not K)
                 J
                 (not I)
                 (not H)
                 (not G)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= Y X)
                 (= A1 Z)
                 (= (+ S (* (- 1) V) A1) (- 1))))
      (a!18 (and (not M)
                 L
                 K
                 J
                 (not I)
                 (not H)
                 G
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= Y X)
                 (= A1 Z)
                 (= (+ W (* (- 1) V)) 1)))
      (a!19 (and (not M)
                 L
                 K
                 (not J)
                 I
                 (not H)
                 (not G)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= Y X)
                 (= A1 Z)
                 (= (+ W (* (- 1) V)) 1)))
      (a!20 (and (not M)
                 (not L)
                 K
                 J
                 I
                 H
                 (not G)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= A1 Z)
                 (= (+ Y (* (- 1) X)) (- 1))))
      (a!21 (and (not M)
                 L
                 (not K)
                 J
                 (not I)
                 H
                 (not G)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= (+ A1 (* (- 1) Z)) (- 1))))
      (a!22 (and M
                 L
                 K
                 J
                 I
                 H
                 (not G)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= A1 Z)))
      (a!23 (and (not M)
                 (not L)
                 (not K)
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= A1 Z))))
  (and (or A D (not C1) (not B) (not C) (not F) (not E) a!1 a!2)
       (or A
           D
           (not C1)
           (not B)
           (not C)
           (not F)
           (not E)
           (not a!1)
           (and M
                L
                K
                J
                (not I)
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       a!3
       a!4
       (or A
           B
           D
           F
           C1
           (not C)
           (not E)
           (= B1 0)
           (and M
                L
                (not K)
                J
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           D
           E
           F
           (not C1)
           (not B)
           (not (<= 1 Q))
           (and M
                L
                (not K)
                (not J)
                I
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           D
           E
           F
           (not C1)
           (not B)
           (<= 1 Q)
           (and M
                L
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           D
           E
           F
           (not C1)
           (not C)
           (= B1 0)
           (and M
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           D
           F
           (not C1)
           (not C)
           (not E)
           (not (<= 1 O))
           (and M
                (not L)
                K
                (not J)
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           D
           F
           (not C1)
           (not C)
           (not E)
           (<= 1 O)
           (and M
                (not L)
                K
                (not J)
                I
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           D
           E
           F
           (not C1)
           (not C)
           (not (= B1 0))
           (and M
                (not L)
                K
                (not J)
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           D
           E
           F
           (not C1)
           (= B1 0)
           (and M
                (not L)
                K
                (not J)
                (not I)
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           D
           F
           (not C1)
           (not E)
           (not (<= 1 O))
           (and M
                (not L)
                (not K)
                (not J)
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           D
           F
           (not C1)
           (not E)
           (<= 1 O)
           (and M
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           D
           E
           F
           (not C1)
           (not (= B1 0))
           (and M
                (not L)
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A C (not C1) (not B) (not D) (not F) (not E) (<= (+ S A1) 1) a!5)
       (or D
           E
           F
           C1
           (not A)
           (not B)
           (not C)
           (= B1 0)
           (and M
                (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           E
           C1
           (not B)
           (not D)
           (not F)
           (= B1 0)
           (and (not M)
                L
                K
                J
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or D
           F
           C1
           (not A)
           (not B)
           (not C)
           (not E)
           (not (<= 1 W))
           (and (not M)
                L
                K
                (not J)
                I
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or D
           F
           C1
           (not A)
           (not B)
           (not C)
           (not E)
           (<= 1 W)
           (and (not M)
                L
                K
                (not J)
                I
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or D
           E
           F
           C1
           (not A)
           (not B)
           (not C)
           (not (= B1 0))
           (and (not M)
                L
                K
                (not J)
                (not I)
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           C1
           (not B)
           (not D)
           (not F)
           (not E)
           (not (<= 1 W))
           (and (not M)
                L
                K
                (not J)
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or C
           D
           E
           F
           C1
           (not A)
           (not B)
           (= B1 0)
           (and (not M)
                L
                K
                (not J)
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           C1
           (not B)
           (not D)
           (not F)
           (not E)
           (<= 1 W)
           (and (not M)
                L
                K
                (not J)
                (not I)
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           E
           C1
           (not B)
           (not D)
           (not F)
           (not (= B1 0))
           (and (not M)
                L
                (not K)
                J
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           D
           E
           F
           C1
           (not B)
           (= B1 0)
           (and (not M)
                L
                (not K)
                J
                I
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or C
           D
           F
           C1
           (not A)
           (not B)
           (not E)
           (not (<= 1 W))
           (and (not M)
                L
                (not K)
                (not J)
                I
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           D
           F
           C1
           (not B)
           (not E)
           (not (<= 1 S))
           (and (not M)
                L
                (not K)
                (not J)
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or C
           D
           F
           C1
           (not A)
           (not B)
           (not E)
           (<= 1 W)
           (and (not M)
                L
                (not K)
                (not J)
                I
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           D
           F
           C1
           (not B)
           (not E)
           (<= 1 S)
           (and (not M)
                L
                (not K)
                (not J)
                I
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or C
           D
           E
           F
           C1
           (not A)
           (not B)
           (not (= B1 0))
           (and (not M)
                L
                (not K)
                (not J)
                (not I)
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           D
           E
           F
           C1
           (not B)
           (not (= B1 0))
           (and (not M)
                L
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           C
           C1
           (not A)
           (not D)
           (not F)
           (not E)
           (= B1 0)
           (and (not M)
                L
                (not K)
                (not J)
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           D
           E
           C1
           (not C)
           (not F)
           (= B1 0)
           (and (not M)
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           D
           C1
           (not C)
           (not F)
           (not E)
           (not (<= 1 U))
           (and (not M)
                (not L)
                K
                J
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           D
           C1
           (not C)
           (not F)
           (not E)
           (<= 1 U)
           (and (not M)
                (not L)
                K
                J
                (not I)
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           D
           E
           C1
           (not C)
           (not F)
           (not (= B1 0))
           (and (not M)
                (not L)
                K
                (not J)
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           D
           E
           F
           C1
           (not A)
           (not C)
           (not (<= 1 Q))
           (and (not M)
                (not L)
                K
                (not J)
                I
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           D
           F
           C1
           (not C)
           (not E)
           (not (= B1 0))
           (and (not M)
                (not L)
                K
                (not J)
                I
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           D
           E
           F
           C1
           (not A)
           (not C)
           (<= 1 Q)
           (and (not M)
                (not L)
                K
                (not J)
                (not I)
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           C
           C1
           (not A)
           (not D)
           (not F)
           (not E)
           (not (= B1 0))
           (and (not M)
                (not L)
                K
                (not J)
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C1
           (not B)
           (not C)
           (not D)
           (not F)
           (not E)
           (= B1 0)
           (and (not M)
                (not L)
                (not K)
                J
                I
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           D
           F
           C1
           (not E)
           (not (<= 1 O))
           (and (not M)
                (not L)
                (not K)
                (not J)
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           C
           D
           E
           F
           C1
           (not A)
           (not (<= 1 Q))
           (and (not M)
                (not L)
                (not K)
                (not J)
                I
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           D
           F
           C1
           (not E)
           (<= 1 O)
           (and (not M)
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           C
           D
           E
           F
           C1
           (not A)
           (<= 1 Q)
           (and (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C1
           (not B)
           (not C)
           (not D)
           (not F)
           (not E)
           (not (= B1 0))
           (and (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or C
           D
           C1
           (not A)
           (not B)
           (not F)
           (not E)
           (and (not M)
                L
                (not K)
                J
                (not I)
                (not H)
                G
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)
                a!6))
       (or B
           D
           C1
           (not A)
           (not C)
           (not F)
           (not E)
           (and (not M)
                (not L)
                K
                J
                (not I)
                (not H)
                G
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)
                a!6))
       (or A
           D
           E
           C1
           (not B)
           (not C)
           (not F)
           (and (not M)
                L
                K
                (not J)
                I
                H
                (not G)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)
                a!7))
       (or B
           C
           D
           E
           C1
           (not A)
           (not F)
           (and (not M)
                (not L)
                (not K)
                (not J)
                I
                H
                G
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)
                a!7))
       (or A B D (not C1) (not C) (not F) (not E) a!8)
       (or A B C D (not C1) (not F) (not E) a!9)
       (or A B C E F (not C1) (not D) a!10)
       (or E F C1 (not A) (not B) (not C) (not D) a!11)
       (or A C D E (not C1) (not B) (not F) a!12)
       (or B D E C1 (not A) (not C) (not F) a!13)
       (or A C D C1 (not B) (not F) (not E) a!14)
       (or A B F C1 (not C) (not D) (not E) a!15)
       (or A B E F (not C1) (not C) (not D) a!16)
       (or A C D (not C1) (not B) (not F) (not E) a!17)
       (or D C1 (not A) (not B) (not C) (not F) (not E) a!18)
       (or A D F C1 (not B) (not C) (not E) a!19)
       (or A B E C1 (not C) (not D) (not F) a!20)
       (or A C E F C1 (not B) (not D) a!21)
       (or A (not C1) (not B) (not C) (not D) (not F) (not E) a!22)
       (or A E (not C1) (not B) (not C) (not D) (not F) a!2)
       (or A
           E
           F
           (not C1)
           (not B)
           (not C)
           (not D)
           (and M
                L
                K
                J
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           D
           E
           (not C1)
           (not B)
           (not C)
           (not F)
           (and M
                L
                K
                (not J)
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           D
           E
           F
           (not C1)
           (not B)
           (not C)
           (and M
                L
                K
                (not J)
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           E
           (not C1)
           (not B)
           (not D)
           (not F)
           (and M
                (not L)
                K
                J
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           (not C1)
           (not C)
           (not D)
           (not F)
           (not E)
           (and M
                (not L)
                (not K)
                J
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B C D E F (not C1) (not A) a!5)
       (or A
           B
           C
           (not C1)
           (not D)
           (not F)
           (not E)
           (and (not M)
                L
                K
                J
                I
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           C
           E
           C1
           (not A)
           (not D)
           (not F)
           (and (not M)
                L
                K
                J
                I
                (not H)
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or C1
           (not A)
           (not B)
           (not C)
           (not D)
           (not F)
           (not E)
           (and (not M)
                L
                (not K)
                J
                I
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           E
           C1
           (not B)
           (not C)
           (not D)
           (not F)
           (and (not M)
                L
                (not K)
                J
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or C
           C1
           (not A)
           (not B)
           (not D)
           (not F)
           (not E)
           (and (not M)
                (not L)
                K
                J
                I
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           F
           C1
           (not B)
           (not D)
           (not E)
           (and (not M)
                (not L)
                K
                J
                I
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C1
           (not C)
           (not D)
           (not F)
           (not E)
           (and (not M)
                (not L)
                K
                (not J)
                (not I)
                H
                (not G)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           C1
           (not A)
           (not C)
           (not D)
           (not F)
           (not E)
           (and (not M)
                (not L)
                (not K)
                J
                I
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A B C D E F C1 a!23)
       (or A B C D E C1 (not F) a!23)
       (or A B C D E (not C1) (not F) a!23)
       (or A B D E (not C1) (not C) (not F) a!23)
       (or A B E F C1 (not C) (not D) a!23)
       (or A C D E C1 (not B) (not F) a!23)
       (or A C D F (not C1) (not B) (not E) a!23)
       (or A D E F C1 (not B) (not C) a!23)
       (or A F (not C1) (not B) (not C) (not D) (not E) a!23)
       (or B C D F C1 (not A) (not E) a!23)
       (or B D F C1 (not A) (not C) (not E) a!23)
       (or C D E C1 (not A) (not B) (not F) a!23)
       (or D E C1 (not A) (not B) (not C) (not F) a!23)
       (or A
           D
           C1
           (not B)
           (not C)
           (not F)
           (not E)
           (and (not M)
                L
                K
                J
                (not I)
                (not H)
                (not G)
                (= P 0)
                (= O N)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           E
           C1
           (not D)
           (not F)
           (and (not M)
                (not L)
                (not K)
                J
                I
                H
                (not G)
                (= P 0)
                (= O N)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           C
           D
           C1
           (not A)
           (not F)
           (not E)
           (and (not M)
                (not L)
                (not K)
                J
                (not I)
                (not H)
                G
                (= P 0)
                (= O N)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           C
           E
           F
           (not C1)
           (not B)
           (not D)
           (and M
                L
                (not K)
                J
                (not I)
                H
                (not G)
                (= R 0)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           F
           (not C1)
           (not C)
           (not D)
           (not E)
           (and M
                (not L)
                K
                J
                I
                (not H)
                (not G)
                (= R 0)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           E
           F
           C1
           (not D)
           (and (not M)
                (not L)
                (not K)
                J
                (not I)
                H
                (not G)
                (= R 0)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or C
           F
           C1
           (not A)
           (not B)
           (not D)
           (not E)
           (and (not M)
                L
                (not K)
                J
                I
                (not H)
                G
                (= R 1)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           F
           C1
           (not A)
           (not C)
           (not D)
           (not E)
           (and (not M)
                (not L)
                K
                J
                I
                (not H)
                G
                (= R 1)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           F
           (not C1)
           (not D)
           (not E)
           (and M
                (not L)
                (not K)
                J
                I
                (not H)
                (not G)
                (= T 0)
                (= O N)
                (= Q P)
                (= S R)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or F
           C1
           (not A)
           (not B)
           (not C)
           (not D)
           (not E)
           (and (not M)
                L
                K
                J
                I
                (not H)
                G
                (= T 0)
                (= O N)
                (= Q P)
                (= S R)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           C1
           (not D)
           (not F)
           (not E)
           (and (not M)
                (not L)
                K
                (not J)
                (not I)
                (not H)
                (not G)
                (= T 0)
                (= O N)
                (= Q P)
                (= S R)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or A
           E
           F
           C1
           (not B)
           (not C)
           (not D)
           (and (not M)
                L
                K
                J
                (not I)
                H
                (not G)
                (= T 1)
                (= O N)
                (= Q P)
                (= S R)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or B
           C
           E
           F
           C1
           (not A)
           (not D)
           (and (not M)
                (not L)
                (not K)
                J
                (not I)
                H
                G
                (= T 1)
                (= O N)
                (= Q P)
                (= S R)
                (= W V)
                (= Y X)
                (= A1 Z)))
       (or C
           E
           F
           C1
           (not A)
           (not B)
           (not D)
           (and (not M)
                L
                (not K)
                J
                (not I)
                H
                G
                (= V 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= Y X)
                (= A1 Z)))
       (or B
           E
           F
           C1
           (not A)
           (not C)
           (not D)
           (and (not M)
                (not L)
                K
                J
                (not I)
                H
                G
                (= V 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           D
           C1
           (not F)
           (not E)
           (and (not M)
                (not L)
                (not K)
                J
                (not I)
                (not H)
                (not G)
                (= V 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= Y X)
                (= A1 Z)))
       (or A
           B
           C
           E
           (not C1)
           (not D)
           (not F)
           (and M
                (not L)
                (not K)
                J
                I
                H
                (not G)
                (= X 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= A1 Z)))
       (or E
           C1
           (not A)
           (not B)
           (not C)
           (not D)
           (not F)
           (and (not M)
                L
                K
                J
                I
                H
                G
                (= X 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= A1 Z)))
       (or A
           F
           C1
           (not B)
           (not C)
           (not D)
           (not E)
           (and (not M)
                L
                K
                J
                I
                (not H)
                (not G)
                (= X 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= A1 Z)))
       (or A
           B
           D
           E
           F
           C1
           (not C)
           (and (not M)
                (not L)
                K
                (not J)
                (not I)
                H
                (not G)
                (= X 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= A1 Z)))
       (or B
           C
           F
           C1
           (not A)
           (not D)
           (not E)
           (and (not M)
                (not L)
                (not K)
                J
                I
                (not H)
                G
                (= X 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= A1 Z)))
       (or A
           C
           F
           (not C1)
           (not B)
           (not D)
           (not E)
           (and M
                L
                (not K)
                J
                I
                (not H)
                (not G)
                (= Z 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A
           B
           E
           (not C1)
           (not C)
           (not D)
           (not F)
           (and M
                (not L)
                K
                J
                I
                H
                (not G)
                (= Z 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or C
           E
           C1
           (not A)
           (not B)
           (not D)
           (not F)
           (and (not M)
                L
                (not K)
                J
                I
                H
                G
                (= Z 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or B
           E
           C1
           (not A)
           (not C)
           (not D)
           (not F)
           (and (not M)
                (not L)
                K
                J
                I
                H
                G
                (= Z 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A
           B
           C
           F
           C1
           (not D)
           (not E)
           (and (not M)
                (not L)
                (not K)
                J
                I
                (not H)
                (not G)
                (= Z 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A D F (not C1) (not B) (not C) (not E) (<= (+ U Y) 1) a!22)))
      )
      (state I H J K L G M N P R T V X Z)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Bool) ) 
    (=>
      (and
        (state F E D C B A N G H I J K L M)
        (or (and N (not A) B C D (not E) F)
    (and N (not A) B C D E F)
    (and N A (not B) (not C) (not D) (not E) (not F)))
      )
      false
    )
  )
)

(check-sat)
(exit)
