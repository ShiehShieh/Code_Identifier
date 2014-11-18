var
   f:array[0..101,0..201]of longint;
   i,j,n,ans:longint;ch:char;
function min(a,b:longint):longint;
   begin
      if a>b then exit(b) else exit(a);
   end;
begin
   fillchar(f,sizeof(f),0);
   readln(n);
   for i:=1 to n do 
   begin
      for j:=1 to i-1 do read(ch);
      for j:=1 to (n-i)<<1+1 do
      begin
         read(ch);
         if ch='-' then f[i,j]:=1;
      end;
      readln;
   end;
   ans:=0;
   for i:=n downto 1 do
      for j:=(n-i)<<1-1 downto 1 do
         if f[i,j]<>0 then
         begin
            if odd(j) then
            begin
               f[i,j]:=min(f[i,j+2],f[i+1,j])+1;
               if f[i,j+1]=0 then f[i,j]:=1;
            end
            else begin
               f[i,j]:=min(f[i+1,j],f[i+1,j-2])+1;
               if f[i+1,j-1]=0 then f[i,j]:=1;
            end;
            if f[i,j]>ans then ans:=f[i,j];
         end;
   writeln(ans*ans)
end.
