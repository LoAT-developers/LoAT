; ./prepared/vmt/./ctigar/nested7.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (and (= D true) (not C) (not B) (not A) (not L) (not E))
      )
      (state E D C A B L F G H I J K)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) ) 
    (=>
      (and
        (state E D C A B Y M O Q S U W)
        (let ((a!1 (<= (+ O (* (- 1) Q) (* (- 1) W)) 0))
      (a!2 (and K
                (not J)
                (not I)
                H
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
      (a!3 (and (not K)
                J
                I
                H
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
      (a!4 (<= 0 (+ O (* (- 1) Q) (* (- 1) W))))
      (a!5 (and (not K)
                (not J)
                I
                H
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
      (a!6 (and (not K)
                J
                I
                H
                G
                F
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!7 (and (not K)
                J
                (not I)
                (not H)
                (not G)
                (not F)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ M (* (- 1) L)) (- 1))))
      (a!8 (and (not K)
                J
                I
                (not H)
                G
                F
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!9 (and (not K)
                (not J)
                I
                H
                (not G)
                (not F)
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!10 (and K
                 (not J)
                 (not I)
                 H
                 (not G)
                 (not F)
                 (= M L)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)
                 (= (+ O (* (- 1) N)) 1)))
      (a!11 (and K
                 (not J)
                 (not I)
                 H
                 (not G)
                 F
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= (+ S (* (- 1) R)) (- 1))))
      (a!12 (and (not K)
                 J
                 I
                 H
                 (not G)
                 F
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= (+ S (* (- 1) R)) (- 1))))
      (a!13 (and (not K)
                 J
                 (not I)
                 H
                 (not G)
                 F
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= (+ S (* (- 1) R)) (- 1))))
      (a!14 (and (not K)
                 (not J)
                 I
                 H
                 (not G)
                 F
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= U T)
                 (= W V)
                 (= (+ S (* (- 1) R)) (- 1))))
      (a!15 (and K
                 (not J)
                 I
                 (not H)
                 G
                 F
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V)))
      (a!16 (and (not K)
                 (not J)
                 (not I)
                 (not H)
                 (not G)
                 (not F)
                 (= M L)
                 (= O N)
                 (= Q P)
                 (= S R)
                 (= U T)
                 (= W V))))
  (and (or B
           C
           D
           E
           (not Y)
           (not A)
           (not a!1)
           (and K
                (not J)
                I
                (not H)
                (not G)
                F
                (= M L)
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
           (not (<= W M))
           (and K
                (not J)
                I
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A B C D E (not Y) (not (<= Q W)) a!2)
       (or A
           B
           C
           D
           (not Y)
           (not E)
           (not (<= W S))
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
                (= U T)
                (= W V)))
       (or A
           B
           C
           D
           (not Y)
           (not E)
           (<= W S)
           (and K
                (not J)
                (not I)
                (not H)
                G
                F
                (= M L)
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
           (not Y)
           (<= Q W)
           (and K
                (not J)
                (not I)
                (not H)
                (not G)
                F
                (= M L)
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
           (not (<= Q 5))
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
                (= U T)
                (= W V)))
       (or A Y (not B) (not C) (not E) (not D) (not (<= U S)) a!3)
       (or C
           E
           Y
           (not B)
           (not A)
           (not D)
           (not a!4)
           (and (not K)
                J
                I
                H
                (not G)
                (not F)
                (= M L)
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
           a!4
           (and (not K)
                J
                I
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           Y
           (not B)
           (not C)
           (not E)
           (not D)
           (<= U S)
           (and (not K)
                J
                I
                (not H)
                (not G)
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           C
           Y
           (not B)
           (not E)
           (not D)
           (not (<= U S))
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
                (= U T)
                (= W V)))
       (or A
           C
           Y
           (not B)
           (not E)
           (not D)
           (<= U S)
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
                (= U T)
                (= W V)))
       (or A
           C
           E
           Y
           (not B)
           (not D)
           (<= Q 5)
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
                (= U T)
                (= W V)))
       (or A
           B
           D
           Y
           (not C)
           (not E)
           (not (<= U M))
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
                (= U T)
                (= W V)))
       (or B C D E Y (not A) (= X 0) a!5)
       (or B
           C
           D
           Y
           (not A)
           (not E)
           (not (<= W S))
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
                (= U T)
                (= W V)))
       (or B
           C
           D
           Y
           (not A)
           (not E)
           (<= W S)
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
                (= U T)
                (= W V)))
       (or B
           C
           D
           E
           Y
           (not A)
           (not (= X 0))
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
                (= U T)
                (= W V)))
       (or A
           B
           D
           Y
           (not C)
           (not E)
           (<= U M)
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
                (= U T)
                (= W V)))
       (or A
           B
           D
           E
           Y
           (not C)
           (<= W M)
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
                (= U T)
                (= W V)))
       (or A
           B
           C
           E
           Y
           (not D)
           (not a!1)
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
                (= U T)
                (= W V)))
       (or A
           B
           C
           E
           Y
           (not D)
           a!1
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
                (= U T)
                (= W V)))
       (or D Y (not B) (not A) (not C) (not E) a!6)
       (or B Y (not A) (not C) (not E) (not D) a!7)
       (or C D Y (not B) (not A) (not E) a!8)
       (or B C Y (not A) (not E) (not D) a!9)
       (or A B C (not Y) (not E) (not D) a!10)
       (or A B D E (not Y) (not C) a!11)
       (or D E Y (not B) (not A) (not C) a!12)
       (or A D E Y (not B) (not C) a!13)
       (or B D E Y (not A) (not C) a!14)
       (or B C (not Y) (not A) (not E) (not D) a!15)
       (or B
           C
           E
           (not Y)
           (not A)
           (not D)
           (and K
                (not J)
                I
                (not H)
                G
                (not F)
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A B D (not Y) (not C) (not E) a!2)
       (or A
           B
           E
           (not Y)
           (not C)
           (not D)
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
                (= U T)
                (= W V)))
       (or A B (not Y) (not C) (not E) (not D) a!3)
       (or C
           Y
           (not B)
           (not A)
           (not E)
           (not D)
           (and (not K)
                J
                I
                (not H)
                (not G)
                F
                (= M L)
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
           (and (not K)
                J
                (not I)
                H
                G
                F
                (= M L)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           E
           Y
           (not B)
           (not C)
           (not D)
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
                (= U T)
                (= W V)))
       (or B D Y (not A) (not C) (not E) a!5)
       (or B
           E
           Y
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
                (= S R)
                (= U T)
                (= W V)))
       (or A
           C
           D
           E
           Y
           (not B)
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
                (= U T)
                (= W V)))
       (or Y
           (not B)
           (not A)
           (not C)
           (not E)
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
                (= U T)
                (= W V)))
       (or A B C D E Y a!16)
       (or A B C D Y (not E) a!16)
       (or B C D (not Y) (not A) (not E) a!16)
       (or A
           B
           E
           Y
           (not C)
           (not D)
           (and (not K)
                (not J)
                (not I)
                H
                G
                (not F)
                (= L 0)
                (= O N)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           B
           C
           Y
           (not E)
           (not D)
           (and (not K)
                (not J)
                (not I)
                H
                (not G)
                (not F)
                (= L 0)
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
           (and (not K)
                J
                I
                (not H)
                (not G)
                F
                (= N 0)
                (= M L)
                (= Q P)
                (= S R)
                (= U T)
                (= W V)))
       (or A
           B
           Y
           (not C)
           (not E)
           (not D)
           (and (not K)
                (not J)
                I
                (not H)
                (not G)
                (not F)
                (= N Q)
                (= M L)
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
           (and K
                (not J)
                (not I)
                (not H)
                G
                (not F)
                (= R 0)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)))
       (or A
           D
           Y
           (not B)
           (not C)
           (not E)
           (and (not K)
                J
                (not I)
                H
                G
                F
                (= R 0)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)))
       (or A
           C
           D
           Y
           (not B)
           (not E)
           (and (not K)
                J
                (not I)
                (not H)
                G
                F
                (= R 0)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)))
       (or B
           C
           E
           Y
           (not A)
           (not D)
           (and (not K)
                (not J)
                I
                (not H)
                G
                (not F)
                (= R 0)
                (= M L)
                (= O N)
                (= Q P)
                (= U T)
                (= W V)))
       (or B C D E (not Y) (not A) a!1 a!15)))
      )
      (state G F H I J K L N P R T V)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) ) 
    (=>
      (and
        (state E D C A B L F G H I J K)
        (and (= D true) (not C) (not B) (= A true) (= L true) (= E true))
      )
      false
    )
  )
)

(check-sat)
(exit)
