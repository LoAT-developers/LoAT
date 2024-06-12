; ./prepared/vmt/./ctigar/swim1.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (and (= F true) (not E) (not D) (not C) (not B) (not A) (not G))
      )
      (state G F E D B C A H I J K L M N O P)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (state G F E D B C A P R T V X Z B1 D1 F1)
        (let ((a!1 (and N
                M
                L
                K
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!2 (and N
                M
                L
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!3 (and N
                M
                L
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!4 (and N
                M
                L
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!5 (and N
                M
                L
                (not K)
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!6 (and N
                M
                L
                (not K)
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!7 (and N
                M
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!8 (and N
                M
                (not L)
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
      (a!9 (or C
               D
               E
               F
               (not A)
               (not B)
               (not G)
               (not (<= 1 (+ P R X B1 F1)))
               (and N
                    M
                    (not L)
                    K
                    J
                    (not I)
                    (not H)
                    (= P O)
                    (= R Q)
                    (= T S)
                    (= V U)
                    (= X W)
                    (= Z Y)
                    (= B1 A1)
                    (= D1 C1)
                    (= F1 E1))))
      (a!10 (or C
                D
                F
                G
                (not A)
                (not B)
                (not E)
                (not (<= 1 (+ P R V X B1)))
                (and N
                     M
                     (not L)
                     (not K)
                     J
                     I
                     (not H)
                     (= P O)
                     (= R Q)
                     (= T S)
                     (= V U)
                     (= X W)
                     (= Z Y)
                     (= B1 A1)
                     (= D1 C1)
                     (= F1 E1))))
      (a!11 (or C
                D
                E
                F
                G
                (not A)
                (not B)
                (not (<= 1 (+ R V X Z)))
                (and N
                     M
                     (not L)
                     (not K)
                     J
                     (not I)
                     (not H)
                     (= P O)
                     (= R Q)
                     (= T S)
                     (= V U)
                     (= X W)
                     (= Z Y)
                     (= B1 A1)
                     (= D1 C1)
                     (= F1 E1))))
      (a!12 (<= 0 (+ R (* (- 1) T) V X Z)))
      (a!13 (and N
                 (not M)
                 (not L)
                 K
                 J
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!14 (<= 0 (+ P R X B1 (* (- 1) D1) F1)))
      (a!15 (and N
                 (not M)
                 (not L)
                 K
                 (not J)
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!16 (<= (+ P R X B1 (* (- 1) D1) F1) 0))
      (a!17 (and N
                 (not M)
                 (not L)
                 (not K)
                 J
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!18 (= (+ R (* (- 1) T) V X Z) 0))
      (a!19 (and N
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 I
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!20 (and N
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!21 (and (not N)
                 (not M)
                 L
                 K
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!22 (and (not N)
                 M
                 (not L)
                 K
                 J
                 (not I)
                 (not H)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ P (* (- 1) O)) (- 1))))
      (a!23 (and (not N)
                 M
                 L
                 K
                 J
                 (not I)
                 (not H)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ P (* (- 1) O)) 1)))
      (a!24 (and (not N)
                 M
                 L
                 (not K)
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ R (* (- 1) Q)) (- 1))))
      (a!25 (and (not N)
                 (not M)
                 (not L)
                 K
                 (not J)
                 (not I)
                 H
                 (= P O)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!26 (and (not N)
                 M
                 (not L)
                 (not K)
                 (not J)
                 I
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ V (* (- 1) U)) (- 1))))
      (a!27 (and (not N)
                 M
                 L
                 (not K)
                 J
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ V (* (- 1) U)) 1)))
      (a!28 (and (not N)
                 (not M)
                 L
                 (not K)
                 (not J)
                 I
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ X (* (- 1) W)) (- 1))))
      (a!29 (and (not N)
                 M
                 (not L)
                 K
                 (not J)
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ X (* (- 1) W)) 1)))
      (a!30 (and (not N)
                 (not M)
                 (not L)
                 K
                 J
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ Z (* (- 1) Y)) (- 1))))
      (a!31 (and (not N)
                 (not M)
                 L
                 K
                 J
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ Z (* (- 1) Y)) 1)))
      (a!32 (and (not N)
                 M
                 L
                 (not K)
                 J
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!33 (and (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 I
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!34 (and (not N)
                 M
                 (not L)
                 (not K)
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) 1)))
      (a!35 (and (not N)
                 (not M)
                 L
                 (not K)
                 J
                 I
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= D1 C1)
                 (= F1 E1)
                 (= (+ B1 (* (- 1) A1)) 1)))
      (a!36 (and (not N)
                 M
                 (not L)
                 K
                 J
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= (+ F1 (* (- 1) E1)) (- 1))))
      (a!37 (and (not N)
                 M
                 L
                 (not K)
                 (not J)
                 (not I)
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= (+ F1 (* (- 1) E1)) 1)))
      (a!38 (and N
                 M
                 L
                 K
                 J
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1)))
      (a!39 (and (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 (not I)
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= D1 C1)
                 (= F1 E1))))
  (and (or B C F G (not A) (not D) (not E) (<= 0 R) a!1)
       (or B C D F (not A) (not E) (not G) (<= 0 F1) a!2)
       (or B C F (not A) (not D) (not E) (not G) (<= 0 P) a!3)
       (or B C E F G (not A) (not D) (<= 0 X) a!4)
       (or C D E F G (not A) (not B) (<= 1 (+ R V X Z)) a!5)
       (or B C E F (not A) (not D) (not G) (<= 0 Z) a!6)
       (or C D E F (not A) (not B) (not G) (<= 1 (+ P R X B1 F1)) a!7)
       (or C D F G (not A) (not B) (not E) (<= 1 (+ P R V X B1)) a!8)
       a!9
       a!10
       a!11
       (or B
           C
           F
           (not A)
           (not D)
           (not E)
           (not G)
           (not (<= 0 P))
           (and N
                (not M)
                L
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           F
           (not A)
           (not D)
           (not G)
           (not (<= 0 Z))
           (and N
                (not M)
                L
                K
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           F
           G
           (not A)
           (not D)
           (not E)
           (not (<= 0 R))
           (and N
                (not M)
                L
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           F
           G
           (not A)
           (not D)
           (not (<= 0 X))
           (and N
                (not M)
                L
                (not K)
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           F
           (not A)
           (not E)
           (not G)
           (not (<= 0 F1))
           (and N
                (not M)
                (not L)
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A F G (not C) (not B) (not D) (not E) a!12 a!13)
       (or B
           C
           D
           E
           F
           (not A)
           (not G)
           (not (<= 0 V))
           (and N
                (not M)
                (not L)
                K
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A F (not C) (not B) (not D) (not E) (not G) a!14 a!15)
       (or B
           C
           D
           F
           G
           (not A)
           (not E)
           (not (<= 0 B1))
           (and N
                (not M)
                (not L)
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B C D E F G (not A) a!16 a!17)
       (or B
           C
           D
           E
           F
           G
           (not A)
           (not a!16)
           (and N
                (not M)
                (not L)
                (not K)
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A E F (not C) (not B) (not D) (not G) a!18 a!19)
       (or B C D E F (not A) (not G) (<= 0 V) a!20)
       (or A
           F
           (not C)
           (not B)
           (not D)
           (not E)
           (not G)
           (not a!14)
           (and (not N)
                M
                L
                K
                J
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           F
           (not B)
           (not D)
           (not E)
           (not G)
           (not (= G1 0))
           (and (not N)
                M
                L
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           F
           (not C)
           (not B)
           (not D)
           (not G)
           (not a!18)
           (and (not N)
                M
                L
                K
                J
                (not I)
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           G
           (not B)
           (not E)
           (not F)
           (= G1 0)
           (and (not N)
                M
                L
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           F
           (not D)
           (not E)
           (not G)
           (= G1 0)
           (and (not N)
                M
                L
                K
                (not J)
                (not I)
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           E
           F
           G
           (not B)
           (not D)
           (not (<= 1 V))
           (and (not N)
                M
                L
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           F
           G
           (not C)
           (not B)
           (not D)
           (not E)
           (not a!12)
           (and (not N)
                M
                L
                (not K)
                J
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           E
           F
           G
           (not B)
           (not D)
           (<= 1 V)
           (and (not N)
                M
                L
                (not K)
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           F
           (not B)
           (not E)
           (not G)
           (not (<= 1 P))
           (and (not N)
                M
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           G
           (not C)
           (not B)
           (not E)
           (not F)
           (not (<= 1 F1))
           (and (not N)
                M
                (not L)
                K
                J
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           F
           (not B)
           (not E)
           (not G)
           (<= 1 P)
           (and (not N)
                M
                (not L)
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           D
           G
           (not C)
           (not B)
           (not E)
           (not F)
           (<= 1 F1)
           (and (not N)
                M
                (not L)
                K
                (not J)
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           G
           (not B)
           (not E)
           (not F)
           (not (= G1 0))
           (and (not N)
                M
                (not L)
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           F
           G
           (not B)
           (not (<= 1 B1))
           (and (not N)
                M
                (not L)
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           F
           (not C)
           (not D)
           (not E)
           (not G)
           (= G1 0)
           (and (not N)
                M
                (not L)
                (not K)
                J
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           (not D)
           (not E)
           (not G)
           (not F)
           (= G1 0)
           (and (not N)
                M
                (not L)
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           (not C)
           (not D)
           (not E)
           (not G)
           (not F)
           (not (<= 1 X))
           (and (not N)
                M
                (not L)
                (not K)
                J
                (not I)
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           D
           E
           F
           G
           (not B)
           (<= 1 B1)
           (and (not N)
                M
                (not L)
                (not K)
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           (not C)
           (not D)
           (not E)
           (not G)
           (not F)
           (<= 1 X)
           (and (not N)
                M
                (not L)
                (not K)
                (not J)
                (not I)
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           (not D)
           (not E)
           (not G)
           (not F)
           (not (= G1 0))
           (and (not N)
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           F
           (not C)
           (not D)
           (not E)
           (not G)
           (not (= G1 0))
           (and (not N)
                (not M)
                L
                K
                J
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           F
           (not D)
           (not E)
           (not G)
           (not (= G1 0))
           (and (not N)
                (not M)
                L
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           F
           (not D)
           (not G)
           (<= 1 D1)
           (and (not N)
                (not M)
                L
                K
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           G
           (not C)
           (not E)
           (not F)
           (= G1 0)
           (and (not N)
                (not M)
                L
                K
                (not J)
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A B C F G (not D) (not E) (not (<= 1 T)) a!21)
       (or A
           B
           E
           F
           G
           (not C)
           (not D)
           (not (<= 1 B1))
           (and (not N)
                (not M)
                L
                K
                (not J)
                (not I)
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           F
           G
           (not D)
           (not (= T V))
           (and (not N)
                (not M)
                L
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           F
           G
           (not D)
           (not E)
           (<= 1 T)
           (and (not N)
                (not M)
                L
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           E
           F
           G
           (not C)
           (not D)
           (<= 1 B1)
           (and (not N)
                (not M)
                L
                (not K)
                J
                (not I)
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           F
           G
           (not D)
           (= T V)
           (and (not N)
                (not M)
                L
                (not K)
                J
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           E
           F
           (not D)
           (not G)
           (not (<= 1 D1))
           (and (not N)
                (not M)
                L
                (not K)
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           F
           (not C)
           (not E)
           (not G)
           (not (<= 1 Z))
           (and (not N)
                (not M)
                L
                (not K)
                (not J)
                (not I)
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           F
           (not E)
           (not G)
           (not (= B1 D1))
           (and (not N)
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           F
           (not C)
           (not E)
           (not G)
           (<= 1 Z)
           (and (not N)
                (not M)
                (not L)
                K
                J
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           F
           (not E)
           (not G)
           (= B1 D1)
           (and (not N)
                (not M)
                (not L)
                K
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           G
           (not C)
           (not E)
           (not F)
           (not (= G1 0))
           (and (not N)
                (not M)
                (not L)
                K
                (not J)
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           F
           (not B)
           (not D)
           (not E)
           (not G)
           (= G1 0)
           (and (not N)
                (not M)
                (not L)
                (not K)
                J
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           (not B)
           (not D)
           (not E)
           (not G)
           (not F)
           (not (<= 1 R))
           (and (not N)
                (not M)
                (not L)
                (not K)
                J
                (not I)
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           (not B)
           (not D)
           (not E)
           (not G)
           (not F)
           (<= 1 R)
           (and (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A C D E F (not B) (not G) a!22)
       (or A C E F (not B) (not D) (not G) a!23)
       (or A
           B
           C
           D
           E
           G
           (not F)
           (and (not N)
                (not M)
                (not L)
                K
                (not J)
                (not I)
                (not H)
                (= R Q)
                (= O 0)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A C E (not B) (not D) (not G) (not F) a!24)
       (or A B D E G (not C) (not F) a!25)
       (or A D E (not C) (not B) (not G) (not F) a!26)
       (or A C F G (not B) (not D) (not E) a!27)
       (or A B E (not C) (not D) (not G) (not F) a!28)
       (or A D E G (not C) (not B) (not F) a!29)
       (or A B D E F (not C) (not G) a!30)
       (or A B E F (not C) (not D) (not G) a!31)
       (or A E F G (not C) (not B) (not D) a!32)
       (or A B D E (not C) (not G) (not F) a!33)
       (or A C D E (not B) (not G) (not F) a!34)
       (or A B F G (not C) (not D) (not E) a!35)
       (or A D E F (not C) (not B) (not G) a!36)
       (or A D (not C) (not B) (not E) (not G) (not F) a!37)
       (or C (not A) (not B) (not D) (not E) (not G) (not F) a!38)
       (or C E (not A) (not B) (not D) (not G) (not F) a!1)
       (or C F (not A) (not B) (not D) (not E) (not G) a!2)
       (or C E F (not A) (not B) (not D) (not G) a!3)
       (or C G (not A) (not B) (not D) (not E) (not F) a!4)
       (or C E G (not A) (not B) (not D) (not F) a!5)
       (or C F G (not A) (not B) (not D) (not E) a!6)
       (or C E F G (not A) (not B) (not D) a!7)
       (or C D (not A) (not B) (not E) (not G) (not F) a!8)
       (or C
           D
           G
           (not A)
           (not B)
           (not E)
           (not F)
           (and N
                M
                (not L)
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or C
           D
           E
           G
           (not A)
           (not B)
           (not F)
           (and N
                M
                (not L)
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or C
           D
           E
           (not A)
           (not B)
           (not G)
           (not F)
           (and N
                M
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           (not A)
           (not D)
           (not E)
           (not G)
           (not F)
           (and N
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           G
           (not A)
           (not D)
           (not E)
           (not F)
           (and N
                (not M)
                L
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           G
           (not A)
           (not D)
           (not F)
           (and N
                (not M)
                L
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           E
           (not A)
           (not D)
           (not G)
           (not F)
           (and N
                (not M)
                L
                (not K)
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B
           C
           D
           (not A)
           (not E)
           (not G)
           (not F)
           (and N
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B D E (not A) (not C) (not G) (not F) a!13)
       (or B
           C
           D
           G
           (not A)
           (not E)
           (not F)
           (and N
                (not M)
                (not L)
                K
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B D E F (not A) (not C) (not G) a!15)
       (or B
           C
           D
           E
           G
           (not A)
           (not F)
           (and N
                (not M)
                (not L)
                K
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B D E G (not A) (not C) (not F) a!17)
       (or B D F G (not A) (not C) (not E) a!19)
       (or B
           C
           D
           E
           (not A)
           (not G)
           (not F)
           (and N
                (not M)
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or B D E F G (not A) (not C) a!20)
       (or A
           (not C)
           (not B)
           (not D)
           (not E)
           (not G)
           (not F)
           (and N
                (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           G
           (not C)
           (not B)
           (not D)
           (not E)
           (not F)
           (and (not N)
                M
                L
                K
                (not J)
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           D
           F
           G
           (not C)
           (not E)
           (and (not N)
                M
                L
                (not K)
                J
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           (not C)
           (not B)
           (not D)
           (not G)
           (not F)
           (and (not N)
                M
                L
                (not K)
                (not J)
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           E
           G
           (not C)
           (not B)
           (not D)
           (not F)
           (and (not N)
                M
                (not L)
                (not K)
                (not J)
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           C
           G
           (not B)
           (not D)
           (not E)
           (not F)
           (and (not N)
                M
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A C D F G (not B) (not E) a!21)
       (or A
           D
           F
           G
           (not C)
           (not B)
           (not E)
           (and (not N)
                (not M)
                L
                (not K)
                J
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           G
           (not C)
           (not D)
           (not E)
           (not F)
           (and (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                I
                H
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A B C D E F G a!39)
       (or A B C D (not E) (not G) (not F) a!39)
       (or A B C E G (not D) (not F) a!39)
       (or A B C E (not D) (not G) (not F) a!39)
       (or A B C G (not D) (not E) (not F) a!39)
       (or A B D E F G (not C) a!39)
       (or A B D (not C) (not E) (not G) (not F) a!39)
       (or A B E G (not C) (not D) (not F) a!39)
       (or A C D E G (not B) (not F) a!39)
       (or A C D (not B) (not E) (not G) (not F) a!39)
       (or A C E G (not B) (not D) (not F) a!39)
       (or A D E F G (not C) (not B) a!39)
       (or A D F (not C) (not B) (not E) (not G) a!39)
       (or C D F (not A) (not B) (not E) (not G) a!39)
       (or A
           B
           C
           D
           E
           F
           (not G)
           (and (not N)
                (not M)
                (not L)
                K
                J
                (not I)
                (not H)
                (= P O)
                (= Q 0)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           F
           G
           (not E)
           (and (not N)
                (not M)
                (not L)
                (not K)
                J
                I
                (not H)
                (= W 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           E
           (not G)
           (not F)
           (and (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                I
                (not H)
                (= Y 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)
                (= D1 C1)
                (= F1 E1)))
       (or A
           B
           C
           D
           G
           (not E)
           (not F)
           (and (not N)
                (not M)
                (not L)
                K
                (not J)
                I
                (not H)
                (= E1 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= D1 C1)))
       (or B C D F G (not A) (not E) (<= 0 B1) a!38)))
      )
      (state K J I L M H N O Q S U W Y A1 C1 E1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (state G F E D B C A H I J K L M N O P)
        (and (= A true)
     (or (and (not B) C (not D) (not E) (not F) (not G))
         (and (not B) C (not D) (not E) (not F) G)
         (and (not B) C (not D) (not E) F (not G))
         (and (not B) C (not D) (not E) F G)
         (and (not B) C (not D) E (not F) (not G))
         (and B (not C) (not D) E F G)
         (and B (not C) D (not E) (not F) (not G))
         (and B (not C) D (not E) (not F) G)
         (and B (not C) D (not E) F (not G))
         (and B (not C) D (not E) F G)
         (and B (not C) D E (not F) (not G))
         (and B (not C) D E (not F) G)
         (and B (not C) D E F (not G))
         (and B (not C) D E F G)))
      )
      false
    )
  )
)

(check-sat)
(exit)
