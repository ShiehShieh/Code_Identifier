var
     i,j,i1,i2,i3,i4,i5,i6,i7,i8,i9,min:longint;
     a,b,c:array[0..10] of integer;
begin
     min:=maxlongint;
     for i:=1 to 9 do read(a[i]);
     for i1:=0 to 3 do for i2:=0 to 3 do for i3:=0 to 3 do
     for i4:=0 to 3 do for i5:=0 to 3 do for i6:=0 to 3 do
     for i7:=0 to 3 do for i8:=0 to 3 do for i9:=0 to 3 do begin
         b[1]:=i1+i2+i4+a[1];
         b[2]:=i1+i2+i3+i5+a[2];
         b[3]:=i2+i3+i6+a[3];
         b[4]:=i1+i4+i5+i7+a[4];
         b[5]:=i1+i3+i5+i7+i9+a[5];
         b[6]:=i3+i5+i6+i9+a[6];
         b[7]:=i4+i7+i8+a[7];
         b[8]:=i5+i7+i8+i9+a[8];
         b[9]:=i6+i8+i9+a[9];
         if (b[1] mod 4=0) and (b[2] mod 4=0) and (b[3] mod 4=0) and (b[4] mod 4=0)
         and (b[5] mod 4=0) and (b[6] mod 4=0) and (b[7] mod 4=0) and (b[8] mod 4=0)
         and (b[9] mod 4=0) then if (i1+i2+i3+i4+i5+i6+i7+i8+i9)<min then begin
             min:=i1+i2+i3+i4+i5+i6+i7+i8+i9;
             c[1]:=i1;
             c[2]:=i2;
             c[3]:=i3;
             c[4]:=i4;
             c[5]:=i5;
             c[6]:=i6;
             c[7]:=i7;
             c[8]:=i8;
             c[9]:=i9;
         end;
     end;
     for i:=1 to 9 do
     for j:=1 to c[i] do write(i,' ');
     writeln;
end.
