var n,m,p,mi,mj,pi,pj,t1,t2:longint;
    i:longint;
    f:array[0..5000] of longint;
function sort(a:longint):longint;
begin
    if a=f[a] then exit(a);
    f[a]:=sort(f[a]);
    exit(f[a]);
end;
begin
    readln(n,m,p);
    for i:=1 to n do f[i]:=i;
    for i:=1 to m do
     begin
      readln(mi,mj);
       t1:=sort(mi); t2:=sort(mj);
      if t1<>t2 then f[t1]:=t2;
     end;
    for i:=1 to p do
     begin
      readln(pi,pj);
      if sort(pi)=sort(pj) then writeln('Yes')
      else writeln('No');
     end;
end.

