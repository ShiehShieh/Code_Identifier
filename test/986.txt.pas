Const
   Maxn=100000;
   Maxm=100000;
   Null=0;
Type
   Interval=Record
      Left,Right,Kth,Ith:Longint;
   End;
Var
   A:Array[1..Maxn]Of Longint;
   L,R,Size,Key,Priority,Count,F:Array[0..Maxm]Of Longint;
   B:Array[0..Maxm]Of Interval;
   I,J,Tmp,N,M,Free,P,T:Longint;
Function Min(A,B:Longint):Longint;
   Begin
      If A>B Then Exit(B) Else Exit(A);
   End;
Function Max(A,B:Longint):Longint;
   Begin
      If A>B Then Exit(A) Else Exit(B);
   End;
Procedure Initialize;
   Begin
      Size[Null]:=0;Count[Null]:=0;
      L[Null]:=Null;R[Null]:=Null;
      Priority[Null]:=65535;
      P:=1;Free:=Null;T:=Null;
   End;
Procedure Allocate(Var H:Longint);
   Begin
      If P<=N Then Begin
         H:=P;Inc(P);Exit;
      End;
      H:=Free;Free:=L[Free];
   End;
Procedure Clean(Var H:Longint);
   Begin
      L[H]:=Free;
      Free:=H;
      H:=Null;
   End;
Procedure Leftrotate(Var T:Longint);
   Var Tmp:Longint;
   Begin
      Tmp:=L[T];
      L[T]:=R[Tmp];
      R[Tmp]:=T;
      Size[Tmp]:=Size[T];
      Size[T]:=Size[L[T]]+Size[R[T]]+Count[T];
      T:=Tmp;
   End;
Procedure Rightrotate(Var T:Longint);
   Var Tmp:Longint;
   Begin
      Tmp:=R[T];
      R[T]:=L[Tmp];
      L[Tmp]:=T;
      Size[Tmp]:=Size[T];
      Size[T]:=Size[L[T]]+Size[R[T]]+Count[T];
      T:=Tmp;
   End;
Procedure Insert(Var T:Longint;Const K:Longint);
   Begin
      If T=Null Then
      Begin
         Allocate(T);
         L[T]:=Null;R[T]:=Null;
         Key[T]:=K;Priority[T]:=Random(65535);
         Size[T]:=1;Count[T]:=1;
      End
      Else Begin
         Inc(Size[T]);
         If K<Key[T] Then
         Begin
            Insert(L[T],K);
            If Priority[L[T]]<Priority[T] Then
               Leftrotate(T);
         End
         Else If K>Key[T] Then
         Begin
            Insert(R[T],K);
            If Priority[R[T]]<Priority[T] Then
               Rightrotate(T);
         End 
         Else Inc(Count[T]);
      End;
   End;
Procedure Remove(Var T:Longint;Const K:Longint);
   Begin
      If T=Null Then Exit;
      If K<Key[T] Then
         Remove(L[T],K)
      Else If K>Key[T] Then
         Remove(R[T],K)
      Else If Count[T]>1 Then
         Dec(Count[T])
      Else If L[T]=R[T] Then
         Clean(T)
      Else Begin
         If Priority[L[T]]<Priority[R[T]] 
            Then Leftrotate(T)
            Else Rightrotate(T);
         Remove(T,K);
      End;
      Size[T]:=Size[L[T]]+Size[R[T]]+Count[T];
   End;
Function Select(T,K:Longint):Longint;
   Begin
      While T<>Null Do
         If Size[L[T]]>=K Then T:=L[T]
         Else Begin
            Dec(K,Size[L[T]]);
            If K<=Count[T] Then Break;
            Dec(K,Count[T]);
            T:=R[T];
         End;
      Exit(T);
   End;
Function Compare(A,B:Interval):Boolean;
   Begin
      If (A.Left>B.Left) Or
         (A.Left=B.Left)And(A.Right>B.Right)
         Then Exit(True)
         Else Exit(False);
   End;
Procedure Intervalsort(L,R:Longint);
   Var
      Tmp,Mid:Interval;
      I,J:Longint;
   Begin
      I:=L;J:=R;
      Mid:=B[(I+J)>>1];
      Repeat
         While Compare(Mid,B[I]) Do Inc(I);
         While Compare(B[J],Mid) Do Dec(J);
         If Not(I>J) Then Begin
            Tmp:=B[I];B[I]:=B[J];B[J]:=Tmp;
            Inc(I);Dec(J);
         End;
      Until I>J;
      If I<R Then Intervalsort(I,R);
      If L<J Then Intervalsort(L,J);
   End;
Begin
   Read(N,M);
   For I:=1 To N Do Read(A[I]);
   For I:=1 To M Do Begin
      Read(B[I].Left,B[I].Right,B[I].Kth);
      B[I].Ith:=I;
   End;
   Intervalsort(1,M);
   B[0].Left:=Maxlongint;
   B[0].Right:=B[1].Left-1;
   Initialize;
   For I:=1 To M Do
   Begin
      For J:=B[I-1].Left To Min(B[I-1].Right,B[I].Left-1) Do
         Remove(T,A[J]);
      For J:=Max(B[I-1].Right+1,B[I].Left) To B[I].Right Do
         Insert(T,A[J]);
      Tmp:=Select(T,B[I].Kth);
      F[B[I].Ith]:=Key[Tmp];
   End;
   For I:=1 To M Do Begin
      Write(F[I]);
      If I Mod 1000=0 Then Writeln;
   End
End.
