PRogram P1518;
var
  w,d,v,lch,rch,r:array [0..100] of longint;
  len:array [0..100,0..100] of longint;
  f:array [0..100,0..100,0..50] of longint;
  queue:array [1..100] of longint;
  n,k,q:longint;

Function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;

PRocedure INit;
var
  i:longint;
begin
  readln(n,k);
  for i:=1 to n do
    readln(w[i],v[i],d[i]);
  v[0]:=-1;
end;

PRocedure MakeTree;
var
  i,j:longint;
begin
  fillchar(len,sizeof(len),0);
  for i:=1 to n do
    begin
      if lch[v[i]]=0 then
        lch[v[i]]:=i
          else
        begin
          j:=lch[v[i]];
          while rch[j]<>0 do
            j:=rch[j];
          rch[j]:=i;
        end;
      j:=i;
      while j>0 do
        begin
          len[i,v[j]]:=len[i,j]+w[i]*d[j];
          j:=v[j];
        end;
    end;
end;

PRocedure TreeDp(i:longint);
var
  j,s,d:longint;
begin
  if lch[i]>0 then
    begin
      inc(q);
      queue[q]:=i;
      TreeDp(lch[i]);
      dec(q);
    end;
  if rch[i]>0 then
    TreeDp(rch[i]);
  r[i]:=r[lch[i]]+r[rch[i]]+1;
  if r[i]>k then r[i]:=k;
  if (lch[i]=0) and (rch[i]=0) then
    begin
      for j:=q downto 1 do
        begin
          f[i,queue[j],0]:=len[i,queue[j]];
          f[i,queue[j],1]:=0;
        end;
    end else
    begin
      for j:=q downto 1 do
        for s:=0 to r[i] do
          for d:=0 to s do
            f[i,queue[j],s]:=min(f[i,queue[j],s],f[lch[i],queue[j],d]+f[rch[i],queue[j],s-d]+len[i,queue[j]]);
      for j:=q downto 1 do
        for s:=0 to r[i] do
          for d:=0 to s-1 do
            f[i,queue[j],s]:=min(f[i,queue[j],s],f[lch[i],i,d]+f[rch[i],queue[j],s-d-1]);
    end;
end;

begin
  INit;
  MakeTree;
  fillchar(r,sizeof(r),0);
  fillchar(f,sizeof(f),12);
  fillchar(f[0],sizeof(f[0]),0);
  q:=0;
  TreeDp(0);
  writeln(f[lch[0],0,k]);
end.
