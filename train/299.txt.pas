type p=record
     x,y:extended;
     end;
var dist:array[1..1000]of extended;
    a:array[1..1000]of p;
    map:array[1..1000,1..1000]of extended;
    line:array[1..3000,1..2]of p;
    now,i,j,k,m,n,lin:longint;
    bb:array[1..1000]of boolean;
    ma:extended;
procedure insertl(t1,t2:p);
begin inc(lin); line[lin,1]:=t1; line[lin,2]:=t2; end;
procedure init;
var i,j,k:longint;
    x,a1,b1,a2,b2:extended;
    s1,s2:p;
begin
  readln(N); m:=1; a[1].x:=0; a[1].y:=5;
  for i:=1 to n do
    begin
      read(x,a1,b1,a2,b2);
      s1.x:=x; s1.y:=0; s2.x:=x; s2.y:=10;
      inc(m); a[m].x:=x; a[m].y:=a1;
      insertl(s1,a[m]);
      inc(m); a[m].x:=x; a[m].y:=b1;
      inc(m); a[m].x:=x; a[m].y:=a2;
      insertl(a[m-1],a[m]);
      inc(m); a[m].x:=x; a[m].y:=b2;
      insertl(a[m],s2);
    end;
  inc(m); a[m].x:=10; a[m].y:=5;
end;

function diste(a,b:p):extended;
begin diste:=sqrt( sqr(a.x-b.x)+sqr(a.y-b.y) ); end;

function mm(a,b,c:p):extended;
function mmm(x1,y1,x2,y2:extended):extended;
begin exit(x1*y2-x2*y1); end;
begin exit(mmm(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y)); end;
function max(a,b:extended):extended;
begin max:=a; if b>a then max:=b; end;
function min(a,b:extended):extended;
begin min:=a; if b<a then min:=b; end;
function across(a,b,c,d:p):boolean;
begin
  across:=false;
  if (max(a.x,b.x)>=min(c.x,d.x))and
     (max(c.x,d.x)>=min(a.x,b.x))and
     (max(a.y,b.y)>=min(c.y,d.y))and
     (max(c.y,d.y)>=min(a.y,b.y))and
     (mm(a,b,c)*mm(a,b,d)<0)and(mm(c,d,a)*mm(c,d,b)<0) then
     exit(true) else exit(false);
end;
procedure pre;
var i,j,k:longint;
    bbb:boolean;
begin
  for i:=1 to m do
    for j:=i+1 to m do
      begin
        bbb:=true;
        for k:=1 to lin do
          if across(a[i],a[j],line[k,1],line[k,2]) then bbb:=false;
        if bbb then map[i,j]:=diste(a[i],a[j]);
      end;
end;
begin
init;
pre;
for i:=1 to m do dist[i]:=maxint;
dist[1]:=0;
now:=1;
fillchar(bb,sizeof(bb),true);
repeat
  bb[now]:=false;
  for i:=1 to m do
    if bb[i] and (map[now,i]<>0) then
      if dist[i]>dist[now]+map[now,i] then
        dist[i]:=dist[now]+map[now,i];
  ma:=maxint;
  for i:=1 to m do
    if bb[i] and( ma>dist[i]) then
      begin ma:=dist[i]; now:=i; end;
  if now=m then break;
until now=m;
writeln(dist[m]:0:2);
end.




