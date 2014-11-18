const
 x=0.6180339887498949;

var
    n, i, j, bi, bj :longint;
    bx,zx:double;
    a:array[0..30001] of longInt;

procedure pai(l,r:longint);
 var
  i,j,k,mid:longint;
begin
 i:=l;
 j:=r;
 mid:=a[(i+j) div 2];
 repeat
  while a[i]<mid do inc(i);
  while a[j]>mid do dec(j);
  if i<=j
  then begin
        k:=a[i];
        a[i]:=a[j];
        a[j]:=k;
        inc(i);
        dec(j);
       end;
 until i>j;
 if j>l then pai(l,j);
 if i<r then pai(i,r);
end;
////////////////////////////////////////////
begin
    readln(n);
    for i:=1 to n do
      read(a[i]);
    randomize;
    pai(1,n);

    i:=1;
    while a[i]<=0 do inc(i);
    j:=i+1;
    bi:=i;
    bj:=bi+1;
    bx:=a[bi]/a[bj];
    while j<=n do
      begin
        zx:=a[i]/a[j];
        if abs(zx-x)<abs(bx-x)
          then begin
                 bx:=zx;
                 bi:=i;
                 bj:=j
               end;
        if zx<x
          then
            inc(i)
          else
            inc(j)
      end;
    writeln(a[bi]);
    write(a[bj])
end.

