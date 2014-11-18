PRogram P1054;
var
  dist:array [-1..3000] of longint;
  a:array [0..3000,0..3000] of longint;
  boo:array [0..3000] of boolean;
  n,m,minl:longint;

Function Max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;

Function Min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;

Procedure INit;
var
  l,i,j:longint;
begin
  readln(n,m);
  fillchar(boo,sizeof(boo),false);
  minl:=maxlongint;
  for i:=1 to n do
    begin
      readln(l);
      for j:=max(1,l-m) to l do
        begin
          boo[j]:=true;
          minl:=min(j,minl);
        end;
    end;
end;

PRocedure Run;
var
  i,j,mini,r:longint;
  check:boolean;
begin
  if minl=1 then
    begin
      writeln(-1);
      halt;
    end;

  fillchar(dist,sizeof(dist),12);
  for i:=3000 downto 1 do
    if boo[i] then
      dist[i mod minl]:=i;

  fillchar(a,sizeof(a),12);
  for i:=0 to minl-1 do
    for j:=0 to minl-1 do
      a[i,(i+j) mod minl]:=min(a[i,(i+j) mod minl],dist[j]);

  fillchar(boo,sizeof(boo),false);
  dist[-1]:=maxlongint;
  mini:=-1;
  for i:=0 to minl-1 do
    if dist[i]<dist[mini] then mini:=i;
  while mini<>-1 do
    begin
      boo[mini]:=true;
      i:=mini;
      mini:=-1;
      for j:=0 to minl-1 do
        if not boo[j] then
          begin
            dist[j]:=min(dist[j],dist[i]+a[i,j]);
            if dist[j]<dist[mini] then mini:=j;
          end;
    end;
  r:=0;
  for i:=0 to minl-1 do
    r:=max(r,dist[i]);
  if r>=200000000 then
    begin
      writeln(-1);
      halt;
    end;
  for i:=r-1 downto 1 do
    if i<dist[i mod minl] then
      begin
        writeln(i);
        halt;
      end;
  writeln(-1);
end;

begin
  INit;
  Run;
end.
