; ./prepared/vmt/./ctigar/svd1.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (and (= E true) (not D) (not C) (not B) (not A) (not L) (not F))
      )
      (state F E D C A B L K J I H G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) ) 
    (=>
      (and
        (state F E D C A B Y W U S Q O)
        (let ((a!1 (and M
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
                (= W V)))
      (a!2 (and M
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
                (= W V)))
      (a!3 (and M
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
                (= W V)))
      (a!4 (and M
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
                (= W V)))
      (a!5 (and M
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
                (= W V)))
      (a!6 (and M
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
                (= W V)))
      (a!7 (and M
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
                (= W V)))
      (a!8 (and M
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
                (= W V)))
      (a!9 (and M
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
                (= W V)))
      (a!10 (and M
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
                 (= W V)))
      (a!11 (and M
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
                 (= W V)))
      (a!12 (and M
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
                 (= W V)))
      (a!13 (and M
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
                 (= W V)))
      (a!14 (and M
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
                 (= W V)))
      (a!15 (and M
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
                 (= W V)))
      (a!16 (and (not M) L K J I H G (= O N) (= Q P) (= S R) (= U T) (= W V)))
      (a!17 (and (not M)
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
                 (= W V)))
      (a!18 (and (not M)
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
                 (= W V)))
      (a!19 (and (not M)
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
                 (= W V)))
      (a!20 (and (not M)
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
                 (= W V)))
      (a!21 (and (not M)
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
                 (= W V)))
      (a!22 (and (not M)
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
                 (= W V)))
      (a!23 (and (not M)
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
                 (= W V)))
      (a!24 (and (not M)
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
                 (= W V)))
      (a!25 (and (not M)
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
                 (= W V)))
      (a!26 (and (not M)
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
                 (= W V)))
      (a!27 (and M
                 L
                 (not K)
                 (not J)
                 (not I)
                 H
                 G
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= (+ O (* (- 1) N)) 1)))
      (a!28 (and M
                 (not L)
                 K
                 (not J)
                 (not I)
                 H
                 G
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= (+ Q (* (- 1) P)) (- 1))))
      (a!29 (and M
                 (not L)
                 (not K)
                 (not J)
                 I
                 H
                 (not G)
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= (+ Q (* (- 1) P)) (- 1))))
      (a!30 (and (not M)
                 (not L)
                 K
                 (not J)
                 I
                 H
                 (not G)
                 (= O N)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= (+ Q (* (- 1) P)) (- 1))))
      (a!31 (and (not M)
                 L
                 K
                 J
                 I
                 H
                 (not G)
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= (+ S (* (- 1) R)) (- 1))))
      (a!32 (and (not M)
                 L
                 (not K)
                 J
                 (not I)
                 H
                 (not G)
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= (+ S (* (- 1) R)) (- 1))))
      (a!33 (and (not M)
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
                 (= W V))))
  (and (or B D F (not Y) (not A) (not C) (not E) (<= 1 O) a!1)
       (or B D (not Y) (not A) (not C) (not F) (not E) (<= O W) a!2)
       (or B F (not Y) (not A) (not C) (not D) (not E) (<= 1 O) a!3)
       (or B (not Y) (not A) (not C) (not D) (not F) (not E) (<= O W) a!4)
       (or B
           (not Y)
           (not A)
           (not C)
           (not D)
           (not F)
           (not E)
           (not (<= O W))
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
                (= W V)))
       (or B
           F
           (not Y)
           (not A)
           (not C)
           (not D)
           (not E)
           (not (<= 1 O))
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
                (= W V)))
       (or B
           D
           (not Y)
           (not A)
           (not C)
           (not F)
           (not E)
           (not (<= O W))
           (and M
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
                (= W V)))
       (or B
           D
           F
           (not Y)
           (not A)
           (not C)
           (not E)
           (not (<= 1 O))
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
                (= W V)))
       (or A B C F Y (not D) (not E) (not (<= W O)) a!5)
       (or A
           B
           D
           F
           (not Y)
           (not C)
           (not E)
           (<= Q W)
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
                (= W V)))
       (or A B D E (not Y) (not C) (not F) (<= 1 Q) a!6)
       (or A B E F (not Y) (not C) (not D) (<= Q W) a!7)
       (or A B E (not Y) (not C) (not D) (not F) (<= 1 O) a!8)
       (or B C D E F (not Y) (not A) (<= O W) a!9)
       (or B
           C
           D
           E
           F
           (not Y)
           (not A)
           (not (<= O W))
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
                (= W V)))
       (or A
           B
           E
           (not Y)
           (not C)
           (not D)
           (not F)
           (not (<= 1 O))
           (and M
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
                (= W V)))
       (or A
           B
           E
           F
           (not Y)
           (not C)
           (not D)
           (not (<= Q W))
           (and M
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
                (= W V)))
       (or A
           B
           D
           E
           (not Y)
           (not C)
           (not F)
           (not (<= 1 Q))
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
                (= W V)))
       (or A
           B
           D
           F
           (not Y)
           (not C)
           (not E)
           (not (<= Q W))
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
                (= W V)))
       (or A B C E Y (not D) (not F) (= X 0) a!10)
       (or B
           E
           Y
           (not A)
           (not C)
           (not D)
           (not F)
           (<= Q W)
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
                (= W V)))
       (or C
           D
           E
           F
           Y
           (not B)
           (not A)
           (<= S W)
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
                (= W V)))
       (or C D F Y (not B) (not A) (not E) (<= 1 S) a!11)
       (or C D Y (not B) (not A) (not F) (not E) (<= S W) a!12)
       (or C F Y (not B) (not A) (not D) (not E) (<= 1 Q) a!13)
       (or C Y (not B) (not A) (not D) (not F) (not E) (<= Q W) a!14)
       (or D F Y (not B) (not A) (not C) (not E) (<= 1 O) a!15)
       (or D Y (not B) (not A) (not C) (not F) (not E) (<= O W) a!16)
       (or D
           Y
           (not B)
           (not A)
           (not C)
           (not F)
           (not E)
           (not (<= O W))
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
                (= W V)))
       (or D
           F
           Y
           (not B)
           (not A)
           (not C)
           (not E)
           (not (<= 1 O))
           (and (not M)
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
                (= W V)))
       (or C
           Y
           (not B)
           (not A)
           (not D)
           (not F)
           (not E)
           (not (<= Q W))
           (and (not M)
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
                (= W V)))
       (or C
           F
           Y
           (not B)
           (not A)
           (not D)
           (not E)
           (not (<= 1 Q))
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
                (= W V)))
       (or C
           D
           Y
           (not B)
           (not A)
           (not F)
           (not E)
           (not (<= S W))
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
                (= W V)))
       (or C
           D
           F
           Y
           (not B)
           (not A)
           (not E)
           (not (<= 1 S))
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
                (= W V)))
       (or C
           D
           E
           F
           Y
           (not B)
           (not A)
           (not (<= S W))
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
                (= W V)))
       (or A
           C
           D
           E
           F
           Y
           (not B)
           (<= S W)
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
                (= W V)))
       (or A C D F Y (not B) (not E) (<= 1 S) a!17)
       (or A C D Y (not B) (not F) (not E) (<= S W) a!18)
       (or A C F Y (not B) (not D) (not E) (<= 1 Q) a!19)
       (or A C Y (not B) (not D) (not F) (not E) (<= Q W) a!20)
       (or A
           C
           Y
           (not B)
           (not D)
           (not F)
           (not E)
           (not (<= Q W))
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
                (= W V)))
       (or A
           C
           F
           Y
           (not B)
           (not D)
           (not E)
           (not (<= 1 Q))
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
                (= W V)))
       (or A
           C
           D
           Y
           (not B)
           (not F)
           (not E)
           (not (<= S W))
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
                (= W V)))
       (or A
           C
           D
           F
           Y
           (not B)
           (not E)
           (not (<= 1 S))
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
                (= W V)))
       (or A
           C
           D
           E
           F
           Y
           (not B)
           (not (<= S W))
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
                (= W V)))
       (or B
           E
           Y
           (not A)
           (not C)
           (not D)
           (not F)
           (not (<= Q W))
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
                (= W V)))
       (or A
           B
           D
           E
           F
           Y
           (not C)
           (<= Q W)
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
                (= W V)))
       (or A B D F Y (not C) (not E) (<= 1 Q) a!21)
       (or A B D Y (not C) (not F) (not E) (<= Q W) a!22)
       (or A B F Y (not C) (not D) (not E) (<= 1 O) a!23)
       (or A B Y (not C) (not D) (not F) (not E) (<= O W) a!24)
       (or B C D F Y (not A) (not E) (<= 1 U) a!25)
       (or B C D Y (not A) (not F) (not E) (<= U W) a!26)
       (or B
           C
           D
           Y
           (not A)
           (not F)
           (not E)
           (not (<= U W))
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
                (= W V)))
       (or B
           C
           D
           F
           Y
           (not A)
           (not E)
           (not (<= 1 U))
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
                (= W V)))
       (or A
           B
           Y
           (not C)
           (not D)
           (not F)
           (not E)
           (not (<= O W))
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
                (= W V)))
       (or A
           B
           F
           Y
           (not C)
           (not D)
           (not E)
           (not (<= 1 O))
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
                (= W V)))
       (or A
           B
           D
           Y
           (not C)
           (not F)
           (not E)
           (not (<= Q W))
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
                (= W V)))
       (or A
           B
           D
           F
           Y
           (not C)
           (not E)
           (not (<= 1 Q))
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
                (= W V)))
       (or A
           B
           D
           E
           F
           Y
           (not C)
           (not (<= Q W))
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
                (= W V)))
       (or A
           B
           C
           E
           Y
           (not D)
           (not F)
           (not (= X 0))
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
                (= W V)))
       (or A
           B
           C
           F
           Y
           (not D)
           (not E)
           (<= W O)
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
                (= W V)))
       (or A
           B
           C
           E
           F
           Y
           (not D)
           (not (<= 1 O))
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
                (= W V)))
       (or A
           B
           C
           D
           F
           Y
           (not E)
           (<= U 0)
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
                (= W V)))
       (or A
           B
           C
           D
           F
           Y
           (not E)
           (not (<= U 0))
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
                (= W V)))
       (or A C D E (not Y) (not B) (not F) a!27)
       (or A
           B
           C
           D
           Y
           (not F)
           (not E)
           (and (not M)
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (not G)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= W N)))
       (or B C D E (not Y) (not A) (not F) a!28)
       (or A B C F (not Y) (not D) (not E) a!29)
       (or B C F Y (not A) (not D) (not E) a!30)
       (or A
           B
           D
           E
           F
           (not Y)
           (not C)
           (and M
                (not L)
                (not K)
                J
                (not I)
                (not H)
                G
                (= O N)
                (= S R)
                (= U T)
                (= U P)
                (= W V)))
       (or B
           F
           Y
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
                (= S R)
                (= U T)
                (= U P)
                (= W V)))
       (or A
           B
           C
           Y
           (not D)
           (not F)
           (not E)
           (and (not M)
                (not L)
                (not K)
                J
                (not I)
                (not H)
                (not G)
                (= O N)
                (= S R)
                (= U T)
                (= U P)
                (= W V)))
       (or F Y (not B) (not A) (not C) (not D) (not E) a!31)
       (or A D F Y (not B) (not C) (not E) a!32)
       (or A
           Y
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
                (= U T)
                (= U R)
                (= W V)))
       (or B
           Y
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
                (= U T)
                (= U R)
                (= W V)))
       (or A C (not Y) (not B) (not D) (not F) (not E) a!1)
       (or A C E (not Y) (not B) (not D) (not F) a!2)
       (or A C F (not Y) (not B) (not D) (not E) a!3)
       (or A C E F (not Y) (not B) (not D) a!4)
       (or A
           C
           D
           E
           F
           (not Y)
           (not B)
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
                (= W V)))
       (or B
           E
           (not Y)
           (not A)
           (not C)
           (not D)
           (not F)
           (and M (not L) K J I H G (= O N) (= Q P) (= S R) (= U T) (= W V)))
       (or B
           E
           F
           (not Y)
           (not A)
           (not C)
           (not D)
           (and M
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
                (= W V)))
       (or B
           D
           E
           (not Y)
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
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or B D E F (not Y) (not A) (not C) a!5)
       (or B C (not Y) (not A) (not D) (not F) (not E) a!6)
       (or B C E (not Y) (not A) (not D) (not F) a!7)
       (or B C F (not Y) (not A) (not D) (not E) a!8)
       (or B C E F (not Y) (not A) (not D) a!9)
       (or B
           C
           D
           F
           (not Y)
           (not A)
           (not E)
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
                (= W V)))
       (or A
           B
           (not Y)
           (not C)
           (not D)
           (not F)
           (not E)
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
                (= W V)))
       (or A
           B
           F
           (not Y)
           (not C)
           (not D)
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
                (= W V)))
       (or A
           B
           D
           (not Y)
           (not C)
           (not F)
           (not E)
           (and M
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
                (= W V)))
       (or B
           C
           D
           (not Y)
           (not A)
           (not F)
           (not E)
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
                (= W V)))
       (or A B C (not Y) (not D) (not F) (not E) a!10)
       (or A B C E F (not Y) (not D) a!11)
       (or A B C D (not Y) (not F) (not E) a!12)
       (or A B C D E (not Y) (not F) a!13)
       (or A B C D F (not Y) (not E) a!14)
       (or A B C D E F (not Y) a!15)
       (or Y (not B) (not A) (not C) (not D) (not F) (not E) a!16)
       (or E
           F
           Y
           (not B)
           (not A)
           (not C)
           (not D)
           (and (not M)
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
                (= W V)))
       (or D
           E
           Y
           (not B)
           (not A)
           (not C)
           (not F)
           (and (not M)
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
                (= W V)))
       (or D
           E
           F
           Y
           (not B)
           (not A)
           (not C)
           (and (not M)
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
                (= W V)))
       (or C
           E
           Y
           (not B)
           (not A)
           (not D)
           (not F)
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
                (= W V)))
       (or C
           E
           F
           Y
           (not B)
           (not A)
           (not D)
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
                (= W V)))
       (or C
           D
           E
           Y
           (not B)
           (not A)
           (not F)
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
                (= W V)))
       (or E
           Y
           (not B)
           (not A)
           (not C)
           (not D)
           (not F)
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
                (= W V)))
       (or A E Y (not B) (not C) (not D) (not F) a!17)
       (or A F Y (not B) (not C) (not D) (not E) a!18)
       (or A E F Y (not B) (not C) (not D) a!19)
       (or A D Y (not B) (not C) (not F) (not E) a!20)
       (or A
           D
           E
           F
           Y
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
                (= S R)
                (= U T)
                (= W V)))
       (or A
           C
           E
           Y
           (not B)
           (not D)
           (not F)
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
                (= W V)))
       (or A
           C
           E
           F
           Y
           (not B)
           (not D)
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
                (= W V)))
       (or A
           C
           D
           E
           Y
           (not B)
           (not F)
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
                (= W V)))
       (or A
           D
           E
           Y
           (not B)
           (not C)
           (not F)
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
                (= W V)))
       (or A
           B
           C
           E
           (not Y)
           (not D)
           (not F)
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
                (= W V)))
       (or B E F Y (not A) (not C) (not D) a!21)
       (or B D Y (not A) (not C) (not F) (not E) a!22)
       (or B D E Y (not A) (not C) (not F) a!23)
       (or B D F Y (not A) (not C) (not E) a!24)
       (or B D E F Y (not A) (not C) a!25)
       (or B C Y (not A) (not D) (not F) (not E) a!26)
       (or B
           C
           E
           F
           Y
           (not A)
           (not D)
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
                (= W V)))
       (or B
           C
           D
           E
           Y
           (not A)
           (not F)
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
                (= W V)))
       (or B
           C
           D
           E
           F
           Y
           (not A)
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
                (= W V)))
       (or A
           B
           E
           Y
           (not C)
           (not D)
           (not F)
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
                (= W V)))
       (or A
           B
           E
           F
           Y
           (not C)
           (not D)
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
                (= W V)))
       (or A
           B
           D
           E
           Y
           (not C)
           (not F)
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
                (= W V)))
       (or B
           C
           E
           Y
           (not A)
           (not D)
           (not F)
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
                (= W V)))
       (or A
           C
           D
           (not Y)
           (not B)
           (not F)
           (not E)
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
                (= W V)))
       (or A B C D E F Y a!33)
       (or A B C D E Y (not F) a!33)
       (or A D E F (not Y) (not B) (not C) a!33)
       (or A
           C
           D
           F
           (not Y)
           (not B)
           (not E)
           (and M
                L
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= T O)
                (= O N)
                (= Q P)
                (= S R)
                (= W V)))
       (or A
           B
           C
           E
           F
           Y
           (not D)
           (<= 1 O)
           (and M
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
                (= W V)))))
      )
      (state H G I J K L M V T R P N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (state F E D C A B L K J I H G)
        (or (and (not L) (not A) B C (not D) E F)
    (and (not L) (not A) B C D (not E) (not F))
    (and (not L) (not A) B C D (not E) F)
    (and (not L) (not A) B C D E (not F))
    (and (not L) A (not B) (not C) D E F)
    (and (not L) A (not B) C (not D) (not E) (not F))
    (and (not L) A (not B) C (not D) (not E) F)
    (and (not L) A (not B) C (not D) E (not F))
    (and (not L) A (not B) C (not D) E F)
    (and (not L) A (not B) C D (not E) (not F))
    (and (not L) A B C D E F)
    (and L (not A) (not B) (not C) (not D) (not E) (not F))
    (and L (not A) (not B) (not C) (not D) (not E) F)
    (and L (not A) (not B) (not C) (not D) E (not F))
    (and L (not A) (not B) (not C) (not D) E F)
    (and L (not A) (not B) (not C) D (not E) (not F))
    (and L (not A) B (not C) D (not E) (not F))
    (and L (not A) B (not C) D (not E) F)
    (and L (not A) B (not C) D E (not F))
    (and L (not A) B (not C) D E F)
    (and L A (not B) (not C) D (not E) (not F))
    (and L A (not B) (not C) D (not E) F)
    (and L A (not B) (not C) D E (not F))
    (and L A (not B) (not C) D E F))
      )
      false
    )
  )
)

(check-sat)
(exit)
