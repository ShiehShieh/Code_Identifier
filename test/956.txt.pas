var
  d : array[1..30000] of longint;
  n ,i,w,j,s: longint;
  procedure swap(var a,b:longint);
  var t:longint;
  begin
    t:=a;
    a:=b;
    b:=t;
  end;
  procedure qSort(left,right:longint);
  var i,j,m : longint;
  begin
    if left>=right then exit;
    i:=left;  j:=right;
    m:=d[(left+right) div 2];
    repeat
      while d[i]<m do inc(i);
      while d[j]>m do dec(j);
      if i<=j then
      begin
        Swap(d[i],d[j]);
        inc(i);
        dec(j);
      end;
    until i>j;
    qSort(left,j);
    qSort(i,right);
  end;
begin
  readln(w);
  readln(n);
  for i:=1 to n do read(d[i]);
  qsort(1,n);
  i:=1; j:=n;
  while i<=j do
  begin
    if d[j]+d[i]>w then begin inc(s); j:=j-1; end
      else begin inc(s); j:=j-1; i:=i+1; end;
  end;
  writeln(s);
end.
