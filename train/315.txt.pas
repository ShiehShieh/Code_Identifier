var
  a:array[1..300]of char;
  ch:char;
  i,x:integer;
  t1,t2:boolean;
  s:string;
  zm,sz:longint;
  jieguo:real;
procedure aaa;
  begin
  if ((t1=true) and (t2=true)) or ((t1=false) and (t2=false)) then
    zm:=zm+x
  else zm:=zm-x;
  end;
procedure bbb;
  begin
   if ((t1=true) and (t2=true)) or ((t1=false) and (t2=false)) then
    sz:=sz+x
  else sz:=sz-x;
  end;
begin
  t1:=true;
  t2:=true;
  readln(s);
  for i:=1 to length(s) do
    a[i]:=s[i];
  for i:=1 to length(s) do
    case s[i] of
      '0'..'9':x:=x*10+ord(a[i])-48;
      'a'..'z':begin
                 if x=0 then x:=1;
                 ch:=a[i];
                 aaa;
                 x:=0;
               end;
      '+':begin
            bbb;
            x:=0;
            t1:=true;
          end;
      '-':begin
            bbb;
            x:=0;
            t1:=false;
          end;
      '=':begin
            bbb;
            x:=0;
            t2:=false;
            t1:=true;
          end;
  end;
  bbb;
  sz:=0-sz;
  jieguo:=sz/zm;
  if (sz=0) and (zm<0) then jieguo:=0-jieguo;
  writeln(ch,'=',jieguo:1:3);
end. 
