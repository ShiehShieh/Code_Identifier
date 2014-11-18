var
  a:array[1..1000,1..3]of longint;
  now,m,k,i,j:longint;
begin
  readln(m,k);
  for i:=1 to k do
    readln(a[i,1],a[i,2],a[i,3]);
  for i:=1 to 10 do
    begin
      now:=i;
      for j:=k downto 1 do
        begin
          if a[j,3]+1<=now
            then begin
                   if(a[j,3]+1+a[j,2]-a[j,1])>=now
                     then now:=now-a[j,3]-1+a[j,1]
                     else if a[j,2]>=now
                            then now:=now-a[j,3]-(a[j,2]-a[j,1]+1)+a[j,3];
                 end
            else if (a[j,1]<=now) then
              now:=now+(a[j,2]-a[j,1]+1);
        end;
      writeln(now);
    end;
end.
