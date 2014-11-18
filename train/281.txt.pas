const d:array[1..8,1..2] of longint=((1,2),(2,1),(2,-1),(-1,2),(-1,-2),(-2,-1),(1,-2),(-2,1));
var i,x,y,t,r,l:longint;
    a:array[-10..30,-10..30] of longint;
procedure dg(x,y:longint);
begin
  if (x=r) and (y=l) then begin
    inc(t);
    exit;
  end;
  if (x+1<=r) and (a[x+1,y]<>1) then dg(x+1,y);
  if (y+1<=l) and (a[x,y+1]<>1) then dg(x,y+1);
end;
begin
  fillchar(a,sizeof(a),0);
  readln(r,l,x,y);
  a[x,y]:=1;
  for i:=1 to 8 do a[x+d[i,1],y+d[i,2]]:=1;
  t:=0;
  dg(0,0);
  writeln(t);
end.
