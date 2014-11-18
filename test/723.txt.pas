program P1379(input,output);
var
  p1,p2,p3,i,k:integer;
  j,ch,l:char;
  tmp,st,ans:ansistring;
begin
  readln(p1,p2,p3);
  ans:='';
  readln(st);
  for i:=1 to length(st) do
    begin
      if st[i]<>'-' then begin ans:=ans+st[i]; l:=st[i]; continue; end;
      if (succ(l)=st[i+1]) then continue;
      if (l>=st[i+1]) or (i=1) or (i=length(st)) or not((l in ['a'..'z']) and (st[i+1] in ['a'..'z']) or (l in ['0'..'9']) and (st[i+1] in ['0'..'9'])) then
        begin ans:=ans+st[i]; l:=st[i]; continue; end;
      tmp:='';
      for j:=succ(l) to pred(st[i+1]) do
        for k:=1 to p2 do
          begin
            case p1 of
              1:ch:=j;
              2:ch:=upcase(j);
              3:ch:='*';
            end;
            if p3=1 then tmp:=tmp+ch else tmp:=ch+tmp;
          end;

      ans:=ans+tmp;
      l:=ans[length(ans)];
   end;
  writeln(ans);
end.
