var a,b,c,i:integer;
begin
readln(a,b,c);
for i:=1 to 10000 do begin
  c:=c+1;
  case b of
  1,3,5,7,8,10,12:if c>31 then begin b:=b+1; c:=c-31; end;
  4,6,9,11:if c>30 then begin b:=b+1;c:=c-30; end;
  2:begin if (c>29) and ((a mod 400=0) or ((a mod 4=0) and (a mod 100<>0))) then begin
    b:=3; c:=c-29 end;
    if (c>28) and (not((a mod 400=0) or ((a mod 4=0) and (a mod 100<>0)))) then begin b:=3; c:=c-28; end;
    end;
  end;
  if b>12 then begin b:=b-12; a:=a+1;end;
end;
writeln(a,'-',b,'-',c);
end.
