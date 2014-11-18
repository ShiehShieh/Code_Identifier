var s:string;

begin
readln(s);
case s[1] of
'3':if s[3]='8' then writeln(1) else writeln(0);
'Q':writeln(1);
'9':writeln(0);
'2':writeln(1);
'A':if s[3]='4' then writeln(0) else writeln(1);
'4':writeln(0);
end;
end.
