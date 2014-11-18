var a:array[0..201] of longint;
    n,m,sum,l,i,j,k:longint;
function min(a,b:longint):longint;
begin
  min:=a;
  if b<min then min:=b;
end;
begin
  readln(l);
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    begin
      readln(j);
      inc(a[j]);
    end;
  sum:=a[l];
  a[l]:=0;
  if l mod 2=0 then
    begin
      inc(sum,a[l div 2] div 2);
      a[l div 2]:=a[l div 2] mod 2;
    end;
  for i:=l-1 downto l div 2+1 do
    begin
      j:=l-i;
      while a[i]>0 do
        begin
          while (a[j]=0) and (j>0) do dec(j);
          k:=min(a[j],a[i]);
          inc(sum,k);
          dec(a[j],k);
          dec(a[i],k);
          if j=0 then begin inc(sum,a[i]);a[i]:=0;end;
        end;
      end;
  j:=0;
  for i:=l div 2 downto 1 do
    inc(j,a[i]);
  inc(sum,j div 2+j mod 2);
  writeln(sum);
end.






