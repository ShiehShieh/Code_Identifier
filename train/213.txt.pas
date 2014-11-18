var a,b:array[0..2000] of integer;
    c:array[0..2000]of boolean;
    i,j,k,l,m,n,max:integer;
begin
readln(m,n);
for i:=1 to m do readln(a[i]);
for i:=1 to n do readln(b[i]);
for i:=1 to n do c[i]:=true;
for i:=1 to m do begin
                   max:=0;k:=0; 
                   for j:=1 to n do begin
                                      if (a[i]>b[j])and(c[j])then if b[j]>max then begin
                                                                                     max:=b[j];
                                                                                     k:=j;
                                                                                   end;
                                    end;
                   if max<>0 then c[k]:=false;
                end;
l:=0;
for i:=1 to n do if c[i] then inc(l);
write(l);
end.
