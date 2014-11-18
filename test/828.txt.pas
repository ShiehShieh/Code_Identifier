var a,b:array[1..7] of integer;
    x,max,maxday,i:integer;
begin
    for i:=1 to 7 do
    begin
    readln(a[i],b[i]);
    x:=a[i]+b[i];
    if x>max then begin max:=x;maxday:=i end;
    end;
    write(maxday);
end.
