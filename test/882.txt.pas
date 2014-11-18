type
  lj=record
      x,y:integer;
    end;
Var
  f:array[0..41,0..21,0..21,0..21] of longint;
  a:array[1..20,1..20] of integer;
  b:array[1..39] of lj;
  n,i,j,k,l,t:longint;
Function max(a,b,c,d,e,f,g,h:longint):longint;
Begin
  if (a>=b) and (a>=c) and (a>=d) and (a>=e) and (a>=f) and (a>=g) and (a>=h)
    then
      exit(a);
  if (b>=a) and (b>=c) and (b>=d) and (b>=e) and (b>=f) and (b>=g) and (b>=h)
    then
      exit(b);
  if (c>=a) and (b>=b) and (c>=d) and (c>=e) and (c>=f) and (c>=g) and (c>=h)
    then
      exit(c);
  if (d>=a) and (d>=b) and (d>=c) and (d>=e) and (d>=f) and (d>=g) and (d>=h)
    then
      exit(d);
  if (e>=a) and (e>=b) and (e>=c) and (e>=d) and (e>=f) and (e>=g) and (e>=h)
    then
      exit(e);
  if (f>=a) and (f>=b) and (f>=c) and (f>=d) and (f>=e) and (f>=g) and (f>=h)
    then
      exit(f);
  if (g>=a) and (g>=b) and (g>=c) and (g>=d) and (g>=e) and (g>=f) and (g>=h)
    then
      exit(g);
  exit(h);
End;
Begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      read(a[i,j]);
  for i:=1 to n do
    begin
      b[i].x:=1;
      b[i].y:=i;
    end;
  t:=i;
  for i:=2 to n do
    begin
      inc(t);
      b[t].x:=i;
      b[t].y:=n;
    end;
  fillchar(f,sizeof(f),0);
  for i:=1 to 2*n+1 do
    for j:=b[i].x to b[i].y do
      for k:=b[i].x to b[i].y do
        for l:=b[i].x to b[i].y do
          begin
            if j=k
              then
                if l=k
                  then
                    t:=a[j,i-j+1]
                  else
                    t:=a[j,i-j+1]+a[l,i-l+1]
              else
                if k=l
                  then
                    t:=a[j,i-j+1]+a[k,i-k+1]
                  else
                    if j=l
                      then
                        t:=a[j,i-j+1]+a[k,i-k+1]
                      else
                        t:=a[j,i-j+1]+a[k,i-k+1]+a[l,i-l+1];
            f[i,j,k,l]:=t+max(f[i-1,j,k,l],f[i-1,j,k,l-1],f[i-1,j,k-1,l],f[i-1,j,k-1,l-1],f[i-1,j-1,k,l],f[i-1,j-1,k,l-1],f[i-1,j-1,k-1,l],f[i-1,j-1,k-1,l-1]);
          end;
  writeln(f[2*n-1,n,n,n]);
End.

