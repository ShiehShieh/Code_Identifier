var
 a:char;
 s,s1,s2,s3:ansistring;
 l,i:longint;
begin
 readln(s);
 readln(s1);
 l:=length(s1);
 a:=chr(ord(s1[1])+32);
 if a='Q'
 then a:='1';
 if s='What'
 then begin
write('What');
for i:=1 to l do
begin
if (s1[i]='s')and(s1[i-1]='i')
then begin s2:=copy(s1,2,i-1);s3:=copy(s1,i+1,l-i-1);end;
end;
write(s3,' ',a,s2,'!');
end;
 if s='How'
 then begin
write('How');
for i:=1 to l do
begin
if (s1[i]='s')and(s1[i-1]='i')
then begin s2:=copy(s1,2,i-1);s3:=copy(s1,i+1,l-i-1);end;
end;
write(s3,' ',a,s2,'!');
end;
end.
