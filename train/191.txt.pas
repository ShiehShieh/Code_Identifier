const
  months:array[1..12]of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
var
  yy,mm,dd:longint;
function leap(year:longint):boolean;
begin
  if (year mod 4=0)and(year mod 100<>0) then leap:=true
  else
    if year mod 400=0 then leap:=true
                      else leap:=false;
end;
procedure suan(yy,mm:longint;var day:longint);
begin
  if mm<>2 then day:=months[mm]
  else
    if leap(yy) then day:=29 else day:=28;
end;
procedure work;
var
  i,nowdays:longint;
begin
  for i:=1 to 10000 do
    begin
      inc(dd);
      suan(yy,mm,nowdays);
      if dd>nowdays then begin inc(mm);dd:=1;end;
      if mm>12 then begin inc(yy);mm:=1;end;
    end;
end;
begin
  readln(yy,mm,dd);
  work;
  write(yy,'-');
  write(mm,'-');
  writeln(dd);
end.
