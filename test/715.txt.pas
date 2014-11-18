var
   i,j,k,ans,n,tmp:longint;
begin
   read(n);ans:=0;j:=0;k:=0;tmp:=1;
   for i:=1 to n do 
   begin
      ans:=(ans+tmp)mod 10000;
      if k<j then inc(k) else begin k:=0;inc(j);tmp:=(tmp<<1)mod 10000; end;
   end;
   writeln(ans)
end.
