; ./prepared/vmt/./ctigar/svd-some-loop.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) ) 
    (=>
      (and
        (and (= E true) (not D) (not C) (not B) (not A) (not M) (not F))
      )
      (state F E D C A B M L K J I H G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Bool) ) 
    (=>
      (and
        (state F E D C A B A1 Y W U S Q O)
        (let ((a!1 (and M
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
                (= Y X)))
      (a!2 (and M
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
                (= Y X)))
      (a!3 (and M
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
                (= Y X)))
      (a!4 (and M
                (not L)
                K
                J
                I
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
      (a!5 (and M
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
                (= Y X)))
      (a!6 (and M
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
                (= Y X)))
      (a!7 (and M
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
                (= Y X)))
      (a!8 (and M
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
                (= Y X)))
      (a!9 (and M
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
                (= Y X)))
      (a!10 (and M
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
                 (= Y X)))
      (a!11 (and (not M)
                 L
                 K
                 J
                 I
                 (not H)
                 G
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)))
      (a!12 (and (not M)
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
                 (= Y X)))
      (a!13 (and (not M)
                 L
                 K
                 J
                 (not I)
                 H
                 G
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)))
      (a!14 (and (not M)
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
                 (= Y X)))
      (a!15 (and (not M)
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
                 (= W V)
                 (= Y X)))
      (a!16 (and (not M)
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
                 (= Y X)))
      (a!17 (and (not M)
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
                 (= Y X)))
      (a!18 (and (not M)
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
                 (= Y X)))
      (a!19 (and (not M)
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
                 (= Y X)))
      (a!20 (and (not M)
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
                 (= Y X)))
      (a!21 (and (not M)
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
                 (= Y X)))
      (a!22 (and (not M)
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
                 (= Y X)))
      (a!23 (and (not M)
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
                 (= Y X)))
      (a!24 (and (not M)
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
                 (= Y X)))
      (a!25 (and M
                 (not L)
                 K
                 J
                 I
                 (not H)
                 (not G)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= (+ O (* (- 1) N)) 1)))
      (a!26 (and M
                 (not L)
                 (not K)
                 J
                 I
                 (not H)
                 (not G)
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= (+ Q (* (- 1) P)) (- 1))))
      (a!27 (and (not M)
                 L
                 K
                 J
                 I
                 H
                 G
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= (+ Q (* (- 1) P)) (- 1))))
      (a!28 (and (not M)
                 (not L)
                 K
                 (not J)
                 (not I)
                 (not H)
                 G
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= (+ Q (* (- 1) P)) (- 1))))
      (a!29 (and (not M)
                 L
                 K
                 (not J)
                 I
                 H
                 G
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= (+ S (* (- 1) R)) (- 1))))
      (a!30 (and (not M)
                 L
                 (not K)
                 (not J)
                 (not I)
                 H
                 G
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= Y X)
                 (= (+ S (* (- 1) R)) (- 1))))
      (a!31 (and (not M)
                 (not L)
                 (not K)
                 (not J)
                 I
                 (not H)
                 (not G)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= W V)
                 (= Y X)
                 (= (+ T (* (- 1) O)) 1)))
      (a!32 (and (not M)
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
                 (= Y X))))
  (and (or B C D E (not A1) (not A) (not F) (<= 1 O) a!1)
       (or B C E F (not A1) (not A) (not D) (<= O Y) a!2)
       (or B C E (not A1) (not A) (not D) (not F) (<= 1 O) a!3)
       (or B D E F (not A1) (not A) (not C) (<= O Y) a!4)
       (or B
           D
           E
           F
           (not A1)
           (not A)
           (not C)
           (not (<= O Y))
           (and M
                (not L)
                K
                J
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or B
           C
           E
           (not A1)
           (not A)
           (not D)
           (not F)
           (not (<= 1 O))
           (and M
                (not L)
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
                (= Y X)))
       (or B
           C
           E
           F
           (not A1)
           (not A)
           (not D)
           (not (<= O Y))
           (and M
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
                (= Y X)))
       (or B
           C
           D
           E
           (not A1)
           (not A)
           (not F)
           (not (<= 1 O))
           (and M
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
                (= Y X)))
       (or A B C E F A1 (not D) (not (<= Y O)) a!5)
       (or A
           B
           C
           D
           E
           (not A1)
           (not F)
           (<= Q Y)
           (and M
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
                (= Y X)))
       (or A B C D (not A1) (not F) (not E) (<= 1 Q) a!6)
       (or A B C F (not A1) (not D) (not E) (<= Q Y) a!7)
       (or A B C (not A1) (not D) (not F) (not E) (<= 1 O) a!8)
       (or A B D F (not A1) (not C) (not E) (<= O Y) a!9)
       (or A
           B
           D
           F
           (not A1)
           (not C)
           (not E)
           (not (<= O Y))
           (and M
                (not L)
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
                (= Y X)))
       (or A
           B
           C
           (not A1)
           (not D)
           (not F)
           (not E)
           (not (<= 1 O))
           (and M
                (not L)
                (not K)
                J
                (not I)
                (not H)
                (not G)
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
           (not A1)
           (not D)
           (not E)
           (not (<= Q Y))
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
                (= Y X)))
       (or A
           B
           C
           D
           (not A1)
           (not F)
           (not E)
           (not (<= 1 Q))
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
                (= Y X)))
       (or A
           B
           C
           D
           E
           (not A1)
           (not F)
           (not (<= Q Y))
           (and M
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
                (= Y X)))
       (or A B C F A1 (not D) (not E) (= Z 0) a!10)
       (or B
           C
           A1
           (not A)
           (not D)
           (not F)
           (not E)
           (<= Q Y)
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
                (= Y X)))
       (or A
           D
           F
           A1
           (not B)
           (not C)
           (not E)
           (<= S Y)
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
                (= Y X)))
       (or A D E A1 (not B) (not C) (not F) (<= 1 S) a!11)
       (or A E F A1 (not B) (not C) (not D) (<= S Y) a!12)
       (or A E A1 (not B) (not C) (not D) (not F) (<= 1 Q) a!13)
       (or C D E F A1 (not B) (not A) (<= Q Y) a!14)
       (or C D E A1 (not B) (not A) (not F) (<= 1 O) a!15)
       (or C E F A1 (not B) (not A) (not D) (<= O Y) a!16)
       (or C
           E
           F
           A1
           (not B)
           (not A)
           (not D)
           (not (<= O Y))
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
                (= Y X)))
       (or C
           D
           E
           A1
           (not B)
           (not A)
           (not F)
           (not (<= 1 O))
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
                (= Y X)))
       (or C
           D
           E
           F
           A1
           (not B)
           (not A)
           (not (<= Q Y))
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
                (= Y X)))
       (or A
           E
           A1
           (not B)
           (not C)
           (not D)
           (not F)
           (not (<= 1 Q))
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
                (= Y X)))
       (or A
           E
           F
           A1
           (not B)
           (not C)
           (not D)
           (not (<= S Y))
           (and (not M)
                L
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
                (= Y X)))
       (or A
           D
           E
           A1
           (not B)
           (not C)
           (not F)
           (not (<= 1 S))
           (and (not M)
                L
                (not K)
                J
                (not I)
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A
           D
           F
           A1
           (not B)
           (not C)
           (not E)
           (not (<= S Y))
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
                (= Y X)))
       (or B
           D
           F
           A1
           (not A)
           (not C)
           (not E)
           (<= S Y)
           (and (not M)
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
                (= W V)
                (= Y X)))
       (or B D E A1 (not A) (not C) (not F) (<= 1 S) a!17)
       (or B E F A1 (not A) (not C) (not D) (<= S Y) a!18)
       (or B E A1 (not A) (not C) (not D) (not F) (<= 1 Q) a!19)
       (or A C D E F A1 (not B) (<= Q Y) a!20)
       (or A
           C
           D
           E
           F
           A1
           (not B)
           (not (<= Q Y))
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
                (= Y X)))
       (or B
           E
           A1
           (not A)
           (not C)
           (not D)
           (not F)
           (not (<= 1 Q))
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
                (= Y X)))
       (or B
           E
           F
           A1
           (not A)
           (not C)
           (not D)
           (not (<= S Y))
           (and (not M)
                (not L)
                K
                J
                I
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or B
           D
           E
           A1
           (not A)
           (not C)
           (not F)
           (not (<= 1 S))
           (and (not M)
                (not L)
                K
                J
                (not I)
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or B
           D
           F
           A1
           (not A)
           (not C)
           (not E)
           (not (<= S Y))
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
                (= Y X)))
       (or B
           C
           A1
           (not A)
           (not D)
           (not F)
           (not E)
           (not (<= Q Y))
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
                (= Y X)))
       (or A
           B
           C
           A1
           (not D)
           (not F)
           (not E)
           (<= Q Y)
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
                (= Y X)))
       (or A B D E F A1 (not C) (<= 1 Q) a!21)
       (or A B D E A1 (not C) (not F) (<= Q Y) a!22)
       (or A B E F A1 (not C) (not D) (<= 1 O) a!23)
       (or A B E A1 (not C) (not D) (not F) (<= O Y) a!24)
       (or A
           B
           E
           A1
           (not C)
           (not D)
           (not F)
           (not (<= O Y))
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
                (= Y X)))
       (or A
           B
           E
           F
           A1
           (not C)
           (not D)
           (not (<= 1 O))
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
                (= Y X)))
       (or A
           B
           D
           E
           A1
           (not C)
           (not F)
           (not (<= Q Y))
           (and (not M)
                (not L)
                (not K)
                J
                (not I)
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A
           B
           D
           E
           F
           A1
           (not C)
           (not (<= 1 Q))
           (and (not M)
                (not L)
                (not K)
                J
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A
           B
           C
           A1
           (not D)
           (not F)
           (not E)
           (not (<= Q Y))
           (and (not M)
                (not L)
                (not K)
                J
                (not I)
                (not H)
                (not G)
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
           A1
           (not D)
           (not E)
           (not (= Z 0))
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
                (= Y X)))
       (or A
           B
           C
           E
           F
           A1
           (not D)
           (<= Y O)
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
                (= Y X)))
       (or A
           B
           C
           D
           E
           A1
           (not F)
           (not (<= 1 O))
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
                (= Y X)))
       (or B D (not A1) (not A) (not C) (not F) (not E) a!25)
       (or A
           B
           C
           D
           F
           A1
           (not E)
           (and (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)
                (= Y N)))
       (or A B D (not A1) (not C) (not F) (not E) a!26)
       (or E A1 (not B) (not A) (not C) (not D) (not F) a!27)
       (or B C D E F A1 (not A) a!28)
       (or A
           B
           C
           D
           F
           (not A1)
           (not E)
           (and M
                (not L)
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= O N)
                (= S R)
                (= U T)
                (= U P)
                (= W V)
                (= Y X)))
       (or B
           C
           E
           A1
           (not A)
           (not D)
           (not F)
           (and (not M)
                (not L)
                K
                (not J)
                I
                H
                G
                (= O N)
                (= S R)
                (= U T)
                (= U P)
                (= W V)
                (= Y X)))
       (or A
           B
           C
           E
           A1
           (not D)
           (not F)
           (and (not M)
                (not L)
                (not K)
                (not J)
                I
                H
                G
                (= O N)
                (= S R)
                (= U T)
                (= U P)
                (= W V)
                (= Y X)))
       (or C E A1 (not B) (not A) (not D) (not F) a!29)
       (or A C D E A1 (not B) (not F) a!30)
       (or A
           D
           E
           F
           A1
           (not B)
           (not C)
           (and (not M)
                L
                (not K)
                J
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= U T)
                (= U R)
                (= W V)
                (= Y X)))
       (or B
           D
           E
           F
           A1
           (not A)
           (not C)
           (and (not M)
                (not L)
                K
                J
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= U T)
                (= U R)
                (= W V)
                (= Y X)))
       (or A B C D A1 (not F) (not E) a!31)
       (or A C D E F (not A1) (not B) a!1)
       (or B (not A1) (not A) (not C) (not D) (not F) (not E) a!2)
       (or B E (not A1) (not A) (not C) (not D) (not F) a!3)
       (or B F (not A1) (not A) (not C) (not D) (not E) a!4)
       (or B
           D
           F
           (not A1)
           (not A)
           (not C)
           (not E)
           (and M
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
                (= Y X)))
       (or B
           C
           (not A1)
           (not A)
           (not D)
           (not F)
           (not E)
           (and M
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
                (= Y X)))
       (or B
           C
           F
           (not A1)
           (not A)
           (not D)
           (not E)
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
                (= Y X)))
       (or B
           C
           D
           (not A1)
           (not A)
           (not F)
           (not E)
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
                (= Y X)))
       (or B C D F (not A1) (not A) (not E) a!5)
       (or B C D E F (not A1) (not A) a!6)
       (or A B (not A1) (not C) (not D) (not F) (not E) a!7)
       (or A B E (not A1) (not C) (not D) (not F) a!8)
       (or A B F (not A1) (not C) (not D) (not E) a!9)
       (or A
           B
           D
           E
           (not A1)
           (not C)
           (not F)
           (and M
                (not L)
                (not K)
                J
                (not I)
                H
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A
           B
           D
           E
           F
           (not A1)
           (not C)
           (and M
                (not L)
                (not K)
                J
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A
           B
           C
           E
           (not A1)
           (not D)
           (not F)
           (and M
                (not L)
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
                (= Y X)))
       (or A
           B
           C
           E
           F
           (not A1)
           (not D)
           (and M
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
                (= Y X)))
       (or A
           B
           E
           F
           (not A1)
           (not C)
           (not D)
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
                (= Y X)))
       (or A B C D E F (not A1) a!10)
       (or F A1 (not B) (not A) (not C) (not D) (not E) a!11)
       (or E F A1 (not B) (not A) (not C) (not D) a!12)
       (or D A1 (not B) (not A) (not C) (not F) (not E) a!13)
       (or D E A1 (not B) (not A) (not C) (not F) a!14)
       (or D F A1 (not B) (not A) (not C) (not E) a!15)
       (or D E F A1 (not B) (not A) (not C) a!16)
       (or C
           F
           A1
           (not B)
           (not A)
           (not D)
           (not E)
           (and (not M)
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
                (= Y X)))
       (or C
           D
           A1
           (not B)
           (not A)
           (not F)
           (not E)
           (and (not M)
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
                (= Y X)))
       (or C
           D
           F
           A1
           (not B)
           (not A)
           (not E)
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
                (= Y X)))
       (or A
           A1
           (not B)
           (not C)
           (not D)
           (not F)
           (not E)
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
                (= Y X)))
       (or A
           F
           A1
           (not B)
           (not C)
           (not D)
           (not E)
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
                (= Y X)))
       (or A
           D
           A1
           (not B)
           (not C)
           (not F)
           (not E)
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
                (= Y X)))
       (or C
           A1
           (not B)
           (not A)
           (not D)
           (not F)
           (not E)
           (and (not M)
                L
                (not K)
                J
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A C A1 (not B) (not D) (not F) (not E) a!17)
       (or A C E A1 (not B) (not D) (not F) a!18)
       (or A C F A1 (not B) (not D) (not E) a!19)
       (or A C E F A1 (not B) (not D) a!20)
       (or A
           C
           D
           F
           A1
           (not B)
           (not E)
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
                (= Y X)))
       (or B
           A1
           (not A)
           (not C)
           (not D)
           (not F)
           (not E)
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
                (= Y X)))
       (or B
           F
           A1
           (not A)
           (not C)
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
                (= Y X)))
       (or B
           D
           A1
           (not A)
           (not C)
           (not F)
           (not E)
           (and (not M)
                (not L)
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
                (= Y X)))
       (or A
           C
           D
           A1
           (not B)
           (not F)
           (not E)
           (and (not M)
                (not L)
                K
                J
                (not I)
                (not H)
                G
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A1
           (not B)
           (not A)
           (not C)
           (not D)
           (not F)
           (not E)
           (and (not M)
                (not L)
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
                (= Y X)))
       (or B C F A1 (not A) (not D) (not E) a!21)
       (or B C E F A1 (not A) (not D) a!22)
       (or B C D A1 (not A) (not F) (not E) a!23)
       (or B C D E A1 (not A) (not F) a!24)
       (or A
           B
           A1
           (not C)
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
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= Y X)))
       (or A
           B
           F
           A1
           (not C)
           (not D)
           (not E)
           (and (not M)
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
                (= Y X)))
       (or A
           B
           D
           A1
           (not C)
           (not F)
           (not E)
           (and (not M)
                (not L)
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
                (= Y X)))
       (or A
           B
           D
           F
           A1
           (not C)
           (not E)
           (and (not M)
                (not L)
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
                (= Y X)))
       (or B
           C
           D
           F
           A1
           (not A)
           (not E)
           (and (not M)
                (not L)
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
                (= Y X)))
       (or B
           E
           F
           (not A1)
           (not A)
           (not C)
           (not D)
           (and (not M)
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
                (= Y X)))
       (or A B C D E F A1 a!32)
       (or A C D F (not A1) (not B) (not E) a!32)
       (or B
           D
           E
           (not A1)
           (not A)
           (not C)
           (not F)
           (and M
                (not L)
                K
                J
                (not I)
                H
                G
                (= T O)
                (= O N)
                (= Q P)
                (= S R)
                (= W V)
                (= Y X)))
       (or A
           B
           C
           D
           E
           A1
           (not F)
           (<= 1 O)
           (and M
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
                (= Y X)))))
      )
      (state H G I J K L M X V T R P N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) ) 
    (=>
      (and
        (state F E D C A B M L K J I H G)
        (or (and (not M) (not A) B (not C) D (not E) (not F))
    (and (not M) (not A) B (not C) D (not E) F)
    (and (not M) (not A) B (not C) D E (not F))
    (and (not M) (not A) B (not C) D E F)
    (and (not M) A (not B) (not C) (not D) (not E) F)
    (and (not M) A (not B) (not C) (not D) E F)
    (and (not M) A (not B) (not C) D (not E) (not F))
    (and (not M) A (not B) (not C) D E (not F))
    (and (not M) A B C (not D) (not E) (not F))
    (and (not M) A B C (not D) (not E) F)
    (and (not M) A B C (not D) E (not F))
    (and (not M) A B C (not D) E F)
    (and (not M) A B C D (not E) (not F))
    (and (not M) A B C D E (not F))
    (and M (not A) (not B) C D (not E) F)
    (and M (not A) (not B) C D E (not F))
    (and M (not A) (not B) C D E F)
    (and M (not A) B (not C) (not D) (not E) (not F))
    (and M A (not B) (not C) (not D) (not E) (not F))
    (and M A (not B) C D (not E) F)
    (and M A (not B) C D E (not F))
    (and M A (not B) C D E F))
      )
      false
    )
  )
)

(check-sat)
(exit)
