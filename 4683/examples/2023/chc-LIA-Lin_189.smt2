; ./prepared/vmt/./ctigar/sendmail-close-angle.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) (K Bool) ) 
    (=>
      (and
        (and (= C true) (not B) (not A) (not K) (not J) (not D))
      )
      (state D C A B K J E F G H I)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Bool) (W Bool) ) 
    (=>
      (and
        (state D C A B W V L N P R T)
        (let ((a!1 (and J
                (not I)
                (not H)
                G
                (not F)
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
      (a!2 (and J
                (not I)
                (not H)
                (not G)
                F
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
      (a!3 (and J
                (not I)
                (not H)
                (not G)
                (not F)
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
      (a!4 (and (not J) I (not H) G F E (= L K) (= N M) (= P O) (= R Q) (= T S)))
      (a!5 (and (not J)
                I
                (not H)
                G
                (not F)
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
      (a!6 (and (not J)
                I
                (not H)
                (not G)
                F
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
      (a!7 (and (not J)
                I
                (not H)
                (not G)
                (not F)
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
      (a!8 (and (not J)
                (not I)
                H
                G
                (not F)
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
      (a!9 (and J
                (not I)
                (not H)
                (not G)
                F
                (not E)
                (= L K)
                (= P O)
                (= R Q)
                (= T S)
                (= (+ N (* (- 1) M)) (- 1))))
      (a!10 (and (not J)
                 (not I)
                 (not H)
                 (not G)
                 F
                 E
                 (= L K)
                 (= N M)
                 (= R Q)
                 (= T S)
                 (= (+ L (* (- 1) O)) 2)))
      (a!11 (and J
                 (not I)
                 (not H)
                 G
                 (not F)
                 (not E)
                 (= L K)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= (+ T (* (- 1) S)) (- 1))))
      (a!12 (and (not J)
                 I
                 H
                 G
                 F
                 (not E)
                 (= L K)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= (+ T (* (- 1) S)) (- 1))))
      (a!13 (and (not J)
                 I
                 (not H)
                 (not G)
                 F
                 (not E)
                 (= L K)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= (+ T (* (- 1) S)) (- 1))))
      (a!14 (and J
                 (not I)
                 H
                 G
                 F
                 (not E)
                 (= L K)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S)))
      (a!15 (and (not J)
                 (not I)
                 (not H)
                 (not G)
                 (not F)
                 (not E)
                 (= L K)
                 (= N M)
                 (= P O)
                 (= R Q)
                 (= T S))))
  (and (or B
           C
           D
           W
           (not V)
           (not A)
           (<= R N)
           (and J
                (not I)
                H
                G
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A
           B
           C
           W
           (not V)
           (not D)
           (not (<= 0 N))
           (and J
                (not I)
                (not H)
                G
                F
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or C V (not W) (not B) (not A) (not D) (not (<= L T)) a!1)
       (or C D V (not W) (not B) (not A) (<= 0 T) a!2)
       (or A B C W (not V) (not D) (<= 0 N) a!3)
       (or C
           V
           (not W)
           (not B)
           (not A)
           (not D)
           (<= L T)
           (and (not J) I H G F E (= L K) (= N M) (= P O) (= R Q) (= T S)))
       (or C
           D
           V
           (not W)
           (not B)
           (not A)
           (not (<= 0 T))
           (and (not J) I H G (not F) E (= L K) (= N M) (= P O) (= R Q) (= T S)))
       (or B
           C
           D
           V
           (not W)
           (not A)
           (<= L T)
           (and (not J)
                I
                H
                G
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A
           V
           W
           (not B)
           (not D)
           (not C)
           (= P T)
           (and (not J)
                I
                H
                (not G)
                (not F)
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or D V W (not B) (not A) (not C) (<= 0 T) a!4)
       (or A
           B
           C
           V
           (not W)
           (not D)
           (not (<= 0 T))
           (and (not J)
                I
                (not H)
                G
                F
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A B C V (not W) (not D) (<= 0 T) a!5)
       (or V W (not B) (not A) (not D) (not C) (not (<= L T)) a!6)
       (or B C D V (not W) (not A) (not (<= L T)) a!7)
       (or V
           W
           (not B)
           (not A)
           (not D)
           (not C)
           (<= L T)
           (and (not J)
                I
                (not H)
                (not G)
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or B
           D
           V
           W
           (not A)
           (not C)
           (<= R L)
           (and (not J)
                (not I)
                H
                G
                F
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A C V W (not B) (not D) (= U 0) a!8)
       (or A
           B
           V
           W
           (not D)
           (not C)
           (<= R 0)
           (and (not J)
                (not I)
                H
                G
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or D
           V
           W
           (not B)
           (not A)
           (not C)
           (not (<= 0 T))
           (and (not J)
                (not I)
                H
                (not G)
                F
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or B
           D
           V
           W
           (not A)
           (not C)
           (not (<= R L))
           (and (not J)
                (not I)
                H
                (not G)
                F
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A
           V
           W
           (not B)
           (not D)
           (not C)
           (not (= P T))
           (and (not J)
                (not I)
                H
                (not G)
                (not F)
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A
           B
           V
           W
           (not D)
           (not C)
           (not (<= R 0))
           (and (not J)
                (not I)
                H
                (not G)
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A
           C
           V
           W
           (not B)
           (not D)
           (not (= U 0))
           (and (not J)
                (not I)
                (not H)
                G
                F
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A
           B
           D
           V
           W
           (not C)
           (<= L 1)
           (and (not J)
                (not I)
                (not H)
                G
                F
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A
           B
           D
           V
           W
           (not C)
           (not (<= L 1))
           (and (not J)
                (not I)
                (not H)
                (not G)
                F
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A B D W (not V) (not C) a!9)
       (or A D V W (not B) (not C) a!10)
       (or A B C D W (not V) a!11)
       (or B C V (not W) (not A) (not D) a!12)
       (or A B D V (not W) (not C) a!13)
       (or B W (not V) (not A) (not D) (not C) a!14)
       (or B
           D
           W
           (not V)
           (not A)
           (not C)
           (and J
                (not I)
                H
                (not G)
                F
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A
           B
           W
           (not V)
           (not D)
           (not C)
           (and J
                (not I)
                H
                (not G)
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A D W (not V) (not B) (not C) a!1)
       (or A C W (not V) (not B) (not D) a!2)
       (or A C D W (not V) (not B) a!3)
       (or V
           (not W)
           (not B)
           (not A)
           (not D)
           (not C)
           (and J
                (not I)
                (not H)
                (not G)
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or D
           V
           (not W)
           (not B)
           (not A)
           (not C)
           (and (not J) I H (not G) F E (= L K) (= N M) (= P O) (= R Q) (= T S)))
       (or B
           D
           V
           (not W)
           (not A)
           (not C)
           (and (not J)
                I
                H
                (not G)
                F
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A
           B
           V
           (not W)
           (not D)
           (not C)
           (and (not J)
                I
                H
                (not G)
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A V (not W) (not B) (not D) (not C) a!4)
       (or A D V (not W) (not B) (not C) a!5)
       (or A
           B
           C
           D
           V
           (not W)
           (and (not J)
                I
                (not H)
                G
                (not F)
                (not E)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A C V (not W) (not B) (not D) a!6)
       (or A C D V (not W) (not B) a!7)
       (or C
           V
           W
           (not B)
           (not A)
           (not D)
           (and (not J) (not I) H G F E (= L K) (= N M) (= P O) (= R Q) (= T S)))
       (or C D V W (not B) (not A) a!8)
       (or B
           C
           W
           (not V)
           (not A)
           (not D)
           (and (not J)
                (not I)
                (not H)
                (not G)
                F
                E
                (= L K)
                (= N M)
                (= P O)
                (= R Q)
                (= T S)))
       (or A B C D V W a!15)
       (or A B C V W (not D) a!15)
       (or B C D V W (not A) a!15)
       (or B C V W (not A) (not D) a!15)
       (or B V (not W) (not A) (not D) (not C) a!15)
       (or A
           C
           D
           V
           W
           (not B)
           (and (not J)
                (not I)
                (not H)
                G
                (not F)
                E
                (= M 0)
                (= L K)
                (= P O)
                (= R Q)
                (= T S)))
       (or B
           V
           W
           (not A)
           (not D)
           (not C)
           (and (not J)
                (not I)
                (not H)
                (not G)
                (not F)
                E
                (= S 0)
                (= L K)
                (= N M)
                (= P O)
                (= R Q)))
       (or B C D W (not V) (not A) (not (<= R N)) a!14)))
      )
      (state F G H E I J K M O Q S)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Bool) (K Bool) ) 
    (=>
      (and
        (state D C A B K J E F G H I)
        (or (and (not J) K (not A) B (not C) (not D))
    (and (not J) K (not A) B (not C) D)
    (and (not J) K (not A) B C (not D))
    (and (not J) K (not A) B C D)
    (and J (not K) (not A) B (not C) (not D))
    (and J (not K) (not A) B (not C) D)
    (and J (not K) (not A) B C (not D))
    (and J (not K) A (not B) C D))
      )
      false
    )
  )
)

(check-sat)
(exit)
