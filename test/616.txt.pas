var
  yy,mm,dd,y,m,d,a:integer;
begin
  readln(yy,mm,dd);
  for a:=1 to 10000 do
    begin
      dd:=dd+1;
      case mm of
      1,3,5,7,8,10,12     :      if dd=32 then
                                   begin
                                     mm:=mm+1;
                                     dd:=1;
                                   end;
      4,6,9,11            :      if dd=31 then
                                   begin
                                     mm:=mm+1;
                                     dd:=1;
                                   end;
      end;
      if mm=2 then
        begin
          if (yy mod 4) <>0 then
            if dd=29 then
              begin
                mm:=mm+1;
                dd:=1;
              end;
          if (yy mod 4)=0 then
            if dd=30 then
              begin
                mm:=mm+1;
                dd:=1;
              end;
       end;
     if mm=13 then
       begin
         yy:=yy+1;
         mm:=1;
       end;
   end;
 writeln(yy,'-',mm,'-',dd);
end.

