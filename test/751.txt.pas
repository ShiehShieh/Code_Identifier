type ty=packed array[0..10000] of longint;
var a:ty;
i,l,n:longint;
   procedure ks(var b:ty;s,t:longint);
   var ii,j,k:longint;
   begin
   if s<t then begin
   ii:=s;j:=t;k:=b[s];
   repeat
   while (b[j]>k) and (j>ii) do j:=j-1;
   if j>ii then begin
   b[ii]:=b[j];ii:=ii+1;
   end;
   while (b[ii]<k) and (ii<j) do ii:=ii+1;
   if ii<j then begin
   b[j]:=b[ii];j:=j-1;
   end;
   until ii=j;
   b[ii]:=k;
   ks(b,s,j-1);
   ks(b,ii+1,t);
   end;
   end;
      procedure cr;
       var z,temp,k,j:longint;
            bo:boolean;
       begin
   for j:=3 to n-i+1 do a[j-1]:=a[j];
   a[n-i+1]:=0;
   bo:=true;
   for j:=2 to n-i do if (bo) and(a[1]<a[j]) then begin
    bo:=false;
    for k:=n-i downto j do a[k+1]:=a[k];
   a[j]:=a[1];
   for k:=2 to n-i+1 do a[k-1]:=a[k];
   a[n-i+1]:=0;

   end;
    if bo then begin
     a[n-i+1]:=a[1];
     for j:=1 to n-i do a[j]:=a[j+1];
     a[n-i+1]:=0;
     end;
         end;
begin
read(n);
for i:=1 to n do read(a[i]);
l:=0;
ks(a,1,n);
for i:=1 to n-1 do begin
a[1]:=a[1]+a[2];
l:=l+a[1];
a[2]:=0;
cr;
end;
write(l);
end.
