; ./prepared/vmt/./ctigar/NetBSD_g_Ctoc.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (and (= D true) (not C) (not B) (not A) (not J) (not E))
      )
      (state E D C A B J F G H I)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Bool) ) 
    (=>
      (and
        (state E D C A B U M O Q S)
        (let ((a!1 (and K
                (not J)
                (not I)
                (not H)
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
      (a!2 (and K
                (not J)
                (not I)
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
      (a!3 (and (not K) J I H G F (= M L) (= O N) (= Q P) (= S R)))
      (a!4 (and (not K) J I H G (not F) (= M L) (= O N) (= Q P) (= S R)))
      (a!5 (and (not K)
                J
                I
                (not H)
                G
                F
                (= O N)
                (= Q P)
                (= S R)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!6 (and (not K)
                J
                (not I)
                H
                G
                F
                (= O N)
                (= Q P)
                (= S R)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!7 (and (not K)
                J
                I
                H
                (not G)
                (not F)
                (= M L)
                (= Q P)
                (= S R)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!8 (and (not K)
                J
                I
                (not H)
                (not G)
                (not F)
                (= M L)
                (= Q P)
                (= S R)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!9 (and (not K)
                J
                I
                H
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= (+ S (* (- 1) R)) 1)))
      (a!10 (and K (not J) (not I) (not H) G F (= M L) (= O N) (= Q P) (= S R)))
      (a!11 (and (not K)
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (not F)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R))))
  (and (or B E U (not A) (not C) (not D) (<= 0 O) a!1)
       (or B U (not A) (not C) (not E) (not D) (not (<= Q O)) a!2)
       (or A C E U (not B) (not D) (<= 0 M) a!3)
       (or A C U (not B) (not E) (not D) (not (<= Q M)) a!4)
       (or A
           E
           U
           (not B)
           (not C)
           (not D)
           (= T 0)
           (and (not K) J I (not H) (not G) F (= M L) (= O N) (= Q P) (= S R)))
       (or A
           E
           U
           (not B)
           (not C)
           (not D)
           (not (= T 0))
           (and (not K) J (not I) H G (not F) (= M L) (= O N) (= Q P) (= S R)))
       (or A
           C
           U
           (not B)
           (not E)
           (not D)
           (<= Q M)
           (and (not K)
                J
                (not I)
                H
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           C
           E
           U
           (not B)
           (not D)
           (not (<= 0 M))
           (and (not K)
                J
                (not I)
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           U
           (not A)
           (not C)
           (not E)
           (not D)
           (<= Q O)
           (and (not K)
                J
                (not I)
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           E
           U
           (not A)
           (not C)
           (not D)
           (not (<= 0 O))
           (and (not K) (not J) I H G (not F) (= M L) (= O N) (= Q P) (= S R)))
       (or B
           C
           U
           (not A)
           (not E)
           (not D)
           (= S 0)
           (and (not K) (not J) I H (not G) F (= M L) (= O N) (= Q P) (= S R)))
       (or B
           C
           U
           (not A)
           (not E)
           (not D)
           (not (= S 0))
           (and (not K)
                (not J)
                I
                H
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           D
           U
           (not C)
           (not E)
           (= S 0)
           (and (not K)
                (not J)
                I
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           D
           U
           (not C)
           (not E)
           (not (= S 0))
           (and (not K) (not J) (not I) H G F (= M L) (= O N) (= Q P) (= S R)))
       (or A
           B
           D
           E
           U
           (not C)
           (not (<= 1 Q))
           (and (not K)
                (not J)
                (not I)
                H
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           C
           D
           U
           (not E)
           (<= Q 0)
           (and (not K)
                (not J)
                (not I)
                H
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           C
           D
           U
           (not E)
           (not (<= Q 0))
           (and (not K)
                (not J)
                (not I)
                (not H)
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or C D U (not B) (not A) (not E) a!5)
       (or A D U (not B) (not C) (not E) a!6)
       (or C U (not B) (not A) (not E) (not D) a!7)
       (or A U (not B) (not C) (not E) (not D) a!8)
       (or D E U (not B) (not A) (not C) a!9)
       (or A B C (not U) (not E) (not D) a!10)
       (or A B C E (not U) (not D) a!1)
       (or A B C D E (not U) a!2)
       (or U (not B) (not A) (not C) (not E) (not D) a!3)
       (or D U (not B) (not A) (not C) (not E) a!4)
       (or C
           E
           U
           (not B)
           (not A)
           (not D)
           (and (not K) J I (not H) G (not F) (= M L) (= O N) (= Q P) (= S R)))
       (or A
           D
           E
           U
           (not B)
           (not C)
           (and (not K) J (not I) H (not G) F (= M L) (= O N) (= Q P) (= S R)))
       (or A
           C
           D
           U
           (not B)
           (not E)
           (and (not K) J (not I) (not H) G F (= M L) (= O N) (= Q P) (= S R)))
       (or A
           C
           D
           E
           U
           (not B)
           (and (not K)
                J
                (not I)
                (not H)
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           D
           U
           (not A)
           (not C)
           (not E)
           (and (not K) (not J) I H G F (= M L) (= O N) (= Q P) (= S R)))
       (or B
           C
           D
           U
           (not A)
           (not E)
           (and (not K) (not J) I (not H) G F (= M L) (= O N) (= Q P) (= S R)))
       (or E
           U
           (not B)
           (not A)
           (not C)
           (not D)
           (and (not K)
                (not J)
                I
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A
           B
           E
           U
           (not C)
           (not D)
           (and (not K)
                (not J)
                (not I)
                H
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)))
       (or A B C D E U a!11)
       (or A B C D (not U) (not E) a!11)
       (or A B C U (not E) (not D) a!11)
       (or A B U (not C) (not E) (not D) a!11)
       (or B D E U (not A) (not C) a!11)
       (or C D E U (not B) (not A) a!11)
       (or A
           B
           C
           E
           U
           (not D)
           (and (not K)
                (not J)
                (not I)
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q R)
                (= Q P)))
       (or B
           C
           D
           E
           U
           (not A)
           (and (not K)
                (not J)
                I
                (not H)
                (not G)
                F
                (= L 0)
                (= O N)
                (= Q P)
                (= S R)))
       (or B
           C
           E
           U
           (not A)
           (not D)
           (and (not K)
                (not J)
                I
                (not H)
                G
                (not F)
                (= N 0)
                (= M L)
                (= Q P)
                (= S R)))
       (or A B D E U (not C) (<= 1 Q) a!10)))
      )
      (state G F H I J K L N P R)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Bool) ) 
    (=>
      (and
        (state E D C A B J F G H I)
        (or (and (not J) A B C (not D) E)
    (and (not J) A B C D E)
    (and J (not A) (not B) (not C) (not D) (not E))
    (and J (not A) (not B) (not C) D (not E))
    (and J (not A) (not B) (not C) D E))
      )
      false
    )
  )
)

(check-sat)
(exit)
