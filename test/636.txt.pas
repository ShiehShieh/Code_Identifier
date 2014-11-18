var
  s:string;
  i,j,k,ans:integer;
  a:array[1 .. 10] of byte;
  b:char;
begin
  readln(s);
  j:=0;
  for i:=1 to length(s)-1 do
   begin
    if s[i] in ['0'..'9'] then
     begin
      inc(j);
      a[j]:=ord(s[i])-ord('0');
    end;
   end;
  b:=s[length(s)];
  ans:=0;
  for i:=1 to 9 do
    ans:=a[i]*i+ans;
    ans:=ans mod 11;

  if ((ans =10) and (b='X')) or
   (ans=ord(b)-ord('0'))  then writeln('Right')
     else
       begin
        write(a[1],'-');
        for i:=2 to 4 do
         write(a[i]);
         write('-');
        for i:=5 to 9 do
          write(a[i]);
       if ans=10 then write ('-X') else
         write('-',ans);
        end;
end.


