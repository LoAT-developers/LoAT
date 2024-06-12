; ./prepared/vmt/./ctigar/apache-escape-absolute.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (and (= E true) (not D) (not C) (not B) (not A) (not L) (not F))
      )
      (state F E D B A C L K J I H G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) ) 
    (=>
      (and
        (state F E D B A C Y W U S Q O)
        (let ((a!1 (not (<= (+ W (* (- 1) U)) (- 1))))
      (a!2 (not (<= (+ U (* (- 1) O)) (- 1))))
      (a!3 (and M
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
      (a!4 (and M
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
      (a!5 (and M
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
                (= W V)))
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
                (= W V)))
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
                (= W V)))
      (a!9 (and M
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
      (a!10 (and M
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
      (a!11 (not (<= (+ U (* (- 1) O)) 1)))
      (a!12 (and M
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
      (a!13 (and M
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
      (a!14 (and M
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
      (a!15 (and M
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
      (a!16 (and M
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
      (a!17 (and (not M)
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
                 (= W V)))
      (a!18 (and (not M)
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
      (a!19 (and (not M)
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
      (a!20 (and (not M)
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
      (a!21 (and (not M)
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
      (a!22 (and (not M)
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
      (a!23 (and (not M)
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
      (a!24 (or C
                F
                Y
                (not A)
                (not B)
                (not D)
                (not E)
                (= (+ U (* (- 1) O)) 2)
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
                     (= W V))))
      (a!25 (not (= (+ U (* (- 1) O)) 2)))
      (a!26 (or C
                D
                F
                Y
                (not A)
                (not B)
                (not E)
                (<= (+ U (* (- 1) O)) 1)
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
                     (= W V))))
      (a!27 (or B
                C
                Y
                (not A)
                (not D)
                (not F)
                (not E)
                (= (+ U (* (- 1) O)) 1)
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
                     (= W V))))
      (a!28 (not (= (+ U (* (- 1) O)) 1)))
      (a!29 (and (not M)
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
      (a!30 (or B
                C
                D
                E
                F
                Y
                (not A)
                (= (+ U (* (- 1) O)) 1)
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
                     (= W V))))
      (a!31 (or A
                B
                C
                Y
                (not D)
                (not F)
                (not E)
                (<= (+ U (* (- 1) O)) (- 1))
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
                     (= W V))))
      (a!32 (not (<= (- 1) (+ S (* (- 1) Q)))))
      (a!33 (and (<= (+ W (* (- 1) U)) (- 1)) (not (= W 0))))
      (a!34 (and M
                 (not L)
                 (not K)
                 J
                 I
                 (not H)
                 G
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= (+ O (* (- 1) N)) (- 1))))
      (a!35 (and (not M)
                 L
                 K
                 J
                 (not I)
                 (not H)
                 (not G)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= (+ O (* (- 1) N)) (- 1))))
      (a!36 (and (not M)
                 L
                 (not K)
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= (+ O (* (- 1) N)) (- 1))))
      (a!37 (and (not M)
                 L
                 (not K)
                 J
                 I
                 H
                 (not G)
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= (+ S (* (- 1) R)) (- 1))))
      (a!38 (and (not M)
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
      (a!39 (and (not M)
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
      (a!40 (and (not M)
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
      (a!41 (or A
                B
                Y
                (not C)
                (not D)
                (not F)
                (not E)
                (= (+ U (* (- 1) O)) 1)
                (<= (- 1) (+ S (* (- 1) Q)))
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
                     (= W V)))))
  (and (or A
           B
           C
           E
           F
           Y
           (not D)
           (= W 0)
           a!1
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
           D
           F
           Y
           (not E)
           (not (<= U 0))
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
                (= W V)))
       (or A
           B
           C
           D
           E
           Y
           (not F)
           (not (<= Q 0))
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
                (= W V)))
       (or A
           B
           C
           D
           Y
           (not F)
           (not E)
           (<= 0 W)
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
                (= W V)))
       (or A B C Y (not D) (not F) (not E) a!2 a!3)
       (or A C D F Y (not B) (not E) (<= 1 O) a!4)
       (or A C E F Y (not B) (not D) (not (<= U O)) a!5)
       (or A C E Y (not B) (not D) (not F) (<= 0 O) a!6)
       (or A C D E F (not Y) (not B) (not (<= U O)) a!7)
       (or A C D E (not Y) (not B) (not F) (<= 0 O) a!8)
       (or A
           C
           D
           E
           (not Y)
           (not B)
           (not F)
           (not (<= 0 O))
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
           C
           D
           E
           F
           (not Y)
           (not B)
           (<= U O)
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
       (or B
           C
           D
           F
           Y
           (not A)
           (not E)
           (= X 0)
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
                (= W V)))
       (or B C D Y (not A) (not F) (not E) (not (<= U O)) a!9)
       (or B C F Y (not A) (not D) (not E) (<= 0 O) a!10)
       (or C D F Y (not A) (not B) (not E) a!11 a!12)
       (or C D Y (not A) (not B) (not F) (not E) (<= (- 1) O) a!13)
       (or A C D Y (not B) (not F) (not E) (= X 0) a!14)
       (or A
           B
           D
           F
           Y
           (not C)
           (not E)
           (= X 0)
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
                (= W V)))
       (or A B D Y (not C) (not F) (not E) (not (<= U O)) a!15)
       (or A B F Y (not C) (not D) (not E) (<= 0 O) a!16)
       (or A D E F Y (not C) (not B) (not (<= U O)) a!17)
       (or A D E Y (not C) (not B) (not F) (<= 0 O) a!18)
       (or A E Y (not C) (not B) (not D) (not F) (not (<= Q S)) a!19)
       (or B D E F Y (not C) (not A) (<= 0 S) a!20)
       (or B D E Y (not C) (not A) (not F) (not (<= U O)) a!21)
       (or B E F Y (not C) (not A) (not D) (<= 0 O) a!22)
       (or A E F Y (not C) (not B) (not D) (= X 0) a!23)
       (or B
           E
           F
           Y
           (not C)
           (not A)
           (not D)
           (not (<= 0 O))
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
       (or B
           D
           E
           Y
           (not C)
           (not A)
           (not F)
           (<= U O)
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
       (or B
           D
           E
           F
           Y
           (not C)
           (not A)
           (not (<= 0 S))
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
           E
           Y
           (not C)
           (not B)
           (not D)
           (not F)
           (<= Q S)
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
       (or A
           E
           F
           Y
           (not C)
           (not B)
           (not D)
           (not (= X 0))
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
                (= W V)))
       (or A
           D
           E
           Y
           (not C)
           (not B)
           (not F)
           (not (<= 0 O))
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
                (= W V)))
       (or A
           D
           E
           F
           Y
           (not C)
           (not B)
           (<= U O)
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
           B
           F
           Y
           (not C)
           (not D)
           (not E)
           (not (<= 0 O))
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
           B
           D
           Y
           (not C)
           (not F)
           (not E)
           (<= U O)
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
           B
           D
           F
           Y
           (not C)
           (not E)
           (not (= X 0))
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
       a!24
       (or C
           F
           Y
           (not A)
           (not B)
           (not D)
           (not E)
           a!25
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
       (or C
           D
           Y
           (not A)
           (not B)
           (not F)
           (not E)
           (not (<= (- 1) O))
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
                (= W V)))
       a!26
       a!27
       (or B
           C
           Y
           (not A)
           (not D)
           (not F)
           (not E)
           a!28
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
                (= W V)))
       (or B
           C
           F
           Y
           (not A)
           (not D)
           (not E)
           (not (<= 0 O))
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
                (= W V)))
       (or B
           C
           D
           Y
           (not A)
           (not F)
           (not E)
           (<= U O)
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
       (or B C D E F Y (not A) a!28 a!29)
       (or B
           C
           D
           F
           Y
           (not A)
           (not E)
           (not (= X 0))
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
       a!30
       (or A
           C
           E
           Y
           (not B)
           (not D)
           (not F)
           (not (<= 0 O))
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
           C
           E
           F
           Y
           (not B)
           (not D)
           (<= U O)
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
           C
           D
           Y
           (not B)
           (not F)
           (not E)
           (not (= X 0))
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
           C
           D
           F
           Y
           (not B)
           (not E)
           (not (<= 1 O))
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
       a!31
       (or A
           B
           C
           D
           Y
           (not F)
           (not E)
           (not (<= 0 W))
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
       (or A
           B
           C
           D
           E
           Y
           (not F)
           (<= Q 0)
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
           (<= U 0)
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
       (or A
           B
           Y
           (not C)
           (not D)
           (not F)
           (not E)
           (and a!32 a!28)
           (and (not M) L K J I H G (= O N) (= Q P) (= S R) (= U T) (= W V)))
       (or A
           B
           C
           E
           F
           Y
           (not D)
           a!33
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
       (or A C E F (not Y) (not B) (not D) a!34)
       (or B Y (not C) (not A) (not D) (not F) (not E) a!35)
       (or C Y (not A) (not B) (not D) (not F) (not E) a!36)
       (or A
           B
           C
           E
           Y
           (not D)
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
                (= W N)))
       (or A F Y (not C) (not B) (not D) (not E) a!37)
       (or B C D (not Y) (not A) (not F) (not E) a!3)
       (or B C D E (not Y) (not A) (not F) a!4)
       (or B C D F (not Y) (not A) (not E) a!5)
       (or B C D E F (not Y) (not A) a!6)
       (or A C (not Y) (not B) (not D) (not F) (not E) a!7)
       (or A C E (not Y) (not B) (not D) (not F) a!8)
       (or A
           C
           D
           (not Y)
           (not B)
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
       (or A
           C
           D
           F
           (not Y)
           (not B)
           (not E)
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
       (or A B C (not Y) (not D) (not F) (not E) a!9)
       (or A B C E (not Y) (not D) (not F) a!10)
       (or A B C F (not Y) (not D) (not E) a!12)
       (or A B C E F (not Y) (not D) a!13)
       (or A B C D E (not Y) (not F) a!14)
       (or A B C D F (not Y) (not E) a!15)
       (or A B C D E F (not Y) a!16)
       (or E Y (not C) (not A) (not B) (not D) (not F) a!17)
       (or F Y (not C) (not A) (not B) (not D) (not E) a!18)
       (or E F Y (not C) (not A) (not B) (not D) a!19)
       (or D Y (not C) (not A) (not B) (not F) (not E) a!20)
       (or D E Y (not C) (not A) (not B) (not F) a!21)
       (or D F Y (not C) (not A) (not B) (not E) a!22)
       (or B E Y (not C) (not A) (not D) (not F) a!23)
       (or B
           F
           Y
           (not C)
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
                (= W V)))
       (or B
           D
           Y
           (not C)
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
                (= W V)))
       (or B
           D
           F
           Y
           (not C)
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
                (= W V)))
       (or A
           Y
           (not C)
           (not B)
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
                (= W V)))
       (or A
           D
           Y
           (not C)
           (not B)
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
                (= W V)))
       (or A
           D
           F
           Y
           (not C)
           (not B)
           (not E)
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
                (= W V)))
       (or A B E Y (not C) (not D) (not F) a!38)
       (or D E F Y (not C) (not A) (not B) a!38)
       (or A
           B
           E
           F
           Y
           (not C)
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
       (or C
           E
           F
           Y
           (not A)
           (not B)
           (not D)
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
       (or C
           D
           E
           Y
           (not A)
           (not B)
           (not F)
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
       (or B C D E Y (not A) (not F) a!29)
       (or A C F (not Y) (not B) (not D) (not E) a!39)
       (or A C Y (not B) (not D) (not F) (not E) a!39)
       (or A
           C
           F
           Y
           (not B)
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
                (= W V)))
       (or A
           C
           D
           E
           Y
           (not B)
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
       (or A
           C
           D
           E
           F
           Y
           (not B)
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
       (or A B C D E F Y a!40)
       (or A B C D (not Y) (not F) (not E) a!40)
       (or A B C F Y (not D) (not E) a!40)
       (or B C E F (not Y) (not A) (not D) a!40)
       (or B C E (not Y) (not A) (not D) (not F) a!40)
       (or B C F (not Y) (not A) (not D) (not E) a!40)
       (or C D E F Y (not A) (not B) a!40)
       (or C E Y (not A) (not B) (not D) (not F) a!40)
       (or Y (not C) (not A) (not B) (not D) (not F) (not E) a!40)
       (or A
           B
           D
           E
           Y
           (not C)
           (not F)
           (and (not M)
                L
                (not K)
                (not J)
                (not I)
                H
                G
                (= R 0)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)))
       (or A
           B
           D
           E
           F
           Y
           (not C)
           (and (not M)
                L
                (not K)
                (not J)
                (not I)
                (not H)
                G
                (= V O)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       a!41))
      )
      (state H G I J K L M V T R P N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (state F E D B A C L K J I H G)
        (or (and (not L) A B C (not D) (not E) F)
    (and (not L) A B C (not D) E (not F))
    (and (not L) A B C (not D) E F)
    (and (not L) A B C D (not E) (not F))
    (and (not L) A B C D (not E) F)
    (and (not L) A B C D E (not F))
    (and L (not A) (not B) (not C) (not D) (not E) (not F))
    (and L (not A) (not B) (not C) (not D) E (not F))
    (and L (not A) (not B) (not C) D (not E) (not F))
    (and L (not A) (not B) (not C) D (not E) F)
    (and L (not A) (not B) (not C) D E (not F))
    (and L (not A) (not B) (not C) D E F)
    (and L (not A) B (not C) D (not E) F)
    (and L (not A) B (not C) D E F)
    (and L A (not B) (not C) (not D) (not E) (not F))
    (and L A (not B) (not C) (not D) (not E) F)
    (and L A (not B) (not C) (not D) E (not F))
    (and L A (not B) (not C) (not D) E F))
      )
      false
    )
  )
)

(check-sat)
(exit)
