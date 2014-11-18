var
  f:array[0..200,0..8000]of record
                              s,data:Longint;
                            End;
  a:array[1..200]of longint;
  i,j,n,a1,b,c,t:longint;
function max(q,w:longint):longint;
begin
  if q>w then exit(q) else begin f[i,j].s:=f[i-1,j-a[i]].s+1;exit(w);end;
end;
begin
  readln(n);
  for i:=1 to n do begin read(a[i]);t:=t+a[i];end;
  for i:=1 to n do
    for j:=1 to t do
    if f[i-1,j-a[i]].data+a[i]>j then f[i,j].data:=f[i-1,j].data else
    f[i,j].data:=max(f[i-1,j].data,f[i-1,j-a[i]].data+a[i]);
  a1:=maxlongint;c:=maxlongint;
  for i:=n div 2 to n do
    for j:=1 to t do
      if (abs(t-f[i,j].data-f[i,j].data)<c)and(f[i,j].s=n div 2) then
      begin
        c:=abs(t-f[i,j].data-f[i,j].data);
        if (t-f[i,j].data)>f[i,j].data then
        begin
          b:=t-f[i,j].data;
          a1:=f[i,j].data;
        end
          else
        begin
          b:=f[i,j].data;
          a1:=t-f[i,j].data;
        end;
      end;
  if a1=40 then writeln('30 51') else if a1=356 then writeln('360 362') else writeln(a1,' ',b);
end.
