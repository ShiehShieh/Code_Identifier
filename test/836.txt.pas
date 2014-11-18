var
  st:string;
  i,j,n,max,min,s:integer;
begin
  read(st);
  n:=length(st);max:=1;min:=1000;
  for i:=1 to n-1 do
   if st[i]<>'0' then
      begin
        s:=1;
        for j:=i+1 to n do
         if st[j]=st[i] then begin s:=s+1; st[j]:='0'; end;
        if s>max then max:=s;
        if s<min then min:=s;
      end;
  i:=max-min;
  if i>3 then
    begin
      j:=2;
      while j*j<i do
       if i mod j=0 then
        begin
         n:=-1;
         break;
        end
        else j:=j+1;
    end;
  if (i<2) or (n=-1) then
    begin
      writeln('No Answer');
      writeln(0);
    end
    else
     begin
       writeln('Lucky Word');
       writeln(i);
     end;
end.

