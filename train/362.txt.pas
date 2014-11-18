type
 re=record
     l:real;
     x,y:longint;
    end;
var
 p,q,i,j,k,n,m,min:longint;
 d:set of byte;
 total,v,s,s0:real;
 a:array[0..150000] of re;
 f:array[0..150000] of longint;
 c:array[0..150000] of boolean;
procedure sort(cur,size:longint);
 var
  child:longint;
  tmp:re;
 begin
  tmp:=a[cur];
  while cur*2<=size do
   begin
    child:=2*cur;
    if (child+1<=size)and(a[child].l>a[child+1].l) then
     inc(child);
    if tmp.l<a[child].l then
     break;
    a[cur]:=a[child];
    cur:=child;
   end;
  a[cur]:=tmp;
 end;
function getf(v:longint):longint;
 var
  m:longint;
 begin
  if f[v]=v then
   getf:=v
   else
    begin
     m:=getf(f[v]);
     f[v]:=m;
     getf:=m;
    end;
 end;
begin
 readln(s0);
 readln(n);
 m:=0;
 for i:=1 to n do
  f[i]:=i;
 while not eof do
  begin
   readln(p,q,s);
   inc(m);
   a[m].l:=s;
   a[m].x:=p;
   a[m].y:=q;
   c[p]:=true;
   c[q]:=true;
  end;
 if m<n-1 then
  begin
   writeln('Impossible');
   exit;
  end;
 for i:=1 to n do
  if not c[i] then
   begin
    writeln('Impossible');
    exit;
   end;
 for i:=m div 2 downto 1 do
  sort(i,m);
 total:=0;
 for k:=1 to n-1 do
  begin
   while getf(a[1].x)=getf(a[1].y) do
    begin
     a[1]:=a[m];
     dec(m);
     sort(1,m);
    end;
   total:=total+a[1].l;
   f[f[a[1].x]]:=f[a[1].y];
   a[1]:=a[m];
   dec(m);
   sort(1,m);
  end;
 if total<=s0+0.00001 then
  writeln('Need ',total:0:2,' miles of cable')
  else
   writeln('Impossible');
end.
