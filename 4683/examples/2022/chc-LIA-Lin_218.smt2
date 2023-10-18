; ./vmt/./ctigar/nested6.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Bool) ) 
    (=>
      (and
        (and (= B true) (not A) (not I) (not H) (not C))
      )
      (state C B A I H G F E D)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Bool) (S Bool) ) 
    (=>
      (and
        (state C B A S R P N L J)
        (let ((a!1 (and H (not G) F E D (= J I) (= L K) (= N M) (= P O)))
      (a!2 (and H (not G) F E (not D) (= J I) (= L K) (= N M) (= P O)))
      (a!3 (and (not H) G F E D (= J I) (= L K) (= N M) (= P O)))
      (a!4 (and (not H) G F E (not D) (= J I) (= L K) (= N M) (= P O)))
      (a!6 (not (<= 0 (+ N (* (- 2) J)))))
      (a!7 (and H
                G
                (not F)
                (not E)
                D
                (= L K)
                (= N M)
                (= P O)
                (= (+ J (* (- 1) I)) (- 1))))
      (a!8 (and H
                (not G)
                (not F)
                (not E)
                (not D)
                (= J I)
                (= N M)
                (= P O)
                (= (+ L (* (- 1) K)) (- 1))))
      (a!9 (and (not H)
                (not G)
                F
                E
                (not D)
                (= J I)
                (= N M)
                (= P O)
                (= (+ K (* (- 2) J)) 0)))
      (a!10 (and (not H)
                 G
                 F
                 (not E)
                 D
                 (= J I)
                 (= L K)
                 (= P O)
                 (= (+ N (* (- 1) M)) (- 1))))
      (a!11 (and (not H)
                 (not G)
                 (not F)
                 (not E)
                 (not D)
                 (= J I)
                 (= L K)
                 (= N M)
                 (= P O))))
(let ((a!5 (or A B R (not S) (not C) (<= 0 (+ N (* (- 2) J))) a!4)))
  (and (or B
           R
           S
           (not A)
           (not C)
           (not (<= P L))
           (and H G (not F) (not E) (not D) (= J I) (= L K) (= N M) (= P O)))
       (or A C S (not R) (not B) (<= P N) a!1)
       (or A S (not R) (not C) (not B) (<= N P) a!2)
       (or A
           S
           (not R)
           (not C)
           (not B)
           (not (<= N P))
           (and H (not G) F (not E) (not D) (= J I) (= L K) (= N M) (= P O)))
       (or A
           C
           S
           (not R)
           (not B)
           (not (<= P N))
           (and H (not G) (not F) E (not D) (= J I) (= L K) (= N M) (= P O)))
       (or R
           S
           (not A)
           (not C)
           (not B)
           (= Q 0)
           (and H (not G) (not F) (not E) D (= J I) (= L K) (= N M) (= P O)))
       (or A C R (not S) (not B) (not (<= P N)) a!3)
       a!5
       (or A
           B
           R
           (not S)
           (not C)
           a!6
           (and (not H) G (not F) E D (= J I) (= L K) (= N M) (= P O)))
       (or A
           C
           R
           (not S)
           (not B)
           (<= P N)
           (and (not H) G (not F) E (not D) (= J I) (= L K) (= N M) (= P O)))
       (or R
           S
           (not A)
           (not C)
           (not B)
           (not (= Q 0))
           (and (not H)
                G
                (not F)
                (not E)
                (not D)
                (= J I)
                (= L K)
                (= N M)
                (= P O)))
       (or B
           R
           S
           (not A)
           (not C)
           (<= P L)
           (and (not H) (not G) F E D (= J I) (= L K) (= N M) (= P O)))
       (or B
           C
           R
           S
           (not A)
           (<= P J)
           (and (not H) (not G) F (not E) D (= J I) (= L K) (= N M) (= P O)))
       (or A
           C
           R
           S
           (not B)
           (not (= P N))
           (and (not H) (not G) (not F) E D (= J I) (= L K) (= N M) (= P O)))
       (or A
           C
           R
           S
           (not B)
           (= P N)
           (and (not H)
                (not G)
                (not F)
                E
                (not D)
                (= J I)
                (= L K)
                (= N M)
                (= P O)))
       (or A B C (not R) (not S) a!7)
       (or R (not S) (not A) (not C) (not B) a!8)
       (or C R S (not A) (not B) a!9)
       (or B C R (not S) (not A) a!10)
       (or S (not R) (not A) (not C) (not B) a!1)
       (or B S (not R) (not A) (not C) a!2)
       (or B
           C
           S
           (not R)
           (not A)
           (and H (not G) F (not E) D (= J I) (= L K) (= N M) (= P O)))
       (or A
           B
           S
           (not R)
           (not C)
           (and H (not G) (not F) E D (= J I) (= L K) (= N M) (= P O)))
       (or C S (not R) (not A) (not B) a!3)
       (or B R (not S) (not A) (not C) a!4)
       (or A
           R
           (not S)
           (not C)
           (not B)
           (and (not H) G F (not E) (not D) (= J I) (= L K) (= N M) (= P O)))
       (or C
           R
           (not S)
           (not A)
           (not B)
           (and (not H) G (not F) (not E) D (= J I) (= L K) (= N M) (= P O)))
       (or A
           B
           C
           S
           (not R)
           (and (not H) (not G) F E (not D) (= J I) (= L K) (= N M) (= P O)))
       (or A
           C
           (not R)
           (not S)
           (not B)
           (and (not H)
                (not G)
                F
                (not E)
                (not D)
                (= J I)
                (= L K)
                (= N M)
                (= P O)))
       (or A B C R S a!11)
       (or A B R S (not C) a!11)
       (or A B (not R) (not S) (not C) a!11)
       (or A
           R
           S
           (not C)
           (not B)
           (and (not H)
                (not G)
                F
                (not E)
                (not D)
                (= I 0)
                (= L K)
                (= N M)
                (= P O)))
       (or A
           B
           C
           R
           (not S)
           (and (not H) G (not F) (not E) D (= M L) (= J I) (= L K) (= P O)))
       (or B
           C
           R
           S
           (not A)
           (not (<= P J))
           (and H G (not F) E (not D) (= J I) (= L K) (= N M) (= P O))))))
      )
      (state E D F G H O M K I)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Bool) (I Bool) ) 
    (=>
      (and
        (state C B A I H G F E D)
        (or (and (not H) I A (not B) C)
    (and H (not I) A (not B) C)
    (and H (not I) A B C))
      )
      false
    )
  )
)

(check-sat)
(exit)
