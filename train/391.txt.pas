var b,a:array[1..9]of longint;
    i,j,p1,p2,p3,p4,p5,p6,p7,p8,p9:longint;
begin
   for i:=1 to 9 do read(a[i]);
   for p1:=0 to 3 do
   for p2:=0 to 3 do
   for p3:=0 to 3 do
   for p4:=0 to 3 do
   for p5:=0 to 3 do
   for p6:=0 to 3 do
   for p7:=0 to 3 do
   for p8:=0 to 3 do
   for p9:=0 to 3 do begin
      b[1]:=p1+p2+p4+a[1];
      b[2]:=p1+p2+p3+p5+a[2];
      b[3]:=p2+p3+p6+a[3];
      b[4]:=p1+p4+p5+p7+a[4];
      b[5]:=p1+p3+p5+p7+p9+a[5];
      b[6]:=p3+p5+p6+p9+a[6];
      b[7]:=p4+p7+p8+a[7];
      b[8]:=p5+p7+p8+p9+a[8];
      b[9]:=p6+p8+p9+a[9];
      if (b[1]mod 4=0)and(b[2]mod 4=0)and(b[3]mod 4=0)and(b[4]mod 4=0)and(b[5]mod 4=0)and(b[6]mod 4=0)and(b[7]mod 4=0)and(b[8]mod 4=0)and(b[9]mod 4=0) then begin
         for j:=1 to p1 do write('1 ');
         for j:=1 to p2 do write('2 ');
         for j:=1 to p3 do write('3 ');
         for j:=1 to p4 do write('4 ');
         for j:=1 to p5 do write('5 ');
         for j:=1 to p6 do write('6 ');
         for j:=1 to p7 do write('7 ');
         for j:=1 to p8 do write('8 ');
         for j:=1 to p9 do write('9 ');
         exit;
      end;
   end;
end.

