  Var
    MAP,bh:Array[1..100,1..100]of Longint;
    te,now,k,a,b,n,m,h,t:Longint;
    ans:int64;
    Dist:Array[-2000..2000]of int64;
    la,be:Array[-2000..2000]of Longint;
    ro,va,pr,up:Array[-10000..10000]of Longint;
    bl:Array[-2000..2000]of Boolean;
    list:Array[1..10000]of Longint;
  Procedure ins(a1,a2,a3,a4:Longint);
    begin
      te:=te+1;
      pr[te]:=la[a1];
      la[a1]:=te;
      ro[te]:=a2;
      va[te]:=a3;
      up[te]:=a4;
      pr[-te]:=la[a2];
      la[a2]:=-te;
      ro[-te]:=a1;
      va[-te]:=-a3;
      up[-te]:=0;
    End;
  Function SPFA:Boolean;
    Var
      a1:Longint;
    Begin
      h:=0;
      t:=1;
      Fillchar(dist,sizeof(dist),255);
      Dist[-1]:=0;
      List[1]:=-1;
      bl[-1]:=True;
      While h<>t do
        Begin
          h:=h+1;
          If h>10000
            Then
              h:=1;
          a1:=la[list[h]];
          While a1<>0 do
            Begin
              If (up[a1]>0)and(Dist[list[h]]+va[a1]>Dist[ro[a1]])
                Then
                  Begin
                    Dist[ro[a1]]:=Dist[list[h]]+va[a1];
                    be[ro[a1]]:=a1;
                    If Not bl[ro[a1]]
                      Then
                        Begin
                          bl[ro[a1]]:=True;
                          t:=t+1;
                          If t>10000
                            Then
                              t:=1;
                          list[t]:=ro[a1];
                        End;
                  End;
              a1:=pr[a1];
            End;
          bl[list[h]] :=False;
        End;
      If dist[now+1]>-1
        Then
          Begin
            SPFA:=True;
            a1:=now+1;
            Ans:=Ans+dist[now+1];
            While a1<>-1 do
              Begin
                up[be[a1]]:=up[be[a1]]-1;
                up[-be[a1]]:=up[-be[a1]]+1;
                a1:=ro[-be[a1]];
              End;
          End
        Else
          SPFA:=False;
    End;
  Procedure ss;
    Var
      a1:Longint;
    Begin
      For a1:=1 to 3 do
      If not SPFA
        Then
          Break;
    End;
  Begin

    Read(n);
    For a:=1 to n do
      For b:=1 to n do
        Read(map[a,b]);
    te:=0;
    Fillchar(la,sizeof(la),0);
    For a:=1 to n do
      For b:=1 to n-1 do
        Begin
          ins(a*n-n+b,-(a*n-n+b+1),0,100);
        End;
    For a:=1 to n-1 do
      For b:=1 to n do
        Begin
          ins(a*n-n+b,-(a*n-n+b+n),0,100);
        End;                  
    For a:=1 to n do
      For b:=1 to n do
        Begin
          ins(-(a*n-n+b),a*n-n+b,map[a,b],1);
          ins(-(a*n-n+b),a*n-n+b,0,100);
        End;
    Fillchar(bl,sizeof(bl),0);
    Ans:=0;
    now:=n*n-1;
    ss;
    Writeln(ans);
End.
