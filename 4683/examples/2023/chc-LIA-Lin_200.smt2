; ./prepared/vmt/./ctigar/lifo.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (and (= F true) (not E) (not D) (not C) (not B) (not A) (not G))
      )
      (state G F E D C B A H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (state G F E D C B A P R T V X Z B1)
        (let ((a!1 (and N
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
                (= B1 A1)))
      (a!2 (and N
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
                (= B1 A1)))
      (a!3 (and N
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
                (= B1 A1)))
      (a!4 (and N
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
                (= B1 A1)))
      (a!5 (and N
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
                (= B1 A1)))
      (a!6 (or B
               E
               G
               (not A)
               (not C)
               (not D)
               (not F)
               (not (<= (+ V Z) 1))
               (and N
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
                    (= B1 A1))))
      (a!7 (or B
               D
               (not A)
               (not C)
               (not E)
               (not G)
               (not F)
               (not (<= (+ T B1) 1))
               (and N
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
                    (= B1 A1))))
      (a!8 (= (+ P (* (- 1) O) T X B1) 0))
      (a!9 (= (+ P (* (- 1) O) R V Z) 0))
      (a!10 (and (not N)
                 (not M)
                 L
                 K
                 J
                 (not I)
                 H
                 (= R Q)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ P (* (- 1) O)) 1)))
      (a!11 (and (not N)
                 (not M)
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
                 (= (+ P (* (- 1) O)) 1)))
      (a!12 (and (not N)
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
                 (= B1 A1)
                 (= (+ R (* (- 1) Q) V Z) (- 1))))
      (a!13 (and (not N)
                 (not M)
                 L
                 K
                 J
                 I
                 H
                 (= P O)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ R (* (- 1) Q) V Z) (- 1))))
      (a!14 (and (not N)
                 M
                 L
                 K
                 J
                 (not I)
                 (not H)
                 (= P O)
                 (= T S)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!15 (and (not N)
                 (not M)
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
                 (= B1 A1)
                 (= (+ R (* (- 1) Q)) 1)))
      (a!16 (and N
                 (not M)
                 L
                 (not K)
                 (not J)
                 (not I)
                 (not H)
                 (= P O)
                 (= R Q)
                 (= V U)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ T (* (- 1) S)) 1)))
      (a!17 (and N
                 (not M)
                 L
                 K
                 (not J)
                 I
                 (not H)
                 (= P O)
                 (= R Q)
                 (= T S)
                 (= X W)
                 (= Z Y)
                 (= B1 A1)
                 (= (+ V (* (- 1) U)) 1)))
      (a!18 (and (not N)
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
                 (= Z Y)
                 (= B1 A1)
                 (= (+ T X (* (- 1) W) B1) (- 1))))
      (a!19 (and (not N)
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
                 (= Z Y)
                 (= B1 A1)
                 (= (+ T (* (- 1) W) B1) (- 1))))
      (a!20 (and N
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
                 (= Z Y)
                 (= B1 A1)
                 (= (+ X (* (- 1) W)) 1)))
      (a!21 (and (not N)
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
                 (= Z Y)
                 (= B1 A1)
                 (= (+ X (* (- 1) W)) 1)))
      (a!22 (and N
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
                 (= B1 A1)
                 (= (+ Z (* (- 1) Y)) (- 1))))
      (a!23 (and N
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
                 (= (+ B1 (* (- 1) A1)) (- 1))))
      (a!24 (and N
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
                 (= B1 A1)))
      (a!25 (and (not N)
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
                 (= B1 A1))))
  (and (or B G (not A) (not C) (not D) (not E) (not F) (<= 0 V) a!1)
       (or B (not A) (not C) (not D) (not E) (not G) (not F) (<= 0 B1) a!2)
       (or C D E G (not A) (not B) (not F) (<= 0 T) a!3)
       (or C
           D
           E
           G
           (not A)
           (not B)
           (not F)
           (not (<= 0 T))
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
                (= B1 A1)))
       (or B D (not A) (not C) (not E) (not G) (not F) (<= (+ T B1) 1) a!4)
       (or B E G (not A) (not C) (not D) (not F) (<= (+ V Z) 1) a!5)
       (or B
           (not A)
           (not C)
           (not D)
           (not E)
           (not G)
           (not F)
           (not (<= 0 B1))
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
                (= B1 A1)))
       (or A
           B
           C
           E
           G
           (not D)
           (not F)
           (= C1 0)
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
                (= B1 A1)))
       (or B
           G
           (not A)
           (not C)
           (not D)
           (not E)
           (not F)
           (not (<= 0 V))
           (and N
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
                (= Z Y)
                (= B1 A1)))
       (or B
           E
           (not A)
           (not C)
           (not D)
           (not G)
           (not F)
           (not (<= 0 Z))
           (and N
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
                (= B1 A1)))
       (or B
           D
           E
           F
           (not A)
           (not C)
           (not G)
           (not (<= 1 V))
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
                (= B1 A1)))
       (or B
           D
           E
           F
           (not A)
           (not C)
           (not G)
           (<= 1 V)
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
                (= B1 A1)))
       a!6
       (or B
           C
           F
           G
           (not A)
           (not D)
           (not E)
           (= C1 0)
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
                (= B1 A1)))
       a!7
       (or B
           C
           G
           (not A)
           (not D)
           (not E)
           (not F)
           (not (<= 1 T))
           (and N
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
                (= B1 A1)))
       (or B
           C
           G
           (not A)
           (not D)
           (not E)
           (not F)
           (<= 1 T)
           (and N
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
                (= B1 A1)))
       (or B
           C
           D
           F
           G
           (not A)
           (not E)
           (not (<= 1 X))
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
                (= B1 A1)))
       (or B
           C
           F
           G
           (not A)
           (not D)
           (not E)
           (not (= C1 0))
           (and N
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
                (= B1 A1)))
       (or B
           C
           D
           F
           G
           (not A)
           (not E)
           (<= 1 X)
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
                (= B1 A1)))
       (or B
           C
           D
           E
           (not A)
           (not G)
           (not F)
           (= C1 0)
           (and N
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
                (= B1 A1)))
       (or B
           C
           D
           E
           (not A)
           (not G)
           (not F)
           (not (= C1 0))
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
                (= B1 A1)))
       (or A
           E
           (not B)
           (not C)
           (not D)
           (not G)
           (not F)
           (= C1 0)
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
                (= B1 A1)))
       (or A
           F
           G
           (not B)
           (not C)
           (not D)
           (not E)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or A
           F
           G
           (not B)
           (not C)
           (not D)
           (not E)
           (<= 1 R)
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
                (= B1 A1)))
       (or A
           D
           E
           (not B)
           (not C)
           (not G)
           (not F)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or A
           E
           (not B)
           (not C)
           (not D)
           (not G)
           (not F)
           (not (= C1 0))
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
                (= B1 A1)))
       (or A
           D
           E
           (not B)
           (not C)
           (not G)
           (not F)
           (<= 1 R)
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
                (= B1 A1)))
       (or A
           D
           E
           F
           (not B)
           (not C)
           (not G)
           (= C1 0)
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
                (= B1 A1)))
       (or A
           D
           E
           F
           (not B)
           (not C)
           (not G)
           (not (= C1 0))
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
                (= B1 A1)))
       (or A
           C
           E
           F
           (not B)
           (not D)
           (not G)
           (= C1 0)
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
                (= B1 A1)))
       (or A
           C
           E
           (not B)
           (not D)
           (not G)
           (not F)
           (not (<= 1 X))
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
                (= B1 A1)))
       (or A
           C
           D
           E
           (not B)
           (not G)
           (not F)
           (not (<= 1 X))
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
                (= B1 A1)))
       (or A
           C
           E
           (not B)
           (not D)
           (not G)
           (not F)
           (<= 1 X)
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
                (= Z Y)
                (= B1 A1)))
       (or A
           C
           D
           E
           (not B)
           (not G)
           (not F)
           (<= 1 X)
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
                (= B1 A1)))
       (or A
           C
           E
           F
           (not B)
           (not D)
           (not G)
           (not (= C1 0))
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
                (= B1 A1)))
       (or A
           C
           D
           E
           F
           (not B)
           (not G)
           (not (= C1 0))
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
                (= B1 A1)))
       (or A
           C
           D
           E
           F
           (not B)
           (not G)
           (= C1 0)
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
                (= B1 A1)))
       (or A
           B
           E
           F
           (not C)
           (not D)
           (not G)
           (= C1 0)
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
                (= B1 A1)))
       (or A
           B
           E
           (not C)
           (not D)
           (not G)
           (not F)
           (not (<= 1 P))
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
                (= B1 A1)))
       (or A
           B
           D
           E
           (not C)
           (not G)
           (not F)
           (not (<= 1 P))
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
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           E
           (not C)
           (not D)
           (not G)
           (not F)
           (<= 1 P)
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
                (= B1 A1)))
       (or A
           B
           D
           E
           (not C)
           (not G)
           (not F)
           (<= 1 P)
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
                (= B1 A1)))
       (or A
           B
           E
           F
           (not C)
           (not D)
           (not G)
           (not (= C1 0))
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
                (= B1 A1)))
       (or A
           B
           D
           E
           F
           (not C)
           (not G)
           (not (= C1 0))
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
                (= B1 A1)))
       (or A
           B
           D
           E
           F
           (not C)
           (not G)
           (= C1 0)
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
                (= B1 A1)))
       (or A
           B
           C
           E
           F
           (not D)
           (not G)
           (= C1 0)
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
                (= B1 A1)))
       (or A
           B
           C
           E
           (not D)
           (not G)
           (not F)
           (not (<= 1 R))
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
                (= B1 A1)))
       (or A
           B
           C
           E
           (not D)
           (not G)
           (not F)
           (<= 1 R)
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
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           C
           E
           F
           (not D)
           (not G)
           (not (= C1 0))
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
                (= B1 A1)))
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
                (= B1 A1)))
       (or A
           B
           C
           E
           G
           (not D)
           (not F)
           (not (= C1 0))
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
                (= B1 A1)))
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
                (= B1 A1)))
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
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                a!8))
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
                K
                J
                (not I)
                H
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                a!8))
       (or B
           C
           D
           (not A)
           (not E)
           (not G)
           (not F)
           (and N
                (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                H
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                a!9))
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
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                a!9))
       (or A B G (not C) (not D) (not E) (not F) a!10)
       (or A B D G (not C) (not E) (not F) a!11)
       (or A C D F (not B) (not E) (not G) a!12)
       (or A B F (not C) (not D) (not E) (not G) a!13)
       (or A D G (not B) (not C) (not E) (not F) a!14)
       (or A B C G (not D) (not E) (not F) a!15)
       (or B C (not A) (not D) (not E) (not G) (not F) a!16)
       (or B D F G (not A) (not C) (not E) a!17)
       (or A B D F (not C) (not E) (not G) a!18)
       (or A B C F (not D) (not E) (not G) a!19)
       (or B C D F (not A) (not E) (not G) a!20)
       (or A C D G (not B) (not E) (not F) a!21)
       (or B D G (not A) (not C) (not E) (not F) a!22)
       (or B D E F G (not A) (not C) a!23)
       (or C D (not A) (not B) (not E) (not G) (not F) a!24)
       (or C D F (not A) (not B) (not E) (not G) a!1)
       (or C D G (not A) (not B) (not E) (not F) a!2)
       (or C D F G (not A) (not B) (not E) a!3)
       (or C
           D
           E
           F
           (not A)
           (not B)
           (not G)
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
                (= B1 A1)))
       (or C E G (not A) (not B) (not D) (not F) a!4)
       (or C
           D
           E
           F
           G
           (not A)
           (not B)
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
                (= B1 A1)))
       (or C E F G (not A) (not B) (not D) a!5)
       (or B
           F
           (not A)
           (not C)
           (not D)
           (not E)
           (not G)
           (and N
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
                (= B1 A1)))
       (or B
           F
           G
           (not A)
           (not C)
           (not D)
           (not E)
           (and N
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
                (= B1 A1)))
       (or B
           E
           F
           (not A)
           (not C)
           (not D)
           (not G)
           (and N
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
                (= B1 A1)))
       (or B
           E
           F
           G
           (not A)
           (not C)
           (not D)
           (and N
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
                (= Z Y)
                (= B1 A1)))
       (or B
           D
           F
           (not A)
           (not C)
           (not E)
           (not G)
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
                (= B1 A1)))
       (or B
           D
           E
           G
           (not A)
           (not C)
           (not F)
           (and N
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
                (= B1 A1)))
       (or B
           C
           E
           (not A)
           (not D)
           (not G)
           (not F)
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
                (= B1 A1)))
       (or B
           C
           D
           E
           F
           (not A)
           (not G)
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
                (= Z Y)
                (= B1 A1)))
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
                (= B1 A1)))
       (or A
           D
           E
           G
           (not B)
           (not C)
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
                (= B1 A1)))
       (or A
           C
           E
           G
           (not B)
           (not D)
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
                (= B1 A1)))
       (or A
           C
           D
           E
           G
           (not B)
           (not F)
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
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           E
           G
           (not C)
           (not D)
           (not F)
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
                (= B1 A1)))
       (or A
           B
           D
           E
           G
           (not C)
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
                (= B1 A1)))
       (or A B C D E F G a!25)
       (or A B C D E F (not G) a!25)
       (or A B C F G (not D) (not E) a!25)
       (or A B D F G (not C) (not E) a!25)
       (or A B F G (not C) (not D) (not E) a!25)
       (or A C D F G (not B) (not E) a!25)
       (or A C F G (not B) (not D) (not E) a!25)
       (or A D F G (not B) (not C) (not E) a!25)
       (or A G (not B) (not C) (not D) (not E) (not F) a!25)
       (or B C D G (not A) (not E) (not F) a!25)
       (or B C F (not A) (not D) (not E) (not G) a!25)
       (or B D E (not A) (not C) (not G) (not F) a!25)
       (or C D E (not A) (not B) (not G) (not F) a!25)
       (or B
           C
           E
           F
           G
           (not A)
           (not D)
           (and N
                (not M)
                (not L)
                (not K)
                (not J)
                I
                H
                (= Q 0)
                (= P O)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           (not B)
           (not C)
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
                (= Q 0)
                (= P O)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           C
           D
           F
           (not E)
           (not G)
           (and (not N)
                (not M)
                (not L)
                K
                J
                I
                (not H)
                (= Q 0)
                (= P O)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           D
           (not C)
           (not E)
           (not G)
           (not F)
           (and (not N)
                (not M)
                L
                (not K)
                (not J)
                (not I)
                H
                (= S 0)
                (= P O)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           C
           (not D)
           (not E)
           (not G)
           (not F)
           (and (not N)
                (not M)
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (= S 0)
                (= P O)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
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
                K
                (not J)
                I
                (not H)
                (= S 0)
                (= P O)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
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
                (not J)
                I
                H
                (= S 1)
                (= P O)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           C
           (not B)
           (not D)
           (not E)
           (not G)
           (not F)
           (and (not N)
                M
                L
                (not K)
                (not J)
                (not I)
                (not H)
                (= S 1)
                (= P O)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           C
           D
           (not B)
           (not E)
           (not G)
           (not F)
           (and (not N)
                M
                (not L)
                (not K)
                (not J)
                (not I)
                H
                (= U 0)
                (= P O)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           (not C)
           (not D)
           (not E)
           (not G)
           (not F)
           (and (not N)
                M
                (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                (= U 0)
                (= P O)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           C
           D
           (not E)
           (not G)
           (not F)
           (and (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                (not I)
                H
                (= U 0)
                (= P O)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or B
           C
           E
           G
           (not A)
           (not D)
           (not F)
           (and N
                (not M)
                (not L)
                (not K)
                J
                (not I)
                H
                (= U 1)
                (= P O)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)))
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
                (not J)
                I
                (not H)
                (= U 1)
                (= P O)
                (= R Q)
                (= T S)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           D
           (not B)
           (not C)
           (not E)
           (not G)
           (not F)
           (and (not N)
                M
                L
                (not K)
                (not J)
                (not I)
                H
                (= W 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)))
       (or A
           C
           F
           (not B)
           (not D)
           (not E)
           (not G)
           (and (not N)
                M
                (not L)
                K
                J
                I
                H
                (= W 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)))
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
                K
                (not J)
                (not I)
                (not H)
                (= W 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)))
       (or B
           C
           E
           F
           (not A)
           (not D)
           (not G)
           (and N
                (not M)
                (not L)
                (not K)
                J
                I
                H
                (= Y 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)))
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
                (not K)
                J
                (not I)
                (not H)
                (= Y 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)))
       (or A
           C
           E
           F
           G
           (not B)
           (not D)
           (and (not N)
                M
                (not L)
                (not K)
                (not J)
                I
                H
                (= Y 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)))
       (or A
           C
           D
           E
           F
           G
           (not B)
           (and (not N)
                M
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
                (= B1 A1)))
       (or A
           B
           C
           E
           F
           G
           (not D)
           (and (not N)
                (not M)
                (not L)
                (not K)
                (not J)
                I
                H
                (= Y 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)))
       (or A
           E
           G
           (not B)
           (not C)
           (not D)
           (not F)
           (and (not N)
                M
                L
                (not K)
                J
                (not I)
                H
                (= A1 0)
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
           (and (not N)
                M
                L
                (not K)
                (not J)
                I
                (not H)
                (= A1 0)
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
           (and (not N)
                (not M)
                L
                (not K)
                (not J)
                I
                H
                (= A1 0)
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
           F
           G
           (not C)
           (and (not N)
                (not M)
                L
                (not K)
                (not J)
                I
                (not H)
                (= A1 0)
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
           (and (not N)
                (not M)
                (not L)
                K
                J
                (not I)
                (not H)
                (= A1 0)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)))
       (or B E (not A) (not C) (not D) (not G) (not F) (<= 0 Z) a!24)))
      )
      (state J I K H L M N O Q S U W Y A1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (state G F E D C B A H I J K L M N)
        (and (not C)
     (= B true)
     (= A true)
     (or (and (not D) E (not F) (not G))
         (and (not D) E (not F) G)
         (and (not D) E F (not G))
         (and (not D) E F G)
         (and D (not E) (not F) (not G))
         (and D (not E) F (not G))))
      )
      false
    )
  )
)

(check-sat)
(exit)
