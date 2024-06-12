; ./prepared/vmt/./ctigar/large_const.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (and (= E true) (not D) (not C) (not B) (not A) (not F))
      )
      (state F E D C B A N M L K J I H G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (state F E D C B A B1 Z X V T R P N)
        (let ((a!1 (and L
                (not K)
                (not J)
                (not I)
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
      (a!2 (and (not L)
                (not K)
                J
                I
                (not H)
                (not G)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= (+ N (* (- 1) M)) (- 1))))
      (a!3 (and (not L)
                K
                J
                I
                H
                (not G)
                (= N M)
                (= P O)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= (+ R (* (- 1) Q)) (- 1))))
      (a!4 (and (not L)
                K
                (not J)
                I
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= (+ X T (* (- 1) S)) 0)))
      (a!5 (and (not L)
                K
                J
                (not I)
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= (+ V T (* (- 1) S)) 0)))
      (a!6 (and (not L)
                K
                (not J)
                (not I)
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= (+ T (* (- 1) S) P) 0)))
      (a!7 (and (not L)
                K
                J
                I
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)
                (= (+ T (* (- 1) S)) 1)))
      (a!8 (and (not L)
                (not K)
                (not J)
                (not I)
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1))))
  (and (or A D (not B) (not C) (not F) (not E) (not (<= T 0)) a!1)
       (or A
           D
           (not B)
           (not C)
           (not F)
           (not E)
           (<= T 0)
           (and (not L)
                K
                J
                I
                (not H)
                (not G)
                (= N M)
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
           (not F)
           (<= B1 R)
           (and (not L)
                K
                J
                (not I)
                H
                G
                (= N M)
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
           (not F)
           (not (<= B1 N))
           (and (not L)
                K
                J
                (not I)
                (not H)
                G
                (= N M)
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
           (= Z 1)
           (and (not L)
                K
                (not J)
                I
                H
                G
                (= N M)
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
           (not (= Z 1))
           (and (not L)
                K
                (not J)
                I
                (not H)
                G
                (= N M)
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
           F
           (not B)
           (not E)
           (= Z 0)
           (and (not L)
                K
                (not J)
                I
                (not H)
                (not G)
                (= N M)
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
           F
           (not B)
           (not E)
           (not (= Z 0))
           (and (not L)
                K
                (not J)
                (not I)
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           (not C)
           (not D)
           (not F)
           (not E)
           (<= 2 Z)
           (and (not L)
                K
                (not J)
                (not I)
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           (not C)
           (not D)
           (not F)
           (not E)
           (not (<= 2 Z))
           (and (not L)
                K
                (not J)
                (not I)
                (not H)
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           F
           (not C)
           (not D)
           (not E)
           (not (<= 0 Z))
           (and (not L)
                (not K)
                J
                I
                H
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           F
           (not C)
           (not D)
           (not E)
           (<= 0 Z)
           (and (not L)
                (not K)
                J
                I
                H
                (not G)
                (= N M)
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
           (not F)
           (<= B1 N)
           (and (not L)
                (not K)
                J
                (not I)
                H
                G
                (= N M)
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
           (not F)
           (not (<= 0 B1))
           (and (not L)
                (not K)
                J
                (not I)
                (not H)
                (not G)
                (= N M)
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
           (not F)
           (<= 0 B1)
           (and (not L)
                (not K)
                (not J)
                I
                H
                G
                (= N M)
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
           (<= 10 B1)
           (and (not L)
                (not K)
                (not J)
                I
                H
                (not G)
                (= N M)
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
           (not (<= 10 B1))
           (and (not L)
                (not K)
                (not J)
                I
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A B D (not C) (not F) (not E) a!2)
       (or A
           B
           D
           F
           (not C)
           (not E)
           (and (not L)
                (not K)
                J
                (not I)
                H
                (not G)
                (= P O)
                (= M 0)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A F (not B) (not C) (not D) (not E) a!3)
       (or A C F (not B) (not D) (not E) a!4)
       (or A C (not B) (not D) (not F) (not E) a!5)
       (or A C D E (not B) (not F) a!6)
       (or A E (not B) (not C) (not D) (not F) a!7)
       (or B C D E F (not A) a!1)
       (or A
           E
           F
           (not B)
           (not C)
           (not D)
           (and (not L)
                K
                J
                I
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A
           (not B)
           (not C)
           (not D)
           (not F)
           (not E)
           (and (not L)
                K
                J
                (not I)
                H
                (not G)
                (= N M)
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
           (and (not L)
                K
                (not J)
                I
                H
                (not G)
                (= N M)
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
           (not F)
           (and (not L)
                K
                (not J)
                (not I)
                H
                G
                (= N M)
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
           (not B)
           (not F)
           (not E)
           (and (not L)
                (not K)
                J
                (not I)
                H
                (not G)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))
       (or A B C D E F a!8)
       (or A B C F (not D) (not E) a!8)
       (or A B C (not D) (not F) (not E) a!8)
       (or A B E (not C) (not D) (not F) a!8)
       (or A C D E F (not B) a!8)
       (or B C D F (not A) (not E) a!8)
       (or A
           B
           C
           D
           F
           (not E)
           (and (not L)
                (not K)
                (not J)
                (not I)
                H
                (not G)
                (= N M)
                (= O 4000)
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
           (and (not L)
                K
                J
                (not I)
                H
                (not G)
                (= Q 0)
                (= N M)
                (= P O)
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
           (and (not L)
                (not K)
                J
                (not I)
                (not H)
                G
                (= S 0)
                (= N M)
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
           (not F)
           (not E)
           (and (not L)
                (not K)
                (not J)
                I
                (not H)
                (not G)
                (= U 10000)
                (= N M)
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
           E
           (not F)
           (and (not L)
                (not K)
                (not J)
                (not I)
                H
                G
                (= W 2000)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= Z Y)
                (= B1 A1)))
       (or A
           B
           E
           F
           (not C)
           (not D)
           (and (not L)
                (not K)
                J
                I
                (not H)
                G
                (= Y C1)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= B1 A1)))
       (or A
           D
           E
           (not B)
           (not C)
           (not F)
           (not (<= B1 R))
           (and L
                (not K)
                (not J)
                (not I)
                (not H)
                G
                (= N M)
                (= P O)
                (= R Q)
                (= T S)
                (= V U)
                (= X W)
                (= Z Y)
                (= B1 A1)))))
      )
      (state H G I J K L A1 Y W U S Q O M)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (state F E D C B A N M L K J I H G)
        (and (not E) (not D) (not C) (not B) (= A true) (not F))
      )
      false
    )
  )
)

(check-sat)
(exit)
