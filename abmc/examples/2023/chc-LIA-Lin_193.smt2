; ./prepared/vmt/./ctigar/dillig05.c_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) ) 
    (=>
      (and
        (and (not B) (= A true) (not I) (not C))
      )
      (state C A B I D E F G H)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Bool) ) 
    (=>
      (and
        (state C A B S I K M O Q)
        (let ((a!1 (or B
               (not S)
               (not C)
               (not A)
               (<= 1 (+ I (* (- 1) K)))
               (and G F (not E) (not D) (= I H) (= K J) (= M L) (= O N) (= Q P))))
      (a!2 (and G (not F) (not E) D (= I H) (= K J) (= M L) (= O N) (= Q P)))
      (a!3 (and (not G)
                F
                (not E)
                D
                (= K J)
                (= M L)
                (= O N)
                (= Q P)
                (= (+ I (* (- 1) H) O) 0)))
      (a!4 (and (not G)
                F
                E
                D
                (= I H)
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J) Q) 0)))
      (a!5 (and G
                (not F)
                E
                (not D)
                (= I H)
                (= M L)
                (= O N)
                (= Q P)
                (= (+ K (* (- 1) J)) (- 1))))
      (a!6 (and (not G)
                F
                (not E)
                (not D)
                (= I H)
                (= K J)
                (= M L)
                (= Q P)
                (= (+ O (* (- 1) N)) (- 1))))
      (a!7 (and (not G)
                F
                E
                (not D)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= (+ Q (* (- 1) P)) (- 1))))
      (a!8 (and G F (not E) D (= I H) (= K J) (= M L) (= O N) (= Q P)))
      (a!9 (and (not G)
                (not F)
                (not E)
                (not D)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
      (a!10 (not (<= 1 (+ I (* (- 1) K))))))
  (and a!1
       (or A
           B
           S
           (not C)
           (= R 0)
           (and G (not F) E D (= I H) (= K J) (= M L) (= O N) (= Q P)))
       (or S (not B) (not C) (not A) (not (= M 0)) a!2)
       (or S
           (not B)
           (not C)
           (not A)
           (= M 0)
           (and G
                (not F)
                (not E)
                (not D)
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A
           B
           S
           (not C)
           (not (= R 0))
           (and (not G) (not F) E D (= I H) (= K J) (= M L) (= O N) (= Q P)))
       (or C S (not B) (not A) a!3)
       (or A S (not B) (not C) a!4)
       (or A B C (not S) a!5)
       (or B S (not C) (not A) a!6)
       (or A C S (not B) a!7)
       (or A
           C
           (not S)
           (not B)
           (and G F E (not D) (= I H) (= K J) (= M L) (= O N) (= Q P)))
       (or A (not S) (not B) (not C) a!8)
       (or B C (not S) (not A) a!2)
       (or A
           B
           (not S)
           (not C)
           (and (not G)
                (not F)
                (not E)
                D
                (= I H)
                (= K J)
                (= M L)
                (= O N)
                (= Q P)))
       (or A B C S a!9)
       (or C (not S) (not B) (not A) a!9)
       (or B
           C
           S
           (not A)
           (and (not G)
                (not F)
                (not E)
                D
                (= P 0)
                (= N 0)
                (= J 0)
                (= H 0)
                (= M L)))
       (or B (not S) (not C) (not A) a!10 a!8)))
      )
      (state D E F G H J L N P)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) ) 
    (=>
      (and
        (state C A B I D E F G H)
        (and (= B true) (not A) (= I true) (= C true))
      )
      false
    )
  )
)

(check-sat)
(exit)
