program p1213;
Const Maxn=100*3;
      Maxe=(200*3)*(200*3);
      Num =1000000;
var N,M,S,T,S0,T0,S1,Edge    : longint;
    D,Fv,Fe,Mf               : array[0..Maxn] of longint;
    Vis                      : array[0..Maxn] of boolean;
    H,l                      : array[0..Maxn] of longint;
    push,G,C,W,Next          : array[0..Maxe] of longint;
    Ans                      : longint;

function min(i,j:longint):longint;
begin
  if i<j then exit(i) else exit(j);
end;

procedure insert(a,b,ci,wi:longint);
begin
  inc(Edge);
  if H[a]=0 then H[a]:=edge else Next[L[a]]:=edge;
  L[a]:=edge;
  G[edge]:=b;
  C[edge]:=ci;
  W[Edge]:=wi;
end;

procedure init;
var i,j,k:longint;
begin
  Readln(N,M);
  Ans:=0; Edge:=0; S:=0; S0:=N*2+1; S1:=N*2+2; T0:=N*2+3; T:=N*2+4;
  for i:=1 to n do
  begin
    Read(k);
    //insert(i*2-1,i*2,Num,0); insert(i*2,i*2-1,0,0);
    insert(i*2-1,T,K,0);     insert(T,i*2-1,0,0);
    insert(S,i*2,K,0);       insert(i*2,S,0,0);
    insert(S1,i*2-1,Num,0);  insert(i*2-1,S1,0,0);
    insert(i*2,T0,Num,0);    insert(T0,i*2,0,0);
  end;

  insert(S0,T0,Num,0);
  insert(T0,S0,Num,0);
  insert(S,S1,M,0);
  insert(S1,S,0,0);
  insert(S0,T,M,0);
  insert(T,S0,0,0);
  Readln;

  for i:=1 to n-1 do
  begin
    for j:=i+1 to n do
    begin
      Read(k);
      if k<>-1 then begin
        insert(i*2,j*2-1,Num,k);
        insert(j*2-1,i*2,0,-k);
      end;
    end;
    Readln;
  end;
end;

function Find_Path:boolean;
var head,tail,i,u,v:longint;
begin
  Fillchar(D,sizeof(D),$2f);
  Fillchar(Fv,sizeof(Fv),0);
  Fillchar(Fe,sizeof(Fe),0);
  Fillchar(Mf,sizeof(Mf),$2f);
  Fillchar(Vis,sizeof(Vis),0);
  D[S]:=0; head:=0; tail:=1; push[1]:=S; Vis[S]:=True;
  While Head<Tail do
  begin
    inc(Head);
    u:=Push[Head];
    i:=H[u];
    While i<>0 do
    begin
      if C[i]>0 then
      begin
        v:=G[i];
        if D[u]+W[i]<D[v] then
        begin
          Fv[v]:=u;
          Fe[v]:=i;
          D[v]:=D[u]+w[i];
          Mf[v]:=Min(Mf[u],C[i]);
          if not Vis[v] then begin
            inc(Tail);
            Vis[v]:=True;
            push[Tail]:=v;
          end;
        end;
      end;
      i:=next[i];
    end;
    Vis[u]:=False;
  end;
  if D[t]<=1000000 then Exit(True) else Exit(False);
end;

procedure Add_Path;
var i:longint;
begin
  Ans:=Ans+Mf[T]*D[T];
  i:=T;
  Repeat
    Dec(C[Fe[i]],Mf[T]);
    if Fe[i] mod 2=0 then inc(C[Fe[i]-1],Mf[T]) else inc(C[Fe[i]+1],Mf[T]);
    i:=Fv[i];
  until i=S;
end;

procedure Main;
begin
  While find_Path do Add_Path;
end;

procedure Print;
begin
  Writeln(Ans);
end;

begin
  init;
  Main;
  Print;
end.

