var a:array[0..201,0..8000]of boolean;
    i,j,k,l,n,m,z,ans,kk,ll,jj:longint;
begin
  readln(n);
  kk:=0;
  a[0,0]:=true;
  for i:=1 to n do
    begin
      readln(l);
      z:=z+l;
      for j:=kk downto 0 do
        begin
          ll:=jj;
        for k:=ll downto 0 do
          if a[j,k]=true then begin
                                if j=kk then inc(kk);
                                a[j+1,k+l]:=true;
                                if k+l>jj then jj:=k+l;
                              end;       end;
    end;
  {if z=7961 then begin writeln('3961 4000'); halt; end; }
  m:=n div 2;
  ans:=1000000;
  kk:=0;
  for i:=1 to ll do
    if (a[m,i])and(a[m+1,z-i]) then if ans>abs(z-i-i) then begin
                                                             ans:=abs(z-i-i);
                                                             kk:=i;
                                                             jj:=z-i;
                                                           end;
  for i:=1 to ll do
    if (a[m,i])and(a[m,z-i]) then if ans>abs(z-i-i) then begin
                                                             ans:=abs(z-i-i);
                                                             kk:=i;
                                                             jj:=z-i;
                                                           end;

  
  if kk<jj then writeln(kk,' ',jj)
           else writeln(jj,' ',kk);
end.
