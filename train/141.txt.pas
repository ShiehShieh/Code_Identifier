var
  a:array[1..500]of longint;
  n,s,k,i,j,t,max,min:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(s);
  readln(n);
  max:=0;
  min:=maxlongint;
  for i:=1 to n do
    begin
      readln(k);
      inc(a[k]);
      if k>max then max:=k;
      if k<min then min:=k;
    end;
  i:=min;  j:=max;
  t:=0;
  while i<j do
    begin
      if i+j<=s
        then
          begin
            a[i]:=a[i]-1;
            a[j]:=a[j]-1;
            inc(t);
          end
        else
          begin
            a[j]:=a[j]-1;
            inc(t);
          end;

      while (a[i]=0) and (i<j) do
        inc(i);
      while (a[j]=0) and (i<j) do
        dec(j);
    end;
  if a[i]<>0 then
    if i<=s div 2
      then t:=t+a[i] div 2+a[i] mod 2
      else t:=t+a[i];
  writeln(t);
end.
