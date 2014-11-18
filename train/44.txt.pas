program P1051;
const bi:array[1..5,'0'..'9']of string[3]=
 ((' - ','   ',' - ',' - ','   ',' - ',' - ',' - ',' - ',' - '),
  ('| |','  |','  |','  |','| |','|  ','|  ','  |','| |','| |'),
  ('   ','   ',' - ',' - ',' - ',' - ',' - ','   ',' - ',' - '),
  ('| |','  |','|  ','  |','  |','  |','| |','  |','| |','  |'),
  (' - ','   ',' - ',' - ','   ',' - ',' - ','   ',' - ',' - '));
var k,i,j,l,n,g,p:longint; a:array[1..255]of char;
begin
 readln(k);n:=0;
 while not(eoln) do
  begin
   inc(n);
   read(a[n]);
  end;
 for l:=1 to 5 do
  if l mod 2=1 then
   for i:=1 to n do
    begin
     write(' ');
     for j:=1 to k do
     write(bi[l,a[i]][2]);
     write(' ');
     if i=n then writeln
      else write(' ');
    end
   else
    for i:=1 to k do
     for j:=1 to n do
      begin
       write(bi[l,a[j]][1]);
       for g:=1 to k do
       write(' ');
       write(bi[l,a[j]][3]);
       if j<n then write(' ')
        else writeln;
      end;
end.
