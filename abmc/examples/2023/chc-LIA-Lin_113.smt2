; ./prepared/tricera/sv-comp-2020/./mixed/deep-nested.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main22| ( Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main19| ( Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main16| ( Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main10| ( Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (and (<= 0 E) (<= 0 D) (<= 0 C) (<= 0 B) (<= 0 A) (<= 0 F))
      )
      (inv_main4 C B A D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv_main19 C E A B F D)
        (let ((a!1 (not (<= 2 (+ D (* (- 1) F))))))
  (and a!1
       (<= 0 A)
       (<= 0 G)
       (<= 0 F)
       (<= 0 E)
       (<= 0 D)
       (<= 0 C)
       (<= 0 B)
       (= G (+ 1 B))))
      )
      (inv_main16 C E A G F D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main10 H F E B A C)
        (and (= D 0)
     (<= 2 (+ C (* (- 1) F)))
     (<= 2 C)
     (<= 0 A)
     (<= 0 B)
     (<= 0 H)
     (<= 0 G)
     (<= 0 F)
     (<= 0 E)
     (<= 0 D)
     (<= 0 C)
     (= G 0))
      )
      (inv_main16 H F D G A C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main16 B E G D C F)
        (let ((a!1 (not (<= 2 (+ F (* (- 1) D))))))
  (and (= H (+ 1 G))
       (<= 3 (+ F (* (- 1) G)))
       a!1
       (<= 0 A)
       (<= 0 B)
       (<= 0 H)
       (<= 0 G)
       (<= 0 F)
       (<= 0 E)
       (<= 0 D)
       (<= 0 C)
       (= A 0)))
      )
      (inv_main16 B E H A C F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv_main16 F E D C B G)
        (and (<= 2 (+ G (* (- 1) C)))
     (<= 0 A)
     (<= 0 G)
     (<= 0 F)
     (<= 0 E)
     (<= 0 D)
     (<= 0 C)
     (<= 0 B)
     (= A 0))
      )
      (inv_main19 F E D C A G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv_main22 B D G F E A)
        (and (<= 0 A)
     (<= 0 G)
     (<= 0 F)
     (<= 0 E)
     (<= 0 D)
     (<= 0 C)
     (<= 0 B)
     (= C (+ 1 E)))
      )
      (inv_main19 B D G F C A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv_main19 C D G A B F)
        (let ((a!1 (or (not (= C D))
               (not (= D G))
               (not (= G A))
               (not (= A B))
               (not (= B (+ (- 2) F))))))
  (and (<= 2 (+ F (* (- 1) B)))
       (<= 0 A)
       (<= 0 G)
       (<= 0 F)
       (<= 0 E)
       (<= 0 D)
       (<= 0 C)
       (<= 0 B)
       a!1
       (= E (+ 1 B))))
      )
      (inv_main19 C D G A E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main19 E D A F B C)
        (and (= E D)
     (= D A)
     (= B (+ (- 2) C))
     (= A F)
     (<= 2 (+ C (* (- 1) B)))
     (<= 0 F)
     (<= 0 E)
     (<= 0 D)
     (<= 0 C)
     (<= 0 B)
     (<= 0 A)
     (= F B))
      )
      (inv_main22 E D A F B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv_main4 H C B F A E)
        (and (= G 0)
     (= D 0)
     (<= 0 A)
     (<= 0 B)
     (<= 0 C)
     (<= 0 I)
     (<= 0 H)
     (<= 0 G)
     (<= 0 F)
     (<= 0 E)
     (<= 0 D)
     (= I 4294967295))
      )
      (inv_main10 G D B F A I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main10 B E F A C G)
        (let ((a!1 (not (<= 2 (+ G (* (- 1) E))))))
  (and (= D (+ 1 B))
       (<= 3 (+ G (* (- 1) B)))
       a!1
       (<= 0 A)
       (<= 0 B)
       (<= 0 H)
       (<= 0 G)
       (<= 0 F)
       (<= 0 E)
       (<= 0 D)
       (<= 0 C)
       (= H 0)))
      )
      (inv_main10 D H F A C G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main10 H F B G C D)
        (and (= E (+ 1 F))
     (<= 2 (+ D (* (- 1) F)))
     (not (<= 2 D))
     (<= 0 A)
     (<= 0 B)
     (<= 0 H)
     (<= 0 G)
     (<= 0 F)
     (<= 0 E)
     (<= 0 D)
     (<= 0 C)
     (= A 0))
      )
      (inv_main10 H E A G C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv_main16 F E G A C D)
        (let ((a!1 (not (<= 3 (+ D (* (- 1) G))))) (a!2 (not (<= 2 (+ D (* (- 1) A))))))
  (and (= H (+ 1 G))
       a!1
       a!2
       (<= 0 A)
       (<= 0 B)
       (<= 0 H)
       (<= 0 G)
       (<= 0 F)
       (<= 0 E)
       (<= 0 D)
       (<= 0 C)
       (= B (+ 1 E))))
      )
      (inv_main10 F B H A C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main22 E F C A D B)
        (and (<= 0 E) (<= 0 D) (<= 0 C) (<= 0 B) (<= 0 A) (<= 0 F))
      )
      false
    )
  )
)

(check-sat)
(exit)