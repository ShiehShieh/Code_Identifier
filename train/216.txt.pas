var n,i,p,q:integer;
    b:array[0..5000,0..3] of integer;
    a:array[0..5000] of integer;
    c:array[0..5000] of integer;
procedure qsort(l,r: longint);
      var
         i,j,x,y,z: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do inc(i);
           while x<a[j] do dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                z:=c[i];
                c[i]:=c[j];
                c[j]:=z;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           qsort(l,j);
         if i<r then
           qsort(i,r);
      end;
begin
  readln(n);
  for i:=1 to n do readln(b[i,1],b[i,2],b[i,3]);
  for i:=1 to n do a[i]:=b[i,1]+b[i,2]+b[i,3];
  for i:=1 to n do c[i]:=i;
  qsort(1,n);
  for i:=n downto n-6 do if a[i]=a[i+1] then if b[c[i],1]>b[c[i+1],1] then begin
                                                                             p:=a[i];
                                                                            a[i]:=a[i+1];                                                                             a[i+1]:=p;
                                                                             q:=c[i];
                                                                             c[i]:=c[i+1];
                                                                             c[i+1]:=q;
                                                                           end
                                                                      else begin if b[c[i],1]=b[c[i+1],1] then if c[i]<c[i+1] then begin
                                                                                                                                     p:=a[i];
                                                                                                                                     a[i]:=a[i+1];
                                                                                                                                     a[i+1]:=p;
                                                                                                                                     q:=c[i];
                                                                                                                                     c[i]:=c[i+1];
                                                                                                                                     c[i+1]:=q;
                                                                                                                                   end;
                                                                           end;
for i:=n downto n-6 do if a[i]=a[i+1] then if b[c[i],1]>b[c[i+1],1] then begin
                                                                             p:=a[i];
                                                                            a[i]:=a[i+1];                                                                             a[i+1]:=p;
                                                                             q:=c[i];
                                                                             c[i]:=c[i+1];
                                                                             c[i+1]:=q;
                                                                           end
                                                                      else begin if b[c[i],1]=b[c[i+1],1] then if c[i]<c[i+1] then begin
                                                                                                                                     p:=a[i];
                                                                                                                                     a[i]:=a[i+1];
                                                                                                                                     a[i+1]:=p;
                                                                                                                                     q:=c[i];
                                                                                                                                     c[i]:=c[i+1];
                                                                                                                                     c[i+1]:=q;
                                                                                                                                   end;
                                                                           end;
for i:=n downto n-4 do writeln(c[i],' ',a[i]);
end.

