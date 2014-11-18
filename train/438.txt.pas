//Written By:Star Kirby & Phoenix
//Algorithm:Dynamic Programing+ Deal With String
//Date:2009-3-11
Program Dizeng_Xulie;
 Var S:String;
     Final,An:Array[1..80]Of String;
     F:Array[1..80]Of Longint;
     I,j,Len,Total,K:Longint;
     Ans:Array[1..80,1..80]Of String;
     Bef:Array[1..100]Of Longint;
  Procedure Deal(Var Te:String);
   Begin
    While (Te[1]='0') And (Length(Te)>1) Do
     Delete(Te,1,1);
   End;
  Function Max(X,y:String):String;
   Var LenX,LenY,R:Longint;
       TempX,TempY:String;
    Begin
     TempX:=X;
     TempY:=Y;
     Deal(X);
     Deal(Y);
     LenX:=Length(X);
     LenY:=Length(Y);
     If LenX<LenY Then
      Exit(TempY)
     Else
      If LenX>LenY Then
       Exit(TempX)
     Else
      Begin
       For R:=1 To LenX Do
        If X[R]>Y[R] Then
         Exit(TempX)
       Else
        If X[R]<Y[R] Then
         Exit(TempY);
      End;
     Exit(TempX);
    End;
  Procedure Init;
   Begin
    Len:=Length(S);
    Ans[1,1]:=Copy(S,1,1);
    For I:=1 To Len Do
     For J:=I To Len Do
      For K:=I To J Do
       Ans[I,J]:=Copy(S,I,J-I+1);
   End;
  Begin
   Readln(S);
   Init;
   For I:=1 To Len Do
    Begin
     F[I]:=1;
     Final[I]:=Ans[1,I];
    End;
   For I:=1 To Len Do
    For J:=1 To I-1 Do
     If (Max(Ans[J+1,i],Final[J])=Ans[J+1,I]) And (Ans[J+1,I]<>Final[J]) Then
      If F[J]+1>=F[I] Then
       Begin
        Final[I]:=Ans[J+1,I];
        If F[J]+1>=F[I] Then
         Bef[I]:=J
        Else
         If Max(Ans[J+1,I],Final[I])<>Final[I] Then
          Begin
           Final[I]:=Ans[J+1,I];
           Bef[I]:=J;
          End;
        F[I]:=F[J]+1;
       End;
   I:=Len;
   While Bef[I]<>0 Do
    Begin
     Inc(Total);
     An[Total]:=Final[I];
     I:=Bef[I];
    End;
   Write(Final[I]);
   If Total>0 Then
    Begin
     For I:=Total Downto 1 Do
      Write(',',An[I]);
    End;
   Writeln;
  End.

