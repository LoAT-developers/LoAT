; ./prepared/vmt/./ctigar/efm.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (and (= F true) (not E) (not D) (not C) (not B) (not A) (not G))
      )
      (state G F E D C B A H I J K L M)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) ) 
    (=>
      (and
        (state G F E D C B A P R T V X Z)
        (let ((a!1 (and N
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
                (= Z Y)))
      (a!2 (or B
               C
               E
               G
               (not A)
               (not D)
               (not F)
               (not (<= 1 (+ P R V)))
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
                    (= Z Y))))
      (a!3 (<= 0 (+ P R (* (- 1) T) (* (- 1) Z))))
      (a!4 (and N
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
                (= Z Y)))
      (a!5 (and N
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
                (= Z Y)))
      (a!6 (and N
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
                (= Z Y)))
      (a!7 (or B
               C
               D
               G
               (not A)
               (not E)
               (not F)
               (not (<= 1 (+ P Z)))
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
                    (= Z Y))))
      (a!8 (and N
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
                (= Z Y)))
      (a!9 (and N
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
                (= Z Y)))
      (a!10 (and N
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
                 (= Z Y)))
      (a!11 (and N
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
                 (= Z Y)))
      (a!12 (and N
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
                 (= Z Y)))
      (a!13 (or A
                E
                G
                (not B)
                (not C)
                (not D)
                (not F)
                (not (<= (+ T X Z) 1))
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
                     (= Z Y))))
      (a!14 (or A
                E
                (not B)
                (not C)
                (not D)
                (not G)
                (not F)
                (not (<= (+ T Z) 1))
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
                     (= Z Y))))
      (a!15 (or A
                D
                (not B)
                (not C)
                (not E)
                (not G)
                (not F)
                (not (<= 1 (+ T X Z)))
                (and (not N)
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
                     (= Z Y))))
      (a!16 (and (not N)
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
                 (= Z Y)))
      (a!17 (and (not N)
                 M
                 L
                 (not K)
                 J
                 I
                 (not H)
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ P (* (- 1) O)) (- 1))))
      (a!18 (and (not N)
                 M
                 (not L)
                 (not K)
                 (not J)
                 I
                 H
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ P (* (- 1) O)) (- 1))))
      (a!19 (and (not N)
                 (not M)
                 (not L)
                 (not K)
                 (not J)
                 I
                 H
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ P (* (- 1) O)) 1)))
      (a!20 (and (not N)
                 M
                 (not L)
                 K
                 J
                 I
                 (not H)
                 (= P O)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ R (* (- 1) Q)) (- 1))))
      (a!21 (and (not N)
                 (not M)
                 (not L)
                 K
                 (not J)
                 I
                 H
                 (= P O)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ R (* (- 1) Q)) (- 1))))
      (a!22 (and (not N)
                 M
                 (not L)
                 K
                 J
                 (not I)
                 H
                 (= P O)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!23 (and (not N)
                 (not M)
                 L
                 K
                 (not J)
                 I
                 H
                 (= P O)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!24 (and (not N)
                 M
                 (not L)
                 (not K)
                 J
                 I
                 H
                 (= P O)
                 (= R Q)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ T (* (- 1) S) X) 0)))
      (a!25 (and (not N)
                 (not M)
                 (not L)
                 (not K)
                 J
                 I
                 H
                 (= P O)
                 (= R Q)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= (+ T (* (- 1) S)) 1)))
      (a!26 (and (not N)
                 (not M)
                 L
                 K
                 J
                 I
                 H
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= (+ V (* (- 1) U)) (- 1))))
      (a!27 (and (not N)
                 M
                 L
                 (not K)
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= (+ V (* (- 1) U)) 1)))
      (a!28 (and (not N)
                 M
                 (not L)
                 K
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= (+ V (* (- 1) U)) 1)))
      (a!29 (and (not N)
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
                 (= Z Y)
                 (= (+ X (* (- 1) W) Z) 0)))
      (a!30 (and (not N)
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
                 (= (+ Z (* (- 1) Y)) (- 1))))
      (a!31 (and N
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
                 (= Z Y)))
      (a!32 (and (not N)
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
                 (= Z Y))))
  (and (or B C D G (not A) (not E) (not F) (<= 1 (+ P Z)) a!1)
       a!2
       (or B C D (not A) (not E) (not G) (not F) a!3 a!4)
       (or B C E G (not A) (not D) (not F) (<= 1 (+ P R V)) a!5)
       (or B
           C
           D
           (not A)
           (not E)
           (not G)
           (not F)
           (not a!3)
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
                (= Z Y)))
       (or A E (not B) (not C) (not D) (not G) (not F) (<= (+ T Z) 1) a!6)
       a!7
       (or A G (not B) (not C) (not D) (not E) (not F) (<= 0 Z) a!8)
       (or B
           C
           D
           E
           G
           (not A)
           (not F)
           (not (<= 0 V))
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
                (= Z Y)))
       (or A D (not B) (not C) (not E) (not G) (not F) (<= 1 (+ T X Z)) a!9)
       (or A (not B) (not C) (not D) (not E) (not G) (not F) (<= 0 T) a!10)
       (or A E G (not B) (not C) (not D) (not F) (<= (+ T X Z) 1) a!11)
       (or B
           C
           D
           E
           (not A)
           (not G)
           (not F)
           (not (<= 0 R))
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
                (= Z Y)))
       (or B C D E G (not A) (not F) (<= 0 V) a!12)
       (or A
           (not B)
           (not C)
           (not D)
           (not E)
           (not G)
           (not F)
           (not (<= 0 T))
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
                (= Z Y)))
       (or A
           C
           E
           G
           (not B)
           (not D)
           (not F)
           (not (<= 1 V))
           (and (not N)
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
                (= Z Y)))
       (or A
           G
           (not B)
           (not C)
           (not D)
           (not E)
           (not F)
           (not (<= 0 Z))
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
                (= Z Y)))
       a!13
       (or A
           C
           E
           G
           (not B)
           (not D)
           (not F)
           (<= 1 V)
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
                (= Z Y)))
       (or A
           C
           E
           F
           G
           (not B)
           (not D)
           (not (= A1 0))
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
                (= Z Y)))
       a!14
       a!15
       (or A
           C
           D
           E
           F
           G
           (not B)
           (= A1 0)
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
                (= Z Y)))
       (or A
           B
           C
           G
           (not D)
           (not E)
           (not F)
           (= A1 0)
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
                (= Z Y)))
       (or A
           C
           D
           E
           G
           (not B)
           (not F)
           (not (<= 1 T))
           (and (not N)
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
                (= Z Y)))
       (or A
           D
           E
           F
           G
           (not B)
           (not C)
           (not (<= 1 R))
           (and (not N)
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
                (= X W)
                (= Z Y)))
       (or A
           C
           D
           E
           G
           (not B)
           (not F)
           (<= 1 T)
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
                (= Z Y)))
       (or A
           C
           D
           E
           (not B)
           (not G)
           (not F)
           (not (<= 1 V))
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
                (= Z Y)))
       (or A
           D
           E
           F
           G
           (not B)
           (not C)
           (<= 1 R)
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
                (= Z Y)))
       (or A
           C
           D
           E
           F
           G
           (not B)
           (not (= A1 0))
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
                (= Z Y)))
       (or A
           C
           D
           E
           (not B)
           (not G)
           (not F)
           (<= 1 V)
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
                (= Z Y)))
       (or A
           C
           E
           F
           G
           (not B)
           (not D)
           (= A1 0)
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
                (= Z Y)))
       (or A
           B
           E
           F
           G
           (not C)
           (not D)
           (= A1 0)
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
                (= Z Y)))
       (or A
           B
           C
           F
           (not D)
           (not E)
           (not G)
           (not (= A1 0))
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
                (= Z Y)))
       (or A
           B
           E
           G
           (not C)
           (not D)
           (not F)
           (not (<= 1 R))
           (and (not N)
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
                (= Z Y)))
       (or A
           B
           C
           E
           G
           (not D)
           (not F)
           (not (= Z 0))
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
                (= Z Y)))
       (or A
           B
           C
           G
           (not D)
           (not E)
           (not F)
           (not (= A1 0))
           (and (not N)
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
                (= Z Y)))
       (or A
           B
           E
           G
           (not C)
           (not D)
           (not F)
           (<= 1 R)
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
                (= Z Y)))
       (or A
           B
           C
           E
           G
           (not D)
           (not F)
           (= Z 0)
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
                (= Z Y)))
       (or A
           B
           E
           (not C)
           (not D)
           (not G)
           (not F)
           (not (<= 1 X))
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
                (= Z Y)))
       (or A B C E (not D) (not G) (not F) (not (= X 0)) a!16)
       (or A
           B
           E
           F
           G
           (not C)
           (not D)
           (not (= A1 0))
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
                (= Z Y)))
       (or A
           B
           C
           D
           (not E)
           (not G)
           (not F)
           (not (= T 1))
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
                (= Z Y)))
       (or A
           B
           E
           (not C)
           (not D)
           (not G)
           (not F)
           (<= 1 X)
           (and (not N)
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
                (= X W)
                (= Z Y)))
       (or A
           B
           C
           E
           (not D)
           (not G)
           (not F)
           (= X 0)
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
                (= Z Y)))
       (or A
           B
           C
           F
           (not D)
           (not E)
           (not G)
           (= A1 0)
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
                (= Z Y)))
       (or A
           B
           C
           D
           (not E)
           (not G)
           (not F)
           (= T 1)
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
                (= Z Y)))
       (or A
           B
           C
           D
           G
           (not E)
           (not F)
           (not (= V 0))
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
                (= Z Y)))
       (or A
           B
           D
           E
           G
           (not C)
           (not F)
           (not (<= 1 T))
           (and (not N)
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
                (= Z Y)))
       (or A
           B
           C
           D
           E
           G
           (not F)
           (not (<= 1 P))
           (and (not N)
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
                (= Z Y)))
       (or A
           B
           C
           D
           G
           (not E)
           (not F)
           (= V 0)
           (and (not N)
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
                (= Z Y)))
       (or A
           B
           D
           E
           G
           (not C)
           (not F)
           (<= 1 T)
           (and (not N)
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
                (= Z Y)))
       (or A
           B
           C
           D
           E
           G
           (not F)
           (<= 1 P)
           (and (not N)
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
                (= Z Y)))
       (or A
           B
           C
           D
           E
           (not G)
           (not F)
           (not (= R 0))
           (and (not N)
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
                (= Z Y)))
       (or A
           B
           C
           (not D)
           (not E)
           (not G)
           (not F)
           (not (<= 1 P))
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
                (= Z Y)))
       (or A
           B
           C
           D
           E
           (not G)
           (not F)
           (= R 0)
           (and (not N)
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
                (= Z Y)))
       (or A
           B
           C
           (not D)
           (not E)
           (not G)
           (not F)
           (<= 1 P)
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
                (= Z Y)))
       (or A C F G (not B) (not D) (not E) a!17)
       (or A D E (not B) (not C) (not G) (not F) a!18)
       (or A B D E (not C) (not G) (not F) a!19)
       (or A C D F (not B) (not E) (not G) a!20)
       (or A B D G (not C) (not E) (not F) a!21)
       (or A D E F (not B) (not C) (not G) a!22)
       (or A B G (not C) (not D) (not E) (not F) a!23)
       (or A D F G (not B) (not C) (not E) a!24)
       (or A B D F G (not C) (not E) a!25)
       (or A B F (not C) (not D) (not E) (not G) a!26)
       (or A C E (not B) (not D) (not G) (not F) a!27)
       (or A C D G (not B) (not E) (not F) a!28)
       (or A C G (not B) (not D) (not E) (not F) a!29)
       (or A B D F (not C) (not E) (not G) a!30)
       (or B C (not A) (not D) (not E) (not G) (not F) a!31)
       (or B
           C
           E
           F
           (not A)
           (not D)
           (not G)
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
                (= Z Y)))
       (or B C F (not A) (not D) (not E) (not G) a!1)
       (or B C G (not A) (not D) (not E) (not F) a!4)
       (or B
           C
           E
           F
           G
           (not A)
           (not D)
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
                (= Z Y)))
       (or B C F G (not A) (not D) (not E) a!5)
       (or B
           C
           D
           F
           (not A)
           (not E)
           (not G)
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
                (= Z Y)))
       (or B D E (not A) (not C) (not G) (not F) a!6)
       (or B
           C
           D
           E
           F
           (not A)
           (not G)
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
                (= Z Y)))
       (or B D E F (not A) (not C) (not G) a!8)
       (or B D G (not A) (not C) (not E) (not F) a!9)
       (or B
           C
           D
           F
           G
           (not A)
           (not E)
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
                (= Z Y)))
       (or B D E G (not A) (not C) (not F) a!10)
       (or B
           C
           D
           E
           F
           G
           (not A)
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
                (= Z Y)))
       (or B D F G (not A) (not C) (not E) a!11)
       (or B D E F G (not A) (not C) a!12)
       (or A
           F
           (not B)
           (not C)
           (not D)
           (not E)
           (not G)
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
                (= Z Y)))
       (or A
           D
           F
           (not B)
           (not C)
           (not E)
           (not G)
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
                (= Z Y)))
       (or A
           E
           F
           (not B)
           (not C)
           (not D)
           (not G)
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
                (= Z Y)))
       (or A
           F
           G
           (not B)
           (not C)
           (not D)
           (not E)
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
                (= Z Y)))
       (or A
           E
           F
           G
           (not B)
           (not C)
           (not D)
           (and (not N)
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
                (= Z Y)))
       (or A
           C
           (not B)
           (not D)
           (not E)
           (not G)
           (not F)
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
                (= Z Y)))
       (or A
           C
           D
           (not B)
           (not E)
           (not G)
           (not F)
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
                (= Z Y)))
       (or A B D (not C) (not E) (not G) (not F) a!16)
       (or A
           B
           (not C)
           (not D)
           (not E)
           (not G)
           (not F)
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
                (= Z Y)))
       (or A B C D E F G a!32)
       (or A B C D E F (not G) a!32)
       (or A B C D F G (not E) a!32)
       (or A B C D F (not E) (not G) a!32)
       (or A B C E F G (not D) a!32)
       (or A B C E F (not D) (not G) a!32)
       (or A B C F G (not D) (not E) a!32)
       (or A B D E F G (not C) a!32)
       (or A B D E F (not C) (not G) a!32)
       (or A B E F (not C) (not D) (not G) a!32)
       (or A B F G (not C) (not D) (not E) a!32)
       (or A C D E F (not B) (not G) a!32)
       (or A C D F G (not B) (not E) a!32)
       (or A C E F (not B) (not D) (not G) a!32)
       (or A D E G (not B) (not C) (not F) a!32)
       (or B C E (not A) (not D) (not G) (not F) a!32)
       (or A
           D
           G
           (not B)
           (not C)
           (not E)
           (not F)
           (and (not N)
                M
                (not L)
                K
                (not J)
                I
                H
                (= W 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)))
       (or A
           C
           F
           (not B)
           (not D)
           (not E)
           (not G)
           (and (not N)
                M
                L
                K
                J
                I
                (not H)
                (= Y 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)))
       (or B C D E (not A) (not G) (not F) (<= 0 R) a!31)))
      )
      (state K J I L H M N O Q S U W Y)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (state G F E D C B A H I J K L M)
        (and (not B)
     (= A true)
     (or (and (not C) D E (not F) (not G))
         (and (not C) D E (not F) G)
         (and (not C) D E F (not G))
         (and (not C) D E F G)
         (and C (not D) (not E) (not F) (not G))
         (and C (not D) (not E) (not F) G)
         (and C (not D) (not E) F (not G))
         (and C (not D) (not E) F G)
         (and C (not D) E (not F) (not G))
         (and C (not D) E F (not G))))
      )
      false
    )
  )
)

(check-sat)
(exit)
