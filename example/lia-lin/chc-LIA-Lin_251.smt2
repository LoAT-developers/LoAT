; ./vmt/./ctigar/svd2.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) ) 
    (=>
      (and
        (and (= D true) (not C) (not B) (not A) (not K) (not E))
      )
      (state E D C A B K J I H G F)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) ) 
    (=>
      (and
        (state E D C A B W U S Q O M)
        (let ((a!1 (and K
                (not J)
                (not I)
                (not H)
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
      (a!2 (and (not K) J I H G (not F) (= M L) (= O N) (= Q P) (= S R) (= U T)))
      (a!3 (and (not K)
                J
                I
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
      (a!4 (and (not K)
                J
                I
                (not H)
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
      (a!5 (and K
                (not J)
                (not I)
                H
                (not G)
                F
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ M (* (- 1) L)) 1)))
      (a!6 (and K
                (not J)
                (not I)
                (not H)
                (not G)
                F
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!7 (and (not K)
                J
                I
                H
                (not G)
                (not F)
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!8 (and (not K)
                (not J)
                I
                (not H)
                G
                (not F)
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!9 (and (not K)
                J
                I
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= S R)
                (= U T)
                (= (+ Q (* (- 1) P)) (- 1))))
      (a!10 (and (not K)
                 J
                 (not I)
                 (not H)
                 (not G)
                 (not F)
                 (= M L)
                 (= O N)
                 (= S R)
                 (= U T)
                 (= (+ Q (* (- 1) P)) (- 1))))
      (a!11 (and (not K)
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (not F)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T))))
  (and (or A B E W (not C) (not D) (not (<= U M)) a!1)
       (or W
           (not B)
           (not A)
           (not C)
           (not E)
           (not D)
           (<= O U)
           (and K
                (not J)
                (not I)
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or W
           (not B)
           (not A)
           (not C)
           (not E)
           (not D)
           (not (<= O U))
           (and K
                (not J)
                (not I)
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A B D W (not C) (not E) (= V 0) a!2)
       (or B
           D
           E
           W
           (not A)
           (not C)
           (<= O U)
           (and (not K) J I H (not G) F (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or A
           C
           D
           W
           (not B)
           (not E)
           (<= Q U)
           (and (not K) J I (not H) G F (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or A C W (not B) (not E) (not D) (<= 1 M) a!3)
       (or A E W (not B) (not C) (not D) (<= M U) a!4)
       (or A
           E
           W
           (not B)
           (not C)
           (not D)
           (not (<= M U))
           (and (not K)
                J
                (not I)
                H
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           C
           W
           (not B)
           (not E)
           (not D)
           (not (<= 1 M))
           (and (not K)
                J
                (not I)
                H
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           C
           D
           W
           (not B)
           (not E)
           (not (<= Q U))
           (and (not K)
                J
                (not I)
                (not H)
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           D
           W
           (not A)
           (not C)
           (not E)
           (<= Q U)
           (and (not K)
                J
                (not I)
                (not H)
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           D
           W
           (not A)
           (not C)
           (not E)
           (not (<= Q U))
           (and (not K) (not J) I H G F (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or B
           D
           E
           W
           (not A)
           (not C)
           (not (<= O U))
           (and (not K)
                (not J)
                I
                H
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           C
           D
           E
           W
           (not A)
           (<= O U)
           (and (not K)
                (not J)
                I
                (not H)
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           C
           D
           E
           W
           (not A)
           (not (<= O U))
           (and (not K)
                (not J)
                I
                (not H)
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           D
           W
           (not C)
           (not E)
           (not (= V 0))
           (and (not K)
                (not J)
                (not I)
                H
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           E
           W
           (not C)
           (not D)
           (<= U M)
           (and (not K)
                (not J)
                (not I)
                H
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           D
           E
           W
           (not C)
           (not (<= 1 M))
           (and (not K)
                (not J)
                (not I)
                H
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           C
           E
           W
           (not D)
           (<= S 0)
           (and (not K)
                (not J)
                (not I)
                (not H)
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           C
           E
           W
           (not D)
           (not (<= S 0))
           (and (not K)
                (not J)
                (not I)
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A B D E (not W) (not C) a!5)
       (or A
           B
           C
           W
           (not E)
           (not D)
           (and (not K)
                (not J)
                (not I)
                H
                (not G)
                (not F)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= U L)))
       (or A B C D E (not W) a!6)
       (or C W (not B) (not A) (not E) (not D) a!7)
       (or B C E W (not A) (not D) a!8)
       (or D
           W
           (not B)
           (not A)
           (not C)
           (not E)
           (and (not K) J I H G F (= M L) (= Q P) (= S R) (= S N) (= U T)))
       (or B
           C
           W
           (not A)
           (not E)
           (not D)
           (and (not K)
                (not J)
                I
                H
                (not G)
                (not F)
                (= M L)
                (= Q P)
                (= S R)
                (= S N)
                (= U T)))
       (or A
           B
           W
           (not C)
           (not E)
           (not D)
           (and (not K)
                (not J)
                I
                (not H)
                (not G)
                (not F)
                (= M L)
                (= Q P)
                (= S R)
                (= S N)
                (= U T)))
       (or A W (not B) (not C) (not E) (not D) a!9)
       (or B W (not A) (not C) (not E) (not D) a!10)
       (or A
           C
           E
           W
           (not B)
           (not D)
           (and (not K)
                J
                (not I)
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= S R)
                (= S P)
                (= U T)))
       (or B
           E
           W
           (not A)
           (not C)
           (not D)
           (and (not K)
                (not J)
                I
                H
                G
                (not F)
                (= M L)
                (= O N)
                (= S R)
                (= S P)
                (= U T)))
       (or A B C D (not W) (not E) a!1)
       (or A
           B
           C
           E
           (not W)
           (not D)
           (and (not K) J I H G F (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or E W (not B) (not A) (not C) (not D) a!2)
       (or C D W (not B) (not A) (not E) a!3)
       (or C E W (not B) (not A) (not D) a!4)
       (or A
           D
           W
           (not B)
           (not C)
           (not E)
           (and (not K) J (not I) H G F (= M L) (= O N) (= Q P) (= S R) (= U T)))
       (or A
           D
           E
           W
           (not B)
           (not C)
           (and (not K)
                J
                (not I)
                H
                (not G)
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or C
           D
           E
           W
           (not B)
           (not A)
           (and (not K)
                J
                (not I)
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           C
           D
           E
           W
           (not B)
           (and (not K)
                (not J)
                I
                H
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or D
           E
           W
           (not B)
           (not A)
           (not C)
           (and (not K)
                (not J)
                I
                H
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or B
           C
           D
           W
           (not A)
           (not E)
           (and (not K)
                (not J)
                I
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A
           B
           E
           (not W)
           (not C)
           (not D)
           (and (not K)
                (not J)
                (not I)
                H
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))
       (or A B C D E W a!11)
       (or A B C D W (not E) a!11)
       (or A B D (not W) (not C) (not E) a!11)
       (or A
           B
           C
           (not W)
           (not E)
           (not D)
           (and K
                (not J)
                (not I)
                H
                (not G)
                (not F)
                (= R M)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)))
       (or A
           B
           D
           E
           W
           (not C)
           (<= 1 M)
           (and K
                (not J)
                (not I)
                H
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)))))
      )
      (state G F H I J K T R P N L)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) ) 
    (=>
      (and
        (state E D C A B K J I H G F)
        (or (and (not K) A B (not C) (not D) E) (and (not K) A B (not C) D (not E)))
      )
      false
    )
  )
)

(check-sat)
(exit)
