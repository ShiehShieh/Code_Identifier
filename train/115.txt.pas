var
 maxi,a:array[1..40] of longint;
 f:array[0..10000] of longint;
 i,j,k,m,n,max:longint;
procedure try(q,p,t:longint);
 var
  min,i,j,k,w:longint;
 begin
 if q>m then
  begin
   if t>=max then
    begin
     max:=t;
     maxi:=a;
    end;
  end
 else
  for w:=p+1 to t+1 do
   begin
    a[q]:=w;
    fillchar(f,sizeof(f),0);
    f[1]:=1;
    i:=1;
    while true do
     begin
      i:=i+1;
      min:=maxlongint;
      for j:=1 to q do
       if (i>=a[j]) and (f[i-a[j]]+1<min) then min:=f[i-a[j]]+1;
      f[i]:=min;
      if min>n then begin i:=i-1;break;end;
     end;
    try(q+1,w,i);
    a[q]:=0;
   end;
 end;
 begin
  readln(n,m);
  a[1]:=1;
  try(2,1,n);
  for i:=1 to m-1 do
   write(maxi[i],' ');
  writeln(maxi[m]);
  writeln('MAX=',max);
 end.

