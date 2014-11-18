program diyanshu;
 var
 i,j,k,n,m,x,y,x1,x2,y1,y2:longint;
 c:array[0..1024,0..1024]of longint;
 function xx(x:longint):longint;
  begin
  xx:=(x xor (x-1))and x;
  end;
 function tot(x,y:longint):longint;
  var
  i,j,k:longint;
  begin
   tot:=0;
   i:=x;
   while i>0 do begin
    j:=y;
    while j>0 do begin
      inc(tot,c[i,j]);
      dec(j,xx(j)); end;
    dec(i,xx(i));
    end;
  end;
 procedure add(x,y,k:longint);
  var
  i,j:longint;
  begin
   i:=x;
   while i<=n do
    begin
     j:=y;
       while j<=n do begin
            inc(c[i,j],k);inc(j,xx(j));
            end;
     inc(i,xx(i));
    end;
  end;

 begin
  readln(n);
 fillchar(c,sizeof(c),0);
 repeat
 read(m);
 if m=1 then begin
     readln(x,y,k);
     inc(x);inc(y);
     add(x,y,k);
     end;
 if m=2 then begin
    readln(x1,y1,x2,y2);
    inc(x1);inc(y1);inc(x2);inc(y2);
    writeln(tot(x2,y2)-tot(x2,y1-1)-tot(x1-1,y2)+tot(x1-1,y1-1));
  end;
 until m=3;
 end.

