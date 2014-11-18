var
yy,mm,dd,i:word;
v:boolean;
begin
readln(yy,mm,dd);
for i:=1 to 10000 do
begin
v:=true;
if v and (mm=12) and (dd=31) then begin inc(yy); mm:=1; dd:=1; v:=false; end;
if v and ((mm=1) or (mm=3) or (mm=5) or (mm=7) or (mm=8) or (mm=10)) and (dd=31) then begin inc(mm); dd:=1; v:=false; end;
if v and ((mm=1) or (mm=3) or (mm=5) or (mm=7) or (mm=8) or (mm=10) or (mm=12)) and (dd<31) then begin v:=false; inc(dd); end;
if v and ((mm=4) or (mm=6) or (mm=9) or (mm=11)) and (dd=30) then begin inc(mm); dd:=1; v:=false; end;
if v and ((mm=4) or (mm=6) or (mm=9) or (mm=11)) and (dd<30) then begin inc(dd); v:=false; end;
if v and (mm=2) and (dd=29) then begin inc(mm); dd:=1; v:=false; end;
if v and (mm=2) and (dd=28) then
begin
if (yy mod 4=0) then inc(dd);
if (yy mod 4<>0) then begin inc(mm); dd:=1; end;
v:=false;
end;
if v and (mm=2) and (dd<28) then inc(dd);
end;
writeln(yy,'-',mm,'-',dd);
end.
