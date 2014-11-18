program chao;
 var s:longint;
     n,a,b,c:integer;
procedure chaozuo(a,b,c:integer);
  begin
   if c=n then begin
                inc(s);exit;
               end;
   if a>0 then chaozuo(a-1,b+1,c);
   if b>0 then chaozuo(a,b-1,c+1);
  end;


 begin
  readln(n);
  chaozuo(n,0,0);
  writeln(s);
 end.
