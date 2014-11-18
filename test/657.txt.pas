const Maxn=400000;
type index=Longint;
var
  SS,TT,tot,N,M,ans,tot_edge,S,T,S_,T_:index;
  queue,next,G,C,W:array[0..Maxn]of index;
  V,dis,head,last,FaK,Fa:array[-1..400]of index;
  Flag:array[-1..400]of boolean;

procedure insert(x,y,cc,ww:index);
Begin
  inc(tot_edge); G[tot_edge]:=y; C[tot_edge]:=CC; W[tot_edge]:=ww;
  if head[x]=0 then head[x]:=tot_edge
    else next[last[x]]:=tot_edge;
  last[x]:=tot_edge;
  inc(tot_edge); G[tot_edge]:=x; C[tot_edge]:=0; W[tot_edge]:=-ww;
  if head[y]=0 then head[y]:=tot_edge
    else next[last[y]]:=tot_edge;
  last[y]:=tot_edge;
End;

Function nxt(T:index):index;
Begin
  if T=Maxn then Exit(1); Exit(T+1);
End;

Function Find_path:boolean;
var K,h,t:index;
Begin
  Fillchar(dis,sizeof(dis),$FF);
  Fillchar(Flag,sizeof(Flag),0);
  queue[1]:=S_; Flag[S_]:=true; dis[S_]:=0;
  h:=0; t:=1;
  Repeat
    h:=nxt(h);
    K:=head[queue[h]];
    while K<>0 do
      Begin
        if (C[K]>0)and((dis[G[K]]=-1)or(dis[queue[h]]+W[K]<dis[G[K]])) then
          Begin
            FaK[G[K]]:=K; Fa[G[K]]:=queue[h];
            dis[G[K]]:=dis[queue[h]]+W[K];
            if not Flag[G[K]] then
              Begin
                t:=nxt(t); queue[t]:=G[K];
                Flag[G[K]]:=True;
              End;
          End;
        K:=next[K];
      End;
    Flag[queue[h]]:=False;
  Until t=h;
  Exit(dis[T_]<>-1);
End;

procedure Change_path;
var Flow,u:index;
Begin
  Flow:=maxlongint;
  u:=T_;
  while u<>S_ do
    Begin
      if C[FaK[u]]<Flow then Flow:=C[FaK[u]];
      u:=Fa[u];
    End;
  u:=T_;
  while u<>S_ do
    Begin
      if odd(FaK[u]) then
        Begin
          dec(C[FaK[u]],Flow);
          inc(C[FaK[u]+1],Flow);
        End
      Else
        Begin
          dec(C[FaK[u]],Flow);
          inc(C[FaK[u]-1],Flow);
        End;
      u:=Fa[u];
    End;
  ans:=ans+dis[T_]*Flow;
End;

var i,j,ww:index;

Begin

  Readln(N,M);
  tot:=0;
  For i:=1 to N do Read(V[i]);
  For i:=1 to N do tot:=tot+V[i];
  S:=0; T:=2*N+1;
  S_:=-1; T_:=2*N+2;
  SS:=2*N+3;
  insert(S_,S,M,0);
  For i:=1 to N do
    Begin
      insert(i*2-1,T_,V[i],0);
      insert(S_,i*2,V[i],0);
      insert(S,i*2-1,Maxlongint,0);
      insert(i*2,T,Maxlongint,0);
    End;
  For i:=1 to N-1 do
    Begin
      For j:=i+1 to N do
        Begin
          Read(ww); if ww<>-1 then insert(i*2,j*2-1,Maxlongint,ww);
        End;
      Readln;
    End;
  while Find_path do
    Change_path;
  writeln(ans);

End.
