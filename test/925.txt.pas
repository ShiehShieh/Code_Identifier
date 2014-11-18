var
  a:array[1..11111]of record
      s,e,c:longint;
    end;
  k,i,n,s,e,hn:longint;
  f:array[1..11111]of longint;
  h,l:array[1..11111]of longint;

procedure swap(var a,b:longint);
var
  t:longint;
begin
  t:=a;a:=b;b:=t
end;

procedure qsort(x,y:longint);
var
  i,j,k:longint;
begin
  if x<y then
  begin
    i:=x-1;j:=y+1;k:=a[random(y-x+1)+x].s;
    while true do
    begin
      repeat dec(j); until a[j].s<=k;
      repeat inc(i); until a[i].s>=k;
      if i<j then begin swap(a[i].s,a[j].s);swap(a[i].e,a[j].e);swap(a[i].c,a[j].c); end
        else break
    end;
    qsort(x,j);qsort(j+1,y)
  end
end;

procedure insert(x:longint);
var
  xx:longint;
begin
  while x>1 do
  begin
    xx:=x div 2;
    if h[xx]>h[x] then begin swap(h[xx],h[x]);swap(l[xx],l[x]) end
      else break;
    x:=xx
  end
end;

procedure del;
var
  x,xx:longint;
begin
  h[1]:=h[hn];l[1]:=l[hn];h[hn]:=maxlongint;
  dec(hn);
  x:=1;xx:=1;
  while x<=hn div 2 do
  begin
    if h[x]>h[x*2]
      then if h[x*2]<h[x*2+1]
             then xx:=x*2
             else xx:=x*2+1
      else if h[x]>h[x*2+1]
             then xx:=x*2+1
             else break;
    swap(h[x],h[xx]);swap(l[x],l[xx]);
    x:=xx;
  end;
end;

begin

  randomize;
  readln(n,s,e);
  for i:=1 to n do
  begin
    readln(a[i].s,a[i].e,a[i].c);
    h[i]:=maxlongint
  end;
  qsort(1,n);
  h[1]:=0;l[1]:=s-1;hn:=1;
  k:=maxlongint;
  for i:=1 to n do
  begin
    while (hn>0)and(l[1]+1<a[i].s) do del;
    if hn=0 then begin writeln(-1);halt end;
    inc(hn);h[hn]:=h[1]+a[i].c;l[hn]:=a[i].e;
    f[i]:=h[1]+a[i].c;
    if (f[i]<k)and(l[hn]>=e) then k:=f[i];
    insert(hn);
  end;
  writeln(k);

end.

