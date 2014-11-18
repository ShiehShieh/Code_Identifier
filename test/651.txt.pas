var
  a:array[1..10000,1..3] of longint;
  i1,j2,i2,j1,k,l,m,n,i:longint;
begin
  read(n);
  read(m);
  k:=0;
  while m<>3 do
    begin
      if m=1 then
        begin
          inc(k);
          read(a[k,1],a[k,2],a[k,3]);
        end
      else
        if m=2 then
          begin
            read(i1,j1,i2,j2);
              l:=0;
              for i:=1 to k do
                if (a[i,1]>=i1)and(a[i,1]<=i2)and(a[i,2]>=j1)and(a[i,2]<=j2) then
                  inc(l,a[i,3]);
              writeln(l);
          end;
    read(m);
    end;
end.
