program p1352;  // dinic!!!
const maxn=40000;
var s,t,n,n0,U:longint;
    h,g,l,c,next:array[0..maxn*10] of longint;
    ans :longint;
    tot :longint;
    od,d,last,m,DD:array[0..maxn] of longint;

procedure Add_Edge(x,y,z:longint);
begin
  inc(tot);
  if h[x]=0 then h[x]:=tot
  else next[l[x]]:=tot;
  l[x]:=tot;
  g[tot]:=y;
  c[tot]:=z;
end;

procedure BFS;
var i,j,q1,q2,q3:longint;
begin
  fillchar(m,sizeof(m),$ff);
  fillchar(od,sizeof(od),0);
  m[s]:=0; d[1]:=s; q1:=1; q2:=1; q3:=1;
  repeat
    q1:=q3; q3:=q2+1;
    for i:=q1 to q2 do
    begin
      j:=h[d[i]];
      while j<>0 do
      begin
        if c[j]>0  then
          if (m[g[j]]=-1) or (m[d[i]]+1=m[g[j]]) then
            if m[g[j]]=-1 then
            begin
              m[g[j]]:=m[d[i]]+1;
              inc(q2);
              d[q2]:=g[j];
              inc(od[d[i]]);
           end
           else inc(od[d[i]]);
        j:=next[j];
       end;
    end;
  until q3>q2;
end;

function num(x:longint):longint;
begin
  if x mod 2=1 then Num:=(x+1) else Num:=(x-1);
end;

procedure DFS;
var i,top,p,flow:longint;
begin
  d[1]:=s; top:=1; last[1]:=h[s];
  repeat
    if d[top]=t then
    begin
       flow:=maxlongint;
       for i:=1 to top-1 do
         if c[last[i]]<flow then flow:=c[last[i]];
       inc(ans,flow);
       for i:=1 to top-1 do
       begin
         dec(c[last[i]],flow);
         inc(c[num(last[i])],flow);
       end;
       i:=1;
       while c[last[i]]>0 do inc(i);
       top:=i;
    end
    else
      if od[d[top]]>0 then
      begin
        p:=last[top];
        if (m[g[p]]=m[d[top]]+1) and (c[p]>0) then
        begin
          dec(od[d[top]]);
          inc(top);
          d[top]:=g[p];
          last[top]:=h[g[p]];
        end
        else last[top]:=next[last[top]];
      end
      else begin
         dec(top);
         last[top]:=next[last[top]];
      end;
  until top=0;
end;

procedure main;
begin
  repeat
    BFS;
    if m[t]=-1 then break;
    DFS;
  until false;
end;

procedure print;
begin
  writeln((U*N-ans)div 2);
end;

var
  i,x,y,cc:Longint;
Begin

  Readln(N,N0); S:=0; T:=N+1;
  For i:=1 to N do Read(DD[i]); Readln;
  For i:=1 to N do DD[i]:=DD[i]*2;
  For i:=1 to N0 do
    Begin
      Readln(x,y,cc);
      dec(DD[x],cc); dec(DD[y],cc);
      Add_Edge(x,y,cc); Add_Edge(y,x,0);
      Add_Edge(y,x,cc); Add_Edge(x,y,0);
    End;
  U:=0; For i:=1 to N do if DD[i]<U then U:=DD[i];
  U:=Abs(U);
  For i:=1 to N do
    Begin
      Add_Edge(S,i,U); Add_Edge(i,S,0);
      Add_Edge(i,T,U+DD[i]); Add_Edge(T,i,0);
    End;
  main;
  print;

end.
