//Written By:Star Kirby & Phoenix x
//Algorithm:Imitatio + Qsort
//Date:2009-3-11
Program Double_Tao_Pick_Apple;
 Type Re=Array[1..1000000]Of Longint;
 Var Sum,A,B,Hash,Ans:Re;
     N,m,I,j:Longint;
  Procedure Qsort(Var S:Re;L,r:Longint);
   Var C,d,X,Temp:Longint;
    Begin
     C:=l;
     D:=r;
     X:=S[C+Random(D-c+1)];
     Repeat
      While S[C]>X Do Inc(C);
      While S[D]<X Do Dec(D);
      If C<=d Then
       Begin
        Temp:=S[C];
        S[C]:=S[D];
        S[D]:=Temp;
        Temp:=Hash[C];
        Hash[C]:=Hash[D];
        Hash[D]:=Temp;
        Inc(C);
        Dec(D);
       End;
     Until C>d;
     If L<d Then Qsort(S,L,d);
     If C<r Then Qsort(S,C,r);
    End;
  Begin
   Read(N,m);
   Fillchar(A,sizeof(A),0);
   Fillchar(B,sizeof(B),0);
   Randomize;
   For I:=1 To N Do
    Read(A[I]);
   Qsort(A,1,N);
   For J:=1 To M Do
    Read(B[J]);
   For I:=1 To M Do
    Hash[I]:=I;
   Qsort(B,1,M);
   J:=0;
   Repeat
    For I:=1 To M Do
     Inc(Sum[I],A[J+I]);
    Inc(J,M);
   Until J>=N;
   For I:=1 To M Do
    Ans[Hash[I]]:=Sum[I];
   If M>0 Then
    Write(Ans[1]);
   For I:=2 To M Do
    Write(' ',Ans[I]);
   Writeln;
  End.

